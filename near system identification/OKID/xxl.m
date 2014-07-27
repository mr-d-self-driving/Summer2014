% 4 Differnetial Equations for Nonlinear System
function xdd = xl(x,t,u)

w = 0;
f(1) = x(2);
f(2) = -1010.6976*x(3) - 1.5792*x(4) - 1.0*x(1) - 0.01*u(1)-15.68 + w ;
f(3) = x(4);
f(4) = 39.2*cos(x(3)) + 2526.7439*cos(x(3))*x(3) + 3.9480*cos(x(3))*x(4) + ...
       3.92*sin(x(3)) + 199.4305*sin(x(3))*x(3)^2 + 0.62322*sin(x(3))*x(3)*x(4) + ...
       0.0005*sin(x(3))*x(4)^2+0.1*u(2) - 18.816; 
xdd = f';
