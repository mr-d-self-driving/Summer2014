%% moving_flying_flow
% get flow sensor data from sensor moving, motors off

clear variables;
close all;

addpath('..');
addpath('../Optitrack');
addpath('../near system identification');

%get the folder the data are in:
%folder = uigetdir();
%debugging, use the dynamic flight data
folder = 'C:\Users\fatadama\Documents\summer 2014\Optitrack\June 30 EKF test';

fname1 = [folder '\log.csv'];
fname2 = [folder '\opti.csv'];

[dat2,txt] = xlsread(fname2);

%get the ROS frame time, position, attitudes
tind = find(strcmp(txt(1,:),'Timestamp in milliseconds'));
t = (dat2(:,tind) - dat2(1,tind));%time

xyzind = find(strcmp(txt(1,:),'Opti Pos X'));
xyzros = dat2(:,xyzind+(0:2));

quatind = find(strcmp(txt(1,:),'Opti Roll'));
optieuler = dat2(:,quatind+(0:2));
optieuler = optieuler(:,[1 2 3 ]);% opti roll-pitch-yaw
optieuler(:,2:3) = -optieuler(:,2:3);% are negative what they should be

%north-east-down inertial frame position components
xyz = [xyzros(:,1) xyzros(:,2) -xyzros(:,3)];

%inertial frame
quat = zeros(size(optieuler,1),4);
for i = 1:length(t)
    
    X = attparsilent([optieuler(i,[3 2 1])' [3;2;1]],[4 6]);
    quat(i,4) = X(1,1);
    quat(i,1:3) = X(2:4,1);
end

%[t,xyz,vb,ab,quat,wb,vn,an] = opti_velocities(t,xyz,quat,0);
vn = diff(xyz)./repmat(diff(t),1,3);
vb = zeros(size(vn));
an = diff(vn)./repmat(diff(t(2:end)),1,3);
for i = 1:length(vn)
    C = attparsilent(quat(i,[4 1 2 3])',[6 1]);
    vb(i,:) = vn(i,:)*C';
end
wb = diff(optieuler)./repmat(diff(t),1,3);

t = t(2:end-1);
vn = vn(1:end-1,:);
vb = vb(1:end-1,:);
xyz = xyz(2:end-1,:);
wb = wb(2:end,:);

[num,txt] = xlsread(fname1);
labels = txt(1,:);

%% vehicle histories:
tind = find(strcmp('TIME_StartTime',labels));
tfirst = find(~isnan(num(:,tind)),1,'first');
%delete nans
num(1:tfirst-1,:) = [];
tv     = (num(:,tind) - num(1,tind))/10^6;
% cut the body-frame time to match the optitrack time
incut = find( tv < min(t) | tv > max(t) );
tv(incut) = [];
num(incut,:) = [];

tind = find(strcmp('IMU_AccX',labels));
Acc   = num(:,tind+(0:2));% are the acc and gyro values raw? based on the log, they *might* be.
Gyro  = num(:,tind+(3:5));
Mag   = num(:,tind+(6:8));

tind = find(strcmp('LPOS_X',labels));
LPOS  = num(:,tind+(0:2));% vehicle local position histories - these are not raw?
tind = find(strcmp('LPOS_VX',labels));
LPOSV = num(:,tind+(0:2));

tind = find(strcmp('RC_Ch0',labels));
RC    = num(:,tind+(0:8));

tind = find(strcmp('ATT_Roll',labels));
Att   = num(:,tind+(0:8)); % roll, pitch, yaw & rates

% find raw flow data
tind = find(strcmp('FLOW_RawX',labels));
flow = num(:,tind+(0:6));

%find barometric alt
tind = find(strcmp('SENS_BaroAlt',labels));
baro = num(:,tind);

tind = find(strcmp('BYU__Vx',labels));
ekf = num(:,tind+(0:7));% Vx Vy Vz bank, pitch, yaw rate, z, barometer bias

Easy  = round(RC(:,5));

inde = find(Easy==0);
% compute vehicle inertial velocity components
vn_quad = zeros(size(LPOSV));
for i = 1:length(tv)
    C = DCMConverter(1,Att(i,1))*DCMConverter(2,Att(i,2))*DCMConverter(3,Att(i,3));%body-to-inertial
    vn_quad(i,:) = LPOSV(i,:)*C;
end
% compute optitrack euler angle histories
euler = zeros(length(t),3);
for j = 1:length(t)
    B0 = quat(j,4);
    Bv = quat(j,1:3)';
    XX = attpar([B0;Bv],[6 4],struct('seq',[3; 2; 1]));
    euler(j,:) = XX([3 2 1],1)';
    euler(j, euler(j,:) > pi ) = euler(j, euler(j,:) > pi ) - 2*pi;
end

% compute body-frame acceleration "truth"
abacc = zeros(size(an));
for i = 1:length(t)
    B0 = quat(i,4);
    Bv = quat(i,1:3);
    C = attpar([B0 Bv]',[6 1]);%inertial-to-body
    
    anacc = an(i,:)' + [0;0;-9.81];
    abacc(i,:) = (C*anacc)';
end

Cflow = [cos(pi/4) sin(pi/4);-sin(pi/4) cos(pi/4)];
vb_flow = vb(:,1:2)*Cflow';

vb_in = interp1(t,vb,tv);
wb_in = interp1(t,wb,tv);
euler_in = interp1(t,euler,tv);
xyz_in = interp1(t,xyz,tv);

%% align time histories

delta = alignTimeHistories(t,wb(:,3),tv,ekf(:,6),-19.076);
t = t + delta; % better be sure the alignment is good
%% plot data

figure;
for i = 1:3
    subplot(3,1,i)
    plot(tv,ekf(:,i),'r--');
    hold on
    if i < 3
        if i == 2
            plot(t,-vb_flow(:,i));
        else
            plot(t,vb_flow(:,i));
        end
    else
        plot(t,vb(:,i));
    end
    ylabel(['v_' num2str(i) ' m/s']);
end
set(gcf,'position',[150 250 1150 675]);
% residuals
figure;
plot(tv,ekf(:,3)-vb_in(:,3));
hold on;
plot(tv,LPOSV(:,3)-vb_in(:,3),'k--');
ylabel('v_3 errors (m/s)');
set(gcf,'position',[150 250 1150 225]);
fprintf('v_3 error std: %g m/s\n',std(ekf(:,3)-vb_in(:,3)));

figure;
plot(tv,ekf(:,7),'r--');
hold on;
%plot(tv,-flow(:,5),'k-x');
plot(t,xyz(:,3));
ylabel('z (m)');
set(gcf,'position',[150 250 1150 225]);
% residuals
figure;
plot(tv,ekf(:,7)-xyz_in(:,3));
hold on;
plot(tv,LPOS(:,3)-xyz_in(:,3),'k--');
ylabel('z errors (m)');
set(gcf,'position',[150 250 1150 225]);
fprintf('Altitude error std: %g m\n',std(ekf(:,7)-xyz_in(:,3)));

figure;
    subplot(211);
    plot(tv,ekf(:,4)*r2d,'r--');
    hold on;
    plot(t,euler(:,1)*r2d);
    plot(tv,Att(:,1)*r2d,'k--');
    ylabel('\phi (deg)')

    subplot(212);
    plot(tv,ekf(:,5)*r2d,'r--');
    hold on;
    plot(t,euler(:,2)*r2d);
    plot(tv,Att(:,2)*r2d,'k--');
    ylabel('\theta (deg)');
set(gcf,'position',[150 250 1150 450]);
% residuals
figure;
    subplot(211);
    plot(tv,ekf(:,4)*r2d-euler_in(:,1)*r2d);
    hold on;
    plot(tv,Att(:,1)*r2d-euler_in(:,1)*r2d,'k--');
    ylabel('\phi errors (deg)');

    subplot(212);
    plot(tv,ekf(:,5)*r2d-euler_in(:,2)*r2d);
    hold on;
    plot(tv,Att(:,2)*r2d-euler_in(:,2)*r2d,'k--');
    ylabel('\theta errors (deg)');
set(gcf,'position',[150 250 1150 450]);
fprintf('Roll angle error std: %g deg\n',std(ekf(:,4)-euler_in(:,1))*r2d);
fprintf('Pitch angle error std: %g deg\n',std(ekf(:,5)-euler_in(:,2))*r2d);
    
figure;
plot(t,wb(:,3));
hold on;
plot(tv,ekf(:,6),'r--','linewidth',2);
plot(tv,Att(:,6),'k--');
ylabel('r (rad/s)');
set(gcf,'position',[150 250 1150 225]);
%errors
figure;
plot(tv,ekf(:,6)-wb_in(:,3));
hold on;
plot(tv,Att(:,6)-wb_in(:,3),'k--');
ylabel('r errors (rad/s)');
set(gcf,'position',[150 250 1150 225]);
fprintf('Yaw rate error std: %g rad/s\n',std(ekf(:,6)-wb_in(:,2)));
%% 

accelsmooth = filter(.1*ones(10,1),1,Acc);

close all;
figure;
for i = 1:3
    subplot(3,1,i);
    plot(tv,accelsmooth(:,1),'r--');
    hold on;
    plot(tv,ekf(:,1));
end