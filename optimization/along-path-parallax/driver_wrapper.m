%% driver_wrapper

clear variables;
close all;
clear global;

global N h XYJ M Rk;

Rk = .1*diag([1 1]);

XYJ = [0 0;%X1 Y1
    1 1];
M = size(XYJ,1);

T = 1;

count = 0;
Lf = randn(2,1);

for N = [2 4 6]
    driver_test;
end
%% plot solution

global xkPlus lambdakp;

R = Rk;

t = 0:h:T;

xf = 1;
yf = 1;
xi = 0;
yi = 0;

% backward integrate for lambda(k) and x(k) at all k
lambda = zeros(N+1,2);
lambda(end,:) = Lf';
Xk = zeros(N+1,2);
Xk(end,:) = [xf yf];
Uk = zeros(N,2);
for i = N:-1:1
    % compute the control
    xkPlus = Xk(i+1,:)';
    lambdakp = lambda(i+1,:)';
    
    uk = newtonmin(-lambdakp*h,@controlFun);
    Uk(i,:) = uk';
    if ~all(abs(controlFun(uk)) < 1e-4)
        disp('No solution for u');
    end
    Xk(i,:) = Xk(i+1,:)' - h*uk;
    lambda(i,:) = lambda(i+1,:);
    for j = 1:M
        lambda(i,:) = lambda(i,:) - ((uk'*(XYJ(j,:)'-Xk(i,:)'))*uk)';
    end
end

figure;
plot(Xk(:,1),Xk(:,2),'-x');
hold on;
plot(XYJ(:,1),XYJ(:,2),'rd');

axis equal;