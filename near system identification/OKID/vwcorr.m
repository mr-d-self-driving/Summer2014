function vwt=vwcorr(v,w,p)
%
%   Routine to compute data colleration matrix 
%   from data time histories v & w
%
%    function vwt=vwcorr(v,w,p)
%
%    INPUT PARAMETERS
%      v  = data history (nd X r); 
%      w  = data history (nd X m); 
%      p  = number of time shifts for v & w
%
%    OUTPUT PARAMETERS  (see User's guide for explaination)
%      vwt = [V][W]^T  (data correlation)
     
%         by Jer-Nan Juang  3-26-95
%         NASA SDB
[nd,r]=size(v); [nd,m]=size(w);
v=v';w=w';
%
% Computation the first r rows of vwt=v*v^T
%
 vwt=zeros(p*r,p*m);
  for j=1:p;
      cj=(j-1)*m+1:j*m; rj=(j-1)*r+1:j*r;
      c2=p-j+1:nd+1-j;
      vwt(1:r,cj)=v(:,p:nd)*w(:,c2)';
	  vwt(rj,1:m)=v(:,c2)*w(:,p:nd)';
%
%  Efficient Computation for the second r rows up to p*r row
%
	    ri1=1:r; cj1=cj; rj1=rj; ci1=1:m; 
	    i0=p; id=nd+1;
	    j0=p-j+1; jd=nd+2-j;
	  for k=j+1:p;
	        ri1=ri1+r; cj1=cj1+m; rj1=rj1+r; ci1=ci1+m;
		    i0=i0-1; id=id-1;
		    j0=j0-1; jd=jd-1;
		  vwt(ri1,cj1)=vwt(ri1-r,cj1-m)+v(:,i0)*w(:,j0)'-v(:,id)*w(:,jd)';
		  vwt(rj1,ci1)=vwt(rj1-r,ci1-m)+v(:,j0)*w(:,i0)'-v(:,jd)*w(:,id)';
	  end;
   end;
