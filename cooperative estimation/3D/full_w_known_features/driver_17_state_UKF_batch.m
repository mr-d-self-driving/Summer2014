% no IMU sharing
% has magnetometer
% 
% batch driver for Monte Carlo

clear variables;
close all;

% number of simulations to run
monte = 10;

global Ts;

addpath('../../2D');
addpath('../');

if ~exist('data_3d.mat','file');
    disp('Error: generate data first');
    return;
end

% load data
load('data_3d.mat');
disp('Running Monte Carlo 3D known feature SLAM');

% data arrays for batch results
E_POS = zeros(monte,length(T),6);
COV_POS = zeros(monte,length(T),6);

% measurement standard errors
% error stdev in agent-agent measurement
err_dev = 0.01;%rads
% error stdev in magnetometer
mag_dev = 0.1;%rads
% range sensing error
range_dev = 0.1;%metres
% gyro stdev
gyro_noise = 1e-2;%rads
% accelerometer stdev
accel_noise = 1e-1;%metres/sec^2
% feature sensing error
feature_angle_err = .01;%rads, stdev
feature_range_err = .1;%metres

% feature visibility in degrees
FEATURE_FOV_BEARING = [60 60];% half-angle specified here
FEATURE_FOV_DECLIN = [60 60];
FEATURE_RANGE_MIN = [0.1 0.1];% metres
FEATURE_RANGE_MAX = [15 15];%metres

% process noise
% assume both agents have same IMU noise: [gyro_i gyro_j acc_i acc_j]
% terms correspond to: [noise on gyro_i, noise associated with omega_j,
% noise on acc_i, and noise associated with acc_j]. [2] and [4] encompass
% the full range of variable values
Qk = diag([gyro_noise^2*ones(1,3) (1/3)^2*[1 1 1] accel_noise^2*ones(1,3) (1/3)^2*[1 1 1]]);

tic;
for monte_counter = 1:monte
    % add noise - will not work unless this is run first
    % noise stdevs are set in this script
    add_noise;

    % initialize

    xh = cell(2,1);
    Ph = cell(2,1);

    tv = T;

    for i = 1:2
        xh{i} = zeros(length(tv),17);
        Ph{i} = zeros(length(tv),289);
        % random quaternion
        xh{i}(1,7:10) = randn(4,1);xh{i}(1,7:10) = xh{i}(1,7:10)./norm(xh{i}(1,7:10));% inertial attitude
        xh{i}(1,14:17) = randn(4,1);xh{i}(1,14:17) = xh{i}(1,14:17)./norm(xh{i}(1,14:17));% inertial attitude
        xh{i}(1,1:3) = randn(3,1).*[1;1;1];% inertial position, inertial frame
        xh{i}(1,11:13) = randn(3,1).*[5;5;5];%relative position, body frame
        xh{i}(1,4:6) = [0 0 0];%randn(3,1);% inertial velocity, body frame
        Ph{i}(1,:) = reshape( diag([1*ones(1,3) 0.1*ones(1,3)  1*ones(1,4) ones(1,3) 0.1*ones(1,4)]) + 1e-6*ones(17), 289,1)';
    end
    
    % measurement error
    Rhalf = diag([range_dev err_dev err_dev range_dev err_dev err_dev]).^2;
    magnom = [1e-8 mag_dev mag_dev].^2;
    
    % run filter
    for j = 1:2
        for k = 1:length(T)-1
            %% update
            xhat = xh{j}(k,:)';
            Pk = reshape(Ph{j}(k,:)',17,17);

            rin = xhat(1:3);
            qin = xhat(7:10);
            Cin = attparsilent(qin,[6 1]);

            rin_true = Yc{j}(k,1:3)';
            qin_true = Yc{j}(k,7:10)';
            Cin_true = attparsilent(qin_true,[6 1]);
            if j == 1
                notj = 2;
            else
                notj = 1;
            end
            rjn_true = Yc{notj}(k,1:3)';
            qjn_true = Yc{notj}(k,7:10)';
            Cjn_true = attparsilent(qjn_true,[6 1]);

            % measurements

            % determine which KNOWN features I can see
            m1 = 0;
            xyz_known_i = zeros(M,3);
            known_features_used_i = zeros(M,1);
            for mm = 1:M
                % compute the i frame TRUE position vector to feature
                rki = Cin_true*(XYZ_KNOWN(mm,:)' - rin_true);
                % compute range/bearing/declination
                rbd = vector2polar(rki);

                % if this is satisfied, we can see the feature
                if rbd(1) < FEATURE_RANGE_MAX(j) && rbd(1) > FEATURE_RANGE_MIN(j) && abs(rbd(2)) < d2r*(FEATURE_FOV_BEARING(j)) && abs(rbd(3)) < d2r*(FEATURE_FOV_DECLIN(j))
                    m1 = m1 + 1;
                    % generate the measurement of this feature
                    % error angle
                    err_angle = randn*feature_angle_err;
                    % error axis of rotation
                    a_error = randn(3,1);a_error = a_error./norm(a_error);
                    % range error
                    range_err = randn*feature_range_err;
                    Cerr_i = attparsilent([a_error [err_angle;0;0]],[2 1]);
                    % measurement with angle error and range error
                    rmeas = (Cerr_i*rki)*(1+range_err/norm(rki));
                    xyz_known_i(m1,:) = vector2polar(rmeas);
                    known_features_used_i(m1) = mm;
                end
            end
            xyz_known_i(m1+1:end,:) = [];
            known_features_used_i(m1+1:end) = [];

            % determine which features the other agent can see
            m2 = 0;
            xyz_known_j = zeros(M,3);
            known_features_used_j = zeros(M,1);
            for mm = 1:M
                % compute the j frame TRUE position vector to feature
                rkj = Cjn_true*(XYZ_KNOWN(mm,:)' - rjn_true);
                % compute range/bearing/declination
                rbd = vector2polar(rkj);

                % if this is satisfied, we can see the feature
                if rbd(1) < FEATURE_RANGE_MAX(notj) && rbd(1) > FEATURE_RANGE_MIN(notj) && abs(rbd(2)) < d2r*(FEATURE_FOV_BEARING(notj)) && abs(rbd(3)) < d2r*(FEATURE_FOV_DECLIN(notj))
                    m2 = m2 + 1;
                    % generate the measurement of this feature
                    % error angle
                    err_angle = randn*feature_angle_err;
                    % error axis of rotation
                    a_error = randn(3,1);a_error = a_error./norm(a_error);
                    % range error
                    range_err = randn*feature_range_err;
                    Cerr_j = attparsilent([a_error [err_angle;0;0]],[2 1]);
                    % measurement with angle error and range error
                    rmeas = (Cerr_j*rkj)*(1+range_err/norm(rkj));
                    xyz_known_j(m2,:) = vector2polar(rmeas);
                    known_features_used_j(m2) = mm;
                end
            end
            xyz_known_j(m2+1:end,:) = [];
            known_features_used_j(m2+1:end) = [];

            if j == 1
                % my measured angular velocity
                wi = W(k,1:3)';
                ai = A(k,1:3)';
            else
                % my measured angular velocity
                wi = W(k,4:6)';
                ai = A(k,4:6)';
            end
            % his meas of me
            rij_j = meas{notj}(k,1:3)';
            % his magnetometer
            mag_j = meas{notj}(k,4:6)';

            % my meas of him
            rji_i = meas{j}(k,1:3)';
            % my magnetometer
            mag_i = meas{j}(k,4:6)';

            % measurement errors
            Rx = zeros(12+3*(m1+m2));
            Rx(1:6,1:6) = Rhalf;

            % error for my magnetometer
            Crt_b = zeros(3);
            Crt_b(1,:) = mag_i';
            r2 = cross(mag_i,[1;0;0]);r2 = r2./norm(r2);
            r3 = cross(mag_i,r2);
            Crt_b(2,:) = r2';
            Crt_b(3,:) = r3';
            % error covariance associated with mag_i, in its frame
            Rx(7:9,7:9) = Crt_b'*diag(magnom)*Crt_b;

            % repeat for his magnetometer
            Crt_b = zeros(3);
            Crt_b(1,:) = mag_j';
            r2 = cross(mag_j,[1;0;0]);r2 = r2./norm(r2);
            r3 = cross(mag_j,r2);
            Crt_b(2,:) = r2';
            Crt_b(3,:) = r3';
            % error covariance associated with mag_j, in its frame
            Rx(10:12,10:12) = Crt_b'*diag(magnom)*Crt_b;

            % error covariance for range/bearing/declination of agent i
            Rx(12 + (1:m1*3),12 + (1:m1*3)) = diag(repmat([feature_range_err feature_angle_err feature_angle_err].^2,1,m1));
            % error covariance for range/bearing/declination of agent j
            Rx(12 + 3*m1 + (1:m2*3),12 + 3*m1 + (1:m2*3)) = diag(repmat([feature_range_err feature_angle_err feature_angle_err].^2,1,m2));

            uk = [wi;ai;mag_i;m1; reshape(XYZ_KNOWN(known_features_used_i,:)',[],1); m2;reshape(XYZ_KNOWN(known_features_used_j,:)',[],1) ];

            yk = [vector2polar(rji_i); ...
            vector2polar(rij_j); ...
            mag_j;
            reshape(xyz_known_i',[],1);
            reshape(xyz_known_j',[],1)];

            Pvk = Qk;

            Pnk = Rx;

            [xp,Pp] = ukf_update_17_state_mex(xhat,Pk,Pvk,Pnk,uk,yk,1e-3);

            if any(any(isnan(Pp)))
                disp('Error: NaN in covariance output');
                break;
            end

            % store
            xh{j}(k+1,:) = xp';
            Ph{j}(k+1,:) = reshape(Pp,289,1)';
        end
    end

    % process results

    Pdiag = 1:18:289;

    % compute position error
    E_POS(monte_counter,:,1:3) = xh{1}(:,1:3)-Yc{1}(:,1:3);
    E_POS(monte_counter,:,4:6) = xh{2}(:,1:3)-Yc{2}(:,1:3);
    COV_POS(monte_counter,:,1:3) = Ph{1}(:,Pdiag(1:3));
    COV_POS(monte_counter,:,4:6) = Ph{2}(:,Pdiag(1:3));

    etaCalc(monte_counter,monte,toc);
end
toc;

str = clock;
fname = sprintf('monte_%.4i-%.2i-%.2i-%.2i:%.2i.mat',str(1:5));
save(fname,'E_POS','COV_POS','monte');