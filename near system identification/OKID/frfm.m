function[Gz_id]=frfm(A,B,C,D,Gz,f,dt,np,flag)
%       [Gz_id]=frfm(A,B,C,D,Gz,f,dt,np,flag);
% Frequency Respons Function G(w) of a linear system
% given the state-space parameters A,B,C,D.
% Input
% Modified to plot loglog with no DC component
%     A,B,C,D: state-space parameters
%          Gz: frequency response (complex-valued) 
%              if G(z)=C(zI-A)^(-1)B+D=[G1,...,Gr]
%              then Gz=[G1.',...,Gr.']
%          f : frequency vector
%          dt: sample time
%          np: number of data points to be reconstructed
%        flag: flag=1 interactive plotting
% Output
%       Gz_id: identified FRF (complex numbers)
%              G(w)=[G1,...,Gr]; Gz_id=[G1',...,Gr'];  
%--------------------------------------------------

%         Cung-Wen Chen and Jer-Nan Juang  5-14-92 
%         MOD. L.G. Horta 6-11-93
%         NASA Spacecraft Dynamics Branch      

timer1 = clock;
 [s3,s4]=size(Gz);
 [s3,sb]=size(B);[sc,s3]=size(C);Gz_id=[];
     for i=1:sb
       G=freqresp(A,B,C,D,i,exp(sqrt(-1)*f*2*pi*dt));
       Gz_id=[Gz_id G];
     end
timer2=etime(clock,timer1)/60;
disp([' Time (min) to reconstruct FRF ' num2str(timer2)]);
if flag==1;
   hold off;

   Gang=angle(Gz)/pi*180;
   Gang_id=angle(Gz_id)/pi*180;
   n=0;
   for kb=1:sb
      for kc=1:sc;
        n=n+1;
        clg;subplot(211);
        semilogy(f(2:np),abs(Gz(2:np,n)),f(2:np),abs(Gz_id(2:np,n)),'--');
         title(['FRF magnitude plot for input No. ' num2str(kb) ...
                 ' and output No. ' num2str(kc)]);
         xlabel('Freq. (Hz)')
         ylabel('Magnitude')
        subplot(212),plot(f(2:np),Gang(2:np,n),f(2:np),Gang_id(2:np,n),'--');
         title(['FRF phase plot for input No. ' num2str(kb) ...
                 ' and output No. ' num2str(kc)]);
          xlabel('Freq. (Hz)')
          ylabel('Phase (deg.)')
          pause;
       end;
    end;
end;
