%% Jul2_flight1
% get optitrack data, flew back and forth some

clear variables;
close all;

addpath('..');
addpath('../Optitrack');
addpath('../near system identification');

%get the folder the data are in:
%folder = uigetdir();
%debugging, use the dynamic flight data
folder = 'C:\Users\fatadama\Documents\summer 2014\Optitrack\July 2 3DR drag char';

fname2 = [folder '\opti.csv'];

[dat2,txt] = xlsread(fname2);
[t,xyz,quat] = ros2body(dat2,txt);
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

%% plot data
tuse = [20 29.59;
    31.64 39.44;
    73.65 80.96;
    82.06 89.91];
%tuse = [31.41 39.49;
%    39.9 44.51];

tind = [];
for i = 1:size(tuse,1)
    tind2 = find(t < tuse(i,2) & t > tuse(i,1));
    tind = [tind;tind2];
end
tind = unique(tind);

figure
for i = 1:3
    subplot(3,1,i);
    plot(t(tind),xyz(tind,i),'-x');
    ylabel([num2str(i) ' axis inertial position (m)']);
end

figure
for i = 1:3
    subplot(3,1,i);
    plot(t(tind),vb(tind,i));
    ylabel([num2str(i) ' body axis velocity (m/s)']);
end

figure
for i = 1:3
    subplot(3,1,i);
    plot(t(tind),ab(tind,i));
    ylabel([num2str(i) ' body axis acceleration (m/s^2)']);
end

figure;
for i = 1:3
    subplot(3,1,i);
    %plot(t(tind),quat(tind,i+1));
    plot(t(tind),euler(tind,i)*r2d);
    switch i 
        case 1 
            ylabel('\phi (deg)');
        case 2
            ylabel('\theta (deg)');
        case 3
            ylabel('\psi (deg)');
    end
end

%% approximate the derivative at all points

%assume a fixed sample period of .01 sec
ts = .01;

h = 2*ts;

vbdot = zeros(length(t),3);
for i = 2:length(t)-1
    vbdot(i,:) = (vb(i+1,:)-vb(i-1,:))/h;
end
vbdot(1,:) = (vb(2,:)-vb(1,:))/ts;
vbdot(end,:) = (vb(end,:)-vb(end-1,:))/ts;

figure;
for i = 1:3
    subplot(3,1,i);
    hold on;
    plot(t(tind),vbdot(tind,i),'r-');
end

%% compute a best-fit for the data

g = 9.81;

% use the optitrack data
lhs = -vbdot + [-g*sin(euler(:,2)) g*sin(euler(:,1)).*cos(euler(:,2)) g*cos(euler(:,1)).*cos(euler(:,2))] + ...
    [vb(:,2).*wb(:,3)-vb(:,3).*wb(:,2) vb(:,3).*wb(:,1)-vb(:,1).*wb(:,3) vb(:,1).*wb(:,2)-vb(:,2).*wb(:,1)] + ...
    zeros(length(t),3);%the thrust term should go here, but we don't measure it or need it
x = fit_mdl(lhs(tind,1:2),vb(tind,1:2));
n3b = [-sin(euler(:,2)) sin(euler(:,1)).*cos(euler(:,2)) cos(euler(:,1)).*cos(euler(:,2))];
lhs2 = abacc;% - g*n3b;
x2 = fit_mdl(lhs2(tind,1:2),-vb(tind,1:2));

% plot the fit
testrhs =  [-g*sin(euler(:,2)) g*sin(euler(:,1)).*cos(euler(:,2))] + ...
    [vb(:,2).*wb(:,3)-vb(:,3).*wb(:,2) vb(:,3).*wb(:,1)-vb(:,1).*wb(:,3)] - ...
    [vb(:,1) vb(:,2)]*x;
testlhs = vbdot(:,1:2);
theircon = [-g*sin(euler(:,2)) g*sin(euler(:,1)).*cos(euler(:,2))] + ...
    [vb(:,2).*wb(:,3)-vb(:,3).*wb(:,2) vb(:,3).*wb(:,1)-vb(:,1).*wb(:,3)];

figure;
for i = 1:2
    subplot(2,1,i);
    plot(t(tind),testlhs(tind,i),'b-');
    hold on
    plot(t(tind),testrhs(tind,i),'r--');
    plot(t(tind),theircon(tind,i),'m--');
    
    legend('differenced velocity time rates','predicted velocity time rates','prediction with zero drag');
end

mse = sum(( testlhs(tind,:)-testrhs(tind,:)).^2)/length(tind)
mse_their = sum(( testlhs(tind,:)-theircon(tind,:)).^2)/length(tind)

%% compute best-fits to each segment

opti_diff = zeros(size(tuse,1),1);
opti_acc = zeros(size(tuse,1),1);
for i = 1:size(tuse,1)
    ti = find(t > tuse(i,1) & t < tuse(i,2));
    
    lhs = -vbdot + [-g*sin(euler(:,2)) g*sin(euler(:,1)).*cos(euler(:,2)) g*cos(euler(:,1)).*cos(euler(:,2))] + ...
        [vb(:,2).*wb(:,3)-vb(:,3).*wb(:,2) vb(:,3).*wb(:,1)-vb(:,1).*wb(:,3) vb(:,1).*wb(:,2)-vb(:,2).*wb(:,1)] + ...
        zeros(length(t),3);%the thrust term should go here, but we don't measure it or need it
    lhs2 = abacc;% - g*n3b;
    x = fit_mdl(lhs(ti,1:2),vb(ti,1:2));
    x2 = fit_mdl(lhs2(ti,1:2),-vb(ti,1:2));
    
    opti_diff(i) = x;
    opti_acc(i) = x2;
end