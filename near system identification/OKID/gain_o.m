function go=gain_o(obs,y,r,iobs)
% 
%	   Compute deatbeat or almost control gain and observer 
%      gain from pulse response functions
%                                                              
%    go=gain(obs,y,r,iobs)     
%                                                              
%INPUT PARAMETERS
% obs : observability matrix
%   y :[y_1 y_2 y_3... y_ni];                                 
%       y_i = response samples due to a unit pulse            
%             at the i-th input                               
%   r : number of input
% iobs: maximum order of obs (if unknow, set iobs=0)
%                                                              
%OUTPUT PARAMETERS
%  go : observer gain for state estimation such that a+go*c is stable                        
%       (deadbeat gain for noise-free data)

%         J. N. Juang 1-9-95
%         NASA Spacecraft Dynamics Branch                           
%
   [nd,mr]=size(y); m=mr/r; 
   [no,n]=size(obs); po=no/m;
   if iobs<n; iobs=n; end;
%
% Transform the pulse response form into the Markov parameter form
% and generate the data correlation matrix
%
    Markov=p2m(y,r); 
    np=ceil(n/m)+iobs-n;%empirical number
    [d,R]=hankldc(Markov,r,np+1);
%
%  Compute observer gain
%
     yo=R(np*m+1:(np+1)*m,1:np*m)*pinv(R(1:np*m,1:np*m));
     idx=[];
     for i=1:np;
	    idx=[(i-1)*m+1:i*m idx];
	 end;
	 yo=yo(:,idx);
	 yo=marcomp(yo,0,0,po+1,0);yo(:,1:m)=[];
     yo=block_tr(m,po,m,yo,1);
     go=obs\yo;
