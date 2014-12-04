function xkPlus = update_eq_10_state(xk,vk,uk)

global Ts;

%xk: 10 x 2N+1, inertial position, inertial velocity, inertial quaternion, relative position, and relative quaternion
%vk: 6 x 2N+1, noise on wi,ai

%uk[wi;ai] : 6 x 2N+1

n = size(xk,1);
v = size(vk,1);

% IMU measurements of me
wi_m = uk(1:3);
ai_m = uk(4:6);

xkPlus = zeros(size(xk));
for k = 1:size(xk,2);
    xhat = xk(:,k);
    % my velocity
    vin = xhat(4:6);
    % my attitude
    qin = xhat(7:10);
    
    vn = vk(:,k);
    xdot = zeros(10,1);
    
    wi = wi_m + vn(1:3);
    ai = ai_m + vn(4:6);
    
    % cosine matrix
    Cin = attparsilentmex(qin,[6 1]);
    % time rate of my position
    xdot(1:3) = Cin'*vin;
    % time rate of my velocity
    xdot(4:6) = ai - squiggle(wi)*vin;
    % time rate of my attitude
    % A matrix for qin
    Ain = 0.5*[ -qin(2:4)';qin(1)*eye(3) + squiggle(qin(2:4))];
    xdot(7:10) = Ain*wi;

    xkPlus(:,k) = xhat + Ts*xdot;
    %re-normalize
    xkPlus(7:10,k) = xkPlus(7:10,k)/norm(xkPlus(7:10,k));
end

end
