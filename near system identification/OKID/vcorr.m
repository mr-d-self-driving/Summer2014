function vvt=vcorr(v,p)
%
%   Routine to compute data colleration matrix 
%   from data time histories
%
%    function vvt=vcorr(v,p)
%
%    INPUT PARAMETERS
%      v  = data history (n X r); 
%      p  = number of time shifts for correlation
%
%    OUTPUT PARAMETERS  (see User's guide for explaination)
%      vvt = [V][V]^T  (data correlation)
     
%         by Jer-Nan Juang  3-23-95
%         NASA SDB
[nd,q]=size(v);
v=v';
%
% Computation the first q rows of vvt=v*v^T
%
 vvt=zeros(p*q,p*q);
  for j=1:p;
      cj=(j-1)*q+1:j*q;
      c2=p-j+1:nd+1-j;
      vvt(1:q,cj)=v(:,p:nd)*v(:,c2)';
      vvt(cj,1:q)=vvt(1:q,cj)';
%
%  Efficient Computation for the second q rows and up
%
	    ri1=1:q; cj1=cj; 
	    i0=p; id=nd+1;
	    j0=p-j+1; jd=nd+2-j;
	  for k=j+1:p;
	        ri1=ri1+q; cj1=cj1+q;
		    i0=i0-1; id=id-1;
		    j0=j0-1; jd=jd-1;
		  vvt(ri1,cj1)=vvt(ri1-q,cj1-q)+v(:,i0)*v(:,j0)'-v(:,id)*v(:,jd)';
		  vvt(cj1,ri1)=vvt(ri1,cj1)';
	  end;
   end;
