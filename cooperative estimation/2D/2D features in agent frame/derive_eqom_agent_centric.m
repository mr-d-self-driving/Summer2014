clear variables;
syms psii rkx rky rix riy rhokj rhoki rhoji u v real;
syms thetakj thetaji psij thetaki real;
syms rky rky real;

Cbn = [cos(psii) sin(psii);-sin(psii) cos(psii)];
rhokit = sqrt(sum(( Cbn*[rkx;rky] - [rix;riy]).^2));

rjix = rhoji*cos(thetaji);
rjiy = rhoji*sin(thetaji);
rkxi = [cos(psii) sin(psii)]*[rkx;rky];
rkyi = [-sin(psii) cos(psii)]*[rkx;rky];

%body i frame prediction of feature k position:
rki_bi = [cos(psii) sin(psii);
    -sin(psii) cos(psii)]*[rkx;rky] - [rix;riy];
rkix = rki_bi(1);
rkiy = rki_bi(2);
%measured
rji_bi = rhoji*[cos(thetaji);sin(thetaji)];
rjix = rji_bi(1);
rjiy = rji_bi(2);

% solve for the expectation of rhoki^2 in terms of the measurements and
% estimated states
meas_rhokj = rhokj^2-rhoji^2+2*(rkix*rjix+rkiy*rjiy);
exp_rhokj = sum(rki_bi.^2);

% transformation matrix from agent i frame to j frame
C_bjbi = [cos(psij-psii) sin(psij-psii);-sin(psij-psii) cos(psij-psii)];
%vector from j to k in the b^j+ frame
rkj_bj = C_bjbi*([rkix-rjix;rkiy-rjiy]);
%thetakj = atan(rkj_bj(2)/rkj_bj(1));
meas_thetakj = tan(thetakj)*(cos(psij-psii)*(rkix-rjix)+sin(psij-psii)*(rkiy-rjiy))-sin(psij-psii)*rjix+cos(psij-psii)*rjiy;
exp_thetakj = -sin(psij-psii)*rkix+cos(psij-psii)*rkiy;

dx = [rix riy u v psii];
%% own agent's measurements
for i =1:length(dx)
    drdx(i,:) = simplify(diff(rhokit,dx(i)));
end

rki_b = Cbn*[rkx;rky]-[rix;riy];%body frame expectation of relative vector
thetaki = atan(rki_b(2)/rki_b(1));
for i = 1:length(dx)
    dbdx(i,:) = simplify(diff(thetaki,dx(i)));
end
%% other agent's measurements

% gradient of other range measurement w.r.t. estimated state
for i = 1:length(dx)
    drodx(i,:) = simplify(diff(exp_rhokj,dx(i)));
end

% gradient of other bearing meassurement w.r.t. estimated state
for i = 1:length(dx)
    dbodx(i,:) = simplify(diff(exp_thetakj,dx(i)));
end

%% jacobian of other range measurement w.r.t. each non-estimated variable
% (do I include estimated states here?)
dz = [rhoji;thetaji;rhokj;thetakj;psij;dx([1 2 5])'];
for i = 1:length(dz)
    % jacobian of range measurement
    Jac_r(i,:) = simplify(diff(meas_rhokj,dz(i)));
    %jacobian of bearing measurement
    Jac_b(i,:) = simplify(diff(meas_thetakj,dz(i)));
end