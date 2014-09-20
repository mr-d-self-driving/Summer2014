function y = landmark_meas(x,R)
% call with R == 0 to get the expected measurement
global features;

M = length(features);
y = zeros(M,1);
for i = 1:M
    y(i) = features(i) - x(1) + randn*sqrt(R(i,i));
end
end