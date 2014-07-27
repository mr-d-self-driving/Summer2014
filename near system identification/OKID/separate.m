function [Y1,Y2] = separate(Y,q,m1,m2)
% ---------------------------------------------------------------------
%  Routine to separate a sequence into two sequences of prescribed format
%
%                  [Y1,Y2] = separate(Y,q,m1,m2)
%
%  A given matrix Y
%       Y = [Y1(1) Y1(2) | Y2(1) Y2(2) | ... | Yn(1) Yn(2)]
%  is separated into two matrices
%      Y1 = [Y1(1) Y2(1) ... Yn(1)] , each Yi(1) has dimensions q by m1
%      Y2 = [Y1(2) Y2(2) ... Yn(2)] , each Yi(2) has dimensions q by m2
% ---------------------------------------------------------------------

%  M. Phan, NASA SDB

Y1=[];Y2=[];
[nrowsY,ncolsY] = size(Y);
N = ncolsY/(m1+m2);
for i = 1:N;
 Y1 = [Y1,Y(:,(i-1)*(m1+m2)+1:(i-1)*(m1+m2)+m1)];
 Y2 = [Y2,Y(:,(i-1)*(m1+m2)+m1+1:i*(m1+m2))];
end


   

