clear variables;
close all;

addpath('..\2D');

TRUTH = 1;

gen_noise;

% flags
USE_SHARED = 1;

tvect = sort( [t(1); t; t]);

% initialize
xk(2) = struct('xk',zeros(length(t)*2+1,8),'Pk',zeros(length(t)*2+1,64));
xk(1) = struct('xk',zeros(length(t)*2+1,8),'Pk',zeros(length(t)*2+1,64));
%xk: r1 psi1 r2 psi2 rt psit
for i = 1:2
    xk(i).xk(1,:) = (rand(8,1)*1.0+0.5).*Y(1,[1 2 3 7 8 9 4 5])';
    xk(i).Pk(1,:) = reshape(10*eye(8) + 1e-4*ones(8),[],1)';
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
            Pk = reshape( xk(j).Pk(2*i-1,:)',8,8);
            
            %check derivative numerically
%             Hnot = zeros(4,8);
%             for k = 1:8
%                 xnot = xhat;
%                 xnot(k) = xhat(k) + 1e-10;
%                 ynot = get_exp(j,xnot);
%                 Hnot(:,k) = (ynot-yexp).*1e10;
%             end
            
            Rk = diag([sigma_bear sigma_bear sigma_bear sigma_bear]);
            ytilde = [b1(i,:)';b2(i,[2 1])'];
            [yexp,Hk] = get_exp(xhat);
            yexp(1:4) = minangle(yexp(1:4),ytilde(1:4));
            % compute Kalman gain
            if rank(Hk*Pk*Hk'+Rk) < 4 || norm(Pk,'fro') > 1e6
                disp('Singular matrix or large covariance');
                return;
            end
            
            if ~USE_SHARED
                % remove these shared measurements
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
            Pk = (eye(8) - Kk*Hk)*Pk;
            % store values
            xhat([3 6]) = pi2pi(xhat([3 6]));
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
            Pk = reshape( xk(j).Pk(2*i,:)',8,8);
            if j == 1
                uctrl = u1(i,:)';
                %uctrl2 = u2(i,:)';
            else
                uctrl = u2(i,:)';
                %uctrl2 = u1(i,:)';
            end
            uctrl2 = 0;
            
            psii = xhat(3);
            psij = xhat(6);
            %odometry
            wk = w(i,:)';
            
            % linearized matrices
            Fk = eye(8);
            Bk = zeros(8,3);
            Bk(1:5,1:2) = [cos(psii) 0;
                sin(psii) 0;
                0 0;
                0 cos(psij);
                0 sin(psij)];
            if j == 1
                Bk(3,3) = Ts;% own control
            else
                Bk(6,3) = Ts;% own control
            end
            Gk = zeros(8,4);
            Gk(1:2,1) = -[cos(psii);sin(psii)];
            Gk(4:5,2) = -[cos(psij);sin(psij)];
            if j == 1
                Gk(6,3) = 1;
            else
                Gk(3,3) = 1;
            end
            Gk(7:8,4) = [1;1];
            
            xhat = Fk*xhat + Bk*[wk;uctrl];
            Pk = Fk*Pk*Fk' + Gk*Qk*Gk';
            % store
            xk(j).xk(2*i+1,:) = xhat';
            xk(j).Pk(2*i+1,:) = reshape(Pk,[],1)';
        end
    end
end

%% figures

Pdiag = [1:9:64];

for j = 1:2
    figure;
    subplot(321);
    if j == 1
        %plot(t,pi2pi(b1(:,1);
        plot(tvect,pi2pi(atan2(xk(j).xk(:,5)-xk(j).xk(:,2),xk(j).xk(:,4)-xk(j).xk(:,1)) - xk(j).xk(:,3)),'--x');
        hold on;
        plot(T,pi2pi(atan2(Y(:,8)-Y(:,2),Y(:,7)-Y(:,1)) - Y(:,3)),'r-');
    else
        %plot(t,pi2pi(b2(:,1)));
        plot(tvect,pi2pi(atan2(xk(j).xk(:,2)-xk(j).xk(:,5),xk(j).xk(:,1)-xk(j).xk(:,4)) - xk(j).xk(:,6)),'--x');
        hold on;
        plot(T,pi2pi(atan2(Y(:,2)-Y(:,8),Y(:,1)-Y(:,7)) - Y(:,9)),'r-');
    end
    ylabel('agent i to j bearing');
    
    subplot(323);
    if j == 1
        %plot(t,pi2pi(b1(:,2)));
        plot(tvect,pi2pi(atan2(xk(j).xk(:,8)-xk(j).xk(:,2),xk(j).xk(:,7)-xk(j).xk(:,1)) - xk(j).xk(:,3)),'--x');
        hold on;
        plot(T,pi2pi(atan2(Y(:,5)-Y(:,2),Y(:,4)-Y(:,1)) - Y(:,3)),'r-');
    else
        %plot(t,pi2pi(b2(:,2)));
        plot(tvect,pi2pi(atan2(xk(j).xk(:,8)-xk(j).xk(:,5),xk(j).xk(:,7)-xk(j).xk(:,4)) - xk(j).xk(:,6)),'--x');
        hold on;
        plot(T,pi2pi(atan2(Y(:,5)-Y(:,8),Y(:,4)-Y(:,7)) - Y(:,9)),'r-');
    end
    ylabel('agent i to t bearing');
    
    subplot(325);
    if j == 1
        %plot(t,pi2pi(b2(:,2)));
        plot(tvect,pi2pi(atan2(xk(j).xk(:,8)-xk(j).xk(:,5),xk(j).xk(:,7)-xk(j).xk(:,4)) - xk(j).xk(:,6)),'--x');
        hold on;
        plot(T,pi2pi(atan2(Y(:,5)-Y(:,8),Y(:,4)-Y(:,7)) - Y(:,9)),'r-');
    else
        %plot(t,pi2pi(b1(:,2)));
        plot(tvect,pi2pi(atan2(xk(j).xk(:,8)-xk(j).xk(:,2),xk(j).xk(:,7)-xk(j).xk(:,1)) - xk(j).xk(:,3)),'--x');
        hold on;
        plot(T,pi2pi(atan2(Y(:,5)-Y(:,2),Y(:,4)-Y(:,1)) - Y(:,3)),'r-');
    end
    ylabel('agent j to t bearing');
    
    subplot(322);
    plot(tvect,sqrt(sum((xk(j).xk(:,4:5)-xk(j).xk(:,1:2)).^2,2)),'--x');
    hold on;
    plot(T,sqrt(sum((Y(:,7:8)-Y(:,1:2)).^2,2)),'r-');
    ylabel('agent i to j range');
    
    subplot(324);
    if j == 1
        plot(tvect,sqrt(sum((xk(j).xk(:,7:8)-xk(j).xk(:,1:2)).^2,2)),'--x');
        hold on;
        plot(T,sqrt(sum((Y(:,4:5)-Y(:,1:2)).^2,2)),'r-');
    else
        plot(tvect,sqrt(sum((xk(j).xk(:,7:8)-xk(j).xk(:,4:5)).^2,2)),'--x');
        hold on;
        plot(T,sqrt(sum((Y(:,7:8)-Y(:,4:5)).^2,2)),'r-');
    end
    ylabel('agent i to t range');
    
    subplot(326);
    if j == 2
        plot(tvect,sqrt(sum((xk(j).xk(:,7:8)-xk(j).xk(:,1:2)).^2,2)),'--x');
        hold on;
        plot(T,sqrt(sum((Y(:,4:5)-Y(:,1:2)).^2,2)),'r-');
    else
        plot(tvect,sqrt(sum((xk(j).xk(:,7:8)-xk(j).xk(:,4:5)).^2,2)),'--x');
        hold on;
        plot(T,sqrt(sum((Y(:,7:8)-Y(:,4:5)).^2,2)),'r-');
    end
    ylabel('agent j to t range');
    
    figure;
    plot(Y(:,2),Y(:,1),'-');
    hold on
    plot(Y(:,8),Y(:,7),'r-');
    plot(Y(:,5),Y(:,4),'g-');
    plot(xk(j).xk(:,2),xk(j).xk(:,1),'--o')
    plot(xk(j).xk(:,5),xk(j).xk(:,4),'r--d')
    plot(xk(j).xk(:,8),xk(j).xk(:,7),'g--x')
    set(gca,'xlim',[-50 50])
    set(gca,'ylim',[-50 50])
end