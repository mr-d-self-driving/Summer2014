function y = featureInitialization(x)

% x: n x 2N+1, where n is the state vector length
% y: 6 x 2N+1, where the rows are: xyz anchor point, inverse range, bearing, and declination to the feature 
% we assume that the LAST feature in x is the one we are measuring

n = size(x,1);
K = size(x,2);

y = zeros(6,K);

for j = 1:K
    xhat = x(:,j);
    rho = xhat(end-2);
    bearing = xhat(end-1);
    declination = xhat(end);
    
    qin = xhat(7:10);
    Cin = attparsilentmex(qin,[6 1]);
    
    % body frame relative vector to feature
    rki_i = rho*[cos(bearing)*cos(declination);sin(bearing)*cos(declination);sin(declination)];
    % inertial frame vector to the body
    %rin_n = xhat(1:3);
    % inertial frame vector to the feature
    %rkn = Cin'*rki_i + rin_n;
    
    % inertial frame range/bearing/declination to feature
    rki_n = Cin'*rki_i;
    rki_rbd = vector2polar(rki_n);
    
    % anchor point
    y(1:3,j) = xhat(1:3);
    % range
    y(4,j) = 1/rki_rbd(1);
    y(5:6,j) = rki_rbd(2:3);
end

end