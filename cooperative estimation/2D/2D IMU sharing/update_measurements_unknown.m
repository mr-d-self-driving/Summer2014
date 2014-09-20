% update_measurements_unknown

if imu_sharing
else
    switch feature_case
        case 1
            % bearing only feature measurements
            h_unknown_bearing_only_agent_rb_invrange_std;
    end
    
    if agent_case == 0
        % we are estimating our own position, velocity, and heading
        % we are measuring range and bearing to other agents
        
    else
        % we have not programmed this case yet
        disp('Error: cannot handle partially measured relative position vectors yet');
        break;
    end
end