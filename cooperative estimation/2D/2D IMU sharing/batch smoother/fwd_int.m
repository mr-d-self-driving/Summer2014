function [f,Fk,G] = fwd_int(x,u)
    psii = x(5);
    rb = x(1:2);%inertial-frame position, relative to initial
    vb = x(3:4);%body-frame velocity
    % inertial-to-body DCM
    Cbn = [cos(psii) sin(psii);-sin(psii) cos(psii)];
    omega = u(3);
    ai = u(1:2);
    % outputs
    f = zeros(size(x));
    Fk = zeros(size(x,1));
    f(1:5) = [Cbn'*vb;
        ai - [0 -omega;omega 0]*vb;
        omega];
    %gradient of f
    Fk(1:5,1:5) = [zeros(2) Cbn' [-sin(psii) -cos(psii);cos(psii) -sin(psii)]*vb;
        zeros(2) -[0 -omega;omega 0] zeros(2,1);
        zeros(1,5)];
    % process noise influence matrix
    G = zeros(size(x,1),3);
    G(3:5,1:3) = [-1 0 -vb(2);
        0 -1 vb(1);
        0 0 -1];
end