function [J] = fitnessf(u)

J = zeros(1,size(u,2));
for i = 1:size(u,2)
    J(i) = u(:,i)'*u(:,i);
end

end