k1=1.0;k2=2.0;k3=3.0;
m1=1.0;m2=1.0;m3=1.0;ratio=2*0.005;
K=[k1+k2  -k2   0 ;-k2 k2+k3 -k3;0   -k3   k3];
Khalf=sqrtm(K);
Damp=ratio*Khalf;
Ac=[zeros(3,3) eye(3,3);-K -Damp];
Bc=[zeros(3,2);0 0; 1 0; 0 1];
%C=[zeros(1,5) 1];pb=3;pf=3;p=pf+pb;
%Bc=[zeros(5,1);1];
C=[zeros(3,3) eye(3,3)];pb=1;pf=1;p=pf+pb;

format short e; format compact
dt=1.0;pt=300;
[m,n]=size(C);[n,r]=size(Bc);D=eye(m,r);
t=[dt:dt:pt*dt]';
[A,B]=c2d(Ac,Bc,dt);
clear Ac Bc;

u=randn(pt,r);x0=[0;0;0;0;0;0];
y=dlsim(A,B,C,D,u,x0);

%[vst]=uy_stack(u,y,p);
%vst=vst*vst'
[ybar,ubar]=yucov(u,y,pf,pb,0);
