function c = controlFun(uk)

global xkPlus lambdakp h;
global XYJ Rk;

c = zeros(2,size(uk,2));
for j = 1:size(uk,2)
    for i = 1:size(XYJ,1)
        xj = XYJ(i,1);
        yj = XYJ(i,2);
        vxk = uk(1,j);
        vyk = uk(2,j);
        xkp = xkPlus(1);
        ykp = xkPlus(2);
        
        %delta_alpha_k = atan2(yj - xkp(2) + h*uk(2),xj - xkp(1) + h*uk(1)) - atan2(XYJ(i,2) - xkp(2),XYJ(i,1) - xkp(1));
        delta_alpha_k = atan2((yj - ykp + h*vyk),(xj - xkp + h*vxk)) - atan2((yj - ykp),(xj - xkp));
        dalphakdUk =  [-(vyk*h^2 + (yj - ykp)*h)/(((yj - ykp + h*vyk)^2/(xj - xkp + h*vxk)^2 + 1)*(xj - xkp + h*vxk)^2)
                           h/(((yj - ykp + h*vyk)^2/(xj - xkp + h*vxk)^2 + 1)*(xj - xkp + h*vxk))];
        %c(:,j) = c(:,j) - h*delta_alpha_k*(XYJ(i,1) - xkp(1) + h*uk(1))^2/((XYJ(i,1) - xkp(1) + h*uk(1))^2+(XYJ(i,2) - xkp(2) + h*uk(2))^2)*([-(XYJ(i,2) - xkp(2) + h*uk(2))/(XYJ(i,1) - xkp(1) + h*uk(1))^2;1/(XYJ(i,1) - xkp(1) + h*uk(1))]);
        c(:,j) = c(:,j) - delta_alpha_k*dalphakdUk;
    end
    c(:,j) = c(:,j) + Rk*uk(:,j) + lambdakp*h;
end

end