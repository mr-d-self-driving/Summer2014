clear variables;
close all;

addpath('..\2D');

MONTE = 1000;

% flags
USE_SHARED = 1;
XK_COOP = cell(MONTE,1);

tic
for KK = 1:MONTE
    gen_noise;
    tvect = sort( [t(1); t; t]);
    
    % initialize
    xk(2) = struct('xk',zeros(length(t)*2+1,8),'Pk',zeros(length(t)*2+1,64));
    xk(1) = struct('xk',zeros(length(t)*2+1,8),'Pk',zeros(length(t)*2+1,64));
    %xk: r1 psi1 r2 psi2 rt psit
    for i = 1:2
        xk(i).xk(1,:) = (rand(8,1)*1.0+0.5).*Y(1,[1 2 3 7 8 9 4 5])';
        xk(i).Pk(1,:) = reshape(10*eye(8) + 1e-4*ones(8),[],1)';
    end
    
    % loop over time
    sigma_psidot = (Ts)^2;%0.1;
    sigma_rt = (10*Ts)^2;% sigma in target position during propagation
    
    Qk = diag([sigma_w sigma_w sigma_psidot sigma_rt]);
    
    for i = 1:length(t)
        % measurements
        for j = 1:2
            if mod(i,0)
                yexp = zeros(4,1);
                ytilde = zeros(4,1);
                Hk = zeros(4,8);
                Rk = zeros(4);
                xhat = xk(j).xk(2*i-1,:)';
                Pk = reshape( xk(j).Pk(2*i-1,:)',8,8);
                if j == 1
                    psii = xhat(3);
                else
                    psii = xhat(6);
                end
                Cin = [cos(psii) sin(psii);-sin(psii) cos(psii)];
                
                % own bearing measurement of other agent
                if j == 1
                    ytilde(1) = b1(i,1);
                    rji_i = xhat(4:5) - xhat(1:2);
                else
                    ytilde(1) = b2(i,1);
                    rji_i = xhat(1:2) - xhat(4:5);
                end
                yexp(1) = atan2(rji_i(2),rji_i(1)) - psii;
                Rk(1,1) = sigma_bear;
                
                drjix = [-1 0 0 1 0];
                drjiy = [0 -1 0 0 1];
                if j == 1
                    Hk(1,[1 2 3 4 5]) = rji_i(1)^2/(rji_i(1)^2+rji_i(2)^2)*(-rji_i(2)/rji_i(1)^2*drjix + 1/rji_i(1)*drjiy) - [0 0 1 0 0];
                else
                    Hk(1,[4 5 6 1 2]) = rji_i(1)^2/(rji_i(1)^2+rji_i(2)^2)*(-rji_i(2)/rji_i(1)^2*drjix + 1/rji_i(1)*drjiy) - [0 0 1 0 0];
                end
                
                % own bearing measurement of target
                if j == 1
                    ytilde(2) = b1(i,2);
                    rti_i = xhat(7:8) - xhat(1:2);
                else
                    ytilde(2) = b2(i,2);
                    rti_i = xhat(7:8) - xhat(4:5);
                end
                yexp(2) = atan2(rti_i(2),rti_i(1)) - psii;
                Rk(2,2) = sigma_bear;
                
                drtix = [-1 0 0 1 0];
                drtiy = [0 -1 0 0 1];
                if j == 1
                    Hk(2,[1 2 3 7 8]) = rti_i(1)^2/(rti_i(1)^2+rti_i(2)^2)*(-rti_i(2)/rti_i(1)^2*drtix + 1/rti_i(1)*drtiy) - [0 0 1 0 0];
                else
                    Hk(2,[4 5 6 7 8]) = rti_i(1)^2/(rti_i(1)^2+rti_i(2)^2)*(-rti_i(2)/rti_i(1)^2*drtix + 1/rti_i(1)*drtiy) - [0 0 1 0 0];
                end
                
                % other's bearing measurement of target
                psij = 0;
                if j == 1
                    psij = xhat(6);
                    ytilde(3) = b2(i,2);
                    rtj_j = xhat(7:8) - xhat(4:5);
                else
                    psij = xhat(3);
                    ytilde(3) = b1(i,2);
                    rtj_j = xhat(7:8) - xhat(1:2);
                end
                yexp(3) = atan2(rtj_j(2),rtj_j(1)) - psij;
                Rk(3,3) = sigma_bear;
                
                drtjx = [-1 0 0 1 0];
                drtjy = [0 -1 0 0 1];
                if j == 1
                    Hk(3,[4 5 6 7 8]) = rtj_j(1)^2/(rtj_j(1)^2+rtj_j(2)^2)*(-rtj_j(2)/rtj_j(1)^2*drtjx + 1/rtj_j(1)*drtjy) - [0 0 1 0 0];
                else
                    Hk(3,[1 2 3 7 8]) = rtj_j(1)^2/(rtj_j(1)^2+rtj_j(2)^2)*(-rtj_j(2)/rtj_j(1)^2*drtjx + 1/rtj_j(1)*drtjy) - [0 0 1 0 0];
                end
                
                % other agent's bearing measurement of me
                if j == 1
                    ytilde(4) = b2(i,1);
                    rij_j = xhat(1:2) - xhat(4:5);
                else
                    ytilde(4) = b1(i,1);
                    rij_j = xhat(4:5) - xhat(1:2);
                end
                yexp(4) = atan2(rij_j(2),rij_j(1)) - psij;
                Rk(4,4) = sigma_bear;
                
                drijx = [-1 0 0 1 0];
                drijy = [0 -1 0 0 1];
                if j == 1
                    Hk(4,[4 5 6 1 2]) = rij_j(1)^2/(rij_j(1)^2+rij_j(2)^2)*(-rij_j(2)/rij_j(1)^2*drijx + 1/rij_j(1)*drijy) - [0 0 1 0 0];
                else
                    Hk(4,[1 2 3 4 5]) = rij_j(1)^2/(rij_j(1)^2+rij_j(2)^2)*(-rij_j(2)/rij_j(1)^2*drijx + 1/rij_j(1)*drijy) - [0 0 1 0 0];
                end
                
                yexp(1:4) = minangle(yexp(1:4),ytilde(1:4));
                % compute Kalman gain
                if rank(Hk*Pk*Hk'+Rk) < 4 || norm(Pk,'fro') > 1e6
                    disp('Singular matrix or large covariance');
                    return;
                end
                
                if ~USE_SHARED
                    % remove these shared measurements
                    Hk(3:4,:) = [];
                    Rk = Rk(1:2,1:2);
                    ytilde(3:4) = [];
                    yexp(3:4) = [];
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
    xk(2) = struct('xk',zeros(length(t)*2+1,8),'Pk',zeros(length(t)*2+1,64));
    xk(1) = struct('xk',zeros(length(t)*2+1,8),'Pk',zeros(length(t)*2+1,64));
    %xk: r1 psi1 r2 psi2 rt psit
    for i = 1:2
        xk(i).xk(1,:) = (rand(8,1)*1.0+0.5).*Y(1,[1 2 3 7 8 9 4 5])';
        xk(i).Pk(1,:) = reshape(10*eye(8) + 1e-4*ones(8),[],1)';
    end
    
    % loop over time
    sigma_psidot = (Ts)^2;%0.1;
    sigma_rt = (10*Ts)^2;% sigma in target position during propagation
    
    Qk = diag([sigma_w sigma_w sigma_psidot sigma_rt]);
    
    for i = 1:length(t)
        % measurements
        for j = 1:2
            if mod(i,0)
                yexp = zeros(4,1);
                ytilde = zeros(4,1);
                Hk = zeros(4,8);
                Rk = zeros(4);
                xhat = xk(j).xk(2*i-1,:)';
                Pk = reshape( xk(j).Pk(2*i-1,:)',8,8);
                if j == 1
                    psii = xhat(3);
                else
                    psii = xhat(6);
                end
                Cin = [cos(psii) sin(psii);-sin(psii) cos(psii)];
                
                % own bearing measurement of other agent
                if j == 1
                    ytilde(1) = b1(i,1);
                    rji_i = xhat(4:5) - xhat(1:2);
                else
                    ytilde(1) = b2(i,1);
                    rji_i = xhat(1:2) - xhat(4:5);
                end
                yexp(1) = atan2(rji_i(2),rji_i(1)) - psii;
                Rk(1,1) = sigma_bear;
                
                drjix = [-1 0 0 1 0];
                drjiy = [0 -1 0 0 1];
                if j == 1
                    Hk(1,[1 2 3 4 5]) = rji_i(1)^2/(rji_i(1)^2+rji_i(2)^2)*(-rji_i(2)/rji_i(1)^2*drjix + 1/rji_i(1)*drjiy) - [0 0 1 0 0];
                else
                    Hk(1,[4 5 6 1 2]) = rji_i(1)^2/(rji_i(1)^2+rji_i(2)^2)*(-rji_i(2)/rji_i(1)^2*drjix + 1/rji_i(1)*drjiy) - [0 0 1 0 0];
                end
                
                % own bearing measurement of target
                if j == 1
                    ytilde(2) = b1(i,2);
                    rti_i = xhat(7:8) - xhat(1:2);
                else
                    ytilde(2) = b2(i,2);
                    rti_i = xhat(7:8) - xhat(4:5);
                end
                yexp(2) = atan2(rti_i(2),rti_i(1)) - psii;
                Rk(2,2) = sigma_bear;
                
                drtix = [-1 0 0 1 0];
                drtiy = [0 -1 0 0 1];
                if j == 1
                    Hk(2,[1 2 3 7 8]) = rti_i(1)^2/(rti_i(1)^2+rti_i(2)^2)*(-rti_i(2)/rti_i(1)^2*drtix + 1/rti_i(1)*drtiy) - [0 0 1 0 0];
                else
                    Hk(2,[4 5 6 7 8]) = rti_i(1)^2/(rti_i(1)^2+rti_i(2)^2)*(-rti_i(2)/rti_i(1)^2*drtix + 1/rti_i(1)*drtiy) - [0 0 1 0 0];
                end
                
                % other's bearing measurement of target
                psij = 0;
                if j == 1
                    psij = xhat(6);
                    ytilde(3) = b2(i,2);
                    rtj_j = xhat(7:8) - xhat(4:5);
                else
                    psij = xhat(3);
                    ytilde(3) = b1(i,2);
                    rtj_j = xhat(7:8) - xhat(1:2);
                end
                yexp(3) = atan2(rtj_j(2),rtj_j(1)) - psij;
                Rk(3,3) = sigma_bear;
                
                drtjx = [-1 0 0 1 0];
                drtjy = [0 -1 0 0 1];
                if j == 1
                    Hk(3,[4 5 6 7 8]) = rtj_j(1)^2/(rtj_j(1)^2+rtj_j(2)^2)*(-rtj_j(2)/rtj_j(1)^2*drtjx + 1/rtj_j(1)*drtjy) - [0 0 1 0 0];
                else
                    Hk(3,[1 2 3 7 8]) = rtj_j(1)^2/(rtj_j(1)^2+rtj_j(2)^2)*(-rtj_j(2)/rtj_j(1)^2*drtjx + 1/rtj_j(1)*drtjy) - [0 0 1 0 0];
                end
                
                % other agent's bearing measurement of me
                if j == 1
                    ytilde(4) = b2(i,1);
                    rij_j = xhat(1:2) - xhat(4:5);
                else
                    ytilde(4) = b1(i,1);
                    rij_j = xhat(4:5) - xhat(1:2);
                end
                yexp(4) = atan2(rij_j(2),rij_j(1)) - psij;
                Rk(4,4) = sigma_bear;
                
                drijx = [-1 0 0 1 0];
                drijy = [0 -1 0 0 1];
                if j == 1
                    Hk(4,[4 5 6 1 2]) = rij_j(1)^2/(rij_j(1)^2+rij_j(2)^2)*(-rij_j(2)/rij_j(1)^2*drijx + 1/rij_j(1)*drijy) - [0 0 1 0 0];
                else
                    Hk(4,[1 2 3 4 5]) = rij_j(1)^2/(rij_j(1)^2+rij_j(2)^2)*(-rij_j(2)/rij_j(1)^2*drijx + 1/rij_j(1)*drijy) - [0 0 1 0 0];
                end
                
                yexp(1:4) = minangle(yexp(1:4),ytilde(1:4));
                % compute Kalman gain
                if rank(Hk*Pk*Hk'+Rk) < 4 || norm(Pk,'fro') > 1e6
                    disp('Singular matrix or large covariance');
                    return;
                end
                
                if ~USE_SHARED
                    % remove these shared measurements
                    Hk(3:4,:) = [];
                    Rk = Rk(1:2,1:2);
                    ytilde(3:4) = [];
                    yexp(3:4) = [];
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
    % store estimate histories
    XK_SOLO{KK} = xk;
    etaCalc(KK,MONTE,toc);
end

save monte_state.mat;