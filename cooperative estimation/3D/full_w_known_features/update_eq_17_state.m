function xkPlus = update_eq_17_state(xk,vk,uk)

global Ts;

%xk: 17 x 2N+1, inertial position, inertial velocity, inertial quaternion, relative position, and relative quaternion
%vk: 12 x 2N+1, noise on wi,(wj_est),ai,(vj_inertial)

%uk[wi;ai;mag_i] : 9 x 2N+1

n = size(xk,1);
v = size(vk,1);

% IMU measurements of me
wi_m = uk(1:3);
ai_m = uk(4:6);

xkPlus = zeros(size(xk));
for k = 1:size(xk,2);
    xhat = xk(:,k);
    % hist position relative to my. My body frame
    rji = xhat(11:13);
    % my velocity
    vin = xhat(4:6);
    % my attitude
    qin = xhat(7:10);
    % his attitude relative to mine. His body frame
    qji = xhat(14:17);
    
    vn = vk(:,k);
    xdot = zeros(17,1);
    
    vj = vn(10:12);
    wj = vn(4:6);
    
    wi = wi_m + vn(1:3);
    ai = ai_m + vn(7:9);
    
    % cosine matrix
    Cin = attparsilent(qin,[6 1]);
    % time rate of my position
    xdot(1:3) = Cin'*vin;
    % time rate of my velocity
    xdot(4:6) = ai - squiggle(wi)*vin;
    % time rate of my attitude
    % A matrix for qin
    Ain = 0.5*[ -qin(2:4)';qin(1)*eye(3) + squiggle(qin(2:4))];
    xdot(7:10) = Ain*wi;

    % relative attitude cosine matrix
    Cji = attparsilent(qji,[6 1]);

    % relative angular velocity in j frame
    wji = wj-Cji*wi;
    % A matrix for q_ji
    A = 0.5*[ -qji(2:4)';qji(1)*eye(3) + squiggle(qji(2:4))];
    % time rate of relative attitude
    xdot(14:17) = A*wji;
    
    % time rate of relative position
    xdot(11:13) = (vj-vin) - squiggle(wi)*rji;

    xkPlus(:,k) = xhat(:) + Ts*xdot;
    %re-normalize
    xkPlus(7:10,k) = xkPlus(7:10,k)/norm(xkPlus(7:10,k));
    xkPlus(14:17,k) = xkPlus(14:17,k)/norm(xkPlus(14:17,k));
end

end
