% Airfoil NACA 23012 
% Integration 
clear all
global CLa S Mac q J m hcg hh hac c Vinf p q r m hah haac
CLa = 0.083 ; Cmac = -0.008; Vinf= 100; span = 36; 
J=100; m=100; hcg=0.8;  hh = 0.2; hac = 0.25; c=6;
hah=0.85; haac = 0.8;
rho = 0.002378;
q = (rho*Vinf^2)/2;
S = c*span;
Mac = Cmac*q*c*S;

w = 1;
%z = 10*cos(w*t);
%zdot = -10*w*sin(w*t);
%z2dot = -10*w^2*cos(w*t);

%del = 10*sin(w*t);

tempa = -1/((J-m*(hcg-hh)^2*c^2))*((2*hcg-hac-hh)*c*q*S*CLa*(1/Vinf));
tempb = 1/((J-m*(hcg-hh)^2*c^2))*((hcg-hh-hah+haac)*c*q*S*CLa);

Ac = [ 0 1; 1/((J-m*(hcg-hh)^2*c^2))*((2*hcg-hac-hh)*c*q*S*CLa) 1/((J-m*(hcg-hh)^2*c^2))*((2*hcg-hac-hh)*c*q*S*CLa)*((hcg-hh)/Vinf)*c];
Bc = [0 0 ; tempb tempa];
C = [ 0 1];
D = 0;

dt = 0.5;
[A, B] = c2d(Ac,Bc,dt);

pf = 2; pb=0; p = pf+pb; q = 100; pt = 400;

format short e; format compact

%format long e; format compact

[m,n] = size (C); [n,r] = size(Bc);

t = [dt:dt:pt*dt]';  % time step size

%clear Ac Bc;
u = [ 10*sin(w*t)  -10*w*sin(w*t)  ] ;
x0 = [0 0]'; ic1 = 1;
%x0 = [1 1 1 1 1 1]'; ic1 = 1;

[y,x] = dlsim(A,B,C,D,u,x0);

%pt1 = 100;
%n_order=p*m;
%[yi,yo]=pulse(m,r,u,y,pf,pb,pt1,[0 0]);
%[AA,BB,CC,DD,GG,eg,mh]=eradc([yi yo],[1 1 0 m],r,n_order,p,dt)
value = eig(A);
%clear A B C D ;

[A,B,C,D,G,x0]=okid(m,r,dt,u,y,'batch',p);
%value2 = eig(A);
g=deadbeat(A,B,C,D) ;
k=50;
%=========================================
[ybar]=obm2arx(A,B,C,D,g,pf,pb)
%[ybar]=armaxtd(m,r,u,y,pf,pb,[0 0])

[a, b, b0, alpha, beta, beta0] = omtemp(ybar,p,q,r,m);

%temp = alpha(:,1:2) * y(49,:)' + alpha(:,3:4) * y(48,:)' + ... 
%       alpha(:,5:6) * y(47,:)' + beta0 * u(50,:)' + ... 
%       beta(:,1:2)*u(49,:)'+ beta(:,3:4)*u(48,:)' + beta(:,5:6)*u(47,:)'

%temp = alpha(1)*y(9) + alpha(2) * y(8) + beta0 * u(10) + ... 
%       beta(1)*u(9)+ beta(2)*u(8)

[Taup, Betap, Alphap] = tbaptemp(b0, b, a, p, q, m, r);

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

tempp = Taup*uqk +Betap * upkp + Alphap*ypkp

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
udq = u(k:k+q-1,2);
%ucqk = -PT*(Betap*upkp + Alphap*ypkp);
ucqk = -PT*(Taupp(:,q+1:2*q)*udq + Betap*upkp + Alphap*ypkp);
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
  uu(k+i-1,1) = ucqk(i);
     if r == 2
      uu(k+i-1,2) = u(k+i-1,2);
     end
end

%==========================================
%[uu] = example1(A,B,C,D,G,pf,pb,k,u,y);
%[uu] = example2(A,B,C,D,g,pf,pb,k,u,y);

yy = dlsim(A,B,C,D,uu,x0);

tt = [dt:dt:(k+q-1)*dt]'; 

figure(1)
subplot(2,1,1),plot(t,u(:,1),'--',tt,uu(:,1),'-')
%axis([0 50 -4 4])
title('Control Input for using Indirect Method (q step = 50)')
xlabel('Time (sec)')
legend('Original Input','Control Input')
subplot(2,1,2),plot(t,y(:,1),'--',tt,yy(:,1),'-')
%axis([0 50 -5 5])
title('Control Output for using Indrect Method (q step = 50)')
xlabel('Time (sec)')
legend('Original Output','Control Output')
hold on

figure(2)
subplot(2,1,1),plot(t,u(:,2),'--',tt,uu(:,2),'-')
%axis([0 50 -4 4])
title('Control Input for using Indirect Method (q step = 50)')
xlabel('Time (sec)')
legend('Original Input','Control Input')
hold on
