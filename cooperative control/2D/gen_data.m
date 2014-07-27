%% gen_data.m
clear variables;
close all;

% # of agents
N = 2;
% # of landmarks
M = 25;

% covariances
Rimu = diag([.1 .1 .1].^2);%a1 a2 omega
Rrange(1:N) = [1 1].^2;%range to landmarks
Rbear(1:N) = [(10*d2r) (10*d2r)].^2;%bearing to landmarks
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

Tf = 10;
Ts = .1;

ags(N) = struct('truth',[],'IMU',[],'rb',[],'rb_agent',[]);
marks(M) = struct('xy',[]);
for i = 1:M
    range = rand(1)*40;
    bear = rand(1)*2*pi-pi;
    marks(i).xy = range*[cos(bear) sin(bear)];
end

%tspan = linspace(0,Tf,1001);
tspan = 0:Ts:Tf;

% simulate system
for i = 1:N
    y0 = [5*randn(2,1);rand(1)*2*pi-pi];
    if i == 1
        [T,Y,V,W,A] = agent_sim_circular(tspan,y0);
    else
        if i == 2
            %y0 = [0;0;0];
            [T,Y,V,W,A] = agent_sim_circular(tspan,y0);
        end
    end
    %true state histories - X Y vx vy omega
    Y = [Y(:,1:2) V Y(:,3) A W];
    ags(i).truth = Y;
    % IMU
    ags(i).IMU = [A W] + randn(length(T),3).*repmat(sqrt(diag(Rimu)'),length(T),1);
    % range and bearing measurements
    psi = ags(i).truth(:,5);
    ags(i).rb = zeros(length(T),2*M);
    for j = 1:M
        delta = repmat(marks(j).xy,length(T),1) - ags(i).truth(:,1:2);
        %ags(i).rb(:,M+j) = atan2(sqrt(sum((delta(:,1).*sin(psi)-delta(:,2).*cos(psi)).^2,2)),( delta(:,1).*cos(psi) + delta(:,2).*sin(psi) ) ) + randn(length(T),1)*sqrt(Rbear);%bearing
        ags(i).rb(:,M+j) = atan2(delta(:,2),delta(:,1)) - psi + randn(length(T),1)*sqrt(Rbear(i));%bearing
        while any(abs(ags(i).rb(:,M+j)) > pi)
            ags(i).rb(ags(i).rb(:,M+j) > pi,M+j) = ags(i).rb(ags(i).rb(:,M+j) > pi,M+j) - 2*pi;
            ags(i).rb(ags(i).rb(:,M+j) < -pi,M+j) = ags(i).rb(ags(i).rb(:,M+j) < -pi,M+j) + 2*pi;
        end
        ags(i).rb(:,j) = sqrt(sum((repmat(marks(j).xy,length(T),1) - Y(:,1:2)).^2,2)) + randn(length(T),1)*sqrt(Rrange(i));%range
    end
end

for i = 1:N
    %generate measurements to other agents
    ags(i).rb_agent = zeros(length(tspan),2*(N-1));
    c = 0;
    psi = ags(i).truth(:,5);
    for j = [1:i-1 i+1:N]
        c = c + 1;
        ags(i).rb_agent(:,c) = sqrt(sum((ags(i).truth(:,1:2) - ags(j).truth(:,1:2)).^2,2)) + randn(length(T),1)*sqrt(Rrange_ag);%range
        delta = ags(j).truth(:,1:2) - ags(i).truth(:,1:2);
        ags(i).rb_agent(:,2*c) = atan2(delta(:,2),delta(:,1)) - psi + randn(length(T),1)*sqrt(Rbear_ag);%bearing
        ags(i).rb_agent( ags(i).rb_agent(:,2*c)>pi ,2*c) = ags(i).rb_agent( ags(i).rb_agent(:,2*c)>pi ,2*c) - 2*pi;
        %ags(i).rb(:,M+j) = atan2(sqrt(sum((delta(:,1).*sin(psi)-delta(:,2).*cos(psi)).^2,2)),( delta(:,1).*cos(psi) + delta(:,2).*sin(psi) ) ) + randn(length(T),1)*sqrt(Rbear);%bearing
    end
end

save data.mat;

%% animate for verification

disp('done generating');

figure;
for i = 1:length(tspan)
    tic;
    hold off;
    for j = 1:M
        plot(marks(j).xy(2),marks(j).xy(1),'kx');
        text(marks(j).xy(2),marks(j).xy(1),num2str(j));
        hold on;
    end
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
    
    pause(Tf/length(tspan)-toc);
end