function [T,Y,V,W,A] = agent_sim_follower(tspan,y0)
% y0: [ rx1, ry1, psi1, rx2, ry2, psi2 ]

Kr = 1;% lyapunov gain for reference radius
Kinv = 1;% gain for inverse radius controller
Kd = 1;% gain for lyapunov for velocity
Kpsi = 1;% gain for agent 2 heading rate controller
D = 0.25;
L = 1.75;

% agent 1 moves arbitrarily
%initial heading
psi0 = y0(3);
if psi0 > pi
    psi0 = psi0-2*pi;
end
r0 = norm(y0(1:2));
theta0 = atan2(y0(2),y0(1));

% add INERTIAL velocity states of agent 2 for simulation
ysim = [y0;0;0];

[T,Y] = ode45(@eqom,tspan,ysim,odeset('abstol',1e-5,'reltol',1e-5));

% need to modify this to output the velocity and acceleration histories
% functionalize the control and references to expedite this
V = zeros(length(T),4);
A = zeros(length(T),4);
W = zeros(length(T),2);

    function dy = eqom(t,y)
        dy = zeros(6,1);
        psi = y(3);
        rjx = y(1);
        rjy = y(2);
        rix = y(4);
        riy = y(5);
        vi = y(7:8);
        
        % agent 1 velocities are prescribed
        [v,omega] = vel(t);
        
        C = [cos(psi) -sin(psi);sin(psi) cos(psi)];%body to inertial
        dy(1:2) = C*v;
        dy(3) = omega;
        
        % agent 2 follows agent 1
        rref = 0.5*(D+L);
        rr = sqrt((rix-rjx)^2+(riy-rjy)^2);
        % tracking error
        er = rr - rref;
        % agent 1 time rates of inertial position
        rjxd = dy(1);
        rjyd = dy(2);
        Am = [rix-rjx riy-rjy];
        bm = r*(-Kr*er) - ((rjx-rix)*rjxd + (rjy-riy)*rjyd);
        rdot_V = Am'./(Am*Am')*bm;
        
        % inverse distance control term
        bm2 = (rix-rjx)*rjxd + (riy-rjy)*rjyd + rr*Kinv*(1/(rr-D)+1/(rr-L));
        rdot_inv = Am'./(Am*Am')*bm2;
        
        rdot_ref = rdot_inv + rdot_V;
        
        % velocity tracking error
        ev = vi - rdot_ref;
        rddot = -Kd*ev;
        % thrust and heading reference
        psi_ref = atan2(rddot(2),rddot(1));
        f_ref = sqrt(rddot(1)^2+rddot(2)^2);
        
        % get heading rate input
        psidot = -Kpsi*(y(6) - psi_ref);
        
        dy(4:5) = vi;
        dy(6) = psidot;
        dy(7:8) = fi*[cos(y(6));sin(y(6))];
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
