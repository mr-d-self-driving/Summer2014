function xp = rk45(x,u,h,fhandle)
k1 = h*fhandle(x,u);
k2 = h*fhandle(x+0.25*k1,u);
k3 = h*fhandle(x+3./32.*k1+9./32.*k2,u);
k4 = h*fhandle(x+1932./2197.*k1-7200./2197.*k2+7296./2197.*k3,u);
k5 = h*fhandle(x+439./216.*k1-8.*k2+3680./513.*k3-845./4104.*k4,u);
%k6 = h*fhandle(x-8./27.*k1+2.*k2-3544./2565.*k3+1859./4104.*k4-11./40.*k5);

% new value of x
xp = x+25./216.*k1+1408./2565.*k3+2197./4104.*k4-0.2*k5;
end