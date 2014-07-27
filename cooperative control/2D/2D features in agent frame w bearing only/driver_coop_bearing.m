%% driver_coop_bearing
% driver for single simulation with feature bearing measurements only
clear variables;
clear global;
close all;
addpath('..');

global marks;

load data.mat;

% sensor noise levels to use
Rrange = [1 1];
Rbear = [.001 .001];
Rrange_ag = 10;%1;
Rbear_ag = .001;%.01;
Rimu = diag([.5^2 .5^2 .1^2]);

% get new readings from other agent every K_update timesteps
K_update = 1;
update_counter = 0; 
% bitmask for which readings are received
% if readmask & '1xxx' we get range measures of landmarks
% if readmask & 'x1xx' we get bearing measures of landmarks
% if readmask & 'xx1x', we get other agent's range measures
% if readmask & 'xxx1' we get other agent's bearings
readmask = '0101';
readmask = bin2dec(readmask);

FOV = [30 30];%half-angle of sensor FOV for each agent IN DEGREES
RANGE = [10 10];% maximum sensitivity
RANGEMIN = [2 2];%minimum range

% generate new sensor noise consistent with defined levels
TRUTH = 1;
gen_new_noise;
%bitmask for which terms have bias
% 7 bit number
biasmask = '0000000';%from right to left -> a1 a2 omega range_landmark bearing_landmark range_agent bearing_agent
load_data_bitmask;%runs script that adds bias with random walk

%% run the simulation script
run_simple_coop_stat;

%% plots

marksUsing = cell(N,1);
newMarks = zeros(length(tspan),N);
for i = 1:N
   marksUsing{i} = abs(ags(i).rb(:,M+1:end)) <= d2r*FOV(i) & abs(ags(i).rb(:,1:M)) < RANGE(i) & abs(ags(i).rb(:,1:M)) > RANGEMIN(i);
   newMarks(:,i) = [sum( diff(marksUsing{i},1,1) > 0 ,2) > 0;0];
end

for i = 1:N
    figure;
    xtrue = ags(i).truth;
    % must convert inertial truth to the body frame
    for k = 1:length(tspan)
        C = [cos(xtrue(k,5)) sin(xtrue(k,5));
            -sin(xtrue(k,5)) cos(xtrue(k,5))];
        xtrue(k,1:2) = xtrue(k,1:2)*C';
    end
    xk(i).xk(1:2:end-1,5) = minangle(xk(i).xk(1:2:end-1,5),xk(i).xk(2:2:end-1,5));
    xbar = 0.5.*(xk(i).xk(1:2:end-1,:)+xk(i).xk(2:2:end-1,:));
    xbar(:,5) = minangle(xbar(:,5),xtrue(:,5));
    for j = 1:5
        subplot(5,1,j);
        plot(tk,xk(i).xk(:,j),'r--');
        %plot(tspan,xbar(:,j),'r--');
        hold on;
        plot(tspan,xtrue(:,j),'b-');
        % plot when we got new shared measurements
        if j == 1
            gotNew = find(newMarks(:,2));
            myNew = find(newMarks(:,1));
        else
            gotNew = find(newMarks(:,1));
            myNew = find(newMarks(:,2));
        end
        plot(tspan(gotNew),0*gotNew,'kx');
        plot(tspan(myNew),0*myNew,'md');
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
