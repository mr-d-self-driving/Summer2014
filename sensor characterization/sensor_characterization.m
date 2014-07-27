%% sensor_characterization.m
% open the "truth" data and the flight data to extract noise and bias
% parameters

clear variables;
close all;

addpath('../Optitrack');
addpath('../near system identification');

%get the folder the data are in:
%folder = uigetdir();
%debugging, use the dynamic flight data
folder = 'C:\Users\fatadama\Documents\summer 2014\Optitrack\June 12';

fname1 = [folder '\log.csv'];
fname2 = [folder '\opti.csv'];

[dat2,txt] = xlsread(fname2);
[t,xyz,quat] = ros2body(dat2,txt);
[t,xyz,vb,ab,quat,wb,vn,an] = opti_velocities(t,xyz,quat,0);

%% read onboard log
% note when there are gaps in the optitrack time history
Tthres = 2.00;%maximum tolerated multiplicative error on the assumed 100Hz sample rate; otherwise we flag a loss
terrs = find(diff(t) > Tthres*.01);

%load vehicle data
[num,txt] = xlsread(fname1);
labels = txt(1,:);

%vehicle histories:
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
%% compute body-axis acceleration from optitrack, and add -gn_3 offset to compare against acc:

% align data histories
addpath('..');
delta = alignTimeHistories(t,euler(:,1),tv,Att(:,1),0.0);
t = t + delta; % better be sure the alignment is good
%delta = alignTimeHistories(t,vb(1:end-1,1),tv,LPOSV(:,2),-3.47);

figure;
subplot(311);
plot(t,vb(:,1),'-',tv,LPOSV(:,1),'r--');
title('Body-axis velocities');

subplot(312);
plot(t,vb(:,2),'-',tv,LPOSV(:,2),'r--');

subplot(313);
plot(t,vb(:,3),'-',tv,LPOSV(:,3),'r--');

figure;
subplot(311);
plot(t,euler(:,1)*r2d,'-',tv,r2d*Att(:,1),'r--');
hold on;
plot(t(terrs),euler(terrs,1)*r2d,'kx','linewidth',2);
ylabel('\phi (deg)');

subplot(312);
plot(t,r2d*euler(:,2),'-',tv,r2d*Att(:,2),'r--');
hold on;
plot(t(terrs),euler(terrs,2)*r2d,'kx','linewidth',2);
ylabel('\theta (deg)');

subplot(313);
plot(t,r2d*euler(:,3),'-',tv,r2d*Att(:,3),'r--');
ylabel('\psi (deg)');

