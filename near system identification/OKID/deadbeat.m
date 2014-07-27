function [g]=deadbeat(a,b,c,d);
%   Function arxpf_m computes past-in-time and future-in-time observer
%   Markov (ARX) parameters from a discrete-time model   
%
%   [g]=deadbeat(a,b,c,d);
%
%  INPUT 
%        a = discre-time state matrix (n X n)
%        b = discre-time input influence matrix (n X r)
%        c = output influence matrix (m X n)
%        d = direct transmission matrix (m X r)
%
%  OUTPUT
%        g = deatbeat observer if n/m=p is an integer, otherwise 
%            a stable observer if a is a stable and the system is 
%            controllable and observable
%

%
%      Jer-Nan Juang, NASA Langley Research Center, Hampton, VA 23681 
%      December 21, 1994
%

[ns,r]=size(b); [m,ns]=size(c); 
  p=ceil(ns/m);
  pt=10*(ceil(p*m/(r+m))+p+1);
%
u=randn(pt,r);
y=dlsim(a,b,c,d,u);
%
%  compute deatbeat observer Markov parameters
%
ybar=arxm(m,r,u,y,p,0,[0 0]);
%markovp=marcompf(ybar,0,r,p+1);
markovp=marcomp(ybar,0,r,p+1,0);
[ys,yo]=separate(markovp,m,r,m);      
     ob=c;
     temp=c;
     for i=2:p;
         temp=temp*a;
         ob=[ob;temp];
     end;
yo(:,1:m)=[];
yo=block_tr(m,p,m,yo,1); 
g=ob\yo;
