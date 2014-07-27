function [lambda,bm,cm]=modal(a,b,c,flag)
% 
%     Function modal transforms discrete model matrices a, b, c       
%     to a reduced model in modal coordinates which contains only
%     stable modes or unstable modes   
%
%                                                                   
%         function [lambda,bm,cm]=modal(a,b,c,flag)
%
%    INPUT PARAMETERS                                       
%
%    a     = discrete-time state matrix   
%    b     = input matrix                        
%    c     = output matrix                                 
%    flag  < 0  only unstable modes desired                                  
%          >= 0 only stable modes desired                                                               
%
%    OUTPUT PARAMETERS                                       
%
%		  lamda = a column vector containing desired 
%               stable (flag >=0) or unstable eigenvalues (flag <0)        
%   	 bm   = reduced input matrix in modal coordinates                             
%   	 cm   = reduced output matrix in modal coordinates                             

%                                                                   
%         Jer-Nan Juang  11-28-91                     
%         NASA Spacecraft Dynamics Branch             

[V,D]=eig(a);
bm=V\b;
cm=c*V;
lambda=diag(D);
%
%  choose only stable models or unstable modes
%
   if flag < 0;
     k=abs(lambda)>1.0;
    else;
     k=abs(lambda)<=1.0;
   end;
%
   if sum(k)~=0;
     lambda=lambda(k);
     bm=bm(k,:);
     cm=cm(:,k);
%
%   sort eigenvalues, input and output matrices
%
     [lambda,k]=sort(lambda);
     bm=bm(k,:);
     cm=cm(:,k);
   else;
    lambda=[];bm=[];cm=[];
   end;

