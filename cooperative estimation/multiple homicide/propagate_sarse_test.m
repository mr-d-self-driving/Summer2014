function [xhatp,Pkp] = propagate_sarse_test(xhat,Pk,uctrl,imu,Ts,Qk)
% xhat: [rx_n ry_n v1 psi1 ux uy rho
%         1     2   3  4    5  6  7
% uctrl: heading time rate
% imu: [acc1 acc2 gyro] (gyro is redundant)
% noise terms: [a1 a2 omega v_target1 v_target2]

psi = xhat(4);

rh = xhat(7);
uv = xhat(5:6);

x3 = xhat(3);
x4 = xhat(4);
x5 = xhat(5);
x6 = xhat(6);
x9 = xhat(7);

a1 = imu(1);
a2 = imu(2);
vi = [xhat(3);0];

% angular velocity matrix
W = [0 -uctrl;uctrl 0];
% time rates
f = zeros(7,1);
f(1:2) = [cos(psi);sin(psi)];
f(3) = [1 0]*([a1;a2] - W*[xhat(3);0]);
f(4) = uctrl;

LHS = [vi+1/x9*W*[x5;x6];0];
% mass matrix, coeffs are x7dot, x8dot, x10dot
M = [-1/x9 0 x5/x9^2;
    0 -1/x9 x6/x9^2;
    x5 x6 0];
f(5:7) = M\LHS;

% linearized matrices
Fk = zeros(7);
Fk(1:2,3) = [cos(psi);sin(psi)];
Fk(1:2,4) = xhat(3)*[-sin(psi);cos(psi)];

Fk(5:7,3:7) = [[ -(x6^2*x9)/(x5^2 + x6^2), 0,                                                                      (x6*x9*(2*x3*x5*x6))/(x5^2 + x6^2)^2, (uctrl*x5^4 + uctrl*x6^4 + 2*uctrl*x5^2*x6^2 - 2*x3*x5^2*x6*x9)/(x5^2 + x6^2)^2,   -(x6*(x3*x6))/(x5^2 + x6^2)]
    [ (x5*x6*x9)/(x5^2 + x6^2), 0, -(uctrl*x5^4 + uctrl*x6^4 - x3*x6^3*x9 + 2*uctrl*x5^2*x6^2 + x3*x5^2*x6*x9)/(x5^2 + x6^2)^2,                                                  -(x5*x9*(-x3*x5^2 + x3*x6^2))/(x5^2 + x6^2)^2,    (x5*(x3*x6))/(x5^2 + x6^2)]
    [  (x5*x9^2)/(x5^2 + x6^2), 0,                                                                (x9^2*(- x3*x5^2 + x3*x6^2))/(x5^2 + x6^2)^2,                                                          -(x9^2*(2*x3*x5*x6))/(x5^2 + x6^2)^2, -(2*x9*(-x3*x5))/(x5^2 + x6^2)]];
% add identity for discretization
Fk = Ts*Fk + eye(7);

% noise sources: [acc1 acc2 gyro/uctrl]
Gk = zeros(7,3);
Gk(3,1) = -1;
Gk(4,3) = -1;
Gk(5:7,3:5) = -[[ -x6, -(x6^2*x9)/(x5^2 + x6^2), (x5*x6*x9)/(x5^2 + x6^2)]
[  x5, (x5*x6*x9)/(x5^2 + x6^2), -(x5^2*x9)/(x5^2 + x6^2)]
[   0,  (x5*x9^2)/(x5^2 + x6^2),  (x6*x9^2)/(x5^2 + x6^2)]];

Gk = Gk*Ts;

% propagate my state
xhatp = xhat + f*Ts;
% re-normalize
xhatp(5:6) = xhatp(5:6)./norm(xhatp(5:6));
% propagate the covariance matrix
Pkp = Fk*Pk*Fk' + Gk*Qk*Gk';

end