%% driver_simple_coop
clear variables;
close all;
addpath('..');

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
% bitmask for which readings are received
% if readmask & '1xxx' we get range measures of landmarks
% if readmask & 'x1xx' we get bearing measures of landmarks
% if readmask & 'xx1x', we get other agent's range measures
% if readmask & 'xxx1' we get other agent's bearings
readmask = '1111';
readmask = bin2dec(readmask);

FOV = 30*ones(1,N);%half-angle of sensor FOV for each agent IN DEGREES
RANGE = 10*ones(1,N);% maximum sensitivity
RANGEMIN = 2*ones(1,N);%minimum range

% generate new sensor noise consistent with defined levels
TRUTH = 1;
gen_new_noise;
%bitmask for which terms have bias
% 7 bit number
biasmask = '0000000';%from right to left -> a1 a2 omega range_landmark bearing_landmark range_agent bearing_agent
load_data_bitmask;%runs script that adds bias with random walk

%% run the simulation script
run_simple_coop_stat_new;

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
    xk(i).xk(1:2:end-1,5) = minangle(xk(i).xk(1:2:end-1,5),xk(i).xk(2:2:end-1,5));
    xbar = 0.5.*(xk(i).xk(1:2:end-1,:)+xk(i).xk(2:2:end-1,:));
    xbar(:,5) = minangle(xbar(:,5),xtrue(:,5));
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
        switch j
            case 1
                ylabel('\epsilon_x (m)')
            case 2
                ylabel('\epsilon_y (m)')
            case 3
                ylabel('\epsilon_u (m/s)')
            case 4
                ylabel('\epsilon_v (m/s)')
            case 5
                ylabel('\epsilon_\psi (rad)')
        end
        set(gca,'xlim',[tspan(1) tspan(end)]);
    end
    set(gcf,'position',[175 75 1600 900]);
    
    figure;
    plot(tk,xk(i).Pk);
    title('Covariance history');
end

%% animate
