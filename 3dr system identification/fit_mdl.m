function x = fit_mdl(lhs,rhs)
% lhs: n x m matrix, where n is the length of the time vector and m is the
% number of states involved in the associated model

%d = [lhs(tind,1);lhs(tind,2)];
d = reshape(lhs,[],1);
C = reshape(rhs,[],1);
%C = [rhs(tind,1);rhs(tind,2)];
x = lsqlin(C,d,[],[]);

end