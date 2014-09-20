%% second_version.m
% two agents with intermittent relative and egocentric position
% measurements

clear variables;
close all;

T_G = 10;%mean period between gps updates
T_R = 1;%mean period between relative range updates
T_imu = .02;%period between IMU measurements

%simulation time
Tf = 60;

% process noise matrix
G = [0;1];

% process noise covariance
Q = 1^2;

% state propagation matrices
A = [0 1;0 0];
B = [0; 1];

R_GPS = 1^2;
R_rel = 10^2;
R_imu = .2^2;

% initial conditions
x01 = [5;0];
x02 = [-2.4;0];

%% predetermine the time at which GPS and relative range updates occur
xr = rand(1000,1);
x = -T_G*log(1-xr); % solving the PDF for exponential distr w/ mean T_G for the time between failures

t_1_g = 0;
count = 0;
while t_1_g(end) < Tf
    count = count+1;
    t_1_g = [t_1_g;t_1_g(end)+x(count)];
end
t_1_g(end) = [];
t_2_g = 0;
while t_2_g(end) < Tf
    t_2_g = [t_2_g;t_2_g(end)+x(count)];
    count = count+1;
end
t_2_g(end) = [];
clear x xr;

xr = rand(1000,1);
x = -T_R*log(1-xr);

t_1_r = 0;
count = 0;
while t_1_r(end) < Tf
    count = count+1;
    t_1_r = [t_1_r;t_1_r(end)+x(count)];
end
t_1_r(end) = [];
t_2_r = 0;
while t_2_r(end) < Tf
    t_2_r = [t_2_r;t_2_r(end)+x(count)];
    count = count+1;
end
t_2_r(end) = [];
clear x xr;
%% simulate system

AA = [A zeros(2);zeros(2) A];
BB = [B zeros(2,1);zeros(2,1) B];
GG = [G zeros(2,1);zeros(2,1),G];
QQ = diag([Q Q]);

timu = (0:T_imu:Tf)';

tint = [t_1_g;t_2_g;t_1_r;t_2_r;timu];
bitmask = [1*ones(size(t_1_g));2*ones(size(t_2_g));4*ones(size(t_1_r));8*ones(size(t_2_r));16*ones(size(timu))];

[~,in] = sort(tint);
%remove excess zeros in tint
in(1:4) = [];
tint = tint(in);
bitmask = bitmask(in);
ctrlvar = round( log(bitmask)/log(2) );

that = zeros(1e4,1);
xhat1 = zeros(1e4,4);
xhat2 = zeros(1e4,4);
Phat1 = zeros(1e4,16);
Phat2 = zeros(1e4,16);
x1 = zeros(1e4,2);
x2 = zeros(1e4,2);

