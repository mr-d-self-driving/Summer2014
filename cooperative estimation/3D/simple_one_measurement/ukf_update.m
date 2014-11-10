function [xnew,Pnew] = ukf_update(xk,Pxk,Pvk,Pnk,uk,ytilde,updatefun,measurementfun)
% Pxk: covariance associated with state
% Pvk: covariance associated with process noise
% Pnk: covariance assocaited with measurement noise

% vector lengths
n = length(xk);
m = length(uk);
nl = size(Pnk,1);
vl = size(Pvk,1);
N = n+nl+vl;

% constant gamma that influences sigma points
alpha = 1e-3;
Kappa = 0;
lambda = alpha^2*(N+Kappa)-N;
gamm = sqrt(N+lambda);

%augmented covariance and state
Paug = zeros(N);
Paug(1:n,1:n) = Pxk;
Paug(n+(1:vl),n+(1:vl)) = Pvk;
Paug(n+vl+(1:nl),n+vl+(1:nl)) = Pnk;

xaug = [xk;zeros(nl+vl,1)];

Psq = sqrtm(Paug);
Psq = real(Psq);

% compute the sigma points
XAUG = zeros(N,2*N+1);
XAUG(:,1) = xaug;
for k = 1:N
    XAUG(:,k+1) = xaug + gamm*Psq(:,k);
    XAUG(:,N+1+k) = xaug - gamm*Psq(:,k);
end

% propagate the sigma points
XAUGPLUS = updatefun(XAUG(1:n,:),XAUG(n+(1:vl),:),uk);

% weights
beta = 2;% optimal for Gaussian
wc = 0.5/(N+lambda)*ones(2*N+1,1);
wm = 0.5/(N+lambda)*ones(2*N+1,1);
wc(1) = lambda/(N+lambda);
wm(1) = lambda/(N+lambda) + 1-alpha^2+beta;

% calculate the update
xp = sum(XAUGPLUS(1:n,:).*repmat(wm',n,1),2);
% re-normalize
xp(1:4) = xp(1:4)/norm(xp(1:4));
Pp = zeros(n);
for k = 1:2*N+1
    Pp = Pp + wc(k)*(XAUGPLUS(1:n,k)-xp)*(XAUGPLUS(1:n,k)-xp)';
end

% pass the sigma points through the measurement function
YKAUG = measurementfun(XAUGPLUS(1:n,:),XAUG(n+vl+(1:nl),:),uk);

g = size(YKAUG,1);

yhat = sum(YKAUG.*repmat(wm',g,1),2);
% re-normalize (unit vector)
yhat = yhat/norm(yhat);

% measurement covariance
Pyk = zeros(g);
% cross covariance
Pxkyk = zeros(n,g);
for k = 1:2*N+1
    Pyk = Pyk + wc(k)*(YKAUG(:,k)-yhat)*(YKAUG(:,k)-yhat)';
    Pxkyk = Pxkyk + wc(k)*(XAUGPLUS(1:n,k)-xp)*(YKAUG(:,k)-yhat)';
end

% Kalman gain
Kk = Pxkyk*(Pyk\eye(g));

xnew = xp + Kk*(ytilde-yhat);
xnew(1:4) = xnew(1:4)/norm(xnew(1:4));
Pnew = Pp - Kk*Pyk*Kk';

end