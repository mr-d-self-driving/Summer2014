%% animate for unknown features case
% specialized for 2 agents only

if known_features == 0
    % for each agent, plot the true and expected feature locations at each
    % time
    for j = 1:N
        psicmp = ags(j).truth(:,5) - ags(j).truth(1,5);
        % true inertial frame to agent inertial frame DCM
        Ctr_n = [cos(ags(j).truth(1,5)) sin(ags(j).truth(1,5));-sin(ags(j).truth(1,5)) cos(ags(j).truth(1,5))];
        rbcmp = ags(j).truth(:,1:2)*Ctr_n';
        rbcmp = rbcmp - repmat(rbcmp(1,:),length(tspan),1);
        
        % mean estimate, used for computing errors
        xkbar = 0.5*(xk(j).xk(1:2:end-1,:)+xk(j).xk(2:2:end,:));
        xkbar(:,5) = minangle(xkbar(:,5),psicmp);
        % covariance diagonal terms
        Pdiag = 1:(5+4*M*N+1):(5+4*M*N)^2;
        
        feature_x = xk(j).xk(:,6:4:end);
        feature_y = xk(j).xk(:,7:4:end);
        invrho = xk(j).xk(:,8:4:end);
        theta = xk(j).xk(:,9:4:end);
        
        feature_xxyy = ([feature_x feature_y] + repmat(1./invrho,1,2).*[cos(theta) sin(theta)]);
        % rel_r is organized as [x1 x2 x3 ... y1 y2 y3]
        rel_r = feature_xxyy-[repmat(xk(j).xk(:,1),1,M*N) repmat(xk(j).xk(:,2),1,M*N)];
        % rel_truth is organized as [x1 y1 x2 y2... xn yn]
        rel_truth = repmat( reshape(marksv',1,[]), length(tspan),N) - repmat( ags(j).truth(:,1:2) ,1,M*N);
        
        rho_est = sqrt(rel_r(:,1:M*N).^2 + rel_r(:,M*N+(1:M*N)).^2);
        % relative heading to features
        theta_est = pi2pi(atan2(rel_r(:,M*N+(1:M*N)),rel_r(:,1:M*N)) - repmat(xk(j).xk(:,5),1,M*N));
        [~,ix] = sort(xk(j).fl);
        rho_est = rho_est(:,ix);
        theta_est = pi2pi(theta_est(:,ix));
        
        rho_true = repmat( sqrt(rel_truth(:,1:2:end-1).^2 + rel_truth(:,2:2:end).^2) ,1,N);
        theta_true = atan2(rel_truth(:,2:2:end),rel_truth(:,1:2:end-1)) - repmat(ags(j).truth(:,5),1,M*N);
        %rho_true = repmat(ags(j).rb(:,1:M),1,N);
        %theta_true = repmat(pi2pi(ags(j).rb(:,M+1:2*M)),1,N);
        
        xlm = max(max(ags(j).rb(:,1:M)));
        
        figure;
        for k = 1:length(tspan)
            hold off;
            % plot true feature locations
            plot(rho_true(k,1:M).*sin(theta_true(k,1:M)),rho_true(k,1:M).*cos(theta_true(k,1:M)),'kd','linewidth',2);
            hold on;
            % plot self and own FOV
            plot(0,0,'bs','linewidth',2);
            plot(sind(FOV(j))*[RANGEMIN(j) RANGE(j)],cosd(FOV(j))*[RANGEMIN(j) RANGE(j)],'b--','linewidth',2);
            plot(sind(-FOV(j))*[RANGEMIN(j) RANGE(j)],cosd(-FOV(j))*[RANGEMIN(j) RANGE(j)],'b--','linewidth',2);
            %plot own feature estimates
            switch j
                case 1
                    plot(rho_est(2*k-1,M+(1:M)).*sin(theta_est(2*k-1,M+(1:M))),rho_est(2*k-1,M+(1:M)).*cos(theta_est(2*k-1,M+(1:M))),'rs','linewidth',2);
                    plot(rho_est(2*k-1,1:M).*sin(theta_est(2*k-1,1:M)),rho_est(2*k-1,1:M).*cos(theta_est(2*k-1,1:M)),'bx','linewidth',2);
                    j2 = 2;
                case 2
                    plot(rho_est(2*k-1,1:M).*sin(theta_est(2*k-1,1:M)),rho_est(2*k-1,1:M).*cos(theta_est(2*k-1,1:M)),'rs','linewidth',2);
                    plot(rho_est(2*k-1,M+(1:M)).*sin(theta_est(2*k-1,M+(1:M))),rho_est(2*k-1,M+(1:M)).*cos(theta_est(2*k-1,M+(1:M))),'bx','linewidth',2);
                    j2 = 1;
            end
            % plot other agent & FoV
            plot(ags(j).rb_agent(k,1)*sin(ags(j).rb_agent(k,1)),ags(j).rb_agent(k,1)*cos(ags(j).rb_agent(k,1)),'rs','linewidth',2);
            delta = ags(j).rb_agent(k,2) + pi - ags(j2).rb_agent(k,2);
            plot(ags(j).rb_agent(k,1)*sin(ags(j).rb_agent(k,1)) + sin(delta + d2r*FOV(j2))*[RANGEMIN(j2) RANGE(j2)],...
                ags(j).rb_agent(k,1)*cos(ags(j).rb_agent(k,1)) + cos(delta + d2r*FOV(j2))*[RANGEMIN(j2) RANGE(j2)],'r--');
            plot(ags(j).rb_agent(k,1)*sin(ags(j).rb_agent(k,1)) + sin(delta - d2r*FOV(j2))*[RANGEMIN(j2) RANGE(j2)],...
                ags(j).rb_agent(k,1)*cos(ags(j).rb_agent(k,1)) + cos(delta - d2r*FOV(j2))*[RANGEMIN(j2) RANGE(j2)],'r--');
            plot(ags(j).rb_agent(k,1)*sin(ags(j).rb_agent(k,1)) + 2.5*[0 sin(delta + d2r*FOV(j2))],...
                ags(j).rb_agent(k,1)*cos(ags(j).rb_agent(k,1)) + 2.5*[0 cos(delta + d2r*FOV(j2))],'r-');
            
            set(gca,'xlim',[-xlm xlm]);
            set(gca,'ylim',[-xlm xlm]);
            title(['t = ' num2str(tspan(k))]);
            pause(.01);
        end
    end
end