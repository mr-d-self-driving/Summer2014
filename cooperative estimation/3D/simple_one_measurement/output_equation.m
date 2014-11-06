function y = output_equation(x)
% x:[rji_i;rij_j;quaternion] n x M

y = zeros(3,size(x,2));
for k = 1:size(x,2)
    Cji = attparsilent(x(7:10,k),[6 1]);
    y(:,k) = - x(4:6,k) - Cji*x(1:3,k);
end

end