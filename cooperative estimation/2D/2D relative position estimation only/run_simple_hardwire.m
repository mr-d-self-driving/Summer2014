
%% initialize
tk = [sort([tspan tspan]) tspan(end)+Ts];
xk(N) = struct('xk',zeros(length(tspan)*2+1,5*N-2),'Pk',zeros(length(tspan)*2+1,(5*N-2)^2));
for i = 1:N
    if i == 1
        i2 = 2;
    else
        i2 = 1;
    end
    if SHARE_IMU
        xk(i) = struct('xk',zeros(length(tspan)*2+1,5*N-2),'Pk',zeros(length(tspan)*2+1,(5*N-2)^2));
        xk(i).xk(1,[1:3 6:7]) = [ags(i).truth(1,3:5) ags(i2).truth(1,3:4)];
        xk(i).xk(1,8) = [ags(i2).truth(1,5) - ags(i).truth(1,5)];
        Cbn = [cos(ags(i).truth(1,5)) sin(ags(i).truth(1,5));-sin(ags(i).truth(1,5)) cos(ags(i).truth(1,5))];
        xk(i).xk(1,[4 5]) = [ags(i2).truth(1,1:2)-ags(i).truth(1,1:2)]*Cbn';
        xk(i).Pk(1,:) = reshape( diag([.64 .64 .01 1.0 1.0 .64 .64 .01]),[],1)';
    else
        xk(i) = struct('xk',zeros(length(tspan)*2+1,3),'Pk',zeros(length(tspan)*2+1,(3)^2));
        xk(i).xk(1,[1:3]) = [ags(i).truth(1,3:5)];
        xk(i).Pk(1,:) = reshape( diag([.64 .64 .01]),[],1)';
    end
end

if SHARE_IMU
    Qk = diag( [diag(Rimu);diag(Rimu)]);
else
    Qk = Rimu;
end

for i = 1:length(tspan)
    %% update
    for j = 1:2
        xk(j).xk(2*i,:) = xk(j).xk(2*i-1,:);
        xk(j).Pk(2*i,:) = xk(j).Pk(2*i-1,:);
        continue;
        
        if j == 1
            j2 = 2;
        else
            j2 = 1;
        end
        
        % we have to use HIS position measurements also
        ytilde = zeros(4,1);
        yexp = zeros(4,1);
        Hk = zeros(4,8);
        
        x0hat = xk(j).xk(2*i-1,:)';% u,v,psi,rjix,rjiy,uj,vj,psiji - all are in body frame
        P0hat = reshape(xk(j).Pk(2*i-1,:)',N*5-2,N*5-2);
        
        % other agent's relative position, in my body frame
        rjix = x0hat(4);
        rjiy = x0hat(5);
        psiji = x0hat(8);
        
        % measured range to other agent
        rhoji = ags(j).rb_agent(i,1);
        % measured bearing to other agent
        thetaji = ags(j).rb_agent(i,2);
        
        ytilde(1:2) = [rhoji;thetaji];
        yexp(1:2) = [sqrt(rjix^2+rjiy^2);atan2(rjiy,rjix)];
        
        Hk(1,4:5) = [rjix/sqrt(rjix^2+rjiy^2) -rjiy/(rjiy^2+rjix^2)];
        Hk(2,4:5) = [rjiy/sqrt(rjix^2+rjiy^2) rjix/(rjiy^2+rjix^2)];
        
        Rk(1:2,1:2) = diag([Rrange_ag Rbear_ag]);
        
        rhoij = ags(j2).rb_agent(i,1);
        thetaij = ags(j2).rb_agent(i,2);
        
        ytilde(3:4) = [rhoij;thetaij];
        yexp(3:4) = [sqrt(rjix^2+rjiy^2);pi+atan2(rjiy,rjix) - psiji];
        
        Hk(3,4:5) = [rjix/sqrt(rjix^2+rjiy^2) -rjiy/(rjiy^2+rjix^2)];
        Hk(4,[4:5 8]) = [rjiy/sqrt(rjix^2+rjiy^2) rjix/(rjiy^2+rjix^2) -1];
        
        Rk(3:4,3:4) = diag([Rrange_ag Rbear_ag]);
        
        ytilde([2 4]) = minangle(ytilde([2 4]),yexp([2 4]));
        
        Kk = P0hat*Hk'*((Hk*P0hat*Hk' + Rk)\eye(size(Rk)));
        % update estimate
        x0hat = x0hat + Kk*(ytilde-yexp);
        % update covariance
        P0hat = (eye(8)-Kk*Hk)*P0hat;
        
        % store values
        xk(j).xk(2*i,:) = x0hat';
        xk(j).Pk(2*i,:) = reshape(P0hat,(N*5-2)^2,1)';
    end
    %% propagate
    for j = 1:N
        if SHARE_IMU
            x0hat = xk(j).xk(2*i,:)';
            P0hat = reshape(xk(j).Pk(2*i,:)',N*5-2,N*5-2);
            imu = ags(j).IMU(i,:)';% a1 a2 omega
            % propagate own eqom:
            vi = x0hat(1:2);%body frame velocity vector
            psii = x0hat(3);%heading
            Cbin = [cos(psii) sin(psii);-sin(psii) cos(psii)];

            omega = imu(3);
            ai = imu(1:2);
            % dxhat/dt
            f = zeros(5*N-2,1);
            f(1:3) = [ai - [0 -omega;omega 0]*vi;
                omega];
            %gradient of f
            Fk = zeros(5*N-2,3*N);
            Fk(1:3,1:3) = [-[0 -omega;omega 0] zeros(2,1);
                zeros(1,3)];

            % process noise influence matirx
            G = zeros(5*N-2,3*N);
            G(1:3,1:3) = [-1 0 -vi(2);
                0 -1 vi(1);
                0 0 -1];
            % loop over each other agent
            cj = 0; % counter variable
            for jj = [1:j-1 j+1:N]
                cj = cj+1;
                psiji = x0hat(3+5*cj);
                vj = x0hat([1 2]+5*cj);
                rji = x0hat([-1 0]+5*cj);
                imuj = ags(jj).IMU(i,:)';

                Cbjbi = [cos(psiji) sin(psiji);-sin(psiji) cos(psiji)];
                % time rate of relative position
                f([-1 0]+5*cj) = Cbjbi'*vj - vi - [0 -omega;omega 0]*rji;
                % time rate of j frame velocity
                f([1 2]+5*cj) = imuj(1:2) - [0 -imuj(3);imuj(3) 0]*vj;
                % time rate of relative heading
                f(3+5*cj) = imuj(3) - omega;
                % gradient
                Fk([-1 0]+5*cj,1:2) = -eye(2);
                Fk([-1 0]+5*cj,5*cj-2+[1:2]) = - [0 -omega;omega 0];%diff w.r.t rji
                Fk([-1 0]+5*cj,5*cj-2+[3:4]) = Cbjbi';%diff w.r.t. vj
                Fk([-1 0]+5*cj,5*cj-2+5) = [-sin(psiji) -cos(psiji);cos(psiji) -sin(psiji)]*vj;%diff w.r.t psiji

                Fk([1 2]+5*cj,5*cj-2+[3:4]) = -[0 -imuj(3);imuj(3) 0];%diff w.r.t. vj
                % process noise
                G([-1 0]+5*cj,3) = [-rji(2);rji(1)];
                G([1 2] +5*cj,cj*3+(1:2)) = -eye(2);
                G([1 2] +5*cj,cj*3+3) = [vj(2);-vj(1)];
                G(3+5*cj,3) = 1;
                G(3+5*cj,cj*3+3) = -1;
            end
            G = Ts*G;

            % account for the discretized integration in Fk:
            Fk = Ts*Fk + eye(5*N-2);

            %update own associated states
            x0hat = x0hat + Ts*f;
            x0hat(3) = pi2pi(x0hat(3));
            x0hat([8:5:5*N-2]) = pi2pi(x0hat([8:5:5*N-2]));
            P0hat = Fk*P0hat*Fk' + G*Qk*G';
            % store new values
            xk(j).xk(2*i+1,:) = x0hat';
            xk(j).Pk(2*i+1,:) = reshape(P0hat,(N*5-2)^2,1)';
        else
            x0hat = xk(j).xk(2*i,:)';
            P0hat = reshape(xk(j).Pk(2*i,:)',3,3);
            imu = ags(j).IMU(i,:)';% a1 a2 omega
            % propagate own eqom:
            vi = x0hat(1:2);%body frame velocity vector
            psii = x0hat(3);%heading
            Cbin = [cos(psii) sin(psii);-sin(psii) cos(psii)];

            omega = imu(3);
            ai = imu(1:2);
            % dxhat/dt
            f = zeros(3,1);
            f(1:3) = [ai - [0 -omega;omega 0]*vi;
                omega];
            %gradient of f
            Fk = zeros(3,3);
            Fk(1:3,1:3) = [-[0 -omega;omega 0] zeros(2,1);
                zeros(1,3)];

            % process noise influence matirx
            G = zeros(3,3);
            G(1:3,1:3) = [-1 0 -vi(2);
                0 -1 vi(1);
                0 0 -1];
            G = Ts*G;

            % account for the discretized integration in Fk:
            Fk = Ts*Fk + eye(3);

            %update own associated states
            x0hat = x0hat + Ts*f;
            x0hat(3) = pi2pi(x0hat(3));
            P0hat = Fk*P0hat*Fk' + G*Qk*G';
            % store new values
            xk(j).xk(2*i+1,:) = x0hat';
            xk(j).Pk(2*i+1,:) = reshape(P0hat,(3)^2,1)';
        end
    end
end