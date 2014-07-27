function [yvt,vvt]=yucov(u,y,pf,pb,iexp)
%
%   Routine to compute forward and backward covariance 
%   matrices from input and output time histories
%
%    funtion [yvt,vvt]=yucov(u,y,pf,pb,iexp)
%
%    INPUT PARAMETERS
%      u  = input time history (n X r); n = no. of data, r=no. of inputs 
%      y  = output time history (n X m); m = no. of outputs 
%      pf  = number of forward-in-time steps
%      pb  = number of backward-in-time steps
%   iexp  = Flag set to 0 when experiments starts from rest       
%           Otherwise when experiments starts with some initial conditions
%
%    OUTPUT PARAMETERS  (see User's guide for explaination)
%      yvt = y*V^T     (output correlation)
%      vvt = [V][V]^T  (input and output correlation)
     
%         by Jer-Nan Juang  11-29-94 modified 2-4-95
%         NASA SDB
[nd,r]=size(u);
[nd,m]=size(y);
p=pf+pb; q=m+r;
 p1=p+1;
% vvt=zeros(p1*q,p1*q);
 if iexp==0;
	vvt=vcorr([zeros(pf,q);u y],p1);
  else;
    vvt=vcorr([u y],p1);
  end;
k=(pb*q)+r+1:(pb+1)*q;
vvt(:,k)=[];yvt=vvt(k,:);vvt(k,:)=[]; 
