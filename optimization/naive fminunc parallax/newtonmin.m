function u = newtonmin(u,chandle)
% employs a Newton's method

ALPHA = 0.1;

count = 0;
while all(abs(chandle(u)) > 1e-7) && count < 1000
    count = count+1;
    
    % u is a n x 1 vector
    n = length(u);
    J = chandle(u);
    % J is an m x 1 vector, m being the number of constraints
    
    Jt = chandle( repmat(u,1,n) + 1e-10*eye(n) );
    % Jt is a m x n vector
    
    %H is the apprx gradient of the constraint error vector w.r.t. each value in u
    H = (Jt - repmat(J,1,n))*1e10;
    
    % update and return
    u = u - ALPHA*(H\J);
end

end