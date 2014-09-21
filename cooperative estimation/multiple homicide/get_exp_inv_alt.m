function [yexp,Hk] = get_exp_inv_alt(xhat)
% get expectation with minimal inverse range parameterization
% xhat: [rx ry psi rhoj thetaj psij rhot thetat]
%         1  2  3   4      5    6     7     8
yexp = zeros(4,1);
Hk = zeros(4,8);

% my expectation of agent 2
yexp(1) = pi2pi(xhat(5) - xhat(3));
Hk(1,[3 5]) = [-1 1];

% my expectation of target
yexp(2) = pi2pi(xhat(8) - xhat(3));
Hk(2,[3 8]) = [-1 1];

% other agent's expectation of target
%r_tj = r_ti - r_ji
rhoj = xhat(4);
thetaj = xhat(5);
psij = xhat(6);
rhot = xhat(7);
thetat = xhat(8);

rtj = 1/rhot*[cos(thetat);sin(thetat)] - 1/rhoj*[cos(thetaj);sin(thetaj)];
yexp(3) = pi2pi(atan2(rtj(2),rtj(1)) - psij);

drtjx = [0 0 0 cos(thetaj)/rhoj^2 sin(thetaj)/rhoj 0 -cos(thetat)/rhot^2 -sin(thetat)/rhot];
drtjy = [0 0 0 sin(thetaj)/rhoj^2 -cos(thetaj)/rhoj 0 -sin(thetat)/rhot^2 cos(thetat)/rhot];
Hk(3,:) = (rtj(1)^2/(rtj(1)^2+rtj(2)^2))*(drtjy/rtj(1) - rtj(2)/rtj(1)^2*drtjx);
Hk(3,6) = -1;

% other agent's expectation of me
yexp(4) = pi2pi(pi - xhat(6) + xhat(5));
Hk(4,[5 6]) = [1 -1];

end