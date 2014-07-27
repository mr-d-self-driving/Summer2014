function [uu] = example1(A,B,C,D,g,pf,pb,k,u,y,x)
global p q r m 
[ybar]=obm2arx(A,B,C,D,g,pf,pb);

[a, b,b0,alpha, beta, beta0] = omtemp(ybar,p,q,r,m);

%temp = alpha(:,1:2) * y(49,:)' + alpha(:,3:4) * y(48,:)' + ... 
%       alpha(:,5:6) * y(47,:)' + beta0 * u(50,:)' + ... 
%       beta(:,1:2)*u(49,:)'+ beta(:,3:4)*u(48,:)' + beta(:,5:6)*u(47,:)'

temp = alpha(1)*y(49) + alpha(2)*y(48) + alpha(3)*y(47) + alpha(4)*y(46) + ...
       alpha(5)*y(45) + alpha(6)*y(44) + beta0 * u(50) + beta(1)*u(49)+ ...
       beta(2)*u(48) +beta(3)*u(47) +beta(4)*u(46) +beta(5)*u(45) +beta(6)*u(44) 
y(50)
[Taup,Betap,Alphap] = tbaptemp(b0, b, a, p, q, m,r);

for i = 1:r
for j = 1:q
 Taupp(:,(i-1)*q+j) = Taup(:,(j-1)*r+i);
end
end

PT = pinv(Taupp(:,1:q));
%PT = pinv(Taup);

s= p+q;
N = s*r;

for i = 1:q
  uqk(i*r-r+1:i*r,:) = u(k+i-1,:)';
end

for i = 1:p
  upkp(i*r-r+1:i*r,:) = u(k-p+i-1,:)';
  ypkp(i*m-m+1:i*m,:) = y(k-p+i-1,:)';
end

for i = 1:s
  usk(i*r-r+1:i*r,:) = u(k+i-1,:)';
  ysk(i*m-m+1:i*m,:) = y(k+i-1,:)';
end

for i = 1:s
 for j = 1:N
  Usk(i*r-r+1:i*r,j) = u(k+i+j-2,:)';
  Ysk(i*m-m+1:i*m,j) = y(k+i+j-2,:)';
 end
end

for i = 1:p
 for j = 1:N
  Upkp(i*r-r+1:i*r,j) = u(k-p+i+j-2,:)';
  Ypkp(i*m-m+1:i*m,j) = y(k-p+i+j-2,:)';
 end
end

for i = 1:p
 for j = 1:N
  Ypkq(i*m-m+1:i*m,j) = y(k+q+i+j-2,:)';
 end
end

tempp = Taup*uqk +Betap * upkp + Alphap*ypkp;

[TBA] = Ysk *pinv([Usk ; Upkp ; Ypkp]);
[TPPBA] = Ypkq * pinv([Usk; Upkp; Ypkp]);
[c,d] = size(TPPBA);
Tau = TPPBA(:,1:q*r);

for i = 1:r
for j = 1:q
 Tauppp(:,(i-1)*q+j) = Tau(:,(j-1)*r+i);
end
end

Beta = TPPBA(:,d-(p*r+p*m)+1:d-(p*m));
Alpha = TPPBA(:,d-(p*m)+1:d);


TPP = pinv(Tauppp(:,1:q));
ucqk = -PT*(Betap*upkp + Alphap*ypkp);
%ucqk = -TPP*(Beta*upkp + Alpha*ypkp); 

%ypkq = Taup*uqk+ Betap * upkp + Alphap * ypkp;
%ypkq = Tau*uqk+ Beta * upkp + Alpha * ypkp;

%Alc = -PT1(1,:)*Alphap1;
%Bec = -PT1(1,:)*Betap1;
%Bed = -PT1(1,:)*Betap2;

%for i = 1:p
%A_c(i) = Alc(p+1-i);
%B_c(i) = Bec(p+1-i);
%B_d(i) = Bed(p+1-i);
%end

%uck = 0;
%for i = 1:p
%uck = uck + A_c(i)*y(k-i) + B_c(i)*u(k-i,1) + B_d(i)*u(k-i,2);
%end

%for i = 1:q
%uk(i,:) = [ucqk(i*r-r+1:i*r)'];
%end
uu(1:k-1,:) = u(1:k-1,:);
for i = 1:q
  uu(k+i-1,1) = ucqk(i);
     if r == 2
      uu(k+i-1,2) = 0;
     end
end

feedg = PT(1:r,:) ;
uk = -feedg * (Betap*upkp + Alphap*ypkp);

for i = 1:q
yk(i+k-1,1) = (C-feedg*D)*x(k+i-1,:)';
end
yk(1:k-1,1) = y(1:k-1,:);

