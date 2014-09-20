function [epskPlus] = resample_multinomial(epsk,wk,n)

U = rand(1,n);

epskPlus = zeros(size(epsk,1),n);
for ii = 1:n
    j = 2;
    if U(ii) < wk(1)
        epskPlus(:,ii) = epsk(:,1);
    else
        while ~( U(ii) > sum(wk(1:j-1)) && U(ii)<=sum(wk(1:j)) )
            j = j+1;
        end
        epskPlus(:,ii) = epsk(:,j);
    end
end

end