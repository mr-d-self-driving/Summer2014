function [ybar, dbar]=dobm2arx(a,b,c,d,e,f,g,pf,pb);
% ---------------------------------------------------------------------
%  Routine to compute observer (ARX) Markov parameters
%  from system matrices and deadbeat observer gain
%
%          [ybar]=obm2arx(a,b,c,d,g,pf,pb);
%
% INPUT PARAMETERS
%   a,b,c,d = discrete-time system matrices
%         g = discrete-time observer gain
%             set g=0 or [] to find ARX parameters for arxfrf.m
%             to compute the system frf
%         pf= number of forward-time steps
%         pb= number of backward-time steps
%
% OUTPUT PARAMETERS
%   ybar = [[beta(0) -alpha(0)][beta(-1) -alpha(-1)] ...
%           [beta(-p+1) -alpha(-p+1)][beta(-p) -alpha(-p)]]
% ---------------------------------------------------------------------

%  Jer-Nan Juang, NASA SDB, 12/16/94

   [m,n]=size(c);[n,r]=size(b); [nd,rd] = size(f);
   if d==0 | isempty(d)==1; d=zeros(m,r); end;
   q=r+m; p=pf+pb;
if g~=0 & ~isempty(g);
ybar=zeros(m,(p+1)*q);
     abar=a+g*c;
     bbar=[b+g*d -g];
    ybar(:,1:r)=d;
    ybar(:,r+1:q)=-eye(m);
     temp=c;
    for i=1:p;
	   ybar(:,i*q+1:(i+1)*q)=temp*bbar;
	   temp=temp*abar;
    end;
     ybar=-ybar(:,pb*q+r+1:(pb+1)*q)\ybar;
     ybar(:,pb*q+r+1:(pb+1)*q)=[] ;
else;

%
% Generate an arx model for the system to compute frf 

    npt=10*(ceil(p*m/(r+m))+p+1);
    u=randn(npt,r);
    y=dlsim(a,b,c,d,u);
    ybar=armaxtd(m,r,u,y,pf,pb,[0 0]);
end;
qq = rd;
% Generate an ARX parameters for distrubance term
  dbar=zeros(m,(p+1)*qq); 
     ebar = e+g*f ;
     dbar(:,1:rd)=f
%     dbar(:,rd+1:qq)=-eye(m);
     temp=c;
    for i=1:p;
temp*ebar
	   dbar(:,i*qq+1:(i+1)*qq)=temp*ebar;
	   temp=temp*abar;
    end;
 

   

