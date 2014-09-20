%% simple_pf_2

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

x0 = ags(1).truth(1,1:5)';
eps0 = repmat(x0,1,m) + randn(5,m).*repmat([1;1;.1;.1;0.03],1,m)/2;
% compute initial weights
yk = ags(1).rb(1,M+1:2*M);% body frame bearing
yhat = atan2(marksxy(1,2) - eps0(2,:),marksxy(1,1) - eps0(1,:)) - eps0(5,:);
yhat = minangle(yhat,repmat(yk,1,m));
resid = yhat - repmat(yk,1,m);
wk = normpdf(resid,0*resid,Rbear(1)*ones(size(resid)));
wk = wk./sqrt(sum(wk.^2,2));

i = 2;
%% propagate

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
for j = 1:m
    C = [cos(eps0(5,j)) -sin(eps0(5,j));sin(eps0(5,j)) cos(eps0(5,j))];
    f(1:2,j) = C*eps0(3:4,j);
end
f(3:4,:) = abN + [omegaN.*eps0(4,:);-omegaN.*eps0(3,:)];
f(5,:) = omegaN;

epsPlus = eps0 + Ts*f;
%recalculate weights
yk = ags(1).rb(i,M+1:2*M);
yhat = atan2(marksxy(1,2) - epsPlus(2,:),marksxy(1,1) - epsPlus(1,:)) - epsPlus(5,:);
yhat = minangle(yhat,repmat(yk,1,m));
resid = yhat - repmat(yk,1,m);
wPlus = wk.*normpdf(resid,0*resid,Rbear(1)*ones(size(resid)));
wPlus = wPlus./sqrt(sum(wPlus.^2,2));
%% resample
% use the new points and weights as the source for resampling