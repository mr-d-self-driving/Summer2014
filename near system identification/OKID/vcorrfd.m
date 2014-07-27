function vvt=vcorrfd(frf,f,dt,r,p)
%
%   Compute frequency response function correration matrix 
%
%   vvt=vcorrfd(frf,f,dt,r,p);
%
% INPUT PARAMETERS
%      frf: frequency response (complex-valued) 
%          if G(z)=C(zI-A)^(-1)B+D=[G1,...,Gm]
%          then frf=[G1.',...,Gm.']
%       f:  A column vector containing frequency points in Hz 
%      dt: Sampling Time 
%       r: number of input
%       p: number of time shits for correlation
%             
%
% OUTPUT PARAMETERS
%      vvt = [V][V]^T  (frequency data correlation) where v(z)=[I;g(z)];

%
%   Dr. Jer-Nan Juang 4/3/95, Structural Dynamics Branch
%   NASA Langley Research Center, Hampton, VA 23681
%
[nd,mr]=size(frf); m=mr/r;
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
    vvt(kr,kr)=nd*eye(r);
    vvt(kr,km)=p2m(sum(frf),r)';
	  %Using p2m needs to conjugate its resultant complex matrix,
      %but here we will conjugate the final results
    vvt(km,kr)=vvt(kr,km)';
    zg=p2m(frf,r); %Markov Parameters
    vvt(km,km)=zg*zg';
	zg=zeros(nd,mr);
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
		kr=kr+q; 
		vvt(1:r,kr)=conj(sum(zk))*eye(r);
		km=km+q;
		vvt(1:r,km)=p2m(zk'*frf,r)';
		for k1=1:mr;
		    zg(:,k1)=zk .*frf(:,k1);
		end;
		vvt(r+1:r+m,kr)=p2m(sum(zg),r);
		vvt(r+1:r+m,km)=p2m(zg,r)*p2m(frf,r)';
		k1=[kr km];
		vvt(k1,1:q)=vvt(1:q,k1)';
	end;
vvt=conj(vvt); %Bring back to the correct result dut to p2m
