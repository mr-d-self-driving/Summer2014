function [f,f_grad] = robot_dyn(x,u,t,opt)

if nargin < 4
    opt = [];
end

%states
psi = x(5);
vx = x(3);
vy = x(4);
bx = x(6);%x accleration bias
by = x(7);
br = x(8);%yaw rate bias

%measurements
ax = u(1);
ay = u(2);
r = u(3);

f = zeros(8,1);

%xdot, ydot (inertial)
f(1:2) = [cos(psi) -sin(psi);sin(psi) cos(psi)]*[vx;vy];
f(3) = -bx + (r-br)*vy + ax;
f(4) = -by - (r-br)*vx + ay;
f(5) = -br + r;
f(6:8) = 0;

%gradient
f_grad = zeros(8);

f_grad(1,3) = cos(psi);% diff(xdot),vx
f_grad(1,4) = -sin(psi);% diff(xdot),vy
f_grad(1,5) = -vx*sin(psi)-vy*cos(psi);% diff(xdot),psi

f_grad(2,3) = sin(psi);
f_grad(2,4) = cos(psi);
f_grad(2,5) = vx*cos(psi)-vy*sin(psi);% diff(ydot),psi

f_grad(3,4) = r-br;% diff(vxdot,vy)
f_grad(3,6) = -1;% diff(vxdot,bx)
f_grad(3,8) = -vy;% diff(vxdot,br)

f_grad(4,3) = br-r;%diff(vydot,vx)
f_grad(4,7) = -1;%diff(vydot,by)
f_grad(4,8) = vx;%diff(vydot,br)

f_grad(5,8) = -1;%diff(psidot,br)

% if isempty(opt)
%     f_grad_check = zeros(8);
%     step = 1e-6;
%     for j = 1:8
%         xmod = x;
%         xmod(j) = xmod(j) - step;
%         f_grad_check(:,j) = (robot_dyn(x,u,t,1) - robot_dyn(xmod,u,t,1))/step;
%     end
% end
end