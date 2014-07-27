function pulse=m2p(Markov,ni)
% 
% Routine to Rearrange the Markov parameters in the pulse    
% response form                                            
%                                                              
% function pulse=m2p(Markov,ni)                         
%     
% INPUT PARAMETERS                                                         
%  Markov= [D CB CAB ... C(A^p)B];
%  ni    = Number of inputs;                                
%         Note that for combined System/Observer Markov parameters                            
%         B becomes [B G] and ni becomes ni + no (number of outputs)          
%              
% OUTPUT PARAMETERS
%  pulse = [y_1 y_2 y_3...y_ni];                              
%  y_i = response samples due to a unit pulse at the i-th input                                                   

%         L. G. Horta and J. N. Juang  6-25-91
%         NASA Spacecraft Dynamics Branch                           

      [nrow,ncol]=size(Markov);
      pulse=[];
        for i=1:ni
           pulse=[pulse Markov(:,i:ni:ncol)'];
        end
 
