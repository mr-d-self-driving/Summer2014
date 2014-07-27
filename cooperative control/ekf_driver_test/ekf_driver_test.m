%% ekf_driver_test
addpath('..');

read_data_sim;

%% process data from agent 1
t = ags(1).t(1:3000);
state = ags(1).x(1:3000,:);

G = [1;0.5];
R = eye(2,2);
Q = 1;

y = state(:,1:2);
y = y + randn(size(y)).*repmat(diag(R)',length(y),1);
u = state(:,[4 5 3]);

[tout,xout,Pout] = ekf_ol(@simple_f_handle,@simple_h_handle,G,Q,R,t,y,u);