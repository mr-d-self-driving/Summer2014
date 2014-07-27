clear;
k1=1.0;k2=2.0;k3=3.0;
m1=1.0;m2=1.0;m3=1.0;ratio=2*0.005;
K=[k1+k2  -k2   0 ;-k2 k2+k3 -k3;0   -k3   k3];
Khalf=sqrtm(K);
Damp=ratio*Khalf;
Ac=[zeros(3,3) eye(3,3);-K -Damp];
%Bc=[zeros(3,2);0 0; 1 0; 0 1];
C=[zeros(1,5) 1];pf=0;pb=20;
Bc=[zeros(5,1);1];
%C=[zeros(3,3) eye(3,3)];pf=0;pb=10;

format short e; format compact
dt=1.0;pt=100;
[m,n]=size(C);[n,r]=size(Bc);D=eye(m,r);
[A,B]=c2d(Ac,Bc,dt);
clear Ac Bc;

u=randn(pt,r);
y=dlsim(A,B,C,D,u);
y=dlsim(A,B,C,D,u)+0.1*randn(pt,m);

ybar=armaxtd(m,r,u,y,pf,pb,[0 0]);
%[a,b,c,d,g,xt]=ocompan(ybar,pb,r,dt,0);
[a,b,c,d,g,xt]=ocompan(ybar,pb,r,dt,[1 1]);
%[D C*B C*A*B C*A*A*B C*A*A*A*B]
%[d c*b c*a*b c*a*a*b c*a*a*a*b]
%(a+g*c)^3
deg2hz(eig(a+g*c),dt)
