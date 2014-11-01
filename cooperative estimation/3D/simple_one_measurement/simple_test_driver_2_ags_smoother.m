%% discrete-time RTS smoother

clear variables;
close all;

addpath('../../2D');
addpath('../');

if ~exist('data_3d.mat','file');
    disp('Error: generate data first');
    return;
end

load('data_3d.mat');

% compute truth
qji = zeros(length(T),4);
for k = 1:length(T)
    Cin = attparsilent(Yc{1}(k,7:10)',[6 1]);
    Cjn = attparsilent(Yc{2}(k,7:10)',[6 1]);
    Cji = Cjn*Cin';
    qji_tr = attparsilent(Cji,[1 6]);
    qji(k,:) = qji_tr';
end
qji = quatmin(qji);

xh = cell(2,1);
Ph = cell(2,1);

tv = sort([T T T(end)+Ts]);

% measurement error in other agent's omega
Qk = diag(1e-2*Ts^2*[1 1 1]);

% generate IMU histories
W = zeros(length(T),6);
for k = 1:length(T)
    W(k,1:3) = Yc{1}(k,11:13) + randn(1,3).*diag(sqrtm(Qk)/Ts)';
    W(k,4:6) = Yc{2}(k,11:13) + randn(1,3).*diag(sqrtm(Qk)/Ts)';
end

%% initialize
for i = 1:2
    xh{i} = zeros(length(tv),4);
    Ph{i} = zeros(length(tv),16);
    %xh{i}(1,:) = [1 0 0 0];
    if exist('xxh','var')
        xh{i}(1,:) = xxh{i}(1,:);
        Ph{i}(1,:) = Ph{i}(1,:);
    else
        xh{i}(1,:) = randn(4,1);xh{i}(1,:) = xh{i}(1,:)./norm(xh{i}(1,:));
        Ph{i}(1,:) = reshape( eye(4), 16,1)';
    end
end

%% forwards iteration
Rx = zeros(6);
% measurement error
errnom = [0 err_dev err_dev].^2;

for j = 1:2
    for k = 1:length(T)
        %% update        
        xhat = xh{j}(2*k-1,:)';
        Pk = reshape(Ph{j}(2*k-1,:)',4,4);
        
        ymeas = zeros(3,1);
        
        %Cji = eye(3) - 2*xhat(1)*squiggle(xhat(2:4)) + 2*squiggle(xhat(2:4))^2;
        Cji = attparsilent(xhat,[6 1]);
        
        % my meas of him
        rji_i = meas{j}(k,(1:3))';
        if j == 1
            % his meas of me
            rij_j = meas{2}(k,(1:3))';
        else 
            rij_j = meas{1}(k,(1:3))';
        end
        % error
        ydiff = rij_j + Cji*rji_i;
        
        % measurement gradient
        Hk = zeros(3,4);
        Hk(:,1) = -2*squiggle(xhat(2:4))*rji_i;
        Hk(:,2:4) = 2*xhat(1)*squiggle(rji_i) - 2*squiggle(xhat(2:4))*squiggle(rji_i) - 2*squiggle( squiggle(xhat(2:4))*rji_i );
        Hk = -Hk;
        
        Crt_b = zeros(3);
        Crt_b(1,:) = rji_i';
        
        % compute an arbitrary frame transfer from the frame aligned with
        % the measurement vector to the body frame
        % the resulting covariance is independent of the other two axes we
        % choose here
        r2 = cross(rji_i,[1;0;0]);r2 = r2./norm(r2);
        r3 = cross(rji_i,r2);
        Crt_b(2,:) = r2';
        Crt_b(3,:) = r3';
        
        % error covariance associated with rji_i
        Rx(1:3,1:3) = Crt_b'*diag(errnom)*Crt_b;
        
        % repeat for rij_j2
        Crt_b = zeros(3);
        Crt_b(1,:) = rij_j';
        r2 = cross(rij_j,[1;0;0]);r2 = r2./norm(r2);
        r3 = cross(rij_j,r2);
        Crt_b(2,:) = r2';
        Crt_b(3,:) = r3';
        
        % error covariance associated with rij_j, in its frame
        Rx(4:6,4:6) = Crt_b'*diag(errnom)*Crt_b;
        
        % jacobian associated with the measurement
        J = zeros(3,6);
        J(1:3,1:3) = -Cji;
        J(1:3,4:6) = -eye(3);
        
        % actual 'measurement' covariance
        Ry = J*Rx*J';
        
        % Kalman gain
        Kk = Pk*Hk'*((Hk*Pk*Hk'+Ry)\eye(3));
        
        %update
        xhat = xhat + Kk*ydiff;
        Pk = (eye(4) - Kk*Hk)*Pk;
        
        % re-normalize
        xhat = xhat./norm(xhat);
        
        % store
        xh{j}(2*k,:) = xhat';
        Ph{j}(2*k,:) = reshape(Pk,16,1)';% this is P^+_fk
        %% propagate
        %play it forward
        %xh{j}(2*k+1,:) = xh{j}(2*k,:);
        %Ph{j}(2*k+1,:) = Ph{j}(2*k,:);
        
        xhat = xh{j}(2*k,:)';
        Pk = reshape(Ph{j}(2*k,:)',4,4);
        
        if j == 1
            Cji = attparsilent(xhat,[6 1]);
            % relative angular velocity in j frame
            w = W(k,4:6)'- Cji*W(k,1:3)';
        else
            Cji = attparsilent(xhat,[6 1]);
            % relative angular velocity in j frame
            w = W(k,1:3)'- Cji*W(k,4:6)';
        end
        
        A = 0.5*[ -xhat(2:4)';xhat(1)*eye(3) + squiggle(xhat(2:4))];
        xdot = A*w;
        
        % need the gradient F
        Fk = zeros(4,4);
        Fk(2:4,1) = 0.5*eye(3)*w;
        Fk(:,2) = 0.5*[-1 0 0;squiggle([1;0;0])]*w;
        Fk(:,3) = 0.5*[0 -1 0;squiggle([0;1;0])]*w;
        Fk(:,4) = 0.5*[0 0 -1;squiggle([0;0;1])]*w;
        % account for discretization
        Fk = eye(4) + Ts*Fk;
        
        % need the G matrix
        Gk = A;
        
        % update
        xhat = xhat + Ts*xdot;
        Pk = Fk*Pk*Fk' + Gk*Qk*Gk';
        
        % re-normalize
        xhat = xhat./norm(xhat);
        
        % store
        xh{j}(2*k+1,:) = xhat';
        Ph{j}(2*k+1,:) = reshape(Pk,16,1)';% this is P^-_f(k+1)
    end
end
%% backwards iteration

xxh = cell(2,1);
PPh = cell(2,1);

for i = 1:2
    xxh{i} = zeros(length(T),4);
    PPh{i} = zeros(length(T),16);
end

%initialize
xxh{1}(end,:) = xh{1}(end,:);
PPh{1}(end,:) = Ph{1}(end,:);
xxh{2}(end,:) = xh{2}(end,:);
PPh{2}(end,:) = Ph{2}(end,:);

for j = 1:2
    for k = length(T):-1:2
        %% backwards iteration
        Pfk = reshape(Ph{j}(2*k+1,:),4,4);%P^-_fk+1
        Ppfk = reshape(Ph{j}(2*k,:),4,4);%P^+_fk
        
        xfk = xh{j}(2*k+1,:)';%x^-_fk+1
        xpfk = xh{j}(2*k,:)';%x^+_fk
        
        xhat = xxh{j}(k,:)';
        Pk = reshape(PPh{j}(k,:)',4,4);
        
        if j == 1
            Cji = attparsilent(xhat,[6 1]);
            % relative angular velocity in j frame
            w = W(k,4:6)'- Cji*W(k,1:3)';
        else
            Cji = attparsilent(xhat,[6 1]);
            % relative angular velocity in j frame
            w = W(k,1:3)'- Cji*W(k,4:6)';
        end
        
        %A = 0.5*[ -xhat(2:4)';xhat(1)*eye(3) + squiggle(xhat(2:4))];
        
        % need the gradient F
        Fk = zeros(4,4);
        Fk(2:4,1) = 0.5*eye(3)*w;
        Fk(:,2) = 0.5*[-1 0 0;squiggle([1;0;0])]*w;
        Fk(:,3) = 0.5*[0 -1 0;squiggle([0;1;0])]*w;
        Fk(:,4) = 0.5*[0 0 -1;squiggle([0;0;1])]*w;
        % account for discretization
        Fk = eye(4) + Ts*Fk;
        
        % gain
        Kk = Ppfk*Fk'*(Pfk\eye(4));
        
        % backstep the estimate
        Pk = Ppfk + Kk*(Pk-Pfk)*Kk';
        xhat = xpfk + Kk*(xhat-xfk);
        
        % re-normalize
        xhat = xhat./norm(xhat);
        
        % store
        xxh{j}(k-1,:) = xhat';
        PPh{j}(k-1,:) = reshape(Pk,16,1)';
    end
end

%% figures
xxh{1} = quatmin(xxh{1},qji);
xxh{2} = quatmin(xxh{2},[-qji(:,1) qji(:,2:4)]);

Pdiag = 1:5:16;

% compute error quaternions
q_err1 = zeros(length(T),1);
q_err2 = zeros(length(T),1);
for i = 1:length(T)
    %truth
    Cji = attparsilent(qji(i,:)',[6 1]);
    Cji_1 = attparsilent(xxh{1}(i,:)',[6 1]);
    Cij_2 = attparsilent(xxh{2}(i,:)',[6 1]);
    % error DCMs
    Ct_1 = Cji_1'*Cji;
    Ct_2 = Cij_2'*Cji';
    %error quaternions
    gar1 = attparsilent(Ct_1,[1 2]);
    q_err1(i) = gar1(1,2);
    gar2 = attparsilent(Ct_2,[1 2]);
    q_err2(i) = gar2(1,2);
end

% compute the error w/ forward KF to confirm we're doing better
qji_in = interp1(T,qji,tv);

xh{1} = quatmin(xh{1},qji_in);
xh{2} = quatmin(xh{2},[-qji_in(:,1) qji_in(:,2:4)]);

% compute error quaternions
q_errf1 = zeros(length(tv),1);
q_errf2 = zeros(length(tv),1);
for i = 1:length(tv)
    %truth
    Cji = attparsilent(qji_in(i,:)',[6 1]);
    Cji_1 = attparsilent(xh{1}(i,:)',[6 1]);
    Cij_2 = attparsilent(xh{2}(i,:)',[6 1]);
    % error DCMs
    Ct_1 = Cji_1'*Cji;
    Ct_2 = Cij_2'*Cji';
    %error quaternions
    gar1 = attparsilent(Ct_1,[1 2]);
    q_errf1(i) = gar1(1,2);
    gar2 = attparsilent(Ct_2,[1 2]);
    q_errf2(i) = gar2(1,2);
end

figure;
for k = 1:4
    subplot(2,2,k);
    plot(T,xxh{1}(:,k),'--x');
    hold on;
    plot(T,xxh{1}(:,k) + 2*sqrt(PPh{1}(:,Pdiag(k))),'r--');
    plot(T,xxh{1}(:,k) - 2*sqrt(PPh{1}(:,Pdiag(k))),'r--');
    plot(T,qji(:,k),'k-','linewidth',2);
    set(gca,'ylim',[-1 1]);
end

figure;
for k = 1:4
    subplot(2,2,k);
    plot(T,xxh{2}(:,k),'--x');
    hold on;
    plot(T,xxh{2}(:,k) + 2*sqrt(PPh{2}(:,Pdiag(k))),'r--');
    plot(T,xxh{2}(:,k) - 2*sqrt(PPh{2}(:,Pdiag(k))),'r--');
    if k == 1
        plot(T,-qji(:,k),'k-','linewidth',2);
    else
        plot(T,qji(:,k),'k-','linewidth',2);
    end
    set(gca,'ylim',[-1 1]);
end

figure;

subplot(211);
plot(T, q_err1);
hold on;
plot(tv,q_errf1,'r--');
legend('smoothed estimate','additive EKF estimate');
ylabel('agent 1 pointing error (rad)');

subplot(212);
plot(T, q_err2);
hold on;
plot(tv,q_errf2,'r--');
ylabel('agent 2 pointing error (rad)');