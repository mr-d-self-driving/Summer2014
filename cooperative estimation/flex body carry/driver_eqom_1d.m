%% driver_eqom_1d
clear variables;
close all;

y0 = [0.2;-0.1;0.11;-0.1];

global K L D;
K = 0.5;
D = 0.1;
L = 1;
A = y0(3) - (L+D)/2;

tspan = [0 10];

f1handle = @(t,x) 1e-2./(t+.01);

[T,Y] = eqom_1d(tspan,y0,f1handle);

x1 = Y(:,1);
x2 = x1-Y(:,3);

figure;
subplot(211);
plot(T,[x1 x2]);

subplot(212);
plot(T,Y(:,3));