function y = coopFunctionBearingOnly(x)
% function y = coopFunctionBearingOnly(x)
% 
% computes the output function of an input vector x
% x is of the form: [psi_i psi_j rho_ji theta_ji r_jx r_jy theta_1j theta_2j ... theta_Mj]
% INPUTS:
%   x: [n x ...] vectorized vector of real or effective measurements
% 
% OUTPUTS:
%   y: computed agent i outputs: [rho_1i, theta_1i, rho_2i, theta_2i, ...
% rho_Mi, theta_Mi]

global marks marksUsed xhatk;

y = zeros(size(x,1)-6,size(x,2));
for j = 1:size(x,2)
    rhoji = x(1,j);
    thetaji = x(2,j);
    thetaij = x(3,j);
    %rix = xhatk(1);
    %riy = xhatk(2);
    %psii = xhatk(5);
    rix = x(4,j);
    riy = x(5,j);
    psii = x(6,j);
    % loop over landmarks
    counter = 0;
    for i = 1:length(marksUsed)
        if marksUsed(i)
            counter = counter+1;
            thetakj = x(6+counter,j);
            % landmark k's estimated postiion
            rkx = marks(i).xy(1);
            rky = marks(i).xy(2);
            % est. vector from agent i to feature k
            Cbin = [cos(psii) sin(psii);-sin(psii) cos(psii)];%inertial-to-b_i transformation
            rki_bi = Cbin*[rkx;rky]-[rix;riy];%body frame expectation of relative vector
            % store the constraint eq from agent i to landmark k:
            tiltil = atan2( rki_bi(2)-rhoji*sin(thetaji) , rki_bi(1)-rhoji*cos(thetaji) );
            tiltil = minangle(tiltil,thetakj + pi - thetaij + thetaji);
            y(counter,j) = tiltil - (thetakj + pi - thetaij + thetaji);
        end
    end
end
end