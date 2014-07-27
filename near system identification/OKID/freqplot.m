function [mag,phase,mag2,phase2,w]=freqplot(a,b,c,d,a2,b2,c2,d2,p,dt,iu)
%
%
% function [mag,phase,mag2,phase2,w]=freqplot(a,b,c,d,a2,b2,c2,d2,p,dt,iu)
%
%      Subroutine to plot frequency responses 
%      for discrete systems 
%
%   a,b,c,d      =       discrete system matrices
%   a2,b2,c2,d2, =       dis. system to be compared
%   p            =       number of sample points
%   dt           =       time step
%   iu           =       input number used for ploting
fnyq=pi/dt;      % radians/sec
fnyqhz=fnyq/(2*pi);
disp([' Nyquist frequency (Hz) is = ' num2str(fnyqhz)])
lowf=input( ' Enter lower frequency to plot (Hz)= ');
upf=input(' Enter % of nyquist freq. to plot (Hz)= ');
fnyq=fnyq*upf/100;
dd2=log10(fnyq);
dd1=log10(lowf);
w=logspace(dd1,dd2,p);
wht=w*dt;
G1=freqresp(a,b,c,d,iu,exp(sqrt(-1)*wht));
G2=freqresp(a2,b2,c2,d2,iu,exp(sqrt(-1)*wht));
mag=abs(G1);phase=180/pi*angle(G1);
mag2=abs(G2);phase2=180/pi*angle(G2);
w=w/(2*pi);
[nout,trash]=size(c);
    for ij=1:nout
       clg
       texto=[' Response due to input= ',num2str(iu),' output= ',num2str(ij)];
       subplot(211), loglog(w,mag(:,ij),w,mag2(:,ij),'--')
       title(texto);
       xlabel('  Frequency (Hz) ')
       ylabel(' Mag. ')
       subplot(212), semilogx(w,phase(:,ij),w,phase2(:,ij),'--')
       xlabel(' Frequency (Hz) ')
       ylabel(' Phase (deg) ')
       disp(' *******Hit carriage return to continue*********')
       pause
    end
