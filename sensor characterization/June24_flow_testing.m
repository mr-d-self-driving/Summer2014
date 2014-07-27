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
folder = 'C:\Users\fatadama\Documents\summer 2014\Optitrack\June 24 optic flow test';

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

%% align time histories

delta = alignTimeHistories(t,-xyz(:,3),tv,flow(:,5),-2.2);
t = t + delta; % better be sure the alignment is good
%% plot data

inshort = find(diff(flow(:,5)) ~= 0);
inshort = [1;inshort];
tshort = tv(inshort);
flowshort = flow(inshort,:);

%plot optic flow
figure;
subplot(211)
plot(tv,flow(:,3),'r--',t,vb_flow(:,1))
hold on;
plot([t(1) t(end)],0.2*[1 1],'k--');
plot([t(1) t(end)],-0.2*[1 1],'k--');
ylabel('v_x flow (m/s)');

subplot(212)
plot(tv,flow(:,4),'r--',t,vb_flow(:,2))
hold on;
plot([t(1) t(end)],0.2*[1 1],'k--');
plot([t(1) t(end)],-0.2*[1 1],'k--');
ylabel('v_y flow (m/s)');

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
tuse = [25.99 65];
    %184.3 189.3];

tind = [];
for i = 1:size(tuse,1)
    tind = [tind;find(tv < tuse(i,2) & tv > tuse(i,1))];
end
tind = sort(unique(tind));

%% check local optic flow residual slopes

% loop over every N data points
% compute the residuals vs measurement linear best fit for optic flow
% plot as a function of time

N = 250;

vb_flow_in = interp1(t,vb_flow,tv);

resid = vb_flow_in(:,1:2) - flow(:,3:4);

slopes = zeros(length(tv)-N,2);
tplot = tv(N:end);
for i = N:length(tv)
    for j = 1:2
        %X = [ones(N,1) flow((i-N+1):i,2+j)];
        X = [ones(N,1) vb_flow_in((i-N+1):i,j)];
        y = resid((i-N+1):i,j);
        [b,~,r,rint] = regress(y,X);
        slopes(i-N+1,j) = b(2);
    end
end

figure;
%subplot(211);
plot(tplot,slopes*r2d);

%% check optic flow residual slope in tind

for i = 1:2
    X = [ones(length(tind),1) vb_flow_in(tind,i)];
    y = resid(tind,i);
    b = regress(y,X);
    fprintf(['Slope of axis ' num2str(i) ' optic flow residuals in tind: %.3g deg\n'],r2d*b(2));
end

tt = find(tv > 15 & flow(:,6) >  min(flow(tind,6)));
for i = 1:2
    X = [ones(length(tt),1) vb_flow_in(tt,i)];
    y = resid(tt,i);
    b = regress(y,X);
    fprintf(['Slope of axis ' num2str(i) ' optic flow residuals overall: %.3g deg\n'],r2d*b(2));
end