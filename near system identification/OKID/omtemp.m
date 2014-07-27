function [a, b, b0, alpha, beta, beta0] = omtemp(ybar,p,q,r,m)

for i = 1:r
  beta0(:,i) = ybar(:,i) ;
end

for i = 1:p
    beta(:,i*r-r+1:i*r) = ybar(:,r+i*(r+m)-(r+m)+1:r+i*(r+m)-m);
    alpha(:,i*m-m+1:i*m) = ybar(:,r+i*(r+m)-m+1:r+i*(r+m));
end

j = 1;
    for i = 1:p
      if i == p 
         a(i*m-m+1:i*m,j*m-m+1:j*m) = alpha(:,j*m-m+1:j*m)*alpha(:,i*m-m+1:i*m) ;
         b(i*m-m+1:i*m,j*r-r+1:j*r) = alpha(:,j*m-m+1:j*m)*beta(:,i*r-r+1:i*r);   
        else 
          a(i*m-m+1:i*m,j*m-m+1:j*m) = alpha(:,j*m-m+1:j*m)*alpha(:,i*m-m+1:i*m) + alpha(:,(i+1)*m-m+1:(i+1)*m);
          b(i*m-m+1:i*m,j*r-r+1:j*r) = alpha(:,j*m-m+1:j*m)*beta(:,i*r-r+1:i*r) + beta(:,(i+1)*r-r+1:(i+1)*r); 
    end
   end   

for j = 2:p+q+1
  for i = 1:p
   if i == p
         a(i*m-m+1:i*m,j*m-m+1:j*m) = a(1:m,(j-1)*m-m+1:(j-1)*m)*alpha(:,i*m-m+1:i*m); 
         b(i*m-m+1:i*m,j*r-r+1:j*r) = a(1:m,(j-1)*m-m+1:(j-1)*m)*beta(:,i*r-r+1:i*r);  
   else 
         a(i*m-m+1:i*m,j*m-m+1:j*m) = a(1:m,(j-1)*m-m+1:(j-1)*m)*alpha(:,i*m-m+1:i*m) + a((i+1)*m-m+1:(i+1)*m,(j-1)*m-m+1:(j-1)*m);
         b(i*m-m+1:i*m,j*r-r+1:j*r) = a(1:m,(j-1)*m-m+1:(j-1)*m)*beta(:,i*r-r+1:i*r) + b((i+1)*m-m+1:(i+1)*m,(j-1)*r-r+1:(j-1)*r) ;
   end
end
end

for j = 1:p+q+1
    if j == 1
        b0(:,j*r-r+1:j*r) = alpha(:,j*m-m+1:j*m)*beta0 + beta(:,j*r-r+1:j*r);
   else
        b0(:,j*r-r+1:j*r) = a(1:m,(j-1)*m-m+1:(j-1)*m)*beta0 + b(1:m,(j-1)*r-r+1:(j-1)*r);
    end 
end

