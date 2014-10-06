% propagate with the inverse range parameterization for agents

clear variables;
close all;

addpath('../2D');

gen_noise;

% constants for feature initialization:
RHO0 = 0.5;
SIGMARHO = 0.25;

% flags
USE_SHARED = 1;

tvect = sort( [t(1); t; t]);

% xhat: [rx_n ry_n v1 psi1 ux uy uxdot uydot rho -rhodot/rho
%         1     2   3  4    5  6  7      8    9     10

% initialize
xk(2) = struct('xk',zeros(length(t)*2+1,11),'Pk',zeros(length(t)*2+1,121));
xk(1) = struct('xk',zeros(length(t)*2+1,11),'Pk',zeros(length(t)*2+1,121));
%xk: r1 psi1 r2 psi2 rt psit
xk(1).xk(1,[1 2 4]) = Y(1,1:3);% my initial postion and heading
xk(1).xk(1,3) = [0;0];% my initial velocity
xk(1).xk(1,5:6) = [1;0];% unit vector to target
xk(1).xk(1,7:8) = [0;0];% body frame time rate of unit vector to target
xk(1).xk(1,9) = RHO0;% inverse range to target
xk(1).xk(1,10) = 0;% -rhodot/rho to target

xk(2).xk(1,[1 2 4]) = Y(1,7:9);% my initial postion and heading
xk(2).xk(1,3) = [0;0];% my initial velocity
xk(2).xk(1,5:6) = [1;0];% unit vector to target
xk(2).xk(1,7:8) = [0;0];% body frame time rate of unit vector to target
xk(2).xk(1,9) = RHO0;% inverse range to target
xk(2).xk(1,10) = 0;% -rhodot/rho to target
for i = 1:2
    xk(i).Pk(1,:) = reshape(10*eye(10) + 1e-4*ones(10),[],1)';
end

%% loop over time
sigma_psidot = (Ts)^2;%0.1;
sigma_rt = (10*Ts)^2;% sigma in target position during propagation

Qk = diag([sigma_w sigma_w sigma_psidot sigma_rt]);

for i = 1:length(t)
    % measurements
    for j = 1:2
        if mod(i,0)
            xhat = xk(j).xk(2*i-1,:)';
            Pk = reshape( xk(j).Pk(2*i-1,:)',10,10);
            
            Rk = diag([sigma_w sigma_bear sigma_bear]);
            if j == 1
                % measurements: [v1; body-frame unit vector to target]
                ytilde = [w(i,1)/Ts;cos(b1(i,2));sin(b1(i,2))];
            else
                ytilde = [w(i,2)/Ts;cos(b2(i,2));sin(b2(i,2))];
            end
            
            [yexp,Hk] = get_exp_sarse_test(xhat);
%             %check derivative numerically
%             Hnot = zeros(4,length(xhat));
%             for k = 1:length(xhat)
%                 xnot = xhat;
%                 xnot(k) = xhat(k) + 1e-10;
%                 ynot = get_exp_inv(xnot);
%                 Hnot(:,k) = (ynot-yexp).*1e10;
%             end
            
            % compute Kalman gain
            if rank(Hk*Pk*Hk'+Rk) < 3 || norm(Pk,'fro') > 1e6
                disp('Singular matrix or large covariance');
                return;
            end
                        
            Kk = Pk*Hk'*((Hk*Pk*Hk'+Rk)\eye(size(Rk)));
            xhat = xhat + Kk*(ytilde - yexp);
            Pk = (eye(10) - Kk*Hk)*Pk;
            % re-normalize unit vector
            xhat(5:6) = xhat(5:6)/norm(xhat(5:6));
            % store values
            xk(j).xk(2*i,:) = xhat';
            xk(j).Pk(2*i,:) = reshape(Pk,[],1)';
        else
            xk(j).xk(2*i,:) = xk(j).xk(2*i-1,:);
            xk(j).Pk(2*i,:) = xk(j).Pk(2*i-1,:);
        end
    end
    
    % propagation
    for j = 1:2
        if ~mod(i,0)
            xk(j).xk(2*i+1,:) = xk(j).xk(2*i,:);
            xk(j).Pk(2*i+1,:) = xk(j).Pk(2*i,:);
        else
            xhat = xk(j).xk(2*i,:)';
            Pk = reshape( xk(j).Pk(2*i,:)',10,10);
            if j == 1
                uctrl = u1(i,:)';
                %odometry
                wk = w(i,1)';
            else
                uctrl = u2(i,:)';
                %odometry
                wk = w(i,2)';
            end
            
            [xhat,Pk] = propagate_inv(xhat,Pk,uctrl,wk,Ts,Qk);
            % store
            xk(j).xk(2*i+1,:) = xhat';
            xk(j).Pk(2*i+1,:) = reshape(Pk,[],1)';
        end
    end
end

%% figures

Pdiag = [1:13:144];

for j = 1:2
    figure;
    subplot(321);
    ri = xk(j).xk(:,1:2);
    rj = xk(j).xk(:,4:5) + 1./repmat(xk(j).xk(:,6),1,2).*[cos(xk(j).xk(:,7)) sin(xk(j).xk(:,7))];
    rt = xk(j).xk(:,9:10) + 1./repmat(xk(j).xk(:,11),1,2).*[cos(xk(j).xk(:,12)) sin(xk(j).xk(:,12))];
    psii = xk(j).xk(:,3);
    psij = xk(j).xk(:,8);
    
    plot(tvect,pi2pi(atan2(rj(:,2)-ri(:,2),rj(:,1)-ri(:,1)) - psii),'--x');
	hold on;
    if j == 1
        plot(T,pi2pi(atan2(Y(:,8)-Y(:,2),Y(:,7)-Y(:,1)) - Y(:,3)),'r-');
    else
        plot(T,pi2pi(atan2(Y(:,2)-Y(:,8),Y(:,1)-Y(:,7)) - Y(:,9)),'r-');
    end
    ylabel('agent i to j bearing');
    
    subplot(323);
    plot(tvect,pi2pi(atan2(rt(:,2)-ri(:,2),rt(:,1)-ri(:,1)) - psii),'--x');
    hold on;
    if j == 1
        plot(T,pi2pi(atan2(Y(:,5)-Y(:,2),Y(:,4)-Y(:,1)) - Y(:,3)),'r-');
    else
        plot(T,pi2pi(atan2(Y(:,5)-Y(:,8),Y(:,4)-Y(:,7)) - Y(:,9)),'r-');
    end
    ylabel('agent i to t bearing');
    
    subplot(325);
    plot(tvect,pi2pi(atan2(rt(:,2)-rj(:,2),rt(:,1)-rj(:,1)) - psij),'--x');
    hold on;
    if j == 1
        plot(T,pi2pi(atan2(Y(:,5)-Y(:,8),Y(:,4)-Y(:,7)) - Y(:,9)),'r-');
    else
        plot(T,pi2pi(atan2(Y(:,5)-Y(:,2),Y(:,4)-Y(:,1)) - Y(:,3)),'r-');
    end
    ylabel('agent j to t bearing');
    
    subplot(322);
    plot(tvect,sqrt(sum((rj-ri).^2,2)),'--x');
    hold on;
    plot(T,sqrt(sum((Y(:,7:8)-Y(:,1:2)).^2,2)),'r-');
    ylabel('agent i to j range');
    
    subplot(324);
    plot(tvect,sqrt(sum((rt-ri).^2,2)),'--x');
    hold on;
    if j == 1
        plot(T,sqrt(sum((Y(:,4:5)-Y(:,1:2)).^2,2)),'r-');
    else
        plot(T,sqrt(sum((Y(:,7:8)-Y(:,4:5)).^2,2)),'r-');
    end
    ylabel('agent i to t range');
    
    subplot(326);
    plot(tvect,sqrt(sum((rt-rj).^2,2)),'--x');
    hold on;
    if j == 2
        plot(T,sqrt(sum((Y(:,4:5)-Y(:,1:2)).^2,2)),'r-');
    else
        plot(T,sqrt(sum((Y(:,7:8)-Y(:,4:5)).^2,2)),'r-');
    end
    ylabel('agent j to t range');
    
    figure;
    plot(Y(:,2),Y(:,1),'-');
    hold on
    plot(Y(:,8),Y(:,7),'r-');
    plot(Y(:,5),Y(:,4),'g-');
    plot(ri(:,2),ri(:,1),'--o');
    plot(rj(:,2),rj(:,1),'r--d');
    plot(rt(:,2),rt(:,1),'g--x');
    set(gca,'xlim',[-50 50])
    set(gca,'ylim',[-50 50])
end