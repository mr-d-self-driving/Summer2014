function [freq,HL,HH,SYU,SUU,SYY]=frffst(u,y,dt,bsize,Nolp,flag,iplot)
%
%      Routine to compute the Frequency Response Functions (FRF)
%      from multi-input and multi-output data
%
%    [freq,HL,HH,SYU,SUU,SYY]=frffst(u,y,dt,bsize,Nolp,flag,iplot)
%
% INPUT
%    y           = Sensor time history
%    u           = input time history
%    dt          = Sampling time
%    bsize       = block size for FRF (make it power of 2)
%    Nolp        = Percent Overlapping
%    flag=0      = Compute Fast FRF for SIMO tests using cross/auto (ONLY)
%    iplot       = Set to 1 plots FRF results
%
% OUTPUT
%    freq        = frequency points
%    HL          = FRF (Lower Bound) computed by SYU/SUU
%    HH          = FRF (Upper Bound) computed by SYY/SUY
%                   (not computed if flag==0)
%    SYU         = Scaled cross spectral density
%    SUU         = Scaled input auto-spectral density
%    SYY         = Scaled output auto-spectral density

%         L.G. Horta 1-28-93 Mod. 9-10-93

[ntotal,q]=size(y);
[ntotal,r]=size(u);
X=1-Nolp/100;
NuT=ntotal/X;
nbl=fix(NuT/bsize);
nblock=fix((ntotal/bsize-1)/X+1);
disp([' Number of Averages = ' num2str(nblock)])
half=bsize/2+1;
sguu=zeros(r,r*half);sgyu=zeros(q,r*half);sgyy=zeros(q,q*half);
Hhigh=zeros(q,r*half);Hlow=zeros(q,r*half);
wt=2/(dt*bsize);
T0=clock;
  for ip=1:nblock
      index=bsize*X*(ip-1)+1:bsize*X*(ip-1)+bsize;
      yip=y(index,:);
      uip=u(index,:);
%      yip=yip-ones(bsize,q)*diag(mean(yip));
      yd=fft(yip);
      ud=fft(uip);
      yd=yd.';ud=ud.';
      yd=yd(:).';ud=ud(:).';
         for i=1:r; 
           for j=1:r
             ij=j:r:r*half;
             ii=i:r:r*half;
             sguu(j,ii)=sguu(j,ii)+ud(ii).*conj(ud(ij));
           end
           for j=1:q;
             ij=j:q:q*half;
             ii=i:r:r*half;
             sgyu(j,ii)=sgyu(j,ii)+yd(ij).*conj(ud(ii));
           end
         end
         for i=1:q; 
           for j=1:q
              ij=j:q:q*half;
              ii=i:q:q*half;
              sgyy(j,ii)=sgyy(j,ii)+yd(ii).*conj(yd(ij));
           end
         end
    end
sguu=2*sguu/(bsize^2*nblock);
sgyu=2*sgyu/(bsize^2*nblock);
sgyy=2*sgyy/(bsize^2*nblock);
%
%            Computation of FRF using averaged Spectral Matrices
%
      if flag == 0,
         for ii=1:q;
           Hlow(ii,:)=sgyu(ii,:)./sguu;
         end
      else
         for km=1:half;
           br=[(km-1)*r+1:km*r];
           bq=[(km-1)*q+1:km*q];
           Hlow(:,br)=wt*sgyu(:,br)*pinv(wt*sguu(:,br));
           Hhigh(:,br)=wt*sgyy(:,bq)*pinv(wt*sgyu(:,br)');
         end
      end
freq=[0:half-1]'/(bsize*dt);
T1=etime(clock,T0)/60;
disp([' Time (min) to compute FRF ' num2str(T1)])
%
%            Plotting Results
% 
if iplot == 1;
disp([' Plotting and Organizing Output Matrices'])
HTh=m2p(conj(Hlow),r);HThm=abs(HTh);HThp=angle(HTh)*57.2958;
ERh=m2p(conj(Hhigh),r);ERhm=abs(ERh)/2;ERhp=angle(ERh)*57.2958;

   for ik=1:r
    for ij=1:q
       texto=[' Response due to input= ',num2str(ik),' output= ',num2str(ij)]; 
       NI= ij+(ik-1)*q;   
       clg
       subplot(211), semilogy(freq,HThm(:,NI))
       title(texto);
       xlabel('  Frequency (Hz) ')
       ylabel(' Mag.  ')
       subplot(212), plot(freq,HThp(:,NI))
       xlabel(' Frequency (Hz) ')
       ylabel(' Phase (Deg.) ')
       disp(' *******carriage return to continue*********')
       pause;
    end
   end
end
% 
%       Stacking of Spectra Matrices
%
SYU=zeros(q*r,half);SYY=zeros(q*q,half);SUU=zeros(r*r,half);
HL=zeros(q*r,half);HH=zeros(q*r,half); 
for j=1:q
   for i=1:r
      vs=[i:r:half*r];
      SYU((j-1)*r+i,1:half)=sgyu(j,vs);
      HL((j-1)*r+i,1:half)=Hlow(j,vs);
      HH((j-1)*r+i,1:half)=Hhigh(j,vs);
   end
end
clear Hhigh Hlow
for j=1:q
   for i=1:q
      vs=[i:q:half*q];
      SYY((j-1)*q+i,1:half)=sgyy(j,vs);
   end
end
for j=1:r
   for i=1:r
      vs=[i:r:half*r];
      SUU((j-1)*r+i,1:half)=sguu(j,vs);
   end
end
SYU=SYU.';SUU=SUU.';SYY=SYY.';HH=HH.';HL=HL.';


