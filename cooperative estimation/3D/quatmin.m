%% quatmin.m
function qu = quatmin(qu,qu2)

if size(qu,2) ~= 4
    qu = qu';
end

if nargin < 2
    for i = 2:size(qu,1)
        if sum(abs(qu(i,:) + qu(i-1,:))) < sum(abs(qu(i,:) - qu(i-1,:)))
            qu(i:end,:) = -qu(i:end,:);
        end
    end
else
    for i = 1:size(qu,1)
        if sum(abs(qu(i,:) + qu2(i,:))) < sum(abs(qu(i,:) - qu2(i,:)))
            qu(i,:) = -qu(i,:);
        end
    end
end

end