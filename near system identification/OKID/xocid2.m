clear
k1=1.0;k2=2.0;k3=3.0;
m1=1.0;m2=1.0;m3=1.0;ratio=2*0.005;
K=[k1+k2  -k2   0 ;-k2 k2+k3 -k3;0   -k3   k3];
Khalf=sqrtm(K);
Damp=ratio*Khalf;
Ac=[zeros(3,3) eye(3,3);-K -Damp];
Bc=[zeros(3,2);0 0; 1 0; 0 1];
C=[zeros(1,5) 1];p=6;
Bc=[zeros(5,1);1];
C=[zeros(3,3) eye(3,3)];p=5;

format short e; format compact
dt=1.0;pt=100;
[m,n]=size(C);[n,r]=size(Bc);D=zeros(m,r);
t=[dt:dt:pt*dt]';
[A,B]=c2d(Ac,Bc,dt);
clear Ac Bc;
[K,S,E]=dlqr(A,B,eye(size(A)),eye(r));
%eigc=deg2hz(eig(A-B*K),dt)
u=randn(pt,r);
u=zeros(pt,r);u(1,1)=1;
y=dlsim(A,B,C,D,u);
[y1,x]=dlsim(A-B*K,B,C,D,u);
%y1=y1+0.01*randn(pt,m);
uf=-x*K';



%y=dlsim(A,B,C,D,u+uf);
%plot([y y1]);

%[a,b,c,d,g,f]=ocid(u,uf,y1,dt,'batch',p);
[a,b,c,d,g,f]=ocid(u,uf,y1,dt,'batch_lq',p);
eigc=deg2hz(eig(A-B*K),dt)
eigc=deg2hz(eig(a-b*f),dt)
eigo=deg2hz(eig(a+g*c),dt)
y2=dlsim(a-b*f,b,c,d,u);

subplot(411); plot(y(:,1))
subplot(412); plot(y1(:,1))
subplot(413); plot(y2(:,1));
subplot(414); plot(t,[y(:,1) y1(:,1) y2(:,1)]);

[y y1 y2]


break;
%[a,b,c,d,g]=okid(m,r,dt,u+uf,y1,'batch',p);
%eigc=deg2hz(eig(A-B*K),dt)
%eigc=deg2hz(eig(a-b*f),dt)
%eigc=deg2hz(eig(a+g*c),dt)
%  [D C*B C*A*B C*A^2*B C*A^3*B C*A^4*B C*A^5*B]
H0=[c; -f];H=H0*[b g];
for k=1:5; 
 H0=H0*a; H=[H H0*[b g]];
end;
H
[a,b,c,d,g,f]=ocid(u,uf,y1,dt,'batch',p);
eigc=deg2hz(eig(a-b*f),dt)
eigc=deg2hz(eig(a+g*c),dt)


