%filter optitrack histories to generate acceleration-level time histories
close all;
clear variables;

addpath('../Optitrack');

%% read data
filename = 'log.xls';

filename2 = 'opti.xls';
numo = xlsread(filename2);
to = numo(:,5) + numo(:,6)/10^9 - numo(1,5);%time
dto  = to(2:end,1)-to(1:end-1,1);

xyz = numo(:,11:13);
dtt= sum(dto)/length(dto);
fc = 60; wc = fc*2*pi; alp = dtt/(1/wc+dtt);
%xyz = filter(alp,[1 alp-1],xyz);
OPVEL = [(xyz(2:end,1)-xyz(1:end-1,1))./dto   (xyz(1:end-1,2)-xyz(2:end,2))./dto   (xyz(1:end-1,3)-xyz(2:end,3))./dto]; 

%initialize to zero
xyz = xyz - repmat(mean(xyz(1:10,:)),length(xyz),1);
%% tune butterworth filter
close all;

% d = fdesign.lowpass(1.0,10,1,20,50,'dB');%Fpass, Fstop, Apass, Astop, Freq (Hz)
% HV = design(d,'butter');
% HV.PersistentMemory = false;
% 
% V_avgf = zeros(size(beard.V_avg));
% V_avgf(:,2) = filter(HV,beard.V_avg(:,2)-repmat( mean(beard.V_avg(1:50,2),1), length(beard.t_avg),1) )+repmat( mean(beard.V_avg(1:50,2),1),length(beard.t_avg),1);

%Fstop should be somewhere in 12.5 - 50 Hz range, still tuning
d = fdesign.lowpass(0.1,12.5,1,20,100,'dB');%Fpass, Fstop, Apass, Astop, Freq (Hz)
H = design(d,'butter');
H.PersistentMemory = false;
xyz_avg1 = filter(H,xyz);

[b,a] = butter(1,1.5/50,'low');
xyz_avg = filter(b,a,xyz);

% plot

for i = 1:3
    subplot(3,2,2*i-1);
    plot(to,xyz(:,i),'-','linewidth',2);
    hold on;
    plot(to,xyz_avg(:,i),'r--','linewidth',2);
    plot(to,xyz_avg1(:,i),'k:','linewidth',2);
    switch i
        case 1
            ylabel('x');
        case 2
            ylabel('y');
        case 3
            ylabel('z');
    end
end

for i = 1:3
    subplot(3,2,2*i);
    plot(to,xyz(:,i)-xyz_avg(:,i),'-','linewidth',2);
    switch i
        case 1
            ylabel('x diff');
        case 2
            ylabel('y diff');
        case 3
            ylabel('z diff');
    end
end

%% tune velocity-level butterworth filter

figure;

v_n = diff(xyz_avg)./repmat(diff(to),1,3);

d = fdesign.lowpass(0.01,10.0,1,20,100,'dB');%Fpass, Fstop, Apass, Astop, Freq (Hz)
Hv = design(d,'butter');
Hv.PersistentMemory = false;
v_n_avg1 = filter(Hv,v_n);

[bv,av] = butter(1,1.0/50.0,'low');
v_n_avg = filter(bv,av,v_n);

for i = 1:3
    subplot(3,2,2*i-1);
    plot(to(1:end-1),v_n(:,i),'-','linewidth',2);
    hold on;
    plot(to(1:end-1),v_n_avg(:,i),'r--','linewidth',2);
    plot(to(1:end-1),v_n_avg1(:,i),'k:','linewidth',2);
    switch i
        case 1
            ylabel('xdot');
        case 2
            ylabel('ydot');
        case 3
            ylabel('zdot');
    end
end

for i = 1:3
    subplot(3,2,2*i);
    plot(to(1:end-1),v_n(:,i)-v_n_avg(:,i),'-','linewidth',2);
    switch i
        case 1
            ylabel('x diff');
        case 2
            ylabel('y diff');
        case 3
            ylabel('z diff');
    end
end
%% check with numerical integration

xyz_int = zeros(size(v_n_avg));
for i = 1:length(v_n_avg)
    if i == 1
        xyz_int(i,:) = xyz_avg(i,:);
    else
        xyz_int(i,:) = xyz_avg(1,:) + trapz(to(1:i),v_n_avg(1:i,:));
    end
