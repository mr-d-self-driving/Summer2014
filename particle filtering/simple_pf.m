%% simple_pf
clear variables;
close all;

load data.mat;

M = 1;

% vector of landmark positions
marksxy = zeros(M,2);
for i = 1:M
    marksxy(i,:) = marks(i).xy;
end

%number of particles
m = 192;

%% initialize

Cbn = [cos(ags(1).truth(i,5)) sin(ags(1).truth(i,5));-sin(ags(1).truth(i,5)) cos(ags(1).truth(i,5))];
x0 = ags(1).truth(1,1:5)';
% convert initial position to body frame
x0(1:2) = Cbn*x0(1:2);

eps0 = repmat(x0,1,m) + randn(5,m).*repmat([10;10;1;1;0.5],1,m);

% uniform initial weights for now
w0 = 1/m*ones(1,m);

xk = zeros(length(tspan),5);
sigm = zeros(length(tspan),5);%store the standard deviation
tic;
for i = 1:length(tspan)
    %% simulate & update weights
    
    % imu measurements
    imu = ags(1).IMU(i,:)';
    ab = imu(1:2);
    omega = imu(3);
    % Rimu is the associated covariance
    omegaN = repmat(omega,1,m) + randn(1,m)*Rimu(3,3);
    abN = repmat(ab,1,m);
    abN(1,:) = abN(1,:) + randn(1,m)*Rimu(1,1);
    abN(2,:) = abN(2,:) + randn(1,m)*Rimu(2,2);
    f = zeros(5,m);
    f(1:2,:) = eps0(3:4,:) + [omegaN.*eps0(2,:);-omegaN.*eps0(1,:)];
    f(3:4,:) = abN + [omegaN.*eps0(4,:);-omegaN.*eps0(3,:)];
    f(5,:) = omegaN;
    epsPlus = eps0 + Ts*f;
    % get measurements
    yk = ags(1).rb(i,M+1:2*M);
    % compute the expectation of yk, given epsPlus
    % Cmat is a matrix of DCMs from inertial to body
    Cmat(1:2:2*m-1,:) = [cos(epsPlus(5,:))' sin(epsPlus(5,:))'];
    Cmat(2:2:2*m,:) = [-sin(epsPlus(5,:))' cos(epsPlus(5,:))'];
    % rki_exp is the matrix of expected vectors from agent i to landmark k:
    % each row 2*i-1:2*i of rki_exp is a matrix of all the expected vectors for
    % one particle i
    rki_exp = Cmat*marksxy' - repmat(reshape(epsPlus(1:2,:),2*m,1),1,M);
    % each row i and column j of bear_exp is the expected bearing to landmark j
    % given particle i
    bear_exp = atan2(rki_exp(1:2:end-1,:),rki_exp(2:2:end,:));
    for k = 1:M
        bear_exp(:,k) = minangle(bear_exp(:,k),repmat(yk(k),m,1));
    end
    % residual matrix of errors, same format as bear_exp
    resid = repmat(yk,m,1) - bear_exp;
    % probability that the residuals are what they are or greater, not sure
    % this is correct
    % since each measurement is independent, the probability of all of them is
    % the sum of the probability of each
    p_y_x = prod(normpdf(resid,0*resid,Rbear(1)*ones(size(resid)))',1);
    %p_y_x = sum(2*(1-normcdf(abs(resid)))',1);
    wkPlus = w0.*p_y_x;
    wkPlus = wkPlus/sum(wkPlus);
    
    if any(isnan(wkPlus))
        disp('warning');
    end
    
    %% resample
    % store values
    xk(i,:) = 0.5*sum(epsPlus.*repmat(wkPlus,5,1) + eps0.*repmat(w0,5,1),2)';
    sigm(i,:) = std([epsPlus eps0],1,2)';
    % update
    eps0 = epsPlus;
    % sort by inverse weight, useful if we decide not to resample
    % everything
    [~,ins] = sort(wkPlus,2,'ascend');
    w0 = w0(ins);
    eps0 = eps0(:,ins);
    
    % number of particles, effective:
    Neff = 1/(sum(wkPlus.^2));
    
    % resample all particles for now
    n = m;% # to resample
    epsPlus = resample_multinomial(eps0,wkPlus,n);
    % recompute the weights for the resampled particles
        % compute the expectation of yk, given epsPlus
        % Cmat is a matrix of DCMs from inertial to body
        Cmat(1:2:2*m-1,:) = [cos(epsPlus(5,:))' sin(epsPlus(5,:))'];
        Cmat(2:2:2*m,:) = [-sin(epsPlus(5,:))' cos(epsPlus(5,:))'];
        % rki_exp is the matrix of expected vectors from agent i to landmark k:
        % each row 2*i-1:2*i of rki_exp is a matrix of all the expected vectors for
        % one particle i
        rki_exp = Cmat*marksxy' - repmat(reshape(epsPlus(1:2,:),2*m,1),1,M);
        % each row i and column j of bear_exp is the expected bearing to landmark j
        % given particle i
        bear_exp = atan2(rki_exp(1:2:end-1,:),rki_exp(2:2:end,:));
        for k = 1:M
            bear_exp(:,k) = minangle(bear_exp(:,k),repmat(yk(k),m,1));
        end
        % residual matrix of errors, same format as bear_exp
        resid = repmat(yk,m,1) - bear_exp;
        % probability that the residuals are what they are or greater, not sure
        % this is correct
        % since each measurement is independent, the probability of all of them is
        % the sum of the probability of each
        p_y_x = sum(2*(1-normcdf(abs(resid)))',1);% well, now we know this is wrong
    wkPlus = wkPlus.*p_y_x;% do i use wkplus or w0 here?
    wkPlus = wkPlus/sum(wkPlus);
        
    w0 = wkPlus;
    eps0 = epsPlus;
    
    if ~mod(i-1,100)
        etaCalc(i,length(tspan),toc);
    end
end

%% figures;
addpath('../cooperative control/2D');
xk(:,5) = pi2pi(xk(:,5));
for i = 1:3
    subplot(3,1,i);
    plot(tspan,ags(1).truth(:,i+2));
    hold on;
    plot(tspan,xk(:,i+2),'r--');
    plot(tspan,xk(:,i+2)+3*sigm(:,i+2),'m-');
    plot(tspan,xk(:,i+2)-3*sigm(:,i+2),'m-');
end
