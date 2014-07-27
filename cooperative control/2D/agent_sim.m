function [T,Y,V,W,A] = agent_sim(tspan,y0)

[T,Y] = ode45(@eqom,tspan,y0,odeset('abstol',1e-5,'reltol',1e-5));

% make sure heading is between \pm pi
while any(abs(Y(:,3)) > pi)
    i1 = find(Y(:,3) < -pi);
    i2 = find(Y(:,3) > pi);
    Y(i1,3) = Y(i1,3) + 2*pi;
    Y(i2,3) = Y(i2,3) - 2*pi;
end

V = zeros(length(T),2);
A = zeros(length(T),2);
W = zeros(length(T),1);
for i = 1:length(T)
    [V(i,:),W(i),A(i,:)] = vel(T(i));
end

    function dy = eqom(t,y)
        dy = [0;0;0];
        psi = y(3);
        
        % velocities are prescribed
        [v,omega] = vel(t);
        
        C = [cos(psi) -sin(psi);sin(psi) cos(psi)];%body to inertial
        dy(1:2) = C*v;
        dy(3) = omega;
    end
    function [v,w,a] = vel(t)
        if t > 100
            t = t-100;
        end
        if t < 20
            u = 0.025*t;
            w = 0.1;%0.2 + 0.1*rand;
            a = 0.025;
        elseif t < 40 && t >= 20
            u = .5;
            w = -0.1 + 0.1*rand;
            a = 0;
        elseif t >= 40 && t < 60
            u = .5-.025*(t-40);
            w = 0.3 + 0.1*rand;
            a = -.025;
        else
            u = -1*cos(t*2*pi/20)+1;
            w = 0.2 + 0.1*rand;
            a = 2*pi/20*sin(t*2*pi/20);
        end
        
        v = [u;0];
        a = [a;0] + [0 -w;w 0]*v;
    end
end