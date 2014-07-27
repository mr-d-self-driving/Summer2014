%% driver_simple_sharing
clear variables;
addpath('..');
%close all;
load data.mat;

DEBUG = 0;%set to 1 to use numerical gradients of update and measurements

Rrange = [100 100];
Rbear = [.01 .01];
Rrange_ag = 100;
Rbear_ag = .1;
Rimu = diag([.5^2 .5^2 .1^2]);

% generate new measurements
TRUTH = 0; % set to 1 to use truth data in gen_new_noise
gen_new_noise;
%bitmask for which terms have bias
% 7 bit number
biasmask = '0000000';%from right to left -> a1 a2 omega range_landmark bearing_landmark range_agent bearing_agent
load_data_bitmask;%runs script that adds bias with random walk

%% open-loop test EKFs
% estimating position, velocity, and ang velocity with KNOWN landmarks and
% range and bearing measurements to everything
% not measuring to other agents

Rrelative = diag([Rrange_ag Rbear_ag]);

Ts = mean(diff(tspan));

th = [sort(repmat(tspan,1,2)) tspan(end)+Ts];
xh = cell(N,1);
Ph = cell(N,1);
% ye: holds the expected and actual measurements and the calculated
% measurement covariance, which includes the relative sensing uncertainty
ye(N) = struct('exp',zeros(length(tspan),4*M),'tilde',zeros(length(tspan),4*M),'Rexp',zeros(length(tspan),16*M*M));

for K = 1:2
    %initialize estimates
    %x0hat = zeros(5,1);
    xh{K} = zeros(2*length(tspan),5);
    Ph{K} = zeros(2*length(tspan),25);
    
    %xh{K}(1,:) = ags(K).truth(1,1:5)';
    xh{K}(1,:)= ags(K).truth(1,1:5)' + randn(5,1).*[1;1;.1;.1;.15];
    Ph{K}(1,:) = reshape( 10*eye(5)+.1*ones(5), 1, 25);
end

Q = Rimu + Ts^2*eye(3);%IMU terms only

