function [a, b,bd, b0,bd0, alpha, beta,betad, beta0, betad0] = domtemp(ybar,dbar,p,q,r,rd,m)

for i = 1:r
  beta0(:,i) = ybar(:,i) ;
end

for i = 1:rd
  betad0(:,i) = dbar(:,i) ;
end

for i = 1:p
    beta(:,i*r-r+1:i*r) = ybar(:,r+i*(r+m)-(r+m)+1:r+i*(r+m)-m);
    alpha(:,i*m-m+1:i*m) = ybar(:,r+i*(r+m)-m+1:r+i*(r+m));
    betad(:,i*rd-rd+1:i*rd) = dbar(:,rd+i*rd-(rd)+1:rd+i*rd);
end

j = 1;
    for i = 1:p
      if i == p 
         a(i*m-m+1:i*m,j*m-m+1:j*m) = alpha(:,j*m-m+1:j*m)*alpha(:,i*m-m+1:i*m) ;
         b(i*m-m+1:i*m,j*r-r+1:j*r) = alpha(:,j*m-m+1:j*m)*beta(:,i*r-r+1:i*r);   
         bd(i*m-m+1:i*m,j*rd-rd+1:j*rd) = alpha(:,j*m-m+1:j*m)*betad(:,i*rd-rd+1:i*rd);   
        else 
          a(i*m-m+1:i*m,j*m-m+1:j*m) = alpha(:,j*m-m+1:j*m)*alpha(:,i*m-m+1:i*m) + alpha(:,(i+1)*m-m+1:(i+1)*m);
          b(i*m-m+1:i*m,j*r-r+1:j*r) = alpha(:,j*m-m+1:j*m)*beta(:,i*r-r+1:i*r) + beta(:,(i+1)*r-r+1:(i+1)*r); 
          bd(i*m-m+1:i*m,j*rd-rd+1:j*rd) = alpha(:,j*m-m+1:j*m)*betad(:,i*rd-rd+1:i*rd) + betad(:,(i+1)*rd-rd+1:(i+1)*rd); 
   
     end
   end   

for j = 2:p+q+1
  for i = 1:p
   if i == p
         a(i*m-m+1:i*m,j*m-m+1:j*m) = a(1:m,(j-1)*m-m+1:(j-1)*m)*alpha(:,i*m-m+1:i*m); 
         b(i*m-m+1:i*m,j*r-r+1:j*r) = a(1:m,(j-1)*m-m+1:(j-1)*m)*beta(:,i*r-r+1:i*r);  
         bd(i*m-m+1:i*m,j*rd-rd+1:j*rd) = a(1:m,(j-1)*m-m+1:(j-1)*m)*betad(:,i*rd-rd+1:i*rd);  
   else 
         a(i*m-m+1:i*m,j*m-m+1:j*m) = a(1:m,(j-1)*m-m+1:(j-1)*m)*alpha(:,i*m-m+1:i*m) + a((i+1)*m-m+1:(i+1)*m,(j-1)*m-m+1:(j-1)*m);
         b(i*m-m+1:i*m,j*r-r+1:j*r) = a(1:m,(j-1)*m-m+1:(j-1)*m)*beta(:,i*r-r+1:i*r) + b((i+1)*m-m+1:(i+1)*m,(j-1)*r-r+1:(j-1)*r) ;
         bd(i*m-m+1:i*m,j*rd-rd+1:j*rd) = a(1:m,(j-1)*m-m+1:(j-1)*m)*betad(:,i*rd-rd+1:i*rd) + bd((i+1)*m-m+1:(i+1)*m,(j-1)*rd-rd+1:(j-1)*rd) ;
   end
end
end

for j = 1:p+q+1
    if j == 1
        b0(:,j*r-r+1:j*r) = alpha(:,j*m-m+1:j*m)*beta0 + beta(:,j*r-r+1:j*r);
        bd0(:,j*rd-rd+1:j*rd) = alpha(:,j*m-m+1:j*m)*betad0 + betad(:,j*rd-rd+1:j*rd);
    else
        b0(:,j*r-r+1:j*r) = a(1:m,(j-1)*m-m+1:(j-1)*m)*beta0 + b(1:m,(j-1)*r-r+1:(j-1)*r);
        bd0(:,j*rd-rd+1:j*rd) = a(1:m,(j-1)*m-m+1:(j-1)*m)*betad0 + bd(1:m,(j-1)*rd-rd+1:(j-1)*rd);
    end 
end

