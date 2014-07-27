function [a,b,c,d]=okid_fq(r,f,dt,Gz,desp,p)
%
%     Function okid_fq identifies a discrete model directly from       
%     system frequency response data. 
%                                                                   
%     [A,B,C,D]=okid_fq(r,f,dt,Gz,desp,p)
%
%           INPUT PARAMETERS                                       
%                                                                   
%  r   = number of inputs                                    
%  f   = frequency vector
%  dt  = sample time
%  Gz  = frequency response (complex-valued) 
%        if G(z)=C(zI-A)^(-1)B+D=[G1,...,Gm]
%        then Gz=[G1.',...,Gm.']
% desp = Information about data being analyzed                     
%      ='batch': It performs the batch job.
%          *Any other string will require user interaction.
%  p   = an integer (assumed number of states=p*no. of outputs)
%                                                                   
%       The identified model is        
%		      x(k+1) = Ax(k) + Bu(k)                
%   	      y(z) = Cx(k) + Du(k)                               
%       where x and y mean system state and output
%  
%        The Matrix Description Model is also provided in the form
%         y(z)=A(z)^(-1)*B(z)u(z)           
%                                                                  

%         Jer-Nan Juang  4-13-95                             
%         NASA Spacecraft Dynamics Branch                           
%                                                                   
disp(desp)
desp1='oc';
  if strcmp(desp,'batch')==1; desp1='batch_oc'; end;
  [n_total,rm]=size(Gz);
  m=rm/r;
[a,b,c,d,g,x0]=idengine(m,r,dt,f,Gz,desp1,p,0,[0 0 0]);

