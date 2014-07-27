function yv=yxvfd(y,frf,f,dt,r,pf,pb)
%
%   Routine to compute the colleration matrix between 
%   parameter matrix y and frequency response function
%
%   yv=yxvfd(y,frf,f,dt,r,p)
%
% INPUT PARAMETERS
%      y : parameter matrix (m X p*q) where m=number of outputs 
%     frf: frequency response (complex-valued) 
%          if G(z)=C(zI-A)^(-1)B+D=[G1,...,Gm]
%          then frf=[G1.',...,Gm.'] (N X r*m)
%       f:  A column vector containing frequency points in Hz 
%      dt: Sampling Time 
%       r: number of input
%      pf: number of forward-time shits in y
%      pb: number of backward-time shits in y
%             
%
% OUTPUT PARAMETERS
%      yv = (yV)'  where v(z)=[I;g(z)] forms V;

%
%   Dr. Jer-Nan Juang 4/3/95, Structural Dynamics Branch
%   NASA Langley Research Center, Hampton, VA 23681
%
p=pf+pb; p1=p+1;
[m,k]=size(y); [nd,mr]=size(frf); m1=fix(mr/r);
  if p1*(r+m1)~=k, 
     disp('Number of input/output does not match the')
     disp('dimension of the frequency data given');
    break;
   end
[yr,ym]=separate(y,m,r,m1);
yr=m2p(yr,r);
j=sqrt(-1);
z=exp(2*pi*j*dt*f);
%
%  Start computing
%	   
  yrf=zeros(nd,m*r);
  yv=zeros(m,nd*r);
	zg=zeros(nd,mr);
    zk=z .^(pb+1);
	for k=1:p1;
	    zk=zk ./z; 
		for k1=1:mr;
		    zg(:,k1)=zk .*frf(:,k1);
		end;
		for k1=1:m*r;
			yrf(:,k1)=yr(k,k1)*zk;
		end;
        idx=(k-1)*m1+1:k*m1;
	    yv=yv+p2m(yrf,r)+ym(:,idx)*p2m(zg,r); 
	end;
yv=m2p(yv,r);	
	
	
	
	
	
	
	
