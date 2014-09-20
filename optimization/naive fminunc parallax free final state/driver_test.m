
h = T/N;

thiscount = 0;
L0m = [1e-4;1e-4];
%while( (any(abs(1-L0m./L0) > 1e-2) && costf(L0) > h^2))
    thiscount = thiscount+1;
    count = count + 1;
    L0m = L0;
    %L0 = graddescent(L0,@costf);
    L0 = fminunc(@costf,L0);
    disp([count L0' costf(L0)]);
%     if abs(1-costf(L0m)/costf(L0)) < 1e-4
%         disp('*** Solver stalled, breaking ***');
%         break;
%     end
%     if thiscount > 250
%         disp('*** Solver timed out, slow convergence probable ***');
%         break;
%     end
%end
disp('----------------------------------------------');