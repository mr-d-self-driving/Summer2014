k1=1.0;k2=2.0;k3=3.0;
m1=1.0;m2=1.0;m3=1.0;ratio=2*0.005;
K=[k1+k2  -k2   0 ; -k2 k2+k3 -k3; 0   -k3   k3];
Khalf=sqrtm(K);
Damp=ratio*Khalf;
Ac=[zeros(3,3) eye(3,3);-K -Damp];
Bc=[zeros(3,2);1 0; 0 1; 0 0];
C=[zeros(1,5) 1];
%Bc=[zeros(5,1);1];
%C=[zeros(2,4) eye(2,2)];
%C=[zeros(3,3) eye(3,3)];
clear k1 k2 k3 m1 m2 m3 ratio Khalf Damp;

dt=1.0;pt=200;pf=10;pb=0;
[m,n]=size(C);[n,r]=size(Bc);
D=zeros(m,r);
t=[dt:dt:pt*dt]';
[A,B]=c2d(Ac,Bc,dt);
clear Ac Bc;
yp=[];
for i=1:r;
 yp=[yp dimpulse(A,B,C,D,i,pt)];
end;
clg
u=randn(pt,r);
y=dlsim(A,B,C,D,u);
[ys,yo]=pulse(m,r,u,y,pf,pb,pt,[0 0]);
subplot(211), plot(yp);
subplot(212), plot(ys);
pause;clg;
err=norm(yp-ys)


