function c = constrf(u)

%evaluate state history
X = zeros(4,size(u,2));
for i = 1:size(u,2)
    x = statehist(u(:,i));
    X(:,i) = x(:,end);
end

c = X([1 3 4],:) - repmat([1.524;0;0.81],1,size(u,2));
end