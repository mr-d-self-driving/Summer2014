function [Ybar]=arxc(y,u,v,p)

timer1=clock;
[N,m]=size(y); [N,r]=size(u);
v=u+v;
[yVt,VVt]=yucov(v,y,p,0,1);
uVt=u(p+1:N,:)'*v(p+1:N,:);
for i=1:p;
uVt=[uVt u(p+1:N,:)'*[v(p-i+1:N-i,:) y(p-i+1:N-i,:)]];
end;
Ybar=[yVt;uVt]*pinv(VVt);
timer2=etime(clock,timer1)/60;
disp(['Time (min) to compute observer parameters ' num2str(timer2)])
