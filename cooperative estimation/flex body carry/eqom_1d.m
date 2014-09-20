function [T,Y] = eqom_1d(tspan,y0,f1handle)

global K L D;
if isempty(K)
    K = 0.5;
    L = 1;
    D = 0.1;
end

if y0(3) > 0
    A = (L+D)/2;
else
    A = -(L+D)/2;
end

% y: [x1 x1dot x3 x3dot];

[T,Y] = ode45(@eqom,tspan,y0);

    function dy = eqom(t,y)
        
        x3dotr = -K*(y(3) - A);
        
        
        f1 = f1handle(t,y);
        f_stab = -(y(4) - x3dotr);
        f_inv = 0;
        if y(3) > 0
            f_inv = 1e-2*(1/(y(3)-D) + 1/(y(3)-L));
        else
            f_inv = 1e-2*(1/(y(3)+D) + 1/(y(3)+L));
        end
        f2 = f1 - f_stab - f_inv;
        
        dy = [y(2);f1;y(4);f1-f2];
    end
end