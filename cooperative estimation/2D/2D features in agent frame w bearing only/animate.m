function animate(j,ags,marks,xk,Rrange,Rbear,tspan,FOV,RANGE,ye,MOVIEFLAG)

if nargin < 10
    PLOTY = 0;
    MOVIEFLAG = 0;
else 
    PLOTY = 1;
    if nargin < 11
        MOVIEFLAG = 0;
    end
end

figure;

if MOVIEFLAG
    % Preallocate the struct array for the struct returned by getframe
    F(length(tspan)) = struct('cdata',[],'colormap',[]);
end

if isempty(j)
    jmax = length(ags);
    jmin = 1;
else
    jmax = j;
    jmin = j;
end

% make a vector of landmarks
marksv = zeros(length(marks),2);
for i = 1:length(marks)
    marksv(i,:) = marks(i).xy;
end

M = length(marks);

xm = [0 0];
ym = [0 0];
for j = jmin:jmax
    % find x and y limits for plotting
    xm2 = [min(ags(j).truth(:,2)) max(ags(j).truth(:,2))] + [-1 1]*sqrt(Rrange(j))*3;
    ym2 = [min(ags(j).truth(:,1)) max(ags(j).truth(:,1))] + [-1 1]*sqrt(Rrange(j))*3;
    
    xm(1) = min(xm(1),xm2(1));
    xm(2) = max(xm(2),xm2(2));
    ym(1) = min(ym(1),ym2(1));
    ym(2) = max(ym(2),ym2(2));
end
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
xhatn = cell(length(jmin:jmax),1);
for j = jmin:jmax    
    % compute the inertial position estimate of the agent
    xhatn{j} = zeros(length(tspan),2);
    for k = 1:length(xk(j).xk)
        Cbn = [cos(xk(j).xk(k,5)) -sin(xk(j).xk(k,5));
            sin(xk(j).xk(k,5)) cos(xk(j).xk(k,5))];
        xhatn{j}(k,:) = xk(j).xk(k,1:2)*Cbn';
    end
end
for i = 1:length(tspan)
    tic;
    hold off;
    % plot true landmarks
    plot(marksv(:,2),marksv(:,1),'kx');
    hold on;
    for j = jmin:jmax
        % define the indexing variable j2 again
        if j == 1
            j2 = 2;
        else
            j2 = 1;
        end
        
        % plot truth trajectory & estimated trajectory in inertial frame
        if j == 1
            plot(ags(j).truth(1:i,2),ags(j).truth(1:i,1),'-');
            hold on;
            plot(xhatn{j}(1:2*i,2),xhatn{j}(1:2*i,1),'--');
            if PLOTY
                for kkk = 1:size(ye{i,j},2)
                    plot( ye{i,j}(2,kkk), ye{i,j}(1,kkk), 'bo');
                end
            end
        else
            plot(ags(j).truth(1:i,2),ags(j).truth(1:i,1),'r-');
            hold on;
            plot(xhatn{j}(1:2*i,2),xhatn{j}(1:2*i,1),'r--');
            if PLOTY
                for kkk = 1:size(ye{i,j},2)
                    plot( ye{i,j}(2,kkk), ye{i,j}(1,kkk), 'ro');
                end
            end
        end
        %plot heading
        plot(ags(j).truth(i,2)+ [0 sin(ags(j).truth(i,5))],ags(j).truth(i,1)+ [0 cos(ags(j).truth(i,5))],'r-');
        plot(xhatn{j}(2*i,2)+ [0 sin(xk(j).xk(2*i,5))],xhatn{j}(2*i,1)+ [0 cos(xk(j).xk(2*i,5))],'r--');
        hold on;
        % plot FOV
        plot(ags(j).truth(i,2)+ [RANGE(2,j) RANGE(1,j)].*sin(ags(j).truth(i,5)+d2r*FOV(j)).*[1 1],ags(j).truth(i,1)+ [RANGE(2,j) RANGE(1,j)].*cos(ags(j).truth(i,5)+d2r*FOV(j)).*[1 1],'k-');
        plot(ags(j).truth(i,2)+ [RANGE(2,j) RANGE(1,j)].*sin(ags(j).truth(i,5)-d2r*FOV(j)).*[1 1],ags(j).truth(i,1)+ [RANGE(2,j) RANGE(1,j)].*cos(ags(j).truth(i,5)-d2r*FOV(j)).*[1 1],'k-');
    end
    set(gca,'xlim',xm,'ylim',ym);
    %axis equal;
    title(['t = ' num2str(tspan(i))]);
    set(gca,'NextPlot','replacechildren');
    
    set(gcf,'position',[225 100 1075 875]);
    
    if MOVIEFLAG
        F(i) = getframe;
    end
    if .03333 > toc
        pause(0.03333-toc);
    else
        pause(.0001)
    end
end

if MOVIEFLAG
    VR = VideoWriter('animate.avi');
    VR.FrameRate = 30;
    open(VR);
    
    for i = 1:length(tspan)
        writeVideo(VR,F(i));
    end
    
    close(VR);
end
end