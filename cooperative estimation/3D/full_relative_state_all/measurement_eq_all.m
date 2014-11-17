function yk = measurement_eq_all(xk,nk,uk)

%xk: 10 x 2N+1, relative quaternion, position, and velocity
%nk: 6 x 2N+1, error on range/bearing/azimuth for agent 1, then agent 2

%uk[wi;wj;ai;aj] : 12 x 2N+1

n = size(xk,1);
l = size(nk,1);

yk = zeros(6,size(xk,2));
for k = 1:size(xk,2)
    % i to j frame transform
    qhat = xk(1:4,k);
    % est relative position
    rji_i_hat = xk(5:7,k);
    
    Cji = attparsilent(qhat,[6 1]);
    % expected range/bearing/azimuth from agent i's measurement
    yk(1:3,k) = [sqrt(sum(rji_i_hat.^2));atan2(rji_i_hat(2),rji_i_hat(1));atan2(rji_i_hat(3),sqrt(sum(rji_i_hat(1:2).^2)))] + nk(1:3,k);

    % expectation from agent j's measurement
    rij_j_hat = -Cji*rji_i_hat;
    % expected range/bearing/azimuth from agent j's measurement
    yk(4:6,k) = [sqrt(sum(rij_j_hat.^2));atan2(rij_j_hat(2),rij_j_hat(1));atan2(rij_j_hat(3),sqrt(sum(rij_j_hat(1:2).^2)))] + nk(4:6,k);
    
    if k > 1
        % minimize angle difference
        yk([2;3;5;6],k) = minangle(yk([2;3;5;6],k),yk([2;3;5;6],1));
    end
end

end
