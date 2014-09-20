function dP = fwd_int_P(P,F,G)
    %F: gradient of xdot at current time
    global Qk;
    
    dP = F*P + P*F' + G*Qk*G';
end