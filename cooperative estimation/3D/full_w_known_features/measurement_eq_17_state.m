function yk = measurement_eq_17_state(xk,nk,uk)

% m1: # of features agent 1 sees
% m2: # of features agent 2 sees

%xk: 17 x 2N+1, inertial position, inertial velocity, inertial quaternion, relative position, and relative quaternion
%nk: 12+3*m1+3*m2 x 2N+1, error on range/bearing/azimuth for agent 1, then agent 2, then magnetometer errors for agent 1 then 2, 
%       THEN feature range/bearing/azimuth errors FOR EACH FEATURE for agent 1, then same for agent 2 

%uk[wi;ai;mag_i;# of i features;rkn;...;# of j features;rkn;...] : 9+2+3*m x 2N+1, m being total # of features from i and j 

mag_i = uk(7:9);

m1 = uk(10);
m2 = uk(10+3*m1+1);
m = m1+m2;% total # of features

% 3 x m1 array of known inertial position of features seen by agent 1
RKN_1 = reshape(uk(10+3*(1:m1)),3,[])';
% 3 x m2 array of known inertial position of features seen by agent 2
RKN_2 = reshape(uk(10+3*m1+1+3*(1:m2)),3,[])';

n = size(xk,1);
l = size(nk,1);

yk = zeros(9+3*m,size(xk,2));
for k = 1:size(xk,2)
    % i to j frame transform
    qhat = xk(14:17,k);
    % est relative position
    rji_i_hat = xk(11:13,k);
    % estimated my inertial position
    rin = xk(1:3,k);
    % my estimated inertial attitude
    qin = xk(7:10);
    Cin = attparsilent(qin,[6 1]);
    
    Cji = attparsilent(qhat,[6 1]);
    % expected range/bearing/azimuth from agent i's measurement
    yk(1:3,k) = [sqrt(sum(rji_i_hat.^2));atan2(rji_i_hat(2),rji_i_hat(1));atan2(rji_i_hat(3),sqrt(sum(rji_i_hat(1:2).^2)))] + nk(1:3,k);

    % expectated relative vector from agent j's measurement
    rij_j_hat = -Cji*rji_i_hat;
    % expected range/bearing/azimuth from agent j's measurement
    yk(4:6,k) = [sqrt(sum(rij_j_hat.^2));atan2(rij_j_hat(2),rij_j_hat(1));atan2(rij_j_hat(3),sqrt(sum(rij_j_hat(1:2).^2)))] + nk(4:6,k);
    
    if k > 1
        % minimize angle difference
        yk([2;3;5;6],k) = minangle(yk([2;3;5;6],k),yk([2;3;5;6],1));
    end
    % expected magnetometer measurement
    yk(7:9,k) = Cji*(mag_i + nk(7:9,k)) - nk(10:12,k);
    
    % feature measurements
    for kk = 1:m1
        % get the i frame vector to the feature
        rki = Cin*(RKN_1(kk,:)' - rin);
        % the index for now
        index = (kk-1)*3 + (1:3);
        % compute range/bearing/declination
        y_kk = [sqrt(sum(rki.^2));atan2(rki(2),rki(1));atan2(rki(3),sqrt(sum(rki(1:2).^2)))] + nk(12 + index,k);
        yk(9 + index,k) = y_kk;
    end
    
    for kk = 1:m2
        % get the j frame vector to the feature
        rkj = Cji*Cin*(RKN_2(kk,:)' - Cin'*rji_i_hat + rin);
        % the index for now
        index = (kk-1)*3 + (1:3) + m1*3;
        % compute range/bearing/declination
        y_kk = [sqrt(sum(rkj.^2));atan2(rkj(2),rkj(1));atan2(rkj(3),sqrt(sum(rkj(1:2).^2)))] + nk(12 + index,k);
        yk(9 + index,k) = y_kk;
    end
end

end
