function yk = measurement_eq_10_state(xk,nk,uk)

% m1: # of features agent 1 sees

%xk: 10 x 2N+1, inertial position, inertial velocity, inertial quaternion, relative position, and relative quaternion
%nk: 3*m1 x 2N+1, feature range/bearing/azimuth errors FOR EACH FEATURE

%uk[wi;ai;# of i features;rkn;...;# of j features;rkn;...] : 6+2+3*m x 2N+1, m being total # of features from i and j 

m1 = uk(7);
m = m1;% total # of features

% 3 x m1 array of known inertial position of features seen by agent 1
if m1 > 0
    RKN_1 = reshape(uk(7+(1:m1*3)),3,[])';
else
    RKN_1 = [];
end

n = size(xk,1);
l = size(nk,1);

yk = zeros(3*m,size(xk,2));
for k = 1:size(xk,2)
    % estimated my inertial position
    rin = xk(1:3,k);
    % my estimated inertial attitude
    qin = xk(7:10,k);
    Cin = attparsilentmex(qin,[6 1]);
    
    % feature measurements
    for kk = 1:m1
        % get the i frame vector to the feature
        rki = Cin*(RKN_1(kk,:)' - rin);
        % the index for now
        index = (kk-1)*3 + (1:3);
        % compute range/bearing/declination
        %y_kk = [sqrt(sum(rki.^2));atan2(rki(2),rki(1));atan2(rki(3),sqrt(sum(rki(1:2).^2)))] + nk(index,k);
        y_kk = vector2polar(rki);
        yk(index,k) = y_kk;
    end
    
    if k > 1
        % minimize all angle differences
        yk( (2:3:3*m1),k ) = minangle(yk((2:3:3*m1),k),yk((2:3:3*m1),1));
        yk( (3:3:3*m1),k ) = minangle(yk((3:3:3*m1),k),yk((3:3:3*m1),1));
    end
end

end
