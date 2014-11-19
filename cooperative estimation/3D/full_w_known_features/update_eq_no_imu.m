function xkPlus = update_eq_no_imu(xk,vk,uk)

global Ts;

%xk: 16 x 2N+1, relative quaternion, position, and velocity
%vk: 12 x 2N+1, noise on wi,(wj_est),ai,(aj_est)

%uk[wi;ai;mag_i] : 9 x 2N+1

n = size(xk,1);
v = size(vk,1);

wi = uk(1:3);
ai = uk(4:6);

xkPlus = zeros(size(xk));
for k = 1:size(xk,2);
    xhat = xk(:,k);
    vn = vk(:,k);
    xdot = zeros(10,1);
    
    aj = xhat(11:13);
    wj = xhat(14:16);

    % cosine matrix
    Cji = attparsilent(xhat(1:4),[6 1]);

    % relative angular velocity in j frame
    wji = wj-Cji*(wi-vn(1:3));
    % A matrix for q_ji
    A = 0.5*[ -xhat(2:4)';xhat(1)*eye(3) + squiggle(xhat(2:4))];
    xdot(1:4) = A*wji;

    xdot(5:7) = xhat(8:10) - squiggle(wi-vn(1:3))*xhat(5:7);
    xdot(8:10) = (Cji'*aj - (ai-vn(7:9)))-squiggle(wi-vn(1:3))*xhat(8:10);

    xkPlus(1:10,k) = xhat(1:10) + Ts*xdot;
    xkPlus(11:16,k) = xhat(11:16) + vn([10:12 4:6]);
    %re-normalize
    xkPlus(1:4,k) = xkPlus(1:4,k)/norm(xkPlus(1:4,k));
end

end
