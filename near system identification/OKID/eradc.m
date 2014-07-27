function [a,b,c,d,g,xs,xt]=eradc(y,fg,r,n,nm,dt)
% 
%	   Construct a state space model, observer gain, and control gain 
%      from pulse respone samples using the ERA time domain technique.
%                                                              
%    [A,B,C,D,G,xs,xt] = eradc(y,fg,r,n,nm,dt)     
%                                                              
% y   :[y_1 y_2 y_3... y_ni];                                 
%       y_i = response samples due to a unit pulse            
%             at the i-th input                               
% fg  : 0 or any number will do reqular id work or any vector shoter than 4.
%       fg(1)=1 Perform Modal Reduction interactively only when n=0;
%       fg(2)=1 computing observer gain; fg(2)=2 plus control gain                         
%       fg(3) > 0 keep stable modes; fg(3) < 0 keep unstable modes
%       fg(4) = 0 or actual number of outputs only when the pulse samples y
%              contains controller/observer gain pulse response                                                             
% r   : no. of system inputs.                              
% n   : desired model order and/or flag                                 
%        n=0 ; User's interaction is required to determine
%              the system order by looking at the singular value plot   
%        n >0; Desired model order without computing observer gain  
%        n <0; Desired model order abs(n) with observer gain computed
% nm  : no. of block row shifts to form H(0) (Hankel Matrix)
%       (maximum order to be identified is nm*m)                         
% dt  : data sample time interval                          
%                                                              
% The identified model is                                  
%		   x(k+1) = Ax(k) + Bu(k)                                
%   	   y(k) = Cx(k) + Du(k)                                
%  G  : G(:,1:m) = observer gain for state estimation if fg(2)=1
%       G(:,r+1:r+m)' = control gain for full state feedback if fg(2)=2 
% xs  : singular values of the correlation matrix.  	     
% xt  : 1st column = Damping ratios (%)                         
%       2st column = Frequencies (Hz)                         
%       3th column = Singular value of the pulse response samples 
%                    contributed by the identified individual modes 

%         J. N. Juang 11-29-91
%         NASA Spacecraft Dynamics Branch                           
%                                                                   
format short e; format compact
   [nd,rm]=size(y); m=rm/r;
   nr=nd-nm-1;% All the data will be used.
   if r*nr<nm*m;
     disp(['Errors in the era m-file occur.  The data length may not'])
     disp(['be long enough.  Try to increase the data length or reduce the'])
     disp(['number of row shifts nm. See User guide for more information.'])
     return;
   end; 
%
%  setup all flags
%
if isempty(fg)==1 | length(fg)<4; 
   fg=[fg zeros(1,4-length(fg))]; 
end;
flagera=1; if n==0; flagera=0; n=10000; else; fg(1)=0; end;   
%
%  Find the real number of inputs
%
   realr=r; realm=m;
   if fg(4)>0; 
      realr=r-fg(4); realm=fg(4); 
      if realr <= 0 | realm  > m; 
		 disp(['The actual number of inputs or outputs is in error.']);
		 return;
	  end;
   end;
%
% Generate the data correlation matrix R:
%
    disp(['ERADC is used now.']);
    disp(['The Hankel matrix size for ERADC is ' num2str(nm*m)...
          ' by ' num2str(nr*r) '.']);
    Markov=p2m(y,r);
    [d,R]=hankldc(Markov,r,nm);
%
% Generate a Hankel matrix H of a suitalbe size for computing b
% and control gain gc
%
    nh=3*(nm+1)*m; nh=min(nh,nr);
    [d1,H]=hankl(Markov(:,1:nh*r),r,nm);clear Markov;
%
% Perform Singular Value decomposition
%
    [p,xs,q]=svd(R(1:m*nm,:));clear q;
    xs=diag(xs); sigcont=sum(xs);   
	nmax=length(xs); 
	if n>nmax | n<0; n=nmax; end;  
     disp(['Maximum Hankel singular value = ' sprintf('%e',max(xs))])
     disp(['Minimum Hankel singular value = ' sprintf('%e',min(xs))])
     n_index=find(xs>0.00000001);
	 n_index=min(length(n_index),nmax);
%
% Determine the order of the system
%
   if flagera==0; clg;
         if fg(1)==1; subplot(211); end;
	  semilogy([xs],'*');
      xlabel(' Number');ylabel('SV Magnitude');
      title(' Hankel Singular Values (HSV)');pause;
      disp([' '])
      disp(['The HSV plot allows you to determine a desired model size.'])
      disp(['Besides, further modal reduction may also be desired.'])
      disp(['See the option of this function.'])
    else;
       if n>n_index; 
         disp(['The initial order is set to ' num2str(n) '.'])
         disp(['It is now set to ' num2str(n_index) '.']) 
         n=n_index;
       end;       
    end;

 while n > 0; 
   if flagera==0;
       n=input(['Desired Model Order (See HSV plot) (0=stop)=: ']);
       if isempty(n)==1 | n==0; break; end;
       if n>nmax | n<0; n=nmax; end; 
       sigkpt=sprintf('%g',100*sum(xs(1:n))/sigcont);
       disp([' Model Describes ' sigkpt ' (%) of Test Data'])
   end;
%
% Calculate a discrete model realization
%
   d1=sqrt(xs(1:n));
   d2=1.0 ./d1;
   a=diag(d2)*p(:,1:n)'*R(m+1:m*(nm+1),:)*p(:,1:n)*diag(d2);
   ctr=diag(d2)*p(:,1:n)'*H;
   b=ctr(:,1:r);
   obs=p(:,1:n)*diag(d1);
   c=obs(1:m,:);
%
%  Solve for eigenvalues and eigenvectors
%
    [phi,lambda]=eig(a);
    lambda=diag(lambda);
%
%   Calculate the singular values of modal participation to
%   the pulse response samples 
%
   if fg(1)==1; subplot(212); end;
   [lambda,bm,cm,msv,index]=svpm(lambda,phi\b(:,1:realr),c(1:realm,:)*phi,fg(1));
   clear bm cm;
%
    xt=deg2hz(lambda,dt); 
    xt=[xt(:,1:2) msv];
     disp('   Damping(%)    Freq(HZ)      Mode SV');
	 disp(xt);
%
   if flagera==1; n=0; end;
 end;

%
%  choose only stable models or unstable modes
%
  if fg(3)~=0;
      if fg(3) < 0;
          k=abs(lambda)>1.0; desp='The unstable part';
       else;
          k=abs(lambda)<=1.0; desp='The stable part';
%           k=abs(lambda); k=1.0; desp='The stable part';
       end;
%
    if sum(k)~=length(lambda);
       if sum(k)~=0;
	      index=index(k); lambda=lambda(k); msv=msv(k);
            xt=deg2hz(lambda,dt); 
            xt=[xt(:,1:2) msv];
	          disp([desp ' of the system model is ']);
              disp('   Damping(%)    Freq(HZ)      Mode SV');
	          disp(xt);
       else;
	      a=[];b=[];c=[];d=[];g=[];xs=[];xt=[];
	      disp([desp ' of the system model cannot be found.']);
	      return;
       end;
	 end;
  end;
%
%  Reduce the system model and put in the block-diagonal form
%
   [n,pc]=size(ctr);pc=pc/r;
   n=length(index);
   if length(obs(1,:)) > n;
     obs=obs*phi; obs=obs(:,index);
     ctr=phi\ctr;clear phi;
     ctr=ctr(index,:);
     [a,ctr,obs]=bk_diag(lambda,ctr,obs);
     b=ctr(:,1:r);c=obs(1:m,:);
   end;
%
%  Compute observer and control gains
%
if fg(2)>0;
%
% for combined system and observer pulses
%
   if realr~=r;
	  k=-r+1:-r+realr; idx=[];
	  for i=1:pc;
	     k=k+r; idx=[idx k];
	  end;
	  ctr=ctr(:,idx);
      y=y(:,1:realr*m);
	end; 
%
%  Obtain actual observability matrix and adjust the pulse response matrix
%
   if realm~=m;
      [ps,n]=size(obs);ps=ps/m;
	  k=-m+1:-m+realm; idx=[];
	  for i=1:ps;
	     k=k+m; idx=[idx k];
	  end;
	  obs=obs(idx,:);
      k=-m+1:-m+realm; idx=[]; 	
      for i=1:realr
		 k=k+m; idx=[idx k];
	  end;
      y=y(:,idx);
	end; 
%
%  Compute observer and control gains for the identified system model
%
   g=gain_o(obs,y,realr,n_index);
   if fg(2)>1;
     gc=gain_c(ctr,y,realr,n_index);
     g=[g gc'];
   end;   
end;

