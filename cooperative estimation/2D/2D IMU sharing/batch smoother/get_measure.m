function [ytilde,fl,Rk] = get_measure(i,j,ags,FOV,RANGE,RANGEMIN,Rbear)
%fl: feature list that are seen, and 0 or j2 if i or other agent saw it

N = size(ags,2);
M = size(ags(1).rb,2)/2;

ytilde = zeros(N*M,1);
fl = zeros(N*M,2);
% covariance matrix for output equation
Rk = zeros(N*M);

measurement_count = 0;

% use our own feature measurements
for m = 1:M
    % measured bearing:
    thetaki = ags(j).rb(i,m+M);
    %check that the measurement is less than the FOV
    if abs(thetaki) <= FOV(j)*d2r && abs(ags(j).rb(i,m)) < RANGE(j) && abs(ags(j).rb(i,m)) > RANGEMIN(j)
        % if we have seen it, use the estimate
        measurement_count = measurement_count+1;
        % measurement:
        ytilde(measurement_count) = thetaki;
        % store the index of the feature
        fl(measurement_count,1) = m;
        fl(measurement_count,2) = 0;
        % measurement covariance
        Rk(measurement_count,measurement_count) = Rbear(j);
    end
end

% check all other agents' feature measurements
for j2 = [1:j-1 j+1:N]
    % index used because each agent stores its
    % measurements of the other agents differently than
    % the `global' index
    j2ind = j2;
    if j2ind > j
        j2ind = j2ind-1;
    end
    jjind = j;
    if jjind > j2
        jjind = jjind-1;
    end
    % loop over each landmark
    for m = 1:M
        % check if the other agent can see the feature
        if abs(ags(j2).rb(i,m+M)) <= d2r*FOV(j2) && abs(ags(j2).rb(i,m)) < RANGE(j2) && abs(ags(j2).rb(i,m)) > RANGEMIN(j2)
            % use the feature
            thetakj = ags(j2).rb(i,m+M);
            measurement_count = measurement_count + 1;
            fl(measurement_count,1) = m;
            fl(measurement_count,2) = j2;
            % other agent's measurement:
            ytilde(measurement_count) = thetakj;
        end
    end
end

% delete unused indices
ytilde(measurement_count+1:end) = [];
fl(measurement_count+1:end,:) = [];

end