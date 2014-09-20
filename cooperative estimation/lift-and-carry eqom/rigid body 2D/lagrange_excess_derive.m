clear variables;
close all;

syms r0x r1x r2x r0y r1y r2y real;
syms m0 m1 m2 I0 I2 I1 g real;
syms r0xd r0yd r1xd r1yd r2xd r2yd real;
syms r0xdd r0ydd r1xdd r1ydd r2xdd r2ydd real;
syms lambda0 lambda1 lambda2 lambda0d lambda1d lambda2d lambda0dd lambda1dd lambda2dd real;
syms fq1x fq2x fq1y fq2y l1q l2q real;
% anchor points in the body 0 frame
syms ra1x ra1y ra2x ra2y real;
ra1 = [ra1x;ra1y;0];
ra2 = [ra2x;ra2y;0];

% direction cosine matrices for inertial to body
C0n = DCMConverter(3,lambda0);
C1n = DCMConverter(3,lambda1);
C2n = DCMConverter(3,lambda2);

% forces and moments
% forces, inertial frame
f0n = [0;0;0];
f1n = C1n'*[fq1x;fq1y;0];
f2n = C2n'*[fq2x;fq2y;0];
%moments, inertial frame
l0n = [0;0;0];
l1n = C1n'*[0;0;l1q];
l2n = C2n'*[0;0;l2q];

% position level kinematics, inertial frame
r0 = [r0x;r0y;0];
r1 = [r1x;r1y;0];
r2 = [r2x;r2y;0];

% velocity level
v0 = [r0xd;r0yd;0];
v1 = [r1xd;r1yd;0];
v2 = [r2xd;r2yd;0];

% angular velocity
w0 = [0;0;lambda0d];
w1 = [0;0;lambda1d];
w2 = [0;0;lambda2d];

% kinetic energy
T0 = 1/2*m0*(v0'*v0) + 1/2*I0*(w0'*w0);
T1 = 1/2*m1*(v1'*v1) + 1/2*I1*(w1'*w1);
T2 = 1/2*m2*(v2'*v2) + 1/2*I2*(w2'*w2);

% potential energy
V0 = m0*g*r0x;
V1 = m1*g*r1x;
V2 = m2*g*r2x;

% LaGrangian
L = T0-V0+T1-V1+T2-V2;

% compute dL/dqkdot
qk = [r0x;r0y;r1x;r1y;r2x;r2y;lambda0;lambda1;lambda2];
qkd = [r0xd;r0yd;r1xd;r1yd;r2xd;r2yd;lambda0d;lambda1d;lambda2d];
dLdqkd = sym('L',[9 1]);
for i = 1:9
    dLdqkd(i) = diff(L,qkd(i));
end

% compute d/dt(dL/dqkdot)
qkdd = [r0xdd;r0ydd;r1xdd;r1ydd;r2xdd;r2ydd;lambda0dd;lambda1dd;lambda2dd];
ddtL = sym('L',[9 1]);
for i = 1:9
    % initialize
    ddtL(i) = diff(dLdqkd(i),qkd(1))*qkdd(1);
    for j = 2:9
        ddtL(i) = ddtL(i) + diff(dLdqkd(i),qkd(j))*qkdd(j);
    end
end

% compute dL/dqk
dLdqk = sym('L',[9 1]);
for i = 1:9
    dLdqk(i) = diff(L,qk(i));
end

% compute the holonomic constraints of the form Phi(x,t) = 0
% constraint for body 1
RR = sym('RR',[2 1]);
RR(1) = sqrt(sum((r1 - (r0 + C0n'*ra1)).^2));
RR(2) = sqrt(sum((r2 - (r0 + C0n'*ra2)).^2));

% Phi = d/dt(RR)
Phi = sym('Phi',[2 1]);
for i = 1:2
    Phi(i) = diff(RR(i),qk(1))*qkd(1);
    for j = 2:9
        Phi(i) = Phi(i) + diff(RR(i),qk(j))*qkd(j);
    end
    Phi(i) = simplify(Phi(i));
end

% compute partials of Phi w.r.t. the excess variables r1y and r2y
ppart = sym('pp',[2 2]);
ppart(:,1) = simplify(diff(Phi,r1y));
ppart(:,2) = simplify(diff(Phi,r2y));

% solve the Phi for r1y and r2y
S1 = solve(Phi(1),r1yd); % solution for r1y dot
S2 = solve(Phi(2),r2yd); % solution for r2y dot

% compute the work rate
Wdot = f1n'*v1 + f2n'*v2 + f0n'*v0 + l0n'*w0 + l1n'*w1 + l2n'*w2;

% compute the generalized forces
Qk = sym('Q',[9 1]);
for i = 1:9
    Qk(i) = simplify(diff(Wdot,qkd(i)) + diff(Wdot,r1yd)*diff(S1,qkd(i)) + diff(Wdot,r2yd)*diff(S2,qkd(i)));
end

% compose the governing equations
LHS = sym('L',[9 1]);
RHS = sym('R',[9 1]);
lambdav = sym('lambdav',[2 1]);
for i = 1:9
    LHS(i) = ddtL(i) - dLdqk(i);
    RHS(i) = Qk(i);
    if i == 4 || i == 6
        if i == 4
            jj = 1;
        else
            jj = 2;
        end
        RHS(i) = RHS(i) + ppart(jj,:)*lambdav;
    end
end