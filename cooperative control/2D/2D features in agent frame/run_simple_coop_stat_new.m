%% run_simple_coop
%main file for running the cooperative estimation case. Data should be
%loaded and called outside of here, plots should be called outside, etc.,
%but this file generates data. Does not clear variables.
% 
% uses statistical linearization to get the computed covariance for
% cooperative measurements, instead of Jacobian

%% initialize

tk = [sort([tspan tspan]) tspan(end)+Ts];
xk(N) = struct('xk',zeros(length(tspan)*2+1,5),'Pk',zeros(length(tspan)*2+1,25));
ye = cell(length(tspan),N);
for i = 1:N
    %intialize state
    xk(i).xk(1,:) = ags(i).truth(1,1:5)';
    % convert inertial position to the body frame
    xk(i).xk(1,1:2) = ags(i).truth(1,1:2)*[cos(ags(i).truth(1,5)) -sin(ags(i).truth(1,5));
        sin(ags(i).truth(1,5)) cos(ags(i).truth(1,5))];
    %initialize covariance
    xk(i).Pk(1,:) = reshape( .1*eye(5)+.001*ones(5), 25,1)';
    %if i == 2
%     xk(i).Pk(1,:) = reshape( [1.5603   -0.3219    0.1505   -0.0257    0.0111
%    -0.3219    0.9997   -0.0158    0.1241    0.0101
%     0.1505   -0.0158    0.0271   -0.0022    0.0017
%    -0.0257    0.1241   -0.0022    0.0255    0.0008
%     0.0111    0.0101    0.0017    0.0008    0.0031],25,1)';
    %end
end
%% loop over all times

Qk = Rimu*Ts;% + Ts^2*eye(3);

for i = 1:length(tspan)
    %% update new measurements
    for j = 1:N
        ytilde = zeros(4*M,1);% doing this the lazy way for now
        yexp = zeros(4*M,1);
        Hk = zeros(4*M,5);
        % initialize the covariance matrix
        Rk = zeros(4*M);
        
        x0hat = xk(j).xk(2*i-1,1:5)';% rix,riy,u,v,psi - all are in body frame
        P0hat = reshape(xk(j).Pk(2*i-1,:)',5,5);
        psii = x0hat(5);
        %psii = ags(j).truth(i,5);
        rix = x0hat(1);
        riy = x0hat(2);
        
        measurement_count = 0;
        
        % iterate over the readmask
        if bitand(readmask,8) || bitand(readmask,4)
            % check that we are in the agent's FOV
            if bitand(readmask,8)
                % loop over each landmark
                for m = 1:M
                    if abs(ags(j).rb(i,m+M)) <= d2r*FOV(j) && abs(ags(j).rb(i,m)) < RANGE(j) && abs(ags(j).rb(i,m)) > RANGEMIN(j)%check that the measurement is less than the FOV
                        measurement_count = measurement_count+1;
                        ytilde(measurement_count) = ags(j).rb(i,m);
                        % measurement noise covariance
                        Rk(measurement_count,measurement_count) = Rrange(j);
                        %compute expectation
                        rkx = marks(m).xy(1);
                        rky = marks(m).xy(2);
                        Cbn = [cos(psii) sin(psii);-sin(psii) cos(psii)];
                        rki_b = Cbn*[rkx;rky]-[rix;riy];%body frame expectation of relative vector
                        rhoki = sqrt(sum( rki_b.^2 ));
                        yexp(measurement_count) = rhoki;
                        % compute gradient
                        Hk(measurement_count,:) = [-(2*rkx*cos(psii) - 2*rix + 2*rky*sin(psii))/(2*((riy - rky*cos(psii) + rkx*sin(psii))^2 + (rkx*cos(psii) - rix + rky*sin(psii))^2)^(1/2))
                            (2*riy - 2*rky*cos(psii) + 2*rkx*sin(psii))/(2*((riy - rky*cos(psii) + rkx*sin(psii))^2 + (rkx*cos(psii) - rix + rky*sin(psii))^2)^(1/2))
                            0
                            0
                            (2*(rkx*cos(psii) + rky*sin(psii))*(riy - rky*cos(psii) + rkx*sin(psii)) + 2*(rky*cos(psii) - rkx*sin(psii))*(rkx*cos(psii) - rix + rky*sin(psii)))/(2*((riy - rky*cos(psii) + rkx*sin(psii))^2 + (rkx*cos(psii) - rix + rky*sin(psii))^2)^(1/2))]';
                    end
                end
            end
            if bitand(readmask,4)
                % new bearing measures of landmarks
                %loop over each landmark
                for m = 1:M
                    if abs(ags(j).rb(i,m+M)) <= d2r*FOV(j) && abs(ags(j).rb(i,m)) < RANGE(j) && abs(ags(j).rb(i,m)) > RANGEMIN(j)%check that the measurement is less than the FOV
                        measurement_count = measurement_count+1;
                        % store measurement
                        ytilde(measurement_count) = ags(j).rb(i,M+m);
                        Rk(measurement_count,measurement_count) = Rbear(j);
                        % expectation
                        rkx = marks(m).xy(1);
                        rky = marks(m).xy(2);
                        Cbn = [cos(psii) sin(psii);-sin(psii) cos(psii)];
                        rki_b = Cbn*[rkx;rky]-[rix;riy];%body frame expectation of relative vector
                        % store expectation
                        yexp(measurement_count) = atan2(rki_b(2),rki_b(1));
                        % minimize the difference in the two angles
                        yexp(measurement_count) = minangle(yexp(measurement_count),ytilde(measurement_count));
                        % compute gradient
                        Hk(measurement_count,:) = [-(riy - rky*cos(psii) + rkx*sin(psii))/(rix^2 - 2*cos(psii)*rix*rkx - 2*sin(psii)*rix*rky + riy^2 + 2*sin(psii)*riy*rkx - 2*cos(psii)*riy*rky + rkx^2 + rky^2)
                            -(rkx*cos(psii) - rix + rky*sin(psii))/(rix^2 - 2*cos(psii)*rix*rkx - 2*sin(psii)*rix*rky + riy^2 + 2*sin(psii)*riy*rkx - 2*cos(psii)*riy*rky + rkx^2 + rky^2)
                            0
                            0
                            (rix*(rkx*cos(psii) + rky*sin(psii)) + riy*(rky*cos(psii) - rkx*sin(psii)) - rkx^2 - rky^2)/(rix^2 - 2*cos(psii)*rix*rkx - 2*sin(psii)*rix*rky + riy^2 + 2*sin(psii)*riy*rkx - 2*cos(psii)*riy*rky + rkx^2 + rky^2)]';
                    end
                end
            end
        end
        if bitand(readmask,2) || bitand(readmask,1)
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
                cooperative_count = 0;
                for j2 = [1:j-1 j+1:N]
                    % index used because each agent stores its
                    % measurements of the other agents differently than
                    % the `global' index
                    j2ind = j2;
                    if j2ind > j
                        j2ind = j2ind-1;
                    end
                    jjind = j;
                    if jjind > j
                        jjind = jjind-1;
                    end
                    % Rx is the covariance of uncertain values in the computed
                    % measurements
                    % these terms are: [rhoji thetaji thetaij rhokj thetakj (forall k)]
                    Rx = zeros(2*M+3);
                    Rx(1:3,1:3) = diag([Rrange_ag Rbear_ag Rbear_ag]);%initalize R for te fixed quantities only
                    % measured range to other agent
                    rhoji = ags(j).rb_agent(i,(j2ind-1)*2+1);
                    % measured bearing to other agent
                    thetaji = ags(j).rb_agent(i,(j2ind-1)*2+2);
                    % measured bearing by other agent
                    thetaij = ags(j2).rb_agent(i,(jjind-1)*2+2);
                    % vector of the real measurements, used for statistical linearization 
                    yeff = zeros(2*M+3,1);
                    yeff(1:3) = [rhoji;thetaji;thetaij];
                    % loop over each landmark
                    for m = 1:M
                        if abs(ags(j2).rb(i,m+M)) <= d2r*FOV(j2) && abs(ags(j2).rb(i,m)) < RANGE(j2) && abs(ags(j2).rb(i,m)) > RANGEMIN(j)
                            %for now we assume other agent measures both range
                            %and bearing
                            rhokj = ags(j2).rb(i,m); %other agent's range measure
                            thetakj = ags(j2).rb(i,m+M);% other agent's bearing measure
                            beta = thetaij - thetakj;
                            rkx = marks(m).xy(1);
                            rky = marks(m).xy(2);
                            
                            if bitand(readmask,2)
                                cooperative_count = cooperative_count+1;
                                measurement_count = measurement_count+1;
                                % store values for the statistical linearization 
                                yeff(3+cooperative_count) = rhokj;%range
                                yeff(3+cooperative_count+1) = thetakj;%bearing
                                % new range measure from other agents, CONVERTED
                                % INTO AGENT j's FRAME!
                                ytilde(measurement_count) = sqrt(rhokj^2+rhoji^2-2*rhokj*rhoji*cos(beta));% law of cosines
                                %compute expectation
                                Cbn = [cos(psii) sin(psii);-sin(psii) cos(psii)];
                                rki_b = Cbn*[rkx;rky]-[rix;riy];%body frame expectation of relative vector
                                rhoki = sqrt(sum( rki_b.^2 ));
                                yexp(measurement_count) = rhoki;
                                % compute gradient
                                Hk(measurement_count,:) = [-(2*rkx*cos(psii) - 2*rix + 2*rky*sin(psii))/(2*((riy - rky*cos(psii) + rkx*sin(psii))^2 + (rkx*cos(psii) - rix + rky*sin(psii))^2)^(1/2))
                                    (2*riy - 2*rky*cos(psii) + 2*rkx*sin(psii))/(2*((riy - rky*cos(psii) + rkx*sin(psii))^2 + (rkx*cos(psii) - rix + rky*sin(psii))^2)^(1/2))
                                    0
                                    0
                                    (2*(rkx*cos(psii) + rky*sin(psii))*(riy - rky*cos(psii) + rkx*sin(psii)) + 2*(rky*cos(psii) - rkx*sin(psii))*(rkx*cos(psii) - rix + rky*sin(psii)))/(2*((riy - rky*cos(psii) + rkx*sin(psii))^2 + (rkx*cos(psii) - rix + rky*sin(psii))^2)^(1/2))]';
                                % add term to Rx
                                Rx(3+cooperative_count,3+cooperative_count) = Rrange(j2);
                            end
                            if bitand(readmask,1)
                                cooperative_count = cooperative_count + 1;
                                measurement_count = measurement_count+1;
                                % new bearing measure from other agents, CONVERTED
                                % INTO AGENT j's FRAME!
                                rhoki_exp = sqrt(rhokj^2+rhoji^2-2*rhokj*rhoji*cos(beta));
                                ytilde(measurement_count) = pi + thetaji - thetaij + thetakj - atan2(( rhoji*sin(beta)/rhoki_exp ),( (rhoji^2-rhokj^2-rhoki_exp^2)/(-2*rhokj*rhoki_exp) ));
                                % expectation
                                Cbn = [cos(psii) sin(psii);-sin(psii) cos(psii)];
                                rki_b = Cbn*[rkx;rky]-[rix;riy];%body frame expectation of relative vector
                                % store expectation
                                yexp(measurement_count) = atan2(rki_b(2),rki_b(1));
                                % minimize the difference in the two angles
                                yexp(measurement_count) = minangle(yexp(measurement_count),ytilde(measurement_count));
                                % compute gradient
                                Hk(measurement_count,:) = [-(riy - rky*cos(psii) + rkx*sin(psii))/(rix^2 - 2*cos(psii)*rix*rkx - 2*sin(psii)*rix*rky + riy^2 + 2*sin(psii)*riy*rkx - 2*cos(psii)*riy*rky + rkx^2 + rky^2)
                                    -(rkx*cos(psii) - rix + rky*sin(psii))/(rix^2 - 2*cos(psii)*rix*rkx - 2*sin(psii)*rix*rky + riy^2 + 2*sin(psii)*riy*rkx - 2*cos(psii)*riy*rky + rkx^2 + rky^2)
                                    0
                                    0
                                    (rix*(rkx*cos(psii) + rky*sin(psii)) + riy*(rky*cos(psii) - rkx*sin(psii)) - rkx^2 - rky^2)/(rix^2 - 2*cos(psii)*rix*rkx - 2*sin(psii)*rix*rky + riy^2 + 2*sin(psii)*riy*rkx - 2*cos(psii)*riy*rky + rkx^2 + rky^2)]';
                                %measurement covariance
                                Rx(3+cooperative_count,3+cooperative_count) = Rbear(j2);
                                % store the predicted vector to this agent
                                % in the inertial frame, given the feature
                                % location and the measurements
%                                 ye{i,j} = [ye{i,j} ...
%                                     marks(m).xy' - ([cos(psij) -sin(psij);
%                                     sin(psij) cos(psij)]*rhokj*[cos(thetakj);sin(thetakj)]+...
%                                     [cos(psii) -sin(psii);
%                                     sin(psii) cos(psii)]*rhoji*[cos(thetaji);sin(thetaji)]) ];
                            end
                        end
                    end
                    if cooperative_count > 0
                        % compute the covariance using the sigma points
                        [y,Py] = statisticalLinearization(yeff(1:3+cooperative_count),Rx(1:3+cooperative_count,1:3+cooperative_count),@coopOutputFun);
                        % add extra error for heading sensitivity
                        %Rx(1:2,1:2) = 1e0*Rx(1:2,1:2);
                        Rk(measurement_count-(cooperative_count)+1:measurement_count,measurement_count-(cooperative_count)+1:measurement_count) = Py;
                        ytilde((measurement_count-cooperative_count+1):measurement_count) = y;
                    end
                end
            end
        end
        % if we get a new measurement, append it to the current list and
        % compute the expectation and gradient
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
        %xk(j).xk(2*i,5) = ags(j).truth(i,5);
        xk(j).Pk(2*i,:) = reshape(P0hat,25,1)';
    end
    %% propagate
    for j = 1:N
        x0hat = xk(j).xk(2*i,:)';
        P0hat = reshape(xk(j).Pk(2*i,:)',5,5);
        imu = ags(j).IMU(i,:)';% a1 a2 omega
        
        ri = x0hat(1:2);%body frame position vector
        vi = x0hat(3:4);%body frame velocity vector
        psii = x0hat(5);%heading
        omega = imu(3);
        ai = imu(1:2);
        % dxhat/dt
        f = [vi - [0 -omega;omega 0]*ri;
            ai - [0 -omega;omega 0]*vi;
            omega];
        %gradient of f
        Fk = [ -[0 -omega;omega 0] eye(2) zeros(2,1);
            zeros(2) -[0 -omega;omega 0] zeros(2,1);
            zeros(1,5)];
        % account for the discretized integration in Fk:
        Fk = Ts*Fk + eye(5);
        % process noise influence matirx
        G = zeros(5,3);
        G(3:5,1:3) = Ts*[-1 0 vi(2);
            0 -1 -vi(1);
            0 0 -1];
        %update
        x0hat = x0hat + Ts*f;
        P0hat = Fk*P0hat*Fk' + G*Qk*G';
        % store new values
        xk(j).xk(2*i+1,:) = x0hat';
        xk(j).Pk(2*i+1,:) = reshape(P0hat,25,1)';
    end
end