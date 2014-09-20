function u = vel_ctrl(t,y)
% u: [f1, f2, lambda1, lambda2] perturbed states

persistent Minv c mi mj g fibar fjbar raix raiy rajx rajy;

if isempty(Minv)
    % load mass matrix
    [m0, mi, mj, I0, ~, ~, li, lj, raix, raiy, rajx, rajy] = loadMass();
    % states: [vx vy lambda0dot=w0 thetaidot thetajdot]
    M = [m0+mi+mj 0 -mi*raiy-mj*rajy 0 0;
        0 m0+mi+mj raix*mi+rajx*mj mi*li mj*lj;
        -mi*raiy-mj*rajy mi*raix+mj*rajx mi*(raix^2+raiy^2)+mj*(rajx^2+rajy^2)+I0 mi*raix*li mj*rajx*lj;
        0 mi mi*raix mi*li 0;
        0 mj mj*rajx 0 mj*lj];
    Minv = M\eye(5);
    
    g = 9.81;
    
    fibar = g*(m0+mi+mj)/(1-raiy/rajy);
    fjbar = fibar*-raiy/rajy;
    
    % load steady-state properties
    c = [fibar+fjbar-g*(m0+mi+mj);
    0;
    -raiy*fibar-fjbar*rajy+mi*g*raiy+mj*g*rajy;
    0;
    0];
end

Kvel = diag([10 0 10 10 10]);
xref = vel_ref(t,y);
% x: [vx vy lambda0dot thetaidot thetajdot]
x = y([1 2 3 6 7]);

B = [1 1 0 0;
    0 0 fibar fjbar;
    -raiy -rajy raix*fibar rajx*fjbar;
    0 0 fibar 0;
    0 0 0 fjbar];

f = [zeros(2,5);
    0 0 raix*(mi*g-fibar)+rajx*(mj*g-fjbar) 0 0;
    0 0 0 mi*g-fibar 0;
    0 0 0 0 mj*g-fjbar];

% minimum-norm solution
% apparently vy is unreachable in general, save this problem for later

G = [1 0 0 0 0;
    zeros(3,2) eye(3)];
%G = [eye(2) zeros(2,3)];

A = G*(Minv*B);
d = G*(-Kvel*(x-xref) - Minv*c - Minv*f*x);

u = A'*((A*A')\d);

end