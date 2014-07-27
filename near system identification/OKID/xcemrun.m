%
%             Example using frequency domain subroutines
%
% Data is from CEM evolutionary model. Test data was incomplete and some 
% of the cross spectra terms are initialized to zero.
% Number of inputs in file is 2
% Number of outputs in file is 8
% This example uses 1in-1out
%
load cemdata
[ntot,junk]=size(YU_cross);
f=fhz;
df=fhz(2)-fhz(1);
fny=f(ntot);
dt=1/(2*fny);
r=1;
m=1;
SUU=zeros(ntot,r*r);
SYY=zeros(ntot,m*m);
%
%         Data from Testbed is incomplete
%         Fill in missing info with zeros
%
IM=1;
Vyy=[];
Vyu=[];
Vuu=[];
Vyy=[1:m+1:m*m];
Vuu=[1:r+1:r*r];
IM=[1:m];
IR=1;
  for j=1:r
    tm=IM+8*(j-1);
    Vyu=[Vyu tm];
   end
Gz=Y_frf(:,Vyu);
SYU=conj(YU_cross(:,Vyu));
SYY=[];
SUU(:,Vuu)=U_auto(:,1:r);
%
%       Skipping frequency points
%
%Vs=[1:640 641:10:2048];
%Vs=[1:320];
Vs=[1:64 65:2:640];
SUU=SUU(Vs,:);SYU=SYU(Vs,:);
Gz=Gz(Vs,:);f=fhz(Vs);
[ntot,jj]=size(Gz);
dt=1/(2*f(ntot));
L=[1:ntot]';
P=20;
[A1,B1,C1,D1]=okid_sp(r,f,dt,Gz,SUU,SYU,SYY,'OKIDASF ',P,0);
%[A2,B2,C2,D2,Az2,Bz2]=okid_fq(r,f,dt,Gz,' OKIDFQM',P);

