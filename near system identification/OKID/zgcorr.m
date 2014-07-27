function gzt=zgcorr(frfp,f,dt,r,p)
%
%  Compute parameters for adjusting system zeros
%
%   gzt=zgcorr(frfp,f,dt,r,p);
%
% INPUT PARAMETERS
%  frfp: frequency response for system zeros stored columnwise 
%        frfp=FRF*p(z)=Frequency Response * Characteristics Polynomial
%     f:  A column vector containing frequency points in Hz 
%    dt: Sampling Time 
%     r: number of input
%     p: number of time shits for correlation
%             
%
% OUTPUT PARAMETERS
%   gzt: parameters for computing system zeros

%
%   Dr. Jer-Nan Juang 4/11/95, Structural Dynamics Branch
%   NASA Langley Research Center, Hampton, VA 23681
%
[nd,mr]=size(frfp); m=mr/r;
  if r*m~=mr, 
     disp('Number of input/output does not match the')
     disp('dimension of the frequency data given');
    break;
   end
j=sqrt(-1);
z=exp(2*pi*j*dt*f);
%
%  Compute the first r+m rows
%	   
  zzt=zeros(p*r,p*r);
  gzt=zeros(m,p*r);
  zk=1.0;
%
%  Compute the first r rows and first r columns
%	   
    zzt(1:r,1:r)=nd*eye(r);
    gzt(1:m,1:r)=conj(p2m(sum(frfp),r));
	zg=zeros(nd,mr);
    kr=1:r; 
	for k=2:p;
	    ri=1:r; cj=kr; 
	  for k1=k:p;
	        ri=ri+r; cj=cj+r;
		  zzt(ri,cj)=zzt(ri-r,cj-r);
		  zzt(cj,ri)=zzt(ri,cj)';
	  end;
	  zk=zk .*z;
	  kr=kr+r; 
	  zzt(1:r,kr)=sum(zk)*eye(r);
	  zzt(kr,1:r)=zzt(1:r,kr)';
	  for k1=1:mr;
		    zg(:,k1)=zk .*frfp(:,k1);
	  end;
	  gzt(1:m,kr)=conj(p2m(sum(zg),r));
	end;
gzt=real(gzt)*pinv(real(zzt));
%gzt=real(gzt*pinv(zzt));
