function [delta] = alignTimeHistories(t0,d0,t1,d1,x0)
% align time histories of data from one source (t0,d0) with another
% source(t1,d1) using a least-squares best fit
% t0 is an L0 x 1 vector
% d0 is an L0 x n matrix
% t1 is an L1 x 1 vector
% 
% t0 should be whichever time history has the faster update rate

%always interpolate in t0 for the times in t1, so make sure the start and
%end of t1 are within the bounds of t0

if nargin < 5
    x0 = 0;
end

options = optimset('disp','iter','maxfunevals',1000);
delta = fminunc(@fminfun,x0,options);

    function f = fminfun(x)
       %x = timeshift in t0
              
       %make sure we don't interpolate outside the bounds of t0
       t1cpy = t1;
       d1cpy = d1;
       if t1cpy(end) > (t0(end)+x)
           inl = find(t1cpy < (t0(end)+x),1,'last');
           t1cpy(inl:end) = [];
           d1cpy(inl:end,:) = [];
       end
       if t1cpy(1) < (t0(1)+x)
           inF = find(t1cpy > (t0(1)+x),1,'first');
           t1cpy(1:inF) = [];
           d1cpy(1:inF,:) = [];
       end
       
       d0_int = interp1(t0+x,d0,t1cpy);
       
       f = sum( sum((d0_int - d1cpy).^2,1) );
    end

end