for I = 1:length(tspan)
    for K = 1:N
        %% update
        %current agent state estimate
        x0hat = xh{K}(2*I-1,:);
        %current agent covariance estimate
        P0hat = reshape(Ph{K}(2*I-1,:),5,5);
        %indexing variable
        if K == 1
            K2 = 2;
        else
            K2 = 1;
        end
        % covariance of: range,bearing x M (this agent), range,bearing x M (other agent)
        Rk = diag( [repmat([Rrange(K) Rbear(K)],1,M) repmat([Rrange(K2) Rbear(K2)],1,M)] );
        
        %measurement of landmarks 1:M by self, then by other agent
        ytilde = [ags(K).rb(I, sort(repmat(1:M,1,2)) + repmat([0 M],1,M) )';
            ags(K2).rb(I, sort(repmat(1:M,1,2)) + repmat([0 M],1,M) )'];
        
        % call the update function
        z_avail = [ags(K).rb_agent(I,:) xh{K2}(2*I-1,5) x0hat];
        [x0hat,P0hat,ye(K).exp(I,:),Rexp] = update_eq(ytilde,z_avail,P0hat,marks,Rk,Rrelative,Ph{K2}(2*I-1,end),DEBUG);
        ye(K).Rexp(I,:) = reshape(Rexp,[],1)';
        ye(K).tilde(I,:) = ytilde';
        
        %store variables
        xh{K}(2*I,:) = x0hat';
        Ph{K}(2*I,:) = reshape(P0hat,25,1)';
    end
    for K = 1:N
    %% propagate
        x0hat = xh{K}(2*I,:)';
        P0hat = reshape(Ph{K}(2*I,:)',5,5);
        
        % DCM from body to inertial
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
        
        x0hatp = f + B*ueff;
        
        if DEBUG
            Fe = zeros(5);
            for J = 1:5
                xe = x0hat;
                xe(J) = xe(J) + 1e-5;
                % DCM from body to inertial
                Cp = [cos(xe(5)) -sin(xe(5));sin(xe(5)) cos(xe(5))];
                % derivative of x is nonlinear in x
                fe = [xe(1:2) + Cp*Ts*xe(3:4);
                    xe(3:4);
                    xe(5)];
                Be = zeros(5,3);
                Be(3,:) = [Ts 0 xe(4)*Ts];
                Be(4,:) = [0 Ts -xe(3)*Ts];
                Be(5,3) = Ts;
                xp = fe + Be*ueff;
                Fe(:,J) = (xp-x0hatp)/1e-5;
            end
            if max(max(abs(Fe-Fk))) > 1e-3
                disp('Warning: numerical propagation function gradient differs from analytical!');
            end
            Fk = Fe;
        end
        
        x0hat = x0hatp;
        
        P0hat = Fk*P0hat*Fk' + G*Q*G';
        
        xh{K}(2*I+1,:) = x0hat';
        Ph{K}(2*I+1,:) = reshape(P0hat,25,1)';
    end
    if ~mod(I-1,100)
        disp(I);
    end
end
%% figures
for K = 1:N
    if K == 1
        K2 = 2;
    else
        K2 = 1;
    end
    Rk = diag( [repmat([Rrange(K) Rbear(K)],1,M) repmat([Rrange(K2) Rbear(K2)],1,M)] );
    
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
   
    %plot measured and expected measurements
    %figure;
    %for i = 1:4*M
    %    subplot(4,3,i);
    %    plot(tspan,ye(K).exp(:,i),'r--');
    %    hold on;
    %    plot(tspan,ye(K).tilde(:,i),'b-');      
    %end
    
    % plot covariance history
    figure;
    %plot(th,Ph{K}(:,[1:5 7:10 13:15 19:20 25]));%unique elements only
    ii = [1 14 27 40 53 66 79 92 105 118 131 144];
    for i = 1:4*M
        %plot(th,Ph{K}(:,ii(i)));
        subplot(4,3,i);
        plot(tspan,ye(K).tilde(:,i) - ye(K).exp(:,i));
        hold on;
        plot(tspan,3*sqrt(Rk(i,i) + ye(K).Rexp(:,ii(i))),'r--');
        plot(tspan,-3*sqrt(Rk(i,i) + ye(K).Rexp(:,ii(i))),'r--');
        title('Measurement error');
        switch i
            case {1,3,5}
                ylabel('\delta\rho_k_i');
            case {2,4,6}
                ylabel('\delta\theta_k_i');
            case {7,9,11}
                ylabel('\delta\rho_k_j');
            case {8,10,12}
                ylabel('\delta\theta_k_j');
        end
    end
end

% plot interagent range-bearing truth and estimate
    figure;
    subplot(311);
    plot(tspan,sqrt(sum((ags(1).truth(:,1:2)-ags(2).truth(:,1:2)).^2,2)),'b-');
    hold on;
    plot(th,sqrt(sum((xh{2}(:,1:2)-xh{1}(:,1:2)).^2,2)),'r--');
    plot(tspan,ags(1).rb_agent(:,1),'k:');
    plot(tspan,ags(2).rb_agent(:,1),'m--');
    legend('truth','estimate diff','measure1','measure2');
    ylabel('\rho_j_i (m)');
    
    subplot(312);
    plot(tspan,r2d*(atan2(ags(2).truth(:,2)-ags(1).truth(:,2),...
        ags(2).truth(:,1)-ags(1).truth(:,1)) - ags(1).truth(:,5)),'b-');
    hold on;
    plot(th,r2d*(atan2(xh{2}(:,2)-xh{1}(:,2),...
        xh{2}(:,1)-xh{1}(:,1)) - xh{1}(:,5)),'r--');
    plot(tspan,r2d*ags(1).rb_agent(:,2),'k:');
    legend('truth','estimate diff','measure1');
    ylabel('\theta_2_1 (deg)');
    
    subplot(313);
    plot(tspan,r2d*(atan2(ags(1).truth(:,2)-ags(2).truth(:,2),...
        ags(1).truth(:,1)-ags(2).truth(:,1)) - ags(2).truth(:,5)),'b-');
    hold on;
    plot(th,r2d*(atan2(xh{1}(:,2)-xh{2}(:,2),...
        xh{1}(:,1)-xh{2}(:,1)) - xh{2}(:,5)),'r--');
    plot(tspan,r2d*ags(2).rb_agent(:,2),'k:');
    legend('truth','estimate diff','measure1');
    ylabel('\theta_1_2 (deg)');
%% animate for verification

%function animate(j,ags,marks,xh,ye,Rrange,Rbear,tspan);

% loop over agents
for j = 1:N
    animate(j,ags,marks,xh,ye,Rrange,Rbear,tspan);
end