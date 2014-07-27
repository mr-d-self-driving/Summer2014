clear variables;
clear global;
close all;

%addpath('../cooperative control');

load('2D Simulator for Summer 2014/bot_workspace.mat');

%Xr: [inertial X...
%   inertial Y...
%   heading ...]

%Xm: [body frame accel X...
%   body frame accel Y...
%   yaw rate ...
%   feature 1 bearing ...
%   feature 2 bearing...]

% estimator state: [x y vx vy psi bx bx br]

% accelerometer & gyro noise looks like process noise

% G matrix now defined in ekf_ol b/c it depends on the state

r_ax = sig_acc(1)^2;
r_ay = sig_acc(2)^2;
r_r = sig_gyro^2;
r_bearing = sig_bea(1)^2;
r_biasx = sig_acc_bias(1)^2;
r_biasy = sig_acc_bias(2)^2;
r_biasr = sig_gyro_bias^2;

Q = diag([r_ax r_ay r_r r_biasx r_biasy r_biasr]);

R = diag([r_bearing r_bearing]);

global thetam markers;
thetam = [t' Xm(4:5,:)'];
markers = Xf;%[x1 x2 x3...;y1 y2 y3...]
%% set up time histories for sim
% effective control history:
u = Xmtrue(1:3,:)';
%effective output history
y = Xmtrue(4:5,:)';
%%
close all;

x0 = zeros(8,1);
x0(3:4) = [cos(Xr(3,1)) sin(Xr(3,1));-sin(Xr(3,1)) cos(Xr(3,1))]*diff(Xr(1:2,1:2),1,2)./diff(t(1:2));
x0(6:8) = [acc_bias;gyro_bias];
P0 = 10*eye(8);

%Q = diag([10^(-4.5)*ones(1,2) 1e-4 1e-7*ones(1,3)]);
%R = diag(1e-12*ones(2,1));

[tout,xhatout,Phatout] = ekf_ol(@robot_dyn,@robot_meas,Q,R,t(1:1500),y,u,x0,P0);

figure;
subplot(211);
plot(tout,xhatout(:,1))
hold on
plot(t,Xr(1,:),'r--')

subplot(212);
plot(tout,xhatout(:,2));
hold on
plot(t,Xr(2,:),'r--');

figure;
subplot(211);
plot(tout,xhatout(:,3))
hold on
plot(tout,.2+.01*sin(tout),'r--')

subplot(212);
plot(tout,xhatout(:,4))
hold on
plot(tout,0*tout,'r--')

% figure;
% plot(tout,xhatout(:,5)*r2d);
% hold on;
% plot(t,Xr(3,:)*r2d,'r--');

figure;
subplot(311);
plot(tout,xhatout(:,6));
hold on;
plot(t,biastrue(:,1),'r--');

subplot(312);
plot(tout,xhatout(:,7));
hold on;
plot(t,biastrue(:,2),'r--');

subplot(313);
plot(tout,xhatout(:,8));
hold on;
plot(t,biastrue(:,3),'r--');