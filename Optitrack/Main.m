

%% THIS PROGRAM PLOTS THE DATA FROM THE LOG FILE FROM PX4

clc
clear all
close all

addpath('\May 5');

%% READ XLS FILE - vehicle log

filename = 'log.xls';
num = xlsread(filename);

t     = (num(:,1) - num(1,1))/10^6;
Acc   = num(:,2:4);
Gyro  = num(:,5:7);
Mag   = num(:,8:10);
LPOS  = num(:,11:13);
LPOSV = num(:,14:16);
RC    = num(:,23:30);
Att   = num(:,32:40); % roll, pitch, yaw, rollrate, pitchrate, yawrate, rolldoublerate ...

Easy  = round(RC(:,5));

inde = find(Easy==0);

%% CONVERT NED 

for j = 1 : length(inde)
    
    i = inde(j);    
    VBODY(:,i) = (Ex(Att(i,1))*Ey(Att(i,2))*Ez(Att(i,3)))*LPOSV(i,:)';   
    PBODY(:,i) = (Ex(Att(i,1))*Ey(Att(i,2))*Ez(Att(i,3)))*LPOS(i,:)';
end

RC_SCALE_PITCH = 0.6;
RC_SCALE_ROLL  = 0.6;
RCVEL = [RC(:,1)/RC_SCALE_PITCH  RC(:,2)/RC_SCALE_ROLL];

%% OPTITRACK DATA LOGGED THROUGH ROS

filename2 = 'opti.xls';
numo = xlsread(filename2);
to = numo(:,5) + numo(:,6)/10^9 - numo(1,5);
xyz = numo(:,11:13);
quat = numo(:,15:18);%scalar part is last
%butterworth lowpass filter for position histories
[b,a] = butter(1,1.5/50,'low');
xyz_avg = filter(b,a,xyz);
quat_avg = filter(b,a,quat - repmat( quat(1,:), length(quat), 1)) + repmat( quat(1,:), length(quat), 1);
%butterworth lowpass filter for velocity histories
[bv,av] = butter(1,1.0/50.0,'low');
v_n = diff(xyz_avg)./repmat(diff(to),1,3);
v_n_avg = filter(bv,av,v_n);
dq = diff(quat_avg)./repmat(diff(to),1,4);
dq_avg = filter(bv,av,dq);
OPVEL = v_n_avg;

%% PLOT

close all

figure(1)
title('Accelerometer and Gyroscope');
subplot(3,2,1)
plot(t,Acc(:,1),'k','LineWidth',2); xlabel('\bf t'); ylabel('\bf a_x');
subplot(3,2,3)
plot(t,Acc(:,2),'k','LineWidth',2); xlabel('\bf t'); ylabel('\bf a_y');
subplot(3,2,5)
plot(t,Acc(:,3),'k','LineWidth',2); xlabel('\bf t'); ylabel('\bf a_z');
subplot(3,2,2)
plot(t,Gyro(:,1),'k','LineWidth',2); xlabel('\bf t'); ylabel('\bf p');
subplot(3,2,4)
plot(t,Gyro(:,2),'k','LineWidth',2); xlabel('\bf t'); ylabel('\bf q');
subplot(3,2,6)
plot(t,Gyro(:,3),'k','LineWidth',2); xlabel('\bf t'); ylabel('\bf r');

figure(2)
title('Local Position and Velocity');
subplot(3,2,1)
plot(t,LPOS(:,1),'k','LineWidth',2); xlabel('\bf t'); ylabel('\bf x'); hold on;
subplot(3,2,3)
plot(t,LPOS(:,2),'k','LineWidth',2); xlabel('\bf t'); ylabel('\bf y'); hold on;
subplot(3,2,5)
plot(t,LPOS(:,3),'k','LineWidth',2); xlabel('\bf t'); ylabel('\bf z'); hold on;
subplot(3,2,2)
plot(t,LPOSV(:,1),'k','LineWidth',2); xlabel('\bf t'); ylabel('\bf v_x'); hold on;
subplot(3,2,4)
plot(t,LPOSV(:,2),'k','LineWidth',2); xlabel('\bf t'); ylabel('\bf v_y'); hold on;
subplot(3,2,6)
plot(t,LPOSV(:,3),'k','LineWidth',2); xlabel('\bf t'); ylabel('\bf v_z'); hold on;


subplot(3,2,1)
plot(t(inde),LPOS(inde,1),'r','LineWidth',2); xlabel('\bf t'); ylabel('\bf x'); hold on;
subplot(3,2,3)
plot(t(inde),LPOS(inde,2),'r','LineWidth',2); xlabel('\bf t'); ylabel('\bf y'); hold on;
subplot(3,2,5)
plot(t(inde),LPOS(inde,3),'r','LineWidth',2); xlabel('\bf t'); ylabel('\bf z'); hold on;
subplot(3,2,2)
plot(t(inde),LPOSV(inde,1),'r','LineWidth',2); xlabel('\bf t'); ylabel('\bf v_x'); hold on;
subplot(3,2,4)
plot(t(inde),LPOSV(inde,2),'r','LineWidth',2); xlabel('\bf t'); ylabel('\bf v_y'); hold on;
subplot(3,2,6)
plot(t(inde),LPOSV(inde,3),'r','LineWidth',2); xlabel('\bf t'); ylabel('\bf v_z'); hold on;

figure(3)
title('Radio Command');
subplot(3,2,1)
plot(t,RC(:,1),'k','LineWidth',2); xlabel('\bf t'); ylabel('\bf RC Channel 1'); hold on;
subplot(3,2,3)
plot(t,RC(:,2),'k','LineWidth',2); xlabel('\bf t'); ylabel('\bf RC Channel 2'); hold on;
subplot(3,2,5)
plot(t,RC(:,3),'k','LineWidth',2); xlabel('\bf t'); ylabel('\bf RC Channel 3'); hold on;
subplot(3,2,2)
plot(t,RC(:,4),'k','LineWidth',2); xlabel('\bf t'); ylabel('\bf RC Channel 4'); ylim([-1.2 1.2]); hold on;
subplot(3,2,4)
plot(t,RC(:,5),'k','LineWidth',2); xlabel('\bf t'); ylabel('\bf RC Channel 5'); ylim([-1.2 1.2]); hold on;
subplot(3,2,6)
plot(t,RC(:,6),'k','LineWidth',2); xlabel('\bf t'); ylabel('\bf RC Channel 6'); ylim([-1.2 1.2]); hold on;

subplot(3,2,1)
plot(t(inde),RC(inde,1),'r','LineWidth',2); xlabel('\bf t'); ylabel('\bf RC Channel 1'); hold on;
subplot(3,2,3)
plot(t(inde),RC(inde,2),'r','LineWidth',2); xlabel('\bf t'); ylabel('\bf RC Channel 2'); hold on;
subplot(3,2,5)
plot(t(inde),RC(inde,3),'r','LineWidth',2); xlabel('\bf t'); ylabel('\bf RC Channel 3'); hold on;
subplot(3,2,2)
plot(t(inde),RC(inde,4),'r','LineWidth',2); xlabel('\bf t'); ylabel('\bf RC Channel 4'); ylim([-1.2 1.2]); hold on;
subplot(3,2,4)
plot(t(inde),RC(inde,5),'r','LineWidth',2); xlabel('\bf t'); ylabel('\bf RC Channel 5'); ylim([-1.2 1.2]); hold on;
subplot(3,2,6)
plot(t(inde),RC(inde,6),'r','LineWidth',2); xlabel('\bf t'); ylabel('\bf RC Channel 6'); ylim([-1.2 1.2]); hold on;


figure(4)
subplot(2,2,1)
plot(t(inde),RCVEL(inde,1),'k','LineWidth',2); xlabel('\bf t'); ylabel('\bf v_x'); hold on;
subplot(2,2,2)
plot(t(inde),RCVEL(inde,2),'k','LineWidth',2); xlabel('\bf t'); ylabel('\bf v_y'); hold on;
subplot(2,2,1)
plot(t(inde),VBODY(2,inde),'m','LineWidth',2); xlabel('\bf t'); ylabel('\bf v_x'); hold on;
subplot(2,2,2)
plot(t(inde),VBODY(1,inde),'m','LineWidth',2); xlabel('\bf t'); ylabel('\bf v_y'); hold on; legend('\bf RC Command','Vehicle velocity');
subplot(2,2,3)
plot(t(inde),RCVEL(inde,1)'-VBODY(2,inde),'k','LineWidth',2); xlabel('\bf t'); ylabel('\bf Error in x velocity'); hold on;
subplot(2,2,4)
plot(t(inde),RCVEL(inde,2)'-VBODY(1,inde),'k','LineWidth',2); xlabel('\bf t'); ylabel('\bf Error in y velocity'); hold on;


figure(5)
subplot(2,2,1)
plot(to,xyz_avg(:,1),'k','LineWidth',2); xlabel('\bf t'); ylabel('\bf x'); hold on; legend('\bf Opti');
subplot(2,2,2)
plot(to,xyz_avg(:,2),'k','LineWidth',2); xlabel('\bf t'); ylabel('\bf y'); hold on;
subplot(2,2,3)
plot(t,LPOS(:,1),'r','LineWidth',2); xlabel('\bf t'); ylabel('\bf x'); hold on; legend('\bf Flow')
subplot(2,2,4)
plot(t,LPOS(:,2),'r','LineWidth',2); xlabel('\bf t'); ylabel('\bf y'); hold on;

figure
subplot(2,2,1)
plot(to(1:end-1),OPVEL(:,1),'k','LineWidth',2); xlabel('\bf t'); ylabel('\bf v_x'); hold on; legend('\bf Opti'); ylim([-1.5 1]);
subplot(2,2,2)
plot(to(1:end-1),OPVEL(:,2),'k','LineWidth',2); xlabel('\bf t'); ylabel('\bf v_y'); hold on; ylim([-1.5 1]);
subplot(2,2,3)
plot(t,LPOSV(:,1),'r','LineWidth',2); xlabel('\bf t'); ylabel('\bf v_x'); hold on; legend('\bf Flow');
subplot(2,2,4)
plot(t,-LPOSV(:,2),'r','LineWidth',2); xlabel('\bf t'); ylabel('\bf v_y'); hold on;
%% generate plots for demo
% needs a user-generated initial guess
addpath('..');
delta = alignTimeHistories(to(1:end-1),OPVEL(:,1),t(inde),VBODY(2,inde)',-5.26);

figure;
subplot(211);
plot(to(1:end-1) + delta,OPVEL(:,1),'-',t(inde),VBODY(2,inde)','r--',t(inde),RCVEL(inde,1),'k','linewidth',2);
title('Inertial x-y velocities','fontsize',14);
ylabel('v_x (m/s) [inertial]','fontsize',12);
legend('Optitrack','Optic flow','RC command','location','southeast');
subplot(212);
plot(to(1:end-1) + delta,OPVEL(:,2),'-',t(inde),VBODY(1,inde)','r--',t(inde),RCVEL(inde,2),'k','linewidth',2);
ylabel('v_y (m/s) [inertial]','fontsize',12);
xlabel('t (sec)','fontsize',12);
legend('Optitrack','Optic flow','RC command','location','southeast');

% subplot(222);
% plot(to + delta,xyz_avg(:,1),'-',t(inde),PBODY(2,inde)','r--','linewidth',2);
% title('Inertial x-y position','fontsize',14);
% ylabel('x (m) [inertial]','fontsize',12);
% subplot(224);
% plot(to + delta,xyz_avg(:,2),'-',t(inde),PBODY(1,inde)','r--','linewidth',2);
% ylabel('y (m) [inertial]','fontsize',12);
% xlabel('t (sec)','fontsize',12);

set(gcf,'position',[126 233 849 575]);
%% generate video for demo

figure('Renderer','zbuffer')
set(gca,'NextPlot','replaceChildren');
clear F writerObj;

t1 = 10 - delta;%start time for optitrack
tz = 45 - delta;%end time for optitrack

xl = [min(xyz_avg(:,1)) max(xyz_avg(:,1))];
yl = [min(xyz_avg(:,2)) max(xyz_avg(:,2))];
zl = [min(xyz_avg(:,3)) max(xyz_avg(:,3))];

writerObj = VideoWriter('test.avi');
writerObj.FrameRate = 100;
open(writerObj);

ii = find(to > t1 & to < tz);
ti = to(ii);

%F(length(ti)-1) = struct('cdata',[],'colormap',[]);
for i = 2:length(ti)
    %plot inertial position
    subplot(2,3,[1 2 4 5]);
    plot3(xyz_avg(ii(1):ii(i),1),xyz_avg(ii(1):ii(i),2),xyz_avg(ii(1):ii(i),3),'-','linewidth',2);
    hold on;
    plot3(xl,[yl(1) yl(1)],[zl(1) zl(1)],'k-');
    plot3(xl,[yl(2) yl(2)],[zl(1) zl(1)],'k-');
    plot3(xl,[yl(2) yl(2)],[zl(2) zl(2)],'k-');
    plot3(xl,[yl(1) yl(1)],[zl(2) zl(2)],'k-');
    
    plot3([xl(2) xl(2)],yl,[zl(1) zl(1)],'k-');
    plot3([xl(1) xl(1)],yl,[zl(1) zl(1)],'k-');
    plot3([xl(2) xl(2)],yl,[zl(2) zl(2)],'k-');
    plot3([xl(1) xl(1)],yl,[zl(2) zl(2)],'k-');
    
    plot3([xl(1) xl(1)],[yl(1) yl(1)],zl,'k-');
    plot3([xl(2) xl(2)],[yl(1) yl(1)],zl,'k-');
    plot3([xl(1) xl(1)],[yl(2) yl(2)],zl,'k-');
    plot3([xl(2) xl(2)],[yl(2) yl(2)],zl,'k-');
    
    axis equal;
    set(gca,'xlim',xl,'ylim',yl,'zlim',zl,'view',[322.5 30]);
    xlabel('X');
    ylabel('Y');
    zlabel('Z');
    set(gca,'NextPlot','replaceChildren');
    hold off;
    
    %plot velocity histories
    subplot(2,3,3);
    plot(ti(1:i) + delta,OPVEL(ii(1:i),1),'-','linewidth',2);%t(inde),VBODY(2,inde)','r--',t(inde),RCVEL(inde,1),'k','linewidth',2);
    title('Inertial x-y velocities','fontsize',14);
    ylabel('v_x (m/s) [inertial]','fontsize',12);
    set(gca,'NextPlot','replaceChildren');
    set(gca,'xlim',[ti(1) ti(end)]+delta,'ylim',[min(OPVEL(:,1)) max(OPVEL(:,1))]);
    
    subplot(2,3,6);
    plot(ti(1:i) + delta,OPVEL(ii(1:i),2),'-','linewidth',2);
    xlabel('t (sec)','fontsize',12);
    ylabel('v_x (m/s) [inertial]','fontsize',12);
    set(gca,'NextPlot','replaceChildren');
    set(gca,'xlim',[ti(1) ti(end)]+delta,'ylim',[min(OPVEL(:,2)) max(OPVEL(:,2))]);
    
    frame = getframe(gcf);
    writeVideo(writerObj,frame);
    if ~mod(i,25)
        clc;
        disp(['Frame ' num2str(i) ' of ' num2str(length(ti))]);
    end
end
close(writerObj);