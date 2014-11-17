% no IMU sharing
% has magnetometer

clear variables;
close all;

global Ts;

addpath('../../2D');
addpath('../');

if ~exist('data_3d.mat','file');
    disp('Error: generate data first');
    return;
end

load('data_3d.mat');

%% process

% measurement error in IMU
% assume both agents have same IMU noise: [gyro_i gyro_j acc_i acc_j]
Qk = diag([1e-4*ones(1,3) (0.05/3)^2*[1 1 1] 1e-2*ones(1,3) (0.05/3)^2*[1 1 1]]);

% generate IMU histories
W = zeros(length(T),6);% ang. vel histories
A = zeros(length(T),6);% linear acc. histories
for k = 1:length(T)
    Cin = attparsilent(Yc{1}(k,7:10)',[6 1]);
    Cjn = attparsilent(Yc{2}(k,7:10)',[6 1]);
    
    W(k,1:3) = Yc{1}(k,11:13) + randn(1,3).*diag(sqrt(Qk(1:3,1:3)))';
    W(k,4:6) = Yc{2}(k,11:13) + randn(1,3).*diag(sqrt(Qk(1:3,1:3)))';
    A(k,1:3) = Yc{1}(k,17:19)*Cin' + randn(1,3).*diag(sqrt(Qk(7:9,7:9)))';
    A(k,4:6) = Yc{2}(k,17:19)*Cjn' + randn(1,3).*diag(sqrt(Qk(7:9,7:9)))';
end

% compute truth
qji = zeros(length(T),4);
vji_i = zeros(length(T),3);
vij_j = zeros(length(T),3);
rji_i_tr = zeros(length(T),3);
rij_j_tr = zeros(length(T),3);
for k = 1:length(T)
    Cin = attparsilent(Yc{1}(k,7:10)',[6 1]);
    Cjn = attparsilent(Yc{2}(k,7:10)',[6 1]);
    Cji = Cjn*Cin';
    qji_tr = attparsilent(Cji,[1 6]);
    qji(k,:) = qji_tr';
    % agent 1 relative velocity
    vji_i(k,:) = Cin*(Yc{2}(k,4:6)' - Yc{1}(k,4:6)');
    % agent 2 relative velocity
    vij_j(k,:) = Cjn*(Yc{1}(k,4:6)' - Yc{2}(k,4:6)');
    % agent 1 relative position
    rji_i_tr(k,:) = Cin*(Yc{2}(k,1:3)' - Yc{1}(k,1:3)');
    % agent 2 relative position
    rij_j_tr(k,:) = Cjn*(Yc{1}(k,1:3)' - Yc{2}(k,1:3)');
end
qji = quatmin(qji);

xh = cell(2,1);
Ph = cell(2,1);

tv = T;

for i = 1:2
    xh{i} = zeros(length(tv),16);
    Ph{i} = zeros(length(tv),256);
    % random quaternion
    xh{i}(1,1:4) = randn(4,1);xh{i}(1,1:4) = xh{i}(1,1:4)./norm(xh{i}(1,1:4));
    xh{i}(1,5:7) = randn(3,1).*[10;10;10];
    xh{i}(1,8:10) = randn(3,1);
    Ph{i}(1,:) = reshape( 1*diag([.1 .1 .1 .1 1 1 1 .1 .1 .1 .1 .1 .1 .1 .1 .1]) + 1e-6*ones(16), 256,1)';
end

%% use exact initial conditions
% xh{1}(1,1:4) = qji(1,:);
% xh{1}(1,5:7) = rji_i_tr(1,:);
% xh{1}(1,8:10) = vji_i(1,:);
% xh{2}(1,1:4) = qji(1,:);xh{2}(1,1) = -xh{2}(1,1);
% xh{2}(1,5:7) = rij_j_tr(1,:);
% xh{2}(1,8:10) = vij_j(1,:);

% measurement error
Rhalf = diag([range_dev err_dev err_dev range_dev err_dev err_dev]).^2;
magnom = [1e-8 mag_dev mag_dev];
Rx = zeros(12);
Rx(1:6,1:6) = Rhalf;

tic;
for j = 1:2
    for k = 1:length(T)-1
        %% update
        xhat = xh{j}(k,:)';
        Pk = reshape(Ph{j}(k,:)',16,16);
        
        if j == 1
            % my measured angular velocity
            wi = W(k,1:3)';
            ai = A(k,1:3)';
        else
            % my measured angular velocity
            wi = W(k,4:6)';
            ai = A(k,4:6)';
        end
        if j == 1
            % his meas of me
            rij_j = meas{2}(k,(1:3))';
            % his magnetometer
            mag_j = meas{2}(k,4:6)';
        else
            rij_j = meas{1}(k,(1:3))';
            % his magnetometer
            mag_j = meas{1}(k,4:6)';
        end
        
        % my meas of him
        rji_i = meas{j}(k,(1:3))';
        % my magnetometer
        mag_i = meas{j}(k,4:6)';
        
        % error for my magnetometer
        Crt_b = zeros(3);
        Crt_b(1,:) = mag_i';
        r2 = cross(mag_i,[1;0;0]);r2 = r2./norm(r2);
        r3 = cross(mag_i,r2);
        Crt_b(2,:) = r2';
        Crt_b(3,:) = r3';
        % error covariance associated with mag_i, in its frame
        Rx(7:9,7:9) = Crt_b'*diag(magnom)*Crt_b;

        % repeat for his magnetometer
        Crt_b = zeros(3);
        Crt_b(1,:) = mag_j';
        r2 = cross(mag_j,[1;0;0]);r2 = r2./norm(r2);
        r3 = cross(mag_j,r2);
        Crt_b(2,:) = r2';
        Crt_b(3,:) = r3';
        % error covariance associated with mag_j, in its frame
        Rx(10:12,10:12) = Crt_b'*diag(magnom)*Crt_b;
        
        uk = [wi;ai;mag_i];
        
        yk = [sqrt(sum(rji_i.^2));atan2(rji_i(2),rji_i(1));atan2(rji_i(3),sqrt(sum(rji_i(1:2).^2))); ...
		sqrt(sum(rij_j.^2));atan2(rij_j(2),rij_j(1));atan2(rij_j(3),sqrt(sum(rij_j(1:2).^2))); ...
        mag_j];
        Pvk = Qk;
        
        Pnk = Rx;
        
        [xp,Pp] = ukf_update(xhat,Pk,Pvk,Pnk,uk,yk,@update_eq_all,@measurement_eq_all);
        
        if any(any(isnan(Pp)))
            disp('Error: NaN in covariance output');
            break;
        end
        
        % store
        xh{j}(k+1,:) = xp';
        Ph{j}(k+1,:) = reshape(Pp,256,1)';

        if ~mod(k-1,100)
            etaCalc((j-1)*length(T) + k,2*length(T),toc);
        end
    end
end
toc;

%% evaluate results

close all;
figure;

Pdiag = 1:17:256;

qji_in = interp1(T,qji,tv);

xh{1}(:,1:4) = quatmin(xh{1}(:,1:4),qji_in);
xh{2}(:,1:4) = quatmin(xh{2}(:,1:4),[-qji_in(:,1) qji_in(:,2:4)]);

for k = 1:4
    subplot(2,2,k);
    plot(tv,xh{1}(:,k),'--x');
    hold on;
    plot(tv,xh{1}(:,k) + 3*sqrt(Ph{1}(:,Pdiag(k))),'r--');
    plot(tv,xh{1}(:,k) - 3*sqrt(Ph{1}(:,Pdiag(k))),'r--');
    plot(T,qji(:,k),'k-','linewidth',2);
    set(gca,'ylim',[-1 1]);
end
set(gcf,'position',[200 275 1300 625])

figure;
for k = 1:4
    subplot(2,2,k);
    plot(tv,xh{2}(:,k),'--x');
    hold on;
    plot(tv,xh{2}(:,k) + 3*sqrt(Ph{2}(:,Pdiag(k))),'r--');
    plot(tv,xh{2}(:,k) - 3*sqrt(Ph{2}(:,Pdiag(k))),'r--');
    if k == 1
        plot(T,-qji(:,k),'k-','linewidth',2);
    else
        plot(T,qji(:,k),'k-','linewidth',2);
    end
    set(gca,'ylim',[-1 1]);
end
set(gcf,'position',[200 275 1300 625])

% compute error quaternions
q_err1 = zeros(length(tv),1);
q_err2 = zeros(length(tv),1);
for i = 1:length(tv)
    %truth
    Cji = attpar(qji_in(i,:)',[6 1]);
    Cji_1 = attpar(xh{1}(i,:)',[6 1]);
    Cij_2 = attpar(xh{2}(i,:)',[6 1]);
    % error DCMs
    Ct_1 = Cji_1'*Cji;
    Ct_2 = Cij_2'*Cji';
    %error quaternions
    gar1 = attpar(Ct_1,[1 2]);
    q_err1(i) = gar1(1,2);
    gar2 = attpar(Ct_2,[1 2]);
    q_err2(i) = gar2(1,2);
end

% plot velocities
figure;
for k = 1:3
    subplot(3,1,k);
    plot(tv,xh{1}(:,k+7));
    hold on;
    plot(tv,xh{1}(:,k+7) + 3*sqrt(Ph{1}(:,Pdiag(k+7))),'r--');
    plot(tv,xh{1}(:,k+7) - 3*sqrt(Ph{1}(:,Pdiag(k+7))),'r--');
    plot(tv,vji_i(:,k),'k-');
    title( 'Agent 1 velocity estimate');
end
set(gcf,'position',[200 275 1300 625])

figure;
for k = 1:3
    subplot(3,1,k);
    plot(tv,xh{2}(:,k+7));
    hold on;
    plot(tv,xh{2}(:,k+7) + 3*sqrt(Ph{2}(:,Pdiag(k+7))),'r--');
    plot(tv,xh{2}(:,k+7) - 3*sqrt(Ph{2}(:,Pdiag(k+7))),'r--');
    plot(tv,vij_j(:,k),'k-');
    title( 'Agent 2 velocity estimate');
end
set(gcf,'position',[200 275 1300 625])

% plot positions
figure;
for k = 1:3
    subplot(3,1,k);
    plot(tv,xh{1}(:,k+4));
    hold on;
    plot(tv,xh{1}(:,k+4) + 3*sqrt(Ph{1}(:,Pdiag(k+4))),'r--');
    plot(tv,xh{1}(:,k+4) - 3*sqrt(Ph{1}(:,Pdiag(k+4))),'r--');
    plot(tv,rji_i_tr(:,k),'k-');
    title( 'Agent 1 position estimate');
end
set(gcf,'position',[200 275 1300 625])

% plot acceleration estimates
figure;
for k = 1:3
    subplot(3,2,2*k-1);
    plot(tv,xh{1}(:,10+k));
    hold on;
    plot(tv,xh{1}(:,10+k) + 3*sqrt(Ph{1}(:,Pdiag(10+k))),'r--');
    plot(tv,xh{1}(:,10+k) - 3*sqrt(Ph{1}(:,Pdiag(10+k))),'r--');
    plot(tv,A(:,k+3),'k-');
    title('Agent 1 estimate of 2''s acceleration');
    
    subplot(3,2,2*k);
    plot(tv,xh{2}(:,10+k));
    hold on;
    plot(tv,xh{2}(:,10+k) + 3*sqrt(Ph{2}(:,Pdiag(10+k))),'r--');
    plot(tv,xh{2}(:,10+k) - 3*sqrt(Ph{2}(:,Pdiag(10+k))),'r--');
    plot(tv,A(:,k),'k-');
    title('Agent 2 estimate of 1''s acceleration');
end

% plot angular velocity estimates
figure;
for k = 1:3
    subplot(3,2,2*k-1);
    plot(tv,xh{1}(:,13+k));
    hold on;
    plot(tv,xh{1}(:,13+k) + 3*sqrt(Ph{1}(:,Pdiag(10+k))),'r--');
    plot(tv,xh{1}(:,13+k) - 3*sqrt(Ph{1}(:,Pdiag(10+k))),'r--');
    plot(tv,W(:,k+3),'k-');
    title('Agent 1 estimate of 2''s angular velocity');
    
    subplot(3,2,2*k);
    plot(tv,xh{2}(:,13+k));
    hold on;
    plot(tv,xh{2}(:,13+k) + 3*sqrt(Ph{2}(:,Pdiag(13+k))),'r--');
    plot(tv,xh{2}(:,13+k) - 3*sqrt(Ph{2}(:,Pdiag(13+k))),'r--');
    plot(tv,W(:,k),'k-');
    title('Agent 2 estimate of 1''s angular velocity');
end
