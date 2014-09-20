clear variables;
close all;

syms rx ry lambda0 lambdai lambdaj thetai thetaj real;
syms vx vy w0 wi wj tid tjd real;
syms fi fj torquei torquej real;
syms g real;
syms raix raiy rajx rajy mi mj m0 li lj real;
syms vxd vyd real;
syms w0d wid wjd tidd tjdd real;
syms I0 Ii Ij m0 mi mj real;
% internal rxns
syms Ti Tj real;

% angular velocity cross product matrices
w0sq = squiggle([0;0;w0]);
wisq = squiggle([0;0;tid]);
wjsq = squiggle([0;0;tjd]);

% time rate of ang vel cross product matrices
w0sqd = squiggle([0;0;w0d]);
wisqd = squiggle([0;0;tidd]);
wjsqd = squiggle([0;0;tjdd]);

% attitude matrices and their time rates
Con = DCMConverter(3,lambda0);
Cond = -w0sq*Con;
Condd = -w0sqd*Con + w0sq*w0sq*Con;
Cin = DCMConverter(3,thetai);
Cind = -wisq*Cin;
Cindd = -wisqd*Cin + wisq*wisq*Cin;
Cjn = DCMConverter(3,thetaj);
Cjnd = -wjsq*Cjn;
Cjndd = -wjsqd*Cjn + wjsq*wjsq*Cjn;

% body 0 frame vectors to the anchor points i and j
rai0 = [raix;raiy;0];
raj0 = [rajx;rajy;0];

% position level
r0n = [rx;ry;0];
rin = r0n + Con'*rai0 + Cin'*[li;0;0];
rjn = r0n + Con'*raj0 + Cjn'*[lj;0;0];

% velocity level
v0n = [vx;vy;0];
vin = v0n + Cond'*rai0 + Cind'*[li;0;0];
vjn = v0n + Cond'*raj0 + Cjnd'*[lj;0;0];

% angular velocity
w0n = [0;0;w0];
win = [0;0;wi];
wjn = [0;0;wj];

% angular momenta rates
h0d = [0;0;I0*w0d];
hid = [0;0;Ii*wid];
hjd = [0;0;Ij*wjd];

% acceleration level
a0n = [vxd;vyd;0];
ain = a0n + Condd'*rai0 + Cindd'*[li;0;0];
ajn = a0n + Condd'*raj0 + Cjndd'*[lj;0;0];

% forces
f0n = [-m0*g;0;0] + Cin'*[Ti;0;0] + Cjn'*[Tj;0;0];
fin = DCMConverter(3,lambdai)'*[fi;0;0] + Cin'*[-Ti;0;0] + [-mi*g;0;0];
fjn = DCMConverter(3,lambdaj)'*[fj;0;0] + Cjn'*[-Tj;0;0] + [-mj*g;0;0];

% moments
l0n = simplify(Con'*(squiggle(rai0)*Con*Cin'*[Ti;0;0]) + Con'*(squiggle(raj0)*Con*Cjn'*[Tj;0;0]));
lin = [0;0;torquei];
ljn = [0;0;torquej];

% cardinal vectors
qk = [rx ry lambda0 lambdai lambdaj thetai thetaj];
sk = [vx vy w0 wi wj tid tjd];
Tau0 = sym('T',[3 length(sk)]);
Taui = sym('T',[3 length(sk)]);
Tauj = sym('T',[3 length(sk)]);
rho0 = sym('T',[3 length(sk)]);
rhoi = sym('T',[3 length(sk)]);
rhoj = sym('T',[3 length(sk)]);
for i = 1:length(sk)
    Tau0(:,i) = diff(v0n,sk(i));
    Taui(:,i) = diff(vin,sk(i));
    Tauj(:,i) = diff(vjn,sk(i));
    
    rho0(:,i) = diff(w0n,sk(i));
    rhoi(:,i) = diff(win,sk(i));
    rhoj(:,i) = diff(wjn,sk(i));
end

% K hashtag terms (from kinematics)
K_h = sym('K',[length(sk) 1]);
for i = 1:length(sk)
    K_h(i) = simplify(m0*a0n'*Tau0(:,i) + mi*ain'*Taui(:,i) + mj*ajn'*Tauj(:,i) + h0d'*rho0(:,i) + hid'*rhoi(:,i) + hjd'*rhoj(:,i));
end

% K b terms (from forces/moments)
K_b = sym('K',[length(sk) 1]);
for i = 1:length(sk)
    K_b(i) = simplify(f0n'*Tau0(:,i) + fin'*Taui(:,i) + fjn'*Tauj(:,i) + l0n'*rho0(:,i) + lin'*rhoi(:,i) + ljn'*rhoj(:,i));
end

skd = [vxd vyd w0d wid wjd tidd tjdd];
EXP = simplify(K_h - K_b);
% mass matrix: M*skd = RHS are the coupled governing EQ
M = sym('M',[7 7]);
RHS = sym('R',[7 1]);
for i = 1:7
    for j = 1:7
        M(i,j) = simplify(diff(EXP(i),skd(j)));
    end
    RHS(i) = simplify(-(EXP(i) - M(i,:)*skd'));
end