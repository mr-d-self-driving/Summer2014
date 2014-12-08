%% gen_data

clear variables;
close all;

addpath('../../2D');
addpath('../');

%% generate data

if ~exist('data_3d.mat','file');
    
    % sample time
    Ts = 0.01;
    % sim time
    Tmax = 20;
    
    % number of known features
    M = 20;
    % allowable sphere for feature initialization
    R_feature = 20;
    % generate known feature locations
    r = rand(M,1)*R_feature;
    thet = rand(M,1)*2*pi-pi;
    phi = rand(M,1)*pi-0.5*pi;
    % array of known feature locations
    XYZ_KNOWN = repmat(r,1,3).*[cos(phi).*cos(thet) cos(phi).*sin(thet) sin(phi)];
    
    % unknown features
    U = 20;
    % generate known feature locations
    r = rand(U,1)*R_feature;
    thet = rand(U,1)*2*pi-pi;
    phi = rand(U,1)*pi-0.5*pi;
    % array of known feature locations
    XYZ_UNKNOWN = repmat(r,1,3).*[cos(phi).*cos(thet) cos(phi).*sin(thet) sin(phi)];
        
    % allowed agent initialization space
    R = 10;
    % target average speed
    Vb = 1.25;
    % number of agents
    N = 2;
    
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
        garb = attpar(q0,[6 4],struct('seq',[1; 2; 1]));
        eul0 = garb(:,1);
        eul0dot = [0;0;0];
        
        tnow = 0;
        
        Y = zeros(length(T),13);% r1 r2 r3 v1 v2 v3 quat omega
        a0 = [0;0;0];
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
            BC = [1 0 0 0 0;0 1 0 0 0;1 Tf Tf^2 Tf^3 Tf^4;0 1 2*Tf 3*Tf^2 4*Tf^3;0 0 2 0 0];% enforce continuity of accel at the start time
            for i = 1:3
                % coefficients
                vc(:,i) = BC\[r0(i);v0(i);rf(i);vf(i);a0(i)];
            end
            
            % reference attitude
            vran = rand(3,1);vran = vran./norm(vran);
            ref1 = [0 1 2 3 4]*vc;ref1 = ref1./norm(ref1);% body 1-axis reference, in inertial frame, at t = 1 sec
            ref2 = cross(ref1,vran);ref2 = ref2./norm(ref2);
            ref3 = cross(ref1,ref2);
            Cbn = [ref1' ref2' ref3']';
            
            % reference quaternion, scalar first
            qref = attpar(Cbn,[1 6]);
            garb = attpar(Cbn,[1 4],struct('seq',[1 2 1]'));
            eulref = garb(:,1);
            
            A = 2;
            
            eulref = minangle(eulref,eul0);
            
            eq = eul0 - eulref;
            
            lt = (1:length(t));
            if count+length(t) > length(T)
                lt = 1:(length(T)-count);
                t = t(lt);
            end
            
            qu = zeros(length(t),4);
            %eul = zeros(length(t),3);
            %euldot = zeros(length(t),3);
            omega = zeros(length(t),3);
            
            rc = zeros(4,3);
            EC = [1 0 0 0;0 1 0 0;1 Tf Tf^2 Tf^3;0 1 2*Tf 3*Tf^2];
            for i = 1:3
                %just do a polynomial for this also
                rc(:,i) = EC\[eul0(i);eul0dot(i);eulref(i);0];
                
                %eul(:,i) = eq(i)*exp(-A*t) + eulref(i);
                %euldot(:,i) = -A*eq(i)*exp(-A*t);
            end
            eul = [ones(length(t),1) t' t.^2' t.^3']*rc;
            euldot = [zeros(length(t),1) ones(length(t),1) 2*t' 3*t.^2']*rc;
            for i = 1:length(t)
                omega(i,:) = ([euldot(i,3);0;0] + DCMConverter(1,eul(i,3))*[0;euldot(i,2);0] + DCMConverter(1,eul(i,3))*DCMConverter(2,eul(i,2))*[euldot(i,1);0;0])';
                qu(i,:) = attpar([eul(i,:)' [1;2;1]],[4 6])';
            end
            
            % position (inertial frame)
            Y(count+lt,1:3) = [ones(length(t),1) t' t.^2' t.^3' t.^4']*vc;
            % velocity (inertial frame)
            Y(count+lt,4:6) = [zeros(length(t),1) ones(length(t),1) 2*t' 3*t.^2' 4*t.^3']*vc;
            % attitude (quaternion)
            Y(count+lt,7:10) = qu;
            % angular velocity
            Y(count+lt,11:13) = omega;
            % euler angles
            Y(count+lt,14:16) = eul;     
            % store acceleration also (inertial frame)
            Y(count+lt,17:19) = [zeros(length(t),1) zeros(length(t),1) 2*ones(length(t),1) 6*t' 12*t.^2']*vc;
            a0 = Y(count+lt(end),17:19);
            
            count = count+length(lt);
            tnow = tnow + t(end);
            
            % reset for next iteration
            r0 = Y(count,1:3)';
            v0 = Y(count,4:6)';
            q0 = Y(count,7:10)';
            eul0 = eul(end,:)';
            eul0dot = euldot(end,:)';
        end
        
        Y(:,7:10) = quatmin(Y(:,7:10));
        
        Yc{II} = Y;
    end
    
    save data_3d.mat;
else
    load data_3d.mat;
end