function yk = measurement_eq_no_range(xk,nk,uk)

%xk: 10 x 2N+1, relative quaternion, position, and velocity
%nk: 4 x 2N+1, error on range/bearing/azimuth for agent 1, then agent 2

%uk[wi;wj;ai;aj] : 12 x 2N+1
% yk: 4 x 2N+1, bearing/azimuth for agents 1 and 2 consecutively

n = size(xk,1);
l = size(nk,1);

yk = zeros(4,size(xk,2));
for k = 1:size(xk,2)
    % i to j frame transform
    qhat = xk(1:4,k);
    % est relative position
    rji_i_hat = xk(5:7,k);
    
    Cji = attparsilent(qhat,[6 1]);
    % expected range/bearing/azimuth from agent i's measurement
    yk(1:2,k) = [atan2(rji_i_hat(2),rji_i_hat(1));atan2(rji_i_hat(3),sqrt(sum(rji_i_hat(1:2).^2)))] + nk(1:2,k);

    % expectation from agent j's measurement
    rij_j_hat = -Cji*rji_i_hat;
    % expected range/bearing/azimuth from agent j's measurement
    yk(3:4,k) = [atan2(rij_j_hat(2),rij_j_hat(1));atan2(rij_j_hat(3),sqrt(sum(rij_j_hat(1:2).^2)))] + nk(3:4,k);
    
    if k > 1
        % minimize angle difference
        yk(:,k) = minangle(yk(:,k),yk(:,1));
    end
end

end
