function [h,h_grad] = robot_meas(x)
global markers;%[time theta1 theta2]

%current position estimates
xn = x(1);
yn = x(2);
psi = x(5);
psi = mod(psi,2*pi);
if psi > pi
    psi = psi - 2*pi;
end

h = zeros(size(markers,2),1);
m = length(h);
for i = 1:m
    h(i) = atan2(markers(2,i)-yn,markers(1,i)-xn) - psi;
    h(i) = mod(h(i),2*pi);
    if h(i) > pi
        h(i) = h(i) - 2*pi;
    end
end

%measurement depends on xn, yn, and psi only
h_grad = zeros(m,8);

%dh/dpsi
h_grad(1:m,5) = -1;

for i = 1:m
    h_grad(i,1) = (markers(2,i) - yn)/((markers(2,i) - yn)^2+(markers(1,i)-xn)^2);
    h_grad(i,2) = -(markers(1,i) - xn)/((markers(2,i) - yn)^2+(markers(1,i)-xn)^2);
end

% h_grad_check = zeros(size(h_grad));
% step = 1e-6;
% for i = 1:m
%     for j = 1:8
%         xmod = x;
%         xmod(j) = xmod(j) - step;
%         h_grad_check(i,j) = 1/step*((atan2(markers(2,i)-yn,markers(1,i)-xn) - psi) - (atan2(markers(2,i)-xmod(2),markers(1,i)-xmod(1)) - xmod(5)));
%     end
% end


end