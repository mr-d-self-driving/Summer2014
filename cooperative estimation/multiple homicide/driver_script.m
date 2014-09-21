%% driver file for generating truth data histories

clear variables;
close all;

clear ctrl_1;
clear ctrl_2;

% initialize;

y0 = [0;0;0];%rx, ry, psi in inertial

yt0 = [randn(2,1)*10-5;2*pi*rand-pi];
yt0 = [10;0;pi/4];

y20 = [randn(2,1)*10-5;2*pi*rand-pi;1];
y20 = [5 -5 0 0.1]';

% y: [rx ry psi_1 rx ry psi_t rx ry psi_2 v2]

tspan = [0 30];
%% integrate
% sensing FOVs
l1 = pi/4;
l2 = pi/4;

tic;
[T,Y] = integ(tspan,[y0;yt0;y20]);
toc;

%% process
u2ref = zeros(length(T),2);
uref = zeros(length(T),1);
vref = zeros(length(T),2);
r2ref = zeros(length(T),2);
for i = 1:length(T)
    [u2ref(i,:),vref(i,:),r2ref(i,:)] = ctrl_2(T(i),Y(i,:)');
    uref(i,:) = ctrl_1(T(i),Y(i,:)');
    if ~mod(i,10)
        i
    end
end

%
figure;
subplot(311);
plot(T,Y(:,10));
hold on;
plot(T,vref(:,2),'b--');
plot(T,Y(:,9),'r-');
plot(T,vref(:,1),'r--');
ylabel('r2_dot_ref');

subplot(312);
plot(T,Y(:,7));
hold on;
plot(T,r2ref(:,1),'b--');
plot(T,Y(:,8),'r-');
plot(T,r2ref(:,2),'r--');
ylabel('r2 ref');

subplot(313);
% draw agent 2 position
plot(Y(:,8),Y(:,7),'r--');
hold on;
plot(Y(end,8),Y(end,7),'r--d');
% draw agent 2 reference
plot(r2ref(:,2),r2ref(:,1),'r:');
plot(r2ref(end,2),r2ref(end,1),'o:');
% draw agent 2 FOV
f21 = Y(end,9) + l2;
f22 = Y(end,9) - l2;
plot(Y(end,8) + 10*[0 sin(f21)],Y(end,7) + 10*[0 cos(f21)],'r--');
plot(Y(end,8) + 10*[0 sin(f22)],Y(end,7) + 10*[0 cos(f22)],'r--');

% draw agent 1 position
plot(Y(:,2),Y(:,1),'b-');
plot(Y(end,2),Y(end,1),'b-x');
% draw target position
plot(Y(:,5),Y(:,4),'g-');
plot(Y(end,5),Y(end,4),'g-s');

% draw agent 1 FOV
f21 = Y(end,3) + l1;
f22 = Y(end,3) - l1;
plot(Y(end,2) + 10*[0 sin(f21)],Y(end,1) + 10*[0 cos(f21)],'b--');
plot(Y(end,2) + 10*[0 sin(f22)],Y(end,1) + 10*[0 cos(f22)],'b--');

axis equal