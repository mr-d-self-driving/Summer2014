%% simple_pf
clear variables;
close all;

addpath('../../2D');
addpath('../');
addpath('../../../particle filtering');

if ~exist('data_3d.mat','file');
    disp('Error: generate data first');
    return;
end

load('data_3d.mat');

%number of particles
m = 192;

%% initialize

% measurement error in other agent's omega
Qk = diag([1e-6*[1 1 1] ...% component for measured ang. vel uncertainty
    1*[1 1 1]]);% component for estimated ang. vel uncertainty

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
    Ph{i}(1,:) = reshape( .1*eye(7)+1e-4*ones(7), 49,1)';
end

% use exact initial conditions
xh{1}(1,1:4) = qji(1,:);
xh{1}(1,5:7) = Yc{2}(1,11:13);
xh{2}(1,1:4) = qji(1,:);xh{2}(1,1) = -xh{2}(1,1);
xh{2}(1,5:7) = Yc{1}(1,11:13);

eps0 = repmat(xh{1}(1,:)',1,m) + randn(7,m).*repmat([1/3,1/3,1/3,1/3,1,1,1]',1,m);
% re-normalize
eps0(1:4,:) = eps0(1:4,:)./repmat(sqrt(sum(eps0(1:4,:).^2,1)),4,1);

% error covariance associated with my measurement of him, and his
% measurement of me
Rx = zeros(6);
% measurement error
errnom = [0 err_dev err_dev].^2;

% uniform initial weights for now
w0 = 1/m*ones(1,m);

xk = zeros(length(T),7);
sigm = zeros(length(T),7);%store the standard deviation
tic;
for i = 1:length(T)
    %% simulate & update weights
    
    % imu measurements
    imu = W(i,1:3)';
    Rimu = Qk(1:3,1:3);
    % Rimu is the associated covariance
    % simulate gyro measurements
    omegaN = repmat(imu,1,m) + randn(3,m).*repmat(sqrt(diag(Rimu)),1,m);
    
    % f is the derivative
    f = zeros(7,m);
    for k = 1:m
        % state vector
        xhat = eps0(:,k);
        % fake of my measured angular velocity
        wi = omegaN(:,k);
        % relative angular velocity in j frame
        w = xhat(5:7) - Cji*wi;
        A = 0.5*[ -xhat(2:4)';xhat(1)*eye(3) + squiggle(xhat(2:4))];
        f(1:4,k) = A*w;
        % add noise for other's angular velocity propagation
        f(5:7,k) = randn(3,1).*diag(sqrt(Qk(4:6,4:6)));
    end
    % propagate
    epsPlus = eps0 + Ts*f;
    % re-normalize
    epsPlus(1:4,:) = epsPlus(1:4,:)./repmat( sqrt(sum(epsPlus(1:4,:).^2,1)) , 4,1);
    % get measurements
    % my meas of him
    rji_i = meas{1}(i,(1:3))';
    rij_j = meas{2}(i,(1:3))';
    % (expectation) error
    %ydiff = -rij_j - Cji*rji_i;
    yk = rij_j;
    % compute the expectation of yk, given epsPlus AND my measurement
    bear_exp = zeros(3,m);
    for k = 1:m
        xhat = epsPlus(:,k);
        Cji = attparsilent(xhat(1:4),[6 1]);
        bear_exp(:,k) = -Cji*rji_i;
    end
    % residual matrix of errors, same format as bear_exp
    resid = repmat(yk,1,m) - bear_exp;
    % compute the associated covariance
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

    % probability that the residuals are what they are or greater, not sure
    % this is correct
    % since each measurement is independent, the probability of all of them is
    % the sum of the probability of each
    p_y_x = prod(normpdf(resid,0*resid,repmat([eye(3) zeros(3)]*real(sqrt(diag(100*Rx))),1,m)),1);
    %p_y_x = sum(2*(1-normcdf(abs(resid)))',1);
    wkPlus = w0.*p_y_x;
    wkPlus = wkPlus/sum(wkPlus);
    
    if any(isnan(wkPlus))
        disp('warning');
    end
    
    %% resample
    % store values
    xk(i,:) = 0.5*sum(epsPlus.*repmat(wkPlus,7,1) + eps0.*repmat(w0,7,1),2)';
    sigm(i,:) = std([epsPlus eps0],1,2)';
    % update
    eps0 = epsPlus;
    % sort by inverse weight, useful if we decide not to resample
    % everything
    [~,ins] = sort(wkPlus,2,'ascend');
    w0 = w0(ins);
    wkPlus = wkPlus(ins);
    eps0 = eps0(:,ins);
    
    % number of particles, effective:
    Neff = 1/(sum(wkPlus.^2));
    
    % resample all particles for now
    n = floor(m/2);% # to resample
    epsPlus(:,1:n) = resample_multinomial(eps0,wkPlus,n,m);
    % re-normalize
    epsPlus(1:4,:) = epsPlus(1:4,:)./repmat( sqrt(sum(epsPlus(1:4,:).^2,1)) , 4,1);
    % recompute the weights for the resampled particles
        % compute the expectation of yk, given epsPlus AND my measurement
        bear_exp = zeros(3,m);
        for k = 1:m
            xhat = epsPlus(:,k);
            Cji = attparsilent(xhat(1:4),[6 1]);
            bear_exp(:,k) = -Cji*rji_i;
        end
        % residual matrix of errors, same format as bear_exp
        resid = repmat(yk,1,m) - bear_exp;
        
        % probability that the residuals are what they are or greater, not sure
        % this is correct
        % since each measurement is independent, the probability of all of them is
        % the sum of the probability of each
        p_y_x = prod(normpdf(resid,0*resid,repmat([eye(3) zeros(3)]*real(sqrt(diag(100*Rx))),1,m)),1);
    wkPlus = wkPlus.*p_y_x;% do i use wkplus or w0 here?
    wkPlus = wkPlus/sum(wkPlus);
        
    w0 = wkPlus;
    eps0 = epsPlus;
    
    if ~mod(i-1,10)
        etaCalc(i,length(T),toc);
    end
end

%% figures;

close all;

figure;
for j = 1:4
    subplot(2,2,j);
    plot(T,xk(:,j),'r--');
    hold on;
    plot(T,qji(:,j),'b-');
end

figure;
for j = 1:3
    subplot(3,1,j);
    plot(T,xk(:,j+4),'r--');
    hold on;
    plot(T,W(:,j),'b-');
end