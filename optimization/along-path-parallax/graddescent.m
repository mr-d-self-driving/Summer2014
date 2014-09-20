function u = graddescent(u,fhandle)
% used in function minimization

ALPHA = 0.25;

% u is a n x 1 vector
n = length(u);
J = fhandle(u);

Jt = fhandle( repmat(u,1,n) + 1e-10*eye(n) );
% Jt is a 1 x n vector

%H is the apprx gradient of the cost function w.r.t. each value in u
H = (Jt - repmat(J,1,n))*1e10;

% appx the second derivative for the adaptive step size

% update and return
u = u - ALPHA*H';
end