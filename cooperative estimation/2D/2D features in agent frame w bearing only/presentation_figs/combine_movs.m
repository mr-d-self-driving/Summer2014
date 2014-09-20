%% combine two animate files

close all;
clear variables;

f1 = '../animate_normal_ind.avi';
f2 = '../animate_normal_coop.avi';

VR1 = VideoReader(f1);
VR2 = VideoReader(f2);

nFrames = VR1.NumberOfFrames;
nFrames = 500;
vidHeight = VR1.Height;
vidWidth = VR1.Width;

mov(1:nFrames) = ...
    struct('cdata', zeros(vidHeight, 2*vidWidth, 3, 'uint8'),...
    'colormap', []);

for i = 1:nFrames
    mov(i).cdata(1:vidHeight,1:vidWidth,:) = read(VR1,i);
    mov(i).cdata(1:vidHeight,1+vidWidth:2*vidWidth,:) = read(VR2,i);
end

% write out to file
VR = VideoWriter('combined_normal.avi');
VR.FrameRate = 30;
open(VR);
for i = 1:nFrames
    writeVideo(VR,mov(i));
end
close(VR);