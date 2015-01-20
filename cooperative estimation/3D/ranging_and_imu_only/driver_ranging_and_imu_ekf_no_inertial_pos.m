% runs EKF with 9 x 2 localizer relative measurements, does not try to
% estimate inertial position at all

clear variables;
close all;

global Ts;

%addpath('../../2D');
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

% compute truth
qji = zeros(length(T),4);
v2_2 = zeros(length(T),3);
v1_1 = zeros(length(T),3);
rji_i_tr = zeros(length(T),3);
rij_j_tr = zeros(length(T),3);
for k = 1:length(T)
    Cin = attparsilent(Yc{1}(k,7:10)',[6 1]);
    Cjn = attparsilent(Yc{2}(k,7:10)',[6 1]);
    Cji = Cjn*Cin';
    qji_tr = attparsilent(Cji,[1 6]);
    qji(k,:) = qji_tr';
    % agent 1 velocity
    v1_1(k,:) = Cin*(Yc{1}(k,4:6)');
    % agent 2 velocity
    v2_2(k,:) = Cjn*(Yc{2}(k,4:6)');
    % agent 1 relative position
    rji_i_tr(k,:) = Cin*(Yc{2}(k,1:3)' - Yc{1}(k,1:3)');
    % agent 2 relative position
    rij_j_tr(k,:) = Cjn*(Yc{1}(k,1:3)' - Yc{2}(k,1:3)');
end
qji = quatmin(qji);

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

Ns = 17;
Ns2 = Ns^2;% size of the covariance matrix


xh = cell(2,1);
Ph = cell(2,1);

% initialize
for i = 1:2
    % random quaternion
    xh{i} = zeros(length(tv),Ns);
    Ph{i} = zeros(length(tv),Ns2);
    % initialize
    xh{i}(1,1:3) = [0 0 0];%randn(3,1);% inertial velocity, body frame
    xh{i}(1,4:7) = randn(4,1);xh{i}(1,4:7) = xh{i}(1,4:7)./norm(xh{i}(1,4:7));% inertial attitude
    xh{i}(1,8:10) = randn(3,1).*[5;5;5];%relative position, body frame
    xh{i}(1,11:14) = randn(4,1);xh{i}(1,11:14) = xh{i}(1,11:14)./norm(xh{i}(1,11:14));% inertial attitude
    % initial covariance for the 20 base states
    Ph{i}(1,:) = reshape( diag([0.01*ones(1,3)  0.2*ones(1,4) 1*ones(1,3) 0.2*ones(1,4) 0.01*ones(1,3)]) + 1e-6*ones(Ns), Ns2,1)';
end

%xh{1}(1,8:10) = rji_i_tr(1,:);
%xh{2}(1,8:10) = rij_j_tr(1,:);
%xh{1}(1,11:14) = qji(1,:);
%xh{2}(1,11:14) = [-qji(1,1) qji(1,2:4)];

%% run filter
% modelled measurements error
Rx = diag(std_dec*ones(1,18)).^2;

tic;
for j = 1:2
    for k = 1:length(T)-1
        %% update
        xhat = xh{j}(k,1:Ns)';
        Pk = reshape(Ph{j}(k,1:Ns2)',Ns,Ns);
                
        % measurements - range to other agent's beacons  
        ytilde = zeros(6,1);
        ytilde(1:9) = permute( RF(k,j,:),[3 1 2]);
        if j == 1
            ytilde(10:18) = permute( RF(k,2,:),[3 1 2]);
            % my measured angular velocity
            wi = W(k,1:3)';
            ai = A(k,1:3)';
            % his
            wj = W(k,4:6)';
            aj = A(k,4:6)';
        else
            ytilde(10:18) = permute( RF(k,1,:),[3 1 2]);
            % my measured angular velocity
            wi = W(k,4:6)';
            ai = A(k,4:6)';
            % his
            wj = W(k,1:3)';
            aj = A(k,1:3)';
        end
        
        % "inputs" vector
        uk = [wi;wj;ai;aj; reshape(rkj_j,9,1)];
        
        %[xp,Pp] = ukf_update_ranging_and_imu(xhat,Pk,Pvk,Pnk,uk,yk,1e-3);
        [xp,Pp] = ekf_propagate_ranging_and_imu_17(xhat,uk,Pk,Qk,Ts);
        [xp,Pp] = ekf_update_ranging_and_imu_17(xp,uk,Pp,Rx,ytilde);
                    
        if any(any(isnan(Pp)))
            disp('Error: NaN in covariance output');
            break;
        end
        
        % store
        xh{j}(k+1,1:Ns) = xp';
        Ph{j}(k+1,1:Ns2) = reshape(Pp,Ns2,1)';

        if ~mod(k-1,100)
            etaCalc((j-1)*length(T) + k,2*length(T),toc);
        end
    end
end
toc;

%% process

Pdiag = 1:(Ns+1):Ns2;

qji_in = interp1(T,qji,tv);

xh{1}(:,11:14) = quatmin(xh{1}(:,11:14),qji);
xh{2}(:,11:14) = quatmin(xh{2}(:,11:14),[-qji(:,1) qji(:,2:4)]);

xh{1}(:,4:7) = quatmin(xh{1}(:,4:7),Yc{1}(:,7:10));
xh{2}(:,4:7) = quatmin(xh{2}(:,4:7),Yc{2}(:,7:10));

% relative attitide errors
err = zeros(length(T),2);
for k = 1:length(T)
    Cji = attparsilent(xh{1}(k,11:14)',[6 1]);
    Cji_tr = attparsilent(qji(k,:)',[6 1]);
    gar = attparsilent(Cji*Cji_tr',[1 2]);
    err(k,1) = gar(1,2);
    Cij = attparsilent(xh{2}(k,11:14)',[6 1]);
    Cij_tr = attparsilent([-qji(k,1) qji(k,2:4)]',[6 1]);
    gar = attparsilent(Cij*Cij_tr',[1 2]);
    err(k,2) = gar(1,2);
end

% for k = 1:4
%     subplot(2,2,k);
%     plot(tv,xh{1}(:,13+k),'--x');
%     hold on;
%     plot(tv,xh{1}(:,13+k) + 3*sqrt(Ph{1}(:,Pdiag(13+k))),'r--');
%     plot(tv,xh{1}(:,13+k) - 3*sqrt(Ph{1}(:,Pdiag(13+k))),'r--');
%     plot(T,qji(:,k),'k-','linewidth',2);
%     set(gca,'ylim',[-1 1]);
% end
% set(gcf,'position',[200 275 1300 625])
% title('Agent 1 relative heading estimate');
% 
% figure;
% for k = 1:4
%     subplot(2,2,k);
%     plot(tv,xh{2}(:,13+k),'--x');
%     hold on;
%     plot(tv,xh{2}(:,13+k) + 3*sqrt(Ph{2}(:,Pdiag(13+k))),'r--');
%     plot(tv,xh{2}(:,13+k) - 3*sqrt(Ph{2}(:,Pdiag(13+k))),'r--');
%     if k == 1
%         plot(T,-qji(:,k),'k-','linewidth',2);
%     else
%         plot(T,qji(:,k),'k-','linewidth',2);
%     end
%     set(gca,'ylim',[-1 1]);
% end
% set(gcf,'position',[200 275 1300 625])
% title('Agent 2 relative heading estimate');

figure;
subplot(211);
plot(tv,err(:,1));
title('Agent 1 relative heading estimate angle error')

subplot(212);
plot(tv,err(:,2));
title('Agent 2 relative heading estimate angle error')
set(gcf,'position',[200 275 1300 625]);

figure;
for k = 1:3
    subplot(3,1,k);
    plot(tv,xh{1}(:,7+k),'--x');
    hold on;
    plot(tv,xh{1}(:,7+k) + 3*sqrt(Ph{1}(:,Pdiag(7+k))),'r--');
    plot(tv,xh{1}(:,7+k) - 3*sqrt(Ph{1}(:,Pdiag(7+k))),'r--');
    plot(T,rji_i_tr(:,k),'k-','linewidth',2);
end
set(gcf,'position',[200 275 1300 625])
title('Agent 1 estimate of agent 2 position');

figure;
for k = 1:3
    subplot(3,1,k);
    plot(tv,xh{2}(:,7+k),'--x');
    hold on;
    plot(tv,xh{2}(:,7+k) + 3*sqrt(Ph{2}(:,Pdiag(7+k))),'r--');
    plot(tv,xh{2}(:,7+k) - 3*sqrt(Ph{2}(:,Pdiag(7+k))),'r--');
    plot(T,rij_j_tr(:,k),'k-','linewidth',2);
end
set(gcf,'position',[200 275 1300 625])
title('Agent 2 estimate of agent 1 position');

figure;
for k = 1:3
    subplot(3,1,k);
    plot(tv,xh{1}(:,14+k),'--x');
    hold on;
    plot(tv,xh{1}(:,14+k) + 3*sqrt(Ph{1}(:,Pdiag(14+k))),'r--');
    plot(tv,xh{1}(:,14+k) - 3*sqrt(Ph{1}(:,Pdiag(14+k))),'r--');
    % plot 2's own velocity estimate
    plot(tv,xh{2}(:,k),'g--x');
    plot(tv,xh{2}(:,k) + 3*sqrt(Ph{2}(:,Pdiag(k))),'r--');
    plot(tv,xh{2}(:,k) - 3*sqrt(Ph{2}(:,Pdiag(k))),'r--');
    plot(T,v2_2(:,k),'k-','linewidth',2);
    title('Estimates of agent 2 velocity');
end
set(gcf,'position',[200 275 1300 625])

figure;
for k = 1:3
    subplot(3,1,k);
    plot(tv,xh{2}(:,14+k),'--x');
    hold on;
    plot(tv,xh{2}(:,14+k) + 3*sqrt(Ph{2}(:,Pdiag(14+k))),'r--');
    plot(tv,xh{2}(:,14+k) - 3*sqrt(Ph{2}(:,Pdiag(14+k))),'r--');
    % plot 1's own velocity estimate
    plot(tv,xh{1}(:,k),'g--x');
    plot(tv,xh{1}(:,k) + 3*sqrt(Ph{1}(:,Pdiag(k))),'r--');
    plot(tv,xh{1}(:,k) - 3*sqrt(Ph{1}(:,Pdiag(k))),'r--');
    plot(T,v1_1(:,k),'k-','linewidth',2);
    title('Estimates of agent 1 velocity');
end
set(gcf,'position',[200 275 1300 625])