function [A,B,C,D]=unsb2sb(Ao,Bo,Co,Do,f,dt,fg)
%
%         Routine to Stabiliz Unstable Systems 
%
%         [A,B,C,D]=unsb2sb(Ao,Bo,Co,Do,f,dt,fg)
% INPUT
%   Ao,Bo,Co,Do = Unstable state space model
%        f      = Frequency vector
%        dt     = Sample time
%       fg(1)   = 1: Compare Unstable and Stabilized System FRF
%       fg(2)   < 0: Discard Unstable Real Modes
%       fg(3)   = 1: User's interaction required to determine modal truncation  
%
%OUTPUT
%     A,B,C,D   = Stabilized state space system
%

%       
%  Jer-Nan Juang 4-11-95, NASA Structural Dynamics Branch
%
if isempty(fg)==1 | length(fg)<3; 
   fg=[fg zeros(1,3-length(fg))]; 
end;
A=Ao;B=Bo;C=Co;D=Do;
  [n,r]=size(Bo); [m,n]=size(Co);
  [evt eva]=eig(Ao);
  eva=diag(eva);
  ns=length(eva);
  ksb=find(abs(eva)<=1);% stable modes
%
%
if length(ksb)<ns,   %------ Unstable mode(s) exist ----
%
  disp(['   '])
  disp(['System stabilization is performed as follows'])
  disp(['No. of eigenvalues: ' num2str(ns)]);
  kusb=find(abs(eva)>1);% unstable modes
  disp(['No. of unstable eigenvalues: ' num2str(length(kusb))]);
%
  Bn=evt\Bo; Cn=Co*evt; clear evt;
%**************************************
% Calculating the Stable Part
%**************************************
  if length(ksb)==0;
     A=[];B=[];C=[];
  else;
    [A,B,C]=bk_diag(eva(ksb),Bn(ksb,:),Cn(:,ksb));
  end;
%**********************************
% Calculate FRF of Unstable Part
%**********************************
  evan=eva(kusb); Bn=Bn(kusb,:);Cn=Cn(:,kusb);
  if fg(2)<0;
   kusbc=find(abs(imag(evan) ./real(evan))>1e-4);
   disp(['No. of real unstable poles: ' num2str(length(kusb)-length(kusbc))]);
   disp(['No. of complex unstable poles: ' num2str(length(kusbc))]);
   evan=evan(kusbc);Bn=Bn(kusbc,:);Cn=Cn(:,kusbc);
  end;
  Dn=0*Do;
  [An,Bn,Cn]=bk_diag(evan,Bn,Cn);
  z=exp(sqrt(-1)*f*2*pi*dt);
  Gzn=[];
   for k=1:r;
      Gztemp=freqresp(An,Bn,Cn,Dn,k,z);
      Gzn=[Gzn Gztemp];
   end; clear Gztemp;
%**********************************
% Stablizing the unstable part
%**********************************
   pns=-real(poly(1 ./evan));  % desired stablized characteristic polynomial
   cp=polyval(fliplr(pns),conj(z));% compute polynomial value for all freqs
  [nd,mr]=size(Gzn);
  frfcp=zeros(nd,mr);
  for k=1:mr
    frfcp(:,k)=-Gzn(:,k) .*cp; % Product of FRF & Characteristics polynomial
  end;
%**********************************
% Compute ARX Zeta Parameters
%**********************************
  npoly=length(pns);
  gzt=zgcorr(frfcp,f,dt,r,npoly); clear frfcp;
%**********************************
% Form Observer Markov parameters
%**********************************
  npoly=length(pns);
  ybar=zeros(m,npoly*(r+m));
  for k=1:npoly;
     yck=(k-1)*(r+m)+1:k*(r+m);
     gck=(k-1)*r+1:k*r;
     ybar(:,yck)=[gzt(:,gck) pns(k)*eye(m)]; 
  end;
  ybar(:,r+1:r+m)=[];
%**********************************
% Compute system Markov parameters
%**********************************
  p=ceil(npoly*min(r,m)/m);
  n_markov=3*ceil(p*m/r)+p+1;
  markovp=marcomp(ybar,0,r,n_markov,0);
  [ys,yo]=separate(markovp,m,r,m);clear markovp;
  ps=m2p(ys,r);clear ys
%*******************************************
%  Use ERADC to compute a state space model 
%*******************************************
  [An,Bn,Cn,Dn,gp,sv,lambda]=eradc(ps,0,r,p*m,p,dt); clear ps;
%*******************************************
%  Compare Unstable and Stabilized System 
%*******************************************
  if fg(1)==1;
    Gzns=[];
    for k=1:r;
      Gztemp=freqresp(An,Bn,Cn,Dn,k,z);
      Gzns=[Gzns Gztemp];
    end; clear Gztemp;
    clg;
    n=0;x=180/pi;
    for kb=1:r;
     for kc=1:m;
       n=n+1;
       subplot(211),
	   semilogy(f(2:nd),abs(Gzn(2:nd,n)),f(2:nd),abs(Gzns(2:nd,n)),'--');
         title(['Comparison of Unstable and Stabilized System' ...
             ' for input # ' num2str(kb) ' and output # ' num2str(kc)]);
         xlabel('Frequency (Hz)');ylabel('Magnitude');
       subplot(212),
	   plot(f(2:nd),x*angle(Gzn(2:nd,n)),f(2:nd),x*angle(Gzns(2:nd,n)),'--');
         xlabel('Frequency (Hz)');ylabel('Phase (deg.)');
	   pause;
     end;
    end;
  end;
  disp(['End of System Stabilization'])
%******************************************
% Combining the stable and unstable parts
%******************************************
    [n1,n1]=size(A);
    [n2,n2]=size(An);
    ndim=n1+n2;
	A=[A zeros(n1,n2); zeros(n2,n1) An];
    B=[B;Bn];C=[C Cn];D=Dn+D; clear An Bn Cn Dn;
%
%  Solve for eigenvalues and eigenvectors of the stabilized system
%
    [evt eva]=eig(A);
    eva=diag(eva);
%
%   Calculate the singular values of modal participation to
%   the pulse response samples 
%
   clg;
   disp(['  '])
   disp(['Eigenvalues of the Stabilized System'])
   [lambda,bm,cm,msv,index]=svpm(eva,evt\B,C*evt,fg(3));
    xt=deg2hz(lambda,dt); 
    xt=[xt(:,1:2) msv];
    disp(['  ']);
    disp([' Frequency and Damping Ratio of the Stabilized System ']);
    disp('   Damping(%)    Freq(HZ)      Mode SV');
	disp(xt);
%
%  Reduce the system model and put in the block-diagonal form
%
     if length(lambda)<length(eva);
         [A,B,C]=bk_diag(lambda,bm,cm);
	 end;
end;
