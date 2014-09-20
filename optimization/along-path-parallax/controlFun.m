function c = controlFun(uk)

global xkPlus lambdakp h;
global XYJ Rk;


c = zeros(2,size(uk,2));
for j = 1:size(uk,2)
    u = uk(:,j);
    for i = 1:size(XYJ,1)
        
        rk = xkPlus - h*u;
        
        c(:,j) = c(:,j) + (u'*(XYJ(i,:)' - rk))*(XYJ(i,:)' - rk);
    end
    c(:,j) = c(:,j) + Rk*u + lambdakp*h;
end

end