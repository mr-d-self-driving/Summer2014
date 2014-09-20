%% driver_simple_coop
clear variables;
close all;
addpath('..');

load data.mat;

% sensor noise levels to use
Rrange = [100 100];
Rbear = [.01 .01];
Rrange_ag = 100;
Rbear_ag = .01;
Rimu = diag([.5^2 .5^2 .1^2]);

% get new readings from other agent every K_update timesteps
K_update = 1;
update_counter = 0;
% bitmask for which readings are received
% if readmask & '1xxx' we get range measures of landmarks
% if readmask & 'x1xx' we get bearing measures of landmarks
% if readmask & 'xx1x', we get other agent's range measures
% if readmask & 'xxx1' we get other agent's bearings
readmask = '1111';
readmask = bin2dec(readmask);

FOV = [45 45];%half-angle of sensor FOV for each agent IN DEGREES

% generate new sensor noise consistent with defined levels
TRUTH = 1;
gen_new_noise;
%bitmask for which terms have bias
% 7 bit number
biasmask = '0000000';%from right to left -> a1 a2 omega range_landmark bearing_landmark range_agent bearing_agent
load_data_bitmask;%runs script that adds bias with random walk

%% initialize

tk = [sort([tspan tspan]) tspan(end)+Ts];
xk(N) = struct('xk',zeros(length(tspan)*2+1,5),'Pk',zeros(length(tspan)*2+1,25));
for i = 1:N
    %intialize state
    xk(i).xk(1,:) = ags(i).truth(1,1:5)';
    % convert inertial position to the body frame
    xk(i).xk(1,1:2) = ags(i).truth(1,1:2)*[cos(ags(i).truth(1,5)) -sin(ags(i).truth(1,5));
        sin(ags(i).truth(1,5)) cos(ags(i).truth(1,5))];
    %initialize covariance
    xk(i).Pk(1,:) = reshape( 1*eye(5)+.1*ones(5), 25,1)';
end
%% loop over all times

Qk = Rimu*Ts;

