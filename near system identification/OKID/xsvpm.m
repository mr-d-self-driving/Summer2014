k1=1.0;k2=2.0;k3=3.0;
m1=1.0;m2=1.0;m3=1.0;ratio=2*0.005;
K=[k1+k2  -k2   0 ; -k2 k2+k3 -k3; 0   -k3   k3];
Khalf=sqrtm(K);
Damp=ratio*Khalf;
Ac=[zeros(3,3) eye(3,3);-K -Damp];
Bc=[zeros(3,2);1 0; 0 1; 0 0];
C=[zeros(3,3) eye(3,3)];
dt=1.0;pt=60;
[A,B]=c2d(Ac,Bc,dt);
[V,lambda]=eig(A);
bm=V\B;cm=C*V;lambda=diag(lambda);
[a,b,c,svm,index] = svpm(lambda,bm,cm,1);

