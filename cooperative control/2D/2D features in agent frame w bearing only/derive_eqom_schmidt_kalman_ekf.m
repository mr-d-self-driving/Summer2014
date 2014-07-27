clear variables;
syms psii rkx rky rix riy u v rhokj rhoki rhoji rhoki_exp real;
syms uj vj real;%velocity components of j in the b_i frame
syms thetakj thetaji psij thetaki omega real;

Cbn = [cos(psii) sin(psii);-sin(psii) cos(psii)];
rki_b = Cbn*[rkx;rky]-[rix;riy];%body frame expectation of relative vector
rhokit = sqrt(sum(( rki_b ).^2));

% vector from i to j
rhoji_b = rhoji*[cos(thetaji);sin(thetaji)];
rhoji_est = sqrt(sum(rhoji_b.^2));
rjix = rhoji*cos(thetaji);
rjiy = rhoji*sin(thetaji);
drji_dt = [uj;vj]-[u;v] - [0 -omega;omega 0]*rhoji*[cos(thetaji);sin(thetaji)];

% propagation equations for the ``nuisance'' states:
drhoji_dt = simplify(cos(thetaji)*drji_dt(1)+sin(thetaji)*drji_dt(2));
dthetaji_dt = simplify(rjix^2/(rjiy^2+rjix^2)*(drji_dt(2)/rjix - rjiy/rjix^2*drji_dt(1)));

% effective x
dx = [rix riy u v psii];
%effective z
dz = [rhoji thetaji];
%% own agent's measurements
for i =1:length(dx)
    drdx(i,:) = simplify(diff(rhokit,dx(i)));
end

thetaki = atan(rki_b(2)/rki_b(1));
for i = 1:length(dx)
    dtdx(i,:) = simplify(diff(thetaki,dx(i)));
end
%% propagation terms:

for i = 1:length(dx)
    gx(1,i) = simplify(diff(drhoji_dt,dx(i)));
    gx(2,i) = simplify(diff(dthetaji_dt,dx(i)));
end
for i = 1:length(dz)
    gz(1,i) = simplify(diff(drhoji_dt,dz(i)));
    gz(2,i) = simplify(diff(dthetaji_dt,dz(i)));
end

%% measurement (update) terms:
clear Gx Gz;

y_exp = simplify((rki_b(2) - rhoji*sin(thetaji))/(rki_b(1)-rhoji*cos(thetaji)));
for i = 1:length(dx)
    Gx(1,i) = simplify(diff(y_exp,dx(i)));
end
for i = 1:length(dz)
    Gz(1,i) = simplify(diff(y_exp,dz(i)));
end

%% jacobian of other range measurement w.r.t. each non-estimated variable
% (do I include estimated states here?)
dz = [psii;psij;rhoji;thetaji;rhokj;thetakj];
for i = 1:length(dz)
    % jacobian of range measurement
    Jac_r(i,:) = simplify(diff(rhoki_tilde,dz(i)));
    %jacobian of bearing measurement
    Jac_b(i,:) = simplify(diff(thetaki_tilde,dz(i)));
end