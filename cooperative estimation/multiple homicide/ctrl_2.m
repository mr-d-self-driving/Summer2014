function [u,v,w] = ctrl_2(t,y)
%u : psidot2, v2dot
%v : [r2dot]_ref
%w: r2_ref
% y: [rx ry psi_1 rx ry psi_t rx ry psi_2 v2]

addpath('..\2D');

persistent l1 l2;
persistent ref_last;
if isempty(l1)
    l1 = pi/4*0.5;
    l2 = pi/4*0.5;
    ref_last = [y(10); y(9)];
end

K = diag([0.825 0.825]);

psi1 = y(3);
psi2 = y(9);
psit = y(6);

b1n = [cos(psi1);sin(psi1)];
b2n = [-sin(psi1);cos(psi1)];

%compute range from 1 to target
rhot1 = norm( y(1:2) - y(4:5) );
rho12_ref = rhot1/(cos(l1)+sin(l1)/tan(l2));
r2_ref = rho12_ref*(cos(l1)*b1n + sin(l1)*b2n) + y(1:2);% the sign of the sine changes which side of agent 1 we are on
r2_ref = -10*[-sin(psit);cos(psit)] + y(4:5);% the reference is just 10 out from the target
% compute the velocity/heading reference

w = r2_ref;
e = y(7:8) - r2_ref;

[v,~,exitflag] = fsolve(@fsolverfun,ref_last,optimset('algo','levenberg-marquardt','disp','none'));
v(1) = pi2pi(v(1));

if exitflag <= 0
    ref_last = [0;0];
    [v,~,exitflag] = fsolve(@fsolverfun,ref_last,optimset('algo','levenberg-marquardt','disp','none'));
    v(1) = pi2pi(v(1));
end
while exitflag <= 0
    ref_last = randn(2,1);
    [v,~,exitflag] = fsolve(@fsolverfun,ref_last,optimset('algo','levenberg-marquardt','disp','none'));
    v(1) = pi2pi(v(1));
end

V2MAX = 5;
v(2) = min(v(2),V2MAX);
v(1) = minangle(v(1),psi2);

ref_last = v;

% check if reference velocity is zero and real velocity is zero, do not
% compute psidot reference if so
if v(2) < 1e-2 && y(10) < 1e-2
    u = [0;0];
    return;
end

% compute the time rate of change of the reference 
Aref = [v(2)*[-sin(v(1)); cos(v(1))] [cos(v(1));sin(v(1))]];
vrdot = Aref\(-K*(y(10)*[cos(psi2);sin(psi2)]) - 0);

% compute the velocity/ heading commands
ev = [y(9);y(10)] - v;% error

Kv = diag([1e0 1e0]);

vrdot = 0;
vdref = (-Kv*ev + vrdot);

u = vdref;%psidot, v2dot

    function [f,J] = fsolverfun(v)
        %v: [psi2 v2]_ref
        f = zeros(3,1);
        J = zeros(3,2);
        f(1:2) = v(2)*[cos(v(1));sin(v(1))] + K*e;
        J(1:2,:) = [v(2)*[-sin(v(1));cos(v(1))] [cos(v(1));sin(v(1))] ];
        % enforce velocity > 0
        if v(2) < 0
            f(3) = -v(2);
            J(3,2) = -1;
        end
    end
end