function X = pi2pi(X)

for j = 1:size(X,2)
    x = X(:,j);
    while any(x < -pi)
        x( x<-pi ) = x( x<-pi ) + 2*pi;
    end
    while any(x > pi)
        x( x > pi ) = x( x>pi )-2*pi;
    end
    X(:,j) = x;
end
end