function xkPlus = update_eq_att(xk,vk,uk)

global Ts;

%xk: 6 x 2N+1
%vk: 3 x 2N+1

n = size(xk,1);
v = size(vk,1);

w_eff = uk(1:3);

xkPlus = zeros(size(xk));
for k = 1:size(xk,2);
    xhat = xk(:,k);
    vn = vk(:,k);

    theta = xhat(2);
    phi = xhat(3);

    A_q = [0 sin(phi)/cos(theta) cos(phi)/cos(theta);
        0 cos(phi) -sin(phi);
        1 tan(theta)*sin(phi) tan(theta)*cos(phi)];

    G = [A_q; zeros(3)];
    
    xdot = [A_q*w_eff;0;0;0] + G*vn;
    
    xkPlus(1:n,k) = xhat + Ts*xdot;
end

end