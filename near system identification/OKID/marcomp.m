function [y]=marcomp(ybar,pb,r,n_markov,fg)
%
%   Routine to compute the system Markov parameters from the   
%   observer Markov parameters. 
%
%      [y]=marcomp(ybar,pb,r,n,fg)                
%                                                              
%  INPUT PARAMETERS                                   
%   ybar   = arx parameters (pb future time steps)
%   pb     = number of backward-time steps  
%   r      = number of inputs                                 
%   n      = number of system Markov parameters to compute  
%  fg      = 0: without residual whitening 
%          > 0: with residual whitening (system and Kalman filter Markov parameters) 
%          < 0: with residual whitening (system and observer Markov parameters) 
%                                                              
%  OUTPUT PARAMETERS                                  
%   y      = [d cb cab ca^2b]                          
%             dimension mx(r+m)(n_tar+1); a:system state matrix
                                             
%                                                              
%   Jer-Nan Juang, NASA Langley Research Center, 11/27/94                                     
    if isempty(fg)==1; fg=0; end;
[m,nd]=size(ybar);
q=r+m; m2=m; eye1=eye(m);
    if fg~=0; q=r+m+m; m2=m+m; end;
pf=(nd-r-pb*q)/q;
p=pf+pb; if n_markov<p; n_markov=p; end;
ybar=[ybar(:,1:pb*q+r) -eye(m,m2) ybar(:,pb*q+r+1:nd)];
ybar=-pinv(ybar(:,r+1:r+m))*ybar;
%*******************************************************************************
%*              Compute system Markov parameters                               *
%*******************************************************************************    
y=zeros((n_markov+1)*m,q);
y(1:m,1:q)=[ybar(1:m,1:r) zeros(m,m2)];
  i=1:r; i1=r+1:q; i2=r+1:r+m;
  iyb=[];
  for k=1:p;
      i=i+q; i1=i1+q; i2=i2+q;
	  iyb=[i2 iyb];
      ky=1:k*m;
      y(k*m+1:(k+1)*m,:)=[ybar(:,i) -ybar(:,i1)]+ybar(:,iyb)*y(ky,:);
      %The negative sign produces Markove parameters for -M-K
  end;
  for k=p+1:n_markov;
      ky=(k-p)*m+1:k*m;
      y(k*m+1:(k+1)*m,:)=ybar(:,iyb)*y(ky,:);
  end;
y=block_tr(m,n_markov,q,y,0);
if fg~=0;
   ko=[]; 
   for k=1:n_markov;
       k1=(k-1)*q+r;
	   ko=[ko k1+1:k1+m];
	end;
	   kk=ko+m;
	   y(:,kk)=y(:,ko)+y(:,kk); %To be used to solve for -K (Kalman Filter gain)                                
       if fg>0;  
          y(:,ko)=[];% System and Kalman Filter Markov Parameters
	   else;
	      y(:,kk)=[];% System and Deadbeat Observer Markov Parameters
	end;
end;
