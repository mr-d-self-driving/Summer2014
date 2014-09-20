%% plot_both
% call both the independent and dependent cases and plot the errors and
% 3sigma

clear variables;
close all;
driver_dep;
%%
close all;

fid = fopen('both_mses.txt','wt');
fprintf(fid,'Case & Agent & $MSE_X$ & $MSE_Y$ & $MSE_u$ & $MSE_v$ & $MSE_\\psi$\\\\ \n');

for K = 1:N
    figure(K);
    clf;
    xbar = 0.5*(xh{K}(2:2:end,:)+xh{K}(3:2:end,:));
    Pbar = 0.5*(Ph{K}(2:2:end,:)+Ph{K}(3:2:end,:));
    xbar(:,5) = minangle(xbar(:,5),ags(K).truth(:,5));
    fprintf(fid,'Cooperative & %i',K);
    for i = 1:5
        subplot(5,1,i)
        plot(tspan,ags(K).truth(:,i)-xbar(:,i),'b-','linewidth',2);
        hold on;
        plot(tspan,3*sqrt(Pbar(:,5*(i-1)+i)),'r--','linewidth',2);
        plot(tspan,-3*sqrt(Pbar(:,5*(i-1)+i)),'r--','linewidth',2);
        % print MSE
        fprintf(fid,'& %.4g',sum((ags(K).truth(:,i)-xbar(:,i)).^2)/length(tspan));
    end
    fprintf(fid,'\\\\ \n');
end

fclose(fid);
clear variables;
driver_indep;
%%
fid = fopen('both_mses.txt','at+');

for K = 1:N
    
    figure(K);
    xbar = 0.5*(xh{K}(2:2:end,:)+xh{K}(3:2:end,:));
    Pbar = 0.5*(Ph{K}(2:2:end,:)+Ph{K}(3:2:end,:));
    xbar(:,5) = minangle(xbar(:,5),ags(K).truth(:,5));
    fprintf(fid,'Individual & %i',K);
    for i = 1:5
        subplot(5,1,i)
        hold on;
        plot(tspan,ags(K).truth(:,i)-xbar(:,i),'m-','linewidth',2);
        hold on;
        plot(tspan,3*sqrt(Pbar(:,5*(i-1)+i)),'k--','linewidth',2);
        plot(tspan,-3*sqrt(Pbar(:,5*(i-1)+i)),'k--','linewidth',2);
        title(['Agent ' num2str(K) ' errors']);
        switch i
            case 1
                ylabel('X (m)');
                set(gca,'ylim',[-4 4]);
            case 2
                ylabel('Y (m)');
                set(gca,'ylim',[-4 4]);
            case 3
                ylabel('u (m/s)');
                set(gca,'ylim',[-7.5 7.5]);
            case 4
                ylabel('v (m/s)');
                set(gca,'ylim',[-7.5 7.5]);
            case 5
                ylabel('\psi (rad)');
                set(gca,'ylim',[-.3 .3]);
        end
        set(gca,'xlim',[0 15]);
        % print MSE
        fprintf(fid,'& %.4g',sum((ags(K).truth(:,i)-xbar(:,i)).^2)/length(tspan));
    end
    fprintf(fid,'\\\\ \n');
    
    legend('cooperative','coop 3\sigma','coop -3\sigma','solo','solo 3\sigma','solo -3\sigma');
    set(gcf,'position',[75 100 1775 900]);
end

fclose(fid);