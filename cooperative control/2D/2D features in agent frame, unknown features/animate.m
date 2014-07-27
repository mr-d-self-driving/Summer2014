function animate(j,ags,marks,xk,Rrange,Rbear,tspan,FOV,RANGE,ye)

if nargin < 10
    PLOTY = 0;
else
    PLOTY = 1;
end

N = size(ags,2);

figure;

if isempty(j)
    jmax = length(ags);
    jmin = 1;
else
    jmax = j;
    jmin = j;
end

% make a vector of landmark true positions
marksv = zeros(length(marks),2);
for i = 1:length(marks)
    marksv(i,:) = marks(i).xy;
end

% make matrices of true inertial-to-body transformations
CBN = cell(N,1);
for J = 1:N
    CBN{J} = zeros(2*length(tspan),2);
    for i = 1:length(tspan)
        % use true heading transf.
        CBN{J}(2*i-1:2*i,:) = [cos(ags(J).truth(i,5)) sin(ags(J).truth(i,5));
            -sin(ags(J).truth(i,5)) cos(ags(J).truth(i,5))];
        % use est. heading transf.
        %CBN{J}(2*i-1:2*i,:) = [cos(xk(J).xk(2*i,3)) sin(xk(J).xk(2*i,3));
        %    -sin(xk(J).xk(2*i,3)) cos(xk(J).xk(2*i,3))];
    end
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
        else
            plot(ags(j).truth(1:i,2),ags(j).truth(1:i,1),'r-');
        end
        if PLOTY
            for kkk = 1:size(ye{i,j},2)
                plot( ye{i,j}(2,kkk), ye{i,j}(1,kkk), 'ro');
            end
        end
        %plot heading
        plot(ags(j).truth(i,2)+ [0 sin(ags(j).truth(i,5))],ags(j).truth(i,1)+ [0 cos(ags(j).truth(i,5))],'r-');
        %temporarily put the estimated heading at the true position 
        plot(ags(j).truth(i,2)+ [0 sin(xk(j).xk(2*i,3))],ags(j).truth(i,1)+ [0 cos(xk(j).xk(2*i,3))],'r-');
        hold on;
        % plot FOV
        plot(ags(j).truth(i,2)+ [RANGE(2,j) RANGE(1,j)].*sin(ags(j).truth(i,5)+d2r*FOV(j)).*[1 1],ags(j).truth(i,1)+ [RANGE(2,j) RANGE(1,j)].*cos(ags(j).truth(i,5)+d2r*FOV(j)).*[1 1],'k-');
        plot(ags(j).truth(i,2)+ [RANGE(2,j) RANGE(1,j)].*sin(ags(j).truth(i,5)-d2r*FOV(j)).*[1 1],ags(j).truth(i,1)+ [RANGE(2,j) RANGE(1,j)].*cos(ags(j).truth(i,5)-d2r*FOV(j)).*[1 1],'k-');
        % plot landmark estimates, vector is in the inertial frame
        r_est = CBN{J}(2*i-1:2*i,:)'*reshape(xk(j).xk(2*i,4:end)',2,M) + repmat(ags(j).truth(i,1:2)',1,M);
        if j == 1
            plot(r_est(2,:),r_est(1,:),'bx');
        end
        if j == 2
            plot(r_est(2,:),r_est(1,:),'rx');
        end
    end
    set(gca,'xlim',xm,'ylim',ym);
    %axis equal;
    title(['t = ' num2str(tspan(i))]);
    set(gca,'NextPlot','replacechildren');
    
    if .03333 > toc
        pause(0.03333-toc);
    else
        pause(.0001)
    end
end
end