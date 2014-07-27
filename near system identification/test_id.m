%% test_id
% load the data
% then call OKID/ LSQ methods to fit

if ~exist('data.mat','file');
    linear_id;
end
clear variables;
close all;

load('data.mat');
if ~exist('wb','var')
    
    % compute the angular velocity history from quaternion and quat rate
    % assume the scalar part of the quaternion is LAST
    % compute the body-frame velocities as well
    
    wb = zeros(length(t),3);
    eul = zeros(length(t),3);
    vb = zeros(length(t),3);
    
    for i = 1:length(t)
        B0 = qb(i,4);
        Bv = qb(i,1:3)';
        
        B = 2*[-Bv eye(3)*B0-squiggle(Bv)];
        
        Bdot = dqb(i,[4 1:3])';
        
        wb(i,:) = (B*Bdot)';
        
        x = attpar([B0;Bv],[6 4],struct('seq',[3 2 1]'));
        
        eul(i,:) = x(:,1)';%yaw-pitch-roll stored
        % mod angles so all roll and yaw angles are between /pm pi
        eul(i,eul(i,:) > pi) = eul(i,eul(i,:) > pi) - 2*pi;
        
        C = attpar([B0;Bv],[6 1]);
        
        vb(i,:) = vn(i,:)*C';
    end
    
    save('data.mat','vb','wb','eul','-append');
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

t_st = [19.2 24.0;
    27.2 32.01;
    27.2 52;
    19.2 32.01];
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
    
    [a,b,c,d,g,x0] = okid(m,r,dt,ins(:,1),outs(:,1),desp,p);
    ap = c*a*(c\eye(1));
    bp = c*b;
    cp = eye(1);
    dp = d;
    sysd11 = ss(ap,bp,cp,dp,dt);
    
    [a,b,c,d,g,x0] = okid(m,r,dt,ins(:,2),outs(:,2),desp,p);
    ap = c*a*(c\eye(1));
    bp = c*b;
    cp = eye(1);
    dp = d;
    sysd12 = ss(ap,bp,cp,dp,dt);
    
    [a,b,c,d,~,xc] = lsqmdl_zeros(m,r,dt,ins(:,1),outs(:,1),desp,p);
    sysd21 = ss(a,b,c,d,dt);
    
    [a,b,c,d,~,xc] = lsqmdl_zeros(m,r,dt,ins(:,2),outs(:,2),desp,p);
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

FID = fopen('out.txt','w+');
fprintf(FID,' %% Output file for linear model fitting to quadrotor flights\n');
for i = 1:length(SYSC)
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
end
fclose(FID);
%% COMPUTE THE DRAG COEFFICIENTS FOR EACH CASE
% check the B matrix entires as well, since these should both be = 1g

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