function c = controlFun(uk)

global Xkg lambdak h;
global XYJ Rk;

c = zeros(2,size(uk,2));
for j = 1:size(uk,2)
    for i = 1:size(XYJ,1)
        xj = XYJ(i,1);
        yj = XYJ(i,2);
        % current control
        vxk = uk(1,j);
        vyk = uk(2,j);
        % current state
        xk = Xkg(1);
        yk = Xkg(2);
        
        delta_alpha_k = atan2((yj - yk),(xj - xk)) - atan2((yj - yk - h*vyk),(xj -xk - h*vxk));
        dalphakdUk =  [ -(h*(yj - yk) - h^2*vyk)/(((yk - yj + h*vyk)^2/(xk - xj + h*vxk)^2 + 1)*(xk - xj + h*vxk)^2)
            -h/(((yk - yj + h*vyk)^2/(xk - xj + h*vxk)^2 + 1)*(xk - xj + h*vxk))];
        dalphakdXk = [(yk - yj + h*vyk)/(((yk - yj + h*vyk)^2/(xk - xj + h*vxk)^2 + 1)*(xk - xj + h*vxk)^2) + (yj - yk)/((xj - xk)^2*((yj - yk)^2/(xj - xk)^2 + 1))
            - 1/(((yk - yj + h*vyk)^2/(xk - xj + h*vxk)^2 + 1)*(xk - xj + h*vxk)) - 1/((xj - xk)*((yj - yk)^2/(xj - xk)^2 + 1))];
        c(:,j) = c(:,j) - delta_alpha_k*dalphakdUk;
        c(:,j) = c(:,j) + h*delta_alpha_k*dalphakdXk;
    end
    c(:,j) = c(:,j) + Rk*uk(:,j) + h*lambdak;
end

end