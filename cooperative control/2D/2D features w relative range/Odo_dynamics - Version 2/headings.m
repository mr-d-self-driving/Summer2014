function [hf] = headings(Xf,Xr)

global nf

hv = Xr(3); % Heading
Xr = repmat(Xr(1:2),1,nf);
Diff = Xf-Xr;
hf = atan2(Diff(2,:),Diff(1,:))-hv; % Subtract the vehicle's heading
hf = hf';

for i = 1 : nf
    
    hf(i) = hf(i).*((hf(i)<pi)&&(hf(i)>-pi)) + (-2*pi+hf(i)).*(hf(i)>pi) + (2*pi+hf(i)).*(hf(i)<-pi);

end

