%% driver_simple_coop
clear variables;
close all;
addpath('..');

load data.mat;

% sensor noise levels to use
Rrange = [10 10];
Rbear = [.01 .01];
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
readmask = '1100';
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
run_simple_coop;

%% process feature measurement errors

% make a vector of landmark true positions
marksv = zeros(length(marks),2);
for i = 1:length(marks)
    marksv(i,:) = marks(i).xy;
end

rho_errs = zeros(N,length(tspan),M);
for J = 1:N
    merrors = zeros(length(tspan),M,2);
    for i = 1:length(tspan)
        % inertial feature relative position vector (true)
        mvect = marksv - repmat(ags(J).truth(i,1:2),M,1);
        % body frame relative postion vectors (true)
        Cbn = [cos(ags(J).truth(i,5)) sin(ags(J).truth(i,5));
            -sin(ags(J).truth(i,5)) cos(ags(J).truth(i,5))];
        mvect_b = mvect*Cbn';
        merrors(i,:,:) = mvect_b - reshape(xk(J).xk(2*i,4:end)',2,M)';
        rho_errs(J,i,:) = sqrt(sum(merrors(i,:,:).^2,3));
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
    end
    xk(i).xk(1:2:end-1,3) = minangle(xk(i).xk(1:2:end-1,3),xk(i).xk(2:2:end-1,3));
    xbar = 0.5.*(xk(i).xk(1:2:end-1,:)+xk(i).xk(2:2:end-1,:));
    xbar(:,3) = minangle(xbar(:,3),xtrue(:,5));
    for j = 1:3
        subplot(3,1,j);
        plot(tspan,xbar(:,j),'r--');
        hold on;
        plot(tspan,xtrue(:,j+2),'b-');
        title(['Agent ' num2str(i) ' estimates and truth']);
    end
    
    figure;
    for j = 1:3
        subplot(3,1,j);
        plot(tspan,xbar(:,j)-xtrue(:,j+2),'b-');
        hold on;
        plot(tk,3*sqrt(xk(i).Pk(:,(3+2*M)*(j-1)+j)),'r--');
        plot(tk,-3*sqrt(xk(i).Pk(:,(3+2*M)*(j-1)+j)),'r--');
        if j == 3
            set(gca,'ylim',[-1 1]);
        end
        title(['Agent ' num2str(i) ' errors']);
    end
    
    figure;
    plot(tk,xk(i).Pk);
    title('Covariance history');
    
    figure;
    plot(tspan,permute(rho_errs(i,:,:), [2 3 1]));
    title('Feature estimate position errors');
end

%% animate
