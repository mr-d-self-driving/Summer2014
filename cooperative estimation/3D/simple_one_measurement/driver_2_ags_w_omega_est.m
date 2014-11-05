%% tries to use the current agent's angular velocity measurement and
% an estimate of the other's angular velocity to propagate
% do not know if it will or can work.

clear variables;
close all;

addpath('../../2D');
addpath('../');

if ~exist('data_3d.mat','file');
    disp('Error: generate data first');
    return;
end

load('data_3d.mat');

%% process

% measurement error in other agent's omega
Qk = diag([1e-6*[1 1 1] ...% component for measured ang. vel uncertainty
    (sqrt(10))^2*[1 1 1]]);% component for estimated ang. vel uncertainty

% generate IMU histories
W = zeros(length(T),6);
for k = 1:length(T)
    W(k,1:3) = Yc{1}(k,11:13) + randn(1,3).*diag(sqrtm(Qk(1:3,1:3)))';
    W(k,4:6) = Yc{2}(k,11:13) + randn(1,3).*diag(sqrtm(Qk(1:3,1:3)))';
end

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

for i = 1:2
    xh{i} = zeros(length(tv),7);
    Ph{i} = zeros(length(tv),49);
    %xh{i}(1,:) = [1 0 0 0];
    xh{i}(1,1:4) = randn(4,1);xh{i}(1,:) = xh{i}(1,:)./norm(xh{i}(1,:));
    xh{i}(1,5:7) = 0;% initialize ang vel to zero. is estimate of j's ang vel in j's frame
    Ph{i}(1,:) = reshape( .01*eye(7), 49,1)';
end

% use exact initial conditions
xh{1}(1,1:4) = qji(1,:);
xh{1}(1,5:7) = Yc{2}(1,11:13);
xh{2}(1,1:4) = qji(1,:);xh{2}(1,1) = -xh{2}(1,1);
xh{2}(1,5:7) = Yc{1}(1,11:13);

% error covariance associated with my measurement of him, and his
% measurement of me
Rx = zeros(6);
% measurement error
errnom = [0 err_dev err_dev].^2;

