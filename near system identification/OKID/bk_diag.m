function [amr,bmr,cmr]=bk_diag(lambda,bm,cm)
%
%     Function bk_diag transforms the complex discrete modal form       
%     of a system into a block real diagonal form
%
%     [am,bmr,cmr]=bk_diag(lambda,bm,cm)                                                              
%
%    INPUT PARAMETERS                                       
%                                                                   
%		  lamda = a column vector containing complex eigenvalues of a system
%   	 bm   = complex input matrix in modal coordinates                             
%   	 cm   = complex output matrix in modal coordinates                             
%
%    OUTPUT PARAMETERS                                       
%
%    am    = discrete-time state matrix in block diagnoal form   
%    bmr   = real input matrix                        
%    cmr   = real output matrix                                 

%                                                                   
%         Jer-Nan Juang  11-28-91                     
%         NASA Spacecraft Dynamics Branch             

%  re-order the eignevalues such that all the real eigenvalues
%  are in the front and pair of complex eigenvalues in the back.
%
   s2=sqrt(2);
   [lambda,k]=sort(lambda);
   bm=bm(k,:);cm=cm(:,k);
%
   k=abs(imag(lambda))==0.0;
   j=abs(imag(lambda))>0.0;
   lambda=[lambda(k);lambda(j)];
   bm=[bm(k,:);bm(j,:)];
   cm=[cm(:,k) cm(:,j)];
   n_real=sum(k); n_cplx=sum(j);

   junk=cplxpair(lambda);% Check if complex numbers are pairable.

      nd=n_real+n_cplx;
%     
      amr=diag(real(lambda));
      bmr=real(bm); cmr=real(cm);
      if n_cplx > 1;
        D=zeros(nd-1,1);
        k=n_real+1:2:nd;
        D(k)=imag(lambda(k));
        amr=amr+diag(D,1)-diag(D,-1);
%
        bmr(k,:)=s2*real(bm(k,:));
        cmr(:,k)=s2*real(cm(:,k));
%
        j=n_real+2:2:nd;
        bmr(j,:)=-s2*imag(bm(k,:));
        cmr(:,j)=s2*imag(cm(:,k));
      end;
