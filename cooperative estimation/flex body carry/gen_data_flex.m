%% gen_data.m
clear variables;
close all;

addpath('../2D');
addpath('../2D/2D IMU sharing/');

% # of agents
N = 2;
% # of landmarks
M = 25;

% covariances
Rimu = diag([.1 .1 .1].^2);%a1 a2 omega
Rrange(1:N) = 1.^2;%range to landmarks
Rbear(1:N) = (10*d2r).^2;%bearing to landmarks
Rrange_ag = 1^2;%range to other agent
Rbear_ag = (10*d2r)^2;%bearing to other agent

% biases: these are only used later, after the data are saved
% format: [max bias initialization, stdev of random walk;]
biasIMU = repmat([.05 1e-4],3,1);
biasrb = [2.5 1e-5;
    5*d2r 1e-4];
biasrb_ag = [2.5 1e-5;
    5*d2r 1e-4];

biasv = [biasIMU;biasrb;biasrb_ag];
Rall = diag( [diag(Rimu)' Rrange Rbear Rrange_ag Rbear_ag] );

Tf = 10.0;
Ts = .01;

ags(N) = struct('truth',[],'IMU',[],'rb',[],'rb_agent',[]);

% landmark positions
marks(M) = struct('xy',[]);
for i = 1:M
    range = rand(1)*20;
    bear = rand(1)*2*pi-pi;
    marks(i).xy = range*[cos(bear) sin(bear)];
end

tspan = 0:Ts:Tf;

% simulate system
y0 = zeros(6,1);
y0(1:3) = [5*randn(2,1);rand(1)*2*pi-pi];
y0(4:5) = y0(1:2) + rand(2,1)*0.64+0.36;
y0(6) = rand(1)*2*pi-pi;
[T,Y,V,W,A] = agent_sim_follower(tspan,y0);

for i = 1:2
    %true state histories - X Y vx vy omega
    Z = [Y(:,(1:2)+(i-1)*3) V(:,(1:2)+(i-1)*2) Y(:,3+(i-1)*3) A(:,(1:2)+(i-1)*2) W(:,i)];
    ags(i).truth = Z;
    % IMU
    ags(i).IMU = [A(:,(1:2)+(i-1)*2) W(:,i)] + randn(length(T),3).*repmat(sqrt(diag(Rimu)'),length(T),1);
    % range and bearing measurements
    psi = ags(i).truth(:,5);
    ags(i).rb = zeros(length(T),2*M);
    for j = 1:M
        delta = repmat(marks(j).xy,length(T),1) - ags(i).truth(:,1:2);
        ags(i).rb(:,M+j) = atan2(delta(:,2),delta(:,1)) - psi + randn(length(T),1)*sqrt(Rbear(i));%bearing
        ags(i).rb(:,M+j) = pi2pi(ags(i).rb(:,M+j));
        ags(i).rb(:,j) = sqrt(sum((repmat(marks(j).xy,length(T),1) - Z(:,1:2)).^2,2)) + randn(length(T),1)*sqrt(Rrange(i));%range
    end
end

for i = 1:N
    %generate measurements to other agents
    ags(i).rb_agent = zeros(length(tspan),2*(N-1));
    c = 0;
    psi = ags(i).truth(:,5);
    for j = [1:i-1 i+1:N]
        c = c + 1;
        ags(i).rb_agent(:,2*c-1) = sqrt(sum((ags(i).truth(:,1:2) - ags(j).truth(:,1:2)).^2,2)) + randn(length(T),1)*sqrt(Rrange_ag);%range
        delta = ags(j).truth(:,1:2) - ags(i).truth(:,1:2);
        ags(i).rb_agent(:,2*c) = atan2(delta(:,2),delta(:,1)) - psi + randn(length(T),1)*sqrt(Rbear_ag);%bearing
        ags(i).rb_agent(:,2*c) = pi2pi(ags(i).rb_agent(:,2*c));
    end
end

save data.mat;

%% animate for verification

disp('done generating');

marksv = zeros(M,2);
for j = 1:M
    marksv(j,:) = marks(j).xy;
end

figure;
i = length(tspan);
    tic;
    hold off;
    plot(marksv(:,2),marksv(:,1),'kx');
    hold on;
    %for j = 1:M
    %text(marks(j).xy(2),marks(j).xy(1),num2str(j));
    %end
    for j = 1:N
        if j == 1
            plot(ags(j).truth(1:i,2),ags(j).truth(1:i,1),'-');
        else
            plot(ags(j).truth(1:i,2),ags(j).truth(1:i,1),'r-');
        end
        %plot heading
        plot(ags(j).truth(i,2)+ [0 sin(ags(j).truth(i,5))],ags(j).truth(i,1)+ [0 cos(ags(j).truth(i,5))],'r--');
    end
    axis equal;
    title(['t = ' num2str(tspan(i))]);
    set(gca,'NextPlot','replacechildren');
    
    %pause(Tf/length(tspan)-toc);