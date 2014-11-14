function Hk = ekf_measurement_gradient(xhat,uk)
rji_i = uk;

Hk = zeros(3,4);
Hk(:,1) = -2*squiggle(xhat(2:4))*rji_i;
Hk(:,2:4) = 2*xhat(1)*squiggle(rji_i) - 2*squiggle(xhat(2:4))*squiggle(rji_i) - 2*squiggle( squiggle(xhat(2:4))*rji_i );
Hk = -Hk;
end