function [] = plotTriangle(rhoji, thetaji, thetaij, thetakj, rki_bi)

figure;

plot([0 rki_bi(2)],[0 rki_bi(1)],'b-');%vector from i to k
hold on;
plot(rhoji*[0 sin(thetaji)],rhoji*[0 cos(thetaji)],'b-');% plot vector to agent j
text(0,0,'i');
text(rhoji*sin(thetaji),rhoji*cos(thetaji),'j')

delta = pi2pi(pi - thetaij + thetaji);

% plot vector from k to i
plot(rhoji*sin(thetaji) + [0 rhoji*sin(delta + thetaij)],rhoji*cos(thetaji) + [0 rhoji*cos(delta + thetaij)],'kd');

thetakj_eff = atan2(rki_bi(2) - rhoji*sin(thetaji),rki_bi(1) - rhoji*cos(thetaji));
rhokj_eff = sqrt(sum( (rki_bi - rhoji*[cos(thetaji);sin(thetaji)]).^2));

% plot vector from j to k
plot(rhoji*sin(thetaji) + [0 rhokj_eff*sin(thetakj_eff)],rhoji*cos(thetaji) + [0 rhokj_eff*cos(thetakj_eff)],'r--');

thetakj_eff_meas = thetakj + delta;
% plot the measured vector from j to k
plot(rhoji*sin(thetaji) + [0 rhokj_eff*sin(thetakj_eff_meas)],rhoji*cos(thetaji) + [0 rhokj_eff*cos(thetakj_eff_meas)],'k:');

axis equal;

end