function [xhatp,Pkp] = propagate_inv_alt(xhat,Pk,uctrl,wk,Ts,Qk)
% propagate the states using the minimal inverse range parameterization
% xhat: [rx ry psi rhoj thetaj psij rhot thetat]
%         1  2  3   4      5    6     7     8

psii = xhat(3);
psij = xhat(8);
rhoj = xhat(4);
thetaj = xhat(5);
rhot = xhat(7);
thetat = xhat(8);

% process noise matrix
Gk = zeros(8,5);
Gk(1:2,1) = -[cos(psii);sin(psii)];
Aji = [-rhoj^2*cos(thetaj) -rhoj^2*sin(thetaj);
    -rhoj*sin(thetaj) rhoj*cos(thetaj)];
Ati = [-rhot^2*cos(thetat) -rhot^2*sin(thetat);
    -rhot*sin(thetat) rhot*cos(thetat)];
Gk(4:5,1) = Aji*[cos(psii);sin(psii)];
Gk(7:8,1) = Ati*[cos(psii);sin(psii)];
Gk(4:5,2) = -Aji*[cos(psij);sin(psij)];
Gk(3,3) = 1;
Gk(7:8,4:5) = Ati*Ts;

% linearized dynamics matrix
Fk = eye(8);
% control influence matrix
Bk = zeros(8,3);
Bk(3,3) = Ts;
Bk(1:2,1) = [cos(psii);sin(psii)];
Bk(4:5,1) = -Aji*[cos(psii);sin(psii)];
Bk(7:8,1) = -Ati*[cos(psii);sin(psii)];
Bk(4:5,2) = Aji*[cos(psij);sin(psij)];

% propagate my state
xhatp = Fk*xhat + Bk*[wk;uctrl];
Pkp = Fk*Pk*Fk' + Gk*Qk*Gk';

end