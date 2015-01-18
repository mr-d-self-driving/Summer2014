clear variables;
close all;

global Ts;

addpath('../../2D');
addpath('../');
addpath('../full_w_known_features');

if ~exist('data_3d.mat','file');
    disp('Error: generate data first');
    return;
end

load('data_3d.mat');
% add noise - will not work unless this is run first

% error stdevs
% DecaWave transceiver errors
std_dec = 0.1/3;% nominal 10 cm acc.
% gyro stdev
gyro_noise = 1e-2;%rads
% accelerometer stdev
accel_noise = 1e-1;%metres/sec^2
%%legacy variables%%
% error stdev in agent-agent measurement
err_dev = 0.0001;%rads
% error stdev in magnetometer
mag_dev = 0.1;%rads
% agent-agent range sensing error
range_dev = 0.01;%metres

% load the body-frame positions of the decawave transceivers, assume
% homogeneous agents
rkj_j = csvread('agent.txt',0,0,[0,0,2,2]);

% generate measurements and add noise
add_noise;

%% process

% process noise
% assume both agents have same IMU noise: [gyro_i gyro_j acc_i acc_j]
% terms correspond to: [noise on gyro_i, noise on gyro_j,
% noise on acc_i, and noise on acc_j]. 
Qk = diag([gyro_noise^2*ones(1,6) accel_noise^2*ones(1,6)]);

xh = cell(2,1);
Ph = cell(2,1);

tv = T;

% we have 10 states for ourself, and estimate the relative vel/att of other
% agent - 17 states total
%[rin,vin,quat_i_n,rji,qji,vji]

Ns = 20;
Ns2 = Ns^2;% size of the covariance matrix

% initialize
for i = 1:2
    xh = cell(2,1);
    Ph = cell(2,1);
    % random quaternion
    xh{i}(1,7:10) = randn(4,1);xh{i}(1,7:10) = xh{i}(1,7:10)./norm(xh{i}(1,7:10));% inertial attitude
    xh{i}(1,14:17) = randn(4,1);xh{i}(1,14:17) = xh{i}(1,14:17)./norm(xh{i}(1,14:17));% inertial attitude
    xh{i}(1,1:3) = randn(3,1).*[1;1;1];% inertial position, inertial frame
    xh{i}(1,11:13) = randn(3,1).*[5;5;5];%relative position, body frame
    xh{i}(1,4:6) = [0 0 0];%randn(3,1);% inertial velocity, body frame
    % initial covariance for the 17 base states
    Ph{i}(1,1:Ns2) = reshape( diag([1*ones(1,3) 0.1*ones(1,3)  1*ones(1,4) ones(1,3) 0.1*ones(1,4)]) + 1e-6*ones(17), 17^2,1)';
end

%% run filter
% modelled measurements error
Rx = diag([std_dec std_dec std_dec]);

tic;
for j = 1:2
    for k = 1:length(T)-1
        %% update
        hat = xh{j}(k,1:Ns)';
        Pk = reshape(Ph{j}(k,1:Ns2)',Ns,Ns);
        
        % own state estimates
        rin = xhat(1:3);
        qin = xhat(7:10);
        Cin = attparsilent(qin,[6 1]);
        
        % measurements - range to other agent's beacons  
        ytilde = permute( RF(k,j,:),[3 1 2]);
        
        if j == 1
            % my measured angular velocity
            wi = W(k,1:3)';
            ai = A(k,1:3)';
            % his
            wj = W(k,4:6)';
            aj = A(k,4:6)';
        else
            % my measured angular velocity
            wi = W(k,4:6)';
            ai = A(k,4:6)';
            % his
            wj = W(k,1:3)';
            aj = A(k,1:3)';
        end
        
        % do we get to use HIS measurements of ME here as well?
        
        % "inputs" vector
        uk = [wi;wj;ai;aj];
        yk = ytilde;
        
        Pvk = Qk;
        
        Pnk = Rx;
        
        [xp,Pp] = ukf_update_ranging_and_bearing(xhat,Pk,Pvk,Pnk,uk,yk,1e-3);
        
    end
end
toc;