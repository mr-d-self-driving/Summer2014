function y = coopFunctionBearingOnlyLHS1(x)
% function y = coopFunctionBearingOnlyLHS1(x)
% 
% computes the output function of an input vector x
% x is of the form: [psi_i psi_j rho_ji theta_ji r_jx r_jy theta_1j theta_2j ... theta_Mj]
% INPUTS:
%   x: [n x ...] vectorized vector of real or effective measurements
% 
% OUTPUTS:
%   y: computed agent i outputs: [rho_1i, theta_1i, rho_2i, theta_2i, ...
% rho_Mi, theta_Mi]

y = zeros(size(x,1)-6,size(x,2));
for j = 1:size(x,2)
    thetaji = x(2,j);
    thetaij = x(3,j);
    
    delta = pi - thetaij + thetaji;
    thetakj = x(6+1:end,j);
    y(:,j) = tan(thetakj + delta);
end
end