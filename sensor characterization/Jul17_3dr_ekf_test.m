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
folder = 'C:\Users\fatadama\Documents\summer 2014\Optitrack\July 17 3dr ekf test 2';
%%
fname1 = [folder '\log.csv'];
fname2 = [folder '\opti.csv'];

[dat2,txt] = xlsread(fname2);
[t,xyz,quat] = ros2body(dat2,txt);
    tdel = find(t > 125,1,'first');
    t(tdel+1:end) = [];
    xyz(tdel+1:end,:) = [];
    quat(tdel+1:end,:) = [];
[t,xyz,vb,ab,quat,wb,vn,an] = opti_velocities(t,xyz,quat,0);

% compute euler angles
euler = zeros(length(t),3);
for i = 1:length(t)
    X = attparsilent(quat(i,[4 1 2 3])',[6 4],struct('seq',[3 2 1]));
    euler(i,:) = X([3 2 1],1)';% ROLL PITCH THEN YAW
end

% compute body-frame acceleration "truth"
abacc = zeros(size(an));
for i = 1:length(t)
    B0 = quat(i,4);
    Bv = quat(i,1:3);
    C = attparsilent([B0 Bv]',[6 1]);%inertial-to-body
    
    anacc = an(i,:)' + [0;0;-9.81];
    abacc(i,:) = (C*anacc)';
end

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

tind = find(strcmp('PF_E_Vx',labels));
ekf = num(:,tind+(0:7));% Vx Vy Vz bank, pitch, yaw rate, z, barometer bias
ekf_var = num(:,tind+(11:18));

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
    XX = attparsilent([B0;Bv],[6 4],struct('seq',[3; 2; 1]));
    euler(j,:) = XX([3 2 1],1)';
    euler(j, euler(j,:) > pi ) = euler(j, euler(j,:) > pi ) - 2*pi;
end

% compute body-frame acceleration "truth"
abacc = zeros(size(an));
for i = 1:length(t)
    B0 = quat(i,4);
    Bv = quat(i,1:3);
    C = attparsilent([B0 Bv]',[6 1]);%inertial-to-body
    
    anacc = an(i,:)' + [0;0;-9.81];
    abacc(i,:) = (C*anacc)';
end

Cflow = eye(2);
vb_flow = vb(:,1:2)*Cflow';

%% align time histories

%delta = alignTimeHistories(t,euler(:,1),tv,ekf(:,4),0.47);% for Jul 17 test 1 
delta = alignTimeHistories(t,euler(:,1),tv,ekf(:,4),-5.33);
delta = alignTimeHistoriesPh(t,euler(:,1),tv,ekf(:,4));
t = t + delta; % better be sure the alignment is good
%% plot data

vb_in = interp1(t,vb,tv);
wb_in = interp1(t,wb,tv);
euler_in = interp1(t,euler,tv);
xyz_in = interp1(t,xyz,tv);

figure;
for i = 1:3
    subplot(3,1,i)
    plot(tv,ekf(:,i),'r--');
    hold on
    plot(t,vb(:,i),'-x');
    ylabel(['v_' num2str(i) ' m/s']);
end
set(gcf,'position',[150 250 1150 675]);
legend('est','truth');
% residuals
figure;
for i = 1:3
    subplot(3,1,i);
    plot(tv,ekf(:,i)-vb_in(:,i));
    hold on;
    plot(tv,LPOSV(:,i)-vb_in(:,i),'k--');
    plot(tv,3*sqrt(ekf_var(:,i)),'r--');
    plot(tv,-3*sqrt(ekf_var(:,i)),'r--');
    
    ylabel(['v_' num2str(i) ' errors (m/s)']);
end
legend('us','them');
set(gcf,'position',[150 250 1150 675]);
fprintf('v error std: %g m/s,%g m/s,%g m/s\n',nanstd(ekf(:,1:3)-vb_in(:,1:3)));
fprintf('v error rmse: %g m/s,%g m/s,%g m/s\n',sqrt(nanmean((ekf(:,1:3)-vb_in(:,1:3)).^2)));

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
plot(tv,sqrt(ekf_var(:,7))*3,'r--');
plot(tv,sqrt(ekf_var(:,7))*-3,'r--')
legend('us','them');
ylabel('z errors (m)');
set(gcf,'position',[150 250 1150 225]);
fprintf('Altitude error std: %g m\n',nanstd(ekf(:,7)-xyz_in(:,3)));

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
    legend('byu ekf','truth','px4 ekf');
set(gcf,'position',[150 250 1150 450]);
% residuals
figure;
    subplot(211);
    plot(tv,ekf(:,4)*r2d-euler_in(:,1)*r2d);
    hold on;
    plot(tv,Att(:,1)*r2d-euler_in(:,1)*r2d,'k--');
    plot(tv,r2d*3*sqrt(ekf_var(:,4)),'r--');
    plot(tv,r2d*-3*sqrt(ekf_var(:,4)),'r--');
    ylabel('\phi errors (deg)');

    subplot(212);
    plot(tv,ekf(:,5)*r2d-euler_in(:,2)*r2d);
    hold on;
    plot(tv,Att(:,2)*r2d-euler_in(:,2)*r2d,'k--');
    plot(tv,r2d*3*sqrt(ekf_var(:,5)),'r--');
    plot(tv,r2d*-3*sqrt(ekf_var(:,5)),'r--');
    ylabel('\theta errors (deg)');
set(gcf,'position',[150 250 1150 450]);
fprintf('Roll angle error std: %g deg\n',nanstd(ekf(:,4)-euler_in(:,1))*r2d);
fprintf('Pitch angle error std: %g deg\n',nanstd(ekf(:,5)-euler_in(:,2))*r2d);
fprintf('Their atttitude angle error std: %g deg %g deg\n',nanstd(Att(:,1:2)-euler_in(:,1:2))*r2d);
    
figure;
plot(t,wb(:,3));
hold on;
plot(tv,ekf(:,6),'r--','linewidth',2);
plot(tv,Att(:,6),'k--');
legend('truth','byu ekf','px4 ekf');
ylabel('r (rad/s)');
set(gcf,'position',[150 250 1150 225]);
%errors
figure;
plot(tv,ekf(:,6)-wb_in(:,3));
hold on;
plot(tv,Att(:,6)-wb_in(:,3),'k--');
legend('us','them');
ylabel('r errors (rad/s)');
plot(tv,3*sqrt(ekf_var(:,6)),'r--');
plot(tv,-3*sqrt(ekf_var(:,6)),'r--');
set(gcf,'position',[150 250 1150 225]);
fprintf('Yaw rate error std: %g rad/s\n',nanstd(ekf(:,6)-wb_in(:,2)));
%% plot acceleration & other reality checks
figure;
for i = 1:3
    subplot(3,1,i);
    plot(t,abacc(:,i),'b-');
    hold on;
    plot(tv,Acc(:,i),'r--');
    set(gca,'ylim',[-20 20]);
    ylabel(['a_' num2str(i) ' (m/s^2)']);
end

est_flow = ekf(:,1:2)*Cflow';
flow_conv = flow(:,3:4)*Cflow;

figure;
for i = 1:2
    subplot(2,1,i);
    %plot(t,vb_flow(:,i),'b-');
    plot(t,vb(:,i),'b-');
    hold on;
    %plot(tv,est_flow(:,i),'r--');
    plot(tv,ekf(:,i),'r--');
    %plot(tv,flow(:,i+2),'k--');
    plot(tv,flow_conv(:,i),'k--');
    legend('optitrack vel','ekf vel','compensated flow eq vel');
end
%%  plot accel vs velocity for kevin

accelsmooth = filter(.1*ones(10,1),1,Acc);

close all;
figure;
for i = 1:2
    subplot(2,1,i);
    plot(tv,accelsmooth(:,i),'r--');
    hold on;
    plot(tv,ekf(:,i));
end