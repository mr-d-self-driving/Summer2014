
h = T/N;

thiscount = 0;
Lfm = [1e-4;1e-4];
%while( (any(abs(1-Lfm./Lf) > 1e-2) || costf(Lf) > h^2))
    thiscount = thiscount+1;
    count = count + 1;
    Lfm = Lf;
    %Lf = graddescent(Lf,@costf);
    options = optimset('disp','iter');
    Lf = fminunc(@costf,Lf,options);
    disp([count Lf' costf(Lf)]);
%     if abs(1-costf(Lfm)/costf(Lf)) < 1e-4
%         disp('*** Solver stalled, breaking ***');
%         break;
%     end
%     if thiscount > 250
%         disp('*** Solver timed out, slow convergence probable ***');
%         break;
%     end
%end
disp('----------------------------------------------');