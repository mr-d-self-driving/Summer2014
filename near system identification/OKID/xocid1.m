%
%           Identification routine demonstration using real
%           test data from an aircraft flutter test data.
%
load samp712 
ue(1:600)=[];y(1:600)=[];u(1:600)=[];
[nd,r]=size(ue);[nd,m]=size(y);p=30;
time=dt*[0:500-1]';
%[a,b,c,d,g,x0]=idengine(m,r,dt,ue-u,y,'ocid',30,0,[1 0]);
%deg2hz((eig(a+g(:,1:m)*c)),dt)
%deg2hz((eig(a+b(:,1:r)*g(:,2*m+1:2*m+r)')),dt)
[a,b,c,d,g,f]=ocid(ue,-u,y,dt,'ocid',p);
%[a,b,c,d,g,f]=ocid(ue,-u,y,dt,'lq',p);
%[a,b,c,d,g,f]=ocid(ue,-u,y,dt,'batch_lq',p);
%[a,b,c,d,g,f]=ocid(ue,-u,y,dt,'batch',p);
eigc=deg2hz(eig(a-b*f),dt)
eigo=deg2hz(eig(a+g*c),dt)

