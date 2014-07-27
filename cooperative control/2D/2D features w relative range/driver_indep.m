%% driver_simple_noshare
clear variables;
%close all;
load data.mat;

Rrange = [100 100];
Rbear = [.01 .01];
Rrange_ag = 100;
Rbear_ag = .1;
Rimu = diag([.5^2 .5^2 .1^2]);

%generate new measurements
TRUTH = 0;
gen_new_noise;
%bitmask for which terms have bias
% 7 bit number
biasmask = '0000000';%from right to left -> a1 a2 omega range_landmark bearing_landmark range_agent bearing_agent
load_data_bitmask;%runs script that adds bias with random walk

%% open-loop test EKFs
% estimating position, velocity, and ang velocity with KNOWN landmarks and
% range and bearing measurements to everything
% not measuring to other agents

Ts = mean(diff(tspan));

th = [sort(repmat(tspan,1,2)) tspan(end)+Ts];
xh = cell(N,1);
Ph = cell(N,1);
ye(N) = struct('exp',zeros(length(tspan),2*M),'tilde',zeros(length(tspan),2*M));

for K = 1:N
    %initialize estimate
    %x0hat = zeros(5,1);
    %x0hat = ags(K).truth(1,1:5)';
    x0hat = ags(K).truth(1,1:5)' + randn(5,1).*[1;1;.1;.1;.15];
    P0hat = 10*eye(5) + .1*ones(5);
        
    xh{K} = zeros(2*length(tspan),5);
    Ph{K} = zeros(2*length(tspan),25);
    
    Q = Rimu + Ts^2*eye(3);%IMU terms only
    
    %covariance
    Rk = diag( repmat([Rrange(K); Rbear(K)],3,1) );
    
    xh{K}(1,:) = x0hat';
    Ph{K}(1,:) = reshape(P0hat,25,1)';
    
    for I = 1:length(tspan)
        %measurement
        ytilde = ags(K).rb(I, sort(repmat(1:M,1,2)) + repmat([0 M],1,M) )';
        %compute measurement gradient
        % and expected measurement
        yexp = zeros(2*M,1);
        Hk = zeros(2*M,5);
        % each measurement
        for i = 1:M
            
            delta = (marks(i).xy'-x0hat(1:2));
            rangenorm = sqrt(sum(delta.^2));
            Hk(2*i-1,:) = -[delta'./rangenorm 0 0 0];%range meas. gradient
            Hk(2*i,:) = [delta'*[0 -1;1 0]./rangenorm^2 0 0 -1];%bearing meas. gradient
            yexp(2*i-1) = rangenorm;%range
            
            yexp(2*i) = atan2(delta(2),delta(1)) - x0hat(5);%bearing
            while ( abs(yexp(2*i)-2*pi-ytilde(2*i)) < abs(yexp(2*i)-ytilde(2*i)) || ...
                    abs(yexp(2*i)+2*pi-ytilde(2*i)) < abs(yexp(2*i)-ytilde(2*i)) )
                if abs(yexp(2*i)-2*pi-ytilde(2*i)) < abs(yexp(2*i)-ytilde(2*i))
                    yexp(2*i) = yexp(2*i) - 2*pi;
                else
                    yexp(2*i) = yexp(2*i) + 2*pi;
                end
            end
        end
        ye(K).exp(I,:) = yexp;
        ye(K).tilde(I,:) = ytilde';
        %gain
        Kk = P0hat*Hk'*((Hk*P0hat*Hk' + Rk)\eye(2*M));
        %% update
        x0hat = x0hat + Kk*(ytilde-yexp);
        P0hat = (eye(5) - Kk*Hk)*P0hat;
        
        while x0hat(5) > pi || x0hat(5) < -pi
            if x0hat(5) > pi
                x0hat(5) = x0hat(5) - 2*pi;
            else
                x0hat(5) = x0hat(5) + 2*pi;
            end
        end
        
        xh{K}(2*I,:) = x0hat';
        Ph{K}(2*I,:) = reshape(P0hat,25,1)';
        %% propagate
        Cp = [cos(x0hat(5)) -sin(x0hat(5));sin(x0hat(5)) cos(x0hat(5))];
        % derivative of x is nonlinear in x
        f = [x0hat(1:2) + Cp*Ts*x0hat(3:4);
            x0hat(3:4);
            x0hat(5)];
        % derivative of x is linear in "u": i.e. B*u
        B = zeros(5,3);
        B(3,:) = [Ts 0 x0hat(4)*Ts];
        B(4,:) = [0 Ts -x0hat(3)*Ts];
        B(5,3) = Ts;
        G = - B;
        ueff = ags(K).IMU(I,:)';
        % gradient of f w.r.t. state:
        Fk = eye(5);
        Fk(1:2,3:4) = Cp*Ts;
        Fk(1:2,5) = [-sin(x0hat(5)) -cos(x0hat(5));cos(x0hat(5)) -sin(x0hat(5))]*x0hat(3:4)*Ts;
        Fk(3:4,3:4) = eye(2) + Ts*ueff(3)*[0 1;-1 0];
                
        x0hat = f + B*ueff;
        P0hat = Fk*P0hat*Fk' + G*Q*G';
        
        xh{K}(2*I+1,:) = x0hat';
        Ph{K}(2*I+1,:) = reshape(P0hat,25,1)';
    end
    
    figure;
    for i = 1:5
        title(['Agent ' num2str(K) ' histories & estimates']);
        subplot(5,1,i)
        plot(th,xh{K}(:,i),'-x');
        hold on
        plot(tspan,ags(K).truth(:,i),'r--','linewidth',2);
    end
    
    figure;
    xbar = 0.5*(xh{K}(2:2:end,:)+xh{K}(3:2:end,:));
    Pbar = 0.5*(Ph{K}(2:2:end,:)+Ph{K}(3:2:end,:));
    xbar(:,5) = minangle(xbar(:,5),ags(K).truth(:,5));
    for i = 1:5
        title(['Agent ' num2str(K) ' errors']);
        subplot(5,1,i)
        plot(tspan,ags(K).truth(:,i)-xbar(:,i),'b-','linewidth',2);
        hold on;
        plot(tspan,3*sqrt(Pbar(:,5*(i-1)+i)),'r--','linewidth',2);
        plot(tspan,-3*sqrt(Pbar(:,5*(i-1)+i)),'r--','linewidth',2);
        switch i
            case 1
                ylabel('X (m)');
            case 2
                ylabel('Y (m)');
            case 3
                ylabel('u (m/s)');
            case 4
                ylabel('v (m/s)');
            case 5
                ylabel('\psi (rad)');
        end
    end
    
    % plot measurement error history & covariance
    figure;
    ii = [1 14 27 40 53 66 79 92 105 118 131 144];
    for i = 1:2*M
        %plot(th,Ph{K}(:,ii(i)));
        subplot(3,2,i);
        plot(tspan,ye(K).tilde(:,i) - ye(K).exp(:,i));
        hold on;
        plot(tspan,3*sqrt(Rk(i,i)),'r--');
        plot(tspan,-3*sqrt(Rk(i,i)),'r--');
        title('Measurement error');
        switch i
            case {1,3,5}
                ylabel(['\delta\rho_k_' num2str(K)]);
            case {2,4,6}
                ylabel(['\delta\theta_k_ ' num2str(K)]);
        end
    end
end

%% animate for verification

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
            hold on;
            plot(xh{j}(1:2*i,2),xh{j}(1:2*i,1),'--');
        else
            plot(ags(j).truth(1:i,2),ags(j).truth(1:i,1),'r-');
            hold on;
            plot(xh{j}(1:2*i,2),xh{j}(1:2*i,1),'r--');
        end
        %plot heading
        plot(ags(j).truth(i,2)+ [0 sin(ags(j).truth(i,5))],ags(j).truth(i,1)+ [0 cos(ags(j).truth(i,5))],'r--');
        plot(xh{j}(2*i,2)+ [0 sin(xh{j}(2*i,5))],xh{j}(2*i,1)+ [0 cos(xh{j}(2*i,5))],'r:');
    end
    axis equal;
    title(['t = ' num2str(tspan(i))]);
    set(gca,'NextPlot','replacechildren');
    
    pause(0.0333-toc);
end