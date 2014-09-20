function [T,Y,V,W,A] = agent_sim_rectangular(tspan,y0)
% explore a 2d rectangular space between X = [0, XM], Y = [0, YM]

data = xlsread('opti.csv');
t = (data(:,1) - data(1,1))/1e9;
% remove when we not moving
xyz = data(:,11:13);
inMove = find( abs(diff(xyz(:,3))) > .0015,1,'first');
t(1:inMove-1) = [];
t = t - t(1);
data(1:inMove-1,:) = [];
% remove any data points beyond what we want to simulate
if tspan(end) < t(end)
    inRem = find(t > tspan(end),1,'first');
    t(inRem:end) = [];
    data(inRem:end,:) = [];
end
xyz = data(:,11:13);
% shift starting point
xyz(:,1:2) = xyz(:,1:2) + repmat([-1.5 0],length(xyz),1);
quat = data(:,15:18);

% permute the data by rotation or mirroring or both
rotate_rad = rand*2*pi - pi;
mirror_axis = round(rand*3);

euler = zeros(length(t),3);
for i = 1:length(t)
    XX = attparsilent(quat(i,[4 1 2 3])',[6 4],struct('seq',[3 2 1]));
    euler(i,:) = XX([3 2 1],1)';
end
PSI = euler(:,3);

%permute the data
PSI =  PSI + rotate_rad;
Crotate = [cos(rotate_rad) sin(rotate_rad);-sin(rotate_rad) cos(rotate_rad)];
xyz(:,1:2) = xyz(:,1:2)*Crotate';
%mirror the data
switch mirror_axis
    case 1
        xyz(:,1) = -xyz(:,1);
        PSI = pi-PSI;
    case 2
        xyz(:,2)  = -xyz(:,2);
        PSI = -PSI;
    case 3
        xyz(:,1) = -xyz(:,1);
        xyz(:,2)  = -xyz(:,2);
        PSI = PSI - pi;
end

% make PSI continuous
inCon = find(abs(diff(PSI)) > 1);
for i = 1:length(inCon)
    if PSI(inCon(i)+1)-PSI(inCon(i)) > 0 %we jumped from -pi to pi
        PSI(inCon(i)+1:end) = PSI(inCon(i)+1:end)-2*pi;
    else
        % we jumped from pi to -pi
        PSI(inCon(i)+1:end) = PSI(inCon(i)+1:end)+2*pi;
    end
end
XY = xyz(:,1:2);
% smooth attitude and position histories
tDown = 0:.1:t(end);
flag = zeros(length(tDown),1);

xy = zeros(length(tDown),2);
psi = zeros(1,length(tDown));
for i = 1:length(tDown)
    ind = find(abs(t-tDown(i)) <= .05);
    if isempty(ind)
        flag(i) = 1;
    else
        xy(i,:) = nanmean(XY(ind,1:2));
        psi(i) = nanmean(PSI(ind));
    end
end
notflag = ~flag;
flag = find(flag);
notflag = find(notflag);
% interpolate for missing optitrac segments
psi(flag) = interp1(tDown(notflag),psi(notflag),tDown(flag));
xy(flag,:) = interp1(tDown(notflag),xy(notflag,:),tDown(flag));
psiSmooth = filter(.1*ones(10,1),1,psi-psi(1)) + psi(1);
xySmooth = filter(.1*ones(10,1),1,xy-repmat(xy(1,:),length(tDown),1)) + repmat(xy(1,:),length(tDown),1);
wb = diff(psiSmooth)./diff(tDown);
vn = diff(xySmooth)./repmat(diff(tDown)',1,2);
an = (xySmooth(1:end-2,:) - 2*xySmooth(2:end-1,:) + xySmooth(3:end,:))/.01;

tDown(end-1:end) = [];
xySmooth(end-1:end,:) = [];
psiSmooth(end-1:end) = [];
wb(end) = [];
vn(end,:) = [];

vb = 0*vn;
ab = 0*vn;
% get body-frame velocities
for i = 1:length(tDown)
    C = [cos(psiSmooth(i)) sin(psiSmooth(i));
        -sin(psiSmooth(i)) cos(psiSmooth(i))];
    vb(i,:) = vn(i,:)*C';
    ab(i,:) = an(i,:)*C';
end

T = tDown;

psiSmooth = pi2pi(psiSmooth);
Y = [xySmooth psiSmooth'];
V = vb;
A = ab;
W = wb';

end