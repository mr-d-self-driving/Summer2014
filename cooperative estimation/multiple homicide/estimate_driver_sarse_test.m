% propagate with the inverse range parameterization for agents

clear variables;
close all;

addpath('../2D');

TRUTH = 1;

gen_noise;

% constants for feature initialization:
RHO0 = 0.5;
SIGMARHO = 1/36;

% flags
USE_SHARED = 1;

tvect = sort( [t; t; t(end)+Ts]);

% xhat: [rx_n ry_n v1 psi1 ux uy rho
%         1     2   3  4    5  6  7

% initialize
xk(2) = struct('xk',zeros(length(t)*2+1,7),'Pk',zeros(length(t)*2+1,49));
xk(1) = struct('xk',zeros(length(t)*2+1,7),'Pk',zeros(length(t)*2+1,49));
%xk: r1 psi1 r2 psi2 rt psit
xk(1).xk(1,[1 2 4]) = Y(1,1:3);% my initial postion and heading
xk(1).xk(1,3) = 0;% my initial velocity
xk(1).xk(1,5:6) = [cos(b1(1,2));sin(b1(1,2))];% unit vector to target
xk(1).xk(1,7) = RHO0;% inverse range to target
%xk(1).xk(1,7) = 1./sqrt(sum((Y(1,1:2)-Y(1,4:5)).^2));

xk(2).xk(1,[1 2 4]) = Y(1,7:9);% my initial postion and heading
xk(2).xk(1,3) = 0;% my initial velocity
xk(2).xk(1,5:6) = [cos(b2(1,2));sin(b2(1,2))];% unit vector to target
xk(2).xk(1,7) = RHO0;% inverse range to target
%xk(2).xk(1,7) = 1./sqrt(sum((Y(1,7:8)-Y(1,4:5)).^2));
for i = 1:2
    Puse = 1*eye(7) + 1e-6*ones(7);
    Puse(4,4) = .1;
    Puse(5,5) = 0.0333;
    Puse(6,6) = 0.0333;
    Puse(7,7) = SIGMARHO;
    xk(i).Pk(1,:) = reshape(Puse,[],1)';
end

%% loop over time
sigma_psidot = (1)^2;%0.1;
sigma_rt = (10)^2;% sigma in target position during propagation

Qk = diag([sigma_acc sigma_acc sigma_psidot sigma_rt sigma_rt]);

for i = 1:length(t)
    % measurements
    for j = 1:2
        if mod(i,0)
            xhat = xk(j).xk(2*i-1,:)';
            Pk = reshape( xk(j).Pk(2*i-1,:)',7,7);
            
            Rk = diag([sigma_w sigma_bear]);
            if j == 1
                % measurements: [v1; body-frame unit vector to target]
                ytilde = [w(i,1)/Ts;b1(i,2)];
            else
                ytilde = [w(i,2)/Ts;b2(i,2)];
            end
            
            [yexp,Hk] = get_exp_sarse_test(xhat);
            %check derivative numerically
%             Hnot = zeros(2,length(xhat));
%             for k = 1:length(xhat)
%                 xnot = xhat;
%                 xnot(k) = xhat(k) + 1e-10;
%                 ynot = get_exp_sarse_test(xnot);
%                 Hnot(:,k) = (ynot-yexp).*1e10;
%             end
            
            % compute Kalman gain
            if rank(Hk*Pk*Hk'+Rk) < 2 || norm(Pk,'fro') > 1e6
                disp('Singular matrix or large covariance');
                return;
            end
            
            yexp(2) = minangle(yexp(2),ytilde(2));
            Kk = Pk*Hk'*((Hk*Pk*Hk'+Rk)\eye(size(Rk)));
            xhat = xhat + Kk*(ytilde - yexp);
            Pk = (eye(7) - Kk*Hk)*Pk;
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
            Pk = reshape( xk(j).Pk(2*i,:)',7,7);
            if j == 1
                uctrl = u1(i,:)';
                %odometry
                wk = w(i,1)';
                imupass = imu(i,1:3);
            else
                uctrl = u2(i,:)';
                %odometry
                wk = w(i,2)';
                imupass = imu(i,4:6);
            end
            
            [xhat,Pk] = propagate_sarse_test(xhat,Pk,uctrl,imupass,Ts,Qk);
            % store
            xk(j).xk(2*i+1,:) = xhat';
            xk(j).Pk(2*i+1,:) = reshape(Pk,[],1)';
        end
    end
end

%% figures

Pdiag = [1:8:49];

for j = 1:2
    
    figure;
    %velocity
    subplot(211);
    plot(tvect,xk(j).xk(:,3),'-x');
    hold on;
    plot(tvect,xk(j).xk(:,3) + sqrt(xk(j).Pk(:,Pdiag(3)))*3,'g--');
    plot(tvect,xk(j).xk(:,3) - sqrt(xk(j).Pk(:,Pdiag(3)))*3,'g--');
    if j == 1
        plot(T,1*ones(size(T)),'r--');
        plot(T(1:end-2),w(:,1)/Ts,'k:');
    else
        plot(T,Y(:,10),'r--');
        plot(T(1:end-2),w(:,2)/Ts,'k:');
    end
    ylabel('v_1 (m/s)');
    % heading
    subplot(212);
    plot(tvect,xk(j).xk(:,4),'-x');
    hold on;
    plot(tvect,xk(j).xk(:,4) + sqrt(xk(j).Pk(:,Pdiag(4)))*3,'g--');
    plot(tvect,xk(j).xk(:,4) - sqrt(xk(j).Pk(:,Pdiag(4)))*3,'g--');
    if j == 1
        plot(T,Y(:,3),'r--');
    else
        plot(T,Y(:,9),'r--');
    end
    ylabel('\psi_1 (rad)');
    
    figure;
    ri = xk(j).xk(:,1:2);
    % bearing to target
    bearing_tj = atan2(xk(j).xk(:,6),xk(j).xk(:,5));
    % range to target
    range_tj = xk(j).xk(:,7);
    psii = xk(j).xk(:,3);
    
    subplot(211);
    plot(tvect,bearing_tj,'--x');
    hold on;
    if j == 1
        plot(T,pi2pi(atan2(Y(:,5)-Y(:,2),Y(:,4)-Y(:,1)) - Y(:,3)),'r-');
        plot(T(1:end-2),b1(:,2),'k--');
    else
        plot(T,pi2pi(atan2(Y(:,5)-Y(:,8),Y(:,4)-Y(:,7)) - Y(:,9)),'r-');
        plot(T(1:end-2),b2(:,2),'k--');
    end
    ylabel('agent i to t bearing');
        
    subplot(212);
    plot(tvect,range_tj,'--x');
    hold on;
    plot(tvect,range_tj+3*sqrt(xk(j).Pk(:,Pdiag(7))),'g--');
    plot(tvect,range_tj-3*sqrt(xk(j).Pk(:,Pdiag(7))),'g--');
    if j == 1
        plot(T,1./sqrt(sum((Y(:,4:5)-Y(:,1:2)).^2,2)),'r-');
    else
        plot(T,1./sqrt(sum((Y(:,7:8)-Y(:,4:5)).^2,2)),'r-');
    end
    ylabel('agent i to t inverse range');
    
    figure;
    plot(Y(:,2),Y(:,1),'-');
    hold on
    plot(Y(:,8),Y(:,7),'r-');
    plot(Y(:,5),Y(:,4),'g-');
    plot(ri(:,2),ri(:,1),'--o');
    %plot(rj(:,2),rj(:,1),'r--d');
    %plot(rt(:,2),rt(:,1),'g--x');
    set(gca,'xlim',[-50 50])
    set(gca,'ylim',[-50 50])
end