%
%             Example using frequency domain subroutines
%
% Data is from CEM evolutionary model.
% FRF for thruster #1 stored in thruster1.mat 
% FRF for thruster #2 stored in thruster2.mat 
% Number of inputs in each file is 1
% Number of outputs in each file is 4
%
r=0;
load thrust1;r=r+1;
%Gz=[y1.']; p=25;
%Gz=[y1.' y2.'];p=10; 
Gz=[y1.' y2.' y3.' y4.'];p=10;
load thrust2;r=r+1;
%Gz=[Gz y1.'];p=25;
Gz=[Gz y1.' y2.' y3.' y4.'];p=15;
%Gz=[Gz y1.' y2.'];p=15;  
%Gz=Gz(1:3:nd,:);dx1=3*dx1;
[nd,n]=size(Gz);
clear y1 y2 y3 y4
df=dx1;
f0=mx1;
f=[f0:df:f0+df*(nd-1)]';dt=1/(2*df*(nd-1));
[n_total,rm]=size(Gz);
m=rm/r;
%[A,B,C,D]=okid_fq(r,f,dt,Gz,'okidfq',p);
%[A,B,C,D]=okid_fqw(r,f,dt,Gz,'batch',p,5);
[A,B,C,D]=okid_fqw(r,f,dt,Gz,'oc',p,5);


