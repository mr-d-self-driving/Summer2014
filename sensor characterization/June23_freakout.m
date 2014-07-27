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
folder = 'C:\Users\fatadama\Documents\summer 2014\Optitrack\June 23 test 3';

fname1 = [folder '\log.csv'];
fname2 = [folder '\opti.csv'];

[dat2,txt] = xlsread(fname2);
[t,xyz,quat] = ros2body(dat2,txt);

%get the ROS frame time, position, attitudes
tind = find(strcmp(txt(1,:),'Timestamp'));
t = data(:,tind) + dat2(:,tind+1)/10^9 - dat2(1,tind);%time

xyzind = find(strcmp(txt(1,:),'Opti Pos X'));
xyzros = dat2(:,xyzind+(0:2));

quatind = find(strcmp(txt(1,:),'Opti Roll'));
optieuler = dat2(:,quatind+(0:2));

for i = 1:length(optieuler)
    gar = attpar(optieuler(i,[3 2 1])',[6 4],struct('seq',[3 2 1]'));
    quat(:,i) = gar([2 3 4 1])';
end

%ROS BODY 2 REAL BODY DCM: 
R1_pi = [1,0,0;
   0,-1,0;
   0,0,-1];

%north-east-down inertial frame position components
xyz = [xyzros(:,1) -xyzros(:,2) -xyzros(:,3)];

%inertial frame 
quat = zeros(size(quatros));
for i = 1:length(t)
    B0 = quatros(i,4);
    Bv = quatros(i,1:3);
    Cros2fakebody = attparsilent([B0 Bv]',[6 1]);
    C = R1_pi*Cros2fakebody*R1_pi';
    X = attpar(C,[1 6]);
    quat(i,4) = X(1,1);
    quat(i,1:3) = X(2:4,1);
end

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

%% align time histories

delta = alignTimeHistories(t,-xyz(:,3),tv,flow(:,5),-1.05);
t = t + delta; % better be sure the alignment is good
%% plot data

inshort = find(diff(flow(:,5)) ~= 0);
inshort = [1;inshort];
tshort = tv(inshort);
flowshort = flow(inshort,:);

figure;
plot(tshort,flowshort(:,5),'k-x',tv,baro-nanmean(baro(71:197)),'m--',tv,-LPOS(:,3)+LPOS(1,3),'r--');
hold on;
plot(t,-xyz(:,3));
legend('sonic','baro','LPOS','opti');


figure;
plot(tv,Acc(:,3),'r--');
hold on;
plot(t,abacc(:,3),'b-');

%plot body-axis velocities
figure;
plot(tv,LPOSV(:,3),'r--');
hold on;
plot(t,vb(:,3),'b-');
ylabel('v_3 (m/s)');
legend('LPOSV','Optitrack');

% check attitutde
%% times to use data from
tuse = [44.4 55;
    64.2 80.0];

%% plot body-frame velocities from both sources
 
%[~,ind] = unique(flow(:,3:4),'rows','first');
%ind = sort(ind,'ascend');
%flowshort = flow(ind,:);
%tshort = tv(ind);

tind = [];
for i = 1:size(tuse,1)
    tind = [tind;find(tv < tuse(i,2) & tv > tuse(i,1))];
end
tind = sort(unique(tind));

figure;
for i = 1:2
    subplot(2,1,i);
    plot(tv(tind),flow(tind,2+i),'r--x');
    hold on;
    plot(t,vb_flow(:,i));
    title([num2str(i) ' axis velocity m/s']);
end

%% plot slope vs time shift for velocity data as a check

tshift = -10:.1:10;

tmat = repmat(t,1,length(tshift)) + repmat(tshift,length(t),1);

residx = zeros(length(tv),length(tmat));
residy = zeros(length(tv),length(tmat));
slopex = zeros(length(tshift),1);
slopey = zeros(length(tshift),1);
for i = 1:length(tshift)
    vb_interer = interp1(tmat(:,i),vb_flow(:,1:2),tv);
    
    residx(:,i) = vb_interer(:,1) - flow(:,3);
    residy(:,i) = vb_interer(:,2) - flow(:,4);
    
    X = [ones(length(tv),1) flow(:,3)];
    y = residx(:,i);
    b = regress(y,X);
    slopex(i) = b(2);
    
    X = [ones(length(tv),1) flow(:,4)];
    y = residy(:,i);
    b = regress(y,X);
    slopey(i) = b(2);
end
figure;
subplot(211);
plot(tshift,atand(slopex))

subplot(212);
plot(tshift,atand(slopey));

%% ang vel residuals

wb_in = interp1(t,wb,tv);
residgyro = wb_in - Att(:,4:6);

fprintf('Mean x and y residuals (m/s): %.2g,%.2g,%.2g\n',nanmean(residgyro(tind,:)));
fprintf('Std of x and y residuals (m/s): %.2g,%.2g,%.2g\n',nanstd(residgyro(tind,:)));

% fit line to residuals versus optitrack accels
for i = 1:3
    X = [ones(length(tind),1) Att(tind,3+i)];
    y = residgyro(tind,i);
    b = regress(y,X);
    fprintf('Slope of gyro residuals axis %i: %f deg\n',i,atand(b(2)));
end
figure;
subplot(311);
histfit(residgyro(tind,1),50);
title('Gyroscope X-velocity residuals');

subplot(312);
histfit(residgyro(tind,2),50);
title('Gyroscope Y-velocity residuals');

subplot(313);
histfit(residgyro(tind,3),50);
title('Gyroscope Z-velocity residuals');

%% Accelerometer

ab_in = interp1(t,abacc,tv);
residacc = ab_in - Acc;

fprintf('Mean x and y residuals (m/s): %.2g,%.2g,%.2g\n',nanmean(residacc(tind,:)));
fprintf('Std of x and y residuals (m/s): %.2g,%.2g,%.2g\n',nanstd(residacc(tind,:)));

% fit line to residuals versus optitrack accels
for i = 1:3
    X = [ones(length(tind),1) Acc(tind,i)];
    y = residacc(tind,i);
    b = regress(y,X);
    fprintf('Slope of acc residuals axis %i: %f deg\n',i,atand(b(2)));
end
figure;
subplot(311);
histfit(residacc(tind,1),50);
title('Accelerometer X-velocity residuals');

subplot(312);
histfit(residacc(tind,2),50);
title('Accelerometer Y-velocity residuals');

subplot(313);
histfit(residacc(tind,3),50);
title('Accelerometer Z-velocity residuals');

%% residuals for velocity

vb_flow_in = interp1(t,vb_flow(:,1:2),tv);
xyz_in = interp1(t,xyz,tv);

resid = vb_flow_in - flow(:,3:4);

fprintf('Mean x and y residuals (m/s): %.2g,%.2g\n',nanmean(resid(tind,:)));
fprintf('Std of x and y residuals (m/s): %.2g,%.2g\n',nanstd(resid(tind,:)));
fprintf('Mean abs x and y velocity optitrack (m/s): %.2g,%.2g\n',mean(abs(vb_flow_in(tind,1:2))));
fprintf('Mean alt (m): %.2g\n',mean(-xyz_in(tind,3)));

% fit line to residuals versus optitrack accels
for i = 1:2
    X = [ones(length(tind),1) flow(tind,2+i)];
    y = resid(tind,i);
    b = regress(y,X);
    fprintf('Slope of residuals axis %i: %f deg\n',i,atand(b(2)));
end
figure;
subplot(211);
histfit(resid(:,1),50);
title('Optic flow X-velocity residuals');

subplot(212);
histfit(resid(:,2),50);
title('Optic flow Y-velocity residuals');