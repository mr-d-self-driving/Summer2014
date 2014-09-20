% derive_discrete_eqom

clear variables;
close all;

syms xk yk xkp ykp real;
syms vxk vyk h Lkx Lky R1 R2 real;
syms xj yj real;%feature coordinates

Xj = [xj;yj];

Lkp = [Lkx;Lky];

Rk = diag([R1 R2]);

%stationarity condition
Uk = [vxk;vyk];
Xkp = [xkp;ykp];
Xk = Xkp - h*Uk;

dalphaj_u = atan((Xj(2)-Xk(2))/(Xj(1)-Xk(1))) - atan((Xj(2)-Xkp(2))/(Xj(1)-Xkp(1)));
Lk_u = 1/2*(Uk'*Rk*Uk - dalphaj_u^2);
Hk_u = Lk_u + Lkp'*(Xkp);

Xk = [xk;yk];
Xkp = Xk + h*Uk;
dalphaj = atan((Xj(2)-Xk(2))/(Xj(1)-Xk(1))) - atan((Xj(2)-Xkp(2))/(Xj(1)-Xkp(1)));

Lk = 1/2*(Uk'*Rk*Uk - dalphaj^2);
Hk = Lk + Lkp'*(Xk + h*Uk);
dHkdXk = sym('dL',[2 1]);
dHkdLkp = sym('dL',[2 1]);
dHkduk = sym('dL',[2 1]);
dalphakdUk = sym('dalpha',[2 1]);
dalphakdXk = sym('dalpha',[2 1]);
for i = 1:length(Xk)
    dHkdXk(i) = simplify(diff(Hk,Xk(i)));
    dHkdLkp(i) = simplify(diff(Hk,Lkp(i)));
    dHkduk(i) = simplify(diff(Hk_u,Uk(i)));
    dalphakdUk(i) = simplify(diff(dalphaj_u,Uk(i)));
    dalphakdXk(i) = simplify(diff(dalphaj,Xk(i)));
end