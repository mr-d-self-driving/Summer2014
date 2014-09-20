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
folder = 'C:\Users\fatadama\Documents\summer 2014\Optitrack\July 28 flow test 2';
%%
fname1 = [folder '\_slash_flow.csv'];
fname2 = [folder '\opti.csv'];
fname3 = [folder '\_slash_flowDebug.csv'];

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

%% load flow imu data

[num,txt] = xlsread(fname3);
labels = txt(1,:);
tind = find(strcmp('rosbagTimestamp',labels));
tfirst = find(~isnan(num(:,tind)),1,'first');
%delete nans
num(1:tfirst-1,:) = [];
tv2 = (num(:,tind) - num(1,tind))*1e-9;

tind = find(strcmp('x',labels));
flowgyro = num(:,tind+(0:2));

%% align time histories

delta = alignTimeHistoriesPh(t,-xyz(:,3),tv,flow(:,6));
t = t + delta; % better be sure the alignment is good
%% plot data

vb_in = interp1(t,vb,tv);
vopt_flow_in = interp1(t,vopt_flow,tv);
wb_in = interp1(t,wb,tv);
euler_in = interp1(t,euler,tv);
xyz_in = interp1(t,xyz,tv);
an_in = interp1(t,an,tv);

figure;
for i = 1:2
    subplot(3,1,i)
    plot(t,vopt_flow(:,i),'-x');
    hold on;
    plot(tv,flow(:,2+i),'r--');
    ylabel(['v_' num2str(i) '_f_l_o_w (m/s)']);
end
set(gcf,'position',[150 250 1150 675]);
legend('truth','flow');
subplot(3,1,3);
plot(t,-xyz(:,3));
hold on;
plot(tv,flow(:,6),'r--');
ylabel('altitude (m)');

figure;
plot(tv,flow(:,5));
ylabel('flow quality');

%% process

% compute true sonar range from optitrack
Rarm = 3;% inches
Rarm = 0.0254*Rarm;%meters
f = 16;%focal length in mm

Rsonar = ((Rarm*cos(pi/4)*(-sin(euler(:,2))+cos(euler(:,2)).*sin(euler(:,1))))-xyz(:,3))./(cos(euler(:,1)).*cos(euler(:,2)));
Rsonar_in = interp1(t,Rsonar,tv);

FLOW_K = 0.15;
flow_dt = diff(tv);

flow_prev = flow(1:end-1,1:2);
flow_ang = flow(2:end,1:2) * FLOW_K/1000./repmat(flow_dt,1,2);
flow_dist = flow(:,6);

% flow measurements vector
flow_m(:,1:2) = -flow_ang .* repmat(flow_dist(2:end),1,2);
flow_m(:,3) = 0;

w_xy_flow = 5.0;
flow_q_min = 0.5;
flow_q = flow(:,5)/255;
flow_q_weight = (flow_q - flow_q_min)/(1-flow_q_min);
w_flow = zeros(length(tv),1);

% convert flow_m to the global frame
flow_v = zeros(length(tv),2);
corr_flow = zeros(length(tv),2);

x_est = zeros(length(tv),2);
y_est = zeros(length(tv),2);
z_est = zeros(length(tv),2);
for i = 1:length(tv)-1
    C = attparsilent([euler_in(i,[3 2 1])' [3;2;1]],[4 1],struct('seq',[3 2 1]));%inertial to body frame
    flow_m(i,3) = x_est(3,2);
    flow_v(i,:) = (C(:,1:2)'*flow_m(i,1:3)');
    corr_flow(i,:) = flow_v(i,:) - [x_est(i,2) y_est(i,2)];
    z_est(i+1,:) = inertial_filter_predict(flow_dt(i),z_est(i,:),an_in(i,3));
    x_est(i+1,:) = inertial_filter_predict(flow_dt(i),x_est(i,:),an_in(i,1));
    y_est(i+1,:) = inertial_filter_predict(flow_dt(i),y_est(i,:),an_in(i,2));
    w_flow(i) = C(3,3)*flow_q_weight(i)/max([flow_dist(i) 1]);
    x_est(i+1,:) = inertial_filter_correct(corr_flow(i,1),flow_dt(i),x_est(i+1,:),2,w_xy_flow*w_flow(i));
    y_est(i+1,:) = inertial_filter_correct(corr_flow(i,2),flow_dt(i),y_est(i+1,:),2,w_xy_flow*w_flow(i));
end

%% more plots

figure;
for i = 1:2
    subplot(2,1,i)
    plot(t,vn(:,i),'-x');
    hold on;
    %plot(tv,flow(:,2+i),'r--');
    switch i
        case 1
            plot(tv,x_est(:,2),'m--');
        case 2
            plot(tv,y_est(:,2),'m--');
    end
        
    ylabel(['v_' num2str(i) '_n (m/s)']);
end
set(gcf,'position',[150 250 1150 675]);
legend('truth','flow_est');