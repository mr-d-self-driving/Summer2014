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
folder = 'C:\Users\fatadama\Documents\summer 2014\Optitrack\July 28 flow test';
%%
fname1 = [folder '\_slash_flow.csv'];
fname2 = [folder '\opti.csv'];

[dat2,txt] = xlsread(fname2);
[t,xyz,quat] = ros2body(dat2,txt);
    tdel = find(t > 125,1,'first');
    t(tdel+1:end) = [];
    xyz(tdel+1:end,:) = [];
    quat(tdel+1:end,:) = [];
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

[num,txt] = xlsread(fname1);
labels = txt(1,:);

%% vehicle histories:
tind = find(strcmp('rosbagTimestamp',labels));
tfirst = find(~isnan(num(:,tind)),1,'first');
%delete nans
num(1:tfirst-1,:) = [];
tv = (num(:,tind) - num(1,tind))*1e-9;

tind = find(strcmp('flowXm',labels));
flow = num(:,tind-2:tind+3);

Cflow = [0.7071 0.7071;-0.7071 0.7071];% body to flow frame
vb_flow = flow(:,3:4)*Cflow;

vopt_flow = vb(:,1:2)*Cflow';

%% align time histories

delta = alignTimeHistoriesPh(t,-xyz(:,3),tv,flow(:,6));
t = t + delta; % better be sure the alignment is good
%% plot data

vb_in = interp1(t,vb,tv);
vopt_flow_in = interp1(t,vopt_flow,tv);
wb_in = interp1(t,wb,tv);
euler_in = interp1(t,euler,tv);
xyz_in = interp1(t,xyz,tv);

figure;
for i = 1:2
    subplot(3,1,i)
    plot(t,vopt_flow(:,i),'-x');
    hold on;
    plot(tv,flow(:,2+i),'r--');
    ylabel(['v_' num2str(i) '_f_l_o_w (m/s)']);
end
set(gcf,'position',[150 250 1150 675]);
legend('flow','truth');
subplot(3,1,3);
plot(t,-xyz(:,3));
hold on;
plot(tv,flow(:,6),'r--');
ylabel('altitude (m)');

figure;
plot(tv,flow(:,5));
ylabel('flow quality');

%% process
t1 = [6.5 12;
    12 15.5;
    15.5 22];

for i = 1:size(t1,1)
    ind = find(tv < t1(i,2) & tv >= t1(i,1));
    indt = find(t < t1(i,2) & t >= t1(i,1));
    fprintf('Mean errors in segment %i: %g,%g m/s\n',i,nanmean(vopt_flow_in(ind,1:2)-flow(ind,3:4)));
    fprintf('Standard errors in segment %i: %g,%g m/s\n',i,nanstd(vopt_flow_in(ind,1:2)-flow(ind,3:4)));
    fprintf('Mean squared errors in segment %i: %g,%g m/s\n',i,nanmean((vopt_flow_in(ind,1:2)-flow(ind,3:4)).^2));
    fprintf('Altitude extrema in segment %i: %.3g-%.3g m\n\n',i,min(-xyz(indt,3)),max(-xyz(indt,3)));
end