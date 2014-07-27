function [xkplus,Pkplus,yexp,Rexp] = update_eq(ytilde,z_avail,Pkminus,marks,Rcov,Rrelative,Rheadingother,DEBUG)
% INPUTS
%   ytilde: actual measured [rho_ki, theta_ki, ..., rho_kj, thetakj, ...]
%   z_avail: [rho_ji, theta_ji, psi_j, xk_minus] for getting predicted output
%   Pkminus: a priori covariance
%   marks: landmarks data structure
%   Rcov: measurement covariance from sensors only, for range/bearing
%       measures
%   Rrelative: [range bearing] relative measurment covariances
%   Rheadingother: expected error variance of other agent's heading est.
%   DEBUG: set to 1 to have the function numerically estimate the
%   measurement gradient and use it instead
% OUTPUTS
%   xkplus: updated state (x_k,y_k,psi_k,v1_x,v2_k)
%   Pkplus: updated covariance

% # of landmarks

if nargin < 8
    DEBUG = 0;
end

M = length(ytilde)/4;

xk = z_avail(4:end);

yexp = zeros(4*M,1);
Hk = zeros(4*M,5);
Rexp = zeros(4*M);
Jac = zeros(2*M,6);
for i = 1:M
% get own prediction of landmarks
    delta = marks(i).xy - xk(1:2);
    rangenorm = sqrt(sum(delta.^2));
    % expectations
    yexp(2*i-1) = rangenorm;
    yexp(2*i) = atan2(delta(2),delta(1)) - xk(5);%bearing
    while abs(yexp(2*i)-2*pi-ytilde(2*i)) < abs(yexp(2*i)-ytilde(2*i))
        yexp(2*i) = yexp(2*i)-2*pi;
    end
    while abs(yexp(2*i)+2*pi-ytilde(2*i)) < abs(yexp(2*i)-ytilde(2*i))
        yexp(2*i) = yexp(2*i)+2*pi;
    end
    % gradients
    Hk(2*i-1,:) = -[delta./rangenorm 0 0 0];%range
    Hk(2*i,:) = [delta*[0 -1;1 0]./rangenorm^2 0 0 -1];%bearing meas. gradient
% get prediction of other agent's landmarks
    rhoji = z_avail(1);
    thetaji = z_avail(2);
    psij = z_avail(3);%other agent's estimated heading
    psii = xk(5);% own esimated heading
    %expected bearing of other agent:
    yexp(2*(i+M)) = atan2( delta(2)-rhoji*sin(thetaji+psii),...
        delta(1)-rhoji*cos(thetaji+psii) ) - psij;
    while abs(yexp(2*(i+M))-2*pi-ytilde(2*(i+M))) < abs(yexp(2*(i+M))-ytilde(2*(i+M)))
        yexp(2*(i+M)) = yexp(2*(i+M))-2*pi;
    end
    while abs(yexp(2*(i+M))+2*pi-ytilde(2*(i+M))) < abs(yexp(2*(i+M))-ytilde(2*(i+M)))
        yexp(2*(i+M)) = yexp(2*(i+M))+2*pi;
    end
    %expected range of other agent to landmark
    rangenormkj = sqrt( (delta(1)-rhoji*cos(thetaji+psii))^2+...
        (delta(2)-rhoji*sin(thetaji+psii))^2 );
    yexp(2*(i+M)-1) = rangenormkj;
% gradient of bearing w.r.t. each term [rix riy psii psij rhoji thetaji]
    dbear = zeros(6,1);
    dbear(1) = (delta(2)-rhoji*sin(thetaji+psii))/rangenormkj^2;
    dbear(2) = -(delta(1)-rhoji*cos(thetaji+psii))/rangenormkj^2;
    dbear(3) = (rhoji^2-rhoji*(delta(1)*cos(thetaji+psii) + delta(2)*sin(thetaji+psii)))/rangenormkj^2;
    dbear(4) = -1;
    dbear(5) = (-delta(1)*sin(thetaji+psii)+delta(2)*cos(thetaji+psii))/rangenormkj^2;
    dbear(6) = dbear(3);
% gradient of range w.r.t terms:
    drange = zeros(6,1);
    drange(1) = -(delta(1)-rhoji*cos(thetaji+psii))/rangenormkj;% d/drix
    drange(2) = -(delta(2)-rhoji*sin(thetaji+psii))/rangenormkj;% d/driy
    drange(3) = rhoji/rangenormkj*(-cos(thetaji+psii)*delta(2) + ...
        sin(thetaji+psii)*delta(1));%d/dpsii
    drange(4) = 0;
    drange(5) = (-cos(thetaji+psii)*(delta(1)-rhoji*cos(thetaji+psii))-sin(thetaji+psii)*(delta(2)-rhoji*sin(thetaji+psii)))/rangenormkj;
    drange(6) = drange(3);
