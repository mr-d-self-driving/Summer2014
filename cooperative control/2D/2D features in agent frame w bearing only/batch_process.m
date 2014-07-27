%% batch_process
% process batch_out file

close all;
clear variables;
load batch_out.mat;
%%
%compute mean, std, and mse errors for each case

errscoop = zeros(length(tspan)*Krun,5);
errssolo = zeros(length(tspan)*Krun,5);
fprintf('\n========================================');
for j = 1:N
    % compute inertial frame truth values
    xtrue = ags(j).truth(:,1:5);
    for kk = 1:length(tspan)
        Cbn = [cos(xtrue(kk,5)) sin(xtrue(kk,5));
            -sin(xtrue(kk,5)) cos(xtrue(kk,5))];
        xtrue(kk,1:2) = xtrue(kk,1:2)*Cbn';
    end
    for i = 1:Krun
        errscoop((1:length(tspan))+(i-1)*length(tspan),:) = xtrue - dvect{i,j};
        errssolo((1:length(tspan))+(i-1)*length(tspan),:) = xtrue - dvect2{i,j};
    end
    fprintf('\nIndividual & %i',j);
    %fprintf('& %.3g',mean(errssolo));
    fprintf('& %.3g',std(errssolo));
    fprintf('& %.3g',mean(errssolo.^2));
    fprintf(' \\\\');
    
    fprintf('\nCooperative & %i',j);
    %fprintf('& %.3g',mean(errscoop));
    fprintf('& %.3g',std(errscoop));
    fprintf('& %.3g',mean(errscoop.^2));
    fprintf(' \\\\');
end
fprintf('\n');