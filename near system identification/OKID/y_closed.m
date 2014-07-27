function [ufb_rec,y_rec]=y_closed(a,b,c,d,g,f,y,ufb,r)
%  ---------------------------------------------------------------
%  Routine to reconstruct feeback control input and closed-loop
%  response using identified system matrices, identified observer
%  and controller gains by ocid.
%
%               [ufb_rec,y_rec]=y_closed(a,b,c,d,g,f,y,ufb,r)
%
%  INPUT VARIABLES
%        a,b,c,d  = identified system matrices by ocid
%              g  = identified observer gain
%              f  = identified existing controller gain
%              y  = closed-loop response used in ocid
%            ufb  = feedback control input used in ocid
%              r  = additive excitation input used in ocid
%
%  OUTPUT VARIABLES
%         ufb_rec =  reconstructed feedback control history
%           y_rec =  reconstructed closed-loop response history
%
%  -----------------------------------------------------------------
[q,m]=size(d);
at=[a+g*c];bt=[b+g*d,-g];ct=[c;-f];
dt=[d,zeros(q,q);zeros(m,m),zeros(m,q)];
ut=[ufb+r,y];
yt=dlsim(at,bt,ct,dt,ut);
y_rec=yt(:,1:q);
ufb_rec=yt(:,q+1:q+m);

