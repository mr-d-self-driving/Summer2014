function [y_e]=yog_cal(a,b,c,d,g,u,x0,y,dt,nd,flag)
%
%    Data Reconstruction with observer and initial condition 
%    for output or frequency response function (frf)                           
%
%     [y_e]=yog_cal(A,B,C,D,g,u,x0,y,dt,nd,flag)
% 
%INPUT PARAMETERS
%A,B,C,D : system matrces                                    
%      g : observer gain matrix; g=0 (without observer) 
%      u : Time-Domain:input histories in columns 
%          Frequency-Domain: frequency vector in Hz
%     x0 : initial conditions; x0=0 (zero initial condition)      
%      y : Time-Domain: output histories in columns 
%          Frequency-Domain: frequency response (complex-valued) 
%          y(z)=[frf(1,1) frf(2,1)...frf(m,r)], r,m = No. of inputs, outputs
%     dt : sampling time; Time-Domain(sec), Frequency-Domain (Hz)  
%     nd : number of reconstructed data points       
%   flag : flag=1 interactive plotting  
%                                                            
%OUTPUT PARAMETERS
%  The estimated output in the time domain is        
%	 x(k+1) = ax(k) + bu(k)-G{y(k)-y_e(k)}                
%    y_e(k) = cx(k) + du(k)                               
%  where x and y_e mean estimated state and output
%     G(z) = C(zI-A)^(-1)B+D; y_e=[G(1,1) G(2,1)...G(m,r)], 
%                             r,m = No. of inputs, outputs             

%         Jer-Nan Juang  12-17-94
%         NASA Structural Dynamics Branch      
[n_total,ck]=size(y); 
      if nd>n_total; nd=n_total; end;
  if max(abs(imag(y(:,1))))==0; 
     idflag=1; % Time-Domain ID
  else;
     idflag=2; % Frequency Domain OKID
  end;
   [m,n]=size(c);[n,r]=size(b); pf=ceil(n/m);
   if x0==0; x0=zeros(n,1); end;
if g==0 | isempty(g);
      if idflag==1;
         y_e=dlsim(a,b,c,d,u(1:nd,:),x0);
 		 despx='Time (sec)';
		 despy='Predicted (- -) and real outputs';
	  else;
%        y_e=[]; j=sqrt(-1);       
%		 z=exp(j*2*pi*dt*u(1:nd));
%        for i=1:r
%           frf=freqresp(a,b,c,d,i,z);%Save time for SISO system
%           y_e=[y_e frf];
%        end;
        y_e=obm2arx(a,b,c,d,0,pf,0);%Save time for MIMO system
        y_e=arxfrf(y_e,r,0,u(1:nd),dt);
		desptl='Predicted (- -) and Real FRFs';
	  end;
else;
      if idflag==1;
          a=a+g*c; b=[b+g*d -g]; 
          d=[d zeros(m,m)];
          y_e=dlsim(a,b,c,d,[u(1:nd,:) y(1:nd,:)],x0);
 		  despx='Time (sec)';
		  despy='Estimated (- -) and real outputs';
	  else;
		  desptl='Estimated (- -) and Real FRFs'
          y_e=obm2arx(a,b,c,d,g,pf,0);
          y_e=arxfrf(y_e,r,0,u(1:nd),dt);
       end;
end;
           if idflag==1; u=dt*[0:nd-1]'; end;
if flag==1; 
     clg
     if idflag==1;
            for kc=1:m;
              plot(u(1:nd),y(1:nd,kc),u(1:nd),y_e(1:nd,kc),'--')
               title(['No. ' num2str(kc) ' output plot']);
              xlabel(despx); ylabel(despy);pause;
			end;
	  else;
        n=0;
          for kb=1:r;
              for kc=1:m;
                n=n+1;
                subplot(211);
                semilogy(u(2:nd),abs(y(2:nd,n)),...
		                 u(2:nd),abs(y_e(2:nd,n)),'--');
                 title([desptl ' for input No. ' num2str(kb) ...
                       ' and output No. ' num2str(kc)]);
                  xlabel(['Frequency (Hz)']);ylabel(['Amplitude']);
                subplot(212),
		        plot(u(2:nd),angle(y(2:nd,n))/pi*180,...
				     u(2:nd),angle(y_e(2:nd,n))/pi*180,'--');
                  xlabel(['Frequency (Hz)']);ylabel(['Phase (deg)']);
				pause;
			  end;
		  end;
       end;
end;
