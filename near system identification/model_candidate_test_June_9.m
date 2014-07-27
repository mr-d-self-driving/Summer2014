%% model_candidate_test_Jun_9
% test using data from June 9
clear variables;
close all;

load June_9_data.mat;
load('candidate_model.mat','SYSC_avg')
%%
SYSD_avg = c2d(SYSC_avg,.01);

for j = 1:size(t_st,1)
    innow = find(t > t_st(j,1) & t < t_st(j,2));
    subplot(2,size(t_st,1),j);
    
    plot(t(innow),vb(innow,[1 2]),'-','linewidth',2);
    x0 = vb(innow(1),[1 2])';
    u = eul(innow,[2 3]);
    ypred = zeros(size(vb(innow,[1 2])));
    for k = 1:length(innow)
        %store
        ypred(k,:) = x0';
        %propagate
        x0 = SYSD_avg.a*x0 + SYSD_avg.b*u(k,:)';
    end
    
    hold on;
    tilt = sprintf(['velocity histories for trial ' num2str(j) '\n with average model']);
    title(tilt);
    plot(t(innow),ypred,'--','linewidth',2);
    legend('u','v');
    
    %plot control
    subplot(2,size(t_st,1),j+size(t_st,1));
    plot(t(innow),r2d*u,'-','linewidth',2);
    legend('\theta','\phi');
    ylabel('deg');
    
    MSQ = 1/length(ypred)*sum((ypred-vb(innow,[1 2])).^2);
    disp(MSQ);
end