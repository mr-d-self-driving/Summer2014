% driver_wrapper

clear variables;
close all;

T = 1.720;

global N h;

L0 = zeros(4,1);
counteval = 0;
for NN = [4 6 8 12 16 26 32 50]

N = NN;
h = T/N;

driver_test;
counteval = counteval + count;

end

disp(counteval);