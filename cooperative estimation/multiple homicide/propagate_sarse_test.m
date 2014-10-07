function [xhatp,Pkp] = propagate_sarse_test(xhat,Pk,uctrl,imu,Ts,Qk)
% xhat: [rx_n ry_n v1 psi1 ux uy rho vt1 vt2
%         1     2   3  4    5  6  7   8   9
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
vj1 = xhat(8);
vj2 = xhat(9);

a1 = imu(1);
a2 = imu(2);
vi = [xhat(3);0];

% angular velocity matrix
W = [0 -uctrl;uctrl 0];
% time rates
f = zeros(9,1);
f(1:2) = [cos(psi);sin(psi)];
f(3) = [1 0]*([a1;a2] - W*[xhat(3);0]);
f(4) = uctrl;

f(5:7) = [(uctrl*x6^3 + uctrl*x5^2*x6 - x3*x6^2*x9)/(x5^2 + x6^2);
 -(uctrl*x5^3 + uctrl*x5*x6^2 - x3*x5*x6*x9)/(x5^2 + x6^2);
                                 -(x9*(-x3*x5*x9))/(x5^2 + x6^2)];
% target velocity state
f(8:9) = -W*[vj1;vj2];
% linearized matrices
Fk = zeros(9);
Fk(1:2,3) = [cos(psi);sin(psi)];
Fk(1:2,4) = xhat(3)*[-sin(psi);cos(psi)];

Fk(5:7,3:end) = [[ -(x6^2*x9)/(x5^2 + x6^2), 0,                      -(- vj2*x9*x5^2*x6 + x9*(2*vj1 - 2*x3)*x5*x6^2 + vj2*x9*x6^3)/(x5^2 + x6^2)^2, uctrl + (x5^2*(2*vj1*x6*x9 - 2*x3*x6*x9) - vj2*x5^3*x9 + vj2*x5*x6^2*x9)/(x5^2 + x6^2)^2,     -(x6*(vj2*x5 - vj1*x6 + x3*x6))/(x5^2 + x6^2),   (x6^2*x9)/(x5^2 + x6^2), -(x5*x6*x9)/(x5^2 + x6^2)]
[ (x5*x6*x9)/(x5^2 + x6^2), 0, ((x3*x9 - vj1*x9)*x6^3 + 2*vj2*x5*x9*x6^2 + (vj1*x5^2*x9 - x3*x5^2*x9)*x6)/(x5^2 + x6^2)^2 - uctrl,         -(x9*(vj1 - x3)*x5^3 + 2*vj2*x9*x5^2*x6 - x9*(vj1 - x3)*x5*x6^2)/(x5^2 + x6^2)^2,       (vj2*x5^2 - x5*x6*(vj1 - x3))/(x5^2 + x6^2), -(x5*x6*x9)/(x5^2 + x6^2),   (x5^2*x9)/(x5^2 + x6^2)]
[  (x5*x9^2)/(x5^2 + x6^2), 0,                   ((vj1 - x3)*x5^2*x9^2 + 2*vj2*x5*x6*x9^2 + (x3 - vj1)*x6^2*x9^2)/(x5^2 + x6^2)^2,            (- vj2*x5^2*x9^2 + (2*vj1 - 2*x3)*x5*x6*x9^2 + vj2*x6^2*x9^2)/(x5^2 + x6^2)^2, -(2*vj2*x6*x9 + 2*x5*x9*(vj1 - x3))/(x5^2 + x6^2),  -(x5*x9^2)/(x5^2 + x6^2),  -(x6*x9^2)/(x5^2 + x6^2)]];
% add identity for discretization
Fk = Ts*Fk + eye(9);

% noise sources: [acc1 acc2 gyro/uctrl]
Gk = zeros(9,5);
Gk(3,1) = -1;
Gk(4,3) = -1;
Gk(5:7,3:5) = [[ -x6, -(x6^2*x9)/(x5^2 + x6^2), (x5*x6*x9)/(x5^2 + x6^2)]
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