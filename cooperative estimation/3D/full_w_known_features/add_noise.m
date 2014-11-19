%% add_noise.m
% to be run before simulation on data w/ no noise

% measurement standard errors
% error stdev in agent-agent measurement
err_dev = 0.01;%rads
% error stdev in magnetometer
mag_dev = 0.01;%rads
% range sensing error
range_dev = 0.1;%metres
% gyro stdev
gyro_noise = 1e-2;%rads
% accelerometer stdev
accel_noise = 1e-1;%metres/sec^2

% generate IMU histories
W = zeros(length(T),3*N);% ang. vel histories
A = zeros(length(T),3*N);% linear acc. histories

% generate measurements for each agent    
meas = cell(N,1);
for II = 1:N
    meas{II} = zeros(length(T),(N-1)*3+3);
    Jcount = 0;
    for JJ = [1:II-1 II+1:N]
        Jcount = Jcount+1;
        % inertial vector from II to JJ
        rdiff = Yc{JJ}(:,1:3) - Yc{II}(:,1:3);
        % convert to body frame
        rsee = zeros(size(rdiff));
        rmeas = zeros(size(rdiff));
        for i = 1:length(T)
            quat = Yc{II}(i,7:10)';
            Cbn = attpar(quat,[6 1]);
            rsee(i,:) = rdiff(i,:)*Cbn';

            % generate error angle
            delta = randn*err_dev;
            % get arbitrary axis of rotation
            vec = rand(3,1);vec = vec./norm(vec);
            % get DCM from true to error "frame"
            Crp_r = attpar([vec [delta;0;0]],[2 1]);

            % get the measured range
            range_frac = (norm(rsee(i,:))+randn(1)*range_dev)/norm(rsee(i,:));

            % store the vector measurement (not unit vector)
            rmeas(i,1:3) = range_frac*rsee(i,:)*Crp_r;
        end

        meas{II}(:,(Jcount-1)*3+(1:3)) = rmeas;
    end
    % get magnetometer out
    rmeas = zeros(length(T),3);
    for i = 1:length(T)
        quat = Yc{II}(i,7:10)';
        % convert to body frame
        Cbn = attparsilent(quat,[6 1]);
        psiVec = Cbn(:,1);
        % generate error angle
        delta = randn*mag_dev;
        % get arbitrary axis of rotation
        vec = rand(3,1);vec = vec./norm(vec);
        % get DCM from true to error "frame"
        Crp_r = attpar([vec [delta;0;0]],[2 1]);
        %store the heading angle measurement (magnetometer)
        rmeas(i,1:3) = psiVec'*Crp_r;
        
        % gyro and accelerometer measurements
        W(i,(1:3) + 3*(II-1)) = Yc{II}(i,11:13) + randn(1,3).*gyro_noise;
        A(i,(1:3) + 3*(II-1)) = Yc{II}(i,17:19)*Cbn' + randn(1,3).*accel_noise;
    end
    meas{II}(:,Jcount*3+(1:3)) = rmeas;
end
%save data_3d.mat;