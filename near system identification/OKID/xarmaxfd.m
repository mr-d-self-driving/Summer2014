k1=1.0;k2=2.0;k3=3.0;
m1=1.0;m2=1.0;m3=1.0;ratio=2*0.005;
K=[k1+k2  -k2   0 ;-k2 k2+k3 -k3;0   -k3   k3];
Khalf=sqrtm(K);
Damp=ratio*Khalf;
Ac=[zeros(3,3) eye(3,3);-K -Damp];
%C=[zeros(1,5) 1];pf=6;pb=0;p=pf+pb;
%Bc=[zeros(5,1);1];
Bc=[0 0;0 0;0 0;0 0;1 1;0 1];
C=[0 0 0 0 0 1;0 0 0 0 1 0; 0 0 0 1 0 0];pf=2;pb=0;p=pf+pb;

format short e; format compact
dt=1.0;pt=200;
[m,n]=size(C);[n,r]=size(Bc);D=zeros(m,r);
t=[dt:dt:pt*dt]';
[A,B]=c2d(Ac,Bc,dt);
clear Ac Bc;
ic1=0;
x0=[0;0;0;0;0;0];ic1=1;
u=randn(pt,r);
y=dlsim(A,B,C,D,u,x0);%+0.1*rand(pt,m);
f0=0.00;df=1/(2*dt*(pt-1));
f=[f0:df:f0+df*(pt-1)]';
ybar=armaxtd(m,r,u,y,pf,pb,[0 0 0]);
frf=arxfrf(ybar,r,pb,f,dt);
frf=frf+2*rand(size(frf));
yb=armaxfd(frf,f,dt,r,pf,pb,[0 1 4])

%q=r+m; n=pb*q+r; 
%pq=length(yb(1,:)); 
%err=yxvfd([yb(:,1:n) -eye(m,m) yb(:,n+1:pq)],frf,f,dt,r,pf,pb);
%norm(norm(err))
