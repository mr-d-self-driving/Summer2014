function [T,Y] = driver_test()
close all;
clear eqom;

FLAG_DONE = 0;

v1max = 1;
vtmax = 0.5;

psi1max = 1;

t = [0 30];

y0 = [0;0;0];%rx, ry, psi in inertial

yt0 = [randn(2,1)*10-5;2*pi*rand-pi];

[T,Y] = ode45(@eqom,t,y0,odeset('abstol',1e-6,'reltol',1e-6));

figure;
subplot(211);
plot(Y(:,2),Y(:,1));
hold on;
plot(Y(end,2),Y(end,1),'x');
plot(yt0(2) + vtmax.*sin(yt0(3)).*T,yt0(1) + vtmax.*cos(yt0(3)).*T,'r--');
plot(yt0(2) + vtmax.*sin(yt0(3)).*T(end),yt0(1) + vtmax.*cos(yt0(3)).*T(end),'rd');
subplot(212);
plot(T,Y(:,1:2));
hold on;
plot(T,repmat(yt0(1:2)',length(T),1) + vtmax*repmat([cos(yt0(3)) sin(yt0(3))],length(T),1).*[T T],'r--');

    function dy = eqom(t,y)
        %y: [rx ry psi lambda_psi]
        
        global RT_T YT;
        
        RT_T = yt0(1:2) + t*vtmax*[cos(yt0(3));sin(yt0(3))];
        
        YT = y(1:2);
        
        persistent last_ref;
        if isempty(last_ref)
            D = RT_T - YT;
            last_ref = [25;atan2(D(2),D(1))];
        end
        
        if norm(YT - RT_T) < 1e-2
            FLAG_DONE = 1;
        end
        
        if FLAG_DONE
            dy = [0;0;0];
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
        
        dy = [v1max*cos(y(3));v1max*sin(y(3));u];
    end
    function [f,J] = nonlinsolve(x)
        global RT_T YT;
        
        f = zeros(3,1);
        J = zeros(3,2);
        
        f(1:2) = RT_T - YT + vtmax*[cos(yt0(3));sin(yt0(3))]*x(1) - x(1)*v1max*[cos(x(2));sin(x(2))];
        J(1:2,:) = [vtmax*[cos(yt0(3));sin(yt0(3))]-v1max*[cos(x(2));sin(x(2))] v1max*x(1)*[sin(x(2));-cos(x(2))]];
        
        if x(1) < 0
            f(3) = -x(1);
            J(3,1) = -1;
        end
        %if x(1) < 0
        %    f = f + (x(1))^2;
        %    J(:,1) = J(:,1) + 2*x(1);
        %end
    end
end