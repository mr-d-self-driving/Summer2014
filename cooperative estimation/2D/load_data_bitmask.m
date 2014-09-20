%% load_data_bitmask
% designed to be called by a script like driver_indep

biasmask = bin2dec(biasmask);

% add any biases
for i = 1:7
    % for each agent, generate a bias history
    for K = 1:N
        %generate bias history
        if bitand(biasmask,2^(i-1))
            bv = (rand(1)*2*biasv(i,1)-biasv(i,1))*ones(length(tspan),1); %initialize uniformly to w/in \pm biasv(i,1)
            for j = 2:length(tspan)
                bv(j:end) = bv(j:end) + diff(tspan(j-1:j))*randn(1)*biasv(i,2);%add the bias standard_dev * delta_time to each subsequent measurement
            end
        else
            continue;
        end
        % add bias to agent's measurements
        if i <= 3
            %imu bias
            ags(K).IMU(:,i) = ags(K).IMU(:,i) + bv;
        else
            if i > 3 && i <=5
                %landmark range/bearing bias to every landmark
                ags(K).rb(:,(1:3) + (i-4)*M) = ags(K).rb(:,(1:3) + (i-4)*M) + repmat(bv,1,M);
            else
                if i > 5
                    ags(K).rb_agent(:,i-5) = ags(K).rb_agent(:,i-5) + bv;
                end
            end
        end
    end
end