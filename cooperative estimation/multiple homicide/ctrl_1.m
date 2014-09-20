function u = ctrl_1(t,y)

persistent psi1max v1max vtmax;
if isempty(psi1max)
    psi1max = 1;
    v1max = 1;
    vtmax = 0.9;
end

RT_T = y(4:5);
YT = y(1:2);

persistent last_ref FLAG_DONE;
if isempty(last_ref)
    D = RT_T - YT;
    last_ref = [25;atan2(D(2),D(1))];
    FLAG_DONE = 0;
end

if norm(YT - RT_T) < 1e-2
    FLAG_DONE = 1;
end

if FLAG_DONE
    u = 0;
    return;
end

ref = fsolve(@nonlinsolve,last_ref,optimset('disp','none','Jacobian','on','algorith','levenberg-marquardt'));
last_ref = ref;

psiref = ref(2);
psi = y(3);

% make sure minimum psi is the one used
while abs((psi - 2*pi) - psiref) < abs(psi-psiref)
    psi = psi-2*pi;
end
while abs((psi + 2*pi) - psiref) < abs(psi-psiref)
    psi = psi+2*pi;
end

delt = psi - psiref;
if abs(delt) < 1e-3
    u = 0;
else
    if delt > 0
        u = -psi1max;
    else
        u = psi1max;
    end
end

    function [f,J] = nonlinsolve(x)
        
        f = zeros(3,1);
        J = zeros(3,2);
        
        f(1:2) = RT_T - YT + vtmax*[cos(y(6));sin(y(6))]*x(1) - x(1)*v1max*[cos(x(2));sin(x(2))];
        J(1:2,:) = [vtmax*[cos(y(6));sin(y(6))]-v1max*[cos(x(2));sin(x(2))] v1max*x(1)*[sin(x(2));-cos(x(2))]];
        
        if x(1) < 0
            f(3) = -x(1);
            J(3,1) = -1;
        end
    end

end