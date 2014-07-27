clg
clear
k1=1.0;k2=2.0;k3=3.0;
m1=1.0;m2=1.0;m3=1.0;ratio=2*0.005;
K=[k1+k2  -k2   0 ; -k2 k2+k3 -k3; 0   -k3   k3];
Khalf=sqrtm(K);
Damp=ratio*Khalf;
Ac=[zeros(3,3) eye(3,3);-K -Damp];
Bc=[zeros(3,2);0 0; 0 1; 1 0];
%Bc=[0;0; 0;0; 0;1];
%Bc=[zeros(3,3);eye(3,3)];
%C=[zeros(3,3) eye(3,3)];pf=2;pb=0;p=pf+pb;
%C=[0 0 0 0 0 1];pf=6;pb=0;p=pf+pb;
C=[0 0 0 0 0 1;0 0 0 0 1 0];pf=3;pb=0;p=pf+pb;
clear k1 k2 k3 m1 m2 m3 ratio khalf Damp;

format short e; format compact
dt=1.0;pt=1000;pt1=100;
[m,n]=size(C);[n,r]=size(Bc);D=zeros(m,r);
n_order=p*m;
t=[dt:dt:pt*dt]';
[A,B]=c2d(Ac,Bc,dt);
%clear Ac Bc;
[K,S,E]=dlqr(A,B,eye(size(A)),eye(r));
%eigc=deg2hz(eig(A-B*K),dt)
u=randn(pt,r);
y=dlsim(A,B,C,D,u);
subplot(211); plot(y)
[y1,x]=dlsim(A-B*K,B,C,D,u);
%y1=y1+0.01*randn(pt,m);
uf=-x*K';
subplot(212); plot(y1)
%y=dlsim(A,B,C,D,u+uf);
%plot([y y1]);


[yi,yo]=pulse(m,r,u,y,pf,pb,pt1,[0 0]);

%[a,b,c,d,g,eg,mh]=era(yi,0,r,6,p,dt);
%[a,b,c,d,g,eg,mh]=era(yi,[0 1 0 0],r,n_order,p,dt);
%[a,b,c,d,g,eg,mh]=era(yi,[1 1 1 0],r,n_order,p,dt);
%[a,b,c,d,g,eg,mh]=era([yi yo],[1 2 1 m],r+m,n_order,p,dt);
%[a,b,c,d,g,eg,mh]=eradc(yi,0,r,n_order,p,dt);
%[a,b,c,d,g,eg,mh]=eradc(yi,[0 1 1 0],r,n_order,p,dt);
%[a,b,c,d,g,eg,mh]=eradc([yi yo],[1 1 1 m],r+m,n_order,p,dt);
[a,b,c,d,g,eg,mh]=eradc([yi yo],[1 2 0 m],r+m,n_order,p,dt);
deg2hz((eig(a-b(:,1:r)*g(:,m+1:r+m)')),dt)
deg2hz((eig(a+g(:,1:m)*c)),dt)
deg2hz((eig(a+b(:,r+1:r+m)*c)),dt)

break;
n_markov=100;
[ybar]=arxc(y1,uf,u,p);
markovp=marcomc(ybar,m,r,n_markov);
  q=r+m;
  p1=ceil(p*m/q);
  ps=m2p(markovp,r+m);clear markovp; 
  [a,b,c,d,gp,eg,mh]=eradc(ps,[0 1 0 m],r+m,n_order,p,dt);
  g=b(:,r+1:q); b=b(:,1:r);
  f=-c(m+1:q,:);c=c(1:m,:);d=d(1:m,1:r);
deg2hz((eig(a-b*gp(:,m+1:r+m)')),dt)
deg2hz((eig(a+gp(:,1:m)*c)),dt)
deg2hz((eig(a-b*f)),dt)
deg2hz((eig(a+g*c)),dt)

