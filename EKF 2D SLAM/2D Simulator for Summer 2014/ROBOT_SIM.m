% CODE TO SIMULATE ROBOT MOVING IN AN ENVIRONMENT WITH FEATURES.

clc
clear all
close all

global dt u w nf R Q

%% Constants

tf = 500;%100;
dt = .1;%1;
t  =  0 : dt : tf;
nf = 2; % No. of features
sig_acc = [0.01;0.01];
sig_acc_bias = [0.0001;0.0001];
sig_gyro = 0.01;
sig_gyro_bias = 0.0001;
sig_bea = 0.00001*ones(nf,1); % Bearing to features

%% Features - Randomly generate feature points bearings and range in inertial frame

rf = 20*randn(nf,1);
thetaf = 2*pi*randn(nf,1);% 0 : 2*pi/nf : 2*pi-2*pi/nf;
Xf = repmat(rf',2,1).*[cos(thetaf)';sin(thetaf)'];

%% Simulate 

% Xr - Robot Inertial position and bearing
%  Xf - Fixed features position and bearing
%  acc - Acceleration measured in robot's body fixed frame
%  gyro - Gyro reading on the robot along z
%  hf  - bearing of features measured by robots 
%  u1 and u2 are parameters used to vary forward velocity and turn rate

Xr(:,1) = [0;0;0];
hf      = headings(Xf,Xr);

% FIRST SENSOR MEASUREMENTS
acc_bias = 0;
gyro_bias = 0;

% SENSOR NOISE AND BIAS
acc_noise     = sig_acc.*randn(2,1); % Noise in aX,aY
acc_bias      = acc_bias + sig_acc_bias.*randn(2,1);
gyro_noise    = sig_gyro.*randn(1,1); % Noise in X,Y and heading
gyro_bias     = gyro_bias + sig_gyro_bias.*randn(1,1);
bea_noise     = sig_bea.*randn(nf,1); % Noise in bearing measurements

u1 = 0.01;
u2 = 0.05;

% TIME LOOP

Xmtrue = zeros(5,length(t));
biastrue = zeros(length(t),3);
for i = 1 : length(t)-1

    %% FORWARD VELOCITY AND TURN RATE OF THE ROBOT
        
    u = 0.2 + u1*sin(t(i));
    w = 0.2 + u2*cos(t(i));
    
    %% PROPAGATION USING RANGE KUTTA
    
    Xr(:,i+1)     = rk4_X(t(i),Xr(:,i)); % vehicle states X,Y,psi i inertial frame
    Xr(3,i+1)     = pi_to_pi(Xr(3,i+1)); % Converting psi to stay between -pi to pi
    hf            = headings(Xf,Xr(:,i+1)); % True bearing theta

    % SENSOR NOISE AND BIAS
    acc_noise     = sig_acc.*randn(2,1); % Noise in aX,aY 
    acc_bias      = acc_bias + sig_acc_bias.*randn(2,1);
    gyro_noise    = sig_gyro.*randn(1,1); % Noise in X,Y and heading
    gyro_bias     = gyro_bias + sig_gyro_bias.*randn(1,1);
    bea_noise     = sig_bea.*randn(nf,1); % Noise in bearing measurements
    biastrue(i,:) = [acc_bias;gyro_bias]';
    
    % SENSOR MEASUREMENTS - Xm(:,i) = [ax; ay; psi_dot; theta_f]  body accelerations, gyro and bearing    
    R = [cos(Xr(3,i+1))  sin(Xr(3,i+1)); -sin(Xr(3,i+1))  cos(Xr(3,i+1))]; % Rotation matrix from inertial to body
    %Pre-multiplying by R moves inertial frame to body frame
    Xmtrue(1:2,i+1) = R*[-u*w*sin(Xr(3,i+1))+u1*cos(t(i))*cos(Xr(3,i+1)); u*w*cos(Xr(3,i+1))+u1*cos(t(i))*sin(Xr(3,i+1))];
    Xmtrue(3,i+1)  = w; % Measured feature bearing in vehicle frame             
    Xmtrue(4:nf+3,i+1) = hf;
    
    Xm(1:2,i+1) = R*[-u*w*sin(Xr(3,i+1))+u1*cos(t(i))*cos(Xr(3,i+1)); u*w*cos(Xr(3,i+1))+u1*cos(t(i))*sin(Xr(3,i+1))] + acc_noise + acc_bias; % Inertial Accelerations
    Xm(3,i+1)  = w + gyro_noise + gyro_bias; % Measured feature bearing in vehicle frame             
    Xm(4:nf+3,i+1) = hf + bea_noise;
    
end

t(1) = [];Xm(:,1) = [];Xmtrue(:,1) = [];Xr(:,1) = [];
biastrue(1,:) = [];

save bot_workspace.mat;