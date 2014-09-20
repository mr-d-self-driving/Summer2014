function [yexp,Hk] = get_exp_inv(xhat)
% get expectation with the inverse range parameterization
% xhat: [rx ry psi rxj ryj rhoj thetaj psij rxt ryt rhot thetat]
%         1  2  3   4   5    6     7     8    9  10  11    12
yexp = zeros(4,1);
Hk = zeros(4,12);

% my expectation of agent 2
psii = pi2pi(xhat(3));
rji = xhat(4:5) + 1/xhat(6)*[cos(xhat(7));sin(xhat(7))] - xhat(1:2);
yexp(1) = atan2(rji(2),rji(1)) - psii;

drjix = [-1 0 0 1 0 -1/xhat(6)^2*cos(xhat(7)) 1/xhat(6)*-sin(xhat(7))];
drjiy = [0 -1 0 0 1 -1/xhat(6)^2*sin(xhat(7)) 1/xhat(6)*cos(xhat(7))];
Hk(1,[1 2 3 4 5 6 7]) = rji(1)^2/(rji(1)^2+rji(2)^2)*(-rji(2)/rji(1)^2*drjix + 1/rji(1)*drjiy) - [0 0 1 0 0 0 0];

% my expectation of target
rti = xhat(9:10) + 1/xhat(11)*[cos(xhat(12));sin(xhat(12))] - xhat(1:2);
yexp(2) = atan2(rti(2),rti(1)) - psii;
drtix = [-1 0 0 1 0 -1/xhat(11)^2*cos(xhat(12)) 1/xhat(11)*-sin(xhat(12))];
drtiy = [0 -1 0 0 1 -1/xhat(11)^2*sin(xhat(12)) 1/xhat(11)*cos(xhat(12))];

Hk(2,[1 2 3 9 10 11 12]) = rti(1)^2/(rti(1)^2+rti(2)^2)*(-rti(2)/rti(1)^2*drtix + 1/rti(1)*drtiy) - [0 0 1 0 0 0 0];

% other agent's expectation of target
psij = pi2pi(xhat(8));
rtj = xhat(9:10) + 1/xhat(11)*[cos(xhat(12));sin(xhat(12))] - xhat(4:5) - 1/xhat(6)*[cos(xhat(7));sin(xhat(7))];
yexp(3) = atan2(rtj(2),rtj(1)) - psij;
drtjx = [-1 0 1/xhat(6)^2*cos(xhat(7)) -1/xhat(6)*-sin(xhat(7)) 0 1 0 -1/xhat(11)^2*cos(xhat(12)) 1/xhat(11)*-sin(xhat(12))];
drtjy = [0 -1 1/xhat(6)^2*sin(xhat(7)) -1/xhat(6)*cos(xhat(7)) 0 0 1 -1/xhat(11)^2*sin(xhat(12)) 1/xhat(11)*cos(xhat(12))];
Hk(3,[4 5 6 7 8 9 10 11 12]) = rtj(1)^2/(rtj(1)^2+rtj(2)^2)*(-rtj(2)/rtj(1)^2*drtjx + 1/rtj(1)*drtjy) - [0 0 0 0 1 0 0 0 0];

% other agent's expectation of me
rij = -rji;
yexp(4) = atan2(rij(2),rij(1)) - psij;
drijx = [-drjix 0];
drijy = [-drjiy 0];
Hk(4,[1 2 3 4 5 6 7 8]) = rij(1)^2/(rij(1)^2+rij(2)^2)*(-rij(2)/rij(1)^2*drijx + 1/rij(1)*drijy) - [0 0 0 0 0 0 0 1];

end