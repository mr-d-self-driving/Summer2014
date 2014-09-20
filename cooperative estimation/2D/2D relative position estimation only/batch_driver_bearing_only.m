%% batch_driver_bearing_only
% 
% Monte Carlo with and without interagent measurements to compare
% performance.

clear variables;
close all;
addpath('..');

global marks;

load data.mat;

% sensor noise levels to use
Rrange = [1 1];
Rbear = [.01 .01];
Rrange_ag = 1;
Rbear_ag = .01;
Rimu = diag([.5^2 .5^2 .1^2]);

% get new readings from other agent every K_update timesteps
K_update = 5;
update_counter = 0;

FOV = [30 30];%half-angle of sensor FOV for each agent IN DEGREES
RANGE = [10 10];% maximum sensitivity
RANGEMIN = [1 1];%minimum range

Krun = 1000;%number of batch simulations to run

%% with measurement sharing

% bitmask for which readings are received
% if readmask & '1xxx' we get range measures of landmarks
% if readmask & 'x1xx' we get bearing measures of landmarks
% if readmask & 'xx1x', we get other agent's range measures
% if readmask & 'xxx1' we get other agent's bearings
readmask = '0101';
readmask = bin2dec(readmask);

dvect = cell(Krun,N);% store the mean squared error
tic;
for KKK = 1:Krun
    %% set up
    update_counter = 0;
    % generate new sensor noise consistent with defined levels
    TRUTH = 0;
    gen_new_noise;
    %bitmask for which terms have bias
    % 7 bit number
    biasmask = '0000000';%from right to left -> a1 a2 omega range_landmark bearing_landmark range_agent bearing_agent
    load_data_bitmask;%runs script that adds bias with random walk
    %% run simulation
    run_simple_coop_stat_new;
    %% store data
    for i = 1:N
        % min angle
        xk(i).xk(1:2:end-1,5) = minangle(xk(i).xk(1:2:end-1,5),xk(i).xk(2:2:end-1,5));
        xbar = 0.5.*(xk(i).xk(1:2:end-1,:)+xk(i).xk(2:2:end-1,:));
        xbar(:,5) = minangle(xbar(:,5),ags(i).truth(:,5));
        dvect{KKK,i} = xbar;
    end
    etaCalc(KKK,Krun,toc);
end

%% no sharing

% bitmask for which readings are received
readmask = '0100';
readmask = bin2dec(readmask);

dvect2 = cell(Krun,N);% store the mean squared error
tic;
for KKK = 1:Krun
    %% set up
    update_counter = 0;
    % generate new sensor noise consistent with defined levels
    TRUTH = 0;
    gen_new_noise;
    %bitmask for which terms have bias
    % 7 bit number
    biasmask = '0000000';%from right to left -> a1 a2 omega range_landmark bearing_landmark range_agent bearing_agent
    load_data_bitmask;%runs script that adds bias with random walk
    %% run simulation
    run_simple_coop_stat_new;
    %% store data
    for i = 1:N
        % min angle
        xk(i).xk(1:2:end-1,5) = minangle(xk(i).xk(1:2:end-1,5),xk(i).xk(2:2:end-1,5));
        xbar = 0.5.*(xk(i).xk(1:2:end-1,:)+xk(i).xk(2:2:end-1,:));
        xbar(:,5) = minangle(xbar(:,5),ags(i).truth(:,5));
        dvect2{KKK,i} = xbar;
    end
    etaCalc(KKK,Krun,toc);
end

save batch_out.mat;