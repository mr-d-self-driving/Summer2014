function [an,bn,cn,kn]=normalzd(a,b,c,kalm)
%
%       Normalization routine to compare realizations
%       of a,b,c. The system must have all complex conjugate 
%       pairs.
%
%          [an,bn,cn,kn]=normalzd(a,b,c,kalm)
%

%        L.G. Horta 11-28-90
%       
[ablk,bblk,cblk,tran]=tform(a,b,c);
[n1,n2]=size(bblk);
n=fix(n1/2);
mtemp=diag(cblk'*cblk);
      for i=1:n
        rmag=sqrt(mtemp(2*i-1)+mtemp(2*i))/2;
        m2(2*i-1,2*i-1)=sign(cblk(1,2*i-1))/rmag;
        m2(2*i,2*i)=sign(cblk(1,2*i-1))/rmag;
      end
cn=cblk*m2;
t=zeros(n1,n1);
      for i=1:n;
           theta=atan(cn(1,2*i)/cn(1,2*i-1));
           t(2*i-1,2*i-1)=cos(theta);
           t(2*i-1,2*i)=-sin(theta);
           t(2*i,2*i-1)=sin(theta);
           t(2*i,2*i)=cos(theta);
       end
tt=m2*t;
cn=cblk*tt;
bn=inv(tt)*bblk;
kn=inv(tran*tt)*kalm;
%disp(' Subroutine modified to output M instead of KF gain')
%kn=inv(tt)*kalm;
an=tt*ablk*inv(tt);
