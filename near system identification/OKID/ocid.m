function [A,B,C,D,G,F]=ocid(v,ufb,y,dt,desp,p)
%  -----------------------------------------------------------------------------
%  Routine to identify the system matrices A, B, C, D, observer gain matrix G,
%  and controller gain matrix F from experimental data which include feedback
%  control input ufb, additive input excitation v, and output closed-loop
%  response y.
%
%             [A,B,C,D,G,F]=ocid(v,ufb,y,dt,desp,p)
%
%  INPUT VARIABLES
%    v = additive excitation to feedback control input
%        stacked by columns
%  ufb = feedback control input stacked by columns
%    y = output of closed-loop system under excitation
%        stacked by columns 
%   dt = discrete sampling interval
% desp = Information about data being analyzed                     
%      ='lq' realizes A, B, C, D first, and then computes G, F from
%      ='batch': It performs the batch job.
%      ='batch_lq': It performs the batch job using least squares.
%          *Any other string will require user interaction
%           and realizes A, B, C, D, G, F simultaneously
%    p = number of desired observer/controller Markov parameters
%          to be computed
%            
%   OUTPUT VARIABLES
% A, B, C, D = identified system matrices
%          G = identified observer gain
%          F = identified controller gain
%-------------------------------------------------------------------------------

%  M. Phan, NASA SDB. Revised Nov. 18, 1991.
%  Jer-Nan Jaung, revised Mar.31, 1995

%  Computation of observer/controller Markov parameters
%
[N,r]=size(ufb);[N,m]=size(y);
    q=r+m; 
    if strcmp(desp,'lq')==1 | strcmp(desp,'batch_lq')==1;q=r;end;
    n_markov=3*ceil(p*m/q)+p+1; %More columns than rows for eradc
disp(desp)
disp([' Total number of sample points = ' num2str(N)])
disp([' Number of inputs (r) = ' num2str(r) ])
disp([' Number of outputs (m) = ' num2str(m) ])
disp([' Sample time (sec) = ' num2str(dt) ])
disp([' Number of forward-time steps (p) = ' num2str(p) ])
disp([' Maximum system order (p*m) = ' num2str(p*m) ])
%disp([' Number of computed Markov parameters = ' num2str(n_markov) ])
%
%*******************************************************************************
%*    Computation of Observer Parameters from data             
%*******************************************************************************
  flag=0;n_order=0;
if strcmp(desp,'batch')==1|strcmp(desp,'batch_lq')==1|strcmp(desp,'batch_oc')==1;
    n_order=p*m;
else;
    flag=input(['Re-run OCID with same ', ...
                'data & input parameters (1=yes,0=no) ?:= ']);
end;
    if flag==0; 
         [ybar]=arxc(y,ufb,v,p);
         save docid ybar m r dt p n_markov
    else;
        load docid;
        disp([' Some parameters used before were:']); 
        disp([' Observer Markov parameter No., p = ' num2str(p) ])
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
%*                 Recovering true parameters                                  *
%*******************************************************************************
timer1 = clock;
markovp=marcomc(ybar,m,r,n_markov);
if strcmp(desp,'lq')==1 | strcmp(desp,'batch_lq')==1;
%
%  Realize A, B, C, D using eradc and 
%  then compute G and F using least squares
%
 [cab,cag]=separate(markovp,m+r,r,m);clear markovp;      
  fab=cab(m+1:m+r,:); fab(:,1:r)=[];
  cab=cab(1:m,:); cag=cag(1:m,:); cag(:,1:m)=[]; 
  ps=m2p(cab,r); 
  [A,B,C,D,gp,sg,mh]=eradc(ps,[0 0 0 0],r,n_order,p,dt);
  [n,n]=size(A);V=B; Bi=B; W=C; Ci=C;
    for i=1:n-1;
	  Bi=A*Bi; V=[V Bi]; 
      Ci=Ci*A; W=[W;Ci];
    end;
  F=-fab(:,1:r*n)*pinv(V);
  G=pinv(W)*block_tr(m,n,m,cag,1);
else;
%  
% Use eradc to simultaneously realize A, B, C, D, G, and F as follows
%
  q=r+m;
  p1=ceil(p*m/q);
  ps=m2p(markovp,r+m);clear markovp; 
  [A,B,C,D,gp,sgdg,mhgf]=eradc(ps,[0 0 0 m],r+m,n_order,p1,dt);
  G=B(:,r+1:q); B=B(:,1:r);
  F=-C(m+1:q,:);C=C(1:m,:);D=D(1:m,1:r);
% Note that This does not work well for noise-free cases,
% unless sufficient large p is chosen.
end;
timer2=etime(clock,timer1)/60;
disp([' Time (min) to compute a system model ' num2str(timer2)]);
%
%
% Recontruct closed-loop response using identified observer and controller
%
if strcmp(desp,'batch')~=1 & strcmp(desp,'batch_lq')~=1;
 flag2=input('Compare closed-loop reconst. and actual resp. (1=yes,0=no) ?:= ');
 if flag2 == 1;
   npoints=input('Number of sample points to reconstruct ?:= ');
   if npoints>length(v(:,1)); npoints=length(v(:,1)); end;
   time=[0:dt:(npoints-1)*dt];
   yol_p=dlsim(A,B,C,D,v(1:npoints,:));
   disp('  ')
   disp('    Predicted open-loop and actual closed-loop responses') 
     for i=1:m;
       plot(time,[yol_p(1:npoints,i),y(1:npoints,i)])
       xlabel(' Time (sec)')
       ylabel(' Pred. Open-Loop and Act. Closed-Loop Resp.')
       title([' Output Number = ' num2str(i)])
       pause
     end;
   [ufb_rec,y_rec]=y_closed(A,B,C,D,G,F,y,ufb,v);
   disp('    Actual vs. reconstructed closed-loop responses')
     for i=1:m;
       plot(time,[y(1:npoints,i),y_rec(1:npoints,i)])
       xlabel(' Time (sec)')
       ylabel(' Act. vs. Reconst. Closed-Loop Response')
       title([' Output Number = ' num2str(i)])
     pause
     end;
   disp('    Actual vs. reconstructed feedback control input histories')
     for i=1:r;
       plot(time,[ufb(1:npoints,i),ufb_rec(1:npoints,i)])
       xlabel(' Time (sec)')
       ylabel(' Act. vs. Reconst. Feedback Control Input')
       title([' Input Number = ' num2str(i)])
       pause;
     end;
 end;
end;        
    
