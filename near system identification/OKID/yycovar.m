function [yvt,vvt]=yycovar(y,p,iexp)
% 
%         Routine to compute covariance matrices
%         from output histories
%         
%    [yvt,ubar]=yycovar(y,p,iexp)
%
%   INPUT PARAMETERS 
%    y    = output data
%    p    = an integer (assumed number of modes=p*no. of outputs)
%    iexp = flag set to 0 when experiments start from rest  
%           otherwise when experiments start with initial conditions
%
%   OUTPUT PARAMETERS  (see User's guide for explaination)
%    yvt = y*V^T 
%    vvt = V*V^T  

%         Jer-Nan Juang  8-2-91, modified 3-24-95
%         NASA Spacecraft Dynamics Branch      
[nd,m]=size(y);
p1=p+1;
 vvt=zeros(p1*m,p1*m);
 if iexp==0;
	vvt=vcorr([zeros(p,m);y],p1);
  else;
    vvt=vcorr(y,p1);
  end;
k=1:m;
vvt(:,k)=[];yvt=vvt(k,:);vvt(k,:)=[]; 

    
