function [KE,CAKE]=k_abcd(A,B,C,D,UDATA,YDATA,q)
% 
%      Given: state space parameters A,B,C,D, input UDATA
%             and output YDATA
%       Find: Observer/Kalman filter gain KE
%
%       function [KE,CAKE]=k_abcd(A,B,C,D,UDATA,YDATA,p)
%         
% Input 
%      A,B,C,D: system state space parameters
%        UDATA: input data
%        YDATA: output measurements
%            p: order of the whitening filter
% Output
%           KE: estimated Observer/Kalman filter gain
%         CAKE: estimated stochastic Markov parameters

%         Chung-Wen Chen and Jer-Nan Juang  8-2-91
%         NASA Spacecraft Dynamics Branch                           

  [s2,s1]=size(YDATA);
  [s3,s4]=size(A);
   y1=dlsim(A,B,C,D,UDATA);
   y2=YDATA-y1;
   clear y1;
  [ybar, yybar]=yycovar(y2,q,0);
  PAV=ybar*pinv(yybar);
  PAV=PAV';
% 
   CAKM=0*PAV.';
   CAKH=CAKM.';
   CAKM(:,1:s1)=PAV(1:s1,:).';
   CAKH(1:s1,:)=PAV(1:s1,:).';
   for i=2:q;
      n1=(i-1)*s1+1;
      n2=i*s1;
      CAKMT=zeros(s1,s1);
      for j=1:i-1;
          n3=(j-1)*s1+1;
          n4=j*s1;
          n5=s1*(i-j-1)+1;
          n6=s1*(i-j);
          CAKMT=CAKMT+PAV(n3:n4,:).'*CAKM(:,n5:n6);
       end;
       temp=CAKMT+PAV(n1:n2,:).';
       CAKM(:,n1:n2)=temp;
       CAKH(n1:n2,:)=temp;
    end;
   CAKE=zeros(s1*s1,q);
    for i=1:q;
    n1=(i-1)*s1+1;
        for j=1:s1;
            nn1=(j-1)*s1+1;
            nn2=j*s1;
            CAKE(nn1:nn2,i)=CAKM(:,n1+j-1);
        end;
     end;
%--------- calculating Kalman filter gain --------------
   H1=CAKH(1:s1*q,:);
   CA=C*A;
   CA1=CA;
     for i=1:q-1;
        CA1=CA1*A;
        CA=[CA;CA1];
     end;
KE=-A*pinv(CA)*H1;
