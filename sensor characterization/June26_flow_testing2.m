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
folder = 'C:\Users\fatadama\Documents\summer 2014\Optitrack\June 26 optic flow test 2';

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
    XX = attparsilent([B0;Bv],[6 4],struct('seq',[3; 2; 1]));
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

delta = alignTimeHistories(t,-xyz(:,3),tv,flow(:,5),9.92);
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

%plot 3-axis acceleration
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
figure;
for i = 1:3
    subplot(3,1,i);
    plot(t,euler(:,i)*r2d);
    hold on;
    plot(tv,Att(:,i)*r2d,'r--');
    ylabel(['Body ' num2str(i) ' axis euler angle']);
end
%% times to use data from
tuse = [56.98 115.8;
    148.6 203];

tind = [];
for i = 1:size(tuse,1)
    tind = [tind;find(tv < tuse(i,2) & tv > tuse(i,1))];
end
tind = sort(unique(tind));

%% check local optic flow residual slopes

% loop over every N data points
% compute the residuals vs measurement linear best fit for optic flow
% plot as a function of time

N = 500;

vb_flow_in = interp1(t,vb_flow,tv);
xyz_in = interp1(t,xyz,tv);

resid = vb_flow_in(:,1:2) - flow(:,3:4);

slopes = zeros(length(tind)-N,2);
tplot = tv(tind(N:end));
for i = N:length(tind)
    for j = 1:2
        %X = [ones(N,1) flow((i-N+1):i,2+j)];
        X = [ones(N,1) vb_flow_in((i-N+1):i,j)];
        y = resid((i-N+1):i,j);
        [b,~,r,rint] = regress(y,X);
        slopes(i-N+1,j) = b(2);
    end
end

figure;
subplot(211);
plot(tplot,slopes*r2d);
subplot(212);
plot(slopes*r2d,-xyz_in(tind(N:end),3),'x');
ylabel('alt');
xlabel('slope');

%% plot residuals(t)

residsmooth = filter(.05*ones(20,1),1,resid);

figure;
subplot(211);
plot(tv,resid(:,1),'r-');
hold on;
plot(tv,residsmooth(:,1),'b--');

subplot(212);
plot(tv,resid(:,2),'r-');
hold on;
plot(tv,residsmooth(:,2),'b--');

%% check optic flow residual slope in tind
FID = fopen('june26_test2.txt','wt');

for i = 1:2
    X = [ones(length(tind),1) vb_flow_in(tind,i)];
    y = resid(tind,i);
    b = regress(y,X);
    fprintf(FID,['Slope of axis ' num2str(i) ' optic flow residuals in tind: %.3g deg\n'],r2d*b(2));
end
fprintf(FID,'Mean residuals in tind: %.2g,%.2g m/s\n',mean(resid(tind,1:2)));
fprintf(FID,'Std of residuals in tind: %.2g,%.2g m/s\n',std(resid(tind,1:2)));
fprintf(FID,'Mean abs flow-plane velocity in tind: %.2g,%.2g m/s\n',mean(abs(vb_flow_in(tind,1:2))));
fprintf(FID,'Mean altitude in tind: %.2g m\n',mean(-xyz_in(tind,3)));
fprintf(FID,'Minimum flow quality in tind: %i\n',min(flow(tind,6)));

tt = find(tv > 6 & flow(:,6) >  215);
for i = 1:2
    X = [ones(length(tt),1) vb_flow_in(tt,i)];
    y = resid(tt,i);
    b = regress(y,X);
    fprintf(FID,['Slope of axis ' num2str(i) ' optic flow residuals overall w/ good flow Q: %.3g deg\n'],r2d*b(2));
end
fprintf(FID,'Mean residuals overall: %.2g,%.2g m/s\n',mean(resid(tt,1:2)));
fprintf(FID,'Std of residuals overall: %.2g,%.2g m/s\n',std(resid(tt,1:2)));
fprintf(FID,'Mean abs flow velocity overall: %.2g,%.2g m/s\n',mean(abs(vb_flow_in(tt,1:2))));
fprintf(FID,'Mean altitude overall: %.2g m\n',mean(-xyz_in(tt,3)));

fclose(FID);
%% plot residual vs alt

% there seems to be a definite dependence on altitude

