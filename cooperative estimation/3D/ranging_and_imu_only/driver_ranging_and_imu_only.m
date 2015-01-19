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
std_dec = 1e-4;%0.1/3;% nominal 10 cm acc.
% gyro stdev
gyro_noise = 1e-6;%rads
% accelerometer stdev
accel_noise = 1e-4;%metres/sec^2
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

Ns = 20;
Ns2 = Ns^2;% size of the covariance matrix


xh = cell(2,1);
Ph = cell(2,1);

% initialize
for i = 1:2
    % random quaternion
    xh{i} = zeros(length(tv),Ns);
    Ph{i} = zeros(length(tv),Ns2);
    % initialize
    xh{i}(1,7:10) = randn(4,1);xh{i}(1,7:10) = xh{i}(1,7:10)./norm(xh{i}(1,7:10));% inertial attitude
    xh{i}(1,14:17) = randn(4,1);xh{i}(1,14:17) = xh{i}(1,14:17)./norm(xh{i}(1,14:17));% inertial attitude
    xh{i}(1,1:3) = randn(3,1).*[1;1;1];% inertial position, inertial frame
    xh{i}(1,11:13) = randn(3,1).*[5;5;5];%relative position, body frame
    xh{i}(1,4:6) = [0 0 0];%randn(3,1);% inertial velocity, body frame
    % initial covariance for the 17 base states
    Ph{i}(1,:) = reshape( diag([0.1*ones(1,3) 0.1*ones(1,3)  0.1*ones(1,4) 0.1*ones(1,3) 0.1*ones(1,4) 0.1*ones(1,3)]) + 1e-6*ones(Ns), Ns2,1)';
end

xh{1}(1,11:13) = rji_i_tr(1,:);
xh{2}(1,11:13) = rij_j_tr(1,:);
xh{1}(1,14:17) = qji(1,:);
xh{2}(1,14:17) = [-qji(1,1) qji(1,2:4)];

%% run filter
% modelled measurements error
Rx = diag(std_dec*ones(1,6)).^2;

tic;
for j = 1:2
    for k = 1:length(T)-1
        %% update
        xhat = xh{j}(k,1:Ns)';
        Pk = reshape(Ph{j}(k,1:Ns2)',Ns,Ns);
        
        % own state estimates
        rin = xhat(1:3);
        qin = xhat(7:10);
        Cin = attparsilent(qin,[6 1]);
        
        % measurements - range to other agent's beacons  
        ytilde = zeros(6,1);
        ytilde(1:3) = permute( RF(k,j,:),[3 1 2]);
        if k == 1
            ytilde(4:6) = permute( RF(2,j,:),[3 1 2]);
        else
            ytilde(4:6) = permute( RF(1,j,:),[3 1 2]);
        end
        
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
        uk = [wi;wj;ai;aj; reshape(rkj_j,9,1)];
        yk = ytilde;
        
        Pvk = Qk;
        
        Pnk = Rx;
        
        [xp,Pp] = ukf_update_ranging_and_imu(xhat,Pk,Pvk,Pnk,uk,yk,1e-3);
        
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

Pdiag = 1:Ns:Ns2;

qji_in = interp1(T,qji,tv);

xh{1}(:,14:17) = quatmin(xh{1}(:,14:17),qji_in);
xh{2}(:,14:17) = quatmin(xh{2}(:,14:17),[-qji_in(:,1) qji_in(:,2:4)]);

xh{1}(:,7:10) = quatmin(xh{1}(:,7:10),Yc{1}(:,7:10));
xh{2}(:,7:10) = quatmin(xh{2}(:,7:10),Yc{2}(:,7:10));

for k = 1:4
    subplot(2,2,k);
    plot(tv,xh{1}(:,13+k),'--x');
    hold on;
    plot(tv,xh{1}(:,13+k) + 3*sqrt(Ph{1}(:,Pdiag(13+k))),'r--');
    plot(tv,xh{1}(:,13+k) - 3*sqrt(Ph{1}(:,Pdiag(13+k))),'r--');
    plot(T,qji(:,k),'k-','linewidth',2);
    set(gca,'ylim',[-1 1]);
end
set(gcf,'position',[200 275 1300 625])

figure;
for k = 1:4
    subplot(2,2,k);
    plot(tv,xh{2}(:,13+k),'--x');
    hold on;
    plot(tv,xh{2}(:,13+k) + 3*sqrt(Ph{2}(:,Pdiag(13+k))),'r--');
    plot(tv,xh{2}(:,13+k) - 3*sqrt(Ph{2}(:,Pdiag(13+k))),'r--');
    if k == 1
        plot(T,-qji(:,k),'k-','linewidth',2);
    else
        plot(T,qji(:,k),'k-','linewidth',2);
    end
    set(gca,'ylim',[-1 1]);
end
set(gcf,'position',[200 275 1300 625])

figure;
for k = 1:3
    subplot(3,1,k);
    plot(tv,xh{1}(:,10+k),'--x');
    hold on;
    plot(tv,xh{1}(:,10+k) + 3*sqrt(Ph{1}(:,Pdiag(10+k))),'r--');
    plot(tv,xh{1}(:,10+k) - 3*sqrt(Ph{1}(:,Pdiag(10+k))),'r--');
    plot(T,rji_i_tr(:,k),'k-','linewidth',2);
end
set(gcf,'position',[200 275 1300 625])

figure;
for k = 1:3
    subplot(3,1,k);
    plot(tv,xh{2}(:,10+k),'--x');
    hold on;
    plot(tv,xh{2}(:,10+k) + 3*sqrt(Ph{2}(:,Pdiag(10+k))),'r--');
    plot(tv,xh{2}(:,10+k) - 3*sqrt(Ph{2}(:,Pdiag(10+k))),'r--');
    plot(T,rij_j_tr(:,k),'k-','linewidth',2);
end
set(gcf,'position',[200 275 1300 625])

figure;
for k = 1:3
    subplot(3,1,k);
    plot(tv,xh{1}(:,17+k),'--x');
    hold on;
    plot(tv,xh{1}(:,17+k) + 3*sqrt(Ph{1}(:,Pdiag(17+k))),'r--');
    plot(tv,xh{1}(:,17+k) - 3*sqrt(Ph{1}(:,Pdiag(17+k))),'r--');
    plot(T,v2_2(:,k),'k-','linewidth',2);
end
set(gcf,'position',[200 275 1300 625])

figure;
for k = 1:3
    subplot(3,1,k);
    plot(tv,xh{2}(:,17+k),'--x');
    hold on;
    plot(tv,xh{2}(:,17+k) + 3*sqrt(Ph{2}(:,Pdiag(17+k))),'r--');
    plot(tv,xh{2}(:,17+k) - 3*sqrt(Ph{2}(:,Pdiag(17+k))),'r--');
    plot(T,v1_1(:,k),'k-','linewidth',2);
end
set(gcf,'position',[200 275 1300 625])