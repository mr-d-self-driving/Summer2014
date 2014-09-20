function dy = local_eqom(t,y)
MU = 1;
%y: [r theta u v lambda_{r theta u v}]
dy = [y(3);
    y(4)/y(1);
    y(4)^2/y(1) - MU/y(1)^2 - 0.5*y(7);
    -y(3)*y(4)/y(1)-0.5*y(8);
    y(6)*y(4)/y(1)^2 - y(8)*y(3)*y(4)/y(1)^2 - y(7)*(2*MU/y(1)^3 - y(4)^2/y(1)^2);
    0;
    -y(5)+y(8)*y(4)/y(1);
    -y(6)/y(1) + y(8)*y(3)/y(1) - 2*y(7)*y(4)/y(1)];
end