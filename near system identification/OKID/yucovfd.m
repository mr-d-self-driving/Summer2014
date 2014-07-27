function ybar=yucovfd(frf,f,dt,r,pf,pb,flag)
%
%   Routine to compute ARX parameters from
%   frequency response function
%
%    ybar=yucovfd(frf,f,dt,r,pf,pb,flag)
%
%  INPUT PARAMETERS
%     frf= frequency response (complex-valued) 
%          if G(z)=C(zI-A)^(-1)B+D=[G1,...,Gm]
%          then frf=[G1.',...,Gm.']
%       f= A column vector containing frequency points in Hz 
%      dt= Sampling Time 
%       r= number of input
%      pf= number of forward-time steps
%      pb= number of backward-time steps
%    flag= 2 including real and imaginary parts for computing ybar
%            otherwise including only real parts for computing ybar
 
%
%  OUTPUT PARAMETERS  (see User's guide for explaination)
%    ybar: ARX parameters
     
%         by Jer-Nan Juang  11-29-94 modified 2-4-95
%         NASA SDB
[nd,mr]=size(frf); m=mr/r;
  if r*m~=mr, 
     disp('Number of input/output does not match the')
     disp('dimension of the frequency data given');
    break;
   end
p=pf+pb; q=m+r;
 p1=p+1;
 vvt=vcorrfd(frf,f,dt,r,p1);
    k=(pb*q)+r+1:(pb+1)*q;vvt=vvt/nd;
    vvt(:,k)=[];yvt=vvt(k,:);vvt(k,:)=[]; 
    if flag==2;  
       ybar=[real(yvt) imag(yvt)]*pinv([real(vvt) imag(vvt)]);
    else;
       ybar=real(yvt)*pinv(real(vvt));
    end;
