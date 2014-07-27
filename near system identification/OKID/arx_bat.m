function [Y]=arxfrf(m,r,u,y,p,l);

Vf=zeros(p*(r+m)+r,l);
Vf(1:r,1:l)=u';

for i=1:p;
    	num1=r+1+(r+m)*(i-1);
	num2=2*r+(r+m)*(i-1);   
 	num3=2*r+1+(r+m)*(i-1);
    	num4=2*r+m+(r+m)*(i-1);
	Vf(num1:num2,i+1:l)=u(1:l-i,:)'	;
    	Vf(num3:num4,i+1:l)=y(1:l-i,:)';
end;
Y=y'*pinv(Vf);
