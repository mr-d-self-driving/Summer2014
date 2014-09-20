clear variables;
close all;

addpath('utilities');

folder = uigetdir();

% i assume the optitrack log is called opti.csv, and the PX4 log is called
% log.csv, but you can easily change this to either a different name, or use
% uigetfile() to select two files
fname1 = [folder '\log.csv'];
fname2 = [folder '\opti.csv'];

% load optitrack truth data from ROS CSV log
[dat2,txt] = xlsread(fname2);
[t,xyz,quat] = ros2body(dat2,txt);
[t,xyz,vb,ab,quat,wb,vn,an] = opti_velocities(t,xyz,quat,0);

% compute euler angles from optitrack
euler = zeros(length(t),3);
for i = 1:length(t)
    X = attparsilent(quat(i,[4 1 2 3])',[6 4],struct('seq',[3 2 1]));
    euler(i,:) = X([3 2 1],1)';% ROLL PITCH THEN YAW
end

% compute body-frame acceleration "truth" from optitrack
abacc = zeros(size(an));
for i = 1:length(t)
    B0 = quat(i,4);
    Bv = quat(i,1:3);
    C = attparsilent([B0 Bv]',[6 1]);%inertial-to-body
    
    anacc = an(i,:)' + [0;0;-9.81];
    abacc(i,:) = (C*anacc)';
end

% load PX4 onboard log
[tv,Acc,Gyro,Mag,LPOS,LPOSV,RC,Att,flow,baro,ekf,ekf_var] = loadPX4(fname1);

% if flow data are rotated relative to the body axes, transform optitrack
% velocities into the flow frame for comparison
Cflow = eye(2);
vb_flow = vb(:,1:2)*Cflow';

%% align time histories
% here, the EKF and optitrack roll histories are aligned
% sonar altitude and optitrack altitude are also good candidates frequently
delta = alignTimeHistoriesPh(t,euler(:,1),tv,ekf(:,4));
t = t + delta;
%% plot data

% interpolate in the Px4 logs (which are lower resolution) for the corresponding Optitrack histories
% use the interpolated histories for computing residuals &c
vb_in = interp1(t,vb,tv);
wb_in = interp1(t,wb,tv);
euler_in = interp1(t,euler,tv);
xyz_in = interp1(t,xyz,tv);

% plot true and EKF estimated velocity
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

% plot EKF velocity residuals
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

% plot true and EKF estimated altitude
figure;
plot(tv,ekf(:,7),'r--');
hold on;
plot(t,xyz(:,3));
ylabel('z (m)');
set(gcf,'position',[150 250 1150 225]);

% altitude residuals
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

% plot attitude truth and estimates
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

% plot attitude residuals
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

% plot yaw rate truth and estimate, and their estimate
figure;
plot(t,wb(:,3));
hold on;
plot(tv,ekf(:,6),'r--','linewidth',2);
plot(tv,Att(:,6),'k--');
legend('truth','byu ekf','px4 ekf');
ylabel('r (rad/s)');
set(gcf,'position',[150 250 1150 225]);

% yaw rate residuals
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

% plot the accelerometer readings and optitrack predicted accelerations.
% optitrack accelerations are noisy and should not in general be assumed to be correct.
figure;
for i = 1:3
    subplot(3,1,i);
    plot(t,abacc(:,i),'b-');
    hold on;
    plot(tv,Acc(:,i),'r--');
    set(gca,'ylim',[-20 20]);
    ylabel(['a_' num2str(i) ' (m/s^2)']);
end

% compute what the EKF would predict the flow reading to be
est_flow = ekf(:,1:2)*Cflow';
% convert the flow readings to the body frame
flow_conv = flow(:,3:4)*Cflow;

% compare the truth, estimated velocity, and flow readings
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