figure;
subplot(211);
plot(resid(:,1),-xyz_in(:,3),'d');
hold on;
plot(resid(tind,1),-xyz_in(tind,3),'rx');
if exist('hypo','var');
     plot(3*hypo,alts,'k-','linewidth',2)
    plot(-3*hypo,alts,'k-','linewidth',2)
end
ylabel('altitude (m)');
xlabel('x-axis velocity residuals (m/s)');

subplot(212);
plot(resid(:,2),-xyz_in(:,3),'d');
hold on
plot(resid(tind,2),-xyz_in(tind,3),'rx');
if exist('hypo','var');
     plot(3*hypo,alts,'k-','linewidth',2)
    plot(-3*hypo,alts,'k-','linewidth',2)
end
ylabel('altitude (m)');
xlabel('y-axis velocity residuals (m/s)');

legend('all residuals','residuals in low error regions');

set(gcf,'position',[275 300 1025 678]);

%% try to characterize residual standard error as a function of altitude

discr = 0.125;

alts = 0:discr:2.7501;

xyz_round = round(xyz_in/discr)*discr;

stds = zeros(length(alts),2);
hypo = zeros(length(alts),1);
for i = 1:length(alts)
    altind = find(-xyz_round(:,3) == alts(i));
    stds(i,:) = std(resid(altind,1:2));
    if alts(i) <= 0.5
        hypo(i) = 0.4;
    else if alts(i) <= 1.75
            hypo(i) = .6800*(alts(i)-0.5) + 0.4;
        else if alts(i) > 1.75
                hypo(i) = 1.25;
            end
        end
    end
end

figure;
plot(alts,stds(:,1));
hold on;
plot(alts,stds(:,2),'r--');
plot(alts,hypo,'k-','linewidth',2);
xlabel('alt (m)');
ylabel('std(v_i) (m/s)');

% current hypothesis: std = 0.4 z <= 0.5
%   std = .68(z-0.5) + 0.4, 0.5 < z <= 1.75
%   std = 1.25, 1.75 < z

%% plot residuals versus inertial velocity

ttin = cell(2,1);
ttin2 = cell(2,1);
for i = 1:2
    %find where the velocity is less than 1 m/s per meter of altitude
    ttin{i} = find( vb_flow_in(:,i) < 1*-xyz_in(:,3) );
    ttin2{i} = find( abs(vb_flow_in(tind,i)) < 1 );
    
    X = [ones(length(tind),1) vb_flow_in(tind,i)];
    y = resid(tind,i);
    b = regress(y,X);
    fprintf(['Slope of axis ' num2str(i) ' optic flow residuals in tind: %.3g deg\n'],r2d*b(2));
    
    X = [ones(length(ttin2{i}),1) vb_flow_in(tind(ttin2{i}),i)];
    y = resid(tind(ttin2{i}),i);
    b = regress(y,X);
    fprintf(['Slope of axis ' num2str(i) ' ttin2 optic flow residuals in tind: %.3g deg\n'],r2d*b(2));
end

figure;
subplot(211);
plot(resid(ttin{1},1),-vb_flow_in(ttin{1},1),'ks');
hold on;
plot(resid(:,1),-vb_flow_in(:,1),'d');
plot(resid(tind,1),-vb_flow_in(tind,1),'rx');
plot(resid(tind(ttin2{1}),1),-vb_flow_in(tind(ttin2{1}),1),'g.');
if exist('hypo','var');
     %plot(3*hypo,alts,'k-','linewidth',2)
     %plot(-3*hypo,alts,'k-','linewidth',2)
end
ylabel('x-axis optitrack velocity (m)');
xlabel('x-axis velocity residuals (m/s)');
axis equal

subplot(212);
plot(resid(ttin{2},2),-vb_flow_in(ttin{2},2),'ks');
hold on;
plot(resid(:,2),-vb_flow_in(:,2),'d');
plot(resid(tind,2),-vb_flow_in(tind,2),'rx');
plot(resid(tind(ttin2{2}),2),-vb_flow_in(tind(ttin2{2}),2),'g.');
if exist('hypo','var');
     %plot(3*hypo,alts,'k-','linewidth',2)
     %plot(-3*hypo,alts,'k-','linewidth',2)
end
ylabel('y-axis optitrack velocity (m)');
xlabel('y-axis velocity residuals (m/s)');
axis equal

legend('velocity < threshold','all residuals','residuals in low error regions','vel < 1 m/s residuals');

set(gcf,'position',[275 300 1025 678]);