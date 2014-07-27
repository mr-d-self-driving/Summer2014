%% read from binary file
clear variables;
close all;

[binfile,folder] = uigetfile('*.bin','Select the binary file with data to load');

%binfile = 'sim_out_2014_6_6.bin';
txtfile = [binfile(1:end-4) '_types.txt'];
%txtfile = 'sim_out_2014_6_6_types.txt';

%% read data length and agent types from txt file
fid2 = fopen(txtfile,'r+');
datalen = fscanf(fid2,'%i\n',1);
A = fscanf(fid2,'%i');
Acell = cell(size(A));
N = length(A);%number of agents
for i = 1:N
    switch A(i)
        case 1
            Acell{i} = 'planar';
    end
end
fclose(fid2);

%% process binary file
ags(N) = struct('model',[],... %function handle to the model that describes how the agent dynamics develop
    'x',[],... %m x n matrix of m timesteps, where n is the number of states; m should be the same for all agents, but n will vary
    't',[]); %time vector, m x 1

fid = fopen(binfile,'r+');
for i = 1:N
    if strcmp('planar',Acell{i})
        B = fread(fid,[datalen 7],'double');
        ags(i).model = 'planar';
    end
    ags(i).x = B(:,2:end);
    ags(i).t = B(:,1);
end
fclose(fid);