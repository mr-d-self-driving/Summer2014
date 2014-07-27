function [a,b,c,d,g,xt]=ocompan(ybar,pb,r,dt,fg); 
% 
%   Routine to form state space realization in observable    
%   canonical form from observer Markov parameters.  
% 
%      [a,b,c,d,g,lambda,xt]=ocompan(ybar,pb,r,dt,fg)                
%                                                               
%  INPUT PARAMETERS                                    
%   ybar = arx parameters (pb future time steps) 
%   pb   = number of backward-time steps   
%   r    = number of inputs                                  
%   dt   = sampling interval (sec)                                 
%  fg(1) = 1 User's interaction required to determine modal truncation                              
%  fg(2) > 0 keep stable modes; fg(2) < 0 keep unstable modes 
%                                                               
%  OUTPUT PARAMETERS                                   
%   a  = state-space matrix in companion form                           
%   b  = input matrix                           
%   c  = output matrix                           
%   d  = direct transmission form                           
%   g  = deadbeat observer gain matrix                           
%   xt = 1st column; Damping ratios (%)                          
%      = 2st column; Frequencies (Hz)                          
%      = 3th column; Singular value of the pulse response samples  
%                       contributed by the identified individual modes  
 
%                                                               
%   Jer-Nan Juang, NASA Langley Research Center, 12/10/94                                      
 
disp(['Observable canonical-form realization.']); 
 
if isempty(fg)==1 | length(fg)<2;  
fg=[fg zeros(1,2-length(fg))];  
end; 
 
[m,nd]=size(ybar); 
q=r+m; 
pf=(nd-r-pb*q)/q; 
p=pf+pb; pm=p*m; 
ybar=[ybar(:,1:pb*q+r) -eye(m,m) ybar(:,pb*q+r+1:nd)]; 
% 
% initialize and form d, c, b, and g matrices 
% 
a=zeros(pm,pm); b=zeros(pm,r); c=zeros(m,pm); g=zeros(pm,m); 
ainv=pinv(ybar(:,r+1:q)); 
d=-ainv*ybar(:,1:r); 
c(:,(p-1)*m+1:pm)=eye(m,m); 
ja=(p-1)*m+1:p*m; 
for i=1:p; 
    ia=(p-i)*m+1:(p+1-i)*m; 
	jm=i*q+r+1:(i+1)*q; 
	jr=i*q+1:i*q+r; 
	a(ia,ja)=-ainv*ybar(:,jm); 
	b(ia,:)=-ainv*(ybar(:,jr)+ybar(:,jm)*d); 
    g(ia,:)=-a(ia,ja); 
end; 
% 
% for companion form of a 
% 
for i=1:p-1; 
    ia=i*m+1:(i+1)*m; 
	ja=(i-1)*m+1:i*m; 
	a(ia,ja)=eye(m,m); 
end; 
% 
%  Solve eigenvalues and eigenvectors and compute modal singular values 
% 
    [phi,lambda]=eig(a); 
    lambda=diag(lambda); 
    bm=phi\[b g];cm=c*phi; 
	clg; 
   [lambda,bm1,cm1,msv,index]=svpm(lambda,bm(:,1:r),cm,fg(1)); 
   clear bm1 cm1; 
    xt=deg2hz(lambda,dt);  
    xt=[xt(:,1:2) msv]; 
     disp('   Damping(%)    Freq(HZ)      Mode SV'); 
	 disp(xt); 
% 
%  choose only stable models or unstable modes 
% 
  if fg(2)~=0; 
      if fg(2) < 0; 
          k=abs(lambda)>1.0; desp='The unstable part'; 
       else; 
          k=abs(lambda)<=1.0; desp='The stable part'; 
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
   if pm>length(index); 
       bm=bm(index,:); cm=cm(:,index); 
	   [a,b,c]=bk_diag(lambda,bm,cm); 
	   g=b(:,r+1:q); b=b(:,1:r); 
   end; 
