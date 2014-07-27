function [a,b,c,d,g]=okid_b(m,r,dt,u,y,desp,p)
% 
%     Function okid_b identifies a discrete model directly from       
%     arbitrary input and output data using arx backward approach
%     Multiple experiments may be used. 
%                                                                   
%     [a,b,c,d,g]=okid_b(m,r,dt,u,y,desp,p) 
%
%           INPUT PARAMETERS                                       
%                                                                   
%   m  = number of outputs                                   
%   r  = number of inputs                                    
%   dt = sample time (sec)                                   
%   u  = input histories stacked by columns for multi-exp. 
%        or frequency vector in the frequency domain
%   y  = output data stacked by columns for multi-exp.       
%        or frequency response (complex-valued) stored columnwise, i.e.,
%           the first m columns for the first input, etc. 
% desp = Information about data being analyzed                      
%      ='batch': perform a batch job.
%   p  =an integer (assumed number of modes=p*no. of outputs)
%                                                                  
%  The identified model with its corresponding observeris        
%		      x_e(k+1) = ax_e(k) + bu(k)-g{y(k)-y_e(k)}                
%   	      y_e(k) = cx_e(k) + du(k)                               
%     where x_e and y_e mean estimated state and output             
%

%         Jer-Nan Juang  12-22-94                             
%         NASA Spacecraft Dynamics Branch                           
%                                                                   

[a,b,c,d,g,x0]=idengine(m,r,dt,u,y,desp,0,p,[0 1 0]);
if isempty(g)==1;return;end;   
g=g(:,1:m);

