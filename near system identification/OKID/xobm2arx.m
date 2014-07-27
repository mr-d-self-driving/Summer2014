k1=1.0;k2=2.0;k3=3.0;
m1=1.0;m2=1.0;m3=1.0;ratio=2*0.005;
K=[k1+k2  -k2   0 ;-k2 k2+k3 -k3;0   -k3   k3];
Khalf=sqrtm(K);
Damp=ratio*Khalf;
Ac=[zeros(3,3) eye(3,3);-K -Damp];
Bc=[0 0;0 0;0 0;0 0;1 0;0 1];
C=[zeros(1,5) 1];pb=0;pf=6;
%Bc=[zeros(5,1);1];
%C=[0 0 0 0 0 1;0 0 0 0 1 0; 0 0 0 1 0 0];pf=6;pb=0;

format short e; format compact
dt=1.0;pt=100;
[m,n]=size(C);[n,r]=size(Bc);D=zeros(m,r);
t=[dt:dt:pt*dt]';
[A,B]=c2d(Ac,Bc,dt);
%clear Ac Bc;
ic1=0;
x0=[0;0;0;0;0;0];ic1=1;
u=randn(pt,r);
y=dlsim(A,B,C,D,u,x0);%+0.1*rand(pt,m);
%x0=[0;0;0;0;0;0];ic1=1;
%u2=randn(pt,r);
%y2=dlsim(A,B,C,D,u2,x0);%+0.1*rand(pt,m);
%y=[y y2];u=[u u2];
f0=0.000;df=1/(2*dt*(pt-1));
f=[f0:df:f0+df*(pt-1)]';
%ybar=armaxtd(m,r,u,y,pf,pb,[0 0]);
%frf=arxfrf(ybar,r,pb,f,dt);
pf=6;pb=0;
timer1 = clock;
 [ybar1]=obm2arx(A,B,C,D,[],pf,pb)
  frf1=arxfrf(ybar1,r,pb,f,dt)
timer2=etime(clock,timer1)/60;
disp([' Time (min) to compute frf1 ' num2str(timer2)]);
   timer1 = clock;
		z=exp(j*2*pi*dt*f);
		y_e=[];
        for i=1:r
           frf=freqresp(A,B,C,D,i,z);
           y_e=[y_e frf];
        end;
   timer2=etime(clock,timer1)/60;
   disp([' Time (min) to y_e ' num2str(timer2)]);
[frf1(1:10,1)-y_e(1:10,1)]
%[abs(frf1(1:5,1)) abs(y_e(1:5,1))]
