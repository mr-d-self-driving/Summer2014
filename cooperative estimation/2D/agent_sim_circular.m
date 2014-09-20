function [T,Y,V,W,A] = agent_sim_circular(tspan,y0)

%initial heading
psi0 = y0(3);
if psi0 > pi
    psi0 = psi0-2*pi;
end
r0 = norm(y0(1:2));
theta0 = atan2(y0(2),y0(1));
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
    [V(i,:),W(i,:),A(i,:)] = vel(T(i));
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
        a = r0*0.5; % radial amplitude
        WW = pi/10;% "orbital" period
        wt = WW*0.75;% rate of change of radius
        
        % w is the spin rate
        if psi0 > 0
            w = -0.4;
        else
            w = 0.4;
            WW = -WW;
        end
        psi = psi0 + w*t;
        
        r = r0 + a*sin(wt*t);
        theta = theta0 + WW*t;
        rdot = a*cos(wt*t)*wt;
        thetadot = WW;
        rddot = -a*wt^2*sin(wt*t);
        thetaddot = 0;
        
        % turn this on to constrain heading to be along the velocity vect
        % v = [rdot;r*thetadot]
        %psi = atan2(r*thetadot,rdot) + theta;
        
        % turn this on to constrain heading to look towards the origin
        %psi = pi2pi(theta);
        
        vn = [rdot*cos(theta)-r*sin(theta)*thetadot;
            rdot*sin(theta)+r*thetadot*cos(theta)];
        an = [rddot*cos(theta)-2*rdot*sin(theta)*thetadot-r*cos(theta)*thetadot^2-r*sin(theta)*thetaddot;
            rddot*sin(theta)+2*rdot*thetadot*cos(theta)+r*thetaddot*cos(theta)-r*thetadot^2*sin(theta)];
        % inerital to body DCM
        C = [cos(psi) sin(psi);
            -sin(psi) cos(psi)];
        v = C*vn;
        a = C*an;
    end
end