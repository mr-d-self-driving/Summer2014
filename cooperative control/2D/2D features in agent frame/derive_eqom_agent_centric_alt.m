clear variables;
syms psii rkx rky rix riy rhokj rhoki rhoji u v real;
syms thetakj thetaji psij thetaki real;
syms rky rky real;

Cbn = [cos(psii) sin(psii);-sin(psii) cos(psii)];
rhokit = sqrt(sum(( Cbn*[rkx;rky] - [rix;riy]).^2));

Cbin = Cbn;
Cbjn = [cos(psij) sin(psij);-sin(psij) cos(psij)];
rkit_bi = Cbin*Cbjn'*rhokj*[cos(thetakj);sin(thetakj)] + rhoji*[cos(thetaji);sin(thetaji)];

meas_rhokj = simplify(sqrt(sum(rkit_bi.^2)));
exp_rhokj = rhokit;

rki_b = Cbn*[rkx;rky]-[rix;riy];%body frame expectation of relative vector
meas_thetakj = atan(rkit_bi(2)/rkit_bi(1));
exp_thetakj = atan(rki_b(2)/rki_b(1));

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
% (do I include estimated states k?)
dz = [rhoji;thetaji;rhokj;thetakj;psij;dx([1 2 5])'];
for i = 1:length(dz)
    % jacobian of range measurement
    Jac_r(i,:) = simplify(diff(meas_rhokj,dz(i)));
    %jacobian of bearing measurement
    Jac_b(i,:) = simplify(diff(meas_thetakj,dz(i)));
end