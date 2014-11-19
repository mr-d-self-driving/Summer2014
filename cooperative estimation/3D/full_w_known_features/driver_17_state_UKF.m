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
% add noise - will not work unless this is run first
% noise stdevs are set in this script
add_noise;

%% process

% feature visibility in degrees
FEATURE_FOV_BEARING = [45 45];
FEATURE_FOV_DECLIN = [45 45];
FEATURE_RANGE_MIN = [0.5 0.5];% metres
FEATURE_RANGE_MAX = [10 10];%metres

% feature sensing error
feature_angle_err = .01;%rads, stdev
feature_range_err = .1;%metres

% process noise
% assume both agents have same IMU noise: [gyro_i gyro_j acc_i acc_j]
% terms correspond to: [noise on gyro_i, noise associated with omega_j,
% noise on acc_i, and noise associated with acc_j]. [2] and [4] encompass
% the full range of variable values
Qk = diag([gyro_noise^2*ones(1,3) (1/3)^2*[1 1 1] accel_noise^2*ones(1,3) (1/3)^2*[1 1 1]]);

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
    xh{i} = zeros(length(tv),17);
    Ph{i} = zeros(length(tv),289);
    % random quaternion
    xh{i}(1,7:10) = randn(4,1);xh{i}(1,7:10) = xh{i}(1,7:10)./norm(xh{i}(1,7:10));% inertial attitude
    xh{i}(1,1:3) = randn(3,1).*[10;10;10];% inertial position, inertial frame
    xh{i}(1,4:6) = randn(3,1);% inertial velocity, body frame
    Ph{i}(1,:) = reshape( diag([ones(1,6) 0.1*ones(1,4) ones(1,3) 0.1*ones(1,4)]) + 1e-6*ones(17), 289,1)';
end

%% use exact initial conditions
% xh{1}(1,14:17) = qji(1,:);
% xh{1}(1,11:13) = rji_i_tr(1,:);
% xh{2}(1,14:17) = qji(1,:);xh{2}(1,14) = -xh{2}(1,1);
% xh{2}(1,11:13) = rij_j_tr(1,:);

% measurement error
Rhalf = diag([range_dev err_dev err_dev range_dev err_dev err_dev]).^2;
magnom = [1e-8 mag_dev mag_dev];
% Rx is the sensor noise for nominal set of measurements, i.e. the ones we
% always get
Rx = zeros(12);
Rx(1:6,1:6) = Rhalf;

