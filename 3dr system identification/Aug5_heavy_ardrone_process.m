%aug5_heavy_ardrone_process
clear variables;
close all;
M1 = load('heavy_ardrone_1.mat');
M2 = load('heavy_ardrone_2.mat');
M3 = load('heavy_ardrone_3.mat');

opti_diff = [M1.opti_diff;M2.opti_diff;M3.opti_diff];
opti_acc = [M1.opti_acc;M2.opti_acc;M3.opti_acc];
acc_est = [M1.acc_est;M2.acc_est;M3.acc_est];

% compute student's t
x = [opti_diff opti_acc acc_est];
% compute 95% confidence interval
treq = tinv(0.975,size(x,1)-1);
conf95 = repmat(mean(x,1),2,1) + repmat((treq*std(x,1))/sqrt(size(x,1)),2,1).*[ones(1,size(x,2)); -1*ones(1,size(x,2))];