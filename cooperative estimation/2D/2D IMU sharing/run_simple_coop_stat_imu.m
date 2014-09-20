%% run_simple_coop_stat
%main file for running the cooperative estimation case. Data should be
%loaded and called outside of here, plots should be called outside, etc.,
%but this file generates data. Does not clear variables.
% 
% uses statistical linearization to get the computed covariance for
% cooperative measurements, instead of Jacobian

global marksUsed xhatk;%Qk; Qk is a global when we do numerical integration

marksVar = cell(N,1);
constrVar = cell(N,1);
for i = 1:N
    marksVar{i} = nan(length(tspan),M);
    constrVar{i} = nan(length(tspan),M);
end

%% initialize

tk = [sort([tspan tspan]) tspan(end)+Ts];
xk(N) = struct('xk',zeros(length(tspan)*2+1,5*N-2),'Pk',zeros(length(tspan)*2+1,(5*N-2)^2));
for i = 1:N
    xk(i) = struct('xk',zeros(length(tspan)*2+1,5*N-2),'Pk',zeros(length(tspan)*2+1,(5*N-2)^2));
    count = 0;
    Pnom = zeros(5*N-2);
    xk(i).xk(1,1:3) = ags(i).truth(1,3:5);
    
    Cbn = [cos(ags(i).truth(1,5)) sin(ags(i).truth(1,5));
        -sin(ags(i).truth(1,5)) cos(ags(i).truth(1,5))];
    Pnom(1:3,1:3) = diag([.64 .64 .01]) + .001*ones(3);
    for j = [1:i-1 i+1:N]
        count = count+1;
        %intialize state
        xk(i).xk(1,3+5*(count-1)+(3:4)) = ags(j).truth(1,3:4)';%agent j b_j frame velocity
        xk(i).xk(1,3+5*(count-1)+5) = ags(j).truth(1,5)' - ags(i).truth(1,5)';%relative heading
        % initialize relative position vector in agent i frame
        xk(i).xk(1,3+5*(count-1)+(1:2)) = (ags(j).truth(1,1:2)-ags(i).truth(1,1:2))*Cbn';
        % add noise
        %
        %initialize covariance
        Pnom(3+5*(count-1) + (1:5),3+5*(count-1) + (1:5)) = 0.001*ones(5) + diag([1.0 1.0 .64 .64 .01]);
    end
    xk(i).Pk(1,:) = reshape(Pnom,(5*N-2)^2,1)';
end
%% loop over all times

Qk = diag(repmat(diag(Rimu),N,1))*Ts;

for i = 1:length(tspan)
    %% update new measurements
    for j = 1:N
        %xk(j).xk(2*i,:) = xk(j).xk(2*i-1,:);
        %xk(j).Pk(2*i,:) = xk(j).Pk(2*i-1,:);
        %continue;
        ytilde = zeros(2*M+2,1);% measurements
        yexp = zeros(2*M+2,1);% expectations
        Hk = zeros(2*M+2,5);
        % initialize the covariance matrix
        Rk = zeros(2*M+2);
        
        x0hat = xk(j).xk(2*i-1,:)';% rix,riy,u,v,psi - all are in body frame
        P0hat = reshape(xk(j).Pk(2*i-1,:)',N*5-2,N*5-2);
        psii = x0hat(3);
        
        measurement_count = 0;
        
         % increment the relative sharing counter
        % only do this the first time since all agents use the same counter
        if j == 1
            update_counter = update_counter+1;
        end
        if update_counter == K_update % check if it's time to get a shared measurement
            if j == N
                % only reset the counter after all of the agents have
                % checked for sharing measurements fun time
                update_counter = 0;
            end
            for j2 = [1:j-1 j+1:N]
                % counter for the number of feature measurements we get
                % from each other agent. resets for each new other agent.
                cooperative_count = 0;
                % index used because each agent stores its
                % measurements of the other agents differently than
                % the `global' index
                j2ind = j2;
                if j2ind > j
                    j2ind = j2ind-1;
                end
                jjind = j;
                if jjind > j2
                    jjind = jjind-1;
                end
                
                % other agent's relative state, in his body frame
                rjix = xk(j).xk(2*i-1,(j2ind)*5+1-2);
                rjiy = xk(j).xk(2*i-1,(j2ind)*5+2-2);
                
                % now account for the relative range measurement
                measurement_count = measurement_count + 2;
                % measured range to other agent
                rhoji = ags(j).rb_agent(i,(j2ind-1)*2+1);
                % measured bearing to other agent
                thetaji = ags(j).rb_agent(i,(j2ind-1)*2+2);
                % store expectation
                rji_meas = rhoji*[cos(thetaji);sin(thetaji)]; % in i's body frame
                ytilde(measurement_count-1:measurement_count) = rji_meas; 
                yexp(measurement_count-1:measurement_count) = [rjix;rjiy];
                % gradient
                Hk = zeros(2*M+2,5*N-2);
                Hk(measurement_count-1:measurement_count,(1:2)+j2ind*5-2) = eye(2);%d/dr_j
                
                % Rx is the covariance of uncertain values in the computed measurements
                % these terms are: [rhoji thetaji {rhokj thetakj for all k}]
                Rx = zeros(2*M+2);
                Rx(1:2,1:2) = diag([Rrange_ag Rbear_ag]);%initalize R for te fixed quantities only
                % Jacobian
                Jac = zeros(2*M+2,2*M+2);
                Jac(1:2,1:2) = [ [cos(thetaji);sin(thetaji)] rhoji*[-sin(thetaji);cos(thetaji)] ];
                % vector of the real measurements, used for statistical linearization
                yeff = zeros(2*M+2,1);
                yeff(1:2) = [rhoji;thetaji];
                [y,Py] = statisticalLinearization(yeff(1:2+cooperative_count),Rx(1:2+cooperative_count,1:2+cooperative_count),@coopFunctionSharedIMU);
                ind = (measurement_count-cooperative_count-2+1):measurement_count;
                %Rk(ind,ind) = ...
                %    Jac(ind,ind)*Rx(ind,ind)*Jac(ind,ind)';
                
                ytilde(ind) = y;
                Rk(ind,ind) = Py;
            end
        end
        % if we get a new measurement, append it to the current list and
        % compute the expectation and gradient
        if measurement_count > 0
            % kalman gain
            if rank(Hk(1:measurement_count,:)*P0hat*Hk(1:measurement_count,:)' + Rk(1:measurement_count,1:measurement_count)) < measurement_count
                % if ill-conditioned, skip
                disp('singular matrix inversion, stopping');
                return;
            else
                Kk = P0hat*Hk(1:measurement_count,:)'*((Hk(1:measurement_count,:)*P0hat*Hk(1:measurement_count,:)' + Rk(1:measurement_count,1:measurement_count))\eye(measurement_count));
                % update estimate
                x0hat = x0hat + Kk*(ytilde(1:measurement_count)-yexp(1:measurement_count));
                % update covariance
                P0hat = (eye(size(Kk,1),size(Hk,2))-Kk*Hk(1:measurement_count,:))*P0hat;
            end
        end
        % store values
        xk(j).xk(2*i,:) = x0hat';
        xk(j).Pk(2*i,:) = reshape(P0hat,(N*5-2)^2,1)';
    end
    %% propagate
    for j = 1:N
        %xk(j).xk(2*i+1,:) = xk(j).xk(2*i,:);
        %xk(j).Pk(2*i+1,:) = xk(j).Pk(2*i,:);
        %continue;
        x0hat = xk(j).xk(2*i,:)';
        P0hat = reshape(xk(j).Pk(2*i,:)',N*5-2,N*5-2);
        imu = ags(j).IMU(i,:)';% a1 a2 omega
        % propagate own eqom:
        vi = x0hat(1:2);%body frame velocity vector
        psii = x0hat(3);%heading
        Cbin = [cos(psii) sin(psii);-sin(psii) cos(psii)];
        
        omega = imu(3);
        ai = imu(1:2);
        % dxhat/dt
        f = zeros(5*N-2,1);
        f(1:3) = [ai - [0 -omega;omega 0]*vi;
            omega];
        %gradient of f
        Fk = zeros(5*N-2,3*N);
        Fk(1:3,1:3) = [-[0 -omega;omega 0] zeros(2,1);
            zeros(1,3)];
        
        % process noise influence matirx
        G = zeros(5*N-2,3*N);
        G(1:3,1:3) = [-1 0 -vi(2);
            0 -1 vi(1);
            0 0 -1];
        % loop over each other agent
        cj = 0;
        for jj = [1:j-1 j+1:N]
            cj = cj+1;
            psiji = x0hat(3+5*cj);
            vj = x0hat([1 2]+5*cj);
            rji = x0hat([-1 0]+5*cj);
            imuj = ags(jj).IMU(i,:)';
            
            Cbjbi = [cos(psiji) sin(psiji);-sin(psiji) cos(psiji)];
            % time rate of relative position
            f([-1 0]+5*cj) = Cbjbi'*vj - vi - [0 -omega;omega 0]*rji;
            % time rate of j frame velocity
            f([1 2]+5*cj) = imuj(1:2) - [0 -imuj(3);imuj(3) 0]*vj;
            % time rate of relative heading
            f(3+5*cj) = imuj(3) - omega;
            % gradient
            Fk([-1 0]+5*cj,1:2) = -eye(2);
            Fk([-1 0]+5*cj,5*cj-2+[1:2]) = - [0 -omega;omega 0];%diff w.r.t rji
            Fk([-1 0]+5*cj,5*cj-2+[3:4]) = Cbjbi';%diff w.r.t. vj
            Fk([-1 0]+5*cj,5*cj-2+5) = [-sin(psiji) -cos(psiji);cos(psiji) -sin(psiji)]*vj;%diff w.r.t psiji
            
            Fk([1 2]+5*cj,5*cj-2+[3:4]) = -[0 -imuj(3);imuj(3) 0];%diff w.r.t. vj
            % process noise
            G([-1 0]+5*cj,3) = [-rji(2);rji(1)];
            G([1 2] +5*cj,cj*3+(1:2)) = -eye(2);
            G([1 2] +5*cj,cj*3+3) = [vj(2);-vj(1)];
            G(3+5*cj,3) = 1;
            G(3+5*cj,cj*3+3) = -1;
        end
        G = Ts*G;
        
        % account for the discretized integration in Fk:
        Fk = Ts*Fk + eye(5*N-2);
        %update own associated states
        x0hat = x0hat + Ts*f;
        x0hat(3) = pi2pi(x0hat(3));
        x0hat([8:5:5*N-2]) = pi2pi(x0hat([8:5:5*N-2]));
        P0hat = Fk*P0hat*Fk' + G*Qk*G';
        % store new values
        xk(j).xk(2*i+1,:) = x0hat';
        xk(j).Pk(2*i+1,:) = reshape(P0hat,(N*5-2)^2,1)';
    end
end