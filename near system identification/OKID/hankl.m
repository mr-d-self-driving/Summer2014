function [D,H]=hankl(Markov,r,p)
% 
%     Routine to form a Hankel matrix from Markov parameters    
%                                                              
%        function [d,H]=hankl(Markov,r,p)                         
%                                                              
%    INPUT PARAMETERS
%     Markov = [D CB CAB ... C(A^(p+q))B]                            
%     r      = Number of inputs                               
%     p      = Number of block shifts in rows                               
%
%    OUTPUT PARAMETERS
%     D      = Direct transmission matrix                            
%     H      = Hankel matrix of size p*m by q*r                               
%              (m=no. of outputs)                           

%         J. N. Juang  12-9-91
%         NASA Spacecraft Dynamics Branch                           

[m,qr]=size(Markov);D=zeros(m,r);
q=(qr/r)-p;
   if q > 0;
      D=Markov(:,1:r);
      H=zeros(p*m,q*r);
      for i=1:p;
        H((i-1)*m+1:i*m,:)=Markov(:,i*r+1:(i+q)*r);
       end
    else;
        disp('There is not enough Markov parameters to form')
        disp('the desired size of Hankel matrix in hankl. ')
        disp('Try to increase the number of Markov parameters')
        disp('or reduce the size of p or q') 
    end;
 
