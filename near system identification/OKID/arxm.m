function [yb]=arxm(m,r,u,y,pf,pb,ic);
%   Function armax computes past-in-time and future-in-time observer
%   Markov (ARMAX) parameters from input and output time histories.   
%   Multiple experiments may be used.
%
%       [yb]=armaxtd(m,r,u,y,pf,pb,ic);
%
% INPUT PARAMETERS
%      m  = number of outputs                                   
%      r  = number of inputs                                    
%      u  = input time history (n X r); n = no. of data, r=no. of inputs 
%      y  = output time history (n X m); m = no. of outputs 
%      pf = number of past time steps
%      pb = number of future time steps
%   ic(1) = Flag set to 0 when experiments start from rest       
%           otherwise when experiments have initial conditions involved       
%   ic(2) = Flag set to 0 for a batch job; prediction error 
%           won't be computed.
%   ic(3) = Number of iterations for computing ARMAX parameters 
%
% OUTPUT PARAMETERS
%    yb = The ARX parameters vector mx[(r+m)p+r] 
%         = [[b_pb -a_pb c_pb] ...[b_1 -a_1 c_1] b(0) [b_-1 -a_-1 c_-1] ...
%            [b_-pf -a_-pf c_-pf]]; which satisfies the following equation
% a_pb*y(k+pb)+...+a_1*y(k+1)+y(k)+a_-1*y(k-1)+...a_-pf*y(k-pf)    
%  =b_pb*u(k+pb)+...+b_1*u(k+1)+b_0*u(k)+b_-1*u(k-1)+...+b_-pf*u(k-pf)
%   c_pb*e(k+pb)+...+c_1*e(k+1)+e(k)+c_-1*e(k-1)+...+c_-pf*e(k-pf)   

%
%      Jer-Nan Juang, NASA Langley Research Center, Hampton, VA 23681 
%      Nov. 21, 1994

%
%  Scaling of the test data                        
%
if isempty(ic)==1 | length(ic)<3; 
   ic=[ic zeros(1,3-length(ic))]; 
end;
   if ic(3)<0; ic(3)=-ic(3); end;
   [L,ny]=size(y); [L,nu]=size(u);
   n_exp=ny/m;
         scaley=max(abs(y(:,1:m))); 
            i=find(scaley==0); scaley(i)=ones(1,length(i)); 
            invscy=1.0 ./scaley; 
         scaleu=max(abs(u(:,1:r))); 
            i=find(scaleu==0); scaleu(i)=ones(1,length(i)); 
            invscu=1.0 ./scaleu;
            for ij=1:n_exp;
              n_n=[(ij-1)*m+1:ij*m];  n_r=[(ij-1)*r+1:ij*r];
              y(:,n_n)=y(:,n_n)*diag(invscy);
              u(:,n_r)=u(:,n_r)*diag(invscu);
              end;clear n_n n_r;
%
% Initializing                                
%
p=pf+pb; q=r+m; pq=p*q+r;
 timer1 = clock;
   yb=zeros(m,pq);
   vvt=zeros(pq,pq);
%
%  Compute ARX parameters for n_exp sets of experiments  
%
   for ie=1:n_exp;
         disp([' Compute Parameters For Data Set Number ' num2str(ie)])
         j=(ie-1)*m+1:ie*m;
         k=(ie-1)*r+1:ie*r;
         [yj0,vj0]=yucov(u(:,k),y(:,j),pf,pb,ic(1));
         vvt=(vvt+vj0);
         yb=(yb+yj0);
   end;  
   clear yj0 vj0;
yb=yb*pinv(vvt);
%
% Compute initial residual sequence                               
%
m2=m;n=pb*q+r; p1=p+1; 
if ic(2)==1 | ic(3)>0;
   ek=zeros(size(y));
   enorm=zeros(1+ic(3),n_exp);
   for ie=1:n_exp;
     j=(ie-1)*m+1:ie*m;
     k=(ie-1)*r+1:ie*r;
     e1=-yxv([yb(:,1:n) -eye(m,m) yb(:,n+1:pq)],[zeros(pf,q);u(:,k) y(:,j)],p1);
     if ic(1)~=0; e1(1:pf,:)=zeros(pf,m); end;
     e1=[e1;zeros(pb,m)]; 
	 enorm(1,ie)=norm(e1);
	 ek(:,j)=e1;
   end;
end;
%
% Whitening procedure starts here                               
%
if ic(3)>0;
  m2=m+m; q=r+m2;  pq=p*q+r; n=pb*q+r; %m more columns for residual sequence
  for i=1:ic(3);
    disp([' Whitening Iteration Number ' num2str(i)])
%
% Step 2: Compute data and residual correlations for n_exp sets of experiments                               
%
  yb1=zeros(m+m,pq);
  vvt=zeros(pq,pq);
    for ie=1:n_exp;
%      disp([' Compute Data and Residual Correlation for Data Set Number ' num2str(ie)])
      j=(ie-1)*m+1:ie*m;
      k=(ie-1)*r+1:ie*r;
	  e1=ek(:,j);
      [yj0,vj0]=yucov(u(:,k),[y(:,j) e1],pf,pb,ic(1));
      vvt=(vvt+vj0);
      yb1=(yb1+yj0);
	end;
%
% Step 2: Compute ARMAX parameters                               
%
    yb=yb1(1:m,:)*pinv(vvt);
%
% Step 3: Compute new residual sequence                               
%
    for ie=1:n_exp;
%      disp([' Compute Residual Sequence for Data Set Number ' num2str(ie)])
      j=(ie-1)*m+1:ie*m;
      k=(ie-1)*r+1:ie*r;
	  e1=ek(:,j);
      e1=-yxv([yb(:,1:n) -eye(m,m2) yb(:,n+1:pq)],[zeros(pf,q);u(:,k) y(:,j) e1],p1);
      if ic(1)~=0; e1(1:pf,:)=zeros(pf,m); end;
      e1=[e1;zeros(pb,m)]; 
	  enorm(i+1,ie)=norm(e1);
	  ek(:,j)=e1;
    end;
  end;
end;
%
% Compute and plot prediction errors 
% 
if ic(2) == 1;
    iflag=input('Plot Output Residual Information (1=yes,0=no)? =: ');
  if iflag == 1; 
%
%  Compute residual sequence                               
%
   itr=0:ic(3);
   for ie=1:n_exp;
     disp([' Plot Residual Information For Data Set Number ' num2str(ie)])
	 e1=ek(:,(ie-1)*m+1:ie*m);
      disp(' Residual Sequence Root Mean Square '); disp(sqrtm(e1'*e1));
         if ic(3)>0; 
		    subplot(211); plot(itr,enorm(:,ie));
            xlabel(' Number of iteration'); ylabel(' Whitened Residual Norm');
	      else; 
		   subplot(211); plot(e1);
	        xlabel(' Time Steps'); ylabel(' Residual Sequence');
        end;
 	   title([' All Output(s) for Data Set Number ' num2str(ie)])
       ewhite=vcorr(e1,p); %whitening Check for p time steps
	   for i=1:m;
	       ecorr(1:p,i)=abs(ewhite(i,i:m:p*m))';
	   end;
       subplot(212); plot(0:p-1,ecorr); 
        xlabel(' Number of time shifts'); ylabel(' Residual Correlations');
		pause;
    end;
  end;
end;
%
% Scaling of the resulting ARX parameters                                
%
 yb=diag(scaley)*[yb(:,1:n) -eye(m,m2) yb(:,n+1:pq)];
 if ic(3)>0; invscy=[invscy invscy]; end; 
  for i=1:p+1;
     i1=(i-1)*q;
     iu=i1+1:i1+r;
     iy=i1+r+1:i1+q;
     yb(:,iu)=yb(:,iu)*diag(invscu);
     yb(:,iy)=yb(:,iy)*diag(invscy);
  end;
  yb(:,n+1:n+m2)=[]; 
timer2=etime(clock,timer1)/60;
disp([' Time (min) to compute observer parameters ' num2str(timer2)])