end

for i = 1:3
    subplot(3,1,i);
    plot(to,xyz(:,i),'-','linewidth',2);
    hold on;
    plot(to(1:end-1),xyz_int(:,i),'r--','linewidth',2);
    switch i 
        case 1
            ylabel('x');
        case 2
            ylabel('y');
        case 3
            ylabel('z');
    end
end
%% acceleration-level histories
%a_n = diff(v_n_avg)./repmat(diff(to(1:end-1)),1,3);

a_n = (xyz_avg(1:end-2,:)-2*xyz_avg(2:end-1,:)+xyz_avg(3:end,:))./repmat( diff(to(2:end)).^2 , 1,3);

[b,a] = butter(1,1.0/50,'low');

ao = repmat(a_n(1,:),length(a_n),1);
a_n_avg = filter(b,a,a_n - ao)+ ao;
clear ao;

% integrate forwards as a check
v_n_int = zeros(size(a_n));
xyz_int_2 = zeros(size(a_n));
for i = 1:length(a_n)
    if i == 1
        v_n_int(i,:) = v_n_avg(1,:);
        xyz_int_2(i,:) = xyz_avg(1,:);
    else
        v_n_int(i,:) = trapz(to(1:i),a_n_avg(1:i,:));
        xyz_int_2(i,:) = trapz(to(1:i),v_n_int(1:i,:));
    end
end

for i = 1:3
    subplot(3,2,2*i-1);
    plot(to(1:end-2),a_n(:,i),'-','linewidth',2);
    hold on;
    plot(to(1:end-2),a_n_avg(:,i),'r--','linewidth',2);
    switch i
        case 1
            ylabel('xddot');
        case 2
            ylabel('yddot');
        case 3
            ylabel('zddot');
    end
    
    subplot(3,2,2*i);
    %plot(to(1:end),xyz_avg(:,i),'b-','linewidth',2);
    %hold on;
    %plot(to(1:end-2),xyz_int_2(:,i),'r--','linewidth',2);
    plot(to(1:end-2),v_n_int(:,i),'r--','linewidth',2);
    hold on;
    plot(to(1:end-1),v_n_avg(:,i),'b-','linewidth',2);
    
    switch i
        case 1
            ylabel('xdot_int');
        case 2
            ylabel('ydot_int');
        case 3
            ylabel('zdot_int');
    end
end
%% rotational data

quat = numo(:,15:18);
%quat_avg = filter(H,quat - repmat( quat(1,:), length(quat), 1)) + repmat( quat(1,:), length(quat), 1);
quat_avg = filter(b,a,quat - repmat( quat(1,:), length(quat), 1)) + repmat( quat(1,:), length(quat), 1);
%normalize
quat_avg = quat_avg./repmat(sqrt(sum(quat_avg.^2,2)),1,4);

% approximate dq/dt
dq = diff(quat_avg)./repmat(diff(to),1,4);
%dq_avg = filter(Hv,dq);
dq_avg = filter(bv,av,dq);

% integrate quaternion time history as a check

quat_int = zeros(size(dq));
for i = 1:length(dq)
    if i == 1
        quat_int(i,:) = quat_avg(1,:);
    else
        quat_int(i,:) = trapz(to(1:i),dq_avg(1:i,:)) + quat_int(1,:);
    end
    %normalize quaternion
    quat_int(i,:) = quat_int(i,:)./norm(quat_int(i,:));
end

%integrate as check
for i = 1:4
    subplot(2,2,i);
    plot(to,quat_avg(:,i),'b-','linewidth',2);
    hold on;
    plot(to(1:end-1),quat_int(:,i),'r--','linewidth',2);
    xlabel(['q_' num2str(i)]);
end
%% export data

t = to(1:end-2);
rn = xyz_avg(1:end-2,:);
vn = v_n_avg(1:end-1,:);
an = a_n_avg;

%components of the inertial-to-body quaternion
qb = quat_avg(1:end-2,:);
dqb = dq_avg(1:end-1);

save('data.mat','t','rn','vn','qb','dqb','an','-append');