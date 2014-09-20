function u = constrdescent(u,chandle)
% used to try to reduce constraint violations in candidate solutions
% employs a Newton's method

ALPHA = 0.1;

% u is a n x 1 vector
n = length(u);
J = chandle(u);
% J is an m x 1 vector, m being the number of constraints

Jt = chandle( repmat(u,1,n) + 1e-6*eye(n) );
% Jt is a m x n vector

%H is the apprx gradient of the constraint error vector w.r.t. each value in u
H = (Jt - repmat(J,1,n))*1e6;

% we want to find the largest magnitude of constraint violation and reduce
% it
[~,j] = max(abs(J));
% we estimate the derivative of the jth constraint, which is a 1 x n vector
fhat = H(j,:);

% update and return
fhatinv = 1./fhat;
fhatinv(fhatinv == Inf) = 0;
u = u - ALPHA*J(j).*fhatinv';
end