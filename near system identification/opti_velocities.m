function [to,xyz_b,v_b,a_b,quat_b,w_b,v_n,a_n] = opti_velocities(t,xyz,quat, DEBUG)
% given optitrack data, consisting of inertial position in an NED frame and
% quaternion from the NED frame to the standard aircraft body frame, filter
% the data and output estimates of the velocity, acceleration, and angular
% velocity time histories, translational components are given in the INERTIAL frame

if nargin < 4
    DEBUG = 0;
end

% time history loses two data points b/c of differentiation
to = t(1:end-2);

% position-level filter
[b,a] = butter(1,0.75/50,'low');
xyz0 = repmat(xyz(1,:),length(xyz),1);
xyz_avg = filter(b,a,xyz-xyz0) + xyz0;

xyz_b = xyz_avg(1:end-2,:);

%velocity-level filter
v_n = diff(xyz_avg)./repmat(diff(t),1,3);

[bv,av] = butter(1,0.5/50.0,'low');
v_n_avg = filter(bv,av,v_n);

%acceleration-level filter
a_n = (xyz_avg(1:end-2,:)-2*xyz_avg(2:end-1,:)+xyz_avg(3:end,:))./repmat( diff(t(2:end)).^2 , 1,3);

[ba,aa] = butter(1,0.25/50,'low');

ao = repmat(a_n(1,:),length(a_n),1);
a_n_avg = filter(ba,aa,a_n - ao)+ ao;

% attitude smoothing
quat_b = filter(b,a,quat - repmat( quat(1,:), length(quat), 1)) + repmat( quat(1,:), length(quat), 1);
%normalize
quat_b = quat_b./repmat(sqrt(sum(quat_b.^2,2)),1,4);

[bq,aq] = butter(1,2.5/50.0,'low');
% approximate dq/dt
dq = diff(quat_b)./repmat(diff(t),1,4);
%dq_avg = filter(Hv,dq);
dq_avg = filter(bq,aq,dq);

% compute body-frame velocity and accelerations
v_b = zeros(size(a_n_avg,1),3);
a_b = v_b;
w_b = v_b;
for i = 1:length(to)
    B0 = quat_b(i,4);
    Bv = quat_b(i,1:3)';
    B = 2*[-Bv eye(3)*B0-squiggle(Bv)];
    Bdot = dq_avg(i,[4 1:3])';
    w_b(i,:) = (B*Bdot)';
    
    C = attparsilent([B0;Bv],[6 1]);
    v_b(i,:) = v_n_avg(i,:)*C';
    a_b(i,:) = a_n_avg(i,:)*C';
end

v_n = v_n_avg(1:end-1,:);
quat_b = quat_b(1:end-2,:);

if DEBUG
    xyz_int = zeros(size(v_n));
    v_n_int = zeros(size(v_n));
    xyz_int_acc = zeros(size(v_n));
    for i = 1:length(v_n)
        if i == 1
            xyz_int(i,:) = xyz_b(i,:);
            v_n_int(i,:) = v_n(1,:);
            xyz_int_acc(i,:) = xyz_b(i,:);
        else
            xyz_int(i,:) = xyz_b(1,:) + trapz(to(1:i),v_n(1:i,:));
            v_n_int(i,:) = v_n(1,:) + trapz(to(1:i),a_n(1:i,:));
            xyz_int_acc(i,:) = xyz_b(i,:) + trapz(to(1:i),v_n_int(1:i,:));
        end
    end
    
    for i = 1:3
        figure(1)
        subplot(3,1,i);
        plot(to,xyz_b(:,i),'-','linewidth',2);
        hold on;
        plot(to,xyz_int(:,i),'r--','linewidth',2);
        plot(t,xyz(:,i),'k:','linewidth',2);
        switch i
            case 1
                ylabel('x');
            case 2
                ylabel('y');
            case 3
                ylabel('z');
        end
        
        figure(2)
        subplot(3,1,i);
        plot(to,v_n(:,i),'-','linewidth',2);
        hold on;
        plot(to,v_n_int(:,i),'r--','linewidth',2);
        switch i
            case 1
                ylabel('xdot');
            case 2
                ylabel('ydot');
            case 3
                ylabel('zdot');
        end
    end
end
end