function x = statehist(uv)

MU = 1;
T = 1.720;

x0 = [1;0;0;1];
m = 2;
N = length(uv)/m;
h = T/N;
x = zeros(4,N);
for i = 1:N
    u = uv((i-1)*m + (1:2));
    % euler appx
    x0 = x0 + h*eqom(x0,u);
    % store history
    x(:,i) = x0;
end

    function dy = eqom(x,u)
       dy = [x(3);
           x(4)/x(1);
           x(4)^2/x(1) - MU/x(1)^2 + u(1);
           -x(4)*x(3)/x(1)+u(2)];
    end
end