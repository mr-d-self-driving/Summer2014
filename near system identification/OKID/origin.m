function [y, x] = origin(a,b,c,d)
global pt dt t
randn('seed',5)
u = randn(2, pt);
[y,x]= dlsim(a,b,c,d,u);

