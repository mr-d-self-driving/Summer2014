function xref = vel_ref(t,y)

% ref: [vx vy w0 thetaidot thetajdot]

xref = [.1;0;0.1*sin(t);0;0];

end