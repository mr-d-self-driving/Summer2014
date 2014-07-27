k1=1.0;k2=2.0;k3=3.0;
m1=1.0;m2=1.0;m3=1.0;ratio=2*0.005;
K=[k1+k2  -k2   0 ;-k2 k2+k3 -k3;0   -k3   k3];
Khalf=sqrtm(K);
Damp=ratio*Khalf;
Ac=[zeros(3,3) eye(3,3);-K -Damp];
%C=[zeros(1,5) 1];p=6;
%Bc=[zeros(5,1);1];
Bc=[zeros(3,2);0 0; 1 0; 0 1];
C=[zeros(3,3) eye(3,3)];p=2;

format short e; format compact
dt=1.0;pt=600;
[m,n]=size(C);[n,r]=size(Bc);D=eye(m,r);
t=[dt:dt:pt*dt]';
[A,B]=c2d(Ac,Bc,dt);
clear Ac Bc;

u=randn(pt,r);x0=[0;0;0;0;0;0];
y=dlsim(A,B,C,D,u,x0);

%vvt=vcorr(y,p)
 timer1 = clock;
[vst]=uy_stack(u,y,p);[q,nd]=size(vst);
vst=vst(r+1:q,2:nd);[q,nd]=size(vst);
vvt1=vst*vst';
timer2=etime(clock,timer1)/60;
disp([' Time (min) to compute observer parameters ' num2str(timer2)])
y=y(1:pt-1,:); u=u(1:pt-1,:);
 timer1 = clock;
u=[zeros(p,r);u]; y=[zeros(p,m);y];
vvt=vcorr([u y],p);
timer2=etime(clock,timer1)/60;
disp([' Time (min) to compute observer parameters ' num2str(timer2)])
timer1 = clock;
vvt1-vvt