for j = 1:2
    for k = 1:length(T)
        %% update        
        xhat = xh{j}(2*k-1,:)';
        Pk = reshape(Ph{j}(2*k-1,:)',7,7);
        
        ymeas = zeros(3,1);
        
        % estactualimated i to j frame transform
        Cji = attparsilent(xhat(1:4),[6 1]);
        
        % my meas of him
        rji_i = meas{j}(k,(1:3))';
        if j == 1
            % his meas of me
            rij_j = meas{2}(k,(1:3))';
        else 
            rij_j = meas{1}(k,(1:3))';
        end
        % (expectation) error
        ydiff = -rij_j - Cji*rji_i;
        
        % measurement gradient
        Hk = zeros(3,7);
        Hk(:,1) = 2*squiggle(xhat(2:4))*rji_i;
        Hk(:,2:4) = -2*xhat(1)*squiggle(rji_i)+2*(squiggle(xhat(2:4))*squiggle(rji_i)+squiggle( squiggle(xhat(2:4))*rji_i ));
        
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
        xhat = xhat + Kk*(-ydiff);
        Pk = (eye(7) - Kk*Hk)*Pk;
        
        % re-normalize
        xhat(1:4) = xhat(1:4)./norm(xhat(1:4));
        
        % store
        xh{j}(2*k,:) = xhat';
        Ph{j}(2*k,:) = reshape(Pk,49,1)';
        %% propagate
        %play it forward
        %xh{j}(2*k+1,:) = xh{j}(2*k,:);
        %Ph{j}(2*k+1,:) = Ph{j}(2*k,:);
        
        xhat = xh{j}(2*k,:)';
        Pk = reshape(Ph{j}(2*k,:)',7,7);
        
        Cji = attparsilent(xhat(1:4),[6 1]);
        if j == 1
            % my angular velocity in my frame
            wi = W(k,1:3)';%Yc{1}(k,11:13)' + randn(3,1).*diag(sqrtm(Qk(1:3,1:3))/Ts);
            % relative angular velocity in j frame
            w = xhat(5:7) - Cji*wi;
        else
            % my angular velocity, measured in my frame
            wi = W(k,4:6)';%Yc{2}(k,11:13)' + randn(3,1).*diag(sqrtm(Qk(1:3,1:3))/Ts);
            % relative angular velocity, in j frame
            w = xhat(5:7) - Cji*wi; % my estimate of his angular velocity is in his reference frame
        end
        
        A = 0.5*[ -xhat(2:4)';xhat(1)*eye(3) + squiggle(xhat(2:4))];
        xdot = [A*w;0;0;0];
        
        % need the gradient F
        bs = squiggle(xhat(2:4));
        wp = xhat(5:7)-wi;
        Fk = zeros(7,7);
        % derivative w.r.t quat_est
        Fk(1:4,1:4) = 0.5*[0 -wp';wp -squiggle(wp)] + [zeros(1,4);2*xhat(1)*bs*wi -xhat(1)^2*squiggle(wi)+squiggle(bs*bs*wi)+bs*squiggle(bs*wi)+bs*bs*squiggle(wi)];
        % derivative w.r.t. omega_est
        Fk(1:4,5:7) = A;
        % account for discretization
        Fk = eye(7) + Ts*Fk;
        
        % need the G matrix
        Gk = zeros(7,6);
        % component for the measured ang. vel error
        Gk(1:4,1:3) = A*Cji;
        % component for the estimated ang. vel uncertainty
        Gk(5:7,4:6) = eye(3);
        % account for discretization
        Gk = Ts*Gk;
        
        % update
        xhat = xhat + Ts*xdot;
        Pk = Fk*Pk*Fk' + Gk*Qk*Gk';
        
        % re-normalize
        xhat(1:4) = xhat(1:4)./norm(xhat(1:4));
        
        % store
        xh{j}(2*k+1,:) = xhat';
        Ph{j}(2*k+1,:) = reshape(Pk,49,1)';
    end
end

%% evaluate results

close all;
figure;

Pdiag = 1:8:49;

qji_in = interp1(T,qji,tv);

xh{1}(:,1:4) = quatmin(xh{1}(:,1:4),qji_in);
xh{2}(:,1:4) = quatmin(xh{2}(:,1:4),[-qji_in(:,1) qji_in(:,2:4)]);

for k = 1:4
    subplot(2,2,k);
    plot(tv,xh{1}(:,k),'--x');
    hold on;
    plot(tv,xh{1}(:,k) + 2*sqrt(Ph{1}(:,Pdiag(k))),'r--');
    plot(tv,xh{1}(:,k) - 2*sqrt(Ph{1}(:,Pdiag(k))),'r--');
    plot(T,qji(:,k),'k-','linewidth',2);
    set(gca,'ylim',[-1 1]);
end

figure;
for k = 1:4
    subplot(2,2,k);
    plot(tv,xh{2}(:,k),'--x');
    hold on;
    plot(tv,xh{2}(:,k) + 2*sqrt(Ph{2}(:,Pdiag(k))),'r--');
    plot(tv,xh{2}(:,k) - 2*sqrt(Ph{2}(:,Pdiag(k))),'r--');
    if k == 1
        plot(T,-qji(:,k),'k-','linewidth',2);
    else
        plot(T,qji(:,k),'k-','linewidth',2);
    end
    set(gca,'ylim',[-1 1]);
end

% compute error quaternions
q_err1 = zeros(length(tv),1);
q_err2 = zeros(length(tv),1);
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
    q_err1(i) = gar1(1,2);
    gar2 = attparsilent(Ct_2,[1 2]);
    q_err2(i) = gar2(1,2);
end
%%
figure;

subplot(211);
plot(tv, q_err1);
ylabel('agent 1 pointing error (rad)');

subplot(212);
plot(tv, q_err2);
ylabel('agent 2 pointing error (rad)');

% angular velocity
w1_interp = interp1(T,Yc{1}(:,11:13),tv);
w2_interp = interp1(T,Yc{2}(:,11:13),tv);
figure;
for k = 1:3
    subplot(3,1,k);
    plot(tv,[w2_interp(:,k) xh{1}(:,k+4)]);
    hold on;
    plot(tv,xh{1}(:,k+4)+3*sqrt(Ph{1}(:,Pdiag(k+4))),'r--');
    plot(tv,xh{1}(:,k+4)-3*sqrt(Ph{1}(:,Pdiag(k+4))),'r--');
    ylabel('agent 1 angular velocity estimate error');
end

figure;
for k = 1:3
    subplot(3,1,k);
    plot(tv,[w1_interp(:,k) xh{2}(:,k+4)]);
    hold on;
    plot(tv,xh{2}(:,k+4)+3*sqrt(Ph{2}(:,Pdiag(k+4))),'r--');
    plot(tv,xh{2}(:,k+4)-3*sqrt(Ph{2}(:,Pdiag(k+4))),'r--');
    ylabel('agent 1 angular velocity estimate error');
end
