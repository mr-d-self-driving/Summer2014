%% presentation_process_batch

errsc = cell(length(batch),1);
errsi = cell(length(batch),1);
tic;
for I = 1:length(batch);
    load(batch{I});
    
    errscoop = zeros(length(tspan)*Krun,5);
    errssolo = zeros(length(tspan)*Krun,5);
    for j = 1:N
        % compute inertial frame truth values
        xtrue = ags(j).truth(:,1:5);
        for kk = 1:length(tspan)
            Cbn = [cos(xtrue(kk,5)) sin(xtrue(kk,5));
                -sin(xtrue(kk,5)) cos(xtrue(kk,5))];
            xtrue(kk,1:2) = xtrue(kk,1:2)*Cbn';
        end
        for i = 1:Krun
            errscoop((1:length(tspan))+(i-1)*length(tspan),:) = xtrue - dvect{i,j};
            errssolo((1:length(tspan))+(i-1)*length(tspan),:) = xtrue - dvect2{i,j};
        end
    end
    
    errsc{I} = errscoop;
    errsi{I} = errssolo;
    etaCalc(I,length(batch),toc);
end