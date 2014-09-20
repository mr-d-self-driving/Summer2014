function [x1] = minangle(x1,x2)
%find the minimum angle between two vectors of 2D angles x1 and x2
count = 0;
while any( (abs(x1-2*pi-x2) < abs(x1-x2)) | (abs(x1+2*pi-x2) < abs(x1-x2)) )
    in1 = find( abs(x1-2*pi-x2) < abs(x1-x2) );
    x1(in1) = x1(in1)-2*pi;
    in2 = find( abs(x1+2*pi-x2) < abs(x1-x2) );
    x1(in2) = x1(in2)+2*pi;
    count = count+1;
    if count > 50
        disp('Warning: minangle() failing to converge');
        return;
    end
end
end