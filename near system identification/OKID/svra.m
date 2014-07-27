function [a,b,c,d,xs,xt]=svra(ut,yt,n,ni,nj,dt,k)
% 
%  Identify a state space model directly from input and output   
%  data by a state vector realization algorithm.               
%                                                              
%  [a,b,c,d,xs,xt]=svra(ut,yt,n,ni,nj,dt,k);        
%                                                              
%       ut = input histories stacked in rows  
%       yt = output data stacked in rows                       
%        n = chosen model order                                
%       ni = no. of sample shifts used for constructing        
%            rows of a Hankel matrix                           
%       nj = no. of columns of the Hankel matrix               
%       dt = sample time interval (sec)                        
%        k = first data used for realization                   
%                                                              
%............The identified model is...........................
%          x(k+1) = ax(k) + bu(k)                              
%            y(k) = cx(k) + du(k)                              
%       xs = singular values of the hankel matrix.  	          
%       xt = 1st column = Dampings (%)                         
%            2nd column = Frequencies (Hz)                     
%            3nd column = complex eigenvalues                  
                                                                  
%         J. S. Lew  1-10-91, ODU Research Associate                                       
%         NASA Spacecraft Dynamics Branch                                                    

ut=ut';yt=yt';
[l,l01]=size(yt);
[m,l01]=size(ut);
k=k-1;
ni=ni/2;
for i1=1:2*ni,
ii1=(l+m)*(i1-1)+1;ii2=ii1+m-1;ii3=ii1+l+m-1;
h0(ii1:ii2,:)=ut(:,k+i1:k+i1+nj-1);
h0(ii2+1:ii3,:)=yt(:,k+i1:k+i1+nj-1);
end
[u,s,v]=svd(h0);
i11=(l+m)*ni;i12=2*m*ni+n;i22=2*i11;
u11=u(1:i11,1:i12);u12=u(1:i11,i12+1:i22);
u21=u(i11+1:i22,1:i12);u22=u(i11+1:i22,i12+1:i22);
s11=s(1:i12,1:i12);
u12t=u12';
us=u12t*u11*s11;
[uq1,sq1,vq1]=svd(us);
uq=uq1(:,1:n);uqt=uq';
a11=uqt*u12t*u(m+l+1:i11+m+l,:)*s;
a21=u(i11+m+1:i11+m+l,:)*s;
a0=[a11;a21];
b11=uqt*u12t*u(1:i11,:)*s;
b12=u(i11+1:i11+m,:)*s;
b0=[b11;b12];
xx=a0/b0;
a=xx(1:n,1:n);b=xx(1:n,n+1:n+m);
c=xx(n+1:n+l,1:n);d=xx(n+1:n+l,n+1:n+m);
[g,xf]=eig(a);
%gi=inv(g);
xs=diag(s);
xt=deg2hz(diag(xf),dt);
