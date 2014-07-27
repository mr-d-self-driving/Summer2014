clear
k1=1.0;k2=2.0;k3=3.0;
m1=1.0;m2=1.0;m3=1.0;ratio=2*0.005;
K=[k1+k2  -k2   0 ;-k2 k2+k3 -k3;0   -k3   k3];
Khalf=sqrtm(K);
Damp=ratio*Khalf;
Ac=[zeros(3,3) eye(3,3);-K -Damp];
%Bc=[0 0;0 0;0 0;0 0;0 1;1 0];
%C=[zeros(1,5) 1];pb=0;pf=6;p=pf+pb;
Bc=[zeros(5,1);1];
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
y=dlsim(A,B,C,D,u,x0);
y=y+1.0*rand(pt,m);
%x0=[0;0;0;0;0;0];ic1=1;
%u2=randn(pt,r);
%y2=dlsim(A,B,C,D,u2,x0);%+0.0*rand(pt,m);
%y=[y y2];u=[u u2];
%f0=0.000;df=1/(2*dt*(pt-1));
%f=[f0:df:f0+df*(pt-1)]';
%ybar=arxm(m,r,u,y,pf,pb,[1 0]);
%frf=arxfrf(ybar,r,pb,f,dt);%+0.01*rand(pt,r*m);
%[a,b,c,d,g,x0]=idengine(m,r,dt,f,frf,'okid_fq',pf,pb,[0 1]);
%[a,b,c,d,g,x0]=idengine(m,r,dt,f,frf,'batch',pf,pb,[1 1]);
%[a,b,c,d,g,x0]=idengine(m,r,dt,f,frf,'lq',pf,pb,[0 1]);
%[a,b,c,d,g,x0]=idengine(m,r,dt,u,y,'batch_lq',pf,pb,[1 1]);
[a,b,c,d,g,x0]=idengine(m,r,dt,u,y,'batch_oc',pf,pb,[0 1 0]);
[a,b,c,d,g,x0]=idengine(m,r,dt,u,y,'batch_oc',pf,pb,[0 1 20]);
%deg2hz((eig(a+g(:,1:m)*c)),dt)
%[a,b,c,d,g,x0]=idengine(m,r,dt,u,y,'batch',pf,pb,[0 1 4]);
%[a,b,c,d,g,x0]=idengine(m,r,dt,u,y,'okid',pf,pb,[1 1 4]);
%[a,b,c,d,g,x0]=idengine(m,r,dt,u,y,'batch_lq',pf,pb,[1 1]);
%a+g(:,1:m)*c
deg2hz((eig(a+g(:,1:m)*c)),dt)
%deg2hz((eig(a+b(:,1:r)*g(:,2*m+1:2*m+r)')),dt)
