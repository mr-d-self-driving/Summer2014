%% FUNCTION TO FIND THE UPDATED STATE

function [x,P] = EKF(t,x,y,P)

global nf R Q

%% EKF - x = states at k, P = covariance at k, R = noise, y = measurement
%% at k

%% Gain
Xf = reshape(x(4:end),2,nf);
Xr = x(1:3);
h  = [Xr;headings(Xf,Xr)];
hv = Xr(3);
Xr = repmat(Xr(1:2),1,nf);
Diff = Xf-Xr;
D  = Diff(1,:).^2 + Diff(2,:).^2;
H(1:3,:) = [1 zeros(1,nf+2); 0 1 zeros(1,nf+1); 0 0 1 zeros(1,nf)];
for j = 1 : nf
    H(j+3,1:3)  = [Diff(2,j)/D(j) -Diff(1,j)/D(j)  -1]; % Do derivative
    H(j+3,3+2*j-1) = -Diff(2,j)/D(j);
    H(j+3,3+2*j) = Diff(1,j)/D(j);
end

K  = P*H'*inv(H*P*H'+R);

%% Update

yy = x + K*(pi_to_pi(y - h));
%x(1:3) = yy(1:3);
x = yy;
P = (eye(length(x)) - K*H)*P;

%% Propogation

F  = eye(length(x));
P  = F*P*F' + Q;
