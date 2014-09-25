%% driver_coop_bearing
% driver for single simulation with feature bearing measurements only
clear variables;
clear global;
close all;
addpath('..');

global marks;

load('data.mat');

% sensor noise levels to use
Rrange = 1e-2*ones(1,N);
Rbear = 1e-1*ones(1,N);
Rrange_ag = 1e-1;
Rbear_ag = 1e-2;
Rimu = 1e-1*diag([.5^2 .5^2 .1^2]);

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
known_features = 1;

FOV = [65 65];%half-angle of sensor FOV for each agent's feature detection, IN DEGREES
RANGE = [15 15];% maximum sensitivity
RANGEMIN = [1 1];%minimum range

% generate new sensor noise consistent with defined levels
TRUTH = 0;
gen_new_noise;
%bitmask for which terms have bias
% 7 bit number
biasmask = '0000000';%from right to left -> a1 a2 omega range_landmark bearing_landmark range_agent bearing_agent
load_data_bitmask;%runs script that adds bias with random walk

%% run the simulation script
if known_features == 1
    run_simple_coop_stat_new;
else
    disp('Warning: unknown feature case not fully integrated');
    run_simple_unknown;
end

%% relative plots
if known_features == 1
    if imu_sharing
        plot_imu_sharing;
    else
        plot_no_imu_sharing;
    end
else
    % unknown feature plots
    marksv = zeros(M,2);
    for j = 1:M
        marksv(j,:) = marks(j).xy;
    end
    
    for j = 1:N
        Nf = xk(j).Nf;
        psicmp = ags(j).truth(:,5) - ags(j).truth(1,5);
        % true inertial frame to agent inertial frame DCM
        Ctr_n = [cos(ags(j).truth(1,5)) sin(ags(j).truth(1,5));-sin(ags(j).truth(1,5)) cos(ags(j).truth(1,5))];
        rbcmp = ags(j).truth(:,1:2)*Ctr_n';
        rbcmp = rbcmp - repmat(rbcmp(1,:),length(tspan),1);
        
        % mean estimate, used for computing errors
        xkbar = 0.5*(xk(j).xk(1:2:end-1,:)+xk(j).xk(2:2:end,:));
        xkbar(:,5) = minangle(xkbar(:,5),psicmp);
        % covariance diagonal terms
        Pdiag = 1:(5+4*M*N+1):(5+4*M*N)^2;
        
        feature_x = xk(j).xk(:,6:4:end);
        feature_y = xk(j).xk(:,7:4:end);
        invrho = xk(j).xk(:,8:4:end);
        theta = xk(j).xk(:,9:4:end);
        
        % feature_xxyy is organized as [x1 x2 x3 .... y1 y2 y3]
        feature_use = find(feature_x(end,:) ~= 0);
        feature_xxyy = ([feature_x feature_y] + repmat(1./invrho,1,2).*[cos(theta) sin(theta)]);
        feature_xxyy = feature_xxyy(:,[feature_use M*N+feature_use]);
        % rel_r is organized as [x1 x2 x3 ... y1 y2 y3]
        rel_r = feature_xxyy-[repmat(xk(j).xk(:,1),1,size(feature_xxyy,2)/2) repmat(xk(j).xk(:,2),1,size(feature_xxyy,2)/2)];
        % rel_truth is organized as [x1 y1 x2 y2... xn yn]
        rel_truth = repmat( reshape(marksv',1,[]), length(tspan),1) - repmat( ags(j).truth(:,1:2) ,1,M);
        
        rho_est = sqrt(rel_r(:,1:size(feature_xxyy,2)/2).^2 + rel_r(:,size(feature_xxyy,2)/2+1:end).^2);
        % relative heading to features
        theta_est = pi2pi(atan2(rel_r(:,size(feature_xxyy,2)/2+1:end),rel_r(:,1:size(feature_xxyy,2)/2)) - ...
            repmat(xk(j).xk(:,5),1,size(feature_xxyy,2)/2));
        ixmod = mod(xk(j).fl'-1,M)+1;
        
        %[~,ix] = sort(xk(j).fl);
        %rho_est = rho_est(:,ix);
        %theta_est = pi2pi(theta_est(:,ix));
        
        rho_true = sqrt(rel_truth(:,1:2:end-1).^2 + rel_truth(:,2:2:end).^2);
        theta_true = atan2(rel_truth(:,2:2:end),rel_truth(:,1:2:end-1)) - repmat(ags(j).truth(:,5),1,M);
        rho_cmp = rho_true(:,ixmod);
        theta_cmp = theta_true(:,ixmod);
        %rho_true = repmat(ags(j).rb(:,1:M),1,N);
        %theta_true = repmat(pi2pi(ags(j).rb(:,M+1:2*M)),1,N);
        
        MN = size(feature_xxyy,2)/2;
        
        figure;
        for k = 1:6
            subplot(3,2,k);
            ix = floor((MN/6*(k-1))+(1:(MN/6)));
            plot(tspan,rho_cmp(:,ix));
            hold on;
            plot(tk,rho_est(:,ix),'--');
            set(gca,'ylim',[0 50]);
        end
        
        figure;
        for k = 1:6
            subplot(3,2,k);
            ix = floor((MN/6*(k-1))+(1:(MN/6)));
            plot(tspan,theta_cmp(:,ix));
            hold on;
            plot(tk,theta_est(:,ix),'--');
        end
        
        figure;
        for i = 1:2
            subplot(3,1,i);
            plot(tspan,ags(j).truth(:,i+2));
            hold on;
            plot(tk,xk(j).xk(:,i+2),'r--');
        end
        subplot(3,1,3);
        plot(tspan,pi2pi(psicmp));
        hold on;
        plot(tspan,xkbar(:,5),'r--');
        title(['Agent ' num2str(j) ' velocity and heading']);
        
        figure;
        for i = 3:5
            subplot(3,1,i-2);
            if i < 5
                plot(tspan,ags(j).truth(:,i)-xkbar(:,i),'-');
            else
                plot(tspan,psicmp-xkbar(:,i),'-');
            end
            hold on;
            plot(tk,3*xk(j).Pk(:,Pdiag(i)),'r--');
            plot(tk,-3*xk(j).Pk(:,Pdiag(i)),'r--');
        end
        title(['Agent ' num2str(j) ' velocity and heading errors']);
    end
end