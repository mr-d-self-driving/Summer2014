n=1;
am=randn(n,n);bm=rand(n,2);cm=rand(1,n);
[v,lambda]=eig(am);
lambda=diag(lambda);
bm=v\bm; cm=cm*v;
   [lambda,k]=sort(lambda);
   bm=bm(k,:);cm=cm(:,k);
[a,b,c]=bk_diag(lambda,bm,cm);

lambdat=lambda'
a


