function [tv,Acc,Gyro,Mag,LPOS,LPOSV,RC,Att,flow,baro,ekf,ekf_var] = loadPX4(fname)
%function [tv,Acc,Gyro,Mag,LPOS,LPOSV,RC,Att,flow,baro,ekf,ekf_var] = loadPX4(fname)
%
% load a PX4 CSV log file at relative or global filepath "fname"
% this file is "dumb" and will need to be updated if uOrb messages or the sdlog2 app changes

try 
	addpath('utilities');
catch error
	disp('Warning: no utilities folder found. Some functions may not be present');
end

[num,txt] = xlsread(fname);
labels = txt(1,:);

% load time vector
tind = find(strcmp('TIME_StartTime',labels));
tfirst = find(~isnan(num(:,tind)),1,'first');
%delete nans
num(1:tfirst-1,:) = [];
tv     = (num(:,tind) - num(1,tind))/10^6;

% load accelerometer, gyro, and magnetometer histories
tind = find(strcmp('IMU_AccX',labels));
Acc   = num(:,tind+(0:2));% are the acc and gyro values raw? based on the log, they *might* be.
Gyro  = num(:,tind+(3:5));
Mag   = num(:,tind+(6:8));

% load PX4 default position/velocity estimates
tind = find(strcmp('LPOS_X',labels));
LPOS  = num(:,tind+(0:2));% vehicle local position histories - these are not raw?
tind = find(strcmp('LPOS_VX',labels));
LPOSV = num(:,tind+(0:2));

% load RC inputs
tind = find(strcmp('RC_Ch0',labels));
RC    = num(:,tind+(0:8));

% load PX4 default attitude estimates
tind = find(strcmp('ATT_Roll',labels));
Att   = num(:,tind+(0:8)); % roll, pitch, yaw & rates

% load flow data
tind = find(strcmp('FLOW_RawX',labels));
flow = num(:,tind+(0:6));

%load barometer values
tind = find(strcmp('SENS_BaroAlt',labels));
baro = num(:,tind);

% load PF_ekf estimates and covariances
tind = find(strcmp('PF_E_Vx',labels));
ekf = num(:,tind+(0:7));% Vx Vy Vz bank, pitch, yaw rate, z, barometer bias
ekf_var = num(:,tind+(11:18));

end