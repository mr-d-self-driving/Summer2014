function xkPlus = update_eq_2_ags_omega(xk,vk,uk)

global Ts;

%xk: 7 x 2N+1
%vk: 6 x 2N+1
% vk(1:3) - process noise associated with my IMU uncertainty
% vk(4:6) - process noise associated with the error in the change in the
% other agent's angular velocity

n = size(xk,1);
v = size(vk,1);

%uk[wi;rji_i]

wi = uk(1:3);

xkPlus = zeros(size(xk));
for k = 1:size(xk,2);
    xhat = xk(:,k);
    vn = vk(:,k);
    wj = xhat(5:7);

    % cosine matrix
    Cji = attparsilent(xhat(1:4),[6 1]);

    % relative angular velocity in j frame
    w = wj-Cji*(wi-vn(1:3));

    A = 0.5*[ -xhat(2:4)';xhat(1)*eye(3) + squiggle(xhat(2:4))];
    xdot = zeros(7,1);
    % quaternion time rate
    xdot(1:4) = A*w;
    
    xkPlus(1:4,k) = xhat(1:4) + Ts*xdot(1:4);
    % angular velocity estimate change
    xkPlus(5:7,k) = xhat(5:7) + vn(4:6);
    %re-normalize
    xkPlus(1:4,k) = xkPlus(1:4,k)/norm(xkPlus(1:4,k));
end

end