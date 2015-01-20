clear all;
close all;

n = 20;
m = 12;

xdot = 0*sym('n',[n,1]);

syms vin1 vin2 vin3 rji1 rji2 rji3 rin1 rin2 rin3 real;
syms qin1 qin2 qin3 qin4 qji1 qji2 qji3 qji4 vjn1 vjn2 vjn3 real;
syms wi1 wi2 wi3 wj1 wj2 wj3 ai1 ai2 ai3 aj1 aj2 aj3 real;
syms v1 v2 v3 v4 v5 v6 v7 v8 v9 v10 v11 v12 real;
syms rk11 rk12 rk13 rk21 rk22 rk23 rk31 rk32 rk33 real;
syms n1 n2 n3 n4 n5 n6 n7 n8 n9 n10 n11 n12 n13 n14 n15 n16 n17 n18 real;

% process noiswe vector
vk = [v1;v2;v3;v4;v5;v6;v7;v8;v9;v10;v11;v12];

% measurement noise vector
nk = [n1;n2;n3;n4;n5;n6;n7;n8;n9;n10;n11;n12;n13;n14;n15;n16;n17;n18];

% vectors of localizer positions in body frame
rk1 = [rk11;rk12;rk13];
rk2 = [rk21;rk22;rk23];
rk3 = [rk31;rk32;rk33];
rkj_j = [rk1 rk2 rk3];

rin = [rin1;rin2;rin3];% inertial frame
vin = [vin1;vin2;vin3];% my body frame
rji = [rji1;rji2;rji3];% my body frame
qin = [qin1;qin2;qin3;qin4];% my body frame
qji = [qji1;qji2;qji3;qji4];% other agent's body frame
vjn = [vjn1;vjn2;vjn3];% other agent's body frame
wi_m = [wi1;wi2;wi3];% my body frame
ai_m = [ai1;ai2;ai3];
wj_m = [wj1;wj2;wj3];
aj_m = [aj1;aj2;aj3];

wi = wi_m - vk(1:3);
wj = wj_m - vk(4:6);
ai = ai_m - vk(7:9);
aj = aj_m - vk(10:12);

Cin = attparsilent(qin,[6 1]);
Cji = attparsilent(qji,[6 1]);

xk = [rin;vin;qin;rji;qji;vjn];
uk = [wi_m;wj_m;ai_m;aj_m];
%% compute the derivative

xdot(1:3) = Cin'*vin;
xdot(4:6) = ai - squiggle(wi)*vin;
% A matrix for qin
Ain = 0.5*[ -qin(2:4)';qin(1)*eye(3) + squiggle(qin(2:4))];
xdot(7:10) = Ain*wi;

xdot(11:13) = (Cji'*vjn-vin) - squiggle(wi)*rji;

% relative angular velocity in j frame
wji = wj-Cji*wi;
% A matrix for q_ji
A = 0.5*[ -qji(2:4)';qji(1)*eye(3) + squiggle(qji(2:4))];
% time rate of relative attitude
xdot(14:17) = A*wji;

xdot(18:20) = aj - squiggle(wj)*vjn;
%% compute the state evolution influence matrices
F = 0*sym('F',[n n]);

for k = 1:n
    F(:,k) = simplify(diff(xdot,xk(k)));
end

B = 0*sym('B',[n m]);
for k = 1:m
    B(:,k) = simplify(diff(xdot,uk(k)));
end

G = 0*sym('G',[n m]);
for k = 1:m
    G(:,k) = simplify(diff(xdot,vk(k)));
end
%% compute the measurement vector
yk = sym('yk',[6 1])*0;

yk(1:9) = sqrt(sum( ...
    (repmat((repmat(rji,1,3)+Cji'*[rk1 rk2 rk3]),1,3)-rkj_j(:,sort(repmat(1:3,1,3))))...
    .^2,1))' + nk(1:9);
%yk(4:6) = sqrt(sum ((repmat(rji,1,3) - [rk1 rk2 rk3]).^2,1) )' + nk(10:18);
yk(10:18) = yk([1 4 7 2 5 8 3 6 9])-nk([1 4 7 2 5 8 3 6 9]) + nk(10:18);

H = sym('H',[18,n])*0;
C = sym('C',[18,18])*0;
for k = 1:n
    H(:,k) = simplify(diff(yk,xk(k)));
end
for k = 1:6
    C(:,k) = simplify(diff(yk,nk(k)));
end