function [T,X] = simulateAgent(A,B,G,Q,tspan,y0,uZOH)

[T,X] = ode45(@eqom_agent,tspan,y0);

    function dy = eqom_agent(t,y)
        %process noise
        w = sqrt(Q)*randn(size(Q,1),1);        
        dy = A*y + B*uZOH + G*w;
    end
end