% expected or known variances:
    sigma_rix2 = Pkminus(1,1);%variance
    sigma_riy2 = Pkminus(2,2);%variance
    cov_rixriy = Pkminus(1,2);%covariance
    sigma_rhoji2 = Rrelative(1,1);
    sigma_thetaji2 = Rrelative(2,2);
    sigma_psii2 = Pkminus(5,5);
    sigma_psij2 = Rheadingother;
    cov_rixthetai = Pkminus(1,5);
    cov_riythetai = Pkminus(2,5);
% Jacobian of other agent's measurements w.r.t the random variables 
    Jac(2*i,:) = dbear';
    Jac(2*i-1,:)= drange';
% gradient of other agent's bearing:
    Hk(2*(i+M),:) = [dbear(1) dbear(2) 0 0 dbear(3)];
% gradient of other agent's range:
    Hk(2*(i+M)-1,:) = [drange(1) drange(2) 0 0 drange(3)];
    % covariance terms from using measurements in the expectation:
    Rexp(2*(i+M),2*(i+M)) = (sum( dbear.^2.*[sigma_rix2; sigma_riy2; sigma_psii2; sigma_psij2; sigma_rhoji2; sigma_thetaji2] ) + ...
        2*dbear(1)*dbear(2)*cov_rixriy + 2*dbear(1)*dbear(3)*cov_rixthetai + 2*dbear(2)*dbear(3)*cov_riythetai);
    Rexp(2*(i+M)-1,2*(i+M)-1) = (sum( drange.^2.*[sigma_rix2; sigma_riy2; sigma_psii2; sigma_psij2; sigma_rhoji2; sigma_thetaji2] ) + ...
        2*drange(1)*drange(2)*cov_rixriy + 2*drange(1)*drange(3)*cov_rixthetai + 2*drange(2)*drange(3)*cov_riythetai);
end
% [rix riy psii psij rhoji thetaji]
Pk = [Pkminus([1 2 5],[1 2 5]) zeros(3);
    zeros(3) [Rheadingother 0 0;
            [0;0] Rrelative]];
Rexp(2*M+1:end,2*M+1:end) = Jac*Pk*Jac';
Rexp(8,8) = 25*Rexp(8,8);
Rexp(10,10) = 25*Rexp(10,10);
Rexp(12,12) = 25*Rexp(12,12);
if DEBUG
    %[He] = numerical_gradient(xk,yexp,z_avail);
    [He,ye] = matlab_gradient(xk,z_avail);
    if max(max(abs([He-Hk]./He))) > 1e-3
        %disp('Warning: numerical and predicted measurement gradient differ');
    end
    Hk = He;
    yexp = ye;
end
% Kalman gain
Kk = Pkminus*Hk'*((Hk*Pkminus*Hk' + Rcov+Rexp)\eye(4*M));

xkplus = xk' + Kk*(ytilde-yexp);
Pkplus = (eye(5)-Kk*Hk)*Pkminus;

while xkplus(5) > pi
    xkplus(5) = xkplus(5) - 2*pi;
end
while xkplus(5) < -pi
    xkplus(5) = xkplus(5) + 2*pi;
