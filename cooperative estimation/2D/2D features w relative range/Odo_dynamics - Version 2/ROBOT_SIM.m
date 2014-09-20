% CODE TO SIMULATE ROBOTS MOVING IN AN ENVIRONMENT WITH FEATURES.

clc
clear all
close all

global dt u w nf R Q
global ang dist

%% Constants

tf = 100;
dt = 1;
t  =  0 : dt : tf;
nf = 25; % No. of features
sig_odo = [0.1;0.1;0.0001];
sig_bea = 0.001*ones(nf,1);
R = diag((sig_bea.^2).*ones(nf,1)); % Variance for measurement
Q = diag([sig_odo.^2;0.*ones(2*nf,1)]); % Variance for states

%% Features 

rf = 6*randn(nf,1);
thetaf = randn(nf,1);%0 : 2*pi/nf : 2*pi-2*pi/nf;
Xf = repmat(rf',2,1).*[cos(thetaf)';sin(thetaf)'];

% Visibility
ang   = 120*pi/180;
dist  = 20;

%% Simulate 

Xr(:,1) = [0;0;0];
hf      = headings(Xf,Xr);
Xt(:,1) = [Xr;hf];
P(:,:,1)= diag([0.1*ones(2,1);0.0000001;0.00001*ones(2*nf,1)]);
P0      = P(:,:,1);
Xp0     = [Xt(1:3,1);Xf(:)]+sqrt(diag(P)).*randn(2*nf+3,1); 
Xp(:,1) = [Xp0(1:3); zeros(2*nf,1)];
Xpp(:,1)= [Xp(1:3,1); headings(reshape(Xp(4:end,1),2,nf),Xp(1:3,1))];
hfm     = headings(reshape(Xp(4:end),2,nf),Xp(1:3,1));
Xm(:,1) = [Xp(1:3);hfm];
flagg   = zeros(nf,1);

%%

for i = 1 : length(t)-1

    %% Initialize
    
    flag = Visible(Xf,Xr(:,i));
    New  = (flag==1).*(flagg==0);
    
    %% EKF        
    
    [Xp(:,i), P(:,:,i+1)] = EKF(t,Xp(:,i),Xm(4:end,i),P(:,:,i),flag-New); % Send only those features into EKF which have already been observed
    flagg= flagg + New;
    ii   = find(New==1);
% #1
%     Xp(2*ii+3-1,i) = Xp0(2*ii+3-1,1);
%     Xp(2*ii+3,i)   = Xp0(2*ii+3,1);
%     P(2*ii+3-1,2*ii+3-1,i) = P0(2*ii+3-1,2*ii+3-1);
%     P(2*ii+3,2*ii+3,i)     = P0(2*ii+3,2*ii+3);

% #2
% for j = 1 : length(ii)
%     Xp(2*ii(j)+3-1:2*ii(j)+3,i) = Xp(1:2,i) + Xf(:,ii(j))-Xr(1:2,i)+sqrt(P0(2*ii(j)+3,2*ii(j)+3))*randn(2,1);
%     P(2*ii(j)+3-1,2*ii(j)+3-1,i+1) = P0(2*ii(j)+3-1,2*ii(j)+3-1);
%     P(2*ii(j)+3,2*ii(j)+3,i+1)     = P0(2*ii(j)+3,2*ii(j)+3);
%     J = eye(2*nf+3);
%     J(2*ii(j)+3-1,1) = 1;
%     J(2*ii(j)+3,2)   = 1;
% end
%     P(:,:,i+1) = J'*P(:,:,i+1)*J;

% #3 - Wrong J
for j = 1 : length(ii)
    Xb = Rth(Xr(3,i))'*(Xf(:,ii(j))-Xr(1:2,i));% Feature in body frame
    th = Xp(3,i);
    Xp(2*ii(j)+3-1:2*ii(j)+3,i) = Xp(1:2,i) + Rth(Xp(3,i))*(Xb+sqrt(P0(2*ii(j)+3,2*ii(j)+3))*randn(2,1));
    P(2*ii(j)+3-1,2*ii(j)+3-1,i+1) = P0(2*ii(j)+3-1,2*ii(j)+3-1);
    P(2*ii(j)+3,2*ii(j)+3,i+1)     = P0(2*ii(j)+3,2*ii(j)+3);
    J = eye(2*nf+3);
    J(2*ii(j)+3-1,1) = 1;
    J(2*ii(j)+3,2)   = 1;
    J(2*ii(j)+3-1,3) = -sin(th)*Xb(1)-cos(th)*Xb(2);
    J(2*ii(j)+3-1,2*ii(j)+3-1) = cos(th);
    J(2*ii(j)+3-1,2*ii(j)+3)   = -sin(th);
    J(2*ii(j)+3,3)             = cos(th)*Xb(1)-sin(th)*Xb(2);
    J(2*ii(j)+3,2*ii(j)+3-1)   = sin(th);
    J(2*ii(j)+3,2*ii(j)+3)     = cos(th);    
end

P(:,:,i+1) = J'*P(:,:,i+1)*J;

    %% Propogation
    
    if t(i) < 20
        u = 0.5 + 0.1*rand;
        w = 0.2 + 0.1*rand;
    elseif t(i) < 40 && t(i) > 20 
        u = 0.5 + 0.1*rand;
        w = -0.1 + 0.1*rand;
    elseif t(i) > 40 && t(i) < 60
        u = 0.2 + 0.1*rand;
        w = 0.3 + 0.1*rand;    
    else
        u = 0.4 + 0.1*rand;
        w = 0.2 + 0.1*rand;    
    end
    
    Xr(:,i+1)     = rk4_X(t(i),Xr(:,i)); % vehicle states x,y,alpha
    hf            = headings(Xf,Xr(:,i+1)); % True bearing
    Xt(:,i+1)     = [Xr(:,i+1);hf]; % True vehicle states
    % MEASUREMENTS
    odo_noise     = sig_odo.*randn(3,1); % Noise in X,Y and heading
    bea_noise     = sig_bea.*randn(nf,1); % Noise in bearing measurements
    Xm(1:3,i+1)   = Xm(1:3,i) + Xt(1:3,i+1)-Xt(1:3,i) + odo_noise; % Measured vehicle states
    Xm(4:end,i+1) = hf + bea_noise; % Measured feature bearing in vehicle frame             
    Xm(:,i);    
    Xp(1:3,i+1)   = Xp(1:3,i)+ Xt(1:3,i+1)-Xt(1:3,i) + odo_noise;
    Xp(4:end,i+1) = Xp(4:end,i);
    Xpp(:,i+1)= [Xp(1:3,i+1); headings(reshape(Xp(4:end,i+1),2,nf),Xp(1:3,i+1))];    
    Xpp(:,i);
    iif = find(flagg==1);
    
    figure(2)
    plot(Xt(1,i),Xt(2,i),'.-k',Xf(1,:),Xf(2,:),'xk','LineWidth',2); hold on;
    plot(Xm(1,i),Xm(2,i),'.-r','LineWidth',2); hold on;
    plot(Xp(1,i),Xp(2,i),'.-m',Xp(3+iif*2-1,end),Xp(3+iif*2,end),'xm','LineWidth',2); hold on;
%    pause(0.01)
    
end

figure(2)
 plot(Xp(3+iif*2-1,end),Xp(3+iif*2,end),'xb','LineWidth',2); hold on;

%% Plot

figure(3)
plot(Xt(1,:),Xt(2,:),'.-k',Xm(1,:),Xm(2,:),'.-r',Xp(1,:),Xp(2,:),'.-b',Xf(1,:),Xf(2,:),'xk',Xp(4:2:end,end),Xp(5:2:end,end),'xb','LineWidth',2);

figure(4)
subplot(3,2,1)
plot(t,Xt(1,:)-Xp(1,:),'.-k',t,Xt(1,:)-Xm(1,:),'.-r','LineWidth',2); hold on;legend('Estimation Error','Measured Error'); xlabel('\bf t');ylabel('\bf x');
subplot(3,2,2)
plot(t,Xt(2,:)-Xp(2,:),'.-k',t,Xt(2,:)-Xm(2,:),'.-r','LineWidth',2); hold on;legend('Estimation Error','Measured Error'); xlabel('\bf t');ylabel('\bf y');
subplot(3,2,3)
plot(t,Xt(3,:)-Xp(3,:),'.-k',t,Xt(3,:)-Xm(3,:),'.-r','LineWidth',2); hold on;legend('Estimation Error','Measured Error'); xlabel('\bf t');ylabel('\bf heading');
subplot(3,2,4)
plot(t,Xt(4,:)-Xpp(4,:),'.-k',t,Xt(4,:)-Xm(4,:),'.-r','LineWidth',2); hold on;legend('Estimation Error','Measured Error');  xlabel('\bf t');ylabel('\bf bearings');
subplot(3,2,5)
plot(t,Xf(1,1)-Xp(4,:),'.-k','LineWidth',2); hold on; xlabel('\bf t');ylabel('\bf X of feature 1');
subplot(3,2,6)
plot(t,Xf(2,1)-Xp(5,:),'.-k','LineWidth',2); hold on; xlabel('\bf t');ylabel('\bf Y of feature 1');