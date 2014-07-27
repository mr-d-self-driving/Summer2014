function yv=yxv(y,v,p)
%
%   Routine to compute the colleration matrix between 
%   parameter matrix y and data time histories v
%
%    function yv=yxv(y,v,p)
%
%    INPUT PARAMETERS
%      y  = parameter matrix (m X p*q) 
%      v  = data history (N X q) 
%      p  = number of time shifts for v & w
%
%    OUTPUT PARAMETERS  (see User's guide for explaination)
%      yv = (yV)'  (m X N) (correlation)
     
%         by Jer-Nan Juang  3-26-95
%         NASA SDB
[m,k]=size(y); [nd,q]=size(v);
v=v';
   if k/p~=q;
     disp(['Dimension Errors in the Input Matrices'])
     return;
   end; 
%
% Computation the first r rows of vwt=v*v^T
%
 yv=zeros(m,nd-p+1);
  for k=1:p;
      cy=(k-1)*q+1:k*q; 
      cv=p-k+1:nd+1-k;
      yv=yv+y(:,cy)*v(:,cv);
   end;
yv=yv';
