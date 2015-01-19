function [  ] = ekf_update_ranging_and_imu(xhat,uk)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here

%xk: 20 x 2N+1, inertial position, inertial velocity, inertial quaternion, relative position, and relative quaternion ... then unknown feature parameters 

%uk[wi;wj;ai;aj;r(1,2,3)j/j] : 21 x 2N+1

n = length(xhat);
m = 12;

% state influence
F = zeros(n);
%``control'' influence
B = zeros(n,m);
% process noise influence
G = zeros(n,m);

xdot = zeros(n,1);

% his position relative to mine. My body frame
rji = xhat(11:13);
% my velocity
vin = xhat(4:6);
% my attitude
qin = xhat(7:10);
% his attitude relative to mine. His body frame
qji = xhat(14:17);
% his inertial velocity (his body frame)
vjn = xhat(18:20);

% IMU measurements I made
wi = uk(1:3);
wj = uk(4:6);
ai = uk(7:9);
aj = uk(10:12);

Cin = attparsilent(qin,[6 1]);
Cji = attparsilent(qji,[6 1]);

%% compute the time derivative of the state
xdot(1:3) = Cin'*vin;
xdot(4:6) = ai - squiggle(wi)*vin;
% A matrix for qin
Ain = 0.5*[ -qin(2:4)';qin(1)*eye(3) + squiggle(qin(2:4))];
xdot(7:10) = Ain*wi;

xdot(11:13) = (Cji'*vjn-vin) - squiggle(wi)*rji;

% relative angular velocity in j frame
wji = wj-Cji*wi;
% A matrix for q_ji
A = 0.5*[ -qji(2:4)';qji(1)*eye(3) + squiggle(qji(2:4))];
% time rate of relative attitude
xdot(14:17) = A*wji;

xdot(18:20) = aj - squiggle(wj)*vjn;

%% state influence matrix

F(1:3,4:6) = Cin';


end