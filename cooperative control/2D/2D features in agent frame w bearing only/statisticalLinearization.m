function [ybar,Py] = statisticalLinearization(x,Rx,fhandle,alpha)
% INPUTS:
%   x: current value of a vector of random Gaussian variables
%   Rx: covariance associated with x
%   fhandle: function handle that returns y = f(x). Ideally should be
%       vectorized for an [n x ...] vector repeated columnwise
% OUTPUTS:
%   ybar: expectation of the output
%   Py: covariance associated with the output

n = length(x);

% linearization parameters
if nargin < 4
    alpha = 10^(0); % alpha is variable and should be an optional input
end
kf = 0;%"usually zero for state estimation"
%kf = 3 - n;
beta = 2;% "for a Gaussian distribution the optimal value is 2", but potentially this is a variable parameter

lambda = alpha^2*(n+kf)-n;
gamma = sqrt(n+lambda);

% get the 2*n+1 sigma points
nSigma = zeros(n,2*n+1);
nSigma(:,1) = x;
nSigma(:,2:(n+1)) = repmat(x,1,n) + gamma*sqrtm(Rx);
nSigma(:,(n+2):(2*n+1)) = repmat(x,1,n) - gamma*sqrtm(Rx);

% propagate the sigma points through the nonlinear function y = f(x)
ySigma = fhandle(nSigma);% ySigma is size m x (2*n+1)
m = size(ySigma,1);

% weights
Wm = zeros(2*n+1,1);
Wc = zeros(2*n+1,1);
Wm(1) = lambda/(n+lambda);
Wc(1) = lambda/(n+lambda) + (1-alpha^2+beta);
Wc(2:end) = 1/(2*(n+lambda));
Wm(2:end) = Wc(2:end);

% compute the mean and covariance for y, the output
ybar = sum(ySigma.*repmat(Wm',m,1),2);
Py = zeros(m);
for i = 1:(2*n+1)
    Py = Py + Wc(i)*(ySigma(:,i)-ybar)*(ySigma(:,i)-ybar)';
end
end