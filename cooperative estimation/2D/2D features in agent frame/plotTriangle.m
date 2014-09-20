function [] = plotTriangle(rhokj,thetakj,rhoji,thetaji,psij,psii)

figure;
plot(rhoji*[0 sin(thetaji)],rhoji*[0 cos(thetaji)],'b-');% plot vector to agent j
hold on;
%plot vector ffrom j to k
plot(rhoji*sin(thetaji) + [0 rhokj*sin(thetakj+psij-psii)],rhoji*cos(thetaji) + [0 rhokj*cos(thetakj+psij-psii)],'b-');
alpha = pi-thetakj-psij+psii+thetaji;
rhoki = sqrt(rhokj^2+rhoji^2-2*rhokj*rhoji*cos(alpha));
gamma = acos((rhokj^2-rhoji^2-rhoki^2)/(-2*rhoji*rhoki));
thetaki = thetaji - asin((rhokj*sin(psii - psij + thetaji - thetakj))/(rhoji^2 + 2*cos(psii - psij + thetaji - thetakj)*rhoji*rhokj + rhokj^2)^(1/2));
gamma = atan2( rhokj/rhoki*sin(alpha),((rhokj^2-rhoji^2-rhoki^2)/(-2*rhoji*rhoki)));
thetaki = thetaji + gamma;
thetaki2 = thetaji - atan2((2*rhoji*rhokj*sin(psii - psij + thetaji - thetakj)),(rhoji^2 + rhoki^2 - rhokj^2));
plot(rhoki*[0 sin(thetaki)],rhoki*[0 cos(thetaki)],'r-');
plot(rhoki*[0 sin(thetaki2)],rhoki*[0 cos(thetaki2)],'m--');

axis equal;
end