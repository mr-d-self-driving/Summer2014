function [f,fgrad] = simple_f_handle(x,u,t)

f = [1 0 0;0 1 0]* DCMConverter(3,u(3))'*[u(1:2);0];
fgrad = zeros(2);

end