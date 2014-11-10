%% omega_est_check_observability

% quaternion
syms w1 w2 w3 real;
syms wi1 wi2 wi3 real;
syms phi theta psi real;
syms Ts real;

Cji = DCMConverter(1,phi)*DCMConverter(2,theta)*DCMConverter(3,psi);

rji = sym('rji',[3 1]);
rij = sym('rij',[3 1]);
wi = [wi1;wi2;wi3];% my measured ang. vel.

yest = -Cji*rji - rij;

%xhat = [beta0;beta;w1;w2;w3];
xhat = [phi;theta;psi;w1;w2;w3];
n = length(xhat);

% get the H matrix
H = 0*sym('H',[3 n]);

for k = 1:n
    H(:,k) = factor(simplify(diff(yest,xhat(k))));
end

% get the F matrix

B = [ [1;0;0] [DCMConverter(1,phi)*[0;1;0]] [DCMConverter(1,phi)*DCMConverter(2,theta)*[0;0;1]]];%  *[0;0;1] + DCMConverter(1,phi)*[0;1;0] + [1;0;0];
A = simplify(inv(B));
% relative angular velocity, includes estimate term
w = xhat(4:6) - Cji*wi;

xdot = simplify([A*w;0;0;0]);

F = 0*sym('F',[n n]);
for k = 1:n
    F(:,k) = factor(simplify(diff(xdot,xhat(k))));
end
F = eye(n)+Ts*F;

% observability matrix, 7th order
O = 0*sym('O',[21 length(xhat)]);
O(1:3,:) = H;
% it can't handle more than 3 iterations, but 3 is enough to make it think
% the thing is full rank
for k = 2:3
    O((1:3)+(k-1)*3,:) = simplify(O((1:3)+(k-2)*3,:)*F);
end