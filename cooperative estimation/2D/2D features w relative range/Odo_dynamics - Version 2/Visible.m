function flag = Visible(Xf,Xr)

global ang dist nf

%% In body frame

alpha = Xr(3);
Xf = Xf-repmat(Xr(1:2),1,nf);
figure(10)
plot(Xf(1,:),Xf(2,:),'xk')
Xf = [cos(alpha) -sin(alpha); sin(alpha)  cos(alpha)]*Xf;
plot(Xf(1,:),Xf(2,:),'xk')

for i = 1 : nf
   
    angl(i) = pi_to_pi(atan2(Xf(2,i),Xf(1,i)));
    distanc(i) = norm(Xf(:,i));
    if  abs(angl(i)) < ang/2 && distanc(i) < dist
        flag(i,1) = 1; 
    else
        flag(i,1) = 0;
    end
    
end

