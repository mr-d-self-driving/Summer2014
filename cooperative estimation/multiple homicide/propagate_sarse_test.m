function [xhatp,Pkp] = propagate_sarse_test(xhat,Pk,uctrl,imu,Ts,Qk)
% xhat: [rx_n ry_n v1 psi1 ux uy uxdot uydot rho -rhodot/rho
%         1     2   3  4    5  6  7      8    9     10
% uctrl: heading time rate
% imu: [acc1 acc2 gyro] (gyro is redundant)

psi = xhat(4);

rh = xhat(9);
rhdrh = -xhat(10);
uv = xhat(5:6);
uvd = xhat(7:8);

x5 = xhat(5);
x6 = xhat(6);
x7 = xhat(7);
x8 = xhat(8);
x9 = xhat(9);
x10 = xhat(10);

a1 = imu(1);
a2 = imu(2);

% angular velocity matrix
W = [0 -uctrl;uctrl 0];
% time rates
f = zeros(10,1);
f(1:2) = [cos(psi);sin(psi)];
f(3) = [1 0]*([a1;a2] - W*[xhat(3);0]);
f(4) = uctrl;
f(5:6) = xhat(7:8);
f(9) = -xhat(9)*xhat(10);

RHS = [rhdrh^2/rh*uv - 2*rhdrh/rh*uvd - 2*rhdrh/rh*W*uv + 2/rh*W*uvd + 1/rh*W*W*uv + [a1;a2];
    -uvd'*uvd];
M = [-1/rh*eye(2) -uv/rh;
    uv' 0];
f([7 8 10]) = M\RHS;

% check derivative f(7 8 10)
LHS = [[a1;a2] + x10^2/x9*[x5;x6] + 2*x10/x9*[x7;x8] + 2*x10/x9*W*[x5;x6] + 2/x9*W*[x7;x8] + 1/x9*W*W*[x5;x6];-x7^2-x8^2];
% mass matrix, coeffs are x7dot, x8dot, x10dot
M = [-1/x9 0 -x5/x9;
    0 -1/x9 -x6/x9;
    x5 x6 0];
eq = M\LHS;

% linearized matrices
Fk = zeros(10);
Fk(1:2,3) = [cos(psi);sin(psi)];
Fk(1:2,4) = xhat(3)*[-sin(psi);cos(psi)];

Fk(5:6,7:8) = eye(2); % uxdot uydot

Fk(9,10) = -xhat(9);
Fk(9,9) = -xhat(10);
% fuck's sake
Fk([7 8 10],5:10) = [[(- 2*uctrl*x5^2*x6*x7 - 2*x10*x5^2*x6*x8 - a2*x9*x5^2*x6 + x5^2*x7^2 + x5^2*x8^2 + 4*x10*x5*x6^2*x7 - 4*uctrl*x5*x6^2*x8 + 2*a1*x9*x5*x6^2 + 2*uctrl*x6^3*x7 + 2*x10*x6^3*x8 + a2*x9*x6^3 - x6^2*x7^2 - x6^2*x8^2)/(x5^2 + x6^2)^2, (2*uctrl*x10*x5^4 + 2*uctrl*x5^3*x7 + 2*x10*x5^3*x8 + a2*x9*x5^3 + 4*uctrl*x10*x5^2*x6^2 - 4*x10*x5^2*x6*x7 + 4*uctrl*x5^2*x6*x8 - 2*a1*x9*x5^2*x6 - 2*uctrl*x5*x6^2*x7 - 2*x10*x5*x6^2*x8 - a2*x9*x5*x6^2 + 2*x5*x6*x7^2 + 2*x5*x6*x8^2 + 2*uctrl*x10*x6^4)/(x5^2 + x6^2)^2, -(2*x10*x6^2 - 2*uctrl*x5*x6 + 2*x5*x7)/(x5^2 + x6^2),  (2*uctrl*x6^2 + 2*x5*x10*x6 - 2*x5*x8)/(x5^2 + x6^2), -(x6*(a1*x6 - a2*x5))/(x5^2 + x6^2),  (2*x6*(uctrl*x5^2 + x8*x5 + uctrl*x6^2 - x7*x6))/(x5^2 + x6^2)]
    [ -(2*uctrl*x10*x5^4 + 4*uctrl*x10*x5^2*x6^2 + 2*x10*x5^2*x6*x7 - 2*uctrl*x5^2*x6*x8 + a1*x9*x5^2*x6 + 4*uctrl*x5*x6^2*x7 + 4*x10*x5*x6^2*x8 + 2*a2*x9*x5*x6^2 - 2*x5*x6*x7^2 - 2*x5*x6*x8^2 + 2*uctrl*x10*x6^4 - 2*x10*x6^3*x7 + 2*uctrl*x6^3*x8 - a1*x9*x6^3)/(x5^2 + x6^2)^2,                                             (2*x10*x5^3*x7 - 2*uctrl*x5^3*x8 + a1*x9*x5^3 + 4*uctrl*x5^2*x6*x7 + 4*x10*x5^2*x6*x8 + 2*a2*x9*x5^2*x6 - x5^2*x7^2 - x5^2*x8^2 - 2*x10*x5*x6^2*x7 + 2*uctrl*x5*x6^2*x8 - a1*x9*x5*x6^2 + x6^2*x7^2 + x6^2*x8^2)/(x5^2 + x6^2)^2, -(2*uctrl*x5^2 - 2*x6*x10*x5 + 2*x6*x7)/(x5^2 + x6^2), -(2*x10*x5^2 + 2*uctrl*x6*x5 + 2*x6*x8)/(x5^2 + x6^2), -(a2*x5^2 - a1*x6*x5)/(x5^2 + x6^2), -(2*x5*(uctrl*x5^2 + x8*x5 + uctrl*x6^2 - x7*x6))/(x5^2 + x6^2)]
    [(2*x10*x5^2*x7 - 2*uctrl*x5^2*x8 + a1*x9*x5^2 + 4*uctrl*x5*x6*x7 + 4*x10*x5*x6*x8 + 2*a2*x9*x5*x6 - 2*x5*x7^2 - 2*x5*x8^2 - 2*x10*x6^2*x7 + 2*uctrl*x6^2*x8 - a1*x9*x6^2)/(x5^2 + x6^2)^2,                                                                                   -(2*uctrl*x5^2*x7 + 2*x10*x5^2*x8 + a2*x9*x5^2 - 4*x10*x5*x6*x7 + 4*uctrl*x5*x6*x8 - 2*a1*x9*x5*x6 - 2*uctrl*x6^2*x7 - 2*x10*x6^2*x8 - a2*x9*x6^2 + 2*x6*x7^2 + 2*x6*x8^2)/(x5^2 + x6^2)^2,         -(2*uctrl*x6 - 2*x7 + 2*x5*x10)/(x5^2 + x6^2),          (2*x8 + 2*uctrl*x5 - 2*x6*x10)/(x5^2 + x6^2),      -(a1*x5 + a2*x6)/(x5^2 + x6^2),    -(2*x10*x5^2 + 2*x7*x5 + 2*x10*x6^2 + 2*x8*x6)/(x5^2 + x6^2)]];
% add identity for discretization
Fk = Ts*Fk + eye(10);

% the ``control'' is the uctrl, we don't need Bk to propagate it tho
%Bk = zeros(10,1);
%Bk(4,1) = Ts;

% noise sources: [acc1 acc2 gyro/uctrl]
Gk = zeros(10,3);
Gk(3,1) = 1;
Gk(4,3) = 1;
Gk([7 8 10],:) = -[[ -(x6^2*x9)/(x5^2 + x6^2), (x5*x6*x9)/(x5^2 + x6^2),      (2*x6*(x10*x5^2 + x7*x5 + x10*x6^2 + x8*x6))/(x5^2 + x6^2)]
    [ (x5*x6*x9)/(x5^2 + x6^2), -(x5^2*x9)/(x5^2 + x6^2),     -(2*x5*(x10*x5^2 + x7*x5 + x10*x6^2 + x8*x6))/(x5^2 + x6^2)]
    [   -(x5*x9)/(x5^2 + x6^2),   -(x6*x9)/(x5^2 + x6^2), (2*uctrl*x5^2 + 2*x8*x5 + 2*uctrl*x6^2 - 2*x7*x6)/(x5^2 + x6^2)]];

Gk = Gk*Ts;

% propagate my state
xhatp = xhat + f*Ts;
% re-normalize
xhatp(5:6) = xhatp(5:6)./norm(xhatp(5:6));
% propagate the covariance matrix
Pkp = Fk*Pk*Fk' + Gk*Qk*Gk';

end