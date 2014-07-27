r=2;m=2;pt=100;p=3;
Markov=randn(m,r*pt);      
[d,H]=hankl(Markov,r,p);
R0=H*H';
[D,R]=hankldc(Markov,r,p);