for i = 1:length(tspan)
    %% update new measurements
    for j = 1:N
        ytilde = [];% doing this the lazy way for now
        yexp = [];
        Hk = [];
        Rk = [];
        
        x0hat = xk(j).xk(2*i-1,:)';% rix,riy,u,v,psi - all are in body frame
        P0hat = reshape(xk(j).Pk(2*i-1,:)',5,5);
        psii = x0hat(5);
        rix = x0hat(1);
        riy = x0hat(2);
        
        % initialize the covariance matrix, well I can't because I don't
        % know what I can measure a prioiri
        % Rk =  zeros( 2*M*length(find(bitand(readmask,[1 2 4 8]))) );
        
        measurement_count = 0;
        
        % iterate over the readmask
        if bitand(readmask,8) || bitand(readmask,4)
            % check that we are in the agent's FOV
            if bitand(readmask,8)
                % loop over each landmark
                for m = 1:M
                    if abs(ags(j).rb(i,m+M)) <= d2r*FOV(j) %check that the measurement is less than the FOV
                        measurement_count = measurement_count+1;
                        ytilde = [ytilde;ags(j).rb(i,m)];
                        % measurement noise covariance
                        Rk(measurement_count,measurement_count) = Rrange(j);
                        %compute expectation
                        rkx = marks(m).xy(1);
                        rky = marks(m).xy(2);
                        Cbn = [cos(psii) sin(psii);-sin(psii) cos(psii)];
                        rki_b = Cbn*[rkx;rky]-[rix;riy];%body frame expectation of relative vector
                        rhoki = sqrt(sum( rki_b.^2 ));
                        yexp = [yexp;rhoki];
                        % compute gradient
                        Hk = [Hk;
                            [-(2*rkx*cos(psii) - 2*rix + 2*rky*sin(psii))/(2*((riy - rky*cos(psii) + rkx*sin(psii))^2 + (rkx*cos(psii) - rix + rky*sin(psii))^2)^(1/2));
                            (2*riy - 2*rky*cos(psii) + 2*rkx*sin(psii))/(2*((riy - rky*cos(psii) + rkx*sin(psii))^2 + (rkx*cos(psii) - rix + rky*sin(psii))^2)^(1/2));
                            0;
                            0;
                            (2*(rkx*cos(psii) + rky*sin(psii))*(riy - rky*cos(psii) + rkx*sin(psii)) + 2*(rky*cos(psii) - rkx*sin(psii))*(rkx*cos(psii) - rix + rky*sin(psii)))/(2*((riy - rky*cos(psii) + rkx*sin(psii))^2 + (rkx*cos(psii) - rix + rky*sin(psii))^2)^(1/2))]'];
                    end
                end
            end
            if bitand(readmask,4)
                % new bearing measures of landmarks
                %loop over each landmark
                for m = 1:M
                    if abs(ags(j).rb(i,m+M)) <= d2r*FOV(j) %check that the measurement is less than the FOV
                        measurement_count = measurement_count+1;
                        % store measurement
                        ytilde = [ytilde;ags(j).rb(i,M+m)'];
                        Rk(measurement_count,measurement_count) = Rbear(j);
                        % expectation
                        rkx = marks(m).xy(1);
                        rky = marks(m).xy(2);
                        Cbn = [cos(psii) sin(psii);-sin(psii) cos(psii)];
                        rki_b = Cbn*[rkx;rky]-[rix;riy];%body frame expectation of relative vector
                        % store expectation
                        yexp = [yexp;atan2(rki_b(2),rki_b(1))];
                        % minimize the difference in the two angles
                        yexp(end) = minangle(yexp(end),ytilde(end));
                        % compute gradient
                        Hk = [Hk;
                            [-(riy - rky*cos(psii) + rkx*sin(psii))/(rix^2 - 2*cos(psii)*rix*rkx - 2*sin(psii)*rix*rky + riy^2 + 2*sin(psii)*riy*rkx - 2*cos(psii)*riy*rky + rkx^2 + rky^2);
                            -(rkx*cos(psii) - rix + rky*sin(psii))/(rix^2 - 2*cos(psii)*rix*rkx - 2*sin(psii)*rix*rky + riy^2 + 2*sin(psii)*riy*rkx - 2*cos(psii)*riy*rky + rkx^2 + rky^2);
                            0;
                            0;
                            (rix*(rkx*cos(psii) + rky*sin(psii)) + riy*(rky*cos(psii) - rkx*sin(psii)) - rkx^2 - rky^2)/(rix^2 - 2*cos(psii)*rix*rkx - 2*sin(psii)*rix*rky + riy^2 + 2*sin(psii)*riy*rkx - 2*cos(psii)*riy*rky + rkx^2 + rky^2)]'];
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
                    % meassurements of the other agents differently than
                    % the `global' index
                    j2ind = j2;
                    if j2ind > j
                        j2ind = j2ind-1;
                    end
                    % Rx is the covariance of uncertain values in the computed
                    % measurements
                    % these terms are: [rhoji thetaji rhokj thetakj psij rix riy psii]
                    Rx = zeros(8);
                    Rx(1:5,1:5) = diag([Rrange_ag Rbear_ag Rrange(j2) Rbear(j2) xk(j2).Pk(2*i-1,end)]);
                    Rx(6:8,6:8) = P0hat([1 2 5],[1 2 5]);% P0hat(5,5)]);
                    % jacobian of computed measurements w.r.t. real
                    % measurements, ASSUMES BOTH RANGE AND BEARING AVAILABLE
                    %Jac = zeros(2*M,5);
                    Jac = [];
                    % measured range to other agent
                    rhoji = ags(j).rb_agent(i,(j2ind-1)*2+1);
                    % measured bearing to other agent
                    thetaji = ags(j).rb_agent(i,(j2ind-1)*2+2);
                    % heading of other agent
                    psij = xk(j2).xk(2*i-1,5);
                    % loop over each landmark
                    for m = 1:M
                        if abs(ags(j2).rb(i,m+M)) <= d2r*FOV(j2)
                            %for now we assume other agent measures both range
                            %and bearing
                            rhokj = ags(j2).rb(i,m); %other agent's range measure
                            thetakj = ags(j2).rb(i,m+M);% other agent's bearing measure
                            alpha = pi-thetakj-psij+psii+thetaji;
                            if bitand(readmask,2)
                                cooperative_count = cooperative_count+1;
                                measurement_count = measurement_count+1;
                                % new range measure from other agents, CONVERTED
                                % INTO AGENT j's FRAME!
                                rkx = marks(m).xy(1);
                                rky = marks(m).xy(2);
                                %compute measurement
                                ytilde = [ytilde; rhokj^2 - rhoji^2 + 2*rhoji*cos(thetaji)*(rkx*cos(psii) - rix + rky*sin(psii)) - 2*rhoji*sin(thetaji)*(riy - rky*cos(psii) + rkx*sin(psii))];
                                %compute expectation
                                yexp = [yexp;(riy - rky*cos(psii) + rkx*sin(psii))^2 + (rkx*cos(psii) - rix + rky*sin(psii))^2];
                                % compute gradient
                                Hk = [Hk;
                                    [2*rix - 2*rkx*cos(psii) - 2*rky*sin(psii)
                                    2*riy - 2*rky*cos(psii) + 2*rkx*sin(psii)
                                    0
                                    0
                                    2*riy*rkx*cos(psii) - 2*rix*rky*cos(psii) + 2*rix*rkx*sin(psii) + 2*riy*rky*sin(psii)]'];
                                % compute covariance
                                Jac(cooperative_count,:) = [2*rkx*cos(psii + thetaji) - 2*rhoji + 2*rky*sin(psii + thetaji) - 2*rix*cos(thetaji) - 2*riy*sin(thetaji)
                                    - 2*rhoji*sin(thetaji)*(rkx*cos(psii) - rix + rky*sin(psii)) - 2*rhoji*cos(thetaji)*(riy - rky*cos(psii) + rkx*sin(psii))
                                    2*rhokj
                                    0
                                    0
                                    -2*rhoji*cos(thetaji)
                                    -2*rhoji*sin(thetaji)
                                    2*rhoji*rky*cos(psii + thetaji) - 2*rhoji*rkx*sin(psii + thetaji)]';
                            end
                            if bitand(readmask,1)
                                cooperative_count = cooperative_count + 1;
                                measurement_count = measurement_count+1;
                                % new bearing measure from other agents, CONVERTED
                                % INTO AGENT j's FRAME!
                                rkx = marks(m).xy(1);
                                rky = marks(m).xy(2);
                                % measurement
                                ytilde = [ytilde; rhoji*cos(psij - psii)*sin(thetaji) - tan(thetakj)*(cos(psij - psii)*(rix - rkx*cos(psii) + rhoji*cos(thetaji) - rky*sin(psii)) + sin(psij - psii)*(riy - rky*cos(psii) + rkx*sin(psii) + rhoji*sin(thetaji))) - rhoji*sin(psij - psii)*cos(thetaji) ];
                                % expectation
                                yexp = [yexp;- cos(psij - psii)*(riy - rky*cos(psii) + rkx*sin(psii)) - sin(psij - psii)*(rkx*cos(psii) - rix + rky*sin(psii))];
                                % compute gradient
                                Hk = [Hk;
                                    [sin(psij - psii)
                                    -cos(psii - psij)
                                    0
                                    0
                                    riy*sin(psii - psij) - rix*cos(psii - psij)]'];
                                % compute the measurement covariance
                                Jac(cooperative_count,:) = [sin(psii - psij + thetaji) - (cos(psij - psii - thetaji)*sin(thetakj))/cos(thetakj)
                                    rhoji*cos(psij - psii - thetaji) + (rhoji*sin(psii - psij + thetaji)*sin(thetakj))/cos(thetakj)
                                    0
                                    -(rhoji*cos(psij - psii - thetaji) - rkx*cos(psij) - rky*sin(psij) + rix*cos(psij - psii) + riy*sin(psij - psii))/cos(thetakj)^2
                                    (sin(thetakj)*(sin(psij - psii)*(rix - rkx*cos(psii) + rhoji*cos(thetaji) - rky*sin(psii)) - cos(psij - psii)*(riy - rky*cos(psii) + rkx*sin(psii) + rhoji*sin(thetaji))))/cos(thetakj) - rhoji*cos(psij - psii - thetaji)
                                    -cos(psij - psii)*tan(thetakj)
                                    sin(psii - psij)*tan(thetakj)
                                    rhoji*cos(psij - psii - thetaji) + rhoji*sin(psii - psij + thetaji)*tan(thetakj) + riy*cos(psij - psii)*tan(thetakj) - rix*sin(psij - psii)*tan(thetakj)]';
                            end
                        end
                    end
                    if cooperative_count > 0
                        Rk(measurement_count-(cooperative_count)+1:measurement_count,measurement_count-(cooperative_count)+1:measurement_count) = Jac*Rx*Jac';
                    end
                end
            end
        end
        % if we get a new measurement, append it to the current list and
        % compute the expectation and gradient
        if measurement_count > 0
            % kalman gain
            Kk = P0hat*Hk'*((Hk*P0hat*Hk' + Rk)\eye(size(Rk)));
            % update estimate
            x0hat = x0hat + Kk*(ytilde-yexp);
            % update covariance
            P0hat = (eye(size(Kk,1),size(Hk,2))-Kk*Hk)*P0hat;
        end
        % store values
        xk(j).xk(2*i,:) = x0hat';
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

%% plots

for i = 1:N
    figure;
    xtrue = ags(i).truth;
    % must convert inertial truth to the body frame
    for k = 1:length(tspan)
        C = [cos(xtrue(k,5)) sin(xtrue(k,5));
            -sin(xtrue(k,5)) cos(xtrue(k,5))];
        xtrue(k,1:2) = xtrue(k,1:2)*C';
        if ~mod(k-1,100)
            disp(k)
        end
    end
    xbar = 0.5.*(xk(i).xk(1:2:end-1,:)+xk(i).xk(2:2:end-1,:));
    xbar(:,5) = minangle(xbar(:,5),ags(i).truth(:,5));
    for j = 1:5
        subplot(5,1,j);
        %plot(tk,xk(i).xk(:,j),'r--');
        plot(tspan,xbar(:,j),'r--');
        hold on;
        plot(tspan,xtrue(:,j),'b-');
        title(['Agent ' num2str(i) ' estimates and truth']);
    end
    
    figure;
    for j = 1:5
        subplot(5,1,j);
        %plot(tk,xk(i).xk(:,j),'r--');
        plot(tspan,xbar(:,j)-xtrue(:,j),'b-');
        hold on;
        plot(tk,3*sqrt(xk(i).Pk(:,1+(j-1)*6)),'r--');
        plot(tk,-3*sqrt(xk(i).Pk(:,1+(j-1)*6)),'r--');
        title(['Agent ' num2str(i) ' errors']);
    end
end

%% animate
