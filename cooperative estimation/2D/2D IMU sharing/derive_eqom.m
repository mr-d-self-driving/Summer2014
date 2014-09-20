%% derive_eqom

clear variables;
close all;

syms rkx rky rix riy rjix rjiy rhokj_til thetakj_til psiji psii n real;

Cbn = [cos(psii) sin(psii); -sin(psii) cos(psii)];
Cbjbi = [cos(psiji) sin(psiji); -sin(psiji) cos(psiji)];
rk = [rkx;rky];
ri = [rix;riy];
rji = [rjix;rjiy];
rkj_exp = Cbjbi*(Cbn*rk - ri - rji);
x_diff = [rix riy n n psii rjix rjiy n n psiji];
Hk_exp = sym('H',[2,10]);
for i = 1:10
    Hk_exp(:,i) = simplify(diff(rkj_exp,x_diff(i)));
end