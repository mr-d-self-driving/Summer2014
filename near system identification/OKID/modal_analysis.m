%  modal_analysis.m
%  This m-file performs a modal analysis of linear state-space model in
%  the time domain.  The outputs are the modal space matrices, in modal
%  coordinates.
%
%  =================================================================
%
%   written by: J. Valasek
%               TAMU Flight Simulation Laboratory
%               25 May 1999
%  =================================================================
%       DIGITAL FLIGHT CONTROL SYSTEMS: Analysis and Design
%                               by
%                          David R. Downing
%                          John Valasek

%   The University of Kansas - Division of Continuing Education

%                          1 September 2003
%  =================================================================

clear all



a = [ -.008195 25.383102 .116427 -32.2 0 ;
      -.000082 -1.674462 .979338 0  0 ;
      -.000079 -12.686053 -1.634148 0 0  ;
      0 0 1 0 0 ;
      0 -951.626 0 951.626 0 ] ;


b = [ 0.652145 ;
      -.003874  ;
      -1.127329  ;
       0  ;
       0 ] ;


c = [  1 0 0 0 0 ;
       0 57.3 0 0 0 ;
       0 0 57.3 0 0 ;
       0 0 0 57.3 0 ;
       0 0 0 0 1] ;


d = [ 0  ;
      0  ;
      0  ;
      0  ;
      0  ] ;

sys = ss(a,-1*b,c,d) ;

tfinal = 10.

%[ab,bb,cb,db] = canon(a,b,c,d,'modal') 


[evm,lambdas] = eig(a) ;

[real_evm, Am_real] = cdf2rdf(evm,lambdas) ;

M = real_evm

Amr = (inv(M))*a*M

Bmr = (inv(M))*b

Z=inv(M)


[y,t,x]=impulse(sys,tfinal) ;
%[y,t,x]=step(sys,tfinal) ;
y_u = y(:,1) + 951.62 ;
y_alp = y(:,2) - 0.339 ;
y_q = y(:,3) ;
y_the = y(:,4) - 0.339 ;
y_h = y(:,5) + 15000. ;



t0    =  0. ;
tf    = 10. ;
tsize = 8  ;

deltav  =  .2 ;
height  =  .15  ;
width   =  .73 ;
left    =  .14 ;
bottom5 =  .004 ;

bottom1 = bottom5 + 4*deltav ;
bottom2 = bottom5 + 3*deltav ;
bottom3 = bottom5 + 2*deltav ;
bottom4 = bottom5 +   deltav ;

wig1 = [left,bottom1,width,height] ;
wig2 = [left,bottom2,width,height] ;
wig3 = [left,bottom3,width,height] ;
wig4 = [left,bottom4,width,height] ;



f1=figure(1) ;

g5=subplot(5,1,5)                                            ;
set(g5,'Position',[left,bottom5,width,height])               ;
p5=plot(t, y_h)                                 ;
grid                                                         ;
%axis([ t0 tf -4 4 ])                                         ;
%set(g5, 'YTick', [ -4 -2 0 2 4 ] ,'FontSize', tsize)         ;
%set(g5, 'XTick', [0 20 40 60 80 100 120 140 160 180 200 ],'FontSize', tsize) ;
%set(g5, 'XTickLabels', [0 1 2 3 4 5 6 7 8 9 10],'FontSize', tsize )   ;
%set(g5, 'XTickLabels','','FontSize', tsize )   ;
xlabel('time  (sec)','FontSize', tsize)                      ;
ylabel('altitude (ft)','FontSize', tsize)            ;
%t5=text(-.95,-4.5,'sideslip angle (deg)')                       ;
%set (t5,'FontSize',tsize,'Rotation',90)                 ;


g4=subplot(5,1,4)                                       ;
set(g4,'Position',wig4)                                 ;
p4=plot(t, y_the)                            ;
grid                                                    ;
%axis([ t0 tf -14 14 ])                                     ;
set(g4, 'XTickLabels', '')                              ;
%set(g4, 'YTick', [-14 -7 0 7 14],'FontSize', tsize )       ;
ylabel('pitch angle (deg)','FontSize', tsize)            ;
%t4=text(-.95,-1,'b.a. yaw rate (deg/sec)')                     ;
%set (t4,'FontSize',tsize,'Rotation',90)                 ;


g3=subplot(5,1,3)                                       ;
set(g3,'Position',wig3)                                 ;
p3=plot(t, y_q)                            ;
grid                                                    ;
%axis([ t0 tf -150 150])                                     ;
set(g3, 'XTickLabels', '')                              ;
%set(g3, 'YTick', [-150 -75 0 75 150 ],'FontSize', tsize )        ;
ylabel('pitchl rate (deg/sec)','FontSize', tsize)      ;
%t3=text(-.95,-.1,'b.a. roll rate (deg/sec)')               ;
%set (t3,'FontSize',tsize,'Rotation',90)                 ;


g2=subplot(5,1,2)                                       ;
set(g2,'Position',wig2)                                 ;
p2=plot(t, y_alp)                            ;
grid                                                    ;
%axis([ t0 tf -180 180 ])                                     ;
set(g2, 'XTickLabels', '')                              ;
%set(g2, 'YTick', [-180 -90 0 90 180 ],'FontSize', tsize) ;
ylabel('angle-of-attack (deg)','FontSize', tsize)                ;
%t2=text(-.95,.15,'bank angle (deg)')                    ;
%set (t2,'FontSize',tsize,'Rotation',90)                 ;


g1=subplot(5,1,1)                                       ;
set(g1,'Position',wig1)                                 ;
p1=plot(t, y_u)                            ;
grid                                                    ;
%axis([ t0 tf 0 12 ])                                     ;
%axis([ t0 tf 0 6 ])                                     ;
set(g1, 'XTickLabel', '')                              ;
%set(g1, 'YTick', [ 0 4 8 12],'FontSize', tsize )        ;
%set(g1, 'YTick', [ 0 2 4 6 ],'FontSize', tsize )        ;
ylabel('true airspeed (ft/sec)','FontSize', tsize)      ;
%t1=text(-.95,-.1,'angle of attack (deg)')               ;
%set (t1,'FontSize',tsize,'Rotation',90)                 ;

pptitle = 'F-5A Response to Unit Step' ;

text(0.5, 2., pptitle, 'Units','normalized', ...
     'HorizontalAlignment','center')                        ;









%ev = conj(diag(lambdas)')   ;

%evm

%evmi = inv(evm) ;


%
%.. complex modal state representation
%

%Am = evmi * A * evm 

%Bm = evmi * B        

%Cm =    C * evm


%
%.. similarity transformation matrix [T] 
%   ( obtained from complex eigenvector matrix of [A] )
%

%T  = [real(evm(:,1)),imag(evm(:,1)),real(evm(:,3)),imag(evm(:,3))]  
%Ti = inv(T) ;


%
%.. real modal state representation
%

%Amr = Ti * A * T 

%Bmr = Ti * B        

%Cmr = C  * T
