function x = inertial_filter_correct(e,dt,x,i,w)

if isfinite(e) && isfinite(dt)
    ewdt = e*w*dt;
    x(i) = x(i) + ewdt;
    if i == 1
        x(2) = x(2)+w*ewdt;
    end
end

end