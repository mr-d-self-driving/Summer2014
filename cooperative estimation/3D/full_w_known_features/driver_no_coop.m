% individual filters
% no cooperation
%
% corresponds to ukf_update_10_state.m/mex

clear variables;
close all;

global Ts;

addpath('../../2D');
addpath('../');

if ~exist('data_3d.mat','file');
    disp('Error: generate data first');
    return;
end

load('data_3d.mat');
% add noise - will not work unless this is run first

% measurement standard errors
% error stdev in agent-agent measurement
err_dev = 0.0001;%rads
% error stdev in magnetometer
mag_dev = 0.0001;%rads
% interagent range sensing error
range_dev = 0.01;%metres
% gyro stdev
gyro_noise = 1e-2;%rads
% accelerometer stdev
accel_noise = 1e-1;%metres/sec^2
% feature sensing error
feature_angle_err = 1e-2;%rads, stdev
feature_range_err = 1e-1;%metres

% noise stdevs are set in this script
add_noise;

%% process

% feature visibility in degrees
FEATURE_FOV_BEARING = [90 90];% half-angle specified here
FEATURE_FOV_DECLIN = [90 90];
FEATURE_RANGE_MIN = [0.1 0.1];% metres
FEATURE_RANGE_MAX = [10 10];%metres

% process noise
% assume both agents have same IMU noise: [gyro_i acc_i]
% terms correspond to: [noise on gyro_i, noise associated with omega_j,
% noise on acc_i, and noise associated with acc_j]. [2] and [4] encompass
% the full range of variable values
Qk = diag([gyro_noise^2*ones(1,3) accel_noise^2*ones(1,3)]);

xh = cell(2,1);
Ph = cell(2,1);

tv = T;

for i = 1:2
    xh{i} = zeros(length(tv),10);
    Ph{i} = zeros(length(tv),100);
    % random quaternion
    xh{i}(1,7:10) = randn(4,1);xh{i}(1,7:10) = xh{i}(1,7:10)./norm(xh{i}(1,7:10));% inertial attitude
    xh{i}(1,1:3) = randn(3,1).*[1;1;1];% inertial position, inertial frame
    xh{i}(1,4:6) = [0 0 0];%randn(3,1);% inertial velocity, body frame
    Ph{i}(1,:) = reshape( diag([1*ones(1,3) 1e-0*ones(1,3) 1*ones(1,4)]) + 1e-8*ones(10), 100,1)';
end

%% use exact initial conditions
%xh{1}(1,7:10) = Yc{1}(1,7:10) + 1e-3.*randn(1,4);
%xh{1}(1,1:3) = Yc{1}(1,1:3) + 1e0.*randn(1,3);
%xh{2}(1,7:10) = Yc{2}(1,7:10) + 1e-3.*randn(1,4);
%xh{2}(1,1:3) = Yc{2}(1,1:3) + 1e0.*randn(1,3);

% measurement error

tic;
for j = 1:2
    for k = 1:length(T)-1
        %% update
        xhat = xh{j}(k,:)';
        Pk = reshape(Ph{j}(k,:)',10,10);
        
        rin = xhat(1:3);
        qin = xhat(7:10);
        Cin = attparsilent(qin,[6 1]);
        
        rin_true = Yc{j}(k,1:3)';
        qin_true = Yc{j}(k,7:10)';
        Cin_true = attparsilent(qin_true,[6 1]);
        
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
                %error angle
                err_angle = randn*feature_angle_err;
                % error axis of rotation
                a_error = randn(3,1);a_error = a_error./norm(a_error);
                % range error
                range_err = randn*feature_range_err;
                Cerr_i = attparsilent([a_error [err_angle;0;0]],[2 1]);
                % measurement with angle error and range error
                rmeas = (Cerr_i*rki)*(1+range_err/norm(rki));
                % measured vecor in my frame
                xyz_known_i(m1,:) = vector2polar(rmeas);
                %rmeas = rki;
                %xyz_known_i(m1,:) = truthv = vector2polar(rmeas);
                % index of the known feature corresponding
                known_features_used_i(m1) = mm;
            end
            if m1 == 1
                break;
            end
        end
        xyz_known_i(m1+1:end,:) = [];
        known_features_used_i(m1+1:end) = [];
        
        if j == 1
            % my measured angular velocity
            wi = W(k,1:3)';
            ai = A(k,1:3)';
        else
            % my measured angular velocity
            wi = W(k,4:6)';
            ai = A(k,4:6)';
        end
        
        % measurement errors
        Rx = zeros(3*m1);
        
        % error covariance for range/bearing/declination to features
        Rx((1:m1*3),(1:m1*3)) = diag(repmat([feature_range_err^2 feature_angle_err^2 feature_angle_err^2],1,m1));
        
        uk = [wi;ai;m1; reshape(XYZ_KNOWN(known_features_used_i,:)',[],1) ];
        
        yk = reshape(xyz_known_i',[],1);
    
        Pvk = Qk;
        
        Pnk = Rx;
        
        [xp,Pp] = ukf_update_10_state(xhat,Pk,Pvk,Pnk,uk,yk,1e-3);
        
        if any(any(isnan(Pp)))
            disp('Error: NaN in covariance output');
            break;
        end
        
        % store
        xh{j}(k+1,:) = xp';
        Ph{j}(k+1,:) = reshape(Pp,100,1)';

        if ~mod(k-1,100)
            etaCalc((j-1)*length(T) + k,2*length(T),toc);
        end
    end
end
toc;

%% evaluate results

close all;

Pdiag = 1:11:100;

xh{1}(:,7:10) = quatmin(xh{1}(:,7:10),Yc{1}(:,7:10));
xh{2}(:,7:10) = quatmin(xh{2}(:,7:10),Yc{2}(:,7:10));

% and body-axis velocities
v1n = zeros(length(tv),3);
v2n = zeros(length(tv),3);
for i = 1:length(tv)    
    C1n = attparsilent(Yc{1}(i,7:10)',[6 1]);
    v1n(i,:) = Yc{1}(i,4:6)*C1n';
    C2n = attparsilent(Yc{2}(i,7:10)',[6 1]);
    v2n(i,:) = Yc{2}(i,4:6)*C2n';
end

% plot inertial position
figure;
for k = 1:3
    subplot(3,1,k);
    plot(tv,xh{1}(:,k));
    hold on;
    plot(tv,xh{1}(:,k) + 3*sqrt(Ph{1}(:,Pdiag(k))),'r--');
    plot(tv,xh{1}(:,k) - 3*sqrt(Ph{1}(:,Pdiag(k))),'r--');
    plot(tv,Yc{1}(:,k),'k-');
    title( 'Agent 1 inertial position estimate');
end
set(gcf,'position',[200 275 1300 625])

figure;
for k = 1:3
    subplot(3,1,k);
    plot(tv,xh{2}(:,k));
    hold on;
    plot(tv,xh{2}(:,k) + 3*sqrt(Ph{2}(:,Pdiag(k))),'r--');
    plot(tv,xh{2}(:,k) - 3*sqrt(Ph{2}(:,Pdiag(k))),'r--');
    plot(tv,Yc{2}(:,k),'k-');
    title( 'Agent 2 inertial position estimate');
end
set(gcf,'position',[200 275 1300 625])

% plot inertial velocity
figure;
for k = 4:6
    subplot(3,1,k-3);
    plot(tv,xh{1}(:,k));
    hold on;
    plot(tv,xh{1}(:,k) + 3*sqrt(Ph{1}(:,Pdiag(k))),'r--');
    plot(tv,xh{1}(:,k) - 3*sqrt(Ph{1}(:,Pdiag(k))),'r--');
    plot(tv,v1n(:,k-3),'k-');
    title( 'Agent 1 body velocity estimate');
end
set(gcf,'position',[200 275 1300 625])

figure;
for k = 4:6
    subplot(3,1,k-3);
    plot(tv,xh{2}(:,k));
    hold on;
    plot(tv,xh{2}(:,k) + 3*sqrt(Ph{2}(:,Pdiag(k))),'r--');
    plot(tv,xh{2}(:,k) - 3*sqrt(Ph{2}(:,Pdiag(k))),'r--');
    plot(tv,v2n(:,k-3),'k-');
    title( 'Agent 2 body velocity estimate');
end
set(gcf,'position',[200 275 1300 625])

% plot inertial attitude
figure;
for k = 1:4
    subplot(2,2,k);
    plot(tv,xh{1}(:,k+6));
    hold on;
    plot(tv,xh{1}(:,k+6) + 3*sqrt(Ph{1}(:,Pdiag(k+6))),'r--');
    plot(tv,xh{1}(:,k+6) - 3*sqrt(Ph{1}(:,Pdiag(k+6))),'r--');
    plot(tv,Yc{1}(:,k+6),'k-');
    title( 'Agent 1 attitude estimate');
end
set(gcf,'position',[200 275 1300 625])

figure;
for k = 1:4
    subplot(2,2,k);
    plot(tv,xh{2}(:,k+6));
    hold on;
    plot(tv,xh{2}(:,k+6) + 3*sqrt(Ph{2}(:,Pdiag(k+6))),'r--');
    plot(tv,xh{2}(:,k+6) - 3*sqrt(Ph{2}(:,Pdiag(k+6))),'r--');
    plot(tv,Yc{2}(:,k+6),'k-');
    title( 'Agent 2 attitude estimate');
end
set(gcf,'position',[200 275 1300 625])