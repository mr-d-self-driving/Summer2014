function [xhatp,Pkp] = propagate_inv_alt(xhat,Pk,uctrl,wk,Ts,Qk,FLAG)
% propagate the states using the minimal inverse range parameterization
% xhat: [rx ry psi rhoj thetaj psij rhot thetat]
%         1  2  3   4      5    6     7     8

rx = xhat(1);
ry = xhat(2);
psii = xhat(3);
psij = xhat(6);
rhoj = xhat(4);
thetaj = xhat(5);
rhot = xhat(7);
thetat = xhat(8);

xhatp = zeros(8,1);

% propagate my state
xhatp(1:2) = xhat(1:2) + wk(1)*[cos(psii);sin(psii)];
xhatp(3) = xhat(3) + Ts*uctrl(1);
% other agent's state
delRx = cos(thetaj)/rhoj + wk(2)*cos(psij) - rx - wk(1)*cos(psii);
delRy = sin(thetaj)/rhoj + wk(2)*sin(psij) - ry - wk(1)*sin(psii);

xhatp(4) = 1/sqrt(delRx^2+delRy^2);
xhatp(5) = atan2(delRy,delRx);
xhatp(6) = xhat(6);
% target's state
delRxt = cos(thetat)/rhot - rx - wk(1)*cos(psii);
delRyt = sin(thetat)/rhot - ry - wk(1)*sin(psii);
xhatp(7) = 1/sqrt(delRxt^2 + delRyt^2);
xhatp(8) = atan2(delRyt,delRxt);

% linearized matrices for propagating the covariance
% dynamic EQOM matrix
Fk = zeros(8);
Fk(1:2,1:2) = eye(2);
Fk(1:2,3) = wk(1)*[-sin(psii);cos(psii)];
Fk(3,3) = 1;
% terms used in the inverse range and bearing to agent j
d_delRx = [-1 0 wk(1)*sin(psii) -cos(thetaj)/rhoj^2 -sin(thetaj)/rhoj -wk(2)*sin(psij) 0 0];
d_delRy = [0 -1 -wk(1)*cos(psii) -sin(thetaj)/rhoj^2 cos(thetaj)/rhoj wk(2)*cos(psij) 0 0];
Fk(4,:) = -xhatp(4)^3*(delRy*d_delRy + delRx*d_delRx);
Fk(5,:) = delRx^2/(delRy^2+delRx^2)*(1/delRx*d_delRy - delRy/delRx^2*d_delRx);
Fk(6,6) = 1;
% terms used in the inverse range and bearing to target
d_delRxt = [-1 0 wk(1)*sin(psii) 0 0 0 -cos(thetat)/rhot^2 -sin(thetat)/rhot];
d_delRyt = [0 -1 -wk(1)*cos(psii) 0 0 0 -sin(thetat)/rhot^2 cos(thetat)/rhot];
Fk(7,:) = -xhatp(7)^3*(delRyt*d_delRyt + delRxt*d_delRxt);
Fk(8,:) = delRxt^2/(delRyt^2+delRxt^2)*(1/delRxt*d_delRyt - delRyt/delRxt^2*d_delRxt);

% process noise matrix
Gk = zeros(8,5);
% dot(psi)_j
Gk(6,3) = Ts;
% agent i invertial position
Gk(1:2,1) = -[cos(psii);sin(psii)];
% agent j inverse range and bearing
d_delRxw = [cos(psii) -cos(psij) 0 0 0];
d_delRyw = [sin(psii) -sin(psij) 0 0 0];
Gk(4,:) = -xhatp(4)^3*(delRy*d_delRyw + delRx*d_delRxw);
Gk(5,:) = delRx^2/(delRy^2+delRx^2)*(1/delRx*d_delRyw - delRy/delRx^2*d_delRxw);
% target inverse range and bearing
d_delRxtw = [cos(psii) 0 0 1 0];
d_delRytw = [sin(psii) 0 0 0 1];
Gk(7,:) = -xhatp(7)^3*(delRyt*d_delRytw + delRxt*d_delRxtw);
Gk(8,:) = delRxt^2/(delRyt^2+delRxt^2)*(1/delRxt*d_delRytw - delRyt/delRxt^2*d_delRxtw);

%xhatp = Fk*xhat + Bk*[wk;uctrl];
Pkp = Fk*Pk*Fk' + Gk*Qk*Gk';

end