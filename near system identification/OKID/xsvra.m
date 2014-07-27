a=[0 1;-1 -0.2]; b=[0;1];c=[1 0];d=0;
pt=100;dt=0.4;t=[dt:dt:dt*pt]';
u=randn(pt,1);
[a,b]=c2d(a,b,dt);
y=dlsim(a,b,c,d,u);
[a1,b1,c1,d1,sg,eg]=svra(u,y,2,20,40,dt,10);
y1=dlsim(a1,b1,c1,d1,u);
y2=[y y1];
clg
plot(y2),title('Random input response')
pause
error=y-y1;
clg
plot(error),title('Error')
