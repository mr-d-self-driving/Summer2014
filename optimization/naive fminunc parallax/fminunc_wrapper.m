%% fminunc_wrapper

clear variables;
close all;
clear global;

global N h XYJ M;
global Rk;

Rk = diag([1;1]);

M = 1;
XYJ = [0 1];

N = 2;

T = 1.0;
h = T/N;

Lf0 = [0;0] + randn(2,1);

options = optimset('disp','iter','LargeScale','off');
%Lf = fminunc(@costf,Lf0,options);
Lf = fsolve(@costf,Lf0,options);

%% plot solution

R1 = Rk(1,1);
R2 = Rk(2,2);
xf = 1;
yf = 1;
xi = 0;
yi = 0;
R = Rk;

t = 0:h:T;
lambda = zeros(N+1,2);
lambda(end,:) = Lf';
Xk = zeros(N+1,2);
Xk(end,:) = [xf yf];
for i = N:-1:1
    Xk(i,:) = (Xk(i+1,:)' + R\lambda(i+1,:)')';
    xk = Xk(i,1);
    yk = Xk(i,2);
    Lkx = lambda(i+1,1);
    Lky = lambda(i+1,2);
    
    for j = 1:M
        xj = XYJ(j,1);
        yj = XYJ(j,2);
        
        lambda(i,:) = [ h*(atan2((yj - yk + Lky/R2),(xj - xk + Lkx/R1)) - atan2((yj - yk),(xj - xk)))*((yj - yk)/((xj - xk)^2*((yj - yk)^2/(xj - xk)^2 + 1)) - (yj - yk + Lky/R2)/(((yj - yk + Lky/R2)^2/(xj - xk + Lkx/R1)^2 + 1)*(xj - xk + Lkx/R1)^2))
                -h*(atan2((yj - yk + Lky/R2),(xj - xk + Lkx/R1)) - atan2((yj - yk),(xj - xk)))*(1/((xj - xk)*((yj - yk)^2/(xj - xk)^2 + 1)) - 1/(((yj - yk + Lky/R2)^2/(xj - xk + Lkx/R1)^2 + 1)*(xj - xk + Lkx/R1)))]';
        if any(isnan(lambda(i,:)))
            lambda(i,:) = [0 0];
        end
    end
end

figure;
plot(Xk(:,1),Xk(:,2),'-x');