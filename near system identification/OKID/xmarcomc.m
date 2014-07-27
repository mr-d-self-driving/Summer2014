%
%           Identification routine demonstration using real
%           test data from an aircraft flutter test data.
%
load samp712 
ue(1:600)=[];y(1:600)=[];u(1:600)=[];
[Ybar]=arxc(y,-u,ue,30);
[H]=marcomc(Ybar,1,1,30)
