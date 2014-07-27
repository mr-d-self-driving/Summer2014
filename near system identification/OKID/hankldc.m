function [D,R]=hankldc(Y,r,p)
% 
%     Routine to form a data correlation matrix from Markov parameters    
%                                                              
%        function [D,R]=hankldc(Markov,r,p)                         
%                                                              
%    INPUT PARAMETERS
%     Markov = [D CB CAB ... C(A^(p+q))B]                            
%     r      = Number of inputs                               
%     p      = Number of block shifts in columns for H(0) (Hankel Matrix)                               
%
%    OUTPUT PARAMETERS
%     D      = Direct transmission matrix                            
%     R      = Data Correlation Hankel matrix of size (p+1)*m by p*m                               
%              (m=no. of outputs) R(1:p*m,:)=H(0)*H(0)';
%                                 R(m+1:(p+1)*m,:)=H(1)*H(0)'                           

%         J. N. Juang 2-4-95
%         NASA Structural Dynamics Branch                           

[m,qr]=size(Y);D=zeros(m,r);
q=(qr/r)-p-1;
   if q > 0;
      D=Y(:,1:r);
      R=zeros((p+1)*m,p*m);
%
%  Compute the first m rows
%
      cj=1-m:0;
      i_index=r+1:r*(1+q); j_index=i_index-r;
      for j=1:p;
          cj=cj+m;
          j_index=j_index+r;
          R(1:m,cj)=Y(:,i_index)*Y(:,j_index)';
          R(cj,1:m)=R(1:m,cj)';
%
%  Compute the next (p-1)*m rows
%
         i1=1:m; j1=cj;
	     i01=1:r; i0d=i01+r*q;
	     j01=i01+(j-1)*r; j0d=i0d+(j-1)*r;
         for k=j+1:p;
		    i1=i1+m; j1=j1+m;
            i01=i01+r;i0d=i0d+r;
            j01=j01+r;j0d=j0d+r;
            R(i1,j1)=R(i1-m,j1-m)-Y(:,i01)*Y(:,j01)'+Y(:,i0d)*Y(:,j0d)';
            R(j1,i1)=R(i1,j1)';
         end;
      end;
%
%  Compute the last m row
%
	  i_index=r*(p+1)+1:r*(p+q+1);
	  j_index=r+1:r*(q+1);
	  i1=p*m+1:(p+1)*m;
      R(i1,1:m)=Y(:,i_index)*Y(:,j_index)';

        i01=r*p+1:r*p+r;i0d=i01+r*q;
		j01=1:r;j0d=j01+r*q;
        j1=1:m;
        i0=i1-m;
        for j=2:p;
           j1=j1+m;j0=j1-m;
           j01=j01+r;j0d=j0d+r;
           R(i1,j1)=R(i0,j0)-Y(:,i01)*Y(:,j01)'+Y(:,i0d)*Y(:,j0d)';
        end;
    else;
        disp('There is not enough Markov parameters to form')
        disp('the desired size of Hankel matrix in hankldc. ')
        disp('Try to increase the number of Markov parameters')
        disp('or reduce the size of p or q.') 
    end;
 
