function [rbd] = vector2polar(r)
rbd = zeros(3,1);
rbd(1) = sqrt(sum(r.^2));
rbd(2) = atan2(r(2),r(1));
rbd(3) = atan2(r(3),sqrt(r(1)^2+r(2)^2));
end