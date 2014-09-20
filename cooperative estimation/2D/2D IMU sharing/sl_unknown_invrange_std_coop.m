function y = sl_unknown_invrange_std_coop(x)
% function y = sl_unknown_invrange_std_coop(x)
%
% function used for statistical linearization (sl) of the cooperative
% bearing-only inverse-range parameterized unknown feature measurement
%
% x: [xi,yi,psii,xki,yki,rhoki,thetaki,rhoji,thetaji,thetaij,thetakj]

%x: size n x 2n+1

L = size(x,2);

y = zeros(1,L);
for i = 1:L
    psii = x(3,i);
    Cbn = [cos(psii) sin(psii);-sin(psii) cos(psii)];
    rkj_bi = Cbn*(x(4:5,i) + 1/x(6,i)*[cos(x(7,i));sin(x(7,i))] - x(1:2,i)) - x(8,i)*[cos(x(9,i));sin(x(9,i))];
    delta = x(9,i) + pi - x(10,i);
    tt = pi2pi(atan2(rkj_bi(2),rkj_bi(1)));
    tt = minangle(tt,pi2pi(x(11,i) + delta));
    y(1,i) = pi2pi(x(11,i) + delta) - tt;
end

end