% compute body-frame acceleration "truth"
abacc = zeros(size(an));
for i = 1:length(t)
    B0 = quat(i,4);
    Bv = quat(i,1:3);
    C = attpar([B0 Bv]',[6 1]);%inertial-to-body
    
    anacc = an(i,:)' + [0;0;-9.81];
    abacc(i,:) = (C*anacc)';
end
%% ignore times with bad optitrack data

t_ig = [0 75;
    103 109;
    138 148];

%% plot body and inertial accelerations

% slope indicates BIAS!!

Accsmooth = filter(1/15*ones(15,1),1,Acc);

figure
for i = 1:3
    if i < 3
        subplot(4,1,i);
    else
        subplot(4,1,[3 4]);
    end
    plot(tv,Acc(:,i),'b-','linewidth',2);
    hold on;
    plot(t,abacc(:,i),'r--','linewidth',2);
    plot(tv,Accsmooth(:,i),'c-','linewidth',2);
    plot(t(terrs),abacc(terrs,i),'kx','markersize',12,'linewidth',2);
    
    set(gca,'ylim',[min(Acc(:,i)) max(Acc(:,i))]);
    if i == 3
        legend('accelerometer','optitrack body-frame with accelerometer offset','15 term accelerometer avg','Optitrack errors','location','southoutside');
    end
end

%find times outside those we want to ignore
igind = find( any( repmat(tv,1,size(t_ig,1)) > repmat(t_ig(:,1)',length(tv),1) & repmat(tv,1,size(t_ig,1)) < repmat(t_ig(:,2)',length(tv),1), 2) );
igind = setdiff(1:length(tv),igind);

%plot error histories in those times
figure;
accinterp = interp1(t,abacc,tv);
resid = accinterp - Acc;
for i = 1:3
    subplot(3,1,i);
    plot(tv(igind),resid(igind,i));
end

%% plot residuals versus optitrack accelerations

sigma_hover = 2*[.56 .54 .36];
figure;
for i = 1:3
    subplot(3,1,i);
    inhist = find(abs(resid(igind,i)) <= 3*repmat(sigma_hover(i),length(igind),1));
    fprintf('Percent retained on axis %i: %f\n',i,length(inhist)/length(igind));
    % test if we can detect outliers from the onboard data alone
    histfromdata = find(abs(diff(Att(igind,i))) > 3*sigma_hover(i));
    inter = intersect(histfromdata,inhist);
    fprintf('Percent predicted from flight data: %f\n',length(inter)/length(inhist));
    fprintf('False negatives from flight data: %f\n',length(inter)/length(histfromdata));
    
    title(['Expected std: ' num2str(sigma_hover(i))]);
    histfit( resid(igind(inhist),i), 30);
end

figure;
for i = 1:3
    % find values outside 3sigma
    sigmai = std(resid(igind,i));
    inout = find( abs(resid(igind,i)) > 3*sigmai );
    inin = setdiff(1:length(igind),inout);
    % fit line to residuals versus optitrack accels
    X = [ones(length(igind(inin)),1) Acc(igind(inin),i)];
    y = resid(igind(inin),i);
    b = regress(y,X);
    
    fprintf('Slope of residuals axis %i: %f deg\n',i,atand(b(2)));

    %plot
    subplot(3,1,i);
    plot(Acc(igind(inin),i),resid(igind(inin),i),'x');
    title([num2str(i) ' axis residuals versus measured accelerations']);
    hold on;
    x = min(Acc(igind,i)):.1:max(Acc(igind,i));
    plot(Acc(igind(inout),i),resid(igind(inout),i),'kd');
    plot(x,[ones(length(x),1) x']*b,'r--');
end
%% angular rate histories

sigma_hover = 2*[.085 .048 .077];

figure;
for i = 1:3
    subplot(3,1,i);
    plot(tv,Att(:,i+3),'b-');
    hold on;
    plot(t,wb(:,i),'r--');
    ylabel([num2str(i) 'th axis angular rate']);
end

% outlier rejection for yaw rate
wbinterp = interp1(t,wb,tv);
residq = wbinterp - Att(:,4:6);
%[ignore2x,ignore2y] = find(abs(residq(igind,:)) > 3*repmat(sigma_hover,length(igind),1));
%residq(igind(ignore2x),ignore2y) = nan;

figure;
for i = 1:3
    subplot(3,1,i);
    inhist = find(abs(residq(:,i)) <= 3*repmat(sigma_hover(i),length(residq),1));
    fprintf('Percent retained on axis %i: %f\n',i,length(inhist)/length(residq));
    title(['Expected std: ' num2str(sigma_hover(i))]);
    histfit( residq(inhist,i), 30);
end

figure;
for i = 1:3
    subplot(3,1,i);
    plot(tv(igind),residq(igind,i),'b-');
    ylabel([num2str(i) 'th axis angular residual']);
end

%plot residuals vs true rates
figure;
for i = 1:3
    % find values outside 3sigma
    sigmai = nanstd(residq(igind,i));
    inout = find( abs(residq(igind,i)) > 3*sigmai );
    inin = setdiff(1:length(igind),inout);
    
    % fit line to residuals versus optitrack accels
    X = [ones(length(igind(inin)),1) wbinterp(igind(inin),i)];
    y = residq(igind(inin),i);
    b = regress(y,X);
    
    fprintf('Slope of residuals axis %i: %f deg\n',i,atand(b(2)));
    
    subplot(3,1,i);
    plot(wbinterp(igind(inin),i),residq(igind(inin),i),'bx');
    hold on;
    x = min(wbinterp(igind,i)):.1:max(wbinterp(igind,i));
    plot(x,[ones(length(x),1) x']*b,'r--');
    plot(wbinterp(igind(inout),i),residq(igind(inout),i),'kd');
    
    ylabel('residual');
    xlabel('optitrack');
end

%% optic flow

% convert optitrack velocities to FLOW frame
C = [1/sqrt(2)*[1 1;-1 1] [0;0];[0 0 1]];
vb_flow = vb*C';

for i = 1:2
    subplot(2,1,i);
    plot(tv,flow(:,i+2),'r--');
    hold on;
    plot(t(igind),vb_flow(igind,i));
end