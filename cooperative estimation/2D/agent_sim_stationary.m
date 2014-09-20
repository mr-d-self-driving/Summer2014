function [T,Y,V,W,A] = agent_sim_stationary(tspan,y0)

[T,Y] = ode45(@eqom,tspan,y0,odeset('abstol',1e-5,'reltol',1e-5));

% make sure heading is between \pm pi
while any(abs(Y(:,3)) > pi)
    i1 = find(Y(:,3) < -pi);
    i2 = find(Y(:,3) > pi);
    Y(i1,3) = Y(i1,3) + 2*pi;
    Y(i2,3) = Y(i2,3) - 2*pi;
end

V = zeros(length(T),2);
V(2:end,:) = diff(Y(:,1:2),1,1)./repmat(diff(T),1,2);
A = zeros(length(T),2);
W = 0.1*ones(length(T),1);

    function dy = eqom(t,y)
        dy = [0;0;0];
        
        dy(1:2) = [0;0];%randn(2,1).*[1;1];
        dy(3) = 0.1;
    end
end