function [T,Y] = agent_propagate(tspan,x0,P0,F,B,G,Q,uzoh)

y0 = [x0;reshape(P0,[],1)];
[T,Y] = ode45(@eqom_sim,tspan,y0,odeset('abstol',1e-5,'reltol',1e-5));

    function dy = eqom_sim(t,y)
        x = y(1:2);
        P = reshape(y(3:end),2,2);
        dx = F*x + B*uzoh;
        dP = F*P+P*F'+G*Q*G';
        
        dy = [dx;reshape(dP,[],1)];
    end
end