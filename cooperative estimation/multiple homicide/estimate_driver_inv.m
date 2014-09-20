% propagate with the inverse range parameterization for agents

clear variables;
close all;

addpath('..\2D');

gen_noise;

% constants for feature initialization:
RHO0 = 0.5;
SIGMARHO = 0.25;

% flags
USE_SHARED = 1;

tvect = sort( [t(1); t; t]);

% xhat: [rx ry psi rxj ryj rhoj thetaj psij rxt ryt rhot thetat]
%         1  2  3   4   5    6     7     8    9  10  11    12

% initialize
xk(2) = struct('xk',zeros(length(t)*2+1,12),'Pk',zeros(length(t)*2+1,144));
xk(1) = struct('xk',zeros(length(t)*2+1,12),'Pk',zeros(length(t)*2+1,144));
%xk: r1 psi1 r2 psi2 rt psit
xk(1).xk(1,1:3) = Y(1,1:3);% my initial postion and heading
xk(1).xk(1,4:5) = xk(1).xk(1,1:2);% anchor pt for other agent
xk(1).xk(1,6:7) = [RHO0;b1(1,1)];% inverse range/ bearing to other agent
xk(1).xk(1,8) = (rand+0.5)*Y(1,9);% heading for other agent
xk(1).xk(1,9:10) = xk(1).xk(1,1:2);% anchor pt for target agent
xk(1).xk(1,11:12) = [RHO0;b1(1,2)];% inverse range/ bearing to target

xk(2).xk(1,1:3) = Y(1,7:9);
xk(2).xk(1,4:5) = xk(2).xk(1,1:2);% anchor pt for other agent
xk(2).xk(1,6:7) = [RHO0;b2(1,1)];% inverse range/ bearing to other agent
xk(2).xk(1,8) = (rand+0.5)*Y(1,3);% heading for other agent
xk(2).xk(1,9:10) = xk(2).xk(1,1:2);% anchor pt for target agent
xk(2).xk(1,11:12) = [RHO0;b2(1,2)];% inverse range/ bearing to target
for i = 1:2
    xk(i).Pk(1,:) = reshape(10*eye(12) + 1e-4*ones(12),[],1)';
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
            Pk = reshape( xk(j).Pk(2*i-1,:)',12,12);
            
            Rk = diag([sigma_bear sigma_bear sigma_bear sigma_bear]);
            if j == 1
                ytilde = [b1(i,:)';b2(i,[2 1])'];
            else
                ytilde = [b2(i,:)';b1(i,[2 1])'];
            end
            
            [yexp,Hk] = get_exp_inv(xhat);
%             %check derivative numerically
%             Hnot = zeros(4,length(xhat));
%             for k = 1:length(xhat)
%                 xnot = xhat;
%                 xnot(k) = xhat(k) + 1e-10;
%                 ynot = get_exp_inv(xnot);
%                 Hnot(:,k) = (ynot-yexp).*1e10;
%             end
            
            yexp(1:4) = minangle(yexp(1:4),ytilde(1:4));
            % compute Kalman gain
            if rank(Hk*Pk*Hk'+Rk) < 4 || norm(Pk,'fro') > 1e6
                disp('Singular matrix or large covariance');
                return;
            end
            
            if ~USE_SHARED
                % remove the shared measurements
                if j == 1
                    Hk(3:4,:) = [];
                    Rk = Rk(1:2,1:2);
                    ytilde(3:4) = [];
                    yexp(3:4) = [];
                else
                    Hk(1:2,:) = [];
                    Rk = Rk(3:4,3:4);
                    ytilde(1:2) = [];
                    yexp(1:2) = [];
                end
            end
            
            Kk = Pk*Hk'*((Hk*Pk*Hk'+Rk)\eye(size(Rk)));
            xhat = xhat + Kk*(ytilde - yexp);
            Pk = (eye(12) - Kk*Hk)*Pk;
            % store values
            xhat([3 8]) = pi2pi(xhat([3 8]));
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
            Pk = reshape( xk(j).Pk(2*i,:)',12,12);
            if j == 1
                uctrl = u1(i,:)';
                %odometry
                wk = w(i,:)';
            else
                uctrl = u2(i,:)';
                %odometry
                wk = w(i,[2 1])';
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