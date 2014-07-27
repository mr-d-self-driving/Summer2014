k1=1.0;k2=2.0;k3=3.0;
m1=1.0;m2=1.0;m3=1.0;ratio=2*0.005;
K=[k1+k2  -k2   0 ;-k2 k2+k3 -k3;0   -k3   k3];
Khalf=sqrtm(K);
Damp=ratio*Khalf;
Ac=[zeros(3,3) eye(3,3);-K -Damp];
%Bc=[zeros(3,2);0 0; 1 0; 0 1];
C=[zeros(1,5) 1];pf=6;pb=0;p=pf+pb;
Bc=[zeros(5,1);1];
%C=[zeros(3,3) eye(3,3)];pf=1;pb=1;p=pf+pb;
%C=[zeros(3,2);0 0; 0 1; 1 0]';pf=3;pb=0;p=pf+pb;

format short e; format compact
dt=1.0;pt=1000;p=2;
[m,n]=size(C);[n,r]=size(Bc);D=eye(m,r);
t=[dt:dt:pt*dt]';
[A,B]=c2d(Ac,Bc,dt);
clear Ac Bc;

u=randn(pt,r);
y=dlsim(A,B,C,D,u);
y=y+1*randn(pt,m);
%u1=rand(pt,r);
%y1=dlsim(A,B,C,D,u1);
%u2=rand(pt,r);u=[u u1]; y=[y y1];
%y2=dlsim(A,B,C,D,u2); u=[u u2];y=[y y2];
clg
ybar=armaxtd(m,r,u,y,pf,pb,[0 0]);
ys=marcomp(ybar,pb,r,7,0); 
%q=m+r;[i,nd]=size(ybar);
%yso=marcomp(ybar,pb,r,5,0) 
%ybar1=[ybar(:,1:pb*q+r) -eye(m,m) ybar(:,pb*q+r+1:nd)];
%[ys,yo]=separate(ybar1,m,r,m);yo(:,pb*m+1:pb*m+m)=[];

%ybar1=armaxtd(m,r,u,y,pf,pb,[0 0 0]);
%ys1=marcomp(ybar1,pb,r,7,0) 
ybar1=armaxtd(m,r,u,y,pf,pb,[0 0 5]);
ys1=marcomp(ybar1,pb,r,7,1);
ys-ys1

%[a,b,c,d,g]=ocompan(ybar,pb,r,dt);
%[D C*B C*A*B C*A*A*B C*A*A*A*B]
%ys
%[d c*b c*a*b c*a*a*b c*a*a*a*b]
%yo
%[c*g c*a*g c*a*a*g c*a*a*a*g]
