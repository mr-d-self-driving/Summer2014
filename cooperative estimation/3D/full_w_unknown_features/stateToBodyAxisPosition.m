function y = stateToBodyAxisPosition(x)
% x: n x 2N+1

n = size(x,1);
M = size(x,2);

% number of unknown features
U = (n-17)/6;

y = zeros(U*3,M);%XYZ in body frame for each unknown feature

for j = 1:M
    xhat = x(:,j);
    
    rin = xhat(1:3);
    qin = xhat(7:10);
    Cin = attparsilentmex(qin,[6 1]);
    
    % loop over features
    for k = 1:U
        index = 17 + (k-1)*6 + (1:6);
        index_y = (k-1)*3+(1:3);
        
        rho = xhat(index(4));
        theta = xhat(index(5));
        phi = xhat(index(6));
        
        % inertial vector to feature
        rkn = xhat(index(1:3)) + 1/rho*[cos(theta)*cos(phi);sin(theta)*cos(phi);sin(phi)];
        
        % body-axis vector from agent to the feature
        y(index_y,j) = Cin*(rkn - rin);
    end
end

end