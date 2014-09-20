function [h, hgrad] = simple_h_handle(x)
h = x;
hgrad = eye(2);
end