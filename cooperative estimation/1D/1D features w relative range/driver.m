%% 
clear variables;
clear global;
close all;

%number of features
M = 3;
% N number of agents
N = 1;

global features;
featureRad = 10;

%uniform feature distribution
features = zeros(M,1);
for i = 1:M
    features(i) = 2*randn*featureRad - featureRad;
end

% measurement covariance for features
Rf = diag(1*ones(1,M));

%update period for landmark measurements
Tl = 1;

%sim time
Tf = 20;

% dynamics
A = [0 1;0 0];
B = [0;1];
Hk = repmat([-1 0],M,1);
G = [0;1];
Q = .1;

%data storage
t = zeros(1e5,1);
truth = zeros(1e5,2);
xhat = zeros(1e5,2);
Phat = zeros(1e5,4);
count = 0;

tnow = 0;
x0 = [0;18.5];
xh0 = [0;0];
Pk = eye(2);
% simulate the system
while tnow < Tf
% update    
    %expectation
    yhat = landmark_meas(xh0,diag([0 0 0]));
    %measurement
    ytilde = landmark_meas(x0,Rf);
    K = Pk*Hk'*((Hk*Pk*Hk' + Rf)\eye(M));
    xh0 = xh0 + K*(ytilde - yhat);
    Pk = (eye(2) - K*Hk)*Pk;
% compute control also
    u1 = -12*sin(2*pi/10*tnow);
    
    count = count + 1;
    t(count) = tnow;
    xhat(count,:) = xh0';
    Phat(count,:) = reshape(Pk,[],1)';
    truth(count,:) = x0';
    
% propagate (integrate)
    tint = linspace(tnow,tnow+Tl,10);
    tnow = tnow + Tl;
    [~,Y] = agent_sim(tint,x0,A,B,G,Q,u1);
    x0 = Y(end,:)';
    t(count+(1:10)) = tint;
    truth(count+(1:10),:) = Y;
    [~,Y] = agent_propagate(tint,xh0,Pk,A,B,G,Q,u1);
    xhat(count+(1:10),:) = Y(:,1:2);
    Phat(count+(1:10),:) = Y(:,3:end);
    xh0 = Y(end,1:2)';
    Pk = reshape(Y(end,3:end),2,2);
    
    count = count + 10;
end
t(count+1:end) = [];
truth(count+1:end,:) = [];
Phat(count+1:end,:) = [];
xhat(count+1:end,:) = [];