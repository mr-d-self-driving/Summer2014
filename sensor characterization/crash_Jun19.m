%% crash_Jun19
% get data from a crash on Jun19. Onboard only.

clear variables;
close all;

addpath('..');
addpath('../Optitrack');
addpath('../near system identification');

%get the folder the data are in:
%folder = uigetdir();
%debugging, use the dynamic flight data
folder = 'C:\Users\fatadama\Documents\summer 2014\Optitrack\June 19 crash';

fname1 = [folder '\log.csv'];
%fname2 = [folder '\opti.csv'];

%[dat2,txt] = xlsread(fname2);
%[t,xyz,quat] = ros2body(dat2,txt);
%[t,xyz,vb,ab,quat,wb,vn,an] = opti_velocities(t,xyz,quat,0);
%% vehicle histories:
[num,txt] = xlsread(fname1);
labels = txt(1,:);

tind = find(strcmp('TIME_StartTime',labels));
tfirst = find(~isnan(num(:,tind)),1,'first');
%delete nans
num(1:tfirst-1,:) = [];
tv     = (num(:,tind) - num(1,tind))/10^6;
% cut the body-frame time to match the optitrack time
%incut = find( tv < min(t) | tv > max(t) );
%tv(incut) = [];
%num(incut,:) = [];

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
%baro(isnan(baro)) = -Inf;

Easy  = round(RC(:,5));

inde = find(Easy==0);
% compute vehicle inertial velocity components
vn_quad = zeros(size(LPOSV));
for i = 1:length(tv)
    C = DCMConverter(1,Att(i,1))*DCMConverter(2,Att(i,2))*DCMConverter(3,Att(i,3));%body-to-inertial
    vn_quad(i,:) = LPOSV(i,:)*C;
end
%% plot data

inshort = find(diff(flow(:,5)) ~= 0);
inshort = [1;inshort];
tshort = tv(inshort);
flowshort = flow(inshort,:);

figure;
plot(tshort,flowshort(:,5),'k-x',tv,baro-nanmean(baro(71:197)),'m--',tv,-LPOS(:,3),'r--');
hold on;
%plot(t,-xyz(:,3));
legend('sonic','baro','LPOS');
ylabel('altitude (m)');

figure;
plot(tv,Acc(:,3),'r--');
hold on;
%plot(t,abacc(:,3),'b-');

%plot body-axis velocities
figure;
plot(tv,LPOSV(:,3),'r--');
hold on;
%plot(t,vb(:,3),'b-');
ylabel('v_3 (m/s)');

% check attitude
figure;
for i = 1:3
    subplot(3,1,i);
    %plot(t,euler(:,i)*r2d);
    %hold on;
    title('Attitude (deg)');
    if i == 3
        plot(tv,Att(:,i)*r2d + 90,'r--');
    else
        plot(tv,Att(:,i)*r2d,'r--');
    end
end

%% FFT of accel data

%tind = find(tv > 25 & tv < 175);
tind = find(tv > 52 & tv <64);%June 24 test 2
%tind = find(tv > 60 & tv < 120);%June 24 position hold test
%tind = find(tv > 16 & tv < 20);% June 23 freakout

figure;
for i = 1:3
subplot(3,1,i);
plotFFT(Acc(tind,i),50);
end
for i = 1:3
subplot(3,1,i);set(gca,'ylim',[0 .25]);
title([num2str(i) ' axis accelerometer FFT']);
end
set(gcf,'position',[105 166 1200 800]);

%% check the onboard filter did what we think it should have
z_est = [0;0];% z_est(1) is position; (2) is velocity;

[~,i1] = min(abs(tv-1.5));
[~,i2] = min(abs(tv-3.5));

baro_o = mean(baro(i1:i2));

z_est_hist = zeros(length(tv),2);
w_z_baro = 0.5;
for i = 1:length(tv)-1
    dt = tv(i+1)-tv(i);
    corr_baro = baro_o - baro(i) - z_est(1);
    acc = Acc(i,3) + 9.81;
    if ~isnan(dt) && dt~=0 && ~isnan(acc)
        z_est(1) = z_est(1) + z_est(2)*dt + acc*dt^2/2;
        z_est(2) = z_est(2) + acc*dt;
    end
    if ~isnan(dt) && dt~=0 && ~isnan(corr_baro)
        z_est(1) = z_est(1) + dt*(corr_baro)*w_z_baro;
        z_est(1) = z_est(1) + dt*(corr_baro)*w_z_baro^2;
    end
    z_est_hist(i+1,:) = z_est';
end

plot(tv,z_est_hist(:,1));
hold on;
plot(tv,LPOS(:,3),'r--');

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

vb_flow_in = interp1(t,vb_flow(:,1:2),tshort);

resid = vb_flow_in - flowshort(:,3:4);

fprintf('Mean x and y residuals (m/s): %.2g,%.2g\n',nanmean(resid(tind,:)));
fprintf('Std of x and y residuals (m/s): %.2g,%.2g\n',nanstd(resid(tind,:)));
fprintf('Mean abs x and y velocity measured (m/s): %.2g,%.2g\n',mean(abs(flowshort(tind,:))));

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