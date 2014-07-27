function [tref,ref] = linearRandom2D(t,y0)
%y: [X,Y,psi,v1,v2,psidot]
%   [inertial,inertial,inertial->body,body,body,body]

tref = t(1):1:t(end);

vmax = 1;

v1ref = 2/pi*vmax*(atan(tref));
v2ref = 0*tref;

psiref = y0(3) + randn(size(tref))*0.5*pi;

%reference
ref = [zeros(2,length(tref));
    psiref;
    v1ref;
    v2ref;
    zeros(1,length(tref))];
end