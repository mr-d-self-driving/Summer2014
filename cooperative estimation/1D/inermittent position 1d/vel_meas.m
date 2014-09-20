function y = vel_meas(x,R)
% x(2): velocity measurement to which to add noise

y = x(2) + randn(1)*sqrt(R);
end