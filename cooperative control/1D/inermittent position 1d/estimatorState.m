function [T,X,P] = estimatorState(A,B,G,Q,tspan,x0,P0,uZOH)
% state 

y0 = [x0;reshape(P0,[],1)];

options = odeset('abstol',1e-4,'reltol',1e-4);

[T,Y] = ode45(@eqom_estimator,tspan,y0,options);

X = Y(:,1:size(A,1));
P = Y(:,size(A,1)+1:end);

    function dy = eqom_estimator(t,y)
        x = y(1:size(A,1));
        P = reshape(y(size(A,1)+1:end),size(A,1),size(A,1));
        
        dx = A*x + B*uZOH;
        dP = A*P + P*A'+G*Q*G';
        
        dy = [dx;reshape(dP,[],1)];
    end
end