function [yexp,Hk] = get_exp_sarse_test(xhat)
% get expectation with the inverse range parameterization
% xhat: [rx_n ry_n v1 psi1 ux uy uxdot uydot rho -rhodot/rho
%         1     2   3  4    5  6  7      8    9     10

yexp = zeros(3,1);
Hk = zeros(3,10);

% my expectation of velocity:
yexp(1) = xhat(3);
Hk(1,3) = 1;

% my expectation of the components ux uy of the unit vector to target
yexp(2:3) = xhat(5:6);
Hk(2:3,5:6) = eye(2);

end