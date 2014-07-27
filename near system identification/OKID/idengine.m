function [a,b,c,d,g,x0]=idengine(m,r,dt,u,y,desp,pf,pb,fg)
%
%     Function idengine identifies a discrete model directly from       
%     arbitrary input and output data or frequency response functions
%     Multiple experiments may be used.        
%                                                                   
%     [a,b,c,d,g,x0]=idengine(m,r,dt,u,y,desp,pf,pb,fg)
%
% INPUT PARAMETERS
%                                                                   
%    m = number of outputs                                   
%    r = number of inputs                                    
%    dt = sample time (sec)                                   
%    u = Time-Domain:input histories stacked by columns for multi-exp. 
%        Frequency-Domain: frequency vector in Hz
%    y = Time-Domain: output histories stacked by columns for multi-exp. 
%        Frequency-Domain:frequency response (complex-valued) 
%        if y(z)=C(zI-A)^(-1)B+D=[G1,...,Gm]
%        then y(z)=[G1.',...,Gm.']
%        u and y have the same columns or the longer one will be shortened
% desp = Information about data being analyzed                      
%      ='batch': perform a batch job.
%      ='batch_lq': perform a batch job using least squares.
%      ='batch_oc': perform a batch job for an observable canonical-form realization.
%      ='lq': use least squares to solve the observer gain (user interaction).
%      ='oc': observable canonical-form realization (user interaction).
%          *Any other string will require user interaction.*
%   pf = number of past time steps in the arx model 
%   pb = number of future time steps in the arx model 
%        (assumed number of modes = ((pf+pb)*m (no. of outputs))
%fg(1) =  0: Time-Domain: when experiments starts from rest       
%             Otherwise when experiments starts with some initial conditions
%         2: Frequency-Domain: including real and imag. parts only for computing 
%             observer parameters, otherwise only real part is used     
%fg(2) = 0: keep all modes; 
%      > 0: keep only stable modes; (needed for pb>0)
%      < 0: keep only unstable modes
%        
%fg(3) = 0: without residual whitening 
%      > 0: Number of iterations for residual whitening (system and Kalman filter) 
%            
%
% OUTPUT PARAMETERS                                       
%  a, b, c, d   = identified state, input, output, and direct transmission matrices   
% g(:,1:m)      = observer gain for state estimation
% g(:,m+1:2m)   = observer gain computed from system pulse response  
% x0 = identified initial state      
%

%The identified model with its corresponding observeris        
%		      x_e(k) = a^-1 x_e(k+1) - bu(k)-g(:,1:m){y(k+1)-y_e(k+1)}              
%   	      y_e(k) = cx_e(k) + du(k)                               
%     where x_e and y_e mean estimated state and output with intial             
%     condition vector x0 which is computed if flag(1)=1 in the time doamin
% 

%         Jer-Nan Juang  11-27-94                             
%         NASA Structural Dynamics Branch                           
%                                                                   
%*******************************************************************************
%*                    Initialization                              
%*******************************************************************************
eps=2.2204e-16;%Matlab internal tolerance for matrix pseudo-inverse and rank check.
if isempty(fg)==1 | length(fg)<3; 
   fg=[fg zeros(1,3-length(fg))]; 
end;
n_total=min(length(y(:,1)),length(u(:,1)));
y=y(1:n_total,:);u=u(1:n_total,:);
[n_total,ck]=size(y); 
  if max(abs(imag(y(:,1))))==0; 
     idflag=1; % Time-Domain OKID
     n_exp=ck/m; % Number of experiments
     despid='Time-Domain OKID';
	 despic=' Initial condition flag = ';
  else;
     idflag=2; % Frequency Domain OKID
     fnyq=u(n_total);
     dtmin=1/(2*fnyq);
     if dt > dtmin; %Check if given sample time is adequate
       dt=dtmin;
       disp([' New Sample Time is := ' num2str(dt)])
     end;
     n_exp=ck/(m*r);  % Number of experiments
     despid='Frequency-Domain OKID';
	 despic=' Real/imaginary flag = ';
  end;

format short e; format compact
p=pf+pb;                 % p*m will be the maximum order of system to be identified 
flag=0;                  % to compute and save computed observer Markov parameters.
q=r+m; q1=q;             % total number of inputs and outputs
    if strcmp(desp,'lq')==1 | strcmp(desp,'batch_lq')==1;q1=r;end;
    n_markov=3*ceil(p*m/q1)+p+1; %More columns than rows for eradc
disp(desp)
disp(despid)
disp([' Total number of sample points = ' num2str(n_total)])
disp([' Number of experiments in file = ' num2str(n_exp)])
disp([' Number of inputs (r) = ' num2str(r) ])
disp([' Number of outputs (m) = ' num2str(m) ])
disp([' Sample time (sec) = ' num2str(dt) ])
disp([' Number of forward-time steps (pf) = ' num2str(pf) ])
disp([' Number of backward-time steps (pb) = ' num2str(pb) ])
disp([' Maximum system order ((pf+pb)*m) = ' num2str(p*m) ])
disp([' Number of iterations for residual whitening = ' num2str(fg(3)) ])
%disp([' Number of computed Markov parameters = ' num2str(n_markov) ])
disp([despic, num2str(fg(1)) ]);
%
%*******************************************************************************
%*    Computation of Observer Parameters from Multiple Experiments             *
%*******************************************************************************
    ic=[fg(1) 1 fg(3)];n_order=0;
if strcmp(desp,'batch')==1|strcmp(desp,'batch_lq')==1|strcmp(desp,'batch_oc')==1;
     ic=[fg(1) 0 fg(3)];n_order=p*m;
else;
     flag=input(['Re-run OKID with same ', ...
                'data & input parameters (1=yes,0=no) ?:= ']);
end;
    if flag==0; 
	   if idflag==1;
          ybar=armaxtd(m,r,u,y,pf,pb,ic);
       else;
          ybar=armaxfd(y,u,dt,r,pf,pb,ic); 
	   end;
        save dokid ybar m r dt p pf pb n_markov
    else;
        load dokid;
        disp([' Some parameters used before were:']); 
        disp([' Observer Markov parameter No., p = ' num2str(p) ])
        if  strcmp(desp,'batch_oc')~=1 & strcmp(desp,'oc')~=1 & pb==0; 
           disp([' System Markov parameter No., n_markov= '...
                   num2str(n_markov) ])
           i=input('Do you want to change n_markov (1=yes,0=no) ?:= ');
              if i==1;
                n_markov=input(['New number (>= ',num2str(n_markov),...
                             ' preferred) for n_markov = ']);
              end;
		end;         
    end;

%*******************************************************************************
%*                Observable canonical-form realization                        *
%*******************************************************************************
kpidx=1;gp=[];
if strcmp(desp,'oc')==1 | strcmp(desp,'batch_oc')==1 | pb~=0;
   timer1 = clock;
      if fg(3)~=0; % Kalman filter parameters should be removed.
	    q=r+m;m2=m+m; q1=r+m2; nd=length(ybar(1,:));
        idx1=[q+1:q1:pb*q1 pb*q1+r+q+1:q1:nd]; idx=idx1;
		for k=1:m-1;
		  idx1=idx1+1; idx=[idx idx1]; 
		end;
		ybar(:,idx)=[];
      end; 
   [a,b,c,d,g,lambda]=ocompan(ybar,pb,r,dt,[ic(2) fg(2)]);
   timer2=etime(clock,timer1)/60;
   disp([' Time (min) to compute observable canonical form ' num2str(timer2)]);
else;
%*******************************************************************************
%*                 Recovering true parameters                                  *
%*******************************************************************************
   timer1 = clock;
       markovp=marcomp(ybar,pb,r,n_markov,fg(3));clear ybar;
   timer2=etime(clock,timer1)/60;
   disp([' Time (min) to compute Markov parameters ' num2str(timer2)]);
%*******************************************************************************
%*                  System Realization Using ERA                            *
%*******************************************************************************
   timer1 = clock;
   if strcmp(desp,'lq')==1 | strcmp(desp,'batch_lq')==1;
%
%   Partition combined Markov parameters into system markov parameters ys
%   and observer gain Markov parameters yo
%
       [ys,yo]=separate(markovp,m,r,m);clear markovp;      
%      yo(:,1:m)=[];
       ps=m2p(ys,r);clear ys
%
%  Use ERADC to compute a state space model and least-squares to
%  compute the observer gain
%
        [a,b,c,d,gp,sv,lambda]=eradc(ps,[1 1 fg(2) 0],r,n_order,p,dt);
        g=gp(:,1:m);
%
%  Use ERADC to simultaneously compute a state space mode and the observer gain 
%  
   else;
      q=r+m;
      ps=m2p(markovp,q);clear markovp; 
      [a,bg,c,d,gp,sv,lambda]=eradc(ps,[1 1 fg(2) m],q,n_order,p,dt);
%		  [a,b,c,d,gp,sv,lambda]=eradc(ps,[0 0 0 0],r,4,p,dt);
     
      b=bg(:,1:r);
      g=bg(:,r+1:q);clear bg;
      d=d(:,1:r);
      kpidx=find(abs(eig(a+gp(:,1:m)*c))>1);
   end;
   clear ps;
   timer2=etime(clock,timer1)/60;
   disp([' Time (min) to compute a system model ' num2str(timer2)]);
   if sv(1)>1.0e12;
     disp(['    '])
     disp(['Warning! Warning! Warning!'])
     disp(['Some Hankel singular values are considerably large (>10e12).'])
     disp(['The identified system may have unstable system and/or noise'])
     disp(['modes.  Re-run the program using the option for observable'])
     disp(['canonical-form realization. Compare both results and choose'])
     disp(['the reasonable one (see guide for the user).'])
     disp(['    '])
   end;
end;
%
%  Check if observer is stable 
%  
istbl=1;
k=find(abs(eig(a+g*c))>1);
if sum(k)~=0;
   if sum(kpidx)~=0;
       disp(['    '])
       disp(['Warning! Warning! Warning!'])
       disp(['The identified observer is unstable.  Re-run the program'])
       disp(['and keep the size of the identified model larger.'])
       disp(['    '])
       istbl=0;
       disp(['Note that estimated output will not be ploted.  Initial'])
       disp(['condition will not be computed if required.'])
       disp(['    '])
   else;
     disp(['Observer computed from ERA is used.'])
     g=gp(:,1:m);%Least square observer is used
   end;
end;  
%*******************************************************************************
%*                   Compute Initial Conditions                                *
%*******************************************************************************
       if isempty(lambda)==1;return;end;   
       [ns,ns]=size(a); 
       x0=zeros(ns,n_exp);
       if fg(1)~=0 & idflag==1;
           for ie=1:n_exp;
                k=(ie-1)*r+1:ie*r; j=(ie-1)*m+1:ie*m;
                  x0(:,ie)=initcond(a,b,c,d,g,u(:,k),y(:,j),p);
           end;
        end;
%*******************************************************************************
%*          System Stabilization for Frequency Domain ID                       *
%*******************************************************************************
   if isempty(lambda)==1;return;end;   
   if fg(2)==0 & idflag==2 & pb==0 & sum(find(lambda(:,1)<0));
      [a,b,c,d]=unsb2sb(a,b,c,d,u,dt,[0 0 ic(2)]);
   end;
%*******************************************************************************
%*                            Data Reconstruction                              *
%*******************************************************************************
if strcmp(desp,'batch')~=1 & strcmp(desp,'batch_lq')~=1 & strcmp(desp,'batch_oc')~=1;
  i2=input('Compare Recons. Output and True output (1=yes,0=no) ?:= ');
           if isempty(i2)==1; i2=0; end;
  if i2 == 1;
    for ie=1:n_exp;
      npts=input('Number of Sample Points to Reconstruct ?:= ');
            if npts>n_total | isempty(npts)==1; npts=n_total; end;
         disp(['Comparison For Data Set Number No. ' num2str(ie)])
         k=(ie-1)*r+1:ie*r; j=(ie-1)*m+1:ie*m;
           if idflag==2; k=ie; j=(ie-1)*r*m+1:ie*r*m; end; 
         disp(['The following figures show predicted and real outputs'])
         y_p=yog_cal(a,b,c,d,0,u(:,k),x0(:,ie),y(:,j),dt,npts,1);
 
         if istbl==1 & idflag==1;
           disp(['The following figures show estimated and real outputs'])
           y_p=yog_cal(a,b,c,d,g,u(:,k),x0(:,ie),y(:,j),dt,npts,1);
	     end;

      if n_exp > 1 & ie < n_exp;
        fg1=input('Continue for the next data set (1=yes,0=no) ?:= ');
        if fg1~=1; break; end;    
      end;
    end;
  end;
end;
g=[g gp];         
