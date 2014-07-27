function y = rel_meas(x1,x2,R)

y = x1(1) - x2(1) + randn(1)*sqrt(R);

end