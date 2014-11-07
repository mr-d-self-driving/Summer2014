function xkPlus = update_eq_2_ags(xk,vk,uk)

global Ts;

%xk: n x 2N+1
%vk: v x 2N+1

n = size(xk,1);
v = size(vk,1);

%uk[wi;wj;rji_i]

wi = uk(1:3);
wj = uk(4:6);

xkPlus = zeros(size(xk));
for k = 1:size(xk,2);
    xhat = xk(:,k);
    vn = vk(:,k);

    % cosine matrix
    Cji = attparsilent(xhat,[6 1]);

    % relative angular velocity in j frame
    w = (wj-vn(4:6))-Cji*(wi-vn(1:3));

    A = 0.5*[ -xhat(2:4)';xhat(1)*eye(3) + squiggle(xhat(2:4))];
    xdot = A*w;

    xkPlus(1:n,k) = xhat + Ts*xdot;
    %re-normalize
    xkPlus(1:4,k) = xkPlus(1:4,k)/norm(xkPlus(1:4,k));
end

end