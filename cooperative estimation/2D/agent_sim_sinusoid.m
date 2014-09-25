function [T,Y,V,W,A] = agent_sim_sinusoid(tspan,y0)

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
        % path is of the form y(x) = A*sin(N*pi/2/r0 * x)
        %
        % r0 is a variable locally accesible
        
        % spatial oscillation periodicity variable:
        N = 6;
        % spatial oscillation freq
        ww = 0.5*N*pi/r0;
        % spatial oscillation amplitude
        Am = 2.5;
        % spatial speed, constant for simplicity
        xdot = -2*r0/(tspan(end)-tspan(1));
        
        % position as a function of time in the frame aligned with the
        % sinusoid
        xt = xdot*(t-tspan(1));
        rt = [r0;0] + [xt;-Am*sin(ww*xt)];
        % sinusoid frame time rate of position
        rdot_b = xdot*[1;-Am*ww*cos(ww*xt)];
        % sinusoid second time rate of position
        rddot_b = xdot^2*[0;Am*ww^2*sin(ww*xt)];
        
        % heading, relative to the sinusoid frame, is tangent to the sinusoid at every point
        gamma = pi/2-atan(Am*ww*cos(ww*xt));
        psi_t = gamma + pi/2;% rotation from sinusoid to vehicle frame
        
        % velocity in the vehicle frame
        Cvb = [cos(psi_t) sin(psi_t);-sin(psi_t) cos(psi_t)]; % sinusoid to vehicle frame conversion
        v = Cvb*rdot_b;
        
        % time rate of heading
        w = Am*ww^2*sin(ww*xt)*xdot/(1+(Am*ww*cos(xt*ww))^2);
        
        % acceleration in the vehicle frame
        a = Cvb*rddot_b;
    end
end