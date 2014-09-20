%% run_simple_unknown

%% initialize


tk = [sort([tspan tspan]) tspan(end)+Ts];

if imu_sharing
    disp('We don''t handle the IMU sharing case yet');
    return;
else
    % I'm estimating my state and up to 4 states per feature
    % Nf is the number of features I've seen so far
    % fl is a list of the feature seen so far (uses same numbers as the global notation 
    xk(N) = struct('xk',zeros(length(tspan)*2+1,5+4*M*N),'Pk',zeros(length(tspan)*2+1,(5+4*M*N)^2),'Nf',0,'fl',zeros(M,1));
    for i = 1:N
        xk(i) = struct('xk',zeros(length(tspan)*2+1,5+4*M*N),'Pk',zeros(length(tspan)*2+1,(5+4*M*N)^2),'Nf',0,'fl',zeros(M,1));
        % initialize my state: rx, ry, vx, vy, heading. position is in the inertial frame again
        % we initialize my position and heading to zero, just for lulz
        xk(i).xk(1,3:4) = ags(i).truth(1,3:4)';
        % initialize the covariance associated with my states
        xk(i).Pk(1,:) = reshape( [diag([1 1 .25 .25 .01])+.0001*ones(5) zeros(5,4*M*N);zeros(4*M*N,5+4*M*N)], (4*M*N+5)^2 , 1);
        %xk(i).Pk(1,:) = reshape( [diag([1 1 .25 .25 .01])+1e-6*ones(5) 1e-6*ones(5,4*M*N);.0001*ones(4*M*N,5+4*M*N)+1e-6*ones(4*M*N,5+4*M*N)], (4*M*N+5)^2 , 1);
    end
end

%% loop over all times

if imu_sharing
else
    Qk = Rimu*Ts;
end

for i = 1:length(tspan)
    %% update
    for j = 1:N
%         if i > 1
%             xk(j).xk(2*i,:) = xk(j).xk(2*i-1,:);
%             xk(j).Pk(2*i,:) = xk(j).Pk(2*i-1,:);
%             continue;
%         end
        update_measurements_unknown;
        if measurement_count > 0
            % kalman gain
            if rank(Hk(1:measurement_count,1:5+4*Nf)*Puse*Hk(1:measurement_count,1:5+4*Nf)' + Rk(1:measurement_count,1:measurement_count)) < measurement_count
                % if ill-conditioned, skip
                disp('singular matrix inversion, stopping');
                break;
            else
                %Kk = P0hat*Hk(1:measurement_count,:)'*((Hk(1:measurement_count,:)*P0hat*Hk(1:measurement_count,:)' + Rk(1:measurement_count,1:measurement_count))\eye(measurement_count));
                Kk = Puse*Hk(1:measurement_count,1:5+4*Nf)'*((Hk(1:measurement_count,1:5+4*Nf)*Puse*Hk(1:measurement_count,1:5+4*Nf)' + Rk(1:measurement_count,1:measurement_count))\eye(measurement_count));
                % update estimate
                x0hat(1:5+4*Nf) = x0hat(1:5+4*Nf) + Kk*(ytilde(1:measurement_count)-yexp(1:measurement_count));
                % update covariance
                Puse = (eye(size(Kk,1),5+4*Nf)-Kk*Hk(1:measurement_count,1:5+4*Nf))*Puse;
                P0hat(1:5+4*Nf,1:5+4*Nf) = Puse;
            end
        end
        % store values
        xk(j).xk(2*i,:) = x0hat';
        %store true heading
        xk(j).Pk(2*i,:) = reshape(P0hat,(4*M*N+5)^2,1)';
        % store number of features
        xk(j).Nf = Nf;
    end
    %% propagate
    for j = 1:N
        if imu_sharing
            
        else
            Nf = xk(j).Nf;
            x0hat = xk(j).xk(2*i,1:(5+4*Nf))';
            P0hat = reshape( xk(j).Pk(2*i,:), 4*M*N+5, 4*M*N+5 );
            Puse = P0hat(1:(5+4*Nf),1:(5+4*Nf));
            imu = ags(j).IMU(i,:)';% a1 a2 omega
            % vehicle states
            psii = x0hat(5);
            rb = x0hat(1:2);%inertial-frame position, relative to initial 
            vb = x0hat(3:4);%body-frame velocity
            % inertial-to-body DCM
            Cbn = [cos(psii) sin(psii);-sin(psii) cos(psii)];
            omega = imu(3);
            ai = imu(1:2);
            % dxhat/dt
            f = zeros(size(x0hat));
            Fk = zeros(size(x0hat,1));
            f(1:5) = [Cbn'*vb;
                ai - [0 -omega;omega 0]*vb;
                omega];
            %gradient of f
            Fk(1:5,1:5) = [zeros(2) Cbn' [-sin(psii) -cos(psii);cos(psii) -sin(psii)]*vb;
                zeros(2) -[0 -omega;omega 0] zeros(2,1);
                zeros(1,5)];
            % the other states are all constant
            % account for the discretized integration in Fk:
            Fk = Ts*Fk + eye(size(Fk));
            % process noise influence matrix
            G = zeros(size(x0hat,1),3);
            G(3:5,1:3) = Ts*[-1 0 -vb(2);
                0 -1 vb(1);
                0 0 -1];
            x0hat = x0hat + Ts*f;
            x0hat(5) = pi2pi(x0hat(5));
            Puse = Fk*Puse*Fk' + G*Qk*G';
            P0hat(1:(5+4*Nf),1:(5+4*Nf)) = Puse;
            % store new values
            xk(j).xk(2*i+1,1:(5+4*Nf)) = x0hat';
            xk(j).Pk(2*i+1,:) = reshape(P0hat,(4*M*N+5)^2,1)';
        end
    end
end