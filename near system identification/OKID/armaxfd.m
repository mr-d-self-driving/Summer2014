function yb=armaxfd(frf,f,dt,r,pf,pb,fg) 
% Calculate the ARX parameters from the given frequency 
% response function. 
% 
%   yb=arxmfd(frf,f,dt,r,pf,pb,fg); 
% 
% INPUT PARAMETERS 
%      frf: frequency response (complex-valued)  
%          if G(z)=C(zI-A)^(-1)B+D=[G1,...,Gm] 
%          then frf=[G1.',...,Gm.'] 
%       f:  A column vector containing frequency points in Hz  
%      dt: Sampling Time  
%       r: number of input 
%      pf: number of forward-time steps 
%      pb: number of backward-time steps 
%   fg(1): 2 including real and imaginary parts for computing yb 
%            otherwise including only real parts for computing yb 
%   fg(2): Flag set to 1 to compare real FRF and estimated FRF 
%   fg(3): Number of iterations for computing ARMAX parameters  
% 
% OUTPUT PARAMETERS 
%    yb = The ARX parameters vector mx[(r+m)p+r]  
%         = [[b_pb -a_pb] ...[b_1 -a_1] b(0) [b_-1 -a_-1] ... 
%            [b_-pf -a_-pf]]; which satisfies the following equation 
%         [a_pb*z^pb+...+a_1*z+I+a_-1*z^-1+...a_-pf*z^-pf]*frf(z)     
%           =b_pb*z^pb+...+b_1*z+b_0+b_-1z^-1+...+b_-pf*z^-pf    
 
% 
%   Dr. Jer-Nan Juang 4/4/95, Structural Dynamics Branch 
%   NASA Langley Research Center, Hampton, VA 23681 
% 
if isempty(fg)==1 | length(fg)<3;  
   fg=[fg zeros(1,3-length(fg))]; 
   end;  
[nd,mr]=size(frf); m=mr/r; 
  if r*m~=mr,  
     disp('Number of input/output does not match the') 
     disp('dimension of the frequency data given'); 
    break; 
   end 
timer1 = clock; 
yb=yucovfd(frf,f,dt,r,pf,pb,fg(1)); 
% 
% Compute initial residual sequence                                
% 
p=pf+pb; p1=p+1; q=r+m; pq=p*q+r; 
m2=m;n=pb*q+r;  
if fg(2)==1 | fg(3)>0; 
   ek=zeros(size(frf)); 
   enorm=zeros(1+fg(3),1); 
   ek=-yxvfd([yb(:,1:n) -eye(m,m) yb(:,n+1:pq)],frf,f,dt,r,pf,pb); 
   enorm(1)=norm(ek); 
end; 
% 
% Whitening procedure starts here                                
% 
if fg(3)>0; 
  m2=m+m; q=r+m2;  pq=p*q+r; n=pb*q+r; %m more columns for residual sequence 
  frf1=zeros(nd,2*mr); 
  for i=1:fg(3); 
    disp([' Whitening Iteration Number ' num2str(i)]) 
% 
% Step 2: Compute ARMAX parameters                                
% 
    for k=1:r; 
       k1=(k-1)*m+1:k*m; 
       frf1(:,(k-1)*m2+1:k*m2)=[frf(:,k1) ek(:,k1)]; 
    end; 
% 
% Step 2: Compute ARMAX parameters                                
% 
    yb=yucovfd(frf1,f,dt,r,pf,pb,fg(1)); 
    yb=yb(1:m,:); 
% 
% Step 3: Compute new residual sequence                                
% 
    ek=-yxvfd([yb(:,1:n) -eye(m,m2) yb(:,n+1:pq)],frf1,f,dt,r,pf,pb); 
    enorm(i+1)=norm(ek); 
  end; 
end; 
timer2=etime(clock,timer1)/60; 
disp([' Time (min) to compute ARX parameters ' num2str(timer2)]); 
% 
% Compute and plot estimated and true FRF 
%  
if fg(2) == 1; 
   iflag=input('Compare Estimated and True FRF (1=yes,0=no)? =: '); 
   if iflag == 1;  
      disp(['FRF Residual Largest Singular Value ']); disp(enorm(fg(3)+1)); 
      if fg(3)>0; 
         itr=0:1:fg(3); 
		 clg; plot(itr,enorm); 
		 title([' Frequency Response Residual Whitening ' ]) 
         xlabel(' Number of iteration'); ylabel(' Whitened Residual Norm'); 
		 pause; 
	  end; 
        n=0; nd=length(f); cst=180/pi; 
        for kb=1:r 
          for kc=1:m; 
              n=n+1; 
              clg; subplot(211); semilogy(f(2:nd),abs(ek(2:nd,n)),'--'); 
              title(['FRF Error Information for Input No. ' num2str(kb) ... 
               ' and Output No. ' num2str(kc)]); 
              xlabel('Freq. (Hz)') 
              ylabel('Magnitude Error')  
	          subplot(212); 
		      plot(f(2:nd),angle(ek(2:nd,n))*cst,'--'); 
              xlabel('Freq. (Hz)') 
              ylabel('Phase Error (deg.)') 
              pause; 
			end; 
	     end; 
   disp(['Look good?. If not, stop and re-run the program with larger p.']); 
   end; 
end; 
