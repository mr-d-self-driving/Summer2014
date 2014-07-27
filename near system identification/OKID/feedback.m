function [y,x] = feedback(A,B,C,D,K)
global dt pt t

R = [0 1 0 0; 0 0 0 1];
P = [ C; R];
Q = inv(P);
Q1 = Q(:,1:2); Q2 = Q(:,3:4);
Abar = P*A*inv(P); Bbar = P*B; Cbar = C*inv(P);
Abar22 = Abar(3:4, 3:4); Abar12 = Abar(1:2, 3:4);
Abar21 = Abar(3:4, 1:2); Abar11 = Abar(1:2, 1:2);
Bbar1 = Bbar(1:2,:); Bbar2 = Bbar(3:4,:);

% Desired poles are -1 and -2 for state estimator
pole = [ -1, -2];
L = place(Abar22', Abar12',pole);
L = L';

% zdot = F*z+ G*y + H*u ; State Estimator

F= Abar22 - L*Abar12 ;
G = F*L + Abar21-L*Abar11;
H = Bbar2 - L*Bbar1;

% The composite dynamical equation of the system (xdot and edot)
AA = [ A+B*K B*K*Q2; zeros(2,4) F];
BB = [B ; zeros(2)];
CC = [ C zeros(2)];

[AA, BB] = c2d(AA, BB, dt);
x(:,1) = [ 3 0.5 0.2 0.5 1 0.5]';
for i = 1:pt
  y(:,i) = CC*x(:,i);
 if i == pt
 else 
   x(:,i+1) = AA*x(:,i);
  end
end
