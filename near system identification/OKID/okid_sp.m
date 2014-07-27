function [a,b,c,d]=okid_sp(r,f,dt,Gz,ruu,ryu,ryy,desp,p,iop)
%
%     Function okid_sp identifies a discrete model directly from       
%     system spectral matrices. Unevenly spaced frequency points 
%     accepted. 
%                                                                   
%     [a,b,c,d]=okid_sp(r,f,dt,Gz,ruu,ryu,ryy,desp,p,iop)
%
%     INPUT PARAMETERS                                       
%                                                                   
%  r   : number of inputs                                    
%  f   : frequency vector
%  dt  : Sample time
%  Gz  : Estimated transfer function stacked column-wise (for comparison only)
%        This may be an empty matrix or zero if desp='batch'
% ruu  : Input Auto spectra stacked like Gz (N x (r*m));m=No. of outputs
% ryu  : Cross-correlation stacked like Gz (N x (r*r))
% ryy  : Output Auto spectra stacked like Gz (N x (m*m))
% desp : Information about data being analyzed                     
%      :'batch': It performs the batch job.
%          *Any other string will require user interaction.
%  p   : an integer (assumed number of states=p*no. of outputs)
%  iop : iop=1 for no process noise solution
%                                                                   
%  The identified model is        
%		      x(k+1) = Ax(k) + Bu(k)                
%   	      y(k) = Cx(k) + Du(k)                               
%     where x and y mean system state and output 

%  
%  The Matrix Description Model is also provided in the form
%         y(z)=A(z)^(-1)*B(z)u(z)           
            

%        L. G. Horta and J.N. Juang 6-14-93, Modified 4-14-95                                      
%         NASA Structural Dynamics Branch
%         Uses a Left Matrix Fraction Description

%*******************************************************************************
%*                    Initialization                              
%*******************************************************************************
format short e; format compact;
[n_total,rm]=size(ryu);
fnyq=f(n_total);
dtmin=1/(2*fnyq);
% 
%         Check is given sample time is adequate
%
  if dt > dtmin; 
    dt=dtmin;
    disp([' New Sample Time is := ' num2str(dt)])
  end
%
 m=rm/r;
disp(desp)
disp([' System ID directly from spectral matrices ' ]);
disp([' Total number of sample  points = ' num2str(n_total)]);
disp([' Number of inputs (r) = ' num2str(r) ]);
disp([' Number of outputs (m) = ' num2str(m) ]);
disp([' Sample time = ' num2str(1/dt) ' Hz']);
disp([' Number of forward-time steps (p) = ' num2str(p) ])
disp([' Maximum system order (p*m) = ' num2str(p*m) ])
disp([' Upper & lower bound FRF Flag = ' num2str(iop) ])
%
%*******************************************************************************
%*    Computation of Observer Markov Parameters 
%*******************************************************************************
  fg=1;flag=0;
  if strcmp(desp,'batch')==1; 
      fg=0; 
   else;
      flag=input(['Have you run OKID with the same ', ...
              'data & p before (1=yes,0=no) ?:= ']);
   end;
if flag==0;  
      timer1 = clock;
    ybar=arx_sp(ruu,ryu,ryy,f,dt,r,p,iop);
      timer2=etime(clock,timer1)/60;
      disp([' Time (min) to compute ARX parameters ' num2str(timer2)]);
    save dokid_sp ybar m r dt p;
else;
    load dokid_sp;
      disp([' Some parameters used before were:']); 
      disp([' ARX parameter No., p = ' num2str(p) ])
end;
[a,b,c,d,g,lambda]=ocompan(ybar,0,r,dt,[fg 0]);
 if sum(find(lambda(:,1)<0));
   [a,b,c,d]=unsb2sb(a,b,c,d,f,dt,[0 0 fg]);
 end;
%*******************************************************************************
%*                            Data Reconstruction                              *
%*******************************************************************************

    if strcmp(desp,'batch')~=1;
      ifg=input('Compare Recons. FRF and Real FRF (1=yes,0=no) ?:= ');
      if ifg == 1;
      npts=input('Number of Sample Points to Reconstruct ?:= ');
            if npts>n_total | isempty(npts)==1; npts=n_total; end;
%        [Gz_id]=frfm(a,b,c,d,Gz,f,dt,n_total,1);
        Gz_id=yog_cal(a,b,c,d,0,f,0,Gz,dt,npts,1);
      end;
    end;
 

