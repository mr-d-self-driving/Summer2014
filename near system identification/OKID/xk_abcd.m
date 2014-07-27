%
%           Identification routine demonstration using real
%           test data from a 10-Bay truss structure.
%
load sample
[pt,i]=size(u);
p=10;
[a,b,c,d,m]=okid(n,r,dt,u,y,'batch',p);
%y_p=yog_cal(a,b,c,d,0,u,0,y,dt,pt,0);
y_e=yog_cal(a,b,c,d,m,u,0,y,dt,pt,0);
[m1,Cake]=k_abcd(a,b,c,d,u,y,p);
y_e1=yog_cal(a,b,c,d,m1,u,0,y,dt,pt,1);
res=y-y_e;
[yvt, vvt]=yycovar(res,3,1);
vvt
res=y-y_e1;
[yvt, vvt1]=yycovar(res,3,1);
vvt1
