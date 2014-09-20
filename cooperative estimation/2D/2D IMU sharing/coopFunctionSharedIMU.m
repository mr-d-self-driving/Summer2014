function y = coopFunctionSharedIMU(x)
% function y = coopFunctionSharedIMU(x)
% 
% computes the output function of an input vector x
% x is of the form: [psi_i psi_j rho_ji theta_ji r_jx r_jy theta_1j theta_2j ... theta_Mj]
% INPUTS:
%   x: [n x ...] vectorized vector of real or effective measurements
% 
% OUTPUTS:
%   y: computed agent i outputs: [rho_1i, theta_1i, rho_2i, theta_2i, ...
% rho_Mi, theta_Mi]

global marks marksUsed;

y = zeros(size(x,1),size(x,2));
for j = 1:size(x,2)
    rhoji = x(1,j);
    thetaji = x(2,j);
    
    % do linearization for interagent measurments
    y(1:2,j) = rhoji*[cos(thetaji);sin(thetaji)];
    
    % loop over landmarks
    counter = 0;
    for i = 1:length(marksUsed)
        if marksUsed(i)
            counter = counter+1;
            rhokj = x(2+2*counter-1,j);
            thetakj = x(2+2*counter,j);
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