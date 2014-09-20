
%%

function x0 = rk4_X(t,x0)

global dt

%% integrating with runge-kutta method and finding new satates

    k1=[];  k2=[];  k3=[];  k4=[];

    k1=eqn_X(t,x0);
    xc=x0+.5*dt*k1;
    k2=eqn_X(t+dt/2,xc);
    xc=x0+.5*dt*k2;
    k3=eqn_X(t+dt/2,xc);
    xc=x0+ dt*k3;
    k4=eqn_X(t+dt,xc);
    x0=x0+ dt/6*(k1+2*k2+2*k3+k4);
    


