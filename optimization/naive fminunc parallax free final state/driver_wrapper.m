%% driver_wrapper

clear variables;
close all;
clear global;

global N h XYJ M Rk;

Rk = 1.0*diag([1 1]);

XYJ = [0.5 0.5];
M = size(XYJ,1);

T = 1;

count = 0;
L0 = randn(2,1);

for N = [2 4 8 12 16]
    driver_test;
end
%% plot solution

global Xkg lambdak;

R = Rk;

t = 0:h:T;

xi = 0;
yi = 0;

% forward integrate for lambda(k) and x(k) at all k
lambda = zeros(N+1,2);
lambda(1,:) = L0';
Xk = zeros(N+1,2);
Xk(1,:) = [xi yi];
Uk = zeros(N,2);
for i = 1:N
    % compute the control
    Xkg = Xk(i,:)';
    lambdak = lambda(i,:)';
    uk = newtonmin(-h*lambda(i,:)',@controlFun);
    Uk(i,:) = uk';
    
    Xk(i+1,:) = (Xk(i,:)' + h*uk)';
    xk = Xk(i,1);
    yk = Xk(i,2);
    
    lambda(i+1,:) = lambda(i,:);
    for j = 1:M
        xj = XYJ(j,1);
        yj = XYJ(j,2);
        vxk = uk(1);
        vyk = uk(2);
        
        delta_alpha_k = atan2((yj - yk),(xj - xk)) - atan2((yk - yj + h*vyk),(xk - xj + h*vxk));
        dalphakdXk = [(yk - yj + h*vyk)/(((yk - yj + h*vyk)^2/(xk - xj + h*vxk)^2 + 1)*(xk - xj + h*vxk)^2) + (yj - yk)/((xj - xk)^2*((yj - yk)^2/(xj - xk)^2 + 1))
            - 1/(((yk - yj + h*vyk)^2/(xk - xj + h*vxk)^2 + 1)*(xk - xj + h*vxk)) - 1/((xj - xk)*((yj - yk)^2/(xj - xk)^2 + 1))];
        lambda(i+1,:) = lambda(i+1,:)+delta_alpha_k*dalphakdXk';
    end
end

figure;
plot(Xk(:,1),Xk(:,2),'-x');
hold on;
plot(XYJ(:,1),XYJ(:,2),'rd');

axis equal;