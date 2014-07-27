%% id_from_data

clear variables;
close all;
addpath('../Optitrack');

%get the folder the data are in:
%folder = uigetdir();
%debugging
folder = 'C:\Users\fatadama\Documents\summer 2014\Optitrack\June 9';

%load optitrack data for ID
fname2 = [folder '\opti.csv'];

dat2 = xlsread(fname2);
[t,xyz,quat] = ros2body(dat2);
[t,xyz,vb,ab,quat,wb,vn,an] = opti_velocities(t,xyz,quat);

% note when there are gaps in the optitrack time history
Tthres = 1.75;%maximum tolerated multiplicative error on the assumed 100Hz sample rate; otherwise we flag a loss
terrs = find(diff(t) > Tthres*.01);

%% compute euler angle histories
eul = zeros(length(t),3);
for i = 1:length(t)
    B0 = quat(i,4);
    Bv = quat(i,1:3)';
    X = attpar([B0;Bv],[6 4],struct('seq',[3;2;1]));
    eul(i,:) = X(:,1)';
    eul(i, eul(i,:) > pi) = eul(i, eul(i,:) > pi) - 2*pi;
end
%% plot time histories of dynamic states & control states to look for good time intervals
close all;
figure;

for i = 1:4
    subplot(2,2,i);
    
    switch i
        case 1% u
            plot(t,vb(:,1),'-','linewidth',2);
            ylabel('u (m/s)');
        case 2 %theta
            plot(t,eul(:,2)*r2d,'-','linewidth',2);
            ylabel('\theta (deg)');
        case 3 % v
            plot(t,vb(:,2),'-','linewidth',2);
            ylabel('v (m/s)');
        case 4 %phi
            plot(t,eul(:,3)*r2d,'-','linewidth',2);
            ylabel('\phi (deg)');
    end
end
%% process data

%for June 5 data
%t_st = [13.04 21.53;
%    21.53 32.99;
%    13.04 32.99];
%for June 9 data
t_st = [11.27 58.46;
    11.27 30;
    30 58.46;
    68.94 76.51];
addpath('OKID');
addpath('LSQ');

SYSC = cell(size(t_st,1)*2,2);
SYSD = SYSC;

for i = 1:size(t_st,1)
    innow = find(t > t_st(i,1) & t < t_st(i,2));
    
    %segment the data histories
    ins = eul(innow,[2 3]);%theta-phi
    outs = vb(innow,[1 2]);%u-v
    m = 1;%outputs
    r = 1;%inputs
    dt = .01;%sec
    p = 1;
    desp = 'batch';
    
    % fit u(theta)
    [a,b,c,d,g,x0] = okid(m,r,dt,ins(:,1),outs(:,1),desp,p);
    ap = c*a*(c\eye(1));
    bp = c*b;
    cp = eye(1);
    dp = d;
    sysd11 = ss(ap,bp,cp,dp,dt);
    % fit v(phi)
    [a,b,c,d,g,x0] = okid(m,r,dt,ins(:,2),outs(:,2),desp,p);
    ap = c*a*(c\eye(1));
    bp = c*b;
    cp = eye(1);
    dp = d;
    sysd12 = ss(ap,bp,cp,dp,dt);
    
    [a,b,c,d,~,~] = lsqmdl_zeros(m,r,dt,ins(:,1),outs(:,1),desp,p);
    sysd21 = ss(a,b,c,d,dt);
    
    [a,b,c,d,~,~] = lsqmdl_zeros(m,r,dt,ins(:,2),outs(:,2),desp,p);
    sysd22 = ss(a,b,c,d,dt);
    
    SYSC{i,1} = d2c(sysd11);
    SYSC{i,2} = d2c(sysd12);
    SYSC{i+size(t_st,1),1} = d2c(sysd21);
    SYSC{i+size(t_st,1),2} = d2c(sysd22);
    
    SYSD{i,1} = sysd11;
    SYSD{i,2} = sysd12;
    SYSD{i+size(t_st,1),1} = sysd21;
    SYSD{i+size(t_st,1),2} = sysd22;
end

%% feed back the control state histories into each identified model
close all;

FID = fopen([folder '/out.txt'],'w+');
fprintf(FID,' %% Output file for linear model fitting to quadrotor flights\n');
for i = 1:length(SYSC)
    %skip unstable models
    if (SYSC{i,1}.a > 0 || SYSC{i,2}.a > 0)
        continue;
    end
    figure;
    fprintf(FID,'Model %i:\n',i);
    for j = 1:size(t_st,1)
        innow = find(t > t_st(j,1) & t < t_st(j,2));
        subplot(2,size(t_st,1),j);
        
        plot(t(innow),vb(innow,[1 2]),'-','linewidth',2);
        
        %simulate with model
        x0 = vb(innow(1),[1 2])';
        u = eul(innow,[2 3]);
        ypred = zeros(size(vb(innow,[1 2])));
        for k = 1:length(innow)
            %store
            ypred(k,:) = x0';
            %propagate
            x0(1) = SYSD{i,1}.a*x0(1) + SYSD{i,1}.b*u(k,1);
            x0(2) = SYSD{i,2}.a*x0(2) + SYSD{i,2}.b*u(k,2);
        end
        hold on;
        tilt = sprintf(['velocity histories for trial ' num2str(j) '\n model ' num2str(i)]);
        title(tilt);
        plot(t(innow),ypred,'--','linewidth',2);
        legend('u','v');
        
        %plot control
        subplot(2,size(t_st,1),j+size(t_st,1));
        plot(t(innow),r2d*u,'-','linewidth',2);
        legend('\theta','\phi');
        ylabel('deg');
        
        % write out mean squared error
        MSQ = 1/length(ypred)*sum((ypred-vb(innow,[1 2])).^2);
        fprintf(FID,'Trial %i: %10.4f %10.4f\n', j, MSQ );
    end
    fprintf(FID,'\n');
    set(gcf,'position',[231 375 775 425]);
end
fclose(FID);
%% COMPUTE THE DRAG COEFFICIENTS FOR EACH CASE
% check the B matrix entires as well, since these should both be = 1g
format short g

coefu = zeros(2*size(t_st,1),1);
coefv = coefu;
gterm = zeros(2*size(t_st,1),2);

for i = 1:length(coefu)
    coefu(i) = SYSC{i,1}.a;
    coefv(i) = SYSC{i,2}.a;
    
    %both of these should be positive, as defined here:
    gterm(i,1) = SYSC{i,1}.b;
    gterm(i,2) = -SYSC{i,2}.b;
end

figure;
subplot(121);
hist([coefu;coefv]);
title('drag coefficient')

subplot(122);
hist(reshape(gterm,[],1));
title('gravity term magnitude');