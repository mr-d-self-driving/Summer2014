function yk = measurement_eq_ranging_and_imu(xk,nk,uk)

%xk: 20 x 2N+1, inertial position, inertial velocity, inertial quaternion,
%relative position, relative quaternion, and other agent's inertial
%velocity in his body frame
%
%nk: 6 x 2N+1, error on range from ME to each beacon on HIM
%   maybe add his range relative to MY beacons later

%uk[wi;wj;ai;aj;r(1,2,3)j/j] : 21 x 2N+1

n = size(xk,1);
l = size(nk,1);

% bodyaxis position of agents' localizers
rkj_j = reshape(uk(13:21),3,3);

yk = zeros(3,size(xk,2));
for k = 1:size(xk,2)
    %xhat = xk(:,k);
    % i to j frame transform
    qhat = xk(14:17,k);
    % est relative position in my (i) frame
    rji_i_hat = xk(11:13,k);
    % estimated my inertial position
    %rin = xk(1:3,k);
    % my estimated inertial attitude
    %qin = xk(7:10,k);
    %Cin = attparsilentmex(qin,[6 1]);
    
    nv = nk(:,k);
    
    Cji = attparsilentmex(qhat,[6 1]);
    
    % predicted vectors to each of the other agent's localizers
    rkj_i = repmat(rji_i_hat,1,3) + Cji'*rkj_j;
    yk(1:3,k) = sqrt(sum(rkj_i.^2,1))' + nv(1:3);
    
    yk(4:6,k) = sqrt(sum ((repmat(rji_i_hat,1,3) - rkj_j).^2,1) )' + nv(4:6);
end

end
