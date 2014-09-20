%aug5_heavy_ardrone_process
clear variables;
close all;
M1 = load('ardrone_1.mat');
M2 = load('ardrone_2.mat');

opti_diff = [M1.opti_diff;M2.opti_diff];
opti_acc = [M1.opti_acc;M2.opti_acc];
acc_est = [M1.acc_est;[M2.acc_est zeros(3,1)]];

% compute student's t
x = [opti_diff opti_acc acc_est];
% compute 95% confidence interval
treq = tinv(0.975,size(x,1)-1);
conf95 = repmat(mean(x,1),2,1) + repmat((treq*std(x,1))/sqrt(size(x,1)),2,1).*[ones(1,size(x,2)); -1*ones(1,size(x,2))];