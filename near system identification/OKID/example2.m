function [uu] = example2(A,B,C,D,g,pf,pb,k,u,y)
global p q r m 
[ybar]=obm2arx(A,B,C,D,g,pf,pb)
%[ybar]=armaxtd(m,r,u,y,pf,pb,[0 0])

[a, b, b0, alpha, beta, beta0] = omtemp(ybar,p,q,r,m);

%temp = alpha(:,1:2) * y(99,:)' + alpha(:,3:4) * y(98,:)' + ... 
%       alpha(:,5:6) * y(97,:)' + beta0 * u(100,:)' + ... 
%       beta(:,1:2)*u(99,:)'+ beta(:,3:4)*u(98,:)'+beta(:,5:6)*u(97,:)'
%temp = alpha(:,1:2) * y(9,:)' + alpha(:,3:4) * y(8,:)' + ... 
%       alpha(:,5:6) * y(7,:)' + beta0 * u(10,:)' + ... 
%       beta(:,1:2)*u(9,:)'+ beta(:,3:4)*u(8,:)'+beta(:,5:6)*u(7,:)'


[Taup, Betap, Alphap] = tbaptemp(b0, b, a, p, q, m, r);

PT = pinv(Taup);

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

[TBA] = Ysk *pinv([Usk ; Upkp ; Ypkp]);
[TPPBA] = Ypkq * pinv([Usk; Upkp; Ypkp]);
[c,d] = size(TPPBA);
Tau = TPPBA(:,1:q*r);
Beta = TPPBA(:,d-(p*r+p*m)+1:d-(p*m));
Alpha = TPPBA(:,d-(p*m)+1:d);

TPP = pinv(Tau);
ucqk = -PT*(Betap*upkp + Alphap*ypkp) ;
%ucqk = -TPP*(Beta*upkp + Alpha*ypkp) ;

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
  uu(k+i-1,:) = ucqk((i-1)*r+1:i*r)';
end

