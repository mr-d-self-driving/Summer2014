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

y = zeros(size(x,1)-3,size(x,2));
for j = 1:size(x,2)
    rhoji = x(1,j);
    thetaji = x(2,j);
    thetaij = x(3,j);
    rix = xhatk(1);%x(4,j);
    riy = xhatk(2);%x(5,j);
    psii = xhatk(3);%x(6,j);
    
    delta = thetaji + pi - thetaij;
    
    % loop over landmarks
    counter = 0;
    for i = 1:length(marksUsed)
        if marksUsed(i)
            counter = counter+1;
            thetakj = x(3+counter,j);
            % landmark k's estimated postiion
            rkx = marks(i).xy(1);
            rky = marks(i).xy(2);
            % est. vector from agent i to feature k
            Cbin = [cos(psii) sin(psii);
                -sin(psii) cos(psii)];
            rki_bi = Cbin*[rkx;rky] - [rix;riy];
            rkj_bi = rki_bi - rhoji*[cos(thetaji);sin(thetaji)];
            %Cbjbi = [cos(delta) sin(delta);-sin(delta) cos(delta)];
            %rkj_bj = Cbjbi*rkj_bi;
            tt = atan2(rkj_bi(2),rkj_bi(1));
            tt = minangle(tt,pi2pi(thetakj+delta));
            % store the constraint eq from agent i to landmark k:
            y(counter,j) = tt - pi2pi(thetakj + delta);
        end
    end
end
end