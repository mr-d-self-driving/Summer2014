clear variables;
close all;

syms x5 x6 x7 x8 x9 x10 real;
syms uctrl a1 a2 real;
W = [0 -uctrl; uctrl 0];
LHS = [[a1;a2] + x10^2/x9*[x5;x6] + 2*x10/x9*[x7;x8] + 2*x10/x9*W*[x5;x6] + 2/x9*W*[x7;x8] + 1/x9*W*W*[x5;x6];-x7^2-x8^2];
% mass matrix, coeffs are x7dot, x8dot, x10dot
M = [-1/x9 0 -x5/x9;
    0 -1/x9 -x6/x9;
    x5 x6 0];

eq = M\LHS;

F = sym('F',[3 6]);
xdiff = [x5;x6;x7;x8;x9;x10];
for k = 1:length(xdiff)
    F(:,k) = simplify(diff(eq,xdiff(k)));
end

ctrldiff = [a1;a2;uctrl];
G = sym('G',[3 3]);
for k = 1:length(ctrldiff)
    G(:,k) = simplify(diff(-eq,ctrldiff(k)));
end

%% full derivation with rates as states
% unfortunatly, this is not observable without some more measurements and
% it blows up

clear variables;
close all;

syms x1 x2 x3 x4 x5 x6 x7 x8 x9 x10 real;
syms uctrl a1 a2 real;

f = sym('f',[10,1]);
f(1:2) = x3*[cos(x4);sin(x4)];
f(3) = a1;
f(4) = uctrl;
f(5:6) = [x7;x8];
f(9) = -x10*x9;

W = [0 -uctrl; uctrl 0];
LHS = [[a1;a2] + x10^2/x9*[x5;x6] + 2*x10/x9*[x7;x8] + 2*x10/x9*W*[x5;x6] + 2/x9*W*[x7;x8] + 1/x9*W*W*[x5;x6];-x7^2-x8^2];
% mass matrix, coeffs are x7dot, x8dot, x10dot
M = [-1/x9 0 -x5/x9;
    0 -1/x9 -x6/x9;
    x5 x6 0];

f([7 8 10]) = M\LHS;

F = sym('F',[10 10]);
xdiff = [x1;x2;x3;x4;x5;x6;x7;x8;x9;x10];
for k = 1:length(xdiff)
    F(:,k) = simplify(diff(f,xdiff(k)));
end

ctrldiff = [a1;a2;uctrl];
G = sym('G',[10 3]);
for k = 1:length(ctrldiff)
    G(:,k) = simplify(diff(-f,ctrldiff(k)));
end

% measurement eqs
yex = [x3;atan(x6/x5)];
Hk = sym('H',[2,10]);
for k = 1:length(xdiff)
    Hk(:,k) = simplify(diff(yex,xdiff(k)));
end

Jk = sym('H',[2,3]);
for k = 1:length(ctrldiff)
    Jk(:,k) = simplify(diff(yex,ctrldiff(k)));
end
%% partial derivation
% reduce the states to try to get observability

clear variables;
close all;

syms x1 x2 x3 x4 x5 x6 x9 real;
syms uctrl a1 a2 real;
syms vj1 vj2 real;

W = [0 -uctrl; uctrl 0];
vj = [vj1;vj2];
u = [x5;x6];
rho = x9;
vi = [x3;0];

f = sym('f',[7,1]);
f(1:2) = x3*[cos(x4);sin(x4)];
f(3) = a1;
f(4) = uctrl;

LHS = [-vj+vi+1/x9*W*u;0];
% mass matrix, coeffs are x7dot, x8dot, x10dot
M = [-1/x9 0 x5/x9^2;
    0 -1/x9 x6/x9^2;
    x5 x6 0];

f([5:7]) = M\LHS;

F = sym('F',[7 7]);
xdiff = [x1;x2;x3;x4;x5;x6;x9];
for k = 1:length(xdiff)
    F(:,k) = simplify(diff(f,xdiff(k)));
end

ctrldiff = [a1;a2;uctrl;vj];
G = sym('G',[7 5]);
for k = 1:length(ctrldiff)
    G(:,k) = simplify(diff(-f,ctrldiff(k)));
end

% measurement eqs
yex = [x3;atan(x6/x5)];
Hk = sym('H',[2,7]);
for k = 1:length(xdiff)
    Hk(:,k) = simplify(diff(yex,xdiff(k)));
end

Jk = sym('H',[2,5]);
for k = 1:length(ctrldiff)
    Jk(:,k) = simplify(diff(yex,ctrldiff(k)));
end