function yk = measurement_eq_ranging_and_imu(xk,nk,uk)

%xk: 20 x 2N+1, inertial position, inertial velocity, inertial quaternion,
%relative position, relative quaternion, and other agent's inertial
%velocity in his body frame
%
%nk: 3/6 x 2N+1, error on range from ME to each beacon on HIM
%   maybe add his range relative to MY beacons later

%uk[wi;wj;ai;aj] : 12 x 2N+1

n = size(xk,1);
l = size(nk,1);

yk = zeros(9+3*(m+w1+w2),size(xk,2));
for k = 1:size(xk,2)
    xhat = xk(:,k);
    % i to j frame transform
    qhat = xk(14:17,k);
    % est relative position in my (i) frame
    rji_i_hat = xk(11:13,k);
    % estimated my inertial position
    rin = xk(1:3,k);
    % my estimated inertial attitude
    qin = xk(7:10,k);
    Cin = attparsilentmex(qin,[6 1]);
    
    nv = nk(:,k);
    
    Cji = attparsilentmex(qhat,[6 1]);
    % expected range/bearing/azimuth from agent i's measurement
    yk(1:3,k) = [sqrt(sum(rji_i_hat.^2));atan2(rji_i_hat(2),rji_i_hat(1));atan2(rji_i_hat(3),sqrt(sum(rji_i_hat(1:2).^2)))] + nv(1:3);

    % expectated relative vector from agent j's measurement
    rij_j_hat = -Cji*rji_i_hat;
    % expected range/bearing/azimuth from agent j's measurement
    yk(4:6,k) = [sqrt(sum(rij_j_hat.^2));atan2(rij_j_hat(2),rij_j_hat(1));atan2(rij_j_hat(3),sqrt(sum(rij_j_hat(1:2).^2)))] + nv(4:6);
    
    % expected magnetometer measurement
    yk(7:9,k) = Cji*(mag_i + nv(7:9)) - nv(10:12);
    
    % known feature measurements agent 1
    for kk = 1:m1
        % get the i frame vector to the feature
        rki = Cin*(RKN_1(kk,:)' - rin);
        % the index for now
        index = (kk-1)*3 + (1:3);
        % compute range/bearing/declination
        %y_kk = [sqrt(sum(rki.^2));atan2(rki(2),rki(1));atan2(rki(3),sqrt(sum(rki(1:2).^2)))] + nv(12 + index);
        y_kk = vector2polar(rki) + nv(12 + index);
        yk(9 + index,k) = y_kk;
    end
    
    % known feature measurements agent 2
    for kk = 1:m2
        % get the j frame vector to the feature
        rkj = Cji*Cin*(RKN_2(kk,:)' - Cin'*rji_i_hat - rin);
        % the index for now
        index = (kk-1)*3 + (1:3) + m1*3;
        % compute range/bearing/declination
        %y_kk = [sqrt(sum(rkj.^2));atan2(rkj(2),rkj(1));atan2(rkj(3),sqrt(sum(rkj(1:2).^2)))] + nv(12 + index);
        y_kk = vector2polar(rkj) + nv(12 + index);
        yk(9 + index,k) = y_kk;
    end
    
    % unknown feature measurements agent 1
    for kk = 1:w1;
        % the index for where to store these data
        index = (kk-1)*3 + (1:3) + (m1+m2)*3;
        % the label for this feature
        feature_no = feature_index_1(kk);
        feature_vec = xhat(17 + (feature_no-1)*6 + (1:6));%xyz,rho,bearing,azimuth
        % the inertial vector to the feature, in inertial frame
        rkn = feature_vec(1:3) + 1/feature_vec(4)*[cos(feature_vec(6))*[cos(feature_vec(5));sin(feature_vec(5))]; sin(feature_vec(6))];
        % the body-frame vector to the feature
        rki_b = Cin*(rkn - rin);
        % extract range/bearing/azimuth
        y_kk = vector2polar(rki_b) + nv(12 + index);
        yk(9 + index,k) = y_kk;
    end
    
    % unknown feature measurements agent 2
    for kk = 1:w2;
        % the index for where to store these data
        index = (kk-1)*3 + (1:3) + (m1+m2+w1)*3;
        % the label for this feature
        feature_no = feature_index_2(kk);
        feature_vec = xhat(17 + (feature_no-1)*6 + (1:6));%xyz,rho,bearing,azimuth
        % the inertial vector to the feature, in inertial frame
        rkn = feature_vec(1:3) + 1/feature_vec(4)*[cos(feature_vec(6))*[cos(feature_vec(5));sin(feature_vec(5))]; sin(feature_vec(6))];
        % the OTHER AGENT'S body-frame vector to the feature
        rkj_j = Cji*Cin*(rkn - rin - Cin'*rji_i_hat);
        % extract range/bearing/azimuth
        y_kk = vector2polar(rkj_j) + nv(12 + index);
        yk(9 + index,k) = y_kk;
    end
    
    if k > 1
        % minimize all angle differences
        yk([2;3;5;6],k) = minangle(yk([2;3;5;6],k),yk([2;3;5;6],1));
        yk( 9 + (2:3:3*m1),k ) = minangle(yk(9 + (2:3:3*m1),k),yk(9 + (2:3:3*m1),1));
        yk( 9 + (3:3:3*m1),k ) = minangle(yk(9 + (3:3:3*m1),k),yk(9 + (3:3:3*m1),1));
        yk( 9 + 3*m1 + (2:3:3*m2),k ) = minangle( yk( 9 + 3*m1 + (2:3:3*m2),k ), yk( 9 + 3*m1 + (2:3:3*m2),1 ) );
        yk( 9 + 3*m1 + (3:3:3*m2),k ) = minangle( yk( 9 + 3*m1 + (3:3:3*m2),k ), yk( 9 + 3*m1 + (3:3:3*m2),1 ) );
        yk( 9 + 3*(m1+m2) + (2:3:3*w1),k ) = minangle(yk( 9 + 3*(m1+m2) + (2:3:3*w1),k ), yk( 9 + 3*(m1+m2) + (2:3:3*w1),1 ) );
        yk( 9 + 3*(m1+m2) + (3:3:3*w1),k ) = minangle(yk( 9 + 3*(m1+m2) + (3:3:3*w1),k ), yk( 9 + 3*(m1+m2) + (3:3:3*w1),1 ) );
        yk( 9 + 3*(m1+m2+w1) + (2:3:3*w2),k ) = minangle(yk( 9 + 3*(m1+m2+w1) + (2:3:3*w2),k ), yk( 9 + 3*(m1+m2+w1) + (2:3:3*w2),k ) );
        yk( 9 + 3*(m1+m2+w1) + (3:3:3*w2),k ) = minangle(yk( 9 + 3*(m1+m2+w1) + (3:3:3*w2),k ), yk( 9 + 3*(m1+m2+w1) + (3:3:3*w2),k ) );
    end
end

end
