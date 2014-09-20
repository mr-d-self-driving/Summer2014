function [xhatp,Pkp] = propagate_inv(xhat,Pk,uctrl,wk,Ts,Qk)
% xhat: [rx ry psi rxj ryj rhoj thetaj psij rxt ryt rhot thetat]
%         1  2  3   4   5    6     7     8    9  10  11    12

psii = xhat(3);
psij = xhat(8);

% linearized matrices
Fk = eye(12);
Bk = zeros(12,3);
Bk(3,3) = Ts;
Bk(1:2,1) = [cos(psii);sin(psii)];
Bk(4:5,2) = [cos(psij);sin(psij)];
Gk = zeros(12,4);
Gk(1:2,1) = -[cos(psii);sin(psii)];
Gk(4:5,2) = -[cos(psij);sin(psij)];
Gk(8,3) = 1;%error in other agent's heading propagation
Gk(9:10,4) = [1;1];% error in target's moving anchor point
% propagate my state
xhatp = Fk*xhat + Bk*[wk;uctrl];
Pkp = Fk*Pk*Fk' + Gk*Qk*Gk';

end