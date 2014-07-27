function x = pi2pi(x)
while any(x < -pi)
    x( x<-pi ) = x( x<-pi ) + 2*pi;
end
while any(x > pi)
    x( x > pi ) = x( x>pi )-2*pi;
end
end