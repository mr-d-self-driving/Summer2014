clear variables;
syms psii rkx rky rix riy rhokj rhoki rhoji u v rhoki_exp real;
syms thetakj thetaji psij real thetaki;

Cbn = [cos(psii) sin(psii);-sin(psii) cos(psii)];
rhokit = sqrt(sum(( Cbn*[rkx;rky] - [rix;riy]).^2));

alpha = pi-thetakj-psij+psii+thetaji;
rhoki_tilde = sqrt(rhokj^2+rhoji^2-2*rhokj*rhoji*cos(alpha));%range of agent i computed from agent j's measurements

%gamma = asin(rhokj/rhoki_tilde*sin(alpha));
gamma = atan( (rhokj/rhoki*sin(alpha))/((rhokj^2-rhoji^2-rhoki^2)/(-2*rhoji*rhoki)));
%thetaki_tilde = thetaji+gamma;%bearing of agent i computed from agent j's measurements
%thetaji - atan2((2*rhoji*rhokj*sin(psii - psij + thetaji - thetakj)),(rhoji^2 + rhoki^2 - rhokj^2))
thetaki_tilde = thetaji - atan((2*rhoji*rhokj*sin(psii - psij + thetaji - thetakj))/(rhoji^2 + rhoki_exp^2 - rhokj^2));

dx = [rix riy u v psii];
%% own agent's measurements
for i =1:length(dx)
    drdx(i,:) = simplify(diff(rhokit,dx(i)));
end

rki_b = Cbn*[rkx;rky]-[rix;riy];%body frame expectation of relative vector
thetaki = atan(rki_b(2)/rki_b(1));
for i = 1:length(dx)
    dtdx(i,:) = simplify(diff(thetaki,dx(i)));
end
%% other agent's measurements

% gradient of other range measurement w.r.t. estimated state
for i = 1:length(dx)
    drodx(i,:) = simplify(diff(rhokit,dx(i)));
end

% gradient of other bearing meassurement w.r.t. estimated state
for i = 1:length(dx)
    dbodx(i,:) = simplify(diff(thetaki,dx(i)));
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