function [T,Y,V,W,A] = agent_sim_follower(tspan,y0)
% y0: [ rx1, ry1, psi1, rx2, ry2, psi2 ]

Kr = 10^(0.5);% lyapunov gain for reference radius
Kinv = 0*10^(-1.0);% gain for inverse radius controller
Kd = 2.5;% gain for lyapunov for velocity
Kpsi = 10;% gain for agent 2 heading rate controller
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

% append INERTIAL velocity states of agent 2 for simulation
% make the initial velocities match to reduce controller overhead
v01 = vel(tspan(1));
C0 = [cos(y0(3)) -sin(y0(3));sin(y0(3)) cos(y0(3))];
ysim = [y0;C0*v01];

[T,Y] = ode45(@eqom,tspan,ysim,odeset('abstol',1e-5,'reltol',1e-5));

% need to modify this to output the velocity and acceleration histories
% functionalize the control and references to expedite this
V = zeros(length(T),4);
A = zeros(length(T),4);
W = zeros(length(T),2);

% call the vectorized functions first
[rdot_V,er] = rdot_lyapunov(T,Y');
rdot_ref = rdot_V;

% rdot_ref is the inertial frame velocities from the reference controllers
rdot_ref = rdot_V;
[f,psi_r,ev] = accel_lyapunov(T,Y',rdot_ref);
[psidot,epsi] = heading_rate(T,Y',psi_r);
W(:,2) = psidot';

for i = 1:length(T)
    [V(i,1:2),W(i,1),A(i,1:2)] = vel(T(i));
    % inertial to body 2 frame DCM
    C_2n = [cos(Y(i,6)) sin(Y(i,6));
        -sin(Y(i,6)) cos(Y(i,6))];
    % compute body-frame velocity of agent 2 and store
    V(i,3:4) = Y(i,7:8)*C_2n';
    % body 2 inertial frame acceleration
    %a2_n = f(:,i)*[cos(Y(i,6)) sin(Y(i,6))];
    %A(i,3:4) = a2_n*C_2n';
end
A(:,3) = f';

%subplot(211);
%plot(T,er);
%hold on;
%plot(T,sqrt(sum((Y(:,1:2)-Y(:,4:5)).^2,2)),'--');
%ylabel('position tracking error and response');

%subplot(212);
%plot(T,f);
%ylabel('normalized thrust');

% delete unused agent 2 inertial velocity histories
Y(:,7:8) = [];


    function dy = eqom(t,y)
        dy = zeros(6,1);
        psi = y(3);
        vi = y(7:8);% inertial velocity
        
        % agent 1 velocities are prescribed
        [v,omega] = vel(t);
        
        C = [cos(psi) -sin(psi);sin(psi) cos(psi)];%body to inertial
        dy(1:2) = C*v;
        dy(3) = omega;
        
        % get std command from lyapunov control
        rdot_V = rdot_lyapunov(t,y);
        
        % total reference
        rdot_ref = rdot_V;
        
        % thrust command and heading reference
        [f_ref,psi_ref] = accel_lyapunov(t,y,rdot_ref);
        
        % get heading rate input
        psidot = heading_rate(t,y,psi_ref);
        
        dy(4:5) = vi;
        dy(6) = psidot;
        dy(7:8) = f_ref*[cos(y(6));sin(y(6))];
    end
    function [psidot,epsi] = heading_rate(t,y,psi_ref)
        epsi = y(6,:) - psi_ref;
        psidot = -Kpsi*epsi;
    end
    function [f,psi_r,ev] = accel_lyapunov(t,y,rdot_ref)
        % generates thrust and reference heading for tracking radial
        % velocity-level commands
        %
        % note that f is a thrust normalized by mass here
        
        vi = y(7:8,:);
        
        % velocity tracking error
        ev = vi - rdot_ref;
        rddot = -Kd*ev;
        % thrust and heading reference
        psi_r = atan2(rddot(2,:),rddot(1,:));
        psi_r = minangle(psi_r,y(6,:));
        f = sqrt(rddot(1,:).^2+rddot(2,:).^2);
    end
    function [rdot_V,er] = rdot_lyapunov(t,y)
        % return the reference velocity from the lyapunov-based law
        rjx = y(1,:);
        rjy = y(2,:);
        psi = y(3,:);
        rix = y(4,:);
        riy = y(5,:);
        
        rjdot = zeros(2,length(t));
        for j = 1:length(t)
            % agent 1 velocities are prescribed in body frame
            [v,~] = vel(t(j));
            C = [cos(psi(j)) -sin(psi(j));sin(psi(j)) cos(psi(j))];%body to inertial
            % convert to the inertial frame
            rjdot(:,j) = C*v;
        end
        
        % agent 2 follows agent 1
        rref = 0.5*(D+L);
        rr = sqrt((rjx-rix).^2+(rjy-riy).^2);
        % tracking error
        er = rr - rref;
        % agent 1 time rates of inertial position
        rjxd = rjdot(1,:);
        rjyd = rjdot(2,:);
        am = [rix-rjx riy-rjy];
        bm = rr.*(-Kr*er) - ((rjx-rix).*rjxd + (rjy-riy).*rjyd) + rr.*Kinv.*(1./(rr-D)+1./(rr-L));
        rdot_V = zeros(2,length(t));
        for j = 1:length(t)
            Am = am(1,[j length(t)+j]);
            Bm = bm(j);
            rdot_V(:,j) = Am'./(Am*Am')*Bm;
        end
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
        % inertial to body DCM
        C = [cos(psi) sin(psi);
            -sin(psi) cos(psi)];
        v = C*vn;
        a = C*an;
    end
end
