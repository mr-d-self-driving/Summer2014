%animate.m
%
%animates the unknown feature case



for j = 1:2
    nFeatures = length(nonzeros(feature_ids(:,j)));
    xest = zeros(length(T),nFeatures);
    yest = zeros(length(T),nFeatures);
    zest = zeros(length(T),nFeatures);
    
    xtrue = zeros(length(T),nFeatures);
    ytrue = zeros(length(T),nFeatures);
    ztrue = zeros(length(T),nFeatures);
    for k = 1:nFeatures
        index = 17 + (k-1)*6 + (1:6);
        
        % find the time index of the first time we saw the feature
        t0 = find(xh{j}(:,index(1))~=0,1,'first');
        
        xyz = xh{j}(:,index(1:3));
        rho = xh{j}(:,index(4));
        bear = xh{j}(:,index(5));
        decl = xh{j}(:,index(6));
        qin = xh{j}(:,7:10);
        
        rkn = xyz + repmat(1./rho,1,3).*[cos(bear).*cos(decl) sin(bear).*cos(decl) sin(decl)];
        rki = rkn - xh{j}(:,1:3);
        
        rkn_true = XYZ_UNKNOWN(feature_ids(k,j),:);
        rki_true = repmat(rkn_true,length(T),1) - Yc{j}(:,1:3);
        qin_true = Yc{j}(:,7:10);
        
        rki_i = zeros(size(rki));
        rki_i_true = zeros(size(rki_true));
        for kk = 1:length(T)
            Cin = attparsilentmex(qin(kk,:)',[6 1]);
            rki_i(kk,:) = rki(kk,:)*Cin';
            Cin_t = attparsilentmex(qin_true(kk,:)',[6 1]);
            rki_i_true(kk,:) = rki_true(kk,:)*Cin_t';
            
            xest(kk,k) = rki_i(kk,1);
            yest(kk,k) = rki_i(kk,2);
            zest(kk,k) = rki_i(kk,3);
            
            xtrue(kk,k) = rki_i_true(kk,1);
            ytrue(kk,k) = rki_i_true(kk,2);
            ztrue(kk,k) = rki_i_true(kk,3);
        end
    end
    figure;
    for k = 1:length(T)
        subplot(121);
        set(gca,'NextPlot','replaceChildren');
        plot([xest(k,:)' xtrue(k,:)']',[yest(k,:)' ytrue(k,:)']','b-d','linewidth',2);
        hold on;
        plot(xtrue(k,:),ytrue(k,:),'rd','linewidth',2);
        plot(0,0,'kx','markersize',12,'linewidth',2);
        hold off;
        title(['Agent ' num2str(j)]);
        xlabel('x');
        ylabel('y');
        
        subplot(122);
        set(gca,'NextPlot','replaceChildren');
        plot([xest(k,:)' xtrue(k,:)']',[zest(k,:)' ztrue(k,:)']','b-d','linewidth',2);
        hold on;
        plot(xtrue(k,:),ztrue(k,:),'rd','linewidth',2);
        plot(0,0,'kx','markersize',12,'linewidth',2);
        hold off;
        title(['t = ' num2str(T(k))]);
        xlabel('x');
        ylabel('z');
        
        pause(.0025);
    end
end