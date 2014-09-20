%% verify_measurements
clear variables;
close all;
load data.mat;

%generate new measurements
gen_new_noise;
%bitmask for which terms have bias
% 7 bit number
biasmask = '0000000';%from right to left -> a1 a2 omega range_landmark bearing_landmark range_agent bearing_agent
load_data_bitmask;%runs script that adds bias with random walk

for K = 1:N
    figure;
    for i = 1:M
        delta = repmat( marks(i).xy,length(T),1) - ags(K).truth(:,1:2);
        psi = ags(K).truth(:,5);
        range = sqrt(sum(delta.^2,2));
        bear = atan2(delta(:,2),delta(:,1))-psi;
        
        subplot(3,2,2*i-1);
        plot(tspan,ags(K).rb(:,i),'r--');
        hold on;
        plot(tspan,range);
        
        subplot(3,2,2*i);
        plot(tspan,ags(K).rb(:,i+M),'r--');
        hold on;
        plot(tspan,bear);
    end
end