function dy = eqom(t,y)
% y : [vxd vyd w0d wid wjd tidd tjdd]

% load static variables;
persistent m0 mi mj I0 Ii Ij g li lj raix raiy rajx rajy fibar fjbar;

if isempty(m0)
    % load from file
    [m0, mi, mj, I0, Ii, Ij, li, lj, raix, raiy, rajx, rajy] = loadMass();
    
    g = 9.81;
    
    fibar = g*(m0+mi+mj)/(1-raiy/rajy);
    fjbar = fibar*-raiy/rajy;
end

% inertial velocities
vx = y(1);
vy = y(2);
% angular velocities
w0 = y(3);
wi = y(4);
wj = y(5);
% tether angular rates
tid = y(6);% theta i dot
tjd = y(7);% theta j dot

rx = y(8);% inertial position of the center body CM
ry = y(9);
% attitudes of central body and quadrotors
lambda0 = y(10);
lambdai = y(11);
lambdaj = y(12);
% oritentation of tethers
thetai = y(13);
thetaj = y(14);

% quadrotor forces and moments

uctrl = vel_ctrl(t,y);

fi = uctrl(1) + fibar;
fj = uctrl(2) + fjbar;

% PD control for the lambdai
torquei = 1*(uctrl(3)-lambdai) - wi;
torquej = 1*(uctrl(4)-lambdaj) - wj;

% mass matrix
M = [[                                                                                m0 + mi + mj,                                                                                         0, - mi*raiy*cos(lambda0) - mj*rajy*cos(lambda0) - mi*raix*sin(lambda0) - mj*rajx*sin(lambda0),  0,  0,                                              -li*mi*sin(thetai),                                              -lj*mj*sin(thetaj)]
    [                                                                                           0,                                                                              m0 + mi + mj,     mi*(raix*cos(lambda0) - raiy*sin(lambda0)) + mj*(rajx*cos(lambda0) - rajy*sin(lambda0)),  0,  0,                                               li*mi*cos(thetai),                                               lj*mj*cos(thetaj)]
    [ - mi*raiy*cos(lambda0) - mj*rajy*cos(lambda0) - mi*raix*sin(lambda0) - mj*rajx*sin(lambda0), mi*raix*cos(lambda0) + mj*rajx*cos(lambda0) - mi*raiy*sin(lambda0) - mj*rajy*sin(lambda0),                                          mi*raix^2 + mi*raiy^2 + mj*rajx^2 + mj*rajy^2 + I0,  0,  0, li*mi*(raix*cos(lambda0 - thetai) - raiy*sin(lambda0 - thetai)), lj*mj*(rajx*cos(lambda0 - thetaj) - rajy*sin(lambda0 - thetaj))]
    [                                                                                           0,                                                                                         0,                                                                                           0, Ii,  0,                                                               0,                                                               0]
    [                                                                                           0,                                                                                         0,                                                                                           0,  0, Ij,                                                               0,                                                               0]
    [                                                                          -li*mi*sin(thetai),                                                                         li*mi*cos(thetai),                             li*mi*(raix*cos(lambda0 - thetai) - raiy*sin(lambda0 - thetai)),  0,  0,                                                         li^2*mi,                                                               0]
    [                                                                          -lj*mj*sin(thetaj),                                                                         lj*mj*cos(thetaj),                             lj*mj*(rajx*cos(lambda0 - thetaj) - rajy*sin(lambda0 - thetaj)),  0,  0,                                                               0,                                                         lj^2*mj]];

RHS = [fi*cos(lambdai) - g*mi - g*mj - g*m0 + fj*cos(lambdaj) + li*mi*tid^2*cos(thetai) + lj*mj*tjd^2*cos(thetaj) + mi*raix*w0^2*cos(lambda0) + mj*rajx*w0^2*cos(lambda0) - mi*raiy*w0^2*sin(lambda0) - mj*rajy*w0^2*sin(lambda0)
    fi*sin(lambdai) + fj*sin(lambdaj) + mi*raiy*w0^2*cos(lambda0) + mj*rajy*w0^2*cos(lambda0) + li*mi*tid^2*sin(thetai) + lj*mj*tjd^2*sin(thetaj) + mi*raix*w0^2*sin(lambda0) + mj*rajx*w0^2*sin(lambda0)
    g*mi*raiy*cos(lambda0) - fj*rajy*cos(lambda0 - lambdaj) - fi*raix*sin(lambda0 - lambdai) - fj*rajx*sin(lambda0 - lambdaj) - fi*raiy*cos(lambda0 - lambdai) + g*mj*rajy*cos(lambda0) + g*mi*raix*sin(lambda0) + g*mj*rajx*sin(lambda0) - li*mi*raiy*tid^2*cos(lambda0 - thetai) - lj*mj*rajy*tjd^2*cos(lambda0 - thetaj) - li*mi*raix*tid^2*sin(lambda0 - thetai) - lj*mj*rajx*tjd^2*sin(lambda0 - thetaj)
    torquei
    torquej
    li*(fi*sin(lambdai - thetai) + g*mi*sin(thetai) + mi*raiy*w0^2*cos(lambda0 - thetai) + mi*raix*w0^2*sin(lambda0 - thetai))
    lj*(fj*sin(lambdaj - thetaj) + g*mj*sin(thetaj) + mj*rajy*w0^2*cos(lambda0 - thetaj) + mj*rajx*w0^2*sin(lambda0 - thetaj))];

dy = zeros(14,1);
dy(1:7)  = M\RHS;
dy(8:9) = [vx;vy];
dy(10:12) = [w0;wi;wj];
dy(13:14) = [tid;tjd];
end