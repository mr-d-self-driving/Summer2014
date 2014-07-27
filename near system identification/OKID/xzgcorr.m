k1=1.0;k2=2.0;k3=3.0;
m1=1.0;m2=1.0;m3=1.0;ratio=2*0.005;
K=[k1+k2  -k2   0 ;-k2 k2+k3 -k3;0   -k3   k3];
Khalf=sqrtm(K);
Damp=ratio*Khalf;
Damp(1,1)=-Damp(1,1);
Ac=[zeros(3,3) eye(3,3);-K -Damp];
C=[zeros(1,5) 1];pf=6;pb=0;p=pf+pb;
Bc=[zeros(5,1);1];
%Bc=[0 0;0 0;0 0;0 0;1 1;0 1];
%C=Bc';pf=3;pb=0;p=pf+pb;
C=[0 0 0 0 0 1;0 0 0 0 1 0; 0 0 0 1 0 0];pf=2;pb=0;p=pf+pb;

format short e; format compact
dt=1.0;pt=100;
[m,n]=size(C);[n,r]=size(Bc);D=zeros(m,r);
t=[dt:dt:pt*dt]';
[A,B]=c2d(Ac,Bc,dt);
clear Ac Bc;
f0=0.00;df=1/(2*dt*(pt-1));
f=[f0:df:f0+df*(pt-1)]';

[a1,b1,c1,d1]=unsb2sb(A,B,C,D,f,dt,[0 0 1]);

