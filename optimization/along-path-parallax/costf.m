function J = costf(u)

% u: lambda(T): u(1) = lambda_u(T), u(2) = lambda_v(T)

global h N M XYJ Rk;%XYJ is an M x 2 matrix of feature coordinates
global xkPlus lambdakp;

xf = 1;
yf = 1;
xi = 0;
yi = 0;

J = zeros(1,size(u,2));
for II = 1:size(u,2)
    % backward integrate for lambda(k) and x(k) at all k
    lambda = zeros(N+1,2);
    lambda(end,:) = u(:,II)';
    Xk = zeros(N+1,2);
    Xk(end,:) = [xf yf];
    for i = N:-1:1
        % compute the control
        xkPlus = Xk(i+1,:)';
        lambdakp = lambda(i+1,:)';
        
        uk = newtonmin(-lambdakp*h,@controlFun);
        if ~all(abs(controlFun(uk)) < 1e-4)
           disp('No solution for u');
        end
        Xk(i,:) = Xk(i+1,:)' - h*uk;
        lambda(i,:) = lambda(i+1,:);
        for j = 1:M
            lambda(i,:) = lambda(i,:) - ((uk'*(XYJ(j,:)'-Xk(i,:)'))*uk)';
        end
    end
    % the cost function is the error w.r.t. the initial state
    J(II) = 0.5*((Xk(1,:) - [xi,yi])*(Xk(1,:) - [xi,yi])');
    
end
end