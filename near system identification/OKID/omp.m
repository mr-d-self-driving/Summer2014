% ****************************************************
% Written by J.R. Yim.
% Modified on September 4, 1997
% For example of numerical calculation
% ****************************************************
clear all
global A B C D Ac Bc p q m n r dt u
randn('seed',5)

% Initial Condition 
M = 1;
Z =0.01;
K = 1;
B2 = 1;
Ac =  [0 1; -inv(M)*K -inv(M)*Z];
Bc = [0; inv(M)*B2];
Cd = 0;
Cv = 0;
Ca = 1;
C = [ Cd-Ca*inv(M)*K Cv-Ca*inv(M)*Z];
D = [Ca*inv(M)*B2];
dt = 0.2;
[A, B] = c2d(Ac,Bc,dt);

pf = 6; pb=0; p = pf+pb; q = 50; pt = 200;

format short e; format compact
%format long e; format compact

[m,n] = size (C); [n,r] = size(Bc);
t = [dt:dt:pt*dt]';  % time step size

u = randn(pt,r) ;
x0 = [0 0 ]'; ic1 = 1;
%x0 = [1 1 1 1 1 1]'; ic1 = 1;
[y, x] = dlsim(A,B,C,D,u,x0);

%[a,b,c,d,G]=okid(m,r,dt,u,y,'batch',p,x0);
[a,b,c,d,G]=okid(m,r,dt,u,y,'batch',1);

figure(1)
plot(t,u(:,1),'--')
axis([0 30 -4 4])
title('Control Input for using the Indirect Method (q step = 50) : CASE III')
xlabel('Time (sec)')
legend('Original Input','Control Input')
hold on

figure(2)
plot(t,y(:,1),'--')
axis([0 30 -10 +10])
title('Control Output for using the Indirect Method (q step = 50) : CASE III')
xlabel('Time (sec)')
legend('Original Output','Control Output')
hold on
