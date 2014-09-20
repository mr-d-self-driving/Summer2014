
global N M FOV RANGE RANGEMIN Rbear Rbear_ag Rrange_ag;

% constants for feature initialization:
RHO0 = 0.5;
SIGMARHO = 0.25;

% measurement model for the case of unknown features whose bearing is
% measured when agent-to-agent range and bearing are measured

Nf = xkj.Nf;
%x0hat = x0hat;%xkj.xk(i,:)';
%P0hat = reshape( xkj.Pk(i,:), 4*M*N+5, 4*M*N+5 );
%Puse = P0hat(1:(5+4*Nf),1:(5+4*Nf));
%p0hat = pt(1:5+4*nf,1:5+4*nf);
measurement_count = 0;

ytilde = zeros(N*M,1);
yexp = zeros(N*M,1);
% measurement gradient matrix
Hk = zeros(N*M,5+4*M*N);
% covariance matrix for output equation
Rk = zeros(N*M);
psii = x0hat(5);
rb = x0hat(1:2);
% inertial-to-body DCM
Cbn = [cos(psii) sin(psii);-sin(psii) cos(psii)];

if i < 0
    return;
end

% use our own feature measurements
for m = 1:M
    % measured bearing:
    thetaki = ags(j).rb(i,m+M);
    %check that the measurement is less than the FOV
    if abs(thetaki) <= FOV(j)*d2r && abs(ags(j).rb(i,m)) < RANGE(j) && abs(ags(j).rb(i,m)) > RANGEMIN(j)
        % have we seen the feature before?
        if ismember((j-1)*M+m,xkj.fl)
            % if we have seen it, use the estimate
            measurement_count = measurement_count+1;
            % index of the feature state estimate in the overall state
            indfl = find(xkj.fl == (j-1)*M+m);
            indNf = 5+4*(indfl-1);
            % compute the expectation
            xyi = x0hat(indNf+(1:2));
            invrhoi = x0hat(indNf + 3);
            thetai = x0hat(indNf + 4);
            % inertial frame expected vector to feature:
            ri = xyi + 1/invrhoi*[cos(thetai);sin(thetai)];
            % body frame expected vector to feature, from the body:
            rib = Cbn*(ri-rb);
            % expected measurement:
            yexp(measurement_count) = atan2(rib(2),rib(1));
            yexp(measurement_count) = minangle(yexp(measurement_count),thetaki);
            % measurement:
            ytilde(measurement_count) = thetaki;
            % measurement covariance
            Rk(measurement_count,measurement_count) = Rbear(j);
            % measurement gradient
            % gradient w.r.t. body x-y
            drb = -Cbn;
            % gradient w.r.t. anchor x-y
            dxyi = Cbn;
            % gradient w.r.t. inverse range
            drhoi = -Cbn*1/invrhoi^2*[cos(thetai);sin(thetai)];
            % gradient w.r.t. bearing
            dthetai = Cbn*1/invrhoi*[-sin(thetai);cos(thetai)];
            % gradient w.r.t. body heading
            dpsii = [-sin(psii) cos(psii);-cos(psii) -sin(psii)]*(ri-rb);
            % store measurement gradient
            constO = rib(1)^2/(rib(2)^2+rib(1)^2);
            Hk(measurement_count,1) = constO*( drb(2,1)/rib(1)-rib(2)*drb(1,1)/rib(1)^2 );
            Hk(measurement_count,2) = constO*( drb(2,2)/rib(1)-rib(2)*drb(1,2)/rib(1)^2 );
            Hk(measurement_count,5) = constO*( dpsii(2)/rib(1)-rib(2)*dpsii(1)/rib(1)^2 );
            Hk(measurement_count,indNf+1) = constO*( dxyi(2,1)/rib(1)-rib(2)*dxyi(1,1)/rib(1)^2 );
            Hk(measurement_count,indNf+2) = constO*( dxyi(2,2)/rib(1)-rib(2)*dxyi(1,2)/rib(1)^2 );
            Hk(measurement_count,indNf+3) = constO*( drhoi(2)/rib(1)-rib(2)*drhoi(1)/rib(1)^2 );
            Hk(measurement_count,indNf+4) = constO*( dthetai(2)/rib(1)-rib(2)*dthetai(1)/rib(1)^2 );
        else
            % if this is new feature, initialize
            Nf = Nf + 1;
            %xkj.fl(Nf) = (j-1)*M+m;
            % initialize feature state
            % feature state index: 5 + 4*(Nf-1) + (1:4)
            indNf = 5+4*(Nf-1);
            % initialize (xi,yi) to my current position estimate, global frame
            x0hat(indNf + (1:2)) = rb;
            % initialize rhoi
            x0hat(indNf + 3) = RHO0;
            % initialize bearing theta to the measured value, inertial frame 
            x0hat(indNf + 4) = thetaki + psii;
            % re-initialize covariance with new terms
            P = zeros(indNf+2);
            P(1:indNf,1:indNf) = Puse(1:indNf,1:indNf);
            P(indNf+1,indNf+1) = Rbear(j);
            P(indNf+2,indNf+2) = SIGMARHO^2;
            % Jacobian of the new states w.r.t. the old states and the image plane measurement and range  
            J = zeros(indNf+4,indNf+2);
            J(1:indNf,1:indNf) = eye(indNf);
            % Jacobian of feature anchor X, Y
            J(indNf+(1:2),1:2) = eye(2);
            % Jacobian of range
            J(indNf+3,indNf+2) = 1;
            % Jacobian of bearing
            J(indNf+4,[5 indNf+1]) = 1;
            % update covariance
            %P0hat(1:indNf+4,1:indNf+4) = J*P*J';
            Puse = J*P*J';%
        end
    end
end

% check all other agents' feature measurements
for j2 = [1:j-1 j+1:N]
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
        % check if the other agent can see the feature
        if abs(ags(j2).rb(i,m+M)) <= d2r*FOV(j2) && abs(ags(j2).rb(i,m)) < RANGE(j2) && abs(ags(j2).rb(i,m)) > RANGEMIN(j2)
            % use the feature
            thetakj = ags(j2).rb(i,m+M);
            % have we seen the feature before? If yes, use estimate
            if ismember((j2-1)*M+m,xkj.fl)
                measurement_count = measurement_count + 1;
                % index of the feature state estimate in the overall state
                indfl = find(xkj.fl == (j2-1)*M+m);
                indNf = 5+4*(indfl-1);
                % compute the expectation
                xyi = x0hat(indNf+(1:2));
                invrhoi = x0hat(indNf + 3);
                thetai = x0hat(indNf + 4);
                % inertial frame expected vector to feature:
                ri = xyi + 1/invrhoi*[cos(thetai);sin(thetai)];
                % expected vector from agent k to j in body i frame
                rkj_bi = Cbn*(ri - rb) - rhoji*[cos(thetaji);sin(thetaji)];
                % constraint equation
                tt = atan2(rkj_bi(2),rkj_bi(1));
                tt = minangle(tt,thetakj + delta);
                ytilde(measurement_count) = thetakj + delta - tt;
                yexp(measurement_count) = 0;
                Rx = zeros(11);
                Rx(1:7,1:7) = Puse([1 2 5 indNf+(1:4)],[1 2 5 indNf+(1:4)]);
                Rx(8,8) = Rrange_ag;
                Rx(9,9) = Rbear_ag;
                Rx(10,10) = Rbear_ag;
                Rx(11,11) = Rbear(j2);
                x = [rb;psii;xyi;invrhoi;thetai;rhoji;thetaji;thetaij;thetakj];
                %measurement covariance & effective measurement
                [ytilde(measurement_count),Rk(measurement_count,measurement_count)] = statisticalLinearization(x,Rx,@sl_unknown_invrange_std_coop);
                %measurement gradient
                dr = [-Cbn [-sin(psii) cos(psii); -cos(psii) -sin(psii)]*(ri-rb) Cbn -Cbn/invrhoi^2*[cos(thetai);sin(thetai)] Cbn/invrhoi*[-sin(thetai);cos(thetai)]];
                constO = 1/(rkj_bi(2)^2 + rkj_bi(1)^2);
                Hk(measurement_count,1:2) = constO*(rkj_bi(1)*dr(2,1:2) - rkj_bi(2)*dr(1,1:2));
                Hk(measurement_count,[5 indNf+(1:4)]) = constO*(rkj_bi(1)*dr(2,3:7) - rkj_bi(2)*dr(1,3:7));
                % check gradient
                %Hp = zeros(1,11);
                %for i = 1:11
                %    xPp = x;
                %    xPp(i) = xPp(i) + 1e-10;
                %    Hp(i) = 1e10*(sl_unknown_invrange_std_coop(xPp)-sl_unknown_invrange_std_coop(x));
                %end
                %disp('pause');
            else
                % if this is a new feature, initialize, using the same
                % initialization as for the individual case
                Nf = Nf + 1;
                %xkj.fl(Nf) = (j2-1)*M+m;
                % initialize feature state
                % feature state index: 5 + 4*(Nf-1) + (1:4)
                indNf = 5+4*(Nf-1);
                % initialize (xi,yi) to where I think the sensing agent is, global frame
                x0hat(indNf + (1:2)) = rb + Cbn'*rhoji*[cos(thetaji);sin(thetaji)];
                % initialize rhoi
                x0hat(indNf + 3) = RHO0;
                % initialize bearing theta to the measured value, inertial frame
                x0hat(indNf + 4) = thetakj + psii + delta;
                % re-initialize covariance matrix with new terms
                P = zeros(8);
                % the eight terms are:
                % [xi,yi,psii,rhoji,thetaji,thetaij, thetakj, rhoki (inv range)]
                P(1:3,1:3) = Puse([1:2 5],[1:2 5]);
                P(4,4) = Rrange_ag;
                P(5,5) = Rbear_ag;
                P(6,6) = Rbear_ag;%j2's agent-agent range err
                P(7,7) = Rbear(j2);
                P(8,8) = SIGMARHO^2;
                rji_til = rhoji*[cos(thetaji);sin(thetaji)];
                % Jacobian of the new states w.r.t. the old states and the image plane measurement and range
                J = zeros(4,8);
                J(1:2,1:2) = eye(2);
                J(1:2,3) = [-sin(psii) -cos(psii);cos(psii) -sin(psii)]*rji_til;
                J(1:2,4) = Cbn'*[cos(thetaji);sin(thetaji)];
                J(1:2,5) = rhoji*Cbn'*[-sin(thetaji);cos(thetaji)];
                J(3,8) = 1;
                J(4,3) = 1;
                J(4,5) = 1;
                J(4,6) = -1;
                J(4,7) = 1;
                % update covariance
                %P0hat(indNf+(1:4),indNf+(1:4)) = J*P*J';
                Puse(indNf+(1:4),indNf+(1:4)) = J*P*J';
            end
        end
    end
end

Hk(measurement_count+1:end,:) = [];
Rk(measurement_count+1:end,:) = [];
Rk(:,measurement_count+1:end) = [];
ytilde(measurement_count+1:end) = [];
yexp(measurement_count+1:end) = [];