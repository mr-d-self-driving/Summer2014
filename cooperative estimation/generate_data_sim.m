%% generate_data_sim
% for N agents, generate full state histories each
% for testing open-loop inter-agent sensing & estimation

clear variables;
close all;

%number of agents
N = 2;
tfinal = 30.0;

ags(N) = struct('model',[],... %function handle to the model that describes how the agent dynamics develop
    'ref',[],... %function handle that provides a reference trajectory
    'statehist',[]); %m x n+1 matrix of m timesteps, where n is the number of states and the first column is the time history
% m should be the same for all agents, but n will vary

%for agents of type 'planar', the states are just x,y,heading, v1, v2, and headingdot. We propagate x and y
%in the inertial frame, which is north-east-down. v1 and v2 are in the body frame. Neglect
%acceleration-level translational dynamics for now.

for i = 1:N
    ags(i).model = @planar;
    ags(i).ref = @linearRandom2D;%moves in a straight line with random heading perturbations every 1 sec
end

figure;
dataout = [];
for i = 1:N
    x0 = rand(3,1).*[20;20;2*pi] - [10;10;pi];%random initialization within a 10 m circle 
    toutput = 0.0:.01:tfinal;
    [T,Y] = ags(i).model(toutput,[x0;0;0;0],ags(i).ref);
    ags(i).statehist = [T Y];
    
    plot(Y(:,2),Y(:,1),'linewidth',2);
    hold on;
    plot(Y(1,2),Y(1,1),'o','linewidth',2);
	
    dataout = [dataout T Y];
end

%% write out histories
timetime = clock;
month = timetime(2);
day = timetime(3);
yr = timetime(1);

outname = ['sim_out_' num2str(yr) '_' num2str(month) '_' num2str(day) '.bin'];
fid2 = fopen( [outname(1:end-4) '_types.txt'],'wt');
%write labels
fprintf(fid2,'%i\n',size(dataout,1));
for i = 1:N
    switch func2str(ags(i).model)
        case 'planar'
            fprintf(fid2,'%i ',1);
    end
end
fclose(fid2);

%write data
fid = fopen(outname,'w');
fwrite(fid,dataout,'double');
fclose(fid);