%% driver_wrapper

clear variables;
close all;
clear global;

global N h XYJ M Rk;

Rk = 1*diag([1 1]);

XYJ = [1/2 1/2;
    1.25 0];
M = size(XYJ,1);

T = 1;

count = 0;
Lf = randn(2,1);

for N = [4 8 12]
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
    uk = newtonmin(-lambda(i+1,:)',@controlFun);
    %uk = fsolve(@controlFun,-lambda(i+1,:)');
    Uk(i,:) = uk';
    
    Xk(i,:) = (Xk(i+1,:)' - h*uk)';
    xk = Xk(i,1);
    yk = Xk(i,2);
    
    lambda(i,:) = lambda(i+1,:);
    for j = 1:M
        xj = XYJ(j,1);
        yj = XYJ(j,2);
        vxk = uk(1);
        vyk = uk(2);
        
        %delta_alpha_k = atan2(XYJ(j,2) - yk,XYJ(j,1) - xk) - atan2(XYJ(j,2) - Xk(i+1,2),XYJ(j,1) - Xk(i+1,1));
        delta_alpha_k = atan2((yj - yk),(xj - xk)) - atan2((yk - yj + h*vyk),(xk - xj + h*vxk));
        %lambda(i,:) = lambda(i,:) + -delta_alpha_k*((xj-xk)^2/((yj-yk)^2+(xj-xk)^2)*[(yj-yk)/(xj-xk)^2;-1/(xj-xk)] + (xj-Xk(i+1,1))^2/((yj-Xk(i+1,2))^2+(xj-Xk(i+1,1))^2)*[(yj-Xk(i+1,2))/(xj-Xk(i+1,1))^2;-1/(xj-Xk(i+1,1))])';
        dalphakdXk = [(yk - yj + h*vyk)/(((yk - yj + h*vyk)^2/(xk - xj + h*vxk)^2 + 1)*(xk - xj + h*vxk)^2) + (yj - yk)/((xj - xk)^2*((yj - yk)^2/(xj - xk)^2 + 1))
            - 1/(((yk - yj + h*vyk)^2/(xk - xj + h*vxk)^2 + 1)*(xk - xj + h*vxk)) - 1/((xj - xk)*((yj - yk)^2/(xj - xk)^2 + 1))];
        lambda(i,:) = lambda(i,:)-delta_alpha_k*dalphakdXk';
    end
end

figure;
plot(Xk(:,1),Xk(:,2),'-x');
hold on;
plot(XYJ(:,1),XYJ(:,2),'rd');

axis equal;