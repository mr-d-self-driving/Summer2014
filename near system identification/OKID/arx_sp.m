function ybar=arx_sp(ruu,ryu,ryy,f,dt,r,p,iop)
%       Calculate the ARX parameters from the given 
%       input and output spectra. 
%
%   ybar=arx_sp(ruu,ryu,ryy,f,dt,r,p,iop);
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
% OUTPUT:
%       ybar: ARX parameters: A(z)Y(z)=B(z)U(z)+E
%       ybar=[B0 [B1 -A1] [B2 -A2] ... [Bp -Ap]'

%
%   Dr. Jer-Nan Juang 4/14/95, Structural Dynamics Branch
%   NASA Langley Research Center, Hampton, VA 23681
%
[nd,mr]=size(ryu); m=mr/r;
  if r*m~=mr, 
    disp('Number of input/output does not match the')
     disp('dimension of the frequency data given');
    break;
  end
%
%  Option: compute upper and lower bound solution if iop~=1
%	   
r1=r;
if iop~=1 & isempty(ryy)~=1 ;
    ryy=[ryu ryy];
	idx=[];
	for k=1:m; idx=[idx k:m:mr]; end;
	ryu=ryu(:,idx);
	ruu=[ruu conj(ryu)];
	ryu=ryy; clear ryy;
	r1=r+m;
end; 
%
%  Compute the first r+m rows and first r+m columns
%	   
  p1=p+1;q=r+m;
  vvt=zeros(p1*q,p1*q);
  kr=1:r; km=r+1:r+m;
	  %Using p2m needs to conjugate its resultant complex matrix,
      %but here we will conjugate the final results
  zg=p2m(ruu,r1);
  vvt(kr,kr)=zg*zg';
  vvt(kr,km)=zg*p2m(ryu,r1)';
  vvt(km,kr)=vvt(kr,km)';
  zg=p2m(ryu,r1);
  vvt(km,km)=zg*zg';
%
%  For the second r+m rows and columns
%	   
  [nd,rr]=size(ruu); [nd,mr]=size(ryu);
  j=sqrt(-1);
  z=exp(2*pi*j*dt*f);  zk=1.0;
  kq=1:q;
	for k=2:p1;
       rk=1:q; ck=kq; 
       for k1=k:p1;
           rk=rk+q; ck=ck+q; 
           vvt(rk,ck)=vvt(rk-q,ck-q);
           vvt(ck,rk)=vvt(rk,ck)';
       end;
	   kq=kq+q;
%
%  Compute the first r+m rows
%	   
	    zk=zk .*z;
        zg=zeros(nd,rr);
		for k1=1:rr;
		    zg(:,k1)=zk .*ruu(:,k1);
		end;
		zg=p2m(zg,r1); 
		kr=kr+q;
		vvt(1:r,kr)=zg*p2m(ruu,r1)';
		km=km+q;
		vvt(1:r,km)=zg*p2m(ryu,r1)';
        zg=zeros(nd,mr);
   		for k1=1:mr;
		    zg(:,k1)=zk .*ryu(:,k1);
		end;
		zg=p2m(zg,r1); 
		vvt(r+1:r+m,kr)=zg*p2m(ruu,r1)';
		vvt(r+1:r+m,km)=zg*p2m(ryu,r1)';
		k1=[kr km];
		vvt(k1,1:q)=vvt(1:q,k1)';
	end;
    vvt=conj(vvt); %To obtain the correct resultant matrix
%
%  Compute the ARX parameters
%	   
    k=r+1:q;
    vvt(:,k)=[];yvt=vvt(k,:);vvt(k,:)=[]; 
    ybar=real(yvt)*pinv(real(vvt));
%
%   ybar=[real(yvt) imag(yvt)]*pinv([real(vvt) imag(vvt)]);
%   This includes imaginary part but it does not help much.
	
