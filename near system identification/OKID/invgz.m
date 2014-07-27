function H=invgz(Gz,m,dt)
%
%         Function to compute the pulse response from a transfer 
%         function estimate
%
%         H=invgz(Gz,m)
%      Input
%         Gz =  Complex transfer function stacked in column format
%         m  =   Number of outputs
%         dt =    Sampled time
%
%     Output
%         H  =    Pulse response stacked columnwise
%

%      Created by L.G. Horta   9-22-93
[s1,s2]=size(Gz);
r=fix(s2/m);
L1=[1:s1]';L2=[s1:-1:2]';
Yd1=Gz(L1,:);
Yd2=conj(Gz(L2,:));
Yd=[Yd1; Yd2];
H=ifft(Yd);

