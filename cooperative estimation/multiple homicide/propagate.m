function [xhatp,Pkp] = propagate(j,xhat,Pk,uctrl,wk,Ts,Qk)
% propagate for
% xhat: [rx1 ry1 psi1 rx2 ry2 psi2 rxt ryt]

psii = xhat(3);
psij = xhat(6);

% linearized matrices
Fk = eye(8);
Bk = zeros(8,3);
Bk(1:5,1:2) = [cos(psii) 0;
    sin(psii) 0;
    0 0;
    0 cos(psij);
    0 sin(psij)];
if j == 1
    Bk(3,3) = Ts;% own control
else
    Bk(6,3) = Ts;% own control
end
Gk = zeros(8,4);
Gk(1:2,1) = -[cos(psii);sin(psii)];
Gk(4:5,2) = -[cos(psij);sin(psij)];
if j == 1
    Gk(6,3) = 1;
else
    Gk(3,3) = 1;
end
Gk(7:8,4) = [1;1];

xhatp = Fk*xhat + Bk*[wk;uctrl];
Pkp = Fk*Pk*Fk' + Gk*Qk*Gk';

end