tic;
for j = 1:2
    for k = 1:length(T)-1
        %% update
        xhat = xh{j}(k,:)';
        Pk = reshape(Ph{j}(k,:)',17,17);
        
        rin = xhat(1:3);
        qin = xhat(7:10);
        Cin = attparsilent(qin,[6 1]);
        
        rin_true = Yc{j}(k,1:3)';
        qin_true = Yc{j}(k,7:10)';
        Cin_true = attparsilent(qin_true,[6 1]);
        if j == 1
            notj = 2;
        else
            notj = 1;
        end
        rjn_true = Yc{notj}(k,1:3)';
        qjn_true = Yc{notj}(k,7:10)';
        Cjn_true = attparsilent(qjn_true,[6 1]);
        
        % measurements
        
        % determine which KNOWN features I can see
        m1 = 0;
        xyz_known_i = zeros(M,3);
        known_features_used_i = zeros(M,1);
        for mm = 1:M
            % compute the i frame TRUE position vector to feature
            rki = Cin_true*(XYZ_KNOWN(mm,:)' - rin_true);
            % compute range/bearing/declination
            rbd = vector2polar(rki);
            
            % if this is satisfied, we can see the feature
            if rbd(1) < FEATURE_RANGE_MAX(j) && rbd(1) > FEATURE_RANGE_MIN(j) && abs(rbd(2)) < d2r*(FEATURE_FOV_BEARING(j)) && abs(rbd(3)) < d2r*(FEATURE_FOV_DECLIN(j))
                m1 = m1 + 1;
                % generate the measurement of this feature
                % error angle
                err_angle = randn*feature_angle_err;
                % error axis of rotation
                a_error = randn(3,1);a_error = a_error./norm(a_error);
                % range error
                range_err = randn*feature_range_err;
                Cerr_i = attparsilent([a_error [err_angle;0;0]],[2 1]);
                % measurement with angle error and range error
                rmeas = (Cerr_i*rki)*(1+range_err/norm(rki));
                xyz_known_i(m1,:) = vector2polar(rmeas);
                known_features_used_i(m2) = mm;
            end
        end
        xyz_known_i(m1+1:end,:) = [];
        known_features_used_i(m1+1:end) = [];
        
        % determine which features the other agent can see
        m2 = 0;
        xyz_known_j = zeros(M,3);
        known_features_used_j = zeros(M,1);
        for mm = 1:M
            % compute the j frame TRUE position vector to feature
            rkj = Cjn_true*(XYZ_KNOWN(mm,:)' - rjn_true);
            % compute range/bearing/declination
            rbd = vector2polar(rkj);
            
            % if this is satisfied, we can see the feature
            if rbd(1) < FEATURE_RANGE_MAX(notj) && rbd(1) > FEATURE_RANGE_MIN(notj) && abs(rbd(2)) < d2r*(FEATURE_FOV_BEARING(notj)) && abs(rbd(3)) < d2r*(FEATURE_FOV_DECLIN(notj))
                m2 = m2 + 1;
                % generate the measurement of this feature
                % error angle
                err_angle = randn*feature_angle_err;
                % error axis of rotation
                a_error = randn(3,1);a_error = a_error./norm(a_error);
                % range error
                range_err = randn*feature_range_err;
                Cerr_j = attparsilent([a_error [err_angle;0;0]],[2 1]);
                % measurement with angle error and range error
                rmeas = (Cerr_j*rkj)*(1+range_err/norm(rkj));
                xyz_known_j(m2,:) = vector2polar(rmeas);
                known_features_used_j(m2) = mm;
            end
        end
        xyz_known_j(m2+1:end,:) = [];
        known_features_used_j(m2+1:end) = [];
        
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
        
        % measurement errors
        Rx = zeros(12+3*(m1+m2));
        Rx(1:6,1:6) = Rhalf;
        
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
        
        % error covariance for range/bearing/declination of agent i
        Rx(12 + (1:m1*3),12 + (1:m1*3)) = diag(repmat([feature_range_err feature_angle_err feature_angle_err],1,m1));
        % error covariance for range/bearing/declination of agent j
        Rx(12 + 3*m1 + (1:m2*3),12 + 3*m1 + (1:m2*3)) = diag(repmat([feature_range_err feature_angle_err feature_angle_err],1,m2));
        
        uk = [wi;ai;mag_i;m1; reshape(XYZ_KNOWN(known_features_used_i,:)',[],1); m2;reshape(XYZ_KNOWN(known_features_used_j,:)',[],1) ];
        
        yk = [sqrt(sum(rji_i.^2));atan2(rji_i(2),rji_i(1));atan2(rji_i(3),sqrt(sum(rji_i(1:2).^2))); ...
		sqrt(sum(rij_j.^2));atan2(rij_j(2),rij_j(1));atan2(rij_j(3),sqrt(sum(rij_j(1:2).^2))); ...
        mag_j;
        reshape(xyz_known_i',[],1);
        reshape(xyz_known_j',[],1)];
    
        Pvk = Qk;
        
        Pnk = Rx;
        
        [xp,Pp] = ukf_update(xhat,Pk,Pvk,Pnk,uk,yk,@update_eq_17_state,@measurement_eq_17_state);
        
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
    title( 'Agent 1 relative velocity estimate');
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
    title( 'Agent 2 relative velocity estimate');
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
    title( 'Agent 1 relative position estimate');
end
set(gcf,'position',[200 275 1300 625])

figure;
for k = 1:3
    subplot(3,1,k);
    plot(tv,xh{2}(:,k+4));
    hold on;
    plot(tv,xh{2}(:,k+4) + 3*sqrt(Ph{2}(:,Pdiag(k+4))),'r--');
    plot(tv,xh{2}(:,k+4) - 3*sqrt(Ph{2}(:,Pdiag(k+4))),'r--');
    plot(tv,rij_j_tr(:,k),'k-');
    title( 'Agent 2 relative position estimate');
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
set(gcf,'position',[200 275 1300 625])

% plot angular velocity estimates
figure;
for k = 1:3
    subplot(3,2,2*k-1);
    plot(tv,xh{1}(:,13+k));
    hold on;
    plot(tv,xh{1}(:,13+k) + 3*sqrt(Ph{1}(:,Pdiag(13+k))),'r--');
    plot(tv,xh{1}(:,13+k) - 3*sqrt(Ph{1}(:,Pdiag(13+k))),'r--');
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
set(gcf,'position',[200 275 1300 625])
