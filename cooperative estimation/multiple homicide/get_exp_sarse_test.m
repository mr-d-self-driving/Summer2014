function [yexp,Hk] = get_exp_sarse_test(xhat)
% get expectation with the inverse range parameterization
% xhat: [rx_n ry_n v1 psi1 ux uy rho
%         1     2   3  4    5  6  7

yexp = zeros(2,1);
Hk = zeros(2,7);

% my expectation of velocity:
yexp(1) = xhat(3);
Hk(1,3) = 1;

% my expectation of the components ux uy of the unit vector to target
yexp(2) = atan2(xhat(6),xhat(5));
Hk(2,5:6) = (xhat(5)^2/(xhat(5)^2+xhat(6)^2))*[-xhat(6)/xhat(5)^2 1/xhat(5)];

end