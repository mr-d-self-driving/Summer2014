function [a,b,c,d,g]=okid(m,r,dt,u,y,desp,p)
%
%     Function okid identifies a discrete model directly from       
%     arbitrary input and output data. Multiple experiments         
%     may be used.        
%                                                                   
%     [A,B,C,D,G]=okid(m,r,dt,u,y,desp,p)               
%
%     INPUT PARAMETERS                                       
%                                                                   
%  m   = number of outputs                                   
%  r   = number of inputs                                    
%  dt  = sample time (sec)                                   
%  u   = input histories stacked by columns for multi-exp. 
%  y   = output data stacked by columns for multi-exp.       
% desp = Information about data being analyzed                      
%      ='batch': perform a batch job.
%      ='batch_lq': perform a batch job using least squares.
%      ='batch_oc': perform a batch job for an observable canonical-form realization.
%      ='lq': use least squares to solve the observer gain (user interaction).
%      ='oc': observable canonical-form realization (user interaction).
%          *Any other string will require user interaction.*
%  p   = an integer (assumed number of modes=p*no. of outputs)
%                                                                   
%  The identified model with its corresponding observeris        
%		      x_e(k+1) = Ax_e(k) + Bu(k)-G{y(k)-y_e(k)}                
%   	      y_e(k) = Cx_e(k) + Du(k)                               
%     where x_e and y_e mean estimated state and output             

%          J. N. Juang 12-22-94                                       
%         NASA Structural Dynamics Branch                           

[a,b,c,d,g,x0]=idengine(m,r,dt,u,y,desp,p,0,[1 0 0]);
g=g(:,1:m);
 

