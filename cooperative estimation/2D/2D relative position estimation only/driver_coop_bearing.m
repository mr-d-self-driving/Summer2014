%% driver_coop_bearing
% driver for single simulation with feature bearing measurements only
clear variables;
clear global;
close all;
addpath('..');

global marks;

load data.mat;

% sensor noise levels to use
Rrange = 1*ones(1,N);
Rbear = .01*ones(1,N);
Rrange_ag = 1;
Rbear_ag = .01;
Rimu = diag([.5^2 .5^2 .1^2]);

% get new readings from other agent every K_update timesteps
K_update = 1;
update_counter = 0;

%set SHARE_IMU to 1 to share imu measurements
SHARE_IMU = 1;

% bitmask for which readings are received
% if readmask & '1xxx' we get range measures of landmarks
% if readmask & 'x1xx' we get bearing measures of landmarks
% if readmask & 'xx1x', we get other agent's range measures
% if readmask & 'xxx1' we get other agent's bearings
readmask = '0000';
readmask = bin2dec(readmask);

FOV = [30 30];%half-angle of sensor FOV for each agent IN DEGREES
RANGE = [10 10];% maximum sensitivity
RANGEMIN = [1 1];%minimum range

% generate new sensor noise consistent with defined levels
TRUTH = 0;
gen_new_noise;
%bitmask for which terms have bias
% 7 bit number
biasmask = '0000000';%from right to left -> a1 a2 omega range_landmark bearing_landmark range_agent bearing_agent
load_data_bitmask;%runs script that adds bias with random walk

%% run the simulation script

%run_simple_coop_stat_imu;
run_simple_hardwire;

%% relative plots
for i = 1:N
    if i == 1
        i2 = 2;
    else
        i2 = 1;
    end
    % inertial frame coordinates of estimated positions
    if SHARE_IMU
        figure;
        for j = 1:2
            subplot(2,1,j);
            plot(tspan,ags(i).rb_agent(:,j));
            delta = ags(i2).truth(:,1:2) - ags(i).truth(:,1:2);
            hold on;
            switch j
                case 1
                    plot(tk,sqrt(sum(xk(i).xk(:,4:5).^2,2)),'r--');
                    plot(tspan,sqrt(sum(delta.^2,2)),'k-');
                    ylabel('\rho');
                case 2
                    plot(tk,atan2(xk(i).xk(:,5),xk(i).xk(:,4)),'r--');
                    plot(tspan,atan2(delta(:,2),delta(:,1)) - ags(i).truth(:,5),'k-');
                    ylabel('\theta');
            end
        end
    end
    figure;
    for j = 1:3
        subplot(3,1,j);
        plot(tk,xk(i).xk(:,j),'r--');
        hold on;
        plot(tspan,ags(i).truth(:,j+2));
    end
end