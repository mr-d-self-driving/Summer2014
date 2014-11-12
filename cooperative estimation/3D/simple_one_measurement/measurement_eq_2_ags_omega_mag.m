function yk = measurement_eq_2_ags_omega(xk,nk,uk)
% for the case where the other agent's angular velocity is estimated and magnetometer is measured

%xk: 7 x 2N+1
%nk: 12 x 2N+1

% measurements: my body frame measurements of (1) other agent (2) heading, converted to the other agent's estimated body frame

%uk[wi;rji_i;mag_i]

n = size(xk,1);
l = size(nk,1);

rji_i = uk(4:6);
mag_i = uk(7:9);

yk = zeros(6,size(xk,2));
for k = 1:size(xk,2)
    xhat = xk(1:4,k);
    
    Cji = attparsilent(xhat,[6 1]);
    
    % where I think he should see me
    yk(1:3,k) = Cji*(rji_i-nk(1:3,k))+nk(4:6,k);
    % normalize
    yk(1:3,k) = yk(1:3,k)/norm(yk(1:3,k));
    % where I think he should see magnetic north
    yk(4:6,k) = Cji*(mag_i-nk(7:9,k))+nk(10:12,k);
    % normalize
    yk(4:6,k) = yk(4:6,k)/norm(yk(4:6,k));
end

end
