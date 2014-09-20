function [T,Y] = agent_sim(tspan,x0,F,B,G,Q,uzoh)

[T,Y] = ode45(@eqom_sim,tspan,x0,odeset('abstol',1e-5,'reltol',1e-5));

    function dy = eqom_sim(t,y)
        dy = F*y + B*uzoh + G*randn(size(Q))*sqrt(Q);
    end
end