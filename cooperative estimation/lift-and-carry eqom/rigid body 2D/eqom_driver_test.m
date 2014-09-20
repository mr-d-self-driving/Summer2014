%% eqom_driver_test

clear variables;
close all;
clear eqom;

% y : [vx vy w0 wi wj tid tjd]
y0 = zeros(14,1);

tspan = [0 25];

[T,Y] = ode45(@eqom,tspan,y0);

[m0, mi, mj, I0, Ii, Ij, li, lj, raix, raiy, rajx, rajy] = loadMass();
g = 9.81;

%% compute velocities of quadrotors
vi = zeros(length(T),2);
vj = zeros(length(T),2);
for i = 1:length(T)
    lambda0 = Y(i,10);
    omega0 = Y(i,3);
    thetaid = Y(i,6);
    thetajd = Y(i,7);
    thetai = Y(i,13);
    thetaj = Y(i,14);
    Con = [cos(lambda0) sin(lambda0);-sin(lambda0) cos(lambda0)];
    Cin = [cos(thetai) sin(thetai);-sin(thetai) cos(thetai)];

    vi(i,:) = Y(i,1:2) + [-raiy*omega0 raix*omega0]*Con + li*thetaid*[-sin(thetai) cos(thetai)];
    vj(i,:) = Y(i,1:2) + [-rajy*omega0 rajx*omega0]*Con + lj*thetajd*[-sin(thetaj) cos(thetaj)];
end
% compute energy
KE = 0.5*m0*sum(Y(:,1:2).^2,2) + ...
    0.5*mi*sum(vi.^2,2) + ...
    0.5*mi*sum(vj.^2,2) + ...
    0.5*I0*Y(:,3).^2 + 0.5*Ii*Y(:,4).^2 + 0.5*Ij*Y(:,5).^2;
V = m0*g*Y(:,8) + mi*g*(Y(:,8) + raix + li*cos(Y(:,13))) + mj*g*(Y(:,8) + rajx + lj*cos(Y(:,14)));

%% plots
% plot velocity of CM
figure;
subplot(3,2,1);
plot(T,Y(:,1:2));
ylabel('$v$ (m/s)','Interpreter','latex','fontsize',12);

% plot angular rates
subplot(3,2,3);
plot(T,Y(:,3:5));
ylabel('$\omega$ (rad/s)','Interpreter','latex','fontsize',12);

% plot tether angle rates
subplot(3,2,5);
plot(T,Y(:,6:7));
ylabel('$\dot{\theta}$ (rad/s)','Interpreter','latex','fontsize',12);

% plot position of CM
subplot(3,2,2);
plot(T,Y(:,8:9));
ylabel('$r$ (m)','Interpreter','latex','fontsize',12);

% plot body attitudes
subplot(3,2,4);
plot(T,Y(:,10:12));
ylabel('$\lambda$ (rad)','Interpreter','latex','fontsize',12);

% plot tether angles
subplot(3,2,6);
plot(T,Y(:,13:14));
ylabel('$\theta$ (rad)','Interpreter','latex','fontsize',12);

set(gcf,'position',[625 125 1125 850]);