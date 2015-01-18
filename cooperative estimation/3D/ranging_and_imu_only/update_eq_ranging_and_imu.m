function xkPlus = update_eq_ranging_and_imu(xk,vk,uk)

global Ts;

%xk: 20 x 2N+1, inertial position, inertial velocity, inertial quaternion, relative position, and relative quaternion ... then unknown feature parameters 
%vk: 12 x 2N+1, noise on wi,wj,ai,aj

%uk[wi;wj;ai;aj] : 12 x 2N+1

n = size(xk,1);
v = size(vk,1);

% IMU measurements I made
wi_m = uk(1:3);
ai_m = uk(7:9);
wj_m = uk(4:6);
aj_m = uk(10:12);

xkPlus = zeros(size(xk));
for k = 1:size(xk,2);
    xhat = xk(:,k);
    % his position relative to mine. My body frame
    rji = xhat(11:13);
    % my velocity
    vin = xhat(4:6);
    % my attitude
    qin = xhat(7:10);
    % his attitude relative to mine. His body frame
    qji = xhat(14:17);
    % his inertial velocity (his body frame)
    vjn = xhat(18:20);
    
    vn = vk(:,k);
    xdot = zeros(n,1);
        
    wi = wi_m + vn(1:3);
    ai = ai_m + vn(7:9);
    
    wj = wj_m + vn(4:6);
    aj = aj_m + vn(10:12);
    
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

    % relative attitude cosine matrix
    Cji = attparsilentmex(qji,[6 1]);

    % relative angular velocity in j frame
    wji = wj-Cji*wi;
    % A matrix for q_ji
    A = 0.5*[ -qji(2:4)';qji(1)*eye(3) + squiggle(qji(2:4))];
    % time rate of relative attitude
    xdot(14:17) = A*wji;
    
    % time rate of relative position
    xdot(11:13) = (Cji'*vjn-vin) - squiggle(wi)*rji;
    
    % time rate of his velocity
    xdot(18:20) = vjn - squiggle(wj)*vjn;
    
    xkPlus(:,k) = xhat + Ts*xdot;
    %re-normalize quaternions
    xkPlus(7:10,k) = xkPlus(7:10,k)/norm(xkPlus(7:10,k));
    xkPlus(14:17,k) = xkPlus(14:17,k)/norm(xkPlus(14:17,k));
end

end
