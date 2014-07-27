

clear variables;
close all;

load data.mat;

Rrange = [100 100];
Rbear = [.01 .01];
Rrange_ag = 100;
Rbear_ag = .01;
Rimu = diag([.5^2 .5^2 .1^2]);
TRUTH = 0;
gen_new_noise;

%sample time
Ts = mean(diff(tspan));
% process noise covariance matrix
Q = Rimu + eye(3)*Ts^2;

%% initialize each agent
tk = [tspan(sort([1:length(tspan) 1:length(tspan)])) tspan(end)+Ts];
xk(N) = struct('xk',zeros(length(tspan)*2+1,5),'Pk',zeros(length(tspan)*2+1,25));
ye(N) = struct('yexp',zeros(length(tspan),2*N*M),...
    'ytilde',zeros(length(tspan),2*N*M),...
    'Rexp',zeros(length(tspan),(2*N*M)^2));
for i = 1:N
    xk(i).xk(1,:) = ags(i).truth(1,1:5);
    %xk(i).Pk(1,:) = reshape( eye(5),25,1)';
    xk(i).Pk(1,:) = reshape( 10*eye(5)+1*ones(5) ,25,1)';
end

%% loop over time
for i = 1:length(tspan)
    %% update
    for j = 1:N
        % current estimate of own state:
        x0hat = xk(j).xk(2*i-1,1:5)';
        % current covariance
        P0hat = reshape(xk(j).Pk(2*i-1,:)',5,5);
        % expected error covariance associated with the expected
        % measurement:
        Rexp = zeros((2*N)*M);
        % measurement error covariance;
        Rrel = zeros(2*N*M);
        Rrel(1:2*M,1:2*M) = diag([repmat(Rrange(j),M,1);repmat(Rbear(j),M,1)]);
        ytilde = zeros((2*N)*M,1);%actual measurement
        yexp = zeros((2*N)*M,1);%expectation
        Hk = zeros((2*N)*M,5);%gradient
        % compute own measurements
        ytilde(1:2*M) = ags(j).rb(i,:)';% range1 range 2 range 3 bearing1 bearing2 bearing3
        % own estimate states:
        rix = x0hat(1);
        riy = x0hat(2);
        psii = pi2pi(x0hat(5));
        % compute expectation for each landmark
        for k = 1:M
            rkx = marks(k).xy(1);
            rky = marks(k).xy(2);
            yexp(k) = sqrt((rkx-rix)^2+(rky-riy)^2);
            yexp(k+M) = atan2(rky-riy,rkx-rix) - psii;
            yexp(k+M) = minangle(yexp(k+M),ytilde(k+M));
            % compute gradient for each landmark
            Hk(k,1) = -(rkx-rix)/yexp(k);
            Hk(k,2) = -(rky-riy)/yexp(k);
            Hk(k+M,1) = (rky-riy)/((rky-riy)^2+(rkx-rix)^2);
            Hk(k+M,2) = -(rkx-rix)/((rky-riy)^2+(rkx-rix)^2);
            Hk(k+M,5) = -1;
        end
        % loop over every other agent's measurements
        jcoun = 0;
        Jac = zeros((N-1)*2*M,6);%jacobian of other agents' measurements w.r.t. relevent variables 
        for j2 = [1:j-1 j+1:N]
            jcoun = jcoun+1;%needed indexing variable because of how histories are stored
            % compute other measurements
            ytilde((jcoun+1)*M + (1:2*M)) = ags(j2).rb(i,:)';% range1 range 2 range 3 bearing1 bearing2 bearing3
            for k = 1:M
                rkx = marks(k).xy(1);
                rky = marks(k).xy(2);
                rhoji = ags(j).rb_agent(i,jcoun);
                thetaji = ags(j).rb_agent(i,jcoun+1);
                psij = pi2pi(xk(j2).xk(2*i-1,5));%other agent heading
                % expected measurements
                phiji = thetaji+psii;
                yexp(k+(jcoun+1)*M) = sqrt( (rkx-rix-rhoji*cos(phiji))^2 + (rky-riy-rhoji*sin(phiji))^2 );%range
                yexp(k+M+(jcoun+1)*M) = atan2(rky-riy-rhoji*sin(phiji),rkx-rix-rhoji*cos(phiji)) - psij;%expected bearing
                yexp(k+M+(jcoun+1)*M) = minangle(yexp(k+M+(jcoun+1)*M),ytilde(k+M+(jcoun+1)*M));
                % gradient of expectation
                rhokj = sqrt((rkx-rix-rhoji*cos(phiji))^2 + (rky-riy-rhoji*sin(phiji))^2);%expected range
                % gradient of expected range
                Hk(k+(jcoun+1)*M,1) = -(rkx-rix-rhoji*cos(phiji))/rhokj;
                Hk(k+(jcoun+1)*M,2) = -(rky-riy-rhoji*sin(phiji))/rhokj;
                Hk(k+(jcoun+1)*M,5) = (rhoji*sin(phiji)*(rkx-rix)-rhoji*cos(phiji)*(rky-riy))/rhokj;
                % gradient of expected bearing
                Hk(k+(jcoun+1)*M+M,1) = (rky-riy-rhoji*sin(phiji))/rhokj^2;
                Hk(k+(jcoun+1)*M+M,2) = -(rkx-rix-rhoji*cos(phiji))/rhokj^2;
                Hk(k+(jcoun+1)*M+M,5) = (rhoji^2-rhoji*(cos(phiji)*(rkx-rix)+sin(phiji)*(rky-riy)))/rhokj^2;
                % must also compute the effective covariance, which depends
                % on a lot of different uncertainties
                % gradients of measurements w.r.t. (rix,riy,psii,rhoji,thetaji,psij) 
                drange = [-(rkx-rix-rhoji*cos(phiji))/rhokj;
                    -(rky-riy-rhoji*sin(phiji))/rhokj;
                    (rhoji*sin(phiji)*(rkx-rix)-rhoji*cos(phiji)*(rky-riy))/rhokj;
                    (rhoji-cos(phiji)*(rkx-rix)-sin(phiji)*(rky-riy))/rhokj;
                    (rhoji*sin(phiji)*(rkx-rix)-rhoji*cos(phiji)*(rky-riy))/rhokj;
                    0];
                dbear = [(rky-riy-rhoji*sin(phiji))/rhokj^2;
                    -(rkx-rix-rhoji*cos(phiji))/rhokj^2;
                    (rhoji^2-rhoji*(cos(phiji)*(rkx-rix)+sin(phiji)*(rky-riy)))/rhokj^2;
                    (-sin(phiji)*(rkx-rix)+cos(phiji)*(rky-riy))/rhokj^2;
                    (rhoji^2-rhoji*(cos(phiji)*(rkx-rix)+sin(phiji)*(rky-riy)))/rhokj^2;
                    -1];
                Jac(k-1+[jcoun;jcoun+M],:) = [drange';
                    dbear'];
                var = [P0hat(1,1);%var(rix_est)
                    P0hat(2,2);%var(riy_est)
                    P0hat(5,5);%var(psii_est)
                    Rrange_ag;%var(rhoji)
                    Rbear_ag;%var(thetaji)
                    xk(j2).Pk(2*i-1,25)];%var(psij)
                cov_rixriy = P0hat(1,2);
                cov_rixpsii = P0hat(1,5);
                cov_riypsii = P0hat(2,5);
                % expected measurement error:
                Rrel(k+(jcoun+1)*M,k+(jcoun+1)*M) = Rrange(j2);
                Rrel(k+(jcoun+1)*M+M,k+(jcoun+1)*M+M) = Rbear(j2);
                %Rrel(k+(jcoun+1)*M,k+(jcoun+1)*M) = Rbear(j2);
                % expected error of agent j's range measurement in i's frame: 
                Rexp(k+(jcoun+1)*M,k+(jcoun+1)*M) = sum(drange.^2.*var) + 2*cov_rixriy*drange(1)*drange(2) + ...
                    2*cov_rixpsii*drange(1)*drange(3) + 2*cov_riypsii*drange(2)*drange(3);
                % expected error of agent j's bearing measurement in i's frame: 
                Rexp(k+(jcoun+1)*M+M,k+(jcoun+1)*M+M) = 10*(sum(dbear.^2.*var) + 2*cov_rixriy*dbear(1)*dbear(2) + ...
                    2*cov_rixpsii*dbear(1)*dbear(3) + 2*cov_riypsii*dbear(2)*dbear(3));
            end
        end
        % this bit probably only works for 2 agents, indexing is off
        Px = [P0hat([1 2 5],[1 2 5]) zeros(3);
            zeros(3) diag([Rrange_ag Rbear_ag xk(j2).Pk(2*i-1,25)])];
        Rexp(2*M+1:end,2*M+1:end) = Jac*Px*Jac';
        ye(j).yexp(i,:) = yexp';
        ye(j).ytilde(i,:) = ytilde';
        ye(j).Rexp(i,:) = reshape(Rexp+Rrel,[],1)';
        % compute the Kalman gain
        Kk = P0hat*Hk'*((Hk*P0hat*Hk'+Rexp+Rrel)\eye(2*N*M));
        % update the state
        x0hat = x0hat + Kk*(ytilde-yexp);
        x0hat(5) = pi2pi(x0hat(5));
        % update the covariance
        P0hat = (eye(5)-Kk*Hk)*P0hat;
        % store the variables
        xk(j).xk(2*i,:) = x0hat';
        xk(j).Pk(2*i,:) = reshape(P0hat,25,1)';
    end
    %% propagate
    for j = 1:N
        x0hat = xk(j).xk(2*i,:)';
        P0hat = reshape(xk(j).Pk(2*i,:)',5,5);
        ueff = ags(j).IMU(i,:);%a1 a2 w3
        Cp = [cos(x0hat(5)) -sin(x0hat(5));
            sin(x0hat(5)) cos(x0hat(5))];
        f = [Cp*x0hat(3:4);
            ueff(1)+ueff(3)*x0hat(4);
            ueff(2)-ueff(3)*x0hat(3);
            ueff(3)];
        % gradient of f w.r.t. w
        Fk = eye(5);
        Fk(1:2,3:4) = Ts*Cp;
        Fk(1:2,5) = Ts*[-sin(x0hat(5)) -cos(x0hat(5));
            cos(x0hat(5)) -sin(x0hat(5))]*x0hat(3:4);
        Fk(3,4) = Ts*ueff(3);
        Fk(4,3) = -Ts*ueff(3);
        % process noise influence matrix
        G = zeros(5,3);
        G(3,:) = [-Ts 0 -x0hat(4)*Ts];
        G(4,:) = [0 -Ts x0hat(3)*Ts];
        G(5,3) = -Ts;
        % propagated state
        x0hat = x0hat+f*Ts;
        % propagated covariance
        P0hat = Fk*P0hat*Fk'+G*Q*G';
        % pi2pi
        x0hat(5) = pi2pi(x0hat(5));
        % store updates
        xk(j).xk(2*i+1,:) = x0hat';
        xk(j).Pk(2*i+1,:) = reshape(P0hat,25,1)';
    end
    if ~mod(i,100)
        disp(i);
    end
end
%% plots
for K = 1:N
    xk(K).xk(:,5) = minangle(xk(K).xk(:,5),[ags(K).truth(1,5);ags(K).truth( sort(repmat(1:length(tspan),1,2)) ,5)]);
    
    figure;
    for i = 1:5
        subplot(5,1,i);
        plot(tk,xk(K).xk(:,i));
        hold on;
        plot(tspan,ags(K).truth(:,i),'r--');
    end
    
    figure;
    for i = 1:5
        subplot(5,1,i);
        plot(tspan,ags(K).truth(:,i)-xk(K).xk(2:2:end,i),'b-');
        hold on;
        plot(tspan,3*sqrt(xk(K).Pk(2:2:end,1+(i-1)*6)),'r--')
        plot(tspan,-3*sqrt(xk(K).Pk(2:2:end,1+(i-1)*6)),'r--')
    end
        
    figure
    for i = 1:3
        if K == 1
            K2 = 2;
        else
            K2 = 1;
        end
        % true agent j bearing to k
        delta = repmat( marks(i).xy,length(tspan),1) - ags(K2).truth(:,1:2);
        bt = pi2pi( atan2(delta(:,2),delta(:,1)) - ags(K2).truth(:,5) );
        % expected bearing, from agent i estimate and measurement
        delta2 = repmat( marks(i).xy,length(tspan),1) - xk(K).xk(2:2:end,1:2) - repmat(ags(K).rb_agent(:,1),1,2).*[cos(ags(K).rb_agent(:,2)+xk(K).xk(2:2:end,5)) sin(ags(K).rb_agent(:,2)+xk(K).xk(2:2:end,5))];
        bt2 = pi2pi( atan2(delta2(:,2),delta2(:,1)) - xk(K2).xk(2:2:end,5) );
        bt2 = minangle(bt2,bt);
        subplot(3,1,i);
        plot(tspan,bt-bt2)
        hold on;
        plot(tspan,3*sqrt( ye(K).Rexp(:,(i+9-1)*13+1)+Rrel((i+9-1)*13+1) ),'r--')
        plot(tspan,-3*sqrt( ye(K).Rexp(:,(i+9-1)*13+1)+Rrel((i+9-1)*13+1) ),'r--')
        fprintf('%g %% of bearing %i errors for agent %i exceed 3sigma\n',length( find(abs(bt-bt2) > 3*sqrt( ye(K).Rexp(:,(i+9-1)*13+1)+Rrel((i+9-1)*13+1)) ))/length(bt),i,K);
    end
end