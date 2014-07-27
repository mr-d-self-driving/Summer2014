function [vst]=uy_stack(u,y,p)
% 
%     Routine to stack the input matrix for least squares     
%                                                             
%     vst=uy_stack(u,y,p)                   
%                                                             
%     INPUT PARAMETERS                                  
%                                                             
%      u     = input time histories                                
%      y     = output time histories                              
%      p     = assumed system order                         
%                          
%     OUTPUT PARAMETERS
%                                 
%      vst   =matrix of dimension [(r+n)p+r]xL                

%     L.G. Horta,  5/25/91                                              
%     NASA Spacecraft Dynamics Branch                                                

[L,n]=size(y);[L,r]=size(u);
u=u';y=y';
vst=u;
        for i=1:p
            ncr=1:L-i;
            vst=[vst; zeros(n+r,i) [u(:,ncr); y(:,ncr)]];
        end
