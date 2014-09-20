function [yexp,Hk] = get_exp(xhat)

yexp = zeros(4,1);
Hk = zeros(4,8);

% process agent 1's measurement of agent 2 first
psii = pi2pi(xhat(3));
% own bearing measurement of other agent
rji_i = xhat(4:5) - xhat(1:2);
yexp(1) = atan2(rji_i(2),rji_i(1)) - psii;
drjix = [-1 0 0 1 0];
drjiy = [0 -1 0 0 1];
Hk(1,[1 2 3 4 5]) = rji_i(1)^2/(rji_i(1)^2+rji_i(2)^2)*(-rji_i(2)/rji_i(1)^2*drjix + 1/rji_i(1)*drjiy) - [0 0 1 0 0];

% agent 1's measurement of target
rti_i = xhat(7:8) - xhat(1:2);
yexp(2) = atan2(rti_i(2),rti_i(1)) - psii;
drtix = [-1 0 0 1 0];
drtiy = [0 -1 0 0 1];
Hk(2,[1 2 3 7 8]) = rti_i(1)^2/(rti_i(1)^2+rti_i(2)^2)*(-rti_i(2)/rti_i(1)^2*drtix + 1/rti_i(1)*drtiy) - [0 0 1 0 0];

% agent 2's measurement of target
psij = pi2pi(xhat(6));
rtj_j = xhat(7:8) - xhat(4:5);
yexp(3) = atan2(rtj_j(2),rtj_j(1)) - psij;
drtjx = [-1 0 0 1 0];
drtjy = [0 -1 0 0 1];
Hk(3,[4 5 6 7 8]) = rtj_j(1)^2/(rtj_j(1)^2+rtj_j(2)^2)*(-rtj_j(2)/rtj_j(1)^2*drtjx + 1/rtj_j(1)*drtjy) - [0 0 1 0 0];

% agent 2's bearing measurement of agent 1
rij_j = xhat(1:2) - xhat(4:5);
yexp(4) = atan2(rij_j(2),rij_j(1)) - psij;
drijx = [-1 0 0 1 0];
drijy = [0 -1 0 0 1];
Hk(4,[4 5 6 1 2]) = rij_j(1)^2/(rij_j(1)^2+rij_j(2)^2)*(-rij_j(2)/rij_j(1)^2*drijx + 1/rij_j(1)*drijy) - [0 0 1 0 0];

end