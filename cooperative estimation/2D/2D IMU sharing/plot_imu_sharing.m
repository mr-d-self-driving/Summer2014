%% plot_imu_sharing
for i = 1:N
    figure;
    if i == 1
        i2 = 2;
    else
        i2 = 1;
    end
    % inertial frame coordinates of estimated positions
    for j = 1:2
        subplot(2,1,j);
        plot(tspan,ags(i).rb_agent(:,j));
        delta = ags(i2).truth(:,1:2) - ags(i).truth(:,1:2);
        hold on;
        switch j
            case 1
                plot(tk,sqrt(sum(xk(i).xk(:,6:7).^2,2)),'r--');
                plot(tspan,sqrt(sum(delta.^2,2)),'k-');
                ylabel('\rho');
            case 2
                plot(tk,atan2(xk(i).xk(:,7),xk(i).xk(:,6)),'r--');
                plot(tspan,atan2(delta(:,2),delta(:,1)) - ags(i).truth(:,5),'k-');
                ylabel('\theta');
        end
    end
    figure;
    for j = 1:3
        subplot(3,1,j);
        if j < 3
            plot(tk,xk(i).xk(:,j+2),'r--');
            hold on;
            plot(tspan,ags(i).truth(:,j+2));
        else
            plot(tk,xk(i).xk(:,10),'r--');
            hold on;
            plot(tspan,pi2pi(ags(i2).truth(:,5)-ags(i).truth(:,5)));
        end
    end
end