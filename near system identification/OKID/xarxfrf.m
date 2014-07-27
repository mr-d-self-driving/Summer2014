k1=1.0;k2=2.0;k3=3.0;
m1=1.0;m2=1.0;m3=1.0;ratio=2*0.005;
K=[k1+k2  -k2   0 ;-k2 k2+k3 -k3;0   -k3   k3];
Khalf=sqrtm(K);
Damp=ratio*Khalf;
Ac=[zeros(3,3) eye(3,3);-K -Damp];
%C=[zeros(1,5) 1];pf=3;pb=3;p=pf+pb;
%Bc=[zeros(5,1);1];
Bc=[0 0;0 0;0 0;0 0;1 1;0 1];
C=[0 0 0 0 0 1;0 0 0 0 1 0; 0 0 0 1 0 0];pf=1;pb=1;p=pf+pb;

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
%x0=[0;0;0;0;0;0];ic1=1;
%u2=randn(pt,r);
%y2=dlsim(A,B,C,D,u2,x0);%+0.1*rand(pt,m);
%y=[y y2];u=[u u2];
f0=0.00;df=1/(2*dt*(pt-1));
f=[f0:df:f0+df*(pt-1)]';
ybar=armaxtd(m,r,u,y,pf,pb,[0 0])
%frf1=arxfrf(ybar1,r,pb,f,dt);
%[a,b,c,d,g]=okid_fd(r,f,dt,frf,'batch',p);
%pf=6;pb=0;
%[qr]=obm2arx(a,b,c,d,g,pf,pb);
%frf1=arxfrf(qr,r,pb,f,dt);
%[frf(1:5,1) frf1(1:5,1)]
