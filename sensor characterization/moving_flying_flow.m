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
folder = 'C:\Users\fatadama\Documents\summer 2014\Optitrack\June 13 flying motion';

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

Easy  = round(RC(:,5));

inde = find(Easy==0);
% compute vehicle inertial velocity components
vn_quad = zeros(size(LPOSV));
for i = 1:length(tv)
    C = DCMConverter(1,Att(i,1))*DCMConverter(2,Att(i,2))*DCMConverter(3,Att(i,3));%body-to-inertial
    vn_quad(i,:) = LPOSV(i,:)*C;
end
%compute optitrack euler angle histories
euler = zeros(length(t),3);
for j = 1:length(t)
    B0 = quat(j,4);
    Bv = quat(j,1:3)';
    XX = attpar([B0;Bv],[6 4],struct('seq',[3; 2; 1]));
    euler(j,:) = XX([3 2 1],1)';
    euler(j, euler(j,:) > pi ) = euler(j, euler(j,:) > pi ) - 2*pi;
end
%% compute the flow mean and std

C = [1/sqrt(2)*[1 1;-1 1] [0;0];[0 0 1]];

vb_flow = vb*C';

% align data histories
delta = alignTimeHistories(t,vb_flow(:,1),tv,flow(:,3),-.87);
t = t + delta; % better be sure the alignment is good

tuse = [40 67;
    90 117;
    130 150];

%% plot body-frame velocities from both sources
 
[~,ind] = unique(flow(:,3:4),'rows','first');
ind = sort(ind,'ascend');
flowshort = flow(ind,:);
tshort = tv(ind);

tind = [];
for i = 1:size(tuse,1)
    tind = [tind;find(tshort < tuse(i,2) & tshort > tuse(i,1))];
end
tind = sort(unique(tind));

for i = 1:2
    subplot(2,1,i);
    plot(tshort(tind),flowshort(tind,2+i),'r--x');
    hold on;
    plot(t,vb_flow(:,i));
    title([num2str(i) ' axis velocity m/s']);
end
%% residuals for velocity

vb_flow_in = interp1(t,vb_flow(:,1:2),tshort);

resid = vb_flow_in - flowshort(:,3:4);

fprintf('Mean x and y residuals (m/s): %.2g,%.2g\n',nanmean(resid(tind,:)));
fprintf('Std of x and y residuals (m/s): %.2g,%.2g\n',nanstd(resid(tind,:)));
fprintf('Mean abs x and y velocity measured (m/s): %.2g,%.2g\n',nanmean(abs(vb_flow_in)));

% fit line to residuals versus optitrack accels
for i = 1:2
    X = [ones(length(tind),1) flowshort(tind,2+i)];
    y = resid(tind,i);
    b = regress(y,X);
    fprintf('Slope of residuals axis %i: %f deg\n',i,atand(b(2)));
end
figure;
subplot(211);
histfit(resid(tind,1),50);
title('Optic flow X-velocity residuals');

subplot(212);
histfit(resid(tind,2),50);
title('Optic flow Y-velocity residuals');

%% compute N term moving mean and standard deviations

N = 1000;

movingmu = zeros(length(tshort),2);
movingsig = zeros(length(tshort),2);
for i = 1:length(resid)
    if i < N
        in = (1:N);
    else
        if length(resid) - i < N
            in = length(resid)-N:length(resid);
        else
            in = i + (1:N);
        end
    end
    movingmu(i,:) = mean(resid(in,:));
    movingsig(i,:) = std(resid(in,:));
end

figure;
plot(tshort(tind),movingmu(tind,:));

%% residuals for altitude (altitude should be constant here)

% look at unique values & plot

alt_in = interp1(t,-xyz(:,3),tshort);

residalt = alt_in - flowshort(:,5);

fprintf('Mean z altitude residual (m): %.2g\n',nanmean(residalt(tind)));
fprintf('Std of z altitude residual (m): %.2g\n',nanstd(residalt(tind)));

X = [ones(length(tshort),1) flowshort(:,5)];
y = residalt;
b = regress(y,X);
fprintf('Slope of residuals for altitude: %f deg\n',atand(b(2)));

%% analyze unique altitudes
tcon = [27.15 133.7];

[~,ind] = unique(flow(:,5));
ind = sort(ind);
altflow = flow(ind,5);
talt = tv(ind);

alt_in = interp1(t,-xyz(:,3),talt);

residalt = alt_in - altflow;

taltf = find(talt < tcon(2) & talt > tcon(1));

badalt = find(altflow > 3);
goodalt = setxor(badalt,1:length(altflow));

tinter = intersect(taltf,goodalt);
tbadinter = intersect(taltf,badalt);

fprintf('Mean z altitude residual (m): %.2g\n',nanmean(residalt(tinter)));
fprintf('Std of z altitude residual (m): %.2g\n',nanstd(residalt(tinter)));
fprintf('Fraction of bad samples: %.2g\n',length(tbadinter)/length(tinter));

X = [ones(length(tinter),1) altflow(tinter)];
y = residalt(tinter);
b = regress(y,X);
fprintf('Slope of residuals for altitude: %f deg\n',atand(b(2)));