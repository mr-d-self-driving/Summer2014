%% gen_new_noise
% for loaded data, generate new measurements with Gaussian white noise

if ~exist('TRUTH','var')
    TRUTH = 0;
end

for i = 1:N    
    if TRUTH
        ags(i).IMU = ags(i).truth(:,6:8);
    else
        ags(i).IMU = ags(i).truth(:,6:8) + randn(length(T),3).*repmat(diag(Rimu)',length(T),1);
    end
    % landmark range/bearing made by each agent
    psi = ags(i).truth(:,5);
    for j = 1:M
        delta = repmat(marks(j).xy,length(T),1) - ags(i).truth(:,1:2);
        if TRUTH
            ags(i).rb(:,M+j) = atan2(delta(:,2),delta(:,1)) - psi;%bearing
        else
            ags(i).rb(:,M+j) = atan2(delta(:,2),delta(:,1)) - psi + randn(length(T),1)*sqrt(Rbear(i));%bearing
        end
        ags(i).rb(:,M+1:end) = pi2pi(ags(i).rb(:,M+1:end));
        if TRUTH
            ags(i).rb(:,j) = sqrt(sum(delta.^2,2));%range
        else
            ags(i).rb(:,j) = sqrt(sum(delta.^2,2)) + randn(length(T),1)*sqrt(Rrange(i));%range
        end
    end
    %relative range/bearing
    c = 0;
    for j = [1:i-1 i+1:N]
        c = c + 1;
        delta = ags(j).truth(:,1:2) - ags(i).truth(:,1:2);
        if TRUTH
            ags(i).rb_agent(:,2*c-1) = sqrt(sum(delta.^2,2));%range
            ags(i).rb_agent(:,2*c) = atan2(delta(:,2),delta(:,1)) - psi;%bearing
        else
            ags(i).rb_agent(:,2*c-1) = sqrt(sum(delta.^2,2)) + randn(length(T),1)*sqrt(Rrange_ag);%range
            ags(i).rb_agent(:,2*c) = atan2(delta(:,2),delta(:,1)) - psi + randn(length(T),1)*sqrt(Rbear_ag);%bearing
        end
        ags(i).rb_agent(:,2*c) = pi2pi(ags(i).rb_agent(:,2*c)); 
    end
end