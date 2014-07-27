clear variables;
syms psii rkx rky rix riy rhokj rhoki rhoji u v rhoki_exp real;
syms thetakj thetaji thetaij psij real thetaki;

Cbn = [cos(psii) sin(psii);-sin(psii) cos(psii)];
rki_b = Cbn*[rkx;rky]-[rix;riy];%body frame expectation of relative vector
rhokit = sqrt(sum(( rki_b ).^2));

dx = [rix riy u v psii];
%% own agent's measurements
for i =1:length(dx)
    drdx(i,:) = simplify(diff(rhokit,dx(i)));
end

thetaki = atan(rki_b(2)/rki_b(1));
for i = 1:length(dx)
    dtdx(i,:) = simplify(diff(thetaki,dx(i)));
end
%% other agent's measurements

delta = pi - thetaij + thetaji;
rhs = atan((rki_b(2) - rhoji*sin(thetaji))/(rki_b(1) - rhoji*cos(thetaji))) - (thetakj + delta);

% gradient of other ``prediction'' w.r.t. estimated state
for i = 1:length(dx)
    dbodx(i,:) = simplify(diff(rhs,dx(i)));
end

%% jacobian of other range measurement w.r.t. each non-estimated variable
% (do I include estimated states here?)
dz = [rhoji;thetaji;thetaij;rix;riy;psii;thetakj];
for i = 1:length(dz)
    %jacobian of bearing measurement
    Jac_b(i,:) = simplify(diff(rhs,dz(i)));
end
%% derive delta value
syms delta real;
% b^i frame to b^j frame
Cbjbi = [cos(delta) sin(delta);-sin(delta) cos(delta)];

bj1 = Cbjbi(1,:)';
bj2 = Cbjbi(2,:)';

rji_bi = rhoji*[cos(thetaji);sin(thetaji)];
solve((rji_bi'*bj2)/(rji_bi'*bj1) - tan(thetaij),delta)