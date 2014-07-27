%% run_simple_coop
%main file for running the cooperative estimation case. Data should be
%loaded and called outside of here, plots should be called outside, etc.,
%but this file generates data. Does not clear variables.

%% initialize

clear xk;
tk = [sort([tspan tspan]) tspan(end)+Ts];
xk(N) = struct('xk',zeros(length(tspan)*2+1,3+2*M),'Pk',zeros(length(tspan)*2+1,(3+2*M)^2));
for i = 1:N-1
    xk(i) = struct('xk',zeros(length(tspan)*2+1,3+2*M),'Pk',zeros(length(tspan)*2+1,(3+2*M)^2));
end
ye = cell(length(tspan),N);
for i = 1:N
    %intialize state
    xk(i).xk(1,1:3) = ags(i).truth(1,3:5)';
    % true initial inertial position
    Cbn = [cos(ags(i).truth(1,5)) sin(ags(i).truth(1,5));
        -sin(ags(i).truth(1,5)) cos(ags(i).truth(1,5))];
    xkb_true = ags(i).truth(1,1:2)*Cbn';
    markxy = zeros(M,2);
    for k = 1:M
        % feature location in the body frame
        markxy(k,:) = marks(k).xy*Cbn';
    end
    xk(i).xk(1,4:end) = reshape((markxy - repmat(xkb_true,M,1))',[],1)';
    %initialize covariance
    xk(i).Pk(1,:) = reshape( 1*eye(3+2*M)+.01*ones(3+2*M), (3+2*M)^2,1)';
end
%% loop over all times

Qk = Rimu*Ts;% + Ts^2*eye(3);

for i = 1:length(tspan)
    %% update new measurements
    for j = 1:N
        ytilde = zeros(4*M,1);% doing this the lazy way for now
        yexp = zeros(4*M,1);
        Hk = zeros(4*M,3+2*M);
        % initialize the covariance matrix
        Rk = zeros(4*M);
        
        x0hat = xk(j).xk(2*i-1,:)';% u,v,psi,rkix,rkiy \forall i - all are in body frame
        P0hat = reshape(xk(j).Pk(2*i-1,:)',3+2*M,3+2*M);
        psii = x0hat(3);
        %psii = ags(j).truth(i,5);
        %rix = x0hat(1);
        %riy = x0hat(2);
        
        measurement_count = 0;
        
        % iterate over the readmask
        if bitand(readmask,8) || bitand(readmask,4)
            % check that we are in the agent's FOV
            if bitand(readmask,8)
                % loop over each landmark
                for m = 1:M
                    % relative position coordinates in the body frame
                    rkix = x0hat(3+(m-1)*2+1);
                    rkiy = x0hat(3+(m-1)*2+2);
                    if abs(ags(j).rb(i,m+M)) <= d2r*FOV(j) && abs(ags(j).rb(i,m)) < RANGE(j) && abs(ags(j).rb(i,m)) > RANGEMIN(j)%check that the measurement is less than the FOV
                        measurement_count = measurement_count+1;
                        ytilde(measurement_count) = ags(j).rb(i,m);
                        % measurement noise covariance
                        Rk(measurement_count,measurement_count) = Rrange(j);
                        %compute expectation
                        rhoki = sqrt(sum( rkix^2+rkiy^2 ));
                        yexp(measurement_count) = rhoki;
                        % compute gradient w.r.t these states
                        Hk(measurement_count,3+(m-1)*2+(1:2)) = [rkix/(rkix^2 + rkiy^2)^(1/2);
                            rkiy/(rkix^2 + rkiy^2)^(1/2)]';
                    end
                end
            end
            if bitand(readmask,4)
                % new bearing measures of landmarks
                %loop over each landmark
                for m = 1:M
                    % relative position coordinates in the body frame
                    rkix = x0hat(3+(m-1)*2+1);
                    rkiy = x0hat(3+(m-1)*2+2);
                    if abs(ags(j).rb(i,m+M)) <= d2r*FOV(j) && abs(ags(j).rb(i,m)) < RANGE(j) && abs(ags(j).rb(i,m)) > RANGEMIN(j)%check that the measurement is less than the FOV
                        measurement_count = measurement_count+1;
                        % store measurement
                        ytilde(measurement_count) = ags(j).rb(i,M+m);
                        Rk(measurement_count,measurement_count) = Rbear(j);
                        % expectation
                        yexp(measurement_count) = atan2(rkiy,rkix);
                        % minimize the difference in the two angles
                        yexp(measurement_count) = minangle(yexp(measurement_count),ytilde(measurement_count));
                        % compute gradient
                        Hk(measurement_count,3+(m-1)*2+(1:2)) = [-rkiy/(rkix^2 + rkiy^2);
                            rkix/(rkix^2 + rkiy^2)]';
                    end
                end
            end
        end
        if bitand(readmask,2) || bitand(readmask,1)
            % increment the relative sharing counter
            update_counter = update_counter+1;
            if update_counter == K_update % check if it's time to get a shared measurement
                update_counter = 0;
                cooperative_count = 0;
                for j2 = [1:j-1 j+1:N]
                    % index used because each agent stores its
                    % measurements of the other agents differently than
                    % the `global' index
                    j2ind = j2;
                    if j2ind > j
                        j2ind = j2ind-1;
                    end
                    % Rx is the covariance of uncertain values in the computed
                    % measurements
                    % these terms are: [psii psij rhoji thetaji rhokj thetakj (forall k)]
                    Rx = zeros(2*M+4);
                    Rx(1:4,1:4) = diag([P0hat(5,5) xk(j2).Pk(2*i-1,end) Rrange_ag Rbear_ag]);%initalize R for te fixed quantities only
                    % jacobian of computed measurements w.r.t. real
                    % measurements, ASSUMES BOTH RANGE AND BEARING AVAILABLE
                    Jac = zeros(2*M,4+2*M);
                    % measured range to other agent
                    rhoji = ags(j).rb_agent(i,(j2ind-1)*2+1);
                    % measured bearing to other agent
                    thetaji = ags(j).rb_agent(i,(j2ind-1)*2+2);
                    % heading of other agent
                    psij = xk(j2).xk(2*i-1,5);
                    %psij = ags(j2).truth(i,5);
                    % loop over each landmark
                    for m = 1:M
                        if abs(ags(j2).rb(i,m+M)) <= d2r*FOV(j2) && abs(ags(j2).rb(i,m)) < RANGE(j2) && abs(ags(j2).rb(i,m)) > RANGEMIN(j)
                            %for now we assume other agent measures both range
                            %and bearing
                            rhokj = ags(j2).rb(i,m); %other agent's range measure
                            thetakj = ags(j2).rb(i,m+M);% other agent's bearing measure
                            alpha = pi-thetakj-psij+psii+thetaji;
                            if bitand(readmask,2)
                                cooperative_count = cooperative_count+1;
                                measurement_count = measurement_count+1;
                                rkx = marks(m).xy(1);
                                rky = marks(m).xy(2);
                                % new range measure from other agents, CONVERTED
                                % INTO AGENT j's FRAME!
                                ytilde(measurement_count) = sqrt(rhokj^2+rhoji^2-2*rhokj*rhoji*cos(alpha));% law of cosines
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
                                % compute covariance
                                Jac(cooperative_count,[1 2 3 4 (4+cooperative_count+(0:1))]) = [-(rhoji*rhokj*sin(psii - psij + thetaji - thetakj))/(rhoji^2 + 2*cos(psii - psij + thetaji - thetakj)*rhoji*rhokj + rhokj^2)^(1/2)
                                    (rhoji*rhokj*sin(psii - psij + thetaji - thetakj))/(rhoji^2 + 2*cos(psii - psij + thetaji - thetakj)*rhoji*rhokj + rhokj^2)^(1/2)
                                    (rhoji + rhokj*cos(psii - psij + thetaji - thetakj))/(rhoji^2 + 2*cos(psii - psij + thetaji - thetakj)*rhoji*rhokj + rhokj^2)^(1/2)
                                    -(rhoji*rhokj*sin(psii - psij + thetaji - thetakj))/(rhoji^2 + 2*cos(psii - psij + thetaji - thetakj)*rhoji*rhokj + rhokj^2)^(1/2)
                                    (rhokj + rhoji*cos(psii - psij + thetaji - thetakj))/(rhoji^2 + 2*cos(psii - psij + thetaji - thetakj)*rhoji*rhokj + rhokj^2)^(1/2)
                                    (rhoji*rhokj*sin(psii - psij + thetaji - thetakj))/(rhoji^2 + 2*cos(psii - psij + thetaji - thetakj)*rhoji*rhokj + rhokj^2)^(1/2)]';
                                % add term to Rx
                                Rx(4+cooperative_count,4+cooperative_count) = Rrange(j2);
                            end
                            if bitand(readmask,1)
                                cooperative_count = cooperative_count + 1;
                                measurement_count = measurement_count+1;
                                rkx = marks(m).xy(1);
                                rky = marks(m).xy(2);
                                % new bearing measure from other agents, CONVERTED
                                % INTO AGENT j's FRAME!
                                ytilde(measurement_count) = thetaji - atan2((2*rhoji*rhokj*sin(psii - psij + thetaji - thetakj)),(rhoji^2 + rhoki^2 - rhokj^2));
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
                                % compute the measurement covariance
                                Jac(cooperative_count,[1 2 3 4 (4+cooperative_count+(-1:0))]) = [(2*rhoji*rhokj*cos(psii - psij + thetaji - thetakj))/(((4*rhoji^2*rhokj^2*(cos(psii - psij + thetaji - thetakj)^2 - 1))/(rhoji^2 + rhoki^2 - rhokj^2)^2 - 1)*(rhoji^2 + rhoki^2 - rhokj^2))
                                    -(2*rhoji*rhokj*cos(psii - psij + thetaji - thetakj))/(((4*rhoji^2*rhokj^2*(cos(psii - psij + thetaji - thetakj)^2 - 1))/(rhoji^2 + rhoki^2 - rhokj^2)^2 - 1)*(rhoji^2 + rhoki^2 - rhokj^2))
                                    -(sin(psii - psij + thetaji - thetakj)*((2*rhokj)/(rhoji^2 + rhoki^2 - rhokj^2) - (4*rhoji^2*rhokj)/(rhoji^2 + rhoki^2 - rhokj^2)^2))/((4*rhoji^2*rhokj^2*sin(psii - psij + thetaji - thetakj)^2)/(rhoji^2 + rhoki^2 - rhokj^2)^2 + 1)
                                    (2*rhoji*rhokj*cos(psii - psij + thetaji - thetakj))/(((4*rhoji^2*rhokj^2*(cos(psii - psij + thetaji - thetakj)^2 - 1))/(rhoji^2 + rhoki^2 - rhokj^2)^2 - 1)*(rhoji^2 + rhoki^2 - rhokj^2)) + 1
                                    -(sin(psii - psij + thetaji - thetakj)*((2*rhoji)/(rhoji^2 + rhoki^2 - rhokj^2) + (4*rhoji*rhokj^2)/(rhoji^2 + rhoki^2 - rhokj^2)^2))/((4*rhoji^2*rhokj^2*sin(psii - psij + thetaji - thetakj)^2)/(rhoji^2 + rhoki^2 - rhokj^2)^2 + 1)
                                    -(2*rhoji*rhokj*cos(psii - psij + thetaji - thetakj))/(((4*rhoji^2*rhokj^2*(cos(psii - psij + thetaji - thetakj)^2 - 1))/(rhoji^2 + rhoki^2 - rhokj^2)^2 - 1)*(rhoji^2 + rhoki^2 - rhokj^2))]';
                                Rx(4+cooperative_count,4+cooperative_count) = Rbear(j2);
                                % store the predicted vector to this agent
                                % in the inertial frame, given the feature
                                % location and the measurements
                                ye{i,j} = [ye{i,j} ...
                                    marks(m).xy' - ([cos(psij) -sin(psij);
                                    sin(psij) cos(psij)]*rhokj*[cos(thetakj);sin(thetakj)]+...
                                    [cos(psii) -sin(psii);
                                    sin(psii) cos(psii)]*rhoji*[cos(thetaji);sin(thetaji)]) ];
                            end
                        end
                    end
                    if cooperative_count > 0
                        if rank(Jac(1:cooperative_count,1:(4+cooperative_count))*Rx(1:(4+cooperative_count),1:(4+cooperative_count))*Jac(1:cooperative_count,1:(4+cooperative_count))') < cooperative_count
                           1;
                        end
                        % add extra error for heading sensitivity
                        Rx(1:2,1:2) = 1e0*Rx(1:2,1:2);
                        Rk(measurement_count-(cooperative_count)+1:measurement_count,measurement_count-(cooperative_count)+1:measurement_count) = Jac(1:cooperative_count,1:(4+cooperative_count))*Rx(1:(4+cooperative_count),1:(4+cooperative_count))*Jac(1:cooperative_count,1:(4+cooperative_count))';
                        % remove off-diagonal terms
                        Rk(measurement_count-(cooperative_count)+1:measurement_count,measurement_count-(cooperative_count)+1:measurement_count) = eye(cooperative_count).*(Rk(measurement_count-(cooperative_count)+1:measurement_count,measurement_count-(cooperative_count)+1:measurement_count));
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
        xk(j).Pk(2*i,:) = reshape(P0hat,(3+2*M)^2,1)';
    end
    %% propagate
    for j = 1:N
        x0hat = xk(j).xk(2*i,:)';
        P0hat = reshape(xk(j).Pk(2*i,:)',3+2*M,3+2*M);
        imu = ags(j).IMU(i,:)';% a1 a2 omega
        
        rki = [x0hat(4:2:end) x0hat(5:2:end)];%body frame relative position vectors
        vi = x0hat(1:2);%body frame velocity vector
        psii = x0hat(3);%heading
        omega = imu(3);
        ai = imu(1:2);
        % time rate
        f = zeros(size(x0hat));
        % dxhat/dt
        f(1:3) = [ai - [0 -omega;omega 0]*vi;
            omega];
        for m = 1:M
            f(3 + (1:2) + 2*(m-1)) = -vi - [0 -omega;omega 0]*rki(m,:)';
        end
        %gradient of f
        Fk = zeros(length(f),3+2*M);
        Fk(1:2,1:2) = -[0 -omega;omega 0];
        % position derivatives w.r.t. u,v
        Fk(4:2:end,1) = -1;
        Fk(5:2:end,2) = -1;
        %postion derivatives w.r.t. position
        for m = 1:M
            Fk(3 + 1 + 2*(m-1),3 + 2 + 2*(m-1)) = omega;
            Fk(3 + 2 + 2*(m-1),3 + 1 + 2*(m-1)) = -omega;
        end
        % account for the discretized integration in Fk:
        Fk = Ts*Fk + eye(3+2*M);
        % process noise influence matirx
        G = zeros(3+2*M,3);
        G(1:3,1:3) = Ts*[-1 0 vi(2);
            0 -1 -vi(1);
            0 0 -1];
        %update
        x0hat = x0hat + Ts*f;
        P0hat = Fk*P0hat*Fk' + G*Qk*G';
        % store new values
        xk(j).xk(2*i+1,:) = x0hat';
        xk(j).Pk(2*i+1,:) = reshape(P0hat,(3+2*M)^2,1)';
    end
end