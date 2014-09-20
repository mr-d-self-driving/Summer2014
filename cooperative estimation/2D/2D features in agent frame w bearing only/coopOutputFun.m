function y = coopOutputFun(x)
% function y = coopOutputFun(x)
% 
% computes the output function of an input vector x
% x is of the form: [psi_i psi_j rho_ji theta_ji rho_1j theta_1j rho_2j
% theta_2j ... rho_Mj theta_Mj], whether rho and theta are estimated or
% known
% INPUTS:
%   x: [n x ...] vectorized vector of real or effective measurements
% 
% OUTPUTS:
%   y: computed agent i outputs: [rho_1i, theta_1i, rho_2i, theta_2i, ...
% rho_Mi, theta_Mi]


y = zeros(size(x,1)-4,size(x,2));
for j = 1:size(x,2)
    psii = x(1,j);
    psij = x(2,j);
    rhoji = x(3,j);
    thetaji = x(4,j);
    for i = 1:((size(x,1)-4)/2)
        rhokj = x(4+2*(i-1)+1,j);
        thetakj = x(4+2*(i-1)+2,j);
        alpha = pi-thetakj-psij+psii+thetaji;
        rhoki = sqrt(rhokj^2+rhoji^2-2*rhokj*rhoji*cos(alpha));
        y(2*i-1,j) = rhoki;
        y(2*i,j) = thetaji - atan2((2*rhoji*rhokj*sin(psii - psij + thetaji - thetakj)),(rhoji^2 + rhoki^2 - rhokj^2));
    end
end
end