clear variables;
clear global;
close all;
addpath('..');
addpath('..\..');

global marks;

load data.mat;

% sensor noise levels to use
Rrange = 1e-4*ones(1,N);
Rbear = 1e-4*ones(1,N);
Rrange_ag = 1e-2;
Rbear_ag = 1e-4;
Rimu = 1e-2*diag([.5^2 .5^2 .1^2]);

% get new readings from other agent every K_update timesteps
K_update = 1;
update_counter = 0;

% BEHAVIOR FLAGS FOR MEASUREMENTS AND ESTIMATION
% feature_case:
% 0: we measure range and bearing to features
% 1: we measure bearing only
% 2: we measure range only
feature_case = 1;
% agent_case
% 0: we measure range and bearing to agents
% 1: we measure bearing only
% 2: we measure range only
agent_case = 0;
% imu_sharing
% 0: we do not share IMU
% 1: we share accelerometer and gyro measurements
imu_sharing = 0;
% known_features
% 0: unknown features
% 1: known features
known_features = 0;

FOV = [65 65];%half-angle of sensor FOV for each agent's feature detection, IN DEGREES
RANGE = [20 20];% maximum sensitivity
RANGEMIN = [1 1];%minimum range

% generate new sensor noise consistent with defined levels
TRUTH = 0;
gen_new_noise;
%bitmask for which terms have bias
% 7 bit number
biasmask = '0000000';%from right to left -> a1 a2 omega range_landmark bearing_landmark range_agent bearing_agent
load_data_bitmask;%runs script that adds bias with random walk

%% initialize memory

tk = tspan;

if imu_sharing
    disp('We don''t handle the IMU sharing case yet');
    return;
else
    % I'm estimating my state and up to 4 states per feature
    % Nf is the number of features I've seen so far
    % fl is a list of the feature seen so far (uses same numbers as the global notation 
    xk(N) = struct('xk',zeros(length(tspan),5+4*M*N),'Pk',zeros(length(tspan),(5+4*M*N)^2),'Nf',0,'fl',zeros(M,1));
    for i = 1:N
        xk(i) = struct('xk',zeros(length(tspan),5+4*M*N),'Pk',zeros(length(tspan),(5+4*M*N)^2),'Nf',0,'fl',zeros(M,1));
        % initialize my state: rx, ry, vx, vy, heading. position is in the inertial frame again
        % we initialize my position and heading to zero, just for lulz
        xk(i).xk(1,3:4) = ags(i).truth(1,3:4)';
        % initialize the covariance associated with my states
        xk(i).Pk(1,:) = reshape( [diag([1 1 .25 .25 .01])+.0001*ones(5) zeros(5,4*M*N);zeros(4*M*N,5+4*M*N)], (4*M*N+5)^2 , 1);
        %xk(i).Pk(1,:) = reshape( [diag([1 1 .25 .25 .01])+1e-6*ones(5) 1e-6*ones(5,4*M*N);.0001*ones(4*M*N,5+4*M*N)+1e-6*ones(4*M*N,5+4*M*N)], (4*M*N+5)^2 , 1);
    end
end

%% loop over all times

global Qk xf_t Pf_inv_t;

if imu_sharing
else
    Qk = Rimu*Ts;
end

% initialize
xest = zeros(length(tspan),N*M);
% initial time call, no measurements are made
i = 1;
for j = 1:N
    
end
for i = 2:length(tspan)
    for j = 1:N
        % get the matrices Hk, Rk, and ytilde
        [ytilde,fl,Rk] = get_measure(i,j,ags,FOV,RANGE,RANGEMIN,Rbear);
        rhoji = ags(j).rb_agent(i,1:2:end-1);
        thetaji = ags(j).rb_agent(i,2:2:end);
        thetaij = zeros(N-1,1);
        count = 0;
        for j2 = [1:j-1 j+1:N]
            count = count+1;
            if j2 > j
                j2ind = j2-1;
            else
                j2ind = j2;
            end
            thetaij(count) = ags(j2).rb_agent(i,j2ind);
        end
        [yexp,Hk,xk(j)] = get_expectation(i,j,M,xk(j),ytilde,fl,rhoji,thetaji,thetaij);
        
        % forward update
        
        % forward propagate
        
        % backward propagate using the adjoint variable
        % initialize adjoint states from the NEXT measurement
        % backward integrate
        % backward update step using the CURRENT measurement
    end
end