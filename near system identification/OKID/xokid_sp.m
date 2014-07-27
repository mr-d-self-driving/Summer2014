k1=1.0;k2=2.0;k3=3.0;
m1=1.0;m2=1.0;m3=1.0;ratio=2*0.005;
K=[k1+k2  -k2   0 ;-k2 k2+k3 -k3;0   -k3   k3];
Khalf=sqrtm(K);
Damp=ratio*Khalf;
%Damp(1,1)=-Damp(1,1);
Ac=[zeros(3,3) eye(3,3);-K -Damp];
%C=[zeros(1,5) 1];pf=6;pb=0;p=pf+pb;
%Bc=[zeros(3,1);1;1;1];
Bc=[0 0;0 0;0 0;0 0;1 0;0 1];
%C=Bc';pf=3;pb=0;p=pf+pb;
C=[0 0 0 1 0 0;0 0 0 0 1 0; 0 0 0 0 0 1];pf=2;pb=0;p=pf+pb;

format short e; format compact
dt=0.5;pt=1024;nb=20;
[m,n]=size(C);[n,r]=size(Bc);D=zeros(m,r);
[A,B]=c2d(Ac,Bc,dt);
clear Ac Bc;
u=[];
for k=1:nb;
  u=[u;rand(pt,r);zeros(3*pt,r)];%Berth random input signals
end;
y=dlsim(A,B,C,D,u);
[freq,HL,HH,SYU,SUU,SYY]=frffst(u,y,dt,4*pt,0,1,0);
  timer1 = clock;
[A1,B1,C1,D1]=okid_sp(r,freq,dt,HL,SUU,SYU,SYY,'batch1',p,0);
  timer2=etime(clock,timer1)/60;
  disp([' Time (min) ' num2str(timer2)]);

