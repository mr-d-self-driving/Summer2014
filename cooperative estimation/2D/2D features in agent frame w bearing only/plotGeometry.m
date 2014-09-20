%% plot_geometry

figure(1);clf;
% plot landmark
plot(marks(m).xy(2),marks(m).xy(1),'x');
text(marks(m).xy(2),marks(m).xy(1),'k');
hold on;
% plot agent i true heading
psiitrue = ags(j).truth(i,5);
plot(ags(j).truth(i,2),ags(j).truth(i,1),'bo');
plot(ags(j).truth(i,2) + [0 sin(psiitrue)],ags(j).truth(i,1) + [0 cos(psiitrue)],'b-');
text(ags(j).truth(i,2),ags(j).truth(i,1),'i');
% plot agent j true heading
psijtrue = ags(j2).truth(i,5);
plot(ags(j2).truth(i,2),ags(j2).truth(i,1),'rd');
plot(ags(j2).truth(i,2) + [0 sin(psijtrue)],ags(j2).truth(i,1) + [0 cos(psijtrue)],'r-');
text(ags(j2).truth(i,2),ags(j2).truth(i,1),'j');
% plot what we think is j's heading
plot(ags(j).truth(i,2) + [0 sin(psiitrue+delta)],ags(j).truth(i,1) + [0 cos(psiitrue+delta)],'r--');
% plot j's position based on i's estimated position & interagent measurement 
Cbin = [cos(xk(j).xk(2*i-1,5)) sin(xk(j).xk(2*i-1,5));-sin(xk(j).xk(2*i-1,5)) cos(xk(j).xk(2*i-1,5))];
rki_b = Cbin*[rkx;rky] - [rix;riy];
rkj_bi = rki_b - rhoji*[cos(thetaji);sin(thetaji)];
rkj_n = Cbin'*rkj_bi;
ri_n = Cbin'*[rix;riy];
rji_n = Cbin'*rhoji*[cos(thetaji);sin(thetaji)];
plot(marks(m).xy(2) - [0 rkj_n(2)],marks(m).xy(1) - [0 rkj_n(1)],'r--s');
% plot rji
plot(ri_n(2) + [0 rji_n(2)],ri_n(1) + [0 rji_n(1)],'b--x');

fprintf('delta = %g deg\n',delta*r2d);
