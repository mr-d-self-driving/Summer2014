%% rest_data
% characterize sensors from data taken at rest on the ground and in POSCTL
% mode

clear variables;
close all;

addpath('../Optitrack');

%get the folder the data are in:
%folder = uigetdir();
%debugging
folder = 'C:\Users\fatadama\Documents\summer 2014\Optitrack\June 13';

%% load onboard log data
fname1 = [folder '\log.csv'];

%load vehicle data
[num,txt] = xlsread(fname1);
labels = txt(1,:);

%vehicle histories:
tind = find(strcmp('TIME_StartTime',labels));
tfirst = find(~isnan(num(:,tind)),1,'first');
%delete nans
num(1:tfirst-1,:) = [];
tv     = (num(:,tind) - num(1,tind))/10^6;

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
%% plot time histories
close all;
% acceleration
figure;
for i = 1:3
    subplot(3,1,i);
    plot(tv,Acc(:,i));
    title(['Accelerometer data for axis ' num2str(i)]);
end
% gyro
figure;
for i = 1:3
    subplot(3,1,i);
    plot(tv,Att(:,3+i));
    title(['Gyro data for axis ' num2str(i)]);
end

% optic flow
figure;
for i = 1:3
    subplot(3,1,i);
    plot(tv,flow(:,i+2));
    switch i 
        case 1
            title('FLOW compX');
        case 2
            title('FLOW compY');
        case 3
            title('FLOW distance');
    end
end
%% segment data

t_c = [1 16;
    26.25 52;
    54.75 69.75];

tind = cell(3,1);
for i = 1:size(t_c,1)
    tind{i} = find(tv < t_c(i,2) & tv > t_c(i,1));
end

%% accelerometer characterization

t1 = tv(tind{1});
acc1 = Acc(tind{1},:);

figure;
for i = 1:3
    subplot(3,1,i);
    plotFFT(acc1(:,i) - mean(acc1(:,i)),50);
    title(['FFT for accelerometer axis ' num2str(i) ' during rest 1']);
end

fprintf('Mean accel rest 1: %0.2g,%0.2g,%0.2g\n',mean(acc1));
fprintf('Std accel rest 1: %0.2g,%0.2g,%0.2g\n',std(acc1));

t2 = tv(tind{2});
acc2 = Acc(tind{2},:);

figure;
for i = 1:3
    subplot(3,1,i);
    plotFFT(acc2(:,i)- mean(acc2(:,i)),50);
    title(['FFT for accelerometer axis ' num2str(i) ' during hover']);
end

fprintf('Mean accel hover: %0.2g,%0.2g,%0.2g\n',mean(acc2));
fprintf('Std accel hover: %0.2g,%0.2g,%0.2g\n',std(acc2));

t3 = tv(tind{3});

acc3 = Acc(tind{3},:);

figure;
for i = 1:3
    subplot(3,1,i);
    plotFFT(acc3(:,i)- mean(acc3(:,i)),50);
    title(['FFT for accelerometer axis ' num2str(i) ' during rest 2']);
end

fprintf('Mean accel rest 2: %0.2g,%0.2g,%0.2g\n',mean(acc3));
fprintf('Std accel rest 2: %0.2g,%0.2g,%0.2g\n',std(acc3));

% histogram
figure;
subplot(311);
histfit(acc2(:,1));
title('1 axis accelerometer values from hover');

subplot(312);
histfit(acc2(:,2));
title('2 axis accelerometer values from hover');

subplot(313);
histfit(acc2(:,3));
title('3 axis accelerometer values from hover');

%% gyro characterization

for j = 1:3
    t = tv(tind{j});
    gyro = Att(tind{j},4:6);
    figure;
    for i = 1:3
        subplot(3,1,i);
        plotFFT(gyro(:,i),50);
        switch j
            case 1
                title(['FFT for gyro axis ' num2str(i) ' during rest 1']);
            case 2
                title(['FFT for gyro axis ' num2str(i) ' during hover']);
            case 3
                title(['FFT for gyro axis ' num2str(i) ' during rest 2']);
        end
    end
    switch j
        case 1
            fprintf('Mean gyro rest 1:');
        case 2
            fprintf('Mean gyro hover:');
        case 3
            fprintf('Mean gyro rest 2:');
    end
    fprintf(' %0.2g,%0.2g,%0.2g\n',mean(gyro));
    switch j
        case 1
            fprintf('Std gyro rest 1:');
        case 2
            fprintf('Std gyro hover:');
        case 3
            fprintf('Std gyro rest 2:');
    end
    fprintf(' %0.2g,%0.2g,%0.2g\n',std(gyro));
    
    if j == 2
        % histogram
        figure;
        subplot(311);
        histfit(gyro(:,1));
        title('1 axis gyro values from hover');
        
        subplot(312);
        histfit(gyro(:,2));
        title('2 axis gyro values from hover');
        
        subplot(313);
        histfit(gyro(:,3));
        title('3 axis gyro values from hover');
    end
end

%% optic flow characterization

% raw optic flow sensors need to rotate 1 3 rotation thru -pi/4 to match
% the body axis

for j = 2
    t = tv(tind{j});
    flowh = flow(tind{j},1:3);
    % rotate through - 45
    %C = [1/sqrt(2)*[1 -1;1 1] [0;0];[0 0 1]];
    %flowh = flowh*C';
    
    figure;
    for i = 1:3
        subplot(3,1,i);
        plotFFT(flowh(:,i),50);
        switch j
            case 1
                title(['FFT for flow axis ' num2str(i) ' during rest 1']);
            case 2
                title(['FFT for flow axis ' num2str(i) ' during hover']);
            case 3
                title(['FFT for flow axis ' num2str(i) ' during rest 2']);
        end
    end
    switch j
        case 1
            fprintf('Mean flow rest 1:');
        case 2
            fprintf('Mean flow hover:');
        case 3
            fprintf('Mean flow rest 2:');
    end
    fprintf(' %0.2g,%0.2g,%0.2g\n',mean(flowh));
    switch j
        case 1
            fprintf('Std flow rest 1:');
        case 2
            fprintf('Std flow hover:');
        case 3
            fprintf('Std flow rest 2:');
    end
    fprintf(' %0.2g,%0.2g,%0.2g\n',std(flowh));
    
    % plot hisograms
    figure;
    for i = 1:3
        subplot(3,1,i);
        histfit(flowh(:,i),20)
        title(['Hisotgram with normal distribution fit for flow axis ' num2str(i)]);
    end
end