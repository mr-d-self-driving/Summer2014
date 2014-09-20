function [xp,Pp] = rk45_xp(x,P,u,h,fhandle,phandle)
P = permute(P,[2 3 1]);

[f,F,G] = fhandle(x,u);
k1 = h*f;
K1 = h*phandle(P,F,G);
[f,F,G] = fhandle(x+0.25*k1,u);
k2 = h*f;
K2 = h*phandle(P+0.25*K1,F,G);
[f,F,G] = fhandle(x+3./32.*k1+9./32.*k2,u);
k3 = h*f;
K3 = h*phandle(P+3./32.*K1+9./32.*K2,F,G);
[f,F,G] = fhandle(x+1932./2197.*k1-7200./2197.*k2+7296./2197.*k3,u);
k4 = h*f;
K4 = h*phandle(P+1932./2197.*K1-7200./2197.*K2+7296./2197.*K3,F,G);
[f,F,G] = fhandle(x+439./216.*k1-8.*k2+3680./513.*k3-845./4104.*k4,u);
k5 = h*f;
K5 = h*phandle(P+439./216.*K1-8.*K2+3680./513.*K3-845./4104.*K4,F,G);

% new value of x
xp = x+25./216.*k1+1408./2565.*k3+2197./4104.*k4-0.2*k5;
Pp = P+25./216.*K1+1408./2565.*K3+2197./4104.*K4-0.2*K5;
end