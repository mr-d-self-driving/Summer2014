%% estimate_process_batch

clear variables;
close all;
load monte_state.mat;

% compute the final range error to target for both agents 1 and 2 and their
% expectation of the other agent

rho_t1 = zeros(MONTE,2);
rho_t2 = zeros(MONTE,2);
rho_t1s = zeros(MONTE,2);
rho_t2s = zeros(MONTE,2);
for II = 1:MONTE
    for j = 1:2
        rho_t1(II,j) = sqrt(sum((XK_COOP{II}(j).xk(end,1:2) - XK_COOP{II}(j).xk(end,7:8)).^2,2));
        rho_t2(II,j) = sqrt(sum((XK_COOP{II}(j).xk(end,4:5) - XK_COOP{II}(j).xk(end,7:8)).^2,2));
        rho_t1s(II,j) = sqrt(sum((XK_SOLO{II}(j).xk(end,1:2) - XK_SOLO{II}(j).xk(end,7:8)).^2,2));
        rho_t2s(II,j) = sqrt(sum((XK_SOLO{II}(j).xk(end,4:5) - XK_SOLO{II}(j).xk(end,7:8)).^2,2));
    end
end

% truth values
rho_t1t = sqrt(sum((Y(end,1:2) - Y(end,4:5)).^2,2));
rho_t2t = sqrt(sum((Y(end,7:8) - Y(end,4:5)).^2,2));

%% 
ix = find(abs(rho_t1s(:,1) - rho_t1t) >= 10);
fprintf('%i range errors > 10 m for agent 1 solo.\n',length(ix));

iy = setdiff(1:MONTE,ix);
fprintf('Mean range-to-target final error (agent 1) coop: %g m, solo: %g m.\n',mean(rho_t1(:,1)-rho_t1t),mean(rho_t1s(iy,1)-rho_t1t));
fprintf('Std of range-to-target final error (agent 1) coop: %g m, solo: %g m.\n',std(rho_t1(:,1)-rho_t1t),std(rho_t1s(iy,1)-rho_t1t));
fprintf('Mean range-to-target final error (agent 2) coop: %g m, solo: %g m.\n',mean(rho_t2(:,2)-rho_t2t),mean(rho_t2s(:,2)-rho_t2t));
fprintf('Std range-to-target final error (agent 2) coop: %g m, solo: %g m.\n',std(rho_t2(:,2)-rho_t2t),std(rho_t2s(:,2)-rho_t2t));