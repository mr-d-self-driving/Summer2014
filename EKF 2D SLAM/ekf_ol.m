function [tout,xhatout,Phatout] = ekf_ol(f_handle,h_handle,Q,R,t,ytilde,u,xt0,P0)
% open-loop extended kalman filter for processing full state/ctrl histories
% INPUTS
% f_handle: function handle that returns f(x,u,t) and its gradient w.r.t. x
% h_handle:     "      "   that returns h(x) and its gradient
% G: process noise influence matrix is now hardwired
% Q: process noise covariance matrix
% R: measurement noise covariance matrix
% t: time history vector, does not need to be evenly spaced
% ytilde: output measurement history, must have size(ytilde,1) = length(t)
% u: control input history
% xt0: (optional) argument that prespecifies an initial state estimate
% P0: (optional) argument that specifies an initial error covariance matrix
%
% OUTPUTS
% tout
% xhatout

n = 8;

% initialize
if nargin <= 8
    xt = zeros(n,1);
    Pt = zeros(n);
else
    xt = xt0;
    Pt = P0;
end

tout = zeros( length(t) + 1 + 10*(length(t)-1),1);
xhatout = zeros(length(tout),n);
Phatout = zeros(length(tout),n^2);
count = 0;
for i = 1:length(t)
    if i == 1
        count = count+1;
        tout(count) = t(i);
        xhatout(count,:) = xt';
        Phatout(count,:) = reshape(Pt,n^2,1)';
    end
    
    % determine the gain
    [hk,Hk] = h_handle(xt);
    Kk = Pt*Hk'*((Hk*Pt*Hk' + R)\eye(size(Hk,1)));
    
    % rigorously check that hk cannot be made close to ytilde by an
    % adjustment of /pm pi
    
    for j = 1:length(hk)
        while abs((hk(j) - 2*pi) - ytilde(i,j)) < abs(hk(j) - ytilde(i,j)) | abs((hk(j) + 2*pi) - ytilde(i,j)) < abs(hk(j) - ytilde(i,j))
            if abs((hk(j) - 2*pi) - ytilde(i,j)) < abs(hk(j) - ytilde(i,j))
                hk(j) = hk(j) - 2*pi;
            else
                if abs((hk(j) + 2*pi) - ytilde(i,j)) < abs(hk(j) - ytilde(i,j))
                    hk(j) = hk(j) + 2*pi;
                end
            end
        end
    end
    
    % update the estimate
    xt = xt + Kk*(ytilde(i,:)' - hk);
    Pt = (eye(n) - Kk*Hk)*Pt;
    
    count = count+1;
    tout(count) = t(i);
    xhatout(count,:) = xt';
    Phatout(count,:) = reshape(Pt,n^2,1)';
    
    if i == length(t)
        break;
    end
    
    % propagate
    state0 = [xt;reshape(Pt,n^2,1)];
    tspan = linspace(t(i),t(i+1),10);
    [T,Y] = ode45(@ekf_eqom,tspan,state0,odeset('abstol',1e-5,'reltol',1e-5));
    
    tout(count+(1:10)) = T;
    xhatout(count+(1:10),:) = Y(:,1:n);
    Phatout(count+(1:10),:) = Y(:,n+1:end);
    count = count+10;
    
    xt = Y(end,1:n)';
    Pt = reshape(Y(end,n+1:end)',n,n);
end

    function dy = ekf_eqom(tt,y)
        dy = zeros(length(y),1);
        x = y(1:n);
        P = reshape(y(n+1:end),n,n);
        
        %interpolate for u(t), assuming a ZOH
        in = find(t <= tt,1,'last');
        U = u(in,:)';
        
        [f,F] = f_handle(x,U,tt);
        
        G = [0 0 0 0 0 0;
            0 0 0 0 0 0;
            -1 0 -x(4) 0 0 0;%vx - accx term influences
            0 -1 x(3) 0 0 0;
            0 0 -1 0 0 0;%psi - gyro bias term influences
            0 0 0 1 0 0;%biases: bias model variance influences
            0 0 0 0 1 0;
            0 0 0 0 0 1];
        
        dy(1:n) = f;
        
        dP = F*P + P*F' + G*Q*G';
        %dP = F*P*F' + G*Q*G';
        
        dy(n+1:end) = reshape(dP,n^2,1);
    end
end