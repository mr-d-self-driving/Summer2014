% initialize
clear variables;
close all;

%N: number of time steps
N = 4;
% m: length of control vector
m = 2;
% n: number of candidate solutions
n = 100;
% G: number of generations
G = 100;
% K: number of subproblems to solve for the nonlinear constraints
K = 10;
% TOL: tolerance for subproblem convergence
TOL = 1e-4;
% REP_PCT: fraction of solutions to reproduce
REP_PCT = 0.2;
% MUT_PCT: percentage of genes to mutate
MUT_PCT = 0.5;

% initial GA population
Ubit = round(rand(8*m*N,n));
U = bit2doub(Ubit,m*N);

% initial subproblem penalties and Lagrange multiplier estimates
LA = rand(K,3)*10;%Lagrange multiplier estimates
RH = 1*ones(K,1);%penalty

% previous value of the augmented function for each solution and each subproblem 
aug_f_last = zeros(K,n);
% previous generation
UOLD = zeros(size(U));
% test the augmented function minimization
for i = 1:G
    FLAG_SUB_SOLVED = 0;
    UOLD = U;
    % for each augmented subproblem
        % evaluate the augmented penalty function for each candidate solution
    aug_f = repmat( fitnessf(U), K, 1) + LA*constrf(U) + 0.5*RH*sum(constrf(U).^2,1);
        % if the subproblem is solved to within tolerance, update the associated Langrange multiplier estimates 
    minvals = 1-min(aug_f_last,[],2)./min(aug_f,[],2);
    ix = find(abs(minvals) < TOL);
    jx = setdiff(1:K,ix);
    if ~isempty(ix)
        FLAG_SUB_SOLVED = 1;
        ceq = zeros(length(ix),3);
        for j = 1:length(ix)
            [~,jm] = min(aug_f(ix(j),:));
            ceq(j,:) = constrf(U(:,jm))';
        end
        LA(ix,:) = LA(ix,:)./ceq;
    end
        % else, increase the associated penalty parameter
        RH(jx) = 1.25*RH(jx);
    % if we solved a subproblem, do reproduction
    if FLAG_SUB_SOLVED
        NUMREP = floor(REP_PCT*n);
        UNEW = zeros( N*m, NUMREP*length(ix));
        for j = 1:length(ix)
            [~,iy] = sort(aug_f(ix(j),:));
            reps = UOLD(:,iy(1:NUMREP));
            % now reproduce
            breeders = ceil( rand( n,2)*NUMREP );
            %new = 
        end
    end
    % do mutation
    % mutate MUT_PCT fraction of all genes
    mutind = ceil(rand(MUT_PCT*8*m*N*n,1)*8*m*N*n);
    Ubit(mutind) = ~Ubit(mutind);
    U = bit2doub(Ubit,m*N);
    % I guess we should break if something satisfies all the subproblems??
    
    aug_f_last = aug_f;
end
