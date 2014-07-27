function gc=gain_c(ctr,y,r,ictr)
% 
%	   Compute deatbeat or almost control gain  
%      from pulse response functions 
%                                                              
%    gc=gain_c(ctr,y,r,ictr)     
%                                                              
%INPUT PARAMETERS
% ctr : controllability matrix
%   y :[y_1 y_2 y_3... y_ni];                                 
%       y_i = response samples due to a unit pulse            
%             at the i-th input                               
%   r : number of input
% ictr: maximum order of ctr (if unknow, set ictr=0) 
%                                                              
%OUTPUT PARAMETERS
%  gc : control gain for full state feedback such that u=-gc'*x
%       (deadbeat gain for noise-free data)

%         J. N. Juang 1-9-95
%         NASA Spacecraft Dynamics Branch                           
%
   [nd,mr]=size(y); m=mr/r; 
   [n,nc]=size(ctr); pc=nc/r;
   if ictr<n; ictr=n; end;
%
% Transpose of the Markov parameters and generate the data correlation matrix
%
    Markov=p2m(y,r); 
    Markov=block_tr(m,nd,r,Markov,1);
    Markov=Markov';
    np=ceil(n/r)+ictr-n;%empirical number
    [d,R]=hankldc(Markov,m,np+1);
%
%  Compute controller gain
%
     yo=R(np*r+1:(np+1)*r,1:np*r)*pinv(R(1:np*r,1:np*r));
     idx=[];
     for i=1:np;
	    idx=[(i-1)*r+1:i*r idx];
	 end;
	 yo=yo(:,idx);
	 yo=marcomp(yo,0,0,pc+1,0);yo(:,1:r)=[];
     yo=block_tr(r,pc,r,yo,1);
     gc=ctr'\yo;
	 gc=-gc';
