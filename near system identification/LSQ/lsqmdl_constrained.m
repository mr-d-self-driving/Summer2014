function [Ak,Bk,Ck,Dk,k,xc] = lsqmdl_constrained(m,r,dt,u,y,desp,p)
% fit least-sqaures model for y_k+1 = Ak*y_k + Bk*u_k
% to allow for different initial conditions
% same functional form as okid() function, some arguments are redundant

xk = [y(1:end-1,1:m)'];%; u(1:end-1,1:r)'];

xkPlus = y(2:end,1:m)';
controlterm = zeros(size(xkPlus));
for i = 1:length(xk)-1
    controlterm(:,i) = (dt*diag([-9.81 9.81])*u(i,:)');
end

xkPlus = xkPlus - controlterm;

xkPlus = reshape(xkPlus,[],1);

%form multiplier matrix, for the form xkPlus = F*[unknowns]
F = kron(xk',eye(m));

x = (F'*F)\(F'*xkPlus);

Ak = reshape(x(1:m*m),[m m]);
Bk = dt*diag([-9.81 9.81]);%reshape(x(m*m+(1:m*r)),[m r]);
Ck = eye(m);
Dk = zeros(m,r);

xc = zeros(m,1);
k = [];

end