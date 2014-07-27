function vvt=vcorrfd(ruu,ryu,ryy,f,dt,r,p,iop)
%
%   Compute frequency response function correration matrix 
%
%   vvt=vcorrfd(ruu,ryu,ryy,f,dt,r,p,iop);
%
% INPUT:
%        ruu: Input Auto spectra stacked like an FRF (N x (r*m))
%        ryu: Cross-correlation stacked Column-wise (N x (r*r))
%        ryy: Output Auto spectra stacked like an FRF (N x (m*m))
%          f: Frequency vector (Hz) 
%         dt: Sampling Time
%          r: number of output
%          p: order of the polynomial
%        iop: If iop=1 only the upper bound solution is computed
%             
%
% OUTPUT PARAMETERS
%      vvt = [V][V]^T  (spectra correlation) where v(z)=[ryu(z);ruu(z)];

%
%   Dr. Jer-Nan Juang 4/14/95, Structural Dynamics Branch
%   NASA Langley Research Center, Hampton, VA 23681
%
[nd,mr]=size(ryu); m=mr/r; 
[nd,rr]=size(ruu); [nd,mm]=size(ryy);
  if r*m~=mr, 
     disp('Number of input/output does not match the')
     disp('dimension of the frequency data given');
    break;
   end
q=r+m;
j=sqrt(-1);
z=exp(2*pi*j*dt*f);
%
%  Compute the first r+m rows and first r+m columns
%	   
  vvt=zeros(p*q,p*q);
  zk=1.0;
  kr=1:r; km=r+1:r+m;
    zg=p2m(ruu,r); zgy=p2m(ryu,r);
	  %Using p2m needs to conjugate its resultant complex matrix.
	  %To save time, we conjugate the final resultant matrix.
    vvt(kr,kr)=zg*zg';
    vvt(kr,km)=zg*zgy';
    vvt(km,kr)=vvt(kr,km)';
    vvt(km,km)=zgy*zgy';
	zg=zeros(nd,rr);zgy=zeros(nd,mr);
	kq=1:q;
	for k=2:p;
%
%  For the second r+m rows and columns
%	   
       rk=1:q; ck=kq; 
       for k1=k:p;
           rk=rk+q; ck=ck+q; 
           vvt(rk,ck)=vvt(rk-q,ck-q);
           vvt(ck,rk)=vvt(rk,ck)';
       end;
	   kq=kq+q;
%
%  Compute the first r+m rows
%	   
	    zk=zk .*z;
		for k1=1:rr;
		    zg(:,k1)=zk .*ruu(:,k1);
		end;
		kr=kr+q; 
		vvt(1:r,kr)=p2m(zg,r)*p2m(ruu,r)';
		for k1=1:mr;
		    zgy(:,k1)=zk .*ryu(:,k1);
		end;
		vvt(r+1:r+m,kr)=p2m(zgy,m)*p2m(ruu,r)';
		km=km+q;
		vvt(1:r,km)=p2m(zg,r)*p2m(ryu,m)';
		vvt(r+1:r+m,km)=p2m(zgy,m)*p2m(ryu,m)';
		k1=[kr km];
		vvt(k1,1:q)=vvt(1:q,k1)';
	end;
    vvt=conj(vvt);
