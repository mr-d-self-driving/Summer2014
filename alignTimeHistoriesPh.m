function [delta] = alignTimeHistoriesPh(t0,d0,t1,d1)
% align time histories of data from one source (t0,d0) with another
% source(t1,d1) using the phase correlation
% t0 is an L0 x 1 vector
% d0 is an L0 x n matrix
% t1 is an L1 x 1 vector
% 
% t0 should be whichever time history has the faster update rate

%always interpolate in t0 for the times in t1, so make sure the start and
%end of t1 are within the bounds of t0

% interpolate

if t1(end) > (t0(end))
    inl = find(t1 < (t0(end)),1,'last');
    t1(inl:end) = [];
    d1(inl:end,:) = [];
end
if t1(1) < (t0(1))
    inF = find(t1 > (t0(1)),1,'first');
    t1(1:inF) = [];
    d1(1:inF,:) = [];
end

d0_int = interp1(t0,d0,t1);

% hamming window
%l0 = hamming(length(t0));
%l1 = ones(length(t1),1);
l1 = hamming(length(t1));

d0_int = d0_int.*l1;
d1 = d1.*l1;

% time histories: t1 & d1
%                 t1cpy & d0_int
y1 = fft(d1);
y2 = fft(d0_int);
R = y1.*conj(y2)/norm(y1.*conj(y2));
r = ifft(R);

[~,in] = max(r);
N = length(r)/2;
if in > length(r)/2
    in = in - length(r);
end
%nVect = linspace(-N,N,length(r));
delta = mean(diff(t1))*in;
end