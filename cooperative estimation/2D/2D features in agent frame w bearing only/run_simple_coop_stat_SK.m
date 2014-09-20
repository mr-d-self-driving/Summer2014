%% run_simple_coop_stat_SK
%main file for running the cooperative estimation case. Data should be
%loaded and called outside of here, plots should be called outside, etc.,
%but this file generates data. Does not clear variables.
% 
% uses statistical linearization to get the computed covariance for
% cooperative measurements, instead of Jacobian
%
% uses Schmidt-Kalman style propagation and update assumptions, using the
% most recent measurements of interagent bearing and range as the
% ``nuisance'' states

%% initialize

tk = [sort([tspan tspan]) tspan(end)+Ts];
xk(N) = struct('xk',zeros(length(tspan)*2+1,5),'Pk',zeros(length(tspan)*2+1,25),'Ck',zeros(length(tspan)*2+1,5*2),'Bk',zeros(length(tspan)*2+1,2*2));
ye = cell(length(tspan),N);
for i = 1:N
    xk(i) = struct('xk',zeros(length(tspan)*2+1,5),'Pk',zeros(length(tspan)*2+1,25),'Ck',zeros(length(tspan)*2+1,5*2),'Bk',zeros(length(tspan)*2+1,2*2));
    %intialize state
    xk(i).xk(1,:) = ags(i).truth(1,1:5)';
    % convert inertial position to the body frame
    xk(i).xk(1,1:2) = ags(i).truth(1,1:2)*[cos(ags(i).truth(1,5)) -sin(ags(i).truth(1,5));
        sin(ags(i).truth(1,5)) cos(ags(i).truth(1,5))];
    %initialize covariance
    xk(i).Pk(1,:) = reshape( diag([1 1 1 1 1]) +.01*ones(5), 25,1)';
    % cross-covariance between estimated and nuisance states
    xk(i).Ck(1,:) = reshape( 1e-4*ones(5,2), 10,1)';
    % variance of nuisance states from the measurment noise:
    xk(i).Bk(1,:) = reshape( diag([Rrange_ag Rbear_ag]), 4,1)';
end
%% loop over all times

Qk = Rimu*Ts;% + Ts^2*eye(3);

for i = 1:length(tspan)
    %% update new measurements
    for j = 1:N
        ytilde = zeros(2*M,1);% doing this the lazy way for now
        yexp = zeros(2*M,1);
        Hx = zeros(2*M,5);
        % initialize the covariance matrix
        Rk = zeros(2*M);
        
        x0hat = xk(j).xk(2*i-1,1:5)';% rix,riy,u,v,psi - all are in body frame
        P0hat = reshape(xk(j).Pk(2*i-1,:)',5,5);
        C0hat = reshape(xk(j).Ck(2*i-1,:)',5,2);
        B0hat = reshape(xk(j).Bk(2*i-1,:)',2,2);
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
                        Hx(measurement_count,:) = [-(2*rkx*cos(psii) - 2*rix + 2*rky*sin(psii))/(2*((riy - rky*cos(psii) + rkx*sin(psii))^2 + (rkx*cos(psii) - rix + rky*sin(psii))^2)^(1/2))
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
                        Hx(measurement_count,:) = [-(riy - rky*cos(psii) + rkx*sin(psii))/(rix^2 - 2*cos(psii)*rix*rkx - 2*sin(psii)*rix*rky + riy^2 + 2*sin(psii)*riy*rkx - 2*cos(psii)*riy*rky + rkx^2 + rky^2)
                            -(rkx*cos(psii) - rix + rky*sin(psii))/(rix^2 - 2*cos(psii)*rix*rkx - 2*sin(psii)*rix*rky + riy^2 + 2*sin(psii)*riy*rkx - 2*cos(psii)*riy*rky + rkx^2 + rky^2)
                            0
                            0
                            (rix*(rkx*cos(psii) + rky*sin(psii)) + riy*(rky*cos(psii) - rkx*sin(psii)) - rkx^2 - rky^2)/(rix^2 - 2*cos(psii)*rix*rkx - 2*sin(psii)*rix*rky + riy^2 + 2*sin(psii)*riy*rkx - 2*cos(psii)*riy*rky + rkx^2 + rky^2)]';
                    end
                end
            end
        end
        cooperative_count = 0;
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
                for j2 = [1:j-1 j+1:N]
                    % index used because each agent stores its
                    % measurements of the other agents differently than
                    % the `global' index
                    j2ind = j2;
                    jjind = j;
                    if j2ind > j
                        j2ind = j2ind-1;
                    end
                    if jjind > j2
                        jjind = jjind-1;
                    end
                    % measured range to other agent
                    rhoji = ags(j).rb_agent(i,(j2ind-1)*2+1);
                    % measured bearing to other agent
                    thetaji = ags(j).rb_agent(i,(j2ind-1)*2+2);
                    % measured bearing by other agent to current agent
                    thetaij = ags(j2).rb_agent(i,(jjind-1)*2+2);
                    % Gx: gradient of the nuisance state equations w.r.t the estimated states 
                    Gx = zeros(M,5);
                    % Gz: gradient of the nuisance state equation w.r.t. the nuisance states 
                    Gz = zeros(M,2);
                    % Rx is the covariance of uncertain values in the computed
                    % measurements
                    % these terms are: [thetaji thetaij {thetakj forall k}]
                    Rx = zeros(M+2);
                    Rx(1:2,1:2) = diag([Rbear_ag Rbear_ag]);
                    % vector of the real measurements, used for statistical linearization 
                    yeff = zeros(M+2,1);
                    yeff(1:2) = [thetaji;thetaij];
                    % loop over each landmark
                    for m = 1:M
                        % landmark position in inertial frame
                        rkx = marks(m).xy(1);
                        rky = marks(m).xy(2);
                        if abs(ags(j2).rb(i,m+M)) <= d2r*FOV(j2) && abs(ags(j2).rb(i,m)) < RANGE(j2) && abs(ags(j2).rb(i,m)) > RANGEMIN(j)
                            if bitand(readmask,1)
                                cooperative_count = cooperative_count+1;
                                measurement_count = measurement_count+1;
                                % other agent's bearing measure
                                thetakj = ags(j2).rb(i,m+M);
                                % we have to get the ESTIMATED range from i to k,
                                % and covariance, from my estiamted state
                                Cbin = [cos(psii) sin(psii);-sin(psii) cos(psii)];%inertial-to-b_i transformation
                                rki_bi = Cbin*[rkx;rky]-[rix;riy];%body frame expectation of relative vector
                                delta = pi - thetaij + thetaji;
                                ytilde(measurement_count) = tan(thetakj + delta);
                                % expectation
                                yexp(measurement_count) = (rki_bi(2)-rhoji*sin(thetaji))/(rki_bi(1)-rhoji*cos(thetaji));
                                % add bearing measurement variance term to Rx
                                Rx(2+cooperative_count,2+cooperative_count) = Rbear(j2);
                                % store values for the statistical linearization
                                yeff(2+cooperative_count) = thetakj;%range
                                % compute gradient of ``expectation'' w.r.t estimated states 
                                Gx(cooperative_count,:) = [-(riy - rky*cos(psii) + rkx*sin(psii) + rhoji*sin(thetaji))/(rix - rkx*cos(psii) + rhoji*cos(thetaji) - rky*sin(psii))^2
                                    1/(rix - rkx*cos(psii) + rhoji*cos(thetaji) - rky*sin(psii))
                                    0
                                    0
                                    (cos(psii)*(rix*rkx + riy*rky) - rkx^2 - rky^2 + rix*rky*sin(psii) - riy*rkx*sin(psii) + rhoji*rkx*cos(psii + thetaji) + rhoji*rky*sin(psii + thetaji))/(rix - rkx*cos(psii) + rhoji*cos(thetaji) - rky*sin(psii))^2]';
                                % compute gradient w.r.t. ``nuisance'' un-estimated states 
                                Gz(cooperative_count,:) = [(rky*cos(psii + thetaji) - rkx*sin(psii + thetaji) - riy*cos(thetaji) + rix*sin(thetaji))/(rix - rkx*cos(psii) + rhoji*cos(thetaji) - rky*sin(psii))^2
                                    (rhoji*(rhoji - rkx*cos(psii + thetaji) + rix*cos(thetaji) + riy*sin(thetaji)) - rhoji*rky*sin(psii + thetaji))/(rix - rkx*cos(psii) + rhoji*cos(thetaji) - rky*sin(psii))^2]';
                            end
                        end
                    end
                    if cooperative_count > 0
                        [y,Py] = statisticalLinearization(yeff(1:2+cooperative_count),Rx(1:2+cooperative_count,1:2+cooperative_count),@coopFunctionBearingOnlyLHS);
                        % add extra error for heading sensitivity
                        Rk(measurement_count-(cooperative_count)+1:measurement_count,measurement_count-(cooperative_count)+1:measurement_count) = Py;
                        ytilde((measurement_count-cooperative_count+1):measurement_count) = y;
                    end
                end
            end
        end
        % if we get a new measurement, append it to the current list and
        % compute the expectation and gradient
        if measurement_count > 0
            if cooperative_count > 0
                %C0hat = C0hat*0;
                %B0hat = diag([Rrange_ag Rbear_ag]);
                % kalman gain
                Hk = [Hx(1:(measurement_count-cooperative_count),:) zeros((measurement_count-cooperative_count),2);
                    Gx(1:cooperative_count,:) Gz(1:cooperative_count,:)];
                Peff = [P0hat C0hat;C0hat' B0hat];
                if rank((Hk*Peff*Hk' + Rk(1:measurement_count,1:measurement_count))) < measurement_count
                    fprintf('error - singular matrix inversion at t = %g, agent %i.\n',tspan(i),j);
                    xk(j).xk(2*i,:) = x0hat';
                    xk(j).Pk(2*i,:) = reshape(P0hat,25,1)';
                    xk(i).Ck(2*i,:) = reshape( 1e-4*ones(5,2), 10,1)';
                    xk(i).Bk(2*i,:) = reshape( diag([Rrange_ag Rbear_ag]), 4,1)';
                    %xk(j).Ck(2*i,:) = reshape(C0hat,10,1)';
                    %xk(j).Bk(2*i,:) = reshape(B0hat,4,1)';
                    continue;
                end
                Kkalman = Peff*Hk'*((Hk*Peff*Hk' + Rk(1:measurement_count,1:measurement_count))\eye(measurement_count));
                Kk = Kkalman(1:5,:);
                % update covariances
                P0hat = P0hat - Kk*Hk*[P0hat;C0hat'];
                C0hat = C0hat - Kk*Hk*[C0hat;B0hat];
            else
                Hk = Hx(1:(measurement_count-cooperative_count),:);
                Kk = P0hat*Hk'*((Hk*P0hat*Hk' + Rk(1:measurement_count,1:measurement_count))\eye(measurement_count));
                % update covariances
                P0hat = P0hat-Kk*Hk*P0hat;
            end
            % update estimate
            x0hat = x0hat + Kk*(ytilde(1:measurement_count)-yexp(1:measurement_count));
            %Peff = (eye(size(Peff)) - [Kk;zeros(2,measurement_count)]*Hk)*Peff;
        end
        % store values
        xk(j).xk(2*i,:) = x0hat';
        %store true heading
        %xk(j).xk(2*i,5) = ags(j).truth(i,5);
        xk(j).Pk(2*i,:) = reshape(P0hat,25,1)';
        xk(j).Ck(2*i,:) = reshape(C0hat,10,1)';
        xk(j).Bk(2*i,:) = reshape(B0hat,4,1)';
    end
    %% propagate
    for j = 1:N
        x0hat = xk(j).xk(2*i,:)';
        P0hat = reshape(xk(j).Pk(2*i,:)',5,5);
        C0hat = reshape(xk(j).Ck(2*i,:)',5,2);
        B0hat = reshape(xk(j).Bk(2*i,:)',2,2);
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
        % process noise influence matrix for estimated states
        G = zeros(5,3);
        G(3:5,1:3) = Ts*[-1 0 vi(2);
            0 -1 -vi(1);
            0 0 -1];
    % nuisance parameter update terms
        % measured range to other agent
        rhoji = ags(j).rb_agent(i,1);
        % measured bearing to other agent
        thetaji = ags(j).rb_agent(i,2);
        % gradient of nuisance parameter update EQOMs w.r.t estimated states 
        gx = [[ 0, 0,      -cos(thetaji),       -sin(thetaji), 0];
            [ 0, 0, sin(thetaji)/rhoji, -cos(thetaji)/rhoji, 0]];
        % gradient w.r.t. nuisance params:
        % we have no way of knowing the other agent's velocity, so we
        % assume it is zero
        uj = 0;vj = 0; % other agent velocity components in the current agent body frame
        gz = [[0,vj*cos(thetaji) - vi(2)*cos(thetaji) + vi(1)*sin(thetaji) - uj*sin(thetaji)]
            [(vi(2)*cos(thetaji) - vj*cos(thetaji) - vi(1)*sin(thetaji) + uj*sin(thetaji))/rhoji^2, (vi(1)*cos(thetaji) - uj*cos(thetaji) + vi(2)*sin(thetaji) - vj*sin(thetaji))/rhoji]];
        % account for the discretized integration:
        gx = gx*Ts;
        gz = gz*Ts + eye(2);
        % ``process noise'' uncertainty associated with rhoji, thetaji 
        Qz = diag([Rrange_ag Rbear_ag]);
        Gz = -gz;
        %update
        %C0hat = C0hat*0;
        %B0hat = diag([Rrange_ag Rbear_ag]);
        
        x0hat = x0hat + Ts*f;
        P0hatp = Fk*P0hat*Fk' + G*Qk*G';
        C0hatp = Fk*P0hat*gx' + Fk*C0hat*gz';
        B0hatp = gx*P0hat*gx' + gz*C0hat'*gx' + gx*C0hat*gz'+gz*B0hat*gz' + Gz*Qz*Gz';
        % store new values
        xk(j).xk(2*i+1,:) = x0hat';
        xk(j).Pk(2*i+1,:) = reshape(P0hatp,25,1)';
        xk(j).Ck(2*i+1,:) = reshape(C0hatp,10,1)';
        xk(j).Bk(2*i+1,:) = reshape(B0hatp,4,1)';
    end
end