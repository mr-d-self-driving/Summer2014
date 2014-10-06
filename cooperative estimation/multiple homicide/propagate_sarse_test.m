function [xhatp,Pkp] = propagate_sarse_test(xhat,Pk,uctrl,wk,Ts,Qk)
% xhat: [rx_n ry_n v1 psi1 ux uy uxdot uydot rho -rhodot/rho
%         1     2   3  4    5  6  7      8    9     10
% uctrl: heading time rate

psi = xhat(4);

rh = xhat(9);
rhdrh = -xhat(10);
uv = xhat(5:6);
uvd = xhat(7:8);

% time rates
f = zeros(10,1);
f(1:2) = [cos(psi);sin(psi)];
f(3) = 0;
f(4) = uctrl;
f(5:6) = xhat(7:8);
f(9) = -xhat(9)*xhat(10);

W = [0 -uctrl;uctrl 0];
RHS = [rhdrh^2/rh*uv - 2*rhdrh/rh*rvd - 2*rhdrh/rh*W*uv + 2/rh*W*uvd + 1/rh*W*W*uv;;
    -uvd'*uvd];
M = [-1/rh*eye(2) -uv/rh;
    uv' 0];
f([7 8 10]) = M\RHS;

% linearized matrices
Fk = eye(10);
Fk(1:2,3) = Ts*[cos(psi);sin(psi)];
Fk(5:6,7:8) = Ts*eye(2); % uxdot uydot
Fk(9,10) = -xhat(9);
Fk(9,9) = -xhat(10);
% fuck's sake

Bk = zeros(10,1);
Bk(4,1) = Ts;

Gk = zeros(10,1);

% propagate my state
xhatp = Fk*xhat + Bk*[wk;uctrl];
Pkp = Fk*Pk*Fk' + Gk*Qk*Gk';

end