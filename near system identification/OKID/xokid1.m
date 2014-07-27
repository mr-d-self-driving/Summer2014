%
%           Identification routine demonstration using real
%           test data from a 10-Bay truss structure.
%
load sample
[a,b,c,d,g]=okid_w(n,r,dt,u,y,'bat',15,5);
%[a,b,c,d,g]=okid(n,r,dt,u,y,'batch',10);
%[a,b,c,d,g]=okid(n,r,dt,u,y,'okid',10);
%[y_p]=yog_cal(a,b,c,d,0,u,0,y,dt,1000,1);
%[y_e]=yog_cal(a,b,c,d,g,u,0,y,dt,1000,1);
%[a,b,c,d,g]=okid_b(n,r,dt,u,y,'batch',10);%Backward-time
%[y_p]=yog_cal(a,b,c,d,0,u,0,y,dt,1000,1);
%[y_e]=yog_cal(a,b,c,d,g,u,0,y,dt,1000,1);
%[a,b,c,d,g]=okid_b(n,r,dt,u,y,'backward',10);%Backward-time
%[y_p]=yog_cal(a,b,c,d,0,u,0,y,dt,1000,1);
%[y_e]=yog_cal(a,b,c,d,g,u,0,y,dt,1000,1);
%[a,b,c,d,g,x0]=idengine(n,r,dt,u,y,'backward',0,10,[1 1]);
%deg2hz((eig(a+g(:,1:n)*c)),dt)
%deg2hz((eig(a+g(:,n+1:n+n)*c)),dt)
%deg2hz((eig(a+b(:,1:r)*g(:,2*n+1:2*n+r)')),dt)
			