end

    function [He,ye] = matlab_gradient(xk,z_avail)
        He = zeros(4*M,5);
        rhoji = z_avail(1);
        thetaji = z_avail(2);
        psij = z_avail(3);%other agent's estimated heading
        
        ye = zeros(4*M,1);
        for I = 1:M
            delta = marks(I).xy - xk(1:2);
            rangenorm = sqrt(sum(delta.^2));
            % gradients
            He(2*I-1,:) = -[delta./rangenorm 0 0 0];%range
            He(2*I,:) = [delta*[0 -1;1 0]./rangenorm^2 0 0 -1];%bearing meas. gradient
            % expectations
            ye(2*I-1) = rangenorm;
            ye(2*I) = atan2(delta(2),delta(1)) - xk(5);%bearing
            
            % variables for the gradient
            rix = xk(1);
            riy = xk(2);
            rkx = marks(I).xy(1);
            rky = marks(I).xy(2);
            psii = xk(5);
            phiji = thetaji + psii;
            
            thetakj = atan2( (rky-riy-rhoji*sin(phiji)),(rkx-rix-rhoji*cos(phiji)) ) - psij;
            while abs( thetakj - 2*pi - ytilde(2*(I+M))) < abs( thetakj - ytilde(2*(I+M)))
                thetakj = thetakj - 2*pi;
            end
            while abs( thetakj + 2*pi - ytilde(2*(I+M))) < abs( thetakj - ytilde(2*(I+M)))
                thetakj = thetakj + 2*pi;
            end
            rhokj = sqrt( (rky-riy - rhoji*sin(phiji))^2 + (rkx-rix-rhoji*cos(phiji))^2 );
            
            ye(2*I+2*M) = thetakj;%bearing
            ye(2*I-1+2*M) = rhokj;%range
            
            drho = [(2*rix - 2*rkx + 2*rhoji*cos(phiji))/(2*((rix - rkx + rhoji*cos(phiji))^2 + (riy - rky + rhoji*sin(phiji))^2)^(1/2));
                (2*riy - 2*rky + 2*rhoji*sin(phiji))/(2*((rix - rkx + rhoji*cos(phiji))^2 + (riy - rky + rhoji*sin(phiji))^2)^(1/2));
                (2*cos(phiji)*(rix - rkx + rhoji*cos(phiji)) + 2*sin(phiji)*(riy - rky + rhoji*sin(phiji)))/(2*((rix - rkx + rhoji*cos(phiji))^2 + (riy - rky + rhoji*sin(phiji))^2)^(1/2));
                -(2*rhoji*sin(phiji)*(rix - rkx + rhoji*cos(phiji)) - 2*rhoji*cos(phiji)*(riy - rky + rhoji*sin(phiji)))/(2*((rix - rkx + rhoji*cos(phiji))^2 + (riy - rky + rhoji*sin(phiji))^2)^(1/2));
                0];
            dtheta = [ -(riy - rky + rhoji*sin(phiji))/(((riy - rky + rhoji*sin(phiji))^2/(rix - rkx + rhoji*cos(phiji))^2 + 1)*(rix - rkx + rhoji*cos(phiji))^2);
                1/(((riy - rky + rhoji*sin(phiji))^2/(rix - rkx + rhoji*cos(phiji))^2 + 1)*(rix - rkx + rhoji*cos(phiji)));
                (sin(phiji)/(rix - rkx + rhoji*cos(phiji)) - (cos(phiji)*(riy - rky + rhoji*sin(phiji)))/(rix - rkx + rhoji*cos(phiji))^2)/((riy - rky + rhoji*sin(phiji))^2/(rix - rkx + rhoji*cos(phiji))^2 + 1);
                ((rhoji*cos(phiji))/(rix - rkx + rhoji*cos(phiji)) + (rhoji*sin(phiji)*(riy - rky + rhoji*sin(phiji)))/(rix - rkx + rhoji*cos(phiji))^2)/((riy - rky + rhoji*sin(phiji))^2/(rix - rkx + rhoji*cos(phiji))^2 + 1);
                -1];
            % other agent bearing measurement gradient
            He(2*I+2*M,:) = [dtheta(1) dtheta(2) 0 0 dtheta(4)];
            % other agent range measurement gradient
            He(2*I-1+2*M,:) = [drho(1) drho(2) 0 0 drho(4)];
        end
    end
    function [He] = numerical_gradient(xk,yexp,z_avail)
        rhoji = z_avail(1);
        thetaji = z_avail(2);
        psij = z_avail(3);%other agent's estimated heading
        He = zeros(4*M,5);
        for j = 1:5
            xe = xk;
            xe(j) = xe(j) - 1e-6;
            ye = zeros(size(yexp));
            for I = 1:M
                psii = xe(5);% own esimated heading
                % get own prediction of landmarks
                delta = marks(I).xy - xe(1:2);
                rangenorm = sqrt(sum(delta.^2));
                % expectations
                ye(2*I-1) = rangenorm;
                ye(2*I) = atan2(delta(2),delta(1)) - xe(5);%bearing
                while abs(ye(2*I)-2*pi-ytilde(2*I)) < abs(ye(2*I)-ytilde(2*I))
                    ye(2*I) = ye(2*I)-2*pi;
                end
                while abs(ye(2*I)+2*pi-ytilde(2*I)) < abs(ye(2*I)-ytilde(2*I))
                    ye(2*I) = ye(2*I)+2*pi;
                end
                % get prediction of other agent's landmarks
                %expected bearing of other agent:
                ye(2*(I+M)) = atan2( delta(2)-rhoji*sin(thetaji+psii),...
                    delta(1)-rhoji*cos(thetaji+psii) ) - psij;
                while abs(ye(2*(I+M))-2*pi-ytilde(2*(I+M))) < abs(ye(2*(I+M))-ytilde(2*(I+M)))
                    ye(2*(I+M)) = ye(2*(I+M))-2*pi;
                end
                while abs(ye(2*(I+M))+2*pi-ytilde(2*(I+M))) < abs(ye(2*(I+M))-ytilde(2*(I+M)))
                    ye(2*(I+M)) = ye(2*(I+M))+2*pi;
                end
                %expected range of other agent to landmark
                rangenormkj = sqrt( (delta(1)-rhoji*cos(thetaji+psii))^2+...
                    (delta(2)-rhoji*sin(thetaji+psii))^2 );
                ye(2*(I+M)-1) = rangenormkj;
            end
            He(:,j) = (yexp-ye)/1e-6;
        end
    end
end