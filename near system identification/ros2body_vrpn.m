function [t,xyz,quat] = ros2body_vrpn(data,txt)
% open optitrack data (attitude are given by ROS)
% output time, position, attitude histories, in the real body frame
%
% new version July 15 from my computer, transformation from ROS to body
% frame seems to be different?

%get the ROS frame time, position, attitudes
tind = find(strcmp(txt(1,:),'secs'));
t = data(:,tind) + data(:,tind+1)/10^9 - data(1,tind);%time

xyzind = find(strcmp(txt(1,:),'translation')) + 1;
xyzros = data(:,xyzind+(0:2));

quatind = find(strcmp(txt(1,:),'rotation')) + 1;
quatros = data(:,quatind+(0:3));

%ROS BODY 2 REAL BODY DCM: 
%R1_pi = [1,0,0;
%   0,-1,0;
%   0,0,-1];
R1_pi = [0 1 0;1 0 0;0 0 -1]; % this one worked on July 15
R1_pi = [0,-1,0;
   -1,0,0;
   0,0,-1];% this one works on July 17

%north-east-down inertial frame position components
%xyz = [xyzros(:,1) -xyzros(:,2) -xyzros(:,3)];
xyz = xyzros*R1_pi';

%inertial frame 
quat = zeros(size(quatros));
for i = 1:length(t)
    B0 = quatros(i,4);
    Bv = quatros(i,1:3);
    Cros2fakebody = attparsilent([B0 Bv]',[6 1]);
    C = R1_pi*Cros2fakebody*R1_pi';
    X = attpar(C,[1 6]);
    quat(i,4) = X(1,1);
    quat(i,1:3) = X(2:4,1);
end
end