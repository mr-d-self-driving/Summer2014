function [a,b,c,svm,index] = svpm(lambda,bm,cm,flag)
% 
%	   Computes the modal observability matrix and the singular values of the
%      modal participation to the pulse response samples.  Sort the singular
%      values and trucncate the small ones which represent the uncontrollable
%      or unobservable parts
%                                                              
%     [a,b,c,svm,index] = svpm(lambda,bm,cm,flag)
%                                                              
%INPUT PARAMETERS
% lambda: n x 1 vector containing system eigenvalues                                 
%    bm : n x r modal input matrix             
%    cm : m x n modal output matrix                               
%  flag : 1 User's interaction required to determine modal truncation                             
%                                            
%                                                              
% OUTPUT PARAMETERS
% 
%   a   : n_t x1 vector containing sorted and truncated eigenvalues                                
%   b   : n_t x r sorted and truncated modal input matrix                                
%   c   : m x n_t sorted and truncated modal output matrix                               
% svm   : n_t x 1 vector containing the normalized modal singular values                                
% index : sorting index                          

%         J. N. Juang 11-29-91, modified 1/6/95
%         NASA Spacecraft Dynamics Branch                           
%                                                                   

%
%  Compute the sigular values of the modal participation to the
%  pulse response samples
%    
   [m,n]=size(cm);[n,r]=size(bm);
   svm=zeros(n,1);
    for j=1:n;
      svm(j)=sqrt(norm(bm(j,:))*norm(cm(:,j))/abs(1-abs(lambda(j))));
    end;
   svm=svm ./max(svm);
%
%  Sort the modal sigular values 
%  

    [svm1,index]=sort(svm);
%
%  Determine the number of modal trucncation
%  
 eps1=10e-4;
 n_order=n;
 if flag==1; 
         semilogy(flipud(svm1),'*');
         xlabel(' Number');ylabel('Magnitude');
         title(' Modal Singular Values (MSV)');pause;
     n_order=input('Number of Modes Wanted (See MSV plot) =: ');
        if isempty(n_order)==1 | n_order<=0 | n_order>n; n_order=n;end;
     eps1=svm1(n-n_order+1)-eps1;
  end;
        i=0;
        while svm1(i+1)<eps1;
           i=i+1;
        end;
       if flag==0;
	     if i~=0;
           disp(['Truncate modes with small modal singular values < 10e-4'])
           disp(['The number of modes was set to ' num2str(n) '.'])
           disp(['It is now set to ' num2str(n-i) '.']) 
		 end;
	   else;
         if n_order~=n-i;
           disp(['The number of modes was set to ' num2str(n_order) '.'])
           disp(['It is now set to ' num2str(n-i) ' in order to pair complex modes.']) 
		 end;
       end;
	   n_order=n-i;
%
%  Obtain the sorted and truncated system matrices
%  
    n1=n-n_order+1;
	index=index(n1:n);
    a=lambda(index);
    b=bm(index,:);c=cm(:,index);
	svm=svm(index);

