%% ladder testing
% get flow sensor data from sensor moving, motors off

clear variables;
close all;

addpath('..');
addpath('../Optitrack');
addpath('../near system identification');

%get the folder the data are in:
%folder = uigetdir();
%debugging, use the dynamic flight data
%folder = 'C:\Users\fatadama\Documents\summer 2014\Optitrack\June 19 ladder test Black';
folder = 'C:\Users\fatadama\Documents\summer 2014\Optitrack\June 19 ladder test Colorful';

fname1 = [folder '\log.csv'];
fname2 = [folder '\opti.csv'];

[dat2,txt] = xlsread(fname2);
[t,xyz,quat] = ros2body(dat2,txt);
[t,xyz,vb,ab,quat,wb,vn,an] = opti_velocities(t,xyz,quat,0);

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

delta = -5.01;% for black

% delta == -5.01 for Black
plot(t,-xyz(:,3),tv,flow(:,5),'r--',tv,baro-baro(1),'m--');
hold on;
plot(tv,-LPOS(:,3),'k-');

[~,ind] = unique(flow(:,3:4),'rows','first');
ind = sort(ind,'ascend');
flowshort = flow(ind,:);
tshort = tv(ind);
%% 

%colorful:
flowshort( isnan(flowshort(:,3)),3) = 0;
delta = alignTimeHistories(t,vb_flow(:,1),tshort,flowshort(:,3),-1.5);
t = t+delta;

tind = find(tshort > 14.89 & tshort < 31.85);

%% 
figure;
for i = 1:2
    subplot(2,1,i);
    plot(tshort(tind),flowshort(tind,2+i),'r--x');
    hold on;
    plot(t,vb_flow(:,i));
    title([num2str(i) ' axis velocity m/s']);
end

% residuals for velocity

vb_flow_in = interp1(t,vb_flow(:,1:2),tshort);
xyz_in = interp1(t,xyz,tshort);

resid = vb_flow_in - flowshort(:,3:4);

fprintf('Mean x and y residuals (m/s): %.2g,%.2g\n',nanmean(resid(tind,:)));
fprintf('Std of x and y residuals (m/s): %.2g,%.2g\n',nanstd(resid(tind,:)));
fprintf('Mean abs x and y velocity optitrack (m/s): %.2g,%.2g\n',nanmean(abs(vb_flow_in(tind,:))));
fprintf('Mean alt (m): %.2g\n',nanmean(-xyz_in(tind,3)));

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

%% plot residual vs alt

% there seems to be a definite dependence on altitude

figure;
subplot(211);
plot(resid(:,1),-xyz_in(:,3),'d');
hold on;
%plot(resid(tind,1),-xyz_in(tind,3),'rx');
ylabel('altitude (m)');
xlabel('x-axis velocity residuals (m/s)');

subplot(212);
plot(resid(:,2),-xyz_in(:,3),'d');
hold on
%plot(resid(tind,2),-xyz_in(tind,3),'rx');
ylabel('altitude (m)');
xlabel('y-axis velocity residuals (m/s)');

%legend('all residuals','residuals in low error regions');

%% try to characterize residual standard error as a function of altitude

discr = 0.5;

alts = 0:discr:3.5001;

xyz_round = round(xyz_in/discr)*discr;

stds = zeros(length(alts),2);
hypo = zeros(length(alts),1);
for i = 1:length(alts)
    altind = find(-xyz_round(:,3) == alts(i));
    stds(i,:) = std(resid(altind,1:2));
    if alts(i) <= 1.5
        hypo(i) = 0.2;
    else if alts(i) <= 3
            hypo(i) = (1.25 - .2)/(3-1.5)*(alts(i)-1.5) + 0.2;
        else if alts(i) > 3
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

% this one yields hypo = 0.2, z <= 1.5
%   hypo = (1.25 - .2)/(3-1.5)*(z-1.5) + 0.2, 1.5 < z <= 3
%   hypo = 1.25, 3<=z