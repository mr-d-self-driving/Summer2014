% ****************************************************
% Written by J.R. Yim.
% Modified on November 4, 1997
% For example of numerical calculation
% ****************************************************
clear all
global A B C D Ac Bc p q m n r dt u
randn('seed',5)

% Initial Condition 
m= 1; R = 1; b = 10; g = 0.98; 
Ac = [ 0 1; -g/R -b/(m*R^2)];
Bc = [0; 1];
C = [1 0];
D = [0];

dt = 0.02;
[A, B] = c2d(Ac,Bc,dt);

pf = 2; pb=0; p = pf+pb; q = 50 ; pt = 200;

%format short e; format compact

format long e; format compact

[m,n] = size (C); [n,r] = size(Bc);
t = [dt:dt:pt*dt]';  % time step size

%clear Ac Bc;

u = randn(pt,r);
x0 = [0 0]'; ic1 = 1;
%x0 = [1 1 1 1 1 1]'; ic1 = 1;

[y, x] = dlsim(A,B,C,D,u,x0);


%[A,B,C,D,G,x0]=okid(m,r,dt,u,y,'batch',p);
%value2 = eig(A);
g=deadbeat(A,B,C,D) ;

k=50;

%[uu, yk] = example1(A,B,C,D,g,pf,pb,k,u,y,x);
[uu] = example2(A,B,C,D,g,pf,pb,k,u,y);

yy = dlsim(A,B,C,D,uu,x0);

tt = [dt:dt:(k+q-1)*dt]'; 
y = y*(180/pi);
yy = yy*(180/pi);

figure(1)
subplot(2,1,1),plot(t,u(:,1),'--',tt,uu(:,1),'-')
axis([0 3 -4 4])
title(' 1 Input for q step = 50')
xlabel('Time (sec)')
legend('No control Input','Openloop Control Input')
subplot(2,1,2),plot(t,y(:,1),'--',tt,yy(:,1),'-')
axis([0 3 -1 +1])
title('  1 Output (q = 50) ')
xlabel('Time (sec)')
legend('No Control Output','Openloop Control Output')
hold on

%plot(t,y(:,1),'--',tt,yy(:,1),'-')
%axis([0 20 -10 +10])
%title('Control Output for using the Indirect Method (q step = 50) : CASE II')
%xlabel('Time (sec)')
%legend('Original Output','Control Output')
%hold on

%figure(4)
%plot(t,y(:,2),'--',tt,yy(:,2),'-')
%axis([0 20 -10 +10])
%title('Control Output for using the Indirect Method (q step = 50) : CASE III')
%xlabel('Time (sec)')
%legend('Original Output','Control Output')
%hold on
