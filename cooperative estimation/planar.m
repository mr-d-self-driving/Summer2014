function [T,Y] = planar(tspan,y0,refFun)

%precompute the reference
[tref,ref] = refFun(tspan,y0);

options = odeset('abstol',1e-7,'reltol',1e-7);
[T,Y] = ode45(@eqom,tspan,y0);

%equation of motion for agent:
    function dy = eqom(t,y)
        %y: [X,Y,psi,v1,v2,psidot]
        dy = zeros(6,1);
        
        refnow = interp1(tref',ref',t);
        dy(4:6) = -1.0*(y(4:6) - refnow(4:6)');
        
        % convert body-frame velocities to the inertial frame:
        dy(1:2) = [cos(y(3)) -sin(y(3));sin(y(3)) cos(y(3))]*refnow(4:5)';
        dy(3) = 1.0*(refnow(3) - y(3));
        
        % add process noise
        zxy = [min(max(0.1*(y(1) + y(2) - 10),1),-1);-0.5];
        dy(1:2) = dy(1:2) + zxy;
    end
end