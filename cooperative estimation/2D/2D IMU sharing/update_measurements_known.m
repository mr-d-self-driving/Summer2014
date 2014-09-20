% update_measurements_known
%
% for the case of known features only

if imu_sharing
    % we are estimating our own position, velocity, heading, and for each
    % other agent: relative position (our body frame), his body-frame
    % velocity, and his relative heading
    x0hat = xk(j).xk(2*i-1,:)';% rix,riy,u,v,psi (me), rjix,rjiy,uj,vj,psiji forall j
    P0hat = reshape(xk(j).Pk(2*i-1,:)',5*N,5*N);
    measurement_count = 0;
    
    switch feature_case
        case 0
            %range and bearing to each feature
            % maximum of 2*N*M measurements, with perfect FOV
            ytilde = zeros(2*N*M,1);
            yexp = zeros(2*N*M,1);
            % measurement gradient matrix
            Hk = zeros(2*N*M,5*N);
            % covariance matrix for pure measurements - may be
            % functions of multiple measurements
            Rk = zeros(2*N*M);
            % our owm heading and position
            % this may be relative to initialization, or in absolute ref. frame
            psii = x0hat(5);
            rix = x0hat(1);
            riy = x0hat(2);
            % inertial-to-body DCM
            Cbn = [cos(psii) sin(psii);-sin(psii) cos(psii)];
            
            % use our own feature measurements
            for m = 1:M
                %check that the measurement is less than the FOV
                if abs(ags(j).rb(i,M+m)) <= FOV(j)*d2r && abs(ags(j).rb(i,m)) < RANGE(j) && abs(ags(j).rb(i,m)) > RANGEMIN(j)
                    % compute expectation
                    %landmark position
                    rkx = marks(m).xy(1);
                    rky = marks(m).xy(2);
                    rki_b = Cbn*[rkx;rky]-[rix;riy];%body frame expectation of relative vector
                    rhoki = sqrt(sum( rki_b.^2 ));% expected range
                    thetaki = atan2(rki_b(2),rki_b(1));% expected bearing
                    % measurements
                    % range
                    measurement_count = measurement_count + 1;
                    ytilde(measurement_count) = ags(j).rb(i,m);
                    Rk(measurement_count,measurement_count) = Rrange(j);
                    yexp(measurement_count) = rhoki;
                    % range gradient
                    Hk(measurement_count,1:5) = [-(2*rkx*cos(psii) - 2*rix + 2*rky*sin(psii))/(2*((riy - rky*cos(psii) + rkx*sin(psii))^2 + (rkx*cos(psii) - rix + rky*sin(psii))^2)^(1/2))
                        (2*riy - 2*rky*cos(psii) + 2*rkx*sin(psii))/(2*((riy - rky*cos(psii) + rkx*sin(psii))^2 + (rkx*cos(psii) - rix + rky*sin(psii))^2)^(1/2))
                        0
                        0
                        (2*(rkx*cos(psii) + rky*sin(psii))*(riy - rky*cos(psii) + rkx*sin(psii)) + 2*(rky*cos(psii) - rkx*sin(psii))*(rkx*cos(psii) - rix + rky*sin(psii)))/(2*((riy - rky*cos(psii) + rkx*sin(psii))^2 + (rkx*cos(psii) - rix + rky*sin(psii))^2)^(1/2))]';
                    % bearing
                    measurement_count = measurement_count + 1;
                    ytilde(measurement_count) = ags(j).rb(i,m+M);
                    Rk(measurement_count,measurement_count) = Rbear(j);
                    yexp(measurement_count) = thetaki;
                    yexp(measurement_count) = minangle(yexp(measurement_count),ytilde(measurement_count));
                    % bearing gradient
                    Hk(measurement_count,1:5) = [-(riy - rky*cos(psii) + rkx*sin(psii))/(rix^2 - 2*cos(psii)*rix*rkx - 2*sin(psii)*rix*rky + riy^2 + 2*sin(psii)*riy*rkx - 2*cos(psii)*riy*rky + rkx^2 + rky^2)
                        -(rkx*cos(psii) - rix + rky*sin(psii))/(rix^2 - 2*cos(psii)*rix*rkx - 2*sin(psii)*rix*rky + riy^2 + 2*sin(psii)*riy*rkx - 2*cos(psii)*riy*rky + rkx^2 + rky^2)
                        0
                        0
                        (rix*(rkx*cos(psii) + rky*sin(psii)) + riy*(rky*cos(psii) - rkx*sin(psii)) - rkx^2 - rky^2)/(rix^2 - 2*cos(psii)*rix*rkx - 2*sin(psii)*rix*rky + riy^2 + 2*sin(psii)*riy*rkx - 2*cos(psii)*riy*rky + rkx^2 + rky^2)]';
                end
            end
            % use all other agents' feature measurements
            for n = 1:N-1
                % we are sharing imu
                rji_hat = x0hat((n-1)*5+(6:7));
                psiji = x0hat((n-1)*5+10);
                % agent i-to-j DCM
                Cbjbi = [cos(psiji) sin(psiji);-sin(psiji) cos(psiji)];
                switch agent_case
                    case 0
                        % we measure range and bearing to agents
                        % index variable j2 is the global index
                        % where the other agent's measurements are
                        if n < j
                            j2 = n;
                        else if n >= j
                                j2 = n+1;
                            end
                        end
                        % index variable n2 is agent j2's index of
                        % where MY measurements are stored
                        if j <= n
                            n2 = j;
                        else
                            if j > n
                                n2 = j - 1;
                            end
                        end
                        % we get 4 constraints for every other agent
                        % my measurement of his range
                        measurement_count = measurement_count + 1;
                        ytilde(measurement_count) = ags(j).rb_agent(i,1+(n-1)*2);
                        Rk(measurement_count,measurement_count) = Rrange_ag;
                        yexp(measurement_count) = norm(rji_hat);
                        Hk(measurement_count,(6:7)+(n-1)*5) = [ rji_hat(1)/norm(rji_hat) rji_hat(2)/norm(rji_hat) ];
                        % my measurement of his bearing
                        measurement_count = measurement_count + 1;
                        ytilde(measurement_count) = ags(j).rb_agent(i,2+(n-1)*2);
                        Rk(measurement_count,measurement_count) = Rbear_ag;
                        yexp(measurement_count) = atan2(rji_hat(2),rji_hat(1));
                        yexp(measurement_count) = minangle(yexp(measurement_count),ytilde(measurement_count));
                        Hk(measurement_count,(6:7)+(n-1)*5) = [ -rji_hat(2)/norm(rji_hat)^2 rji_hat(1)/norm(rji_hat)^2 ];
                        % his measurement of my range
                        rhoij = ags(j2).rb_agent(i,(n2-1)*2+1);
                        measurement_count = measurement_count+1;
                        ytilde(measurement_count) = rhoij;
                        Rk(measurement_count,measurement_count) = Rrange_ag;
                        yexp(measurement_count) = norm(rji_hat);
                        Hk(measurement_count,(6:7)+(n-1)*5) = [ rji_hat(1)/norm(rji_hat) rji_hat(2)/norm(rji_hat) ];
                        % his measurement of my bearing
                        thetaij = ags(j2).rb_agent(i,(n2-1)*2+2);
                        measurement_count = measurement_count+1;
                        ytilde(measurement_count) = thetaij;
                        Rk(measurement_count,measurement_count) = Rbear_ag;
                        yexp(measurement_count) = pi + atan2(rji_hat(2),rji_hat(1)) - psiji;
                        yexp(measurement_count) = minangle(yexp(measurement_count),ytilde(measurement_count));
                        Hk(measurement_count,[6 7 10] + (n-1)*5) = [ -rji_hat(2)/norm(rji_hat)^2 rji_hat(1)/norm(rji_hat)^2 -1 ];
                        % then we get all of his feature range/bearings
                        for m = 1:M
                            %check that he can see the current feature
                            if abs(ags(j2).rb(i,M+m)) <= FOV(j2)*d2r && abs(ags(j2).rb(i,m)) < RANGE(j2) && abs(ags(j2).rb(i,m)) > RANGEMIN(j2)
                                %landmark position
                                rkx = marks(m).xy(1);
                                rky = marks(m).xy(2);
                                % use his measured vector to feature as the constraint
                                measurement_count = measurement_count + 2;
                                rhokj_til = ags(j2).rb(i,m);
                                thetakj_til = ags(j2).rb(i,m+M);
                                
                                ytilde(measurement_count-1:measurement_count) = rhokj_til*[cos(thetakj_til);sin(thetakj_til)];
                                J = [cos(thetakj_til) rhokj_til*-sin(thetakj_til);
                                    sin(thetakj_til) rhokj_til*cos(thetakj_til)];
                                Rx = diag([Rrange(j2) Rbear(j2)]);
                                Rk(measurement_count-1:measurement_count,measurement_count-1:measurement_count) = J*Rx*J';
                                
                                yexp(measurement_count-1:measurement_count) = Cbjbi*(Cbn*[rkx;rky]-[rix;riy] - rji_hat);
                                Hk(measurement_count-1:measurement_count,[1:5 (1:5)+(n*5)]) = [ [-cos(psiji), -sin(psiji), 0, 0,   rky*cos(psii + psiji) - rkx*sin(psii + psiji), -cos(psiji), -sin(psiji), 0, 0, sin(psiji)*(rix + rji_hat(1) - rkx*cos(psii) - rky*sin(psii)) - cos(psiji)*(riy + rji_hat(2) - rky*cos(psii) + rkx*sin(psii))];
                                    [sin(psiji), -cos(psiji), 0, 0, - rkx*cos(psii + psiji) - rky*sin(psii + psiji),  sin(psiji), -cos(psiji), 0, 0, cos(psiji)*(rix + rji_hat(1) - rkx*cos(psii) - rky*sin(psii)) + sin(psiji)*(riy + rji_hat(2) - rky*cos(psii) + rkx*sin(psii))] ];
                            end
                        end
                    case 1
                        % we measure bearing to agents
                        % we get 2 constraints for every other agent
                    case 2
                        % we measure range to agents
                        % we get 2 constraints for every other agent
                end
            end
        case 1
            % bearing only
        case 2
            % range only
        case 3
            % no sharing
    end
else
    if agent_case == 0
        % we are estimating our own position, velocity, and heading
        % we are measuring range and bearing to other agents
        x0hat = xk(j).xk(2*i-1,1:5)';% rix,riy,u,v,psi (me), rjix,rjiy,uj,vj,psiji forall j
        P0hat = reshape(xk(j).Pk(2*i-1,:)',5,5);
        measurement_count = 0;
        switch feature_case
            case 0
                %range and bearing to each feature
                % maximum of 2*N*M measurements, with perfect FOV
                ytilde = zeros(2*N*M,1);
                yexp = zeros(2*N*M,1);
                % measurement gradient matrix
                Hk = zeros(2*N*M,5);
                % covariance matrix for pure measurements - may be
                % functions of multiple measurements
                Rk = zeros(2*N*M);
                % our owm heading and position
                % this may be relative to initialization, or in absolute ref. frame
                psii = x0hat(5);
                rix = x0hat(1);
                riy = x0hat(2);
                % inertial-to-body DCM
                Cbn = [cos(psii) sin(psii);-sin(psii) cos(psii)];
                % check all other agents' feature measurements
                for j2 = [1:j-1 j+1:N]
                    switch agent_case
                        case 0
                            % index used because each agent stores its
                            % measurements of the other agents differently than
                            % the `global' index
                            j2ind = j2;
                            if j2ind > j
                                j2ind = j2ind-1;
                            end
                            jjind = j;
                            if jjind > j2
                                jjind = jjind-1;
                            end
                            % measured range to other agent
                            rhoji = ags(j).rb_agent(i,(j2ind-1)*2+1);
                            % measured bearing to other agent
                            thetaji = ags(j).rb_agent(i,(j2ind-1)*2+2);
                            % measured bearing by other agent to current agent
                            thetaij = ags(j2).rb_agent(i,(jjind-1)*2+2);
                            % delta is the relative heading, equals psi_j - psi_i
                            delta = thetaji + pi - thetaij;
                            % loop over each landmark
                            for m = 1:M
                                % landmark position in inertial frame
                                rkx = marks(m).xy(1);
                                rky = marks(m).xy(2);
                                % check if the other agent can see the feature
                                if abs(ags(j2).rb(i,m+M)) <= d2r*FOV(j2) && abs(ags(j2).rb(i,m)) < RANGE(j2) && abs(ags(j2).rb(i,m)) > RANGEMIN(j2)
                                    measurement_count = measurement_count+1;
                                    % use the feature
                                    rhokj = ags(j2).rb(i,m); %other agent's range measure
                                    thetakj = ags(j2).rb(i,m+M);% other agent's bearing measure
                                    beta = thetaij - thetakj;
                                    % new range measure from other agents, CONVERTED
                                    % INTO AGENT j's FRAME!
                                    rhoki_exp = sqrt(rhokj^2+rhoji^2-2*rhokj*rhoji*cos(beta));
                                    ytilde(measurement_count) = rhoki_exp;% law of cosines
                                    rki_b = Cbn*[rkx;rky]-[rix;riy];%body frame expectation of relative vector
                                    rhoki = sqrt(sum( rki_b.^2 ));
                                    yexp(measurement_count) = rhoki;
                                    % compute gradient
                                    Hk(measurement_count,:) = [-(2*rkx*cos(psii) - 2*rix + 2*rky*sin(psii))/(2*((riy - rky*cos(psii) + rkx*sin(psii))^2 + (rkx*cos(psii) - rix + rky*sin(psii))^2)^(1/2))
                                        (2*riy - 2*rky*cos(psii) + 2*rkx*sin(psii))/(2*((riy - rky*cos(psii) + rkx*sin(psii))^2 + (rkx*cos(psii) - rix + rky*sin(psii))^2)^(1/2))
                                        0
                                        0
                                        (2*(rkx*cos(psii) + rky*sin(psii))*(riy - rky*cos(psii) + rkx*sin(psii)) + 2*(rky*cos(psii) - rkx*sin(psii))*(rkx*cos(psii) - rix + rky*sin(psii)))/(2*((riy - rky*cos(psii) + rkx*sin(psii))^2 + (rkx*cos(psii) - rix + rky*sin(psii))^2)^(1/2))]';
                                    % bearing measurement
                                    measurement_count = measurement_count+1;
                                    % new bearing measure from other agents, CONVERTED
                                    % INTO AGENT j's FRAME!
                                    ytilde(measurement_count) = pi + thetaji - thetaij + thetakj - atan2(( rhoji*sin(beta)/rhoki_exp ),( (rhoji^2-rhokj^2-rhoki_exp^2)/(-2*rhokj*rhoki_exp) ));
                                    yexp(measurement_count) = atan2(rki_b(2),rki_b(1));
                                    % minimize the difference in the two angles
                                    yexp(measurement_count) = minangle(yexp(measurement_count),ytilde(measurement_count));
                                    % compute gradient
                                    Hk(measurement_count,:) = [-(riy - rky*cos(psii) + rkx*sin(psii))/(rix^2 - 2*cos(psii)*rix*rkx - 2*sin(psii)*rix*rky + riy^2 + 2*sin(psii)*riy*rkx - 2*cos(psii)*riy*rky + rkx^2 + rky^2)
                                        -(rkx*cos(psii) - rix + rky*sin(psii))/(rix^2 - 2*cos(psii)*rix*rkx - 2*sin(psii)*rix*rky + riy^2 + 2*sin(psii)*riy*rkx - 2*cos(psii)*riy*rky + rkx^2 + rky^2)
                                        0
                                        0
                                        (rix*(rkx*cos(psii) + rky*sin(psii)) + riy*(rky*cos(psii) - rkx*sin(psii)) - rkx^2 - rky^2)/(rix^2 - 2*cos(psii)*rix*rkx - 2*sin(psii)*rix*rky + riy^2 + 2*sin(psii)*riy*rkx - 2*cos(psii)*riy*rky + rkx^2 + rky^2)]';
                                    % compute the Jacobian and approximate
                                    % the true covariance
                                    Rx = diag([Rrange_ag Rbear_ag Rbear_ag Rrange(j2) Rbear(j2)]);
                                    yeff = [rhoji; thetaji; thetaij;rhokj;thetakj];
                                    [x,Px] = statisticalLinearization(yeff,Rx,@frb_arb);
                                    Rk(measurement_count-1:measurement_count,measurement_count-1:measurement_count) = Px;
                                    ytilde(measurement_count-1:measurement_count) = x;
                                end
                            end
                        case 1
                            % we measure bearing to agents
                        case 2
                            % we measure range to agents
                            % we get 2 constraints for every other agent
                    end
                end
            case 1
                % bearing only
                global xhatk;
                % maximum of N*M measurements, with perfect FOV
                ytilde = zeros(N*M,1);
                yexp = zeros(N*M,1);
                % measurement gradient matrix
                Hk = zeros(N*M,5);
                % covariance matrix for pure measurements - may be
                % functions of multiple measurements
                Rk = zeros(N*M);
                % our own heading and position
                % this may be relative to initialization, or in absolute ref. frame
                psii = x0hat(5);
                rix = x0hat(1);
                riy = x0hat(2);
                % inertial-to-body DCM
                Cbn = [cos(psii) sin(psii);-sin(psii) cos(psii)];
                % check all other agents' feature measurements
                for j2 = [1:j-1 j+1:N]
                    switch agent_case
                        case 0
                            % index used because each agent stores its
                            % measurements of the other agents differently than
                            % the `global' index
                            j2ind = j2;
                            if j2ind > j
                                j2ind = j2ind-1;
                            end
                            jjind = j;
                            if jjind > j2
                                jjind = jjind-1;
                            end
                            % measured range to other agent
                            rhoji = ags(j).rb_agent(i,(j2ind-1)*2+1);
                            % measured bearing to other agent
                            thetaji = ags(j).rb_agent(i,(j2ind-1)*2+2);
                            % measured bearing by other agent to current agent
                            thetaij = ags(j2).rb_agent(i,(jjind-1)*2+2);
                            % delta is the relative heading, equals psi_j - psi_i
                            delta = thetaji + pi - thetaij;
                            % loop over each landmark
                            for m = 1:M
                                % landmark position in inertial frame
                                rkx = marks(m).xy(1);
                                rky = marks(m).xy(2);
                                % check if the other agent can see the feature
                                if abs(ags(j2).rb(i,m+M)) <= d2r*FOV(j2) && abs(ags(j2).rb(i,m)) < RANGE(j2) && abs(ags(j2).rb(i,m)) > RANGEMIN(j2)
                                    measurement_count = measurement_count+1;
                                    % use the feature
                                    % other agent's bearing measure
                                    thetakj = ags(j2).rb(i,m+M);
                                    rki_bi = Cbn*[rkx;rky] - [rix;riy];
                                    rkj_bi = rki_bi - rhoji*[cos(thetaji);sin(thetaji)];
                                    Cbjbi = [cos(delta) sin(delta);-sin(delta) cos(delta)];
                                    rkj_bj = Cbjbi*rkj_bi;
                                    % expected i to k bearing
                                    tt = atan2((rki_bi(2) - rhoji*sin(thetaji)),(rki_bi(1) - rhoji*cos(thetaji)));
                                    tt = minangle(tt,pi2pi(thetakj+delta));
                                    ytilde(measurement_count) = tt - pi2pi(thetakj + delta);
                                    yexp(measurement_count) = 0;
                                    % gradient
                                    Hk(measurement_count,:) = -[-(riy - rky*cos(psii) + rkx*sin(psii) + rhoji*sin(thetaji))/(((riy - rky*cos(psii) + rkx*sin(psii) + rhoji*sin(thetaji))^2/(rix - rkx*cos(psii) + rhoji*cos(thetaji) - rky*sin(psii))^2 + 1)*(rix - rkx*cos(psii) + rhoji*cos(thetaji) - rky*sin(psii))^2)
                                        1/(((riy - rky*cos(psii) + rkx*sin(psii) + rhoji*sin(thetaji))^2/(rix - rkx*cos(psii) + rhoji*cos(thetaji) - rky*sin(psii))^2 + 1)*(rix - rkx*cos(psii) + rhoji*cos(thetaji) - rky*sin(psii)))
                                        0
                                        0
                                        ((rkx*cos(psii) + rky*sin(psii))/(rix - rkx*cos(psii) + rhoji*cos(thetaji) - rky*sin(psii)) + ((rky*cos(psii) - rkx*sin(psii))*(riy - rky*cos(psii) + rkx*sin(psii) + rhoji*sin(thetaji)))/(rix - rkx*cos(psii) + rhoji*cos(thetaji) - rky*sin(psii))^2)/((riy - rky*cos(psii) + rkx*sin(psii) + rhoji*sin(thetaji))^2/(rix - rkx*cos(psii) + rhoji*cos(thetaji) - rky*sin(psii))^2 + 1)]';
                                    
                                    xhatk = [rix;riy;psii;rkx;rky];
                                    Rx = diag([Rrange_ag Rbear_ag Rbear_ag Rbear(j2)]);
                                    yeff = [rhoji; thetaji; thetaij; thetakj];
                                    [x,Px] = statisticalLinearization(yeff,Rx,@fb_arb);
                                    Rk(measurement_count,measurement_count) = Px;
                                    ytilde(measurement_count) = x;
                                end
                            end
                        case 1
                            % we measure bearing to agents
                        case 2
                            % we measure range to agents
                            % we get 2 constraints for every other agent
                    end
                end
            case 2
                % range only
            case 3
                % no sharing
        end
        % use our own feature measurements
        for m = 1:M
            %check that the measurement is less than the FOV
            if abs(ags(j).rb(i,M+m)) <= FOV(j)*d2r && abs(ags(j).rb(i,m)) < RANGE(j) && abs(ags(j).rb(i,m)) > RANGEMIN(j)
                % compute expectation
                %landmark position
                rkx = marks(m).xy(1);
                rky = marks(m).xy(2);
                rki_b = Cbn*[rkx;rky]-[rix;riy];%body frame expectation of relative vector
                rhoki = sqrt(sum( rki_b.^2 ));% expected range
                thetaki = atan2(rki_b(2),rki_b(1));% expected bearing
                % measurements
                % range
                measurement_count = measurement_count + 1;
                ytilde(measurement_count) = ags(j).rb(i,m);
                Rk(measurement_count,measurement_count) = Rrange(j);
                yexp(measurement_count) = rhoki;
                % range gradient
                Hk(measurement_count,1:5) = [-(2*rkx*cos(psii) - 2*rix + 2*rky*sin(psii))/(2*((riy - rky*cos(psii) + rkx*sin(psii))^2 + (rkx*cos(psii) - rix + rky*sin(psii))^2)^(1/2))
                    (2*riy - 2*rky*cos(psii) + 2*rkx*sin(psii))/(2*((riy - rky*cos(psii) + rkx*sin(psii))^2 + (rkx*cos(psii) - rix + rky*sin(psii))^2)^(1/2))
                    0
                    0
                    (2*(rkx*cos(psii) + rky*sin(psii))*(riy - rky*cos(psii) + rkx*sin(psii)) + 2*(rky*cos(psii) - rkx*sin(psii))*(rkx*cos(psii) - rix + rky*sin(psii)))/(2*((riy - rky*cos(psii) + rkx*sin(psii))^2 + (rkx*cos(psii) - rix + rky*sin(psii))^2)^(1/2))]';
                % bearing
                measurement_count = measurement_count + 1;
                ytilde(measurement_count) = ags(j).rb(i,m+M);
                Rk(measurement_count,measurement_count) = Rbear(j);
                yexp(measurement_count) = thetaki;
                yexp(measurement_count) = minangle(yexp(measurement_count),ytilde(measurement_count));
                % bearing gradient
                Hk(measurement_count,1:5) = [-(riy - rky*cos(psii) + rkx*sin(psii))/(rix^2 - 2*cos(psii)*rix*rkx - 2*sin(psii)*rix*rky + riy^2 + 2*sin(psii)*riy*rkx - 2*cos(psii)*riy*rky + rkx^2 + rky^2)
                    -(rkx*cos(psii) - rix + rky*sin(psii))/(rix^2 - 2*cos(psii)*rix*rkx - 2*sin(psii)*rix*rky + riy^2 + 2*sin(psii)*riy*rkx - 2*cos(psii)*riy*rky + rkx^2 + rky^2)
                    0
                    0
                    (rix*(rkx*cos(psii) + rky*sin(psii)) + riy*(rky*cos(psii) - rkx*sin(psii)) - rkx^2 - rky^2)/(rix^2 - 2*cos(psii)*rix*rkx - 2*sin(psii)*rix*rky + riy^2 + 2*sin(psii)*riy*rkx - 2*cos(psii)*riy*rky + rkx^2 + rky^2)]';
            end
        end
    else
        % we have not programmed this case yet
        disp('Error: cannot handle partially measured relative position vectors yet');
        break;
    end
end