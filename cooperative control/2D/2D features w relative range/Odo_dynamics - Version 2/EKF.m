%% FUNCTION TO FIND THE UPDATED STATE

function [x,P] = EKF(t,x,y,P,flag)

global nf R Q flagg

%% EKF - x = states at k, P = covariance at k, R = noise, y = measurement
%% at k

%% Gain

Xf = reshape(x(4:end),2,nf);
Xr = x(1:3);
h  = headings(Xf,Xr);
hv = Xr(3);
Xr = repmat(Xr(1:2),1,nf);
Diff = Xf-Xr;
D  = Diff(1,:).^2 + Diff(2,:).^2;
H  = zeros(nf,2*nf+3);

for j = 1 : nf
    if flag(j)==1
    H(j,1:3)  = [Diff(2,j)/D(j) -Diff(1,j)/D(j)  -1]; % Do derivative
    H(j,3+2*j-1) = -Diff(2,j)/D(j);
    H(j,3+2*j) = Diff(1,j)/D(j);
    else
        H(:,2*j+3-1:2*j+3) = 0;
    end    
end

K  = P*H'*inv(H*P*H'+R);

%% Update

yy = x + K*(flag.*pi_to_pi(y - h));
x  = yy;
P  = (eye(length(x)) - K*H)*P;

%% Propogation

F  = eye(length(x));
P  = F*P*F' + Q;
ii = find(flag~=1);
for j = 1 : length(ii)
    P(2*ii(j)+3,2*ii(j)+3) = 1;   
end
