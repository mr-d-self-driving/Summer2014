function x = inertial_filter_predict(dt,x,acc)

if isfinite(dt)
    if(~isfinite(acc))
        acc = 0;
    end
    x(1) = x(2)*dt+acc*dt^2*0.5;
    x(2) = acc*dt;
end

end