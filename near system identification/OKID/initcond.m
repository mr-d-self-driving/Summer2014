function x0=initcond(A,B,C,D,G,u,y,p)
% 
% Given: state space system matrices A,B,C,D,G, 
%        input u and output y
% Find: initial condition x0
%
% function x0=initcond(A,B,C,D,G,u,y,p)
%         
% Input 
%   A,B,C,D: system state space model
%         G: system observer
%         u: input data (The lenght must be >= p)
%         y: output measurements (The lenght must be >= p)
%         p: order of deadbeat observer {p*m(no. of ouputs)>=order of A}
%                               
% Output
%        x0: initial condition

%         Jer-Nan Juang  11-15-94
%         NASA Langley Research Center                           
Qbar=C;
f=D*u(1,:)';
CAk=C;
Abar=A+G*C;
if sum(find(abs(eig(Abar))>1))==0;
    Bbar=[B+G*D -G];
    QB=[];v=[];
    ybar=y(1,:)';
    for i=2:p;
        CAkB=CAk*Bbar;
        QB=[CAkB QB];
        v=[v;u(i-1,:)';y(i-1,:)'];
        f=[f; QB*v+D*u(i,:)'];
        CAk=CAk*Abar;
        Qbar=[Qbar;CAk];
        ybar=[ybar;y(i,:)'];
    end;
    x0=pinv(Qbar)*(ybar-f);
else;
	disp(['Fail to estimate Initial condition, because the observer']);
    disp(['is unstable.  The initial condition is set to zero.']);
    x0=zeros(length(A(:,1)),1);
end;
