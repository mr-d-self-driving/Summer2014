function J = costf(u)

MU = 1;

% u(1): lambda_r(0)
% u(2): lambda_theta(0)
% u(3): lambda_u(0)
% u(4): lambda_v(0)

%initial conditions
x0 = [1;0;0;1];
% boundary conditions
rf = 1.524;
uf = 0;
vf = 0.81;
lambda_thetaf = 0;

global h N;

J = zeros(1,size(u,2));
for jj = 1:size(u,2)
    
    X = zeros(4,N+1);
    L = zeros(4,N+1);
    
    X(:,1) = x0;
    L(:,1) = u(:,jj);
    
    for i = 1:N
        f = local_eqom([],[X(:,i);L(:,i)]);
        new = [X(:,i);L(:,i)] + h*f;
        X(:,i+1) = new(1:4);
        L(:,i+1) = new(5:8);
    end
    
    J(jj) = 0.5*((X(1,end)-rf)^2 + (X(3,end)-uf)^2 + (X(4,end)-vf)^2 + (L(2,end) - lambda_thetaf)^2);
end

    
end