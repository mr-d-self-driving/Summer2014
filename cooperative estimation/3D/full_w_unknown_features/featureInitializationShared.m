function y = featureInitializationShared(x)

% x: n x 2N+1, where n is the state vector length
% y: 6 x 2N+1, where the rows are: xyz anchor point, inverse range, bearing, and declination to the feature 
% we assume that the LAST feature in x is the one we are measuring

n = size(x,1);
K = size(x,2);

y = zeros(6,K);

for j = 1:K
    xhat = x(:,j);
    % feature range/bearing/declination in OTHER agent's frame 
    rho = xhat(end-2);
    bearing = xhat(end-1);
    declination = xhat(end);
    % relative position vector to other agent, in MY frame
    rji_i = xhat(11:13);
    qji = xhat(14:17);
    Cji = attparsilentmex(qji,[6 1]);
    
    qin = xhat(7:10);
    Cin = attparsilentmex(qin,[6 1]);
    
    % body frame relative vector to feature
    rkj_j = rho*[cos(bearing)*cos(declination);sin(bearing)*cos(declination);sin(declination)];
    % inertial frame vector to the body
    rin_n = xhat(1:3);
    
    % compute vector from ME (i) to feature (K) & extract ...
    % inertial frame range/bearing/declination to feature
    rkj_n = Cin'*Cji'*rkj_j;
    rji_n = Cin'*rji_i;
    rki_n = rkj_n + rji_n;
    rki_rbd = vector2polar(rki_n);
    
    % anchor point
    y(1:3,j) = rin_n;
    % range
    y(4,j) = 1/rki_rbd(1);
    %bearing/declination in inertial frame
    y(5:6,j) = rki_rbd(2:3);
end

end