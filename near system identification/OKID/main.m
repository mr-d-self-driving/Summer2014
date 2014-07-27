% ****************************************************
% Written by J.R. Yim.
% Modified on November 11, 1997
% For example of numerical calculation
% ****************************************************
clear all
global A B C D Ac Bc p q m n r dt u
randn('seed',5)

% Initial Condition 
m1= 1; m2= 1; m3= 1; k1= 1000; k2= 1000;  k3= 1000; 
z1 = 0.1; z2 = 0.1;  z3 = 0.1;  
M = [m1 0 0; 0 m2 0; 0 0 m3];
Z =  [z1+z2 -z2 0; -z2 z2+z3 -z3; 0 -z3 z3];
K = [k1+k2 -k2 0; -k2 k2+k3 -k3; 0 -k3 k3];
Cd = [0 0 0]; Cv = [0 0 0]; Ca = [0 0 1];
%Cd = [0 0 0;0 0 0]; Cv = [0 0 0;0 0 0]; Ca = [0 0 1; 0 1 0];
%Cd = [0 0 0;0 0 0;0 0 0]; Cv = [0 0 0; 0 0 0;0 0 0]; Ca = [0 0 1; 0 1 0; 1 0 0];
%B2 = [ 1 0; 0 1; 0 0];
B2 = [1; 0; 0];
Ac = [zeros(3) eye(3); -inv(M)*K -inv(M)*Z];
Bc = [ 0; 0; 0; inv(M)*B2];
%Bc = [zeros(3,2); inv(M)*B2];
%Bc = [ 0 0; 0 0; 0 0; 1 0; 0 1; 0 0]
C = [ Cd-Ca*inv(M)*K Cv-Ca*inv(M)*Z];
D = [Ca*inv(M)*B2];
dt = 0.2;
[A, B] = c2d(Ac,Bc,dt);

pf = 6; pb=0; p = pf+pb; q = 6 ; pt = 100;

%format short e; format compact
format long e; format compact

[m,n] = size (C); [n,r] = size(Bc);
t = [dt:dt:pt*dt]';  % time step size

%clear Ac Bc;

u = randn(pt,r) ;
x0 = [0 0 0 0 0 0]'; ic1 = 1;
%x0 = [1 1 1 1 1 1]'; ic1 = 1;

[y, x] = dlsim(A,B,C,D,u,x0);
%pt1 = 100;
%n_order=p*m;
%[yi,yo]=pulse(m,r,u,y,pf,pb,pt1,[0 0]);
%[AA,BB,CC,DD,GG,eg,mh]=eradc([yi yo],[1 2 0 m],r+m,n_order,p,dt);

value = eig(A);
%clear A B C D

%[A,B,C,D,G,x0]=okid(m,r,dt,u,y,'batch',p);
value2 = eig(A);
g=deadbeat(A,B,C,D) ;

k=50;

[uu] = example1(A,B,C,D,g,pf,pb,k,u,y,x);
%[uu] = disturb(A,B,C,D,g,pf,pb,k,u,y,x);
%[uu] = example2(A,B,C,D,g,pf,pb,k,u,y);

yy = dlsim(A,B,C,D,uu,x0);

tt = [dt:dt:(k+q-1)*dt]'; 

%np=200;
%dt=1/(.025*np);
%f=logspace(-1,1,np);
%w=f*2*pi;
%Gz=freqresp(A,B,C,D,1,exp(sqrt(-1)*w*dt));
%[Gz_id]=frfm(A,B,C,D,Gz,f,dt,np,1);


figure(1)
subplot(2,1,1),plot(t,u(:,1),'--',tt,uu(:,1),'-')
axis([0 25 -4 4])
title(' 2 Input for q step = 50')
xlabel('Time (sec)')
legend('No control Input','Openloop Control Input')

%subplot(2,1,2),plot(t,u(:,2),'--',tt,uu(:,2),'-')
%axis([0 25 -3 3])
%%title('Disturbance Input for using Indrect Method (q step = 30) : CASE II')
%xlabel('Time (sec)')
%legend('No control Input','Openloop Control Input')
%hold on

%figure(2)
subplot(2,1,2),plot(t,y(:,1),'--',tt,yy(:,1),'-')
axis([0 25 -10 +10])
title('  2 Output (q = 50) ')
xlabel('Time (sec)')
legend('No Control Output','Openloop Control Output')
%subplot(2,1,2),plot(t,y(:,2),'--',tt,yy(:,2),'-')
%axis([0 25 -10 +10])
%title('Output')
%xlabel('Time (sec)')
%legend('No Control Output','Openloop Control Output')
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
