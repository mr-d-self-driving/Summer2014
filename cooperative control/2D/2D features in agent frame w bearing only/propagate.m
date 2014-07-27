function dy = propagate(x,u)
global Qk;

x0hat = x(1:5);
P0hat = reshape(x(6:30),5,5);

ri = x0hat(1:2);%body frame position vector
vi = x0hat(3:4);%body frame velocity vector
psii = x0hat(5);%heading

omega = u(3);
ai = u(1:2);

f = [vi - [0 -omega;omega 0]*ri;
    ai - [0 -omega;omega 0]*vi;
    omega];
Fk = [ -[0 -omega;omega 0] eye(2) zeros(2,1);
    zeros(2) -[0 -omega;omega 0] zeros(2,1);
    zeros(1,5)];
% process noise influence matirx
G = zeros(5,3);
G(3:5,1:3) = [-1 0 -vi(2);
    0 -1 vi(1);
    0 0 -1];

dy = zeros(30,1);
dy(1:5) = f;
dP = Fk*P0hat + P0hat*Fk' + G*Qk*G';
%dP = Fk*P0hat*Fk' + G*Qk*G';
dy(6:30) = reshape(dP,25,1);
end