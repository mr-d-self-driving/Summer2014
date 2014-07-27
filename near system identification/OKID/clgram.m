function [phi]=clgram(range,fnyqhz,a)
%
%          Routine to evaluate frequency weighting
%          Grammians from analytic integration on a contour
%
%           function [phi]=clgram(range,fnyqhz,a)
%
%
%    range   = vector with upper and lower freq. range <= fnyqhz
%    a       = system matrix
%    fnyqhz  = Nyquist frequency in Hz

%
%          L. G. Horta 2-14-90

[m,l]=size(a);
ii=sqrt(-1);
lo1=pi*range(1)/fnyqhz; up1=pi*range(2)/fnyqhz;
up2=2*pi-lo1; lo2=2*pi-up1;
s1=-lo1*eye(m,m)-2*ii*logm(exp(ii*lo1)*eye(m,m)-a);
s2=-up1*eye(m,m)-2*ii*logm(exp(ii*up1)*eye(m,m)-a);
s3=-lo2*eye(m,m)-2*ii*logm(exp(ii*lo2)*eye(m,m)-a);
s4=-up2*eye(m,m)-2*ii*(logm(exp(ii*up2)*eye(m,m)-a)+2*pi*ii*eye(m,m));
phi=((s2-s1)+(s4-s3))/(4*pi);
phi=real(phi);
