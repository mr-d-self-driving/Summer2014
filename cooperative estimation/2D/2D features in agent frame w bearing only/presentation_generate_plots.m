%% generate_plots_presentation

clear variables;
close all;

%% process for variable update rate
batch = {'batch_out_K_05_Jul_22.mat','batch_out_K_10_Jul_22.mat','batch_out_K_25_Jul_22.mat','batch_out_K_100_Jul_22.mat'};
presentation_process_batch;
%% plot for vatriable K
figure;
boxplot( [reshape(errsc{1}(:,1:2),[],1) reshape(errsc{2}(:,1:2),[],1) reshape(errsc{3}(:,1:2),[],1) reshape(errsc{4}(:,1:2),[],1)],'symbol','');
set(gca,'ylim',[-1.5 2]);
set(gca,'xticklabel',{'2 Hz','1 Hz','.04 Hz','.01 Hz'});
set(gca,'xtick',[1 2 3 4],'fontsize',12);
title('Cooperative position errors versus update rate','fontsize',14);
grid on;

set(gcf,'position',[333 200 600 775]);

export_fig('presentation_figs\K_boxes','-png','-transparent','-a1');
%% process for small # landmarks
batch = {'batch_out_M_3_Jul_21.mat','batch_out_M_4_Jul_21.mat','batch_out_M_5_Jul_21.mat'};
presentation_process_batch;
%% plot for small # landmarks

figure;
boxplot( [reshape(errsc{1}(:,1:2),[],1) reshape(errsi{1}(:,1:2),[],1) reshape(errsc{2}(:,1:2),[],1) reshape(errsi{2}(:,1:2),[],1) reshape(errsc{3}(:,1:2),[],1) reshape(errsi{3}(:,1:2),[],1)],'symbol','','colors','rbrb');
set(gca,'ylim',[-25 25]);
set(gca,'xticklabel',{'M = 3, c','M = 3, i','M = 4, c','M = 4, i','M = 5, c','M = 5, i'});
set(gca,'xtick',[1 2 3 4 5 6],'fontsize',12);
title('Position errors for small feature numbers','fontsize',14);

set(gcf,'position',[333 200 600 775]);

export_fig('presentation_figs\M_small_boxes','-png','-transparent','-a1');

%% process for changing landmarks, lots
batch = {'batch_out_M_25_Jul_21.mat','batch_out_M_50_Jul_21.mat','batch_out_M_75_Jul_21.mat'};
presentation_process_batch;
%% plot for large # landmarks

figure;
boxplot( [reshape(errsc{1}(:,1:2),[],1) reshape(errsi{1}(:,1:2),[],1) reshape(errsc{2}(:,1:2),[],1) reshape(errsi{2}(:,1:2),[],1) reshape(errsc{3}(:,1:2),[],1) reshape(errsi{3}(:,1:2),[],1)],'symbol','','colors','rb');
set(gca,'ylim',[-2 2]);
set(gca,'xticklabel',{'M = 25, c','M = 25, i','M = 50, c','M = 50, i','M = 75, c','M = 75, i'});
set(gca,'xtick',[1 2 3 4 5 6],'fontsize',10);
title('Position errors for large feature numbers','fontsize',14);

set(gcf,'position',[333 200 600 775]);

export_fig('presentation_figs\M_large_boxes','-png','-transparent','-a1');
%% process for bearing only vs. bearing/range feature
batch = {'batch_out_nom_Jul18.mat','../2D features in agent frame/batch_out_nom_range_bear_Jul18.mat','../2D features in agent frame/batch_out_nom_range_bear_fr_var_10_Jul21.mat'};
presentation_process_batch;
%% plot for bearing only vs. bearing/range

figure;
ind = floor(linspace(1,size(errsc{1}(:,1),1),size(errsc{2}(:,1),1)));
boxplot( [reshape(errsc{1}(ind,1:2),[],1) reshape(errsi{1}(ind,1:2),[],1) reshape(errsc{2}(:,1:2),[],1) reshape(errsi{2}(:,1:2),[],1) reshape(errsc{3}(:,1:2),[],1) reshape(errsi{3}(:,1:2),[],1)],'symbol','','colors','rbkmkm');
set(gca,'ylim',[-2 2]);
set(gca,'xticklabel',{'bearing,c','bearing,i','r/b,c','r/b,i','r/b,c,v','r/b,i,v'});
set(gca,'xtick',[1 2 3 4 5 6],'fontsize',12);
title( sprintf('Position errors with feature range and\nbearing and range only'),'fontsize',14);

set(gcf,'position',[333 200 600 775]);

export_fig('presentation_figs\bearing_v_range_bear','-png','-transparent','-a1');
%% process for coop vs individual bearing only
batch = {'batch_out_nom_Jul18.mat'};
presentation_process_batch;
%% plot
figure;
boxplot( [reshape(errsc{1}(:,1),[],1) reshape(errsi{1}(:,1),[],1) reshape(errsc{1}(:,2),[],1) reshape(errsi{1}(:,2),[],1)],'symbol','','colors','rb');
set(gca,'ylim',[-2 2.5]);
set(gca,'xticklabel',{'coop, 1','ind, 1','coop, 2','ind, 2'});
set(gca,'xtick',[1 2 3 4],'fontsize',12);
title( sprintf('Position errors for cooperative and individual\n bearing only features'),'fontsize',14);

set(gcf,'position',[333 200 600 775]);

export_fig('presentation_figs\coop_v_ind','-png','-transparent','-a1');