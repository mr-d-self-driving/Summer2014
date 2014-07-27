function animate(j,ags,marks,xh,ye,Rrange,Rbear,tspan)
figure;

M = length(marks);

% find x and y limits for plotting
xm = [min(xh{j}(:,2)) max(xh{j}(:,2))] + [-1 1]*sqrt(Rrange(j))*3;
ym = [min(xh{j}(:,1)) max(xh{j}(:,1))] + [-1 1]*sqrt(Rrange(j))*3;
for k = 1:M
    if xm(1) > marks(k).xy(1)
        xm(1) = marks(k).xy(1);
    else if xm(2) < marks(k).xy(1);
            xm(2) = marks(k).xy(1);
        end
    end
    if ym(1) > marks(k).xy(2)
        ym(1) = marks(k).xy(2);
    else if ym(2) < marks(k).xy(2);
            ym(2) = marks(k).xy(2);
        end
    end
end
% define the indexing variable j2 again
if j == 1
    j2 = 2;
else
    j2 = 1;
end
% get the static covariance component for plotting
Rk = diag( [repmat([Rrange(j) Rbear(j)],1,M) repmat([Rrange(j2) Rbear(j2)],1,M)] );
for i = 1:length(tspan)
    tic;
    hold off;
    % plot true landmarks
    for k = 1:M
        plot(marks(k).xy(2),marks(k).xy(1),'kx');
        text(marks(k).xy(2),marks(k).xy(1),[num2str(k)]);
        hold on;
    end
    % plot truth trajectory & estimated trajectory
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
    hold on;
    % current covariance of measurements
    sigmap = diag(reshape(ye(j).Rexp(i,:),4*M,4*M))' + diag(Rk)';
    %plot own measurement of landmark and 3sigma
    for k = 1:M
        markp = xh{j}(2*i,1:2)' + ags(j).rb(i,k)*[cos(ags(j).rb(i,M+k)+xh{j}(2*i,5));sin(ags(j).rb(i,M+k)+xh{j}(2*i,5))];
        %plot own measurement of landmark
        plot(markp(2),markp(1),'bo');
        hold on;
        % plot 3sigma of own measurements
        sigrho = sqrt(sigmap(2*k-1));
        sigthet = sqrt(sigmap(2*k));
        a = 3*sigrho;
        b = 3*sigthet*ags(j).rb(i,k);
        x = linspace(-a,a,100);
        y1 = sqrt((1-x.^2/a^2)*b^2);
        y2 = -y1;
        %rotate ellipse by theta + psi
        phikk = ags(j).rb(i,M+k)+xh{j}(2*i,5);
        C = [cos(phikk) sin(phikk);-sin(phikk) cos(phikk)];
        xtyt = C'*[x x(end:-1:1);y1 y2(end:-1:1)] + repmat(markp,1,200);
        plot(xtyt(2,:),xtyt(1,:),'b--')
    end
    
    % plot other's measurement of landmark
    for k = 1:M
        markp = xh{j}(2*i,1:2)' + ags(j).rb_agent(i,1)*[cos(ags(j).rb_agent(i,2)+xh{j}(2*i,5));sin(ags(j).rb_agent(i,2)+xh{j}(2*i,5))] + ags(j2).rb(i,k)*[cos(ags(j2).rb(i,M+k)+xh{j2}(2*i,5));sin(ags(j2).rb(i,M+k)+xh{j2}(2*i,5))];
        plot(markp(2),markp(1),'rd');
        hold on;
        % plot 3sigma of other's measurements
        sigrho = sqrt(sigmap(2*M+2*k-1));
        sigthet = sqrt(sigmap(2*M+2*k));
        a = 3*sigrho;
        b = 3*sigthet*ye(j).tilde(i,2*M+2*k-1);
        x = linspace(-a,a,100);
        y1 = sqrt((1-x.^2/a^2)*b^2);
        y2 = -y1;
        %rotate ellipse by theta + psi
        phikk = ye(j).tilde(i,2*M+2*k)+xh{j2}(2*i,5);% is measured theta + other agent's est. heading
        C = [cos(phikk) sin(phikk);-sin(phikk) cos(phikk)];
        xtyt = C'*[x x(end:-1:1);y1 y2(end:-1:1)] + repmat(markp,1,200);
        plot(xtyt(2,:),xtyt(1,:),'r--')
        hold on;
    end
    
    set(gca,'xlim',xm,'ylim',ym);
    %axis equal;
    title(['t = ' num2str(tspan(i))]);
    set(gca,'NextPlot','replacechildren');
    
    pause(0.0333-toc);
end
end