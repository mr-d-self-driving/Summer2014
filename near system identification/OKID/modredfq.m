function [ar,br,cr,dr]=modredfq(ab,bb,cb,d,dt)
%
%             Model reduction section function subroutine
%
%      function [ar,br,cr,dr]=modredfq(ab,bb,cb,d,dt)
%
%      Input variables
%      ab,bb,cd,d   = discrete system matrices
%      dt           =sample time
%
%      Output Variables
%      ar,br,cr,dr  = Reduced order model

%            Created 03-08-1990   by L. G. Horta
%             MOD. 3-17-94 by L.G. Horta

fnyq=pi/dt;      % radians/sec
fnyqhz=fnyq/(2*pi);
disp([' Nyquist frequency (hz) is = ' num2str(fnyqhz)])
lowf=input( ' Reduced Model Desired lower frequency bound  (Hz) := ');
upf=input(' Reduced Model Desired upper frequency bound (Hz) := ');
zrange=[lowf upf]';
p=input('  No. of points to plot in FRF := ');
%
%     Evaluation of the frequency weighted grammian
%
        wcss=dgram(ab,bb);
        woss=dgram(ab',cb');
        [phi]=clgram(zrange,fnyqhz,ab);
        wc=wcss*phi'+phi*wcss;
        wo=woss*phi+phi'*woss;
qtest=chol(wo);
pttest=chol(wc);
h_test=qtest*pttest';
[v_test,s2_test,u_test]=svd(h_test);
r_test=pttest'*u_test*inv(sqrt(s2_test));
rin_test=inv(r_test);
ab_test=rin_test*ab*r_test; bb_test=rin_test*bb; cb_test=cb*r_test;
chk=diag(cb_test'*cb_test*s2_test);
[mtest,trash]=size(ab);
ntrun=mtest;
       while ntrun > 0,
        disp(' State No.   Index ')
        [s11,junk]=size(chk);vjunk=[1:s11]';
        temp=[vjunk chk];
        semilogy([chk],'*');
        disp(temp)
        ntrun=input(' Number of States to be retained (0=stop/end) =: ');
        if ntrun == 0, break, end
        skip=input(' Enter Matrix with State No. to be retained =: ');
        jerror=sum(chk)-sum(chk(skip));
        disp([' Impulse response prediction error =' num2str(jerror)])
        l_trun=zeros(ntrun,mtest);
        uno=eye(ntrun,ntrun);
        l_trun(:,skip)=eye(ntrun,ntrun);
        ar=l_trun*ab_test*l_trun';
        br=l_trun*bb_test;
        cr=cb_test*l_trun';
        dr=d;
        [result]=deg2hz(eig(ar),dt);
        disp('     Damp. (%)    Freq(Hz)  ')
        disp([result(:,1:2)])    
        [junk,rin]=size(bb);
        [m,ph,m2,ph2,omg]=freqplot(ab,bb,cb,d,ar,br,cr,dr,p,dt,1);
         end

