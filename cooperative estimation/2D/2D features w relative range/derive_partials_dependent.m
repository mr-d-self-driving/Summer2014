%% derive partials_dependent
% derive the partial derivatives of the extra-agent measurements 
clear variables;
close all;

syms phiji rky rkx rix riy rhoji psij real;

thetakj = atan( (rky-riy-rhoji*sin(phiji))/(rkx-rix-rhoji*cos(phiji)) ) - psij;
rhokj = sqrt( (rky-riy - rhoji*sin(phiji))^2 + (rkx-rix-rhoji*cos(phiji))^2 );

x = [rix;riy;phiji;rhoji;psij];

dtheta = sym('theta',[length(x) 1]);
drho = sym('rho',[length(x) 1]);
for i = 1:length(x)
    dtheta(i) = simplify(diff(thetakj,x(i)));
    drho(i) = simplify(diff(rhokj,x(i)));
end

% update step
