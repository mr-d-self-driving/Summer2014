%% Jul3_flight1
% get optitrack data, flew back and forth some

clear variables;
close all;

addpath('..');
addpath('../Optitrack');
addpath('../near system identification');

%get the folder the data are in:
%folder = uigetdir();
%debugging, use the dynamic flight data
folder = 'C:\Users\fatadama\Documents\summer 2014\Optitrack\July 3 3DR drag char';

fname1 = [folder '\log.csv'];
fname2 = [folder '\opti.csv'];

[dat2,txt] = xlsread(fname2);
[t,xyz,quat] = ros2body(dat2,txt);
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
    C = attpar([B0 Bv]',[6 1]);%inertial-to-body
    
    anacc = an(i,:)' + [0;0;-9.81];
    abacc(i,:) = (C*anacc)';
end

%% vehicle histories:
[num,txt] = xlsread(fname1);
labels = txt(1,:);

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

Easy  = round(RC(:,5));

inde = find(Easy==0);
% compute vehicle inertial velocity components
vn_quad = zeros(size(LPOSV));
for i = 1:length(tv)
    C = DCMConverter(1,Att(i,1))*DCMConverter(2,Att(i,2))*DCMConverter(3,Att(i,3));%body-to-inertial
    vn_quad(i,:) = LPOSV(i,:)*C;
end

%% align time histories

delta = alignTimeHistories(t,euler(:,1),tv,Att(:,1),-2.57);
t = t + delta; % better be sure the alignment is good

%% plot data
%tuse = [38.17 61.52;
%    87.05 113.9;
%    121.6 150.4;
%    157.5 185.4;
%    205.7 233.2;
%    242.4 270.6];
tuse = [38.17 55.4;
    102.5 113.9;
    223.9 233.2;
    250.3 262.9];

tind = [];
for i = 1:size(tuse,1)
    tind2 = find(t < tuse(i,2) & t > tuse(i,1));
    tind = [tind;tind2];
end
tind = unique(tind);

figure
for i = 1:3
    subplot(3,1,i);
    plot(t(tind),xyz(tind,i),'-');
    ylabel([num2str(i) ' axis inertial position (m)']);
end

figure
for i = 1:3
    subplot(3,1,i);
    plot(t(tind),vb(tind,i));
    ylabel([num2str(i) ' body axis velocity (m/s)']);
    grid on;
end

figure
for i = 1:3
    subplot(3,1,i);
    plot(t(tind),abacc(tind,i));
    hold on;
    plot(tv,Acc(:,i),'r--');
    set(gca,'ylim',[-5 5]);
    if i == 3
        set(gca,'ylim',[-20 0]);
    end
    ylabel([num2str(i) ' body axis acceleration (m/s^2)']);
end

figure;
for i = 1:3
    subplot(3,1,i);
    %plot(t(tind),quat(tind,i+1));
    plot(t(tind),euler(tind,i)*r2d);
    hold on;
    plot(tv,Att(:,i)*r2d,'r--');
    switch i 
        case 1 
            ylabel('\phi (deg)');
        case 2
            ylabel('\theta (deg)');
        case 3
            ylabel('\psi (deg)');
    end
end

%% approximate the derivative at all points

%assume a fixed sample period of .01 sec
ts = .01;

h = 2*ts;

vbdot = zeros(length(t),3);
vbdot(1,:) = (vb(2,:)-vb(1,:))/ts;
vbdot(end,:) = (vb(end,:)-vb(end-1,:))/ts;
for i = 2:length(t)-1
    vbdot(i,:) = (vb(i+1,:)-vb(i-1,:))/h;
    %ceiling the values to reject outliers
    if any(abs(vbdot(i,:)) > 5)
        vbdot(i,:) = vbdot(i-1,:);
    end
end

figure;
for i = 1:3
    subplot(3,1,i);
    hold on;
    plot(t(tind),vbdot(tind,i),'r-');
end

%% compute a best-fit for the data

g = 9.81;

% use the optitrack data
lhs = -vbdot + [-g*sin(euler(:,2)) g*sin(euler(:,1)).*cos(euler(:,2)) g*cos(euler(:,1)).*cos(euler(:,2))] + ...
    [vb(:,2).*wb(:,3)-vb(:,3).*wb(:,2) vb(:,3).*wb(:,1)-vb(:,1).*wb(:,3) vb(:,1).*wb(:,2)-vb(:,2).*wb(:,1)] + ...
    zeros(length(t),3);%the thrust term should go here, but we don't measure it or need it
x = fit_mdl(lhs(tind,1:2),vb(tind,1:2));
n3b = [-sin(euler(:,2)) sin(euler(:,1)).*cos(euler(:,2)) cos(euler(:,1)).*cos(euler(:,2))];
lhs2 = abacc;% - g*n3b;
x2 = fit_mdl(lhs2(tind,1:2),-vb(tind,1:2));

% use the accelerometer
vb_in = interp1(t,vb,tv);
tind2 = [];
for i = 1:size(tuse,1)
    tind2 = [tind2; find(tv < tuse(i,2) & tv > tuse(i,1))];
end
tind2 = unique(tind2);
acclhs = Acc;
accx = fit_mdl(acclhs(tind2,1:2),-vb_in(tind2,1:2));
accx2 = fit_mdl(acclhs(tind2,1:2),LPOSV(tind2,1:2));% use LPOSV instead of optitrack

% plot the fit
testrhs =  [-g*sin(euler(:,2)) g*sin(euler(:,1)).*cos(euler(:,2))] + ...
    [vb(:,2).*wb(:,3)-vb(:,3).*wb(:,2) vb(:,3).*wb(:,1)-vb(:,1).*wb(:,3)] - ...
    [vb(:,1) vb(:,2)]*x;
testlhs = vbdot(:,1:2);
theircon = [-g*sin(euler(:,2)) g*sin(euler(:,1)).*cos(euler(:,2))] + ...
    [vb(:,2).*wb(:,3)-vb(:,3).*wb(:,2) vb(:,3).*wb(:,1)-vb(:,1).*wb(:,3)];

figure;
for i = 1:2
    subplot(2,1,i);
    plot(t(tind),testlhs(tind,i),'b-');
    hold on
    plot(t(tind),testrhs(tind,i),'r--');
    plot(t(tind),theircon(tind,i),'m--');
    
    legend('differenced velocity time rates','predicted velocity time rates','prediction with zero drag');
end

acctestrhs = -[vb_in(:,1) vb_in(:,2)]*accx;
    %[LPOSV(:,1) LPOSV(:,2)]*accx;
acctestrhs2 = LPOSV(:,1:2)*accx2;
acctestlhs = Acc(:,1:2);
acctheircon = 0*Acc(:,1:2);

figure;
for i = 1:2
    subplot(2,1,i);
    plot(tv(tind2),acctestlhs(tind2,i),'b-');
    hold on;
    plot(tv(tind2),acctestrhs(tind2,i),'r--');
    plot(tv(tind2),acctestrhs2(tind2,i),'m--');
    %plot(tv(tind2),acctheircon(tind2,i),'m--');
    legend('Acc reading','model prediction','model prediction 2');
end

mse = sum(( testlhs(tind,:)-testrhs(tind,:)).^2)/length(tind)
mse_their = sum(( testlhs(tind,:)-theircon(tind,:)).^2)/length(tind)
accmse = sum(( acctestrhs(tind2,1:2)-acctestlhs(tind2,1:2)).^2)/length(tind2)
accmse_their = sum(( acctheircon(tind2,1:2)-acctestlhs(tind2,1:2)).^2)/length(tind2)

%% compute best-fits to each segment

opti_diff = zeros(size(tuse,1),1);
opti_acc = zeros(size(tuse,1),1);
acc_est = zeros(size(tuse,1),2);
for i = 1:size(tuse,1)
    ti = find(t > tuse(i,1) & t < tuse(i,2));
    ti2 = find(tv > tuse(i,1) & tv < tuse(i,2));
    
    lhs = -vbdot + [-g*sin(euler(:,2)) g*sin(euler(:,1)).*cos(euler(:,2)) g*cos(euler(:,1)).*cos(euler(:,2))] + ...
        [vb(:,2).*wb(:,3)-vb(:,3).*wb(:,2) vb(:,3).*wb(:,1)-vb(:,1).*wb(:,3) vb(:,1).*wb(:,2)-vb(:,2).*wb(:,1)] + ...
        zeros(length(t),3);%the thrust term should go here, but we don't measure it or need it
    lhs2 = abacc;% - g*n3b;
    x = fit_mdl(lhs(ti,1:2),vb(ti,1:2));
    x2 = fit_mdl(lhs2(ti,1:2),-vb(ti,1:2));
    
    acclhs = Acc;
    accx = fit_mdl(acclhs(ti2,1:2),-vb_in(ti2,1:2));
    accx2 = fit_mdl(acclhs(ti2,1:2),LPOSV(ti2,1:2)); % use LPOSV instead of optitrack
    
    opti_diff(i) = x;
    opti_acc(i) = x2;
    acc_est(i,1) = accx;
    acc_est(i,2) = accx2;
end