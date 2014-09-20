function [yexp,Hk,xkj] = get_expectation(i,j,M,xkj,ytilde,fl,rhoji,thetaji,thetaij)

N = 1+length(rhoji);
Nf = xkj.Nf;

% constants for feature initialization:
RHO0 = 0.5;
SIGMARHO = 0.25;

MN = length(ytilde);

yexp = zeros(MN,1);

Nf = xkj.Nf;
x0hat = xkj.xk(i,:)';
MNN = sqrt(length(xkj.Pk(i,:)'));
P0hat = reshape(xkj.Pk(i,:)',MNN,MNN);
Puse = P0hat(1:(5+4*Nf),1:(5+4*Nf));

% measurement gradient matrix
Hk = zeros(MN,MNN);

% current state
psii = x0hat(5);
rb = x0hat(1:2);
% inertial-to-body DCM
Cbn = [cos(psii) sin(psii);-sin(psii) cos(psii)];

for measurement_count = 1:MN
    if fl(measurement_count,2) == 0
        %my observation
        thetaki = ytilde(measurement_count);
        % have we seen the feature before?
        if ismember((j-1)*M+m,xkj.fl)
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
            xkj.fl(Nf) = (j-1)*M+m;
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
            P0hat(1:indNf+4,1:indNf+4) = J*P*J';
            Puse = P0hat(1:indNf+4,1:indNf+4);
        end
    else
        %other agent's
        thetakj = ytilde(measurement_count);
        % check all other agents' feature measurements
        %for j2 = [1:j-1 j+1:N]
        %end
    end
end

end