%% run_simple_coop_stat_new
%main file for running the cooperative estimation case. Data should be
%loaded and called outside of here, plots should be called outside, etc.,
%but this file generates data. Does not clear variables.
% 
% uses statistical linearization to get the computed covariance for
% cooperative measurements, instead of Jacobian

%% initialize

tk = [sort([tspan tspan]) tspan(end)+Ts];

if imu_sharing
    xk(N) = struct('xk',zeros(length(tspan)*2+1,5*N),'Pk',zeros(length(tspan)*2+1,(5*N)^2));
    for i = 1:N
        xk(i) = struct('xk',zeros(length(tspan)*2+1,5*N),'Pk',zeros(length(tspan)*2+1,(5*N)^2));
        %initialize state
        xk(i).xk(1,1:5) = ags(i).truth(1,1:5)';
        % convert inertial position to the body frame
        Cbn = [cos(ags(i).truth(1,5)) sin(ags(i).truth(1,5));
            -sin(ags(i).truth(1,5)) cos(ags(i).truth(1,5))];
        xk(i).xk(1,1:2) = ags(i).truth(1,1:2)*Cbn';
        %initialize relative states
        cj = 0;
        for j = [1:i-1 i+1:N]
            cj = cj+1;
            rji0 = ags(j).truth(1,1:2) - ags(i).truth(1,1:2);
            xk(i).xk(1,(1:2)+5*cj) = rji0*Cbn';
            xk(i).xk(1,(3:4)+5*cj) = ags(j).truth(1,3:4);
            xk(i).xk(1,5+5*cj) = ags(j).truth(1,5)-ags(i).truth(1,5);
        end
        xk(i).Pk(1,:) = reshape( 1*eye(5*N)+.0001*ones(5*N), (5*N)^2,1);
    end
else
    xk(N) = struct('xk',zeros(length(tspan)*2+1,5),'Pk',zeros(length(tspan)*2+1,25));
    for i = 1:N
        %intialize state
        xk(i).xk(1,:) = ags(i).truth(1,1:5)';
        % convert inertial position to the body frame
        xk(i).xk(1,1:2) = ags(i).truth(1,1:2)*[cos(ags(i).truth(1,5)) -sin(ags(i).truth(1,5));
            sin(ags(i).truth(1,5)) cos(ags(i).truth(1,5))];
        %initialize covariance
        xk(i).Pk(1,:) = reshape( 1.0*eye(5)+.001*ones(5), 25,1)';
    end
end
%% loop over all times

if imu_sharing
    Qk = diag(repmat(diag(Rimu)*Ts,N,1));
else
    Qk = Rimu*Ts;
end
Psize = sqrt(size(xk(j).Pk,2));

for i = 1:length(tspan)
    %% update new measurements
    for j = 1:N
        % call the update script - this is a massive thing with lots of logic 
        update_measurements_known;
        if measurement_count > 0
            % kalman gain
            if rank(Hk(1:measurement_count,:)*P0hat*Hk(1:measurement_count,:)' + Rk(1:measurement_count,1:measurement_count)) < measurement_count
                % if ill-conditioned, skip
                disp('singular matrix inversion, stopping');
                break;
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
        %store true heading
        xk(j).Pk(2*i,:) = reshape(P0hat,Psize^2,1)';
    end
    %% propagate
    for j = 1:N
        x0hat = xk(j).xk(2*i,:)';
        P0hat = reshape(xk(j).Pk(2*i,:)',Psize,Psize);
        
        % in the known feature case, we always progagate our measurements
        % the same way
        imu = ags(j).IMU(i,:)';% a1 a2 omega
        ri = x0hat(1:2);%body frame position vector
        vi = x0hat(3:4);%body frame velocity vector
        psii = x0hat(5);%heading
        omega = imu(3);
        ai = imu(1:2);
        % dxhat/dt
        f = zeros(size(x0hat));
        Fk = zeros(size(x0hat,1));
        f(1:5) = [vi - [0 -omega;omega 0]*ri;
            ai - [0 -omega;omega 0]*vi;
            omega];
        %gradient of f
        Fk(1:5,1:5) = [ -[0 -omega;omega 0] eye(2) zeros(2,1);
            zeros(2) -[0 -omega;omega 0] zeros(2,1);
            zeros(1,5)];
        if imu_sharing
            % process noise influence matirx
            G = zeros(5*N,3*N);
            % loop over each other agent
            cj = 0; % counter variable
            for jj = [1:j-1 j+1:N]
                cj = cj+1;
                psiji = x0hat(5+5*cj);
                vj = x0hat([3 4]+5*cj);
                rji = x0hat([1 2]+5*cj);
                imuj = ags(jj).IMU(i,:)';
                Cbjbi = [cos(psiji) sin(psiji);-sin(psiji) cos(psiji)];
                % time rate of relative position
                f([1 2]+5*cj) = Cbjbi'*vj - vi - [0 -omega;omega 0]*rji;
                % time rate of j frame velocity
                f([3 4]+5*cj) = imuj(1:2) - [0 -imuj(3);imuj(3) 0]*vj;
                % time rate of relative heading
                f(5+5*cj) = imuj(3) - omega;
                % gradient
                Fk([1 2]+5*cj,1:2) = -eye(2);
                Fk([1 2]+5*cj,5*cj+[1:2]) = - [0 -omega;omega 0];%diff w.r.t rji
                Fk([1 2]+5*cj,5*cj+[3:4]) = Cbjbi';%diff w.r.t. vj
                Fk([1 2]+5*cj,5*cj+5) = [-sin(psiji) -cos(psiji);cos(psiji) -sin(psiji)]*vj;%diff w.r.t psiji
                Fk([3 4]+5*cj,5*cj+[3:4]) = -[0 -imuj(3);imuj(3) 0];%diff w.r.t. vj
                % process noise
                G([1 2]+5*cj,3) = [-rji(2);rji(1)];
                G([3 4]+5*cj,cj*3+(1:2)) = -eye(2);
                G([3 4]+5*cj,cj*3+3) = [vj(2);-vj(1)];
                G(5+5*cj,3) = 1;
                G(5+5*cj,cj*3+3) = -1;
            end
            G = Ts*G;
        else
            % process noise influence matirx
            G = zeros(5,3);
        end
        % account for the discretized integration in Fk:
        Fk = Ts*Fk + eye(size(Fk));
        % remaining process noise
        G(1:2,3) = Ts*[-ri(2);ri(1)];
        G(3:5,1:3) = Ts*[-1 0 -vi(2);
            0 -1 vi(1);
            0 0 -1];
        %update
        x0hat = x0hat + Ts*f;
        x0hat(5:5:end) = pi2pi(x0hat(5:5:end));
        P0hat = Fk*P0hat*Fk' + G*Qk*G';
        % store new values
        xk(j).xk(2*i+1,:) = x0hat';
        xk(j).Pk(2*i+1,:) = reshape(P0hat,Psize^2,1)';
    end
end