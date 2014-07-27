function [at]=block_tr(nrow,nblock,ncol,a,flag)
%
%       Routine to perform block transposition
%
%  [at]=block_tr(nrow,nblock,ncol,a,flag)
%
%  INPUT PARAMETERS
%    flag     =set to 1 for wide matrix, 0 for tall matrix  
%                   blocks are assumed to be expanded columnwise
%                   in both cases
%    nrow     =number of rows in block
%    nblock   =number of blocks
%    ncol     =number of columns in block
%    a        =input matrix nrow x [nblock*ncol] when flag=1
%                           [nblock*nrow] x ncol when flag=0
%
%   OUTPUT PARAMETERS
%    at      =Block tranposition (it is not the matrix transposed)
%

%       L.G. Horta 5/25/91
%       NASA Spacecraft Dynamics Branch
at=[];
if flag==1;
   total=ncol*nblock;
    for i=1:nblock;
     nstart=(i-1)*ncol+1;
     nend=i*ncol;
     at=[at; a(:,nstart:nend)];
    end;
else;
   total=nrow*nblock;
     for i=1:nblock;
       nstart=(i-1)*nrow+1;
       nend=i*nrow;
       at=[at a(nstart:nend,:)];
     end;
end;
