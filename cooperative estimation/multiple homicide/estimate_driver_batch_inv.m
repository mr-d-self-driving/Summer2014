clear variables;
close all;

addpath('../2D');

% constants for feature initialization:
RHO0 = 0.5;
SIGMARHO = 0.25;

MONTE = 1000;

% flags
USE_SHARED = 1;
XK_COOP = cell(MONTE,1);

tic
for KK = 1:MONTE
    gen_noise;
    tvect = sort( [t(1); t; t]);
    
    % initialize
    xk(2) = struct('xk',zeros(length(t)*2+1,12),'Pk',zeros(length(t)*2+1,144));
    xk(1) = struct('xk',zeros(length(t)*2+1,12),'Pk',zeros(length(t)*2+1,144));
    %xk: r1 psi1 r2 psi2 rt psit
    xk(1).xk(1,1:3) = (rand(1,3)+0.5).*Y(1,1:3);% my initial postion and heading
    xk(1).xk(1,4:5) = xk(1).xk(1,1:2);% anchor pt for other agent
    xk(1).xk(1,6:7) = [RHO0;b1(1,1)];% inverse range/ bearing to other agent
    xk(1).xk(1,8) = (rand+0.5)*Y(1,9);% heading for other agent
    xk(1).xk(1,9:10) = xk(1).xk(1,1:2);% anchor pt for target agent
    xk(1).xk(1,11:12) = [RHO0;b1(1,2)];% inverse range/ bearing to target
    
    xk(2).xk(1,1:3) = (rand(1,3)+0.5).*Y(1,7:9);
    xk(2).xk(1,4:5) = xk(2).xk(1,1:2);% anchor pt for other agent
    xk(2).xk(1,6:7) = [RHO0;b2(1,1)];% inverse range/ bearing to other agent
    xk(2).xk(1,8) = (rand+0.5)*Y(1,3);% heading for other agent
    xk(2).xk(1,9:10) = xk(2).xk(1,1:2);% anchor pt for target agent
    xk(2).xk(1,11:12) = [RHO0;b2(1,2)];% inverse range/ bearing to target
    for i = 1:2
        xk(i).Pk(1,:) = reshape(10*eye(12) + 1e-4*ones(12),[],1)';
    end
    
    % loop over time
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
    % store estimate histories
    XK_COOP{KK} = xk;
    etaCalc(KK,MONTE,toc);
end

% flags
USE_SHARED = 0;
XK_SOLO = cell(MONTE,1);

tic;
for KK = 1:MONTE
    gen_noise;
    tvect = sort( [t(1); t; t]);
    
    % initialize
    xk(2) = struct('xk',zeros(length(t)*2+1,12),'Pk',zeros(length(t)*2+1,144));
    xk(1) = struct('xk',zeros(length(t)*2+1,12),'Pk',zeros(length(t)*2+1,144));
    %xk: r1 psi1 r2 psi2 rt psit
    xk(1).xk(1,1:3) = (rand(1,3)+0.5).*Y(1,1:3);% my initial postion and heading
    xk(1).xk(1,4:5) = xk(1).xk(1,1:2);% anchor pt for other agent
    xk(1).xk(1,6:7) = [RHO0;b1(1,1)];% inverse range/ bearing to other agent
    xk(1).xk(1,8) = (rand+0.5)*Y(1,9);% heading for other agent
    xk(1).xk(1,9:10) = xk(1).xk(1,1:2);% anchor pt for target agent
    xk(1).xk(1,11:12) = [RHO0;b1(1,2)];% inverse range/ bearing to target
    
    xk(2).xk(1,1:3) = (rand(1,3)+0.5).*Y(1,7:9);
    xk(2).xk(1,4:5) = xk(2).xk(1,1:2);% anchor pt for other agent
    xk(2).xk(1,6:7) = [RHO0;b2(1,1)];% inverse range/ bearing to other agent
    xk(2).xk(1,8) = (rand+0.5)*Y(1,3);% heading for other agent
    xk(2).xk(1,9:10) = xk(2).xk(1,1:2);% anchor pt for target agent
    xk(2).xk(1,11:12) = [RHO0;b2(1,2)];% inverse range/ bearing to target
    for i = 1:2
        xk(i).Pk(1,:) = reshape(10*eye(12) + 1e-4*ones(12),[],1)';
    end
    
    % loop over time
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
    % store estimate histories
    XK_SOLO{KK} = xk;
    etaCalc(KK,MONTE,toc);
end

save monte_state_inv.mat;