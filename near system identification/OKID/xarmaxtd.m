clear all
randn('seed',5)
k1=1.0;k2=2.0;k3=3.0;
m1=1.0;m2=1.0;m3=1.0;ratio=2*0.005;
K=[k1+k2  -k2   0 ;-k2 k2+k3 -k3;0   -k3   k3];
Khalf=sqrtm(K);
Damp=ratio*Khalf;
Ac=[zeros(3,3) eye(3,3);-K -Damp];
Bc=[zeros(3,2);0 0; 1 0; 0 1];
%C=[zeros(1,5) 1]; pf=6; pb=0; p=pf+pb;
%Bc=[zeros(4,1);0;1];
%C=[zeros(3,3) eye(3,3)];  pf=2; pb=0; p=pf+pb;
%C=[zeros(3,2);0 0; 1 0; 0 1]';pf=3;pb=0;p=pf+pb;
C=[zeros(3,2);0 0; 1 0; 0 1]';pf=3;pb=0;p=pf+pb;

format short e; format compact
dt=1.0;pt=200;
[m,n]=size(C);[n,r]=size(Bc);D=eye(m,r);
t=[dt:dt:pt*dt]';
[A,B]=c2d(Ac,Bc,dt);
clear Ac Bc;

u=randn(pt,r);
y=dlsim(A,B,C,D,u);
u1=randn(pt,r);
y1=dlsim(A,B,C,D,u1);
u=[u u1]; y=[y y1];
u2=randn(pt,r);
y2=dlsim(A,B,C,D,u2); u=[u u2];y=[y y2];
y=y+0.5*randn(size(y));
clg
%ybar1=armaxtd(m,r,u,y,pf,pb,[1 1 10])

ybar1=armaxtd(m,r,u,y,pf,pb,[0 0 1])