x0h1 = zeros(4,1);
x0h2 = zeros(4,1);
P0h1 = eye(4);
P0h2 = eye(4);
u1 = 0;
u2 = 0;
count = 0;
for i = 1:length(tint)-1
    tinetegrate = linspace(tint(i),tint(i+1),10);
    %integrate the real states from t = tint(i) to tint(i+1)
    [~,Y1] = simulateAgent(A,B,G,Q,tinetegrate,x01,u1);
    [~,Y2] = simulateAgent(A,B,G,Q,tinetegrate,x02,u2);
    x01 = Y1(end,:)';
    x02 = Y2(end,:)';
    
    x1(count+(1:10),:) = Y1;
    x2(count+(1:10),:) = Y2;
    
    % integrate the estimated states
    [T1,X1,P1] = estimatorState(AA,BB,GG,QQ,tinetegrate,x0h1,P0h1,[u1;u2]);
    [~,X2,P2] = estimatorState(AA,BB,GG,QQ,tinetegrate,x0h2,P0h2,[u1;u2]);
    
    x0h1 = X1(end,:)';
    x0h2 = X2(end,:)';
    P0h1 = reshape(P1(end,:),4,4);
    P0h2 = reshape(P2(end,:),4,4);
    
    that(count+(1:10),:) = T1;
    xhat1(count+(1:10),:) = X1;
    xhat2(count+(1:10),:) = X2;
    Phat1(count+(1:10),:) = P1;
    Phat2(count+(1:10),:) = P2;
    
    count = count+10;
    % update based on the bitmask
    switch ctrlvar(i)
        case 0
            %agent 1 global update
            y1 = global_meas(x01,R_GPS);
            H1 = [1 0 0 0];
            K1 = P0h1*H1'*((H1*P0h1*H1'+R_GPS)\eye(1));
            x0h1 = x0h1 + K1*(y1 - H1*x0h1);
            P0h1 = (eye(4) - K1*H1)*P0h1;
        case 1
            %agent 2 global update
            y2 = global_meas(x02,R_GPS);
            H2 = [0 0 1 0];
            K2 = P0h2*H2'*((H2*P0h2*H2'+R_GPS)\eye(1));
            x0h2 = x0h2 + K2*(y2 - H2*x0h2);
            P0h2 = (eye(4) - K2*H2)*P0h2;
        case 2
            %agent 1 relative update
            y1 = rel_meas(x01,x02,R_rel);
            H1 = [1 0 -1 0];
            K1 = P0h1*H1'*((H1*P0h1*H1'+R_GPS)\eye(1));
            x0h1 = x0h1 + K1*(y1 - H1*x0h1);
            P0h1 = (eye(4) - K1*H1)*P0h1;
        case 3
            %agent 2 relative update
            y2 = rel_meas(x01,x02,R_rel);
            H2 = [1 0 -1 0];
            K2 = P0h2*H2'*((H2*P0h2*H2'+R_GPS)\eye(1));
            x0h2 = x0h2 + K2*(y2 - H2*x0h2);
            P0h2 = (eye(4) - K2*H2)*P0h2;
        case 4
            %velocity update for both agents; control updates also
            H1 = [0 1 0 0];
            H2 = [0 0 0 1];
            
            K1 = P0h1*H1'*((H1*P0h1*H1'+R_imu)\eye(1));
            K2 = P0h2*H2'*((H2*P0h2*H2'+R_imu)\eye(1));
            
            % measurements
            y1 = vel_meas(x01,R_imu);
            y2 = vel_meas(x02,R_imu);
            
            %update state
            x0h1 = x0h1 + K1*(y1 - H1*x0h1);
            x0h2 = x0h2 + K2*(y2 - H2*x0h2);
            P0h1 = (eye(4) - K1*H1)*P0h1;
            P0h2 = (eye(4) - K2*H2)*P0h2;
            
            % control update
            u1 = -1*(x01(1) - cos(.650124*that(count)));
            u2 = -1*(x02(1) - sin(that(count)));
    end
    % store new values
    count  = count+1;
    that(count) = that(count-1);
    xhat1(count,:) = x0h1';
    xhat2(count,:) = x0h2';
    Phat1(count,:) = reshape(P0h1,[],1)';
    Phat2(count,:) = reshape(P0h2,[],1)';
    x1(count,:) = x01';
    x2(count,:) = x02';
end

that(count+1:end) = [];
xhat1(count+1:end,:) = [];
xhat2(count+1:end,:) = [];
Phat1(count+1:end,:) = [];
Phat2(count+1:end,:) = [];
x1(count+1:end,:) = [];
x2(count+1:end,:) = [];
%% plots
gps1 = find(ctrlvar==0);
gps2 = find(ctrlvar==1);
rel1 = find(ctrlvar==2);
rel2 = find(ctrlvar==3);

figure;
subplot(311);
plot(that,xhat1(:,1),'r--',that,x1(:,1),'b-');
hold on;
plot(tint(gps1),0*gps1,'md','markersize',12,'linewidth',2);
plot(tint(rel1),0*rel1,'ks','markersize',12);
ylabel('agent 1 x_1 estimate');

subplot(312);
plot(that,xhat1(:,3),'r--',that,x2(:,1),'b-');
hold on;
plot(tint(gps1),0*gps1,'md','markersize',12,'linewidth',2);
plot(tint(rel1),0*rel1,'ks','markersize',12);
ylabel('agent 1 x_2 estimate');

subplot(313);
plot(that,x1(:,1)-xhat1(:,1),'b-');
hold on;
plot(tint(gps1),0*gps1,'md','markersize',12,'linewidth',2);
plot(tint(rel1),0*rel1,'ks','markersize',12);
plot(that,3*sqrt(Phat1(:,1)),'k-');
plot(that,-3*sqrt(Phat1(:,1)),'k-');
ylabel('agent 1 position estimate error w/ 3\sigma');

figure;
subplot(311);
plot(that,xhat2(:,3),'r--',that,x2(:,1),'b-');
hold on;
plot(tint(gps2),0*gps2,'md','markersize',12,'linewidth',2);
plot(tint(rel2),0*rel2,'ks','markersize',12);
ylabel('agent 2 x_2 estimate');

subplot(312);
plot(that,xhat2(:,1),'r--',that,x1(:,1),'b-');
hold on;
plot(tint(gps2),0*gps2,'md','markersize',12,'linewidth',2);
plot(tint(rel2),0*rel2,'ks','markersize',12);
ylabel('agent 2 x_1 estimate');

subplot(313);
plot(that,x2(:,1)-xhat2(:,3),'b-');
hold on;
plot(tint(gps2),0*gps2,'md','markersize',12,'linewidth',2);
plot(tint(rel2),0*rel2,'ks','markersize',12);
plot(that,3*sqrt(Phat2(:,11)),'k-');
plot(that,-3*sqrt(Phat2(:,11)),'k-');
ylabel('agent 2 position estimate error w/ 3\sigma');