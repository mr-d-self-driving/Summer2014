function [lamdaf,bmf,cmf,msv_f,lamdab,bmb,cmb,msv_b]=match(af,bf,cf,ab,bb,cb)
% 
%     Function match matches eigenvalues of forward and backward models        
%                                                                   
%[lamdaf,bmf,cmf,msv_f,lamdab,bmb,cmb,msv_b]=match(af,bf,cf,ab,bb,cb) 
%
%     INPUT PARAMETERS                                       
%
%   af  = state matrix from the identified forward model; A                                   
%   bf  = input matrix from the identified forward model; B                                    
%   cf  = output matrix from the identified forward model; C                                   
%   ab  = state matrix inverse from the identified backward model; A^-1                                   
%   bb  = input matrix from the identified backward model;(-A^-1)B                                    
%   cb  = output matrix from the identified backward model; C                                   
%                                                                   
%     OUTPUT PARAMETERS                                       
%                                                                   
%   lamdaf  = eigenvalues of the reduced modal forward model                                   
%   bmf     = input matrix of the reduced modal forward model                                    
%   cmf     = output matrix of the reduced modal forward model                                   
%   msv_f   = singular value weighting of the eigenvalues lamdaf                                   
%   lamdab  = eigenvalues of the reduced modal backward model                                   
%   bmb     = input matrix of the reduced modal backward model                                    
%   cmb     = output matrix of the reduced modal backward model                                   
%   msv_b   = singular value weighting of the eigenvalues lamdab                                   

%         J. N. Juang 12-19-91                                       
%         NASA Spacecraft Dynamics Branch                           


  [V,lamdab]=eig(ab);lamdab=diag(lamdab); 
  bmb=V\bb;cmb=cb*V; 

  n_b=length(lamdab);
  [msv_b,cq]=svpm(lamdab,bmb,cmb,1);
  [msv_b,i]=sort(msv_b(:,1));
  lamdab=lamdab(i);bmb=bmb(i,:);cmb=cmb(:,i);
%
  i_u=abs(lamdab)>1.0;n_bu=sum(i_u);
  i_s=abs(lamdab)<=1.0;n_bs=sum(i_s);
  lamdab=[lamdab(i_s);lamdab(i_u)];
  msv_b=[msv_b(i_s);msv_b(i_u)];
  bmb=[bmb(i_s,:);bmb(i_u,:)];cmb=[cmb(:,i_s) cmb(:,i_u)];

   [V,lamdaf]=eig(af);lamdaf=diag(lamdaf);
   bmf=V\bf;cmf=cf*V;clear V;
%
  n_f=length(lamdaf);
  [msv_f,cq]=svpm(lamdaf,bmf,cmf,1);
  [msv_f,i]=sort(msv_f(:,1));
  lamdaf=lamdaf(i);bmf=bmf(i,:);cmf=cmf(:,i);
%
  i_u=abs(lamdaf)>1.0;n_fu=sum(i_u);
  i_s=abs(lamdaf)<=1.0;n_fs=sum(i_s);
  lamdaf=[lamdaf(i_u);lamdaf(i_s)];
  msv_f=[msv_f(i_u);msv_f(i_s)];
  bmf=[bmf(i_u,:);bmf(i_s,:)];cmf=[cmf(:,i_u) cmf(:,i_s)];

  
 if n_fs~=0 & n_bu~=0;
%  Perform stable forward and unstable backward eigenvalue matching
      k=[];junk=lamdaf(n_fu+1:n_f);  %Note that n_f=n_fu+n_fs;
      for i=n_b-n_bu+1:n_b;
        [error,j]=min(abs(junk-ones(n_fs,1)/lamdab(i)));
        k=[k;j+n_fu];
      end;
      km=min(k);i=n_fu+1:km-1;
      if isempty(i)==0;lamdaf(i)=[];msv_f(i)=[];bmf(i,:)=[];cmf(:,i)=[];end;
 else;
    if n_fu<n_f;  
      lamdaf(n_fu+1:n_f)=[];bmf(n_fu+1:n_f,:)=[];cmf(:,n_fu+1:n_f)=[];
      msv_f(n_fu+1:n_f)=[];
    end;
 end;
 if n_fu~=0 & n_bs~=0;
%  Perform unstable forward and stable backward eigenvalue matching
   k=[];junk=lamdab(1:n_bs);  %Note that n_b=n_bu+n_bs;
      for i=1:n_fu;
        [error,j]=min(abs(junk-ones(n_bs,1)/lamdaf(i)));
        k=[k;j];
      end;
    km=min(k);i=1:km-1;
    if isempty(i)==0;lamdab(i)=[];msv_b(i)=[];bmb(i,:)=[];cmb(:,i)=[];end;
 else;
      if n_bs>0;
        lamdab(1:n_bs)=[];bmb(1:n_bs,:)=[];cmb(:,1:n_bs)=[];
        msv_b(1:n_bs)=[];
      end;
 end;
%  if isempty(lamdaf)==1;
%   disp('Sorry, no common modes are found from both forward and backward');
%   disp('models.  Try to increase the number of observer parameters, i.e. p.');   
%   disp('If you did try many times, your system may have considerable');
%   disp('uncertainties that the backward approach cannot identify any system');
%   disp('modes.  In this case, please just use the forward model.');
%  end;
