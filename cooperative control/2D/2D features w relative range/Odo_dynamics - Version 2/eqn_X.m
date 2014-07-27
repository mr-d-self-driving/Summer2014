function xdot = eqn_X(t,x)

global u w

xdot(1,1) = u*cos(x(3));
xdot(2,1) = u*sin(x(3));
xdot(3,1) = w;