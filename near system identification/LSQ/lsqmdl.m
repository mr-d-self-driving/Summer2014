function [Ak,Bk,Ck,Dk,k,xc] = lsqmdl(m,r,dt,u,y,desp,p)
% fit least-sqaures model for y_k+1 = Ak*y_k + Bk*u_k + xc
% to allow for different initial conditions
% same functional form as okid() function, some arguments are redundant


xk = [y(1:end-1,1:m)'; u(1:end-1,1:r)'; ones(1,size(y,1)-1)];

xkPlus = y(2:end,1:m)';
xkPlus = reshape(xkPlus,[],1);

%form multiplier matrix, for the form xkPlus = F*[unknowns]
F = kron(xk',eye(m));

x = (F'*F)\(F'*xkPlus);

Ak = reshape(x(1:m*m),[m m]);
Bk = reshape(x(m*m+(1:m*r)),[m r]);
xc = x(m*(m+r)+(1:m));
Ck = eye(m);
Dk = zeros(m,r);

k = [];

end