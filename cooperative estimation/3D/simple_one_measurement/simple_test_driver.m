clear variables;
close all;

%% generate data

if ~exist('data.mat','file');
    
    % sample time
    Ts = 0.1;
    % sim time
    Tmax = 60;
    
    % allowed position space
    R = 10;
    % target average speed
    Vb = 1;
    % number of agents
    N = 3;
    
    % data storage
    T = 0:Ts:Tmax;
    Yc = cell(N,1);
    
    for II = 1:N
        
        % initialize
        r = rand*2*R-R;
        theta = rand*2*pi - pi;
        phi = (rand-0.5)*pi;
        
        r0 = [r*cos(phi)*cos(theta);
            r*cos(phi)*sin(theta);
            r*sin(phi)];
        v0 = [0;0;0];
        q0 = rand(4,1);q0 = q0./norm(q0);
        
        tnow = 0;
        
        Y = zeros(length(T),10);% r1 r2 r3 v1 v2 v3 quat
        count = 0;
        while(count < length(T))
            
            % pick a point in the space
            r = rand*2*R-R;
            theta = rand*2*pi - pi;
            phi = (rand-0.5)*pi;
            
            rf = [r*cos(phi)*cos(theta);
                r*cos(phi)*sin(theta);
                r*sin(phi)];
            vf = [0;0;0];
            % final time
            Tf = norm(rf-r0)/Vb;
            Tf = round(Tf/Ts)*Ts;% round to nearest sample time for simplicity
            % r0 proscribed
            
            % time vector, relative to last move
            t = 0:Ts:Tf;
            
            % generate coefficients for reference traj
            BC = [1 0 0 0;0 1 0 0;1 Tf Tf^2 Tf^3;0 1 2*Tf 3*Tf^2];
            for i = 1:3
                % coefficients
                vc(:,i) = BC\[r0(i);v0(i);rf(i);vf(i)];
            end
            
            % reference attitude
            vran = rand(3,1);vran = vran./norm(vran);
            ref1 = [0 1 2 3]*vc;ref1 = ref1./norm(ref1);% body 1-axis reference, in inertial frame
            ref2 = cross(ref1,vran);ref2 = ref2./norm(ref2);
            ref3 = cross(ref1,ref2);
            Cbn = [ref1' ref2' ref3']';
            
            % reference quaternion, scalar first
            qref = attpar(Cbn,[1 6]);
            garb = attpar(Cbn,[1 4],struct('seq',[1 2 1]'));
            eulref = garb(:,1);
            
            garb = attpar(q0,[6 4],struct('seq',[1 2 1]'));
            eul0 = garb(:,1);
            
            A = 2;
            
            eq = eul0 - eulref;
            
            lt = (1:length(t));
            if count+length(t) > length(T)
                lt = 1:(length(T)-count);
                t = t(lt);
            end
            
            qu = zeros(length(t),4);
            eul = zeros(length(t),3);
            for i = 1:3
                eul(:,i) = eq(i)*exp(-A*t) + eulref(i);
            end
            for i = 1:length(t)
                qu(i,:) = attpar([eul(i,:)' [1;2;1]],[4 6])';
            end
            
            Y(count+lt,1:3) = [ones(length(t),1) t' t.^2' t.^3']*vc;
            Y(count+lt,4:6) = [zeros(length(t),1) ones(length(t),1) 2*t' 3*t.^2']*vc;
            Y(count+lt,7:10) = qu;
            
            % reset for next iteration
            r0 = Y(count+length(lt),1:3)';
            v0 = Y(count+length(lt),4:6)';
            q0 = Y(count+length(lt),7:10)';
            
            count = count+length(lt);
            tnow = tnow + t(end);
        end
        
        Yc{II} = Y;
    end
    
    save data.mat;
else
    load data.mat;
end
%% generate measurements for each 
if ~exist('meas','var')
    
    % error stdev
    err_dev = 0.1;%rads
    
    meas = cell(N,1);
    for II = 1:N
        meas{II} = zeros(length(T),(N-1)*3);
        Jcount = 0;
        for JJ = [1:II-1 II+1:N]
            Jcount = Jcount+1;
            % inertial vector from II to JJ
            rdiff = Yc{JJ}(:,1:3) - Yc{II}(:,1:3);
            % convert to body frame
            rsee = zeros(size(rdiff));
            rmeas = zeros(size(rdiff));
            for i = 1:length(T)
                quat = Yc{II}(:,7:10)';
                Cbn = attpar(quat,[6 1]);
                rsee(i,:) = rdiff(i,:)*Cbn';
                
                % generate error angle
                delta = randn*err_dev;
                
                % get arbitrary axis of rotation
                vec = rand(3,1);vec = vec./norm(vec);
                
                % get DCM from true to error "frame"
                Crp_r = attpar([vec [delta;0;0]],[2 1]);
                
                rmeas(i,:) = rsee(i,:)*Crp_r;
                % use the unit vector as the measurement
                rmeas(i,:) = rmeas(i,:)./norm(rmeas(i,:));
            end
            
            meas{II}(:,(Jcount-1)*3+(1:3)) = rmeas;
        end
    end
    save data.mat;
end
%% process

Nuse = 2;

xh = cell(Nuse,1);
Ph = cell(Nuse,1);

tv = sort([T T T(1)]);

for i = 1:Nuse
    xh{i} = zeros(length(tv),(Nuse-1)*4);
    Ph{i} = zeros(length(tv),((Nuse-1)*4)^2);
    xh{i}(1,:) = [1 0 0 0];
    Ph{i}(1,:) = reshape( eye(4), ((Nuse-1)*4)^2,1)';
end

for j = 1:Nuse
    for k = 1:length(T)
        %% update
        xht = xh{j}(2*k-1,:)';
        Pht = reshape(Ph{j}(2*k,:)',(Nuse-1)*4,(Nuse-1)*4);
        
        ymeas = zeros(3*Nuse,1);
        
        jjcount = 0;
        for jj = [1:j-1 j+1:Nuse]
            jjcount = jjcount+1;
            xhat = xht((jjcount-1)*4+(1:4));
            Cji = eye(3) - 2*xhat(1)*squiggle(xhat(2:4)) + 2*squiggle(xhat(2:4))^2;
            
            % my meas of him
            rji_i = meas{j}(k,(jjcount-1)*3+(1:3))';
            % his meas of me
            if jj > j
                rij_j = meas{jj}(k,(j-1)*3+(1:3))';
            else
                rij_j = meas{jj}(k,(j-2)*3+(1:3))';
            end
            % error
            ydiff = rij_j + Cji*rji_i;
            
            % measurement gradient
            Hk = zeros(3,4);
            Hk(:,1) = -2*squiggle(xhat(2:4))*rji_i;
            Hk(:,2:4) = 2*xhat(1)*squiggle(rji_i) - 2*squiggle(xhat(2:4))*squiggle(rji_i) - 2*squiggle( squiggle(xhat(2:4))*rji_i );
            
            % measurement error
            
        end
        
        %% propagate
        xhat = xh{j}(2*k,:)';
        Phat = reshape(Ph{j}(2*k+1,:)',4,4);
    end
end