function J = costf(u)

% u: lambda(0): u(1) = lambda_u(0), u(2) = lambda_v(0)

global h N M XYJ;%XYJ is an M x 2 matrix of feature coordinates
global Xkg lambdak;

xi = 0;
yi = 0;

J = zeros(1,size(u,2));
for II = 1:size(u,2)
    % forward integrate for lambda(k) and x(k) at all k
    lambda = zeros(N+1,2);
    lambda(1,:) = u(:,II)';
    Xk = zeros(N+1,2);
    Xk(1,:) = [xi yi];
    for i = 1:N
        % compute the control
        Xkg = Xk(i,:)';
        lambdak = lambda(i,:)';
        uk = newtonmin(-h*lambda(i,:)',@controlFun);
        
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
    % the cost function is the error w.r.t. the final costate
    J(II) = 0.5*(lambda(end,:)*lambda(end,:)');
end
end