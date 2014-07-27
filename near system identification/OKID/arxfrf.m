function [frf]=arxfrf(ybar,r,pb,f,dt);
% ---------------------------------------------------------------------
%  Routine to to compute frf from observer (ARX) Markov parameters
%
%          [frf]=arxfrf(ybar,r,pb,f,dt)
%
% INPUT PARAMETERS
%   ybar = [[beta(pb) -alpha(pb)]...[beta(1) -alpha(1)] [beta(0) -alpha(0)]...
%           [beta(-1) -alpha(-1)]...[beta(-pf) -alpha(-pf)]]
%   r    = number of inputs
%   pb   = number of backward-time steps
%   f    = frequency points
%   dt   = sampling rate (Hz)
%
% OUTPUT PARAMETERS
%    frf = Frequency Response Function
% ---------------------------------------------------------------------

%  Jer-Nan Juang, NASA SDB

[m,nd]=size(ybar);
q=r+m;
pf=(nd-r-pb*q)/q;
ybar=[ybar(:,1:pb*q+r) -eye(m,m) ybar(:,pb*q+r+1:nd)];
j=sqrt(-1);
p=pf+pb;
z=exp(j*2*pi*dt*f);
nd=length(f);
frf=zeros(m,nd*r);
for i=1:nd;
    zk=z(i)^(pb+1); 
    QR=zeros(m,q);
    indexi=-q+1:0;
    for k=1:p+1;
        zk=zk/z(i); 
        indexi=indexi+q;
        QR=QR+ybar(:,indexi)*zk;
    end;
    frf(:,(i-1)*r+1:i*r)=-QR(:,r+1:r+m)\QR(:,1:r);
end;
frf=conj(m2p(frf,r));


       




   

