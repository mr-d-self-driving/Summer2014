function [ys,yo]=pulse(m,r,u,y,pf,pb,n_pulse,ic)
% 
%     Compute unit pulse respone samples from experimental data  
%     using identified observer Markov parameters.                                                             
%
%     [ys,yo]=pulse(m,r,u,y,pf,pb,n_pulse,ic)
%
%     INPUT PARAMETERS                                       
%                                                                   
%  m     = number of outputs                                   
%  r     = number of inputs                                    
%  u     = input histories stacked by columns for multi-exp
%  y     = output histories stacked by columns for multi-exp
%  pf    = an integer (forward-time steps)
%  pb    = an integer (Backward-time steps)
%n_pulse = desired number of pulse response samples
%   ic(1) = Flag set to 0 when experiments start from rest       
%           otherwise when experiments have initial conditions involved       
%   ic(2) = Flag set to 0 for a batch job; prediction error 
%           won't be computed.
%
%     OUTPUT PARAMETERS 
%   ys =[ys_1 ys_2 ys_3,...,ys_r]; n_pulse rows by r*m columns                          
%        ys_i = response samples due to a unit pulse at the i-th            
%               input; each ys_i has m columns and n_pulse rows.                                
%   yo =[yo_1 yo_2 yo_3,...,yo_m]; n_pulse rows by m*m columns                        
%        yo_i = observer gain response samples due to a unit pulse            
%              at the i-th input; each yo_i has mcolumns and n_pulse rows.                               
%
%      Assuming a zero-order hold on the input and sample time dt.                                              

%          J. N. Juang 12-1-91                                       
%         NASA Spacecraft Dynamics Branch                           

%
%  Compute Observer Parameters from Multiple Experiments             
%  and recover true combined Markov parameters
%
       [p_arx]=armaxtd(m,r,u,y,pf,pb,ic);
       [p_true]=marcomp(p_arx,pb,r,n_pulse,0);clear p_arx;
%
%   Partition combined Markov parameters into system pulse response ys
%   and observer gain pulse response yo. . 
%
      [ys,yo]=separate(p_true,m,r,m);clear p_true;      
      ys=m2p(ys,r);
      yo=m2p(yo,m);



