function [T,Y] = integ(tspan,y0)

% y: [rx ry psi_1 rx ry psi_t rx ry psi_2 v2]

v1max = 1;
vtmax = 0.9;

[T,Y] = ode45(@eqom,tspan,y0);

    function dy = eqom(t,y)
        u1 = ctrl_1(t,y);
        %u1 = 0;
        u2 = ctrl_2(t,y);
        
        dy = zeros(10,1);
        
        dy(1:2) = v1max*[cos(y(3));sin(y(3))];
        dy(3) = u1;
        dy(4:5) = vtmax*[cos(y(6));sin(y(6))];
        dy(7:8) = y(10)*[cos(y(9));sin(y(9))];
        dy(9:10) = u2;
    end
end