%% flow_angle_char
% get flow sensor data from sensor moving, motors off

clear variables;
close all;

addpath('..');
addpath('../Optitrack');
addpath('../near system identification');

%get the folder the data are in:
%folder = uigetdir();
%debugging, use the dynamic flight data
folder = 'C:\Users\fatadama\Documents\summer 2014\Optitrack\June 19 flow angle test';

fname1 = [folder '\log.csv'];
fname2 = [folder '\opti.csv'];

[dat2,txt] = xlsread(fname2);
[t,xyz,quat] = ros2body(dat2,txt);
[t,xyz,vb,ab,quat,wb,vn,an] = opti_velocities(t,xyz,quat,0);

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

%% convert optitrack to the flow frame
C = [1/sqrt(2)*[1 1;-1 1] [0;0];[0 0 1]];

vb_flow = vb*C';

% -5.01 for Black
plot(t,-xyz(:,3),tv,flow(:,5),'r--',tv,baro-baro(1),'m--');
%% align time histories

% set nans in flow to -1
flow(find(isnan(flow(:,5))),:) = -1;

delta = alignTimeHistories(t,-xyz(:,3),tv,flow(:,5),-5.91);
t = t + delta; % better be sure the alignment is good
%% plot the sonic altitude return and plot pitch and bank angles
close all;

inshort = find(diff(flow(:,5)) ~= 0);
inshort = [1;inshort];
tshort = tv(inshort);
flowshort = flow(inshort,:);

figure;
subplot(311);
plot(t,-xyz(:,3),tshort,flowshort(:,5),'r--x',tv,baro-baro(1),'m--')
ylabel('altitude (m)');
legend('Optitrack','Flow sensor','Local position 3 component');

subplot(312);
plot(t,euler(:,1)*r2d,tv,Att(:,1)*r2d,'r--');
ylabel('\phi (deg)');

subplot(313);
plot(t,euler(:,2)*r2d,tv,Att(:,2)*r2d,'r--');
ylabel('\theta (deg)');

figure;

plot(tshort,flowshort(:,5),'r--x');
hold on;
plot(t,max(abs(euler(:,1:2)),[],2)*r2d,'b-')

%% plot unique sonic returns vs. maximum of pitch or roll angles
% max sensitivity angle for sonic is 20 deg

tacq = [12.08;16.08;19.88;25.68;28.07;32.49;40.78;48.47];
inacq = zeros(size(tacq));
inacq2 = zeros(size(tacq));
for i = 1:length(tacq)
    [~,inacq(i)] = min(abs(tshort - tacq(i)));
    [~,inacq2(i)] = min(abs(t - tacq(i)));
end

fprintf('%22s %22s %22s %22s\n','Roll (onboard,deg)','Pitch(onboard,deg)','Roll (opti,deg)','Pitch(opti,deg)');
fprintf('%22.4g %22.4g %22.4g %22.4g\n',[Att(inshort(inacq),1:2)*r2d euler(inacq2,1:2)*r2d]');