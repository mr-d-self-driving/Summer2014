function H=marcomc(ybar,m,r,n_markov)
%----------------------------------------------------------------------------
%
%  Routine to return the system, observer, and controller Markov parameters
%  from feedback control input ufb, additive input excitation v, and output
%  response y
%
%                  H=marcomc(ybar,p,r,n_markov)
%
%  INPUT VARIABLES
%     ybar = arxc parameters 
%        r = number of inputs                                 
%        m = number of outputs                                 
% n_markov = number of desired system, observer, controller Markov parameters
%
%   OUTPUT VARIABLES
%        ocs =   identified system, observer, controller Markov parameters
%    H = [[D;#0],[C;-F]*[B,-G],[C;-F]*A*[B,-G],...,[C;-F]*A^(n_markov-1)*[B,-G]]
%
%-------------------------------------------------------------------------------

%  M. Phan, NASA SDB, revised by Jer-nan Juang 3/31/95
%
[yr,yc]=size(ybar);
ybar1=ybar(1:m,:);ybar2=ybar(m+1:m+r,:);
Dc=ybar1(:,1:r);Df=ybar2(:,1:r);
H0=[Dc zeros(m,m);Df zeros(r,m)];
ybar2=ybar2(:,r+1:yc);
p=(yc-r)/(r+m);
ybar2=[ybar2 zeros(r,(r+m)*(n_markov-p))];
% ----------------------------------------------------------------------------
% Unscramble ybar1
%
H1=marcomp(ybar1,0,r,n_markov+1,0);H1(:,1:r+m)=[];
% ----------------------------------------------------------------------------
% Unscramble ybar2
%
[Y1,Y2]=separate(ybar2,r,r,m);
Ys=[Dc zeros(m,m)];
H2=[];
q=r+m;
for i=1:n_markov;
    k=(i-1)*r+1:i*r;
	k1=(i-1)*m+1:i*m;
    fbg=[Y1(:,k) -Y2(:,k1)]+Y2(:,1:i*m)*Ys;
    Ys=[H1(:,(i-1)*q+1:i*q);Ys];
    H2=[H2 fbg];
end
%
% ----------------------------------------------------------------------------
% Assemble H from H1, H2, and H0
%
H=[H1;H2];
H=[H0 H];
