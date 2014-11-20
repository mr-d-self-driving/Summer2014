%DCM2eul - returns the euler angle rotation sequence corresponding to cosine matrix C and specified sequence seq. 
function[eul, seq] = DCM2eul(C,seq)
    %[eul,seq] = DCM2Eul(C,seq)
    %
    %C - a 3 x 3 direction cosine matrix
    %seq - a 3 x 1 vector specifying the Euler angle sequence to return
    if nargin==1
        %angle rotation sequence not specified, default to 3-1-3
        seq = [3;1;3];
    end
    %nine possible sequences exist
    if seq(1)==seq(3)
        switch seq(1)
            case 1
                thet2 = acos(C(1,1));
            case 2
                thet2 = acos(C(2,2));
            case 3
                thet2 = acos(C(3,3));
        end
        if seq == [3;1;3]
            thet3 = atan2(C(1,3),C(2,3));
            thet1 = atan2(C(3,1),-C(3,2));
        end
        if seq == [1;2;1]
            thet1 = atan2(C(1,2),-C(1,3));
            thet3 = atan2(C(2,1),C(3,1));
        end
        if seq == [1;3;1]
            thet1 = atan2(C(1,3),C(1,2));
            thet3 = atan2(C(3,1),-C(2,1));
        end
        if seq == [2;1;2]
            thet1 = atan2(C(2,1),C(2,3));
            thet3 = atan2(C(1,2),-C(3,2));
        end
        if seq == [2;3;2]
            thet1 = atan2(C(2,3),-C(2,1));
            thet3 = atan2(C(3,2),C(1,2));
        end
        if seq ==[3;2;3]
            thet1 = atan2(C(3,2),C(3,1));
            thet3 = atan2(C(2,3),-C(1,3));
        end
    else
        %asymmetric set
        if seq == [1;2;3]
            thet2 = asin(C(3,1));
            thet1 = atan2(-C(3,2),C(3,3));
            thet3 = atan2(-C(2,1),C(1,1));
        end
        if seq == [1;3;2]
            thet2 = -asin(C(2,1));
            thet1 = atan2(C(2,3),C(2,2));
            thet3 = atan2(C(3,1),C(1,1));
        end
        if seq == [2;1;3]
            thet2 = -asin(C(3,2));
            thet1 = atan2(C(3,1),C(3,3));
            thet3 = atan2(C(1,2),C(2,2));
        end
        if seq ==[2;3;1]
            thet2 = asin(C(1,2));
            thet1 = atan2(-C(1,3),C(1,1));
            thet3 = atan2(-C(3,2),C(2,2));
        end
        if seq == [3;1;2]
            thet2 = asin(C(2,3));
            thet1 = atan2(-C(2,1),C(2,2));
            thet3 = atan2(-C(1,3),C(3,3));
        end
        if seq == [3;2;1]
            thet2 = -asin(C(1,3));
            thet1 = atan2(C(1,2),C(1,1));
            thet3 = atan2(C(2,3),C(3,3));
        end
    end
    %if ~exist('thet1','var')
    %    error('Invalid rotation sequence specified');
    %end
    %check the sign of angles:
    thet1 = mod(thet1,2*pi);
    thet3 = mod(thet3,2*pi);
    if seq(1)==seq(3)%if symmetric, 0<theta2<=pi
        thet2 = mod(thet2,2*pi);
    else%is asymmetric, -pi/2<=theta2<=pi/2
        %???
        if abs(thet2)>pi/2
            %disp('Warning: second angle of asymmetric set is outside the range +/- pi/2.');
        end
    end
    eul = [thet1;thet2;thet3];
end