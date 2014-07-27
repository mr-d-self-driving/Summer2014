clear

k1=1.0;k2=2.0;k3=3.0;
m1=1.0;m2=1.0;m3=1.0;ratio=2*0.005;
K=[k1+k2  -k2   0 ;-k2 k2+k3 -k3;0   -k3   k3];
Khalf=sqrtm(K);
Damp=ratio*Khalf;
Ac=[zeros(3,3) eye(3,3);-K -Damp];
Bc=[zeros(3,2);0 0; 1 0; 0 1];
%C=[zeros(1,5) 1];p=8;
%Bc=[zeros(5,1);1];
C=[zeros(3,3) eye(3,3)];p=2;

format short e; format compact
dt=1.0;pt=300;
[m,n]=size(C);[n,r]=size(Bc);D=eye(m,r);
t=[dt:dt:pt*dt]';
[A,B]=c2d(Ac,Bc,dt);
clear Ac Bc;

u=randn(pt,r);x0=[0;0;0;0;0;0];
y=dlsim(A,B,C,D,u,x0);
%u1=randn(pt,r);
%y1=dlsim(A,B,C,D,u1);u=[u u1];y=[y y1];
%u2=randn(pt,r);
%y2=dlsim(A,B,C,D,u2);u=[u u2];y=[y y2];
y=y+0.5*randn(size(y));

clg
plot(t,y);
%[a,b,c,d,G]=okid(m,r,dt,u,y,'oc',p,x0);
%[a,b,c,d,G]=okid(m,r,dt,u,y,'okid',p);
%[a,b,c,d,G]=okid(m,r,dt,u,y,'batch_lq',p);
%[a,b,c,d,G]=okid(m,r,dt,u,y,'lq',p);
%[a,b,c,d,G]=okid(m,r,dt,u,y,'batch_oc',p)
[a,b,c,d,G]=okid_b(m,r,dt,u,y,'batch',p)
%[a,b,c,d,G]=okid_b(m,r,dt,u,y,'okid',p);
%[a,b,c,d,G]=okid_w(m,r,dt,u,y,'batch_oc',p,8);
%[a,b,c,d,G]=okid_w(m,r,dt,u,y,'batch',p,8);
%[a,b,c,d,G]=okid_w(m,r,dt,u,y,'okid_w',p,8);
deg2hz(eig(a+G*c),dt)
