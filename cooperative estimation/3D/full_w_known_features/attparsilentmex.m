function [Y] = attparsilentmex(X,I,options)
%Tim Woodbury
%modified for AERO 622
%
%[Y] = attpar(X,I,options)
%Function to convert between attitude parametrizations
%
%INPUTS:
%X - matrix input of appropriate dimension (detailed later)
%I - 2 x 1 indexing vector indicating the input (I(1)) and output (I(2))
%    attitude parametrizations, corresponding to the numbers in the section,
%    "I/O SPECIFICATION PARAMETERS".
%options - a data structure. Currently only allows output Euler angle
%    sequence to be defined. Supported members are "seq" which should be a
%    [3 x 1] vector describing the first, second, and third rotations in
%    the desired output sequence.
%
%OUTPUTS:
%Y - output matrix of appropriate dimensions.
%    All angles are in radians.
%
%I/O SPECIFICATION PARAMETERS:
%1 - Direction cosine matrix, dimensions [3 x 3]
%2 - Euler principal axis/angle, [3 x 2]. [:,1] is the principal axis;
%    [1,2] is the principal angle (rad).
%3 - 2-angle parametrization, [3 x 4]
%4 - Euler angle sequence, [3 x 2]. [:,1] are the rotation angles in radians, 
%     and [2,1]-[2,2]-[2,3] is the rotation sequence. 
%     [3-1-3] sequence is default for output. Other sequences may be specified
%     by passing an optional data structure with a [3 x 1] member "seq" whose
%     entries [a;b;c] correspond to the sequence a-b-c. Any input sequence
%     may be used by specifying the second column of input appropriately.
%5 - Classical Rodrigues parameters [3 x 1]
%6 - quaternion [4 x 1]. The scalar part of the quaternion comes FIRST.
%7 - modified Rodrigues parameters [3 x 1]
%8 - exponential matrix, [3 x 3]
%9 - Cayley-Klein parameters, [2 x 2]

%check if any options are passed
if nargin >=3
    EULOUTSEQ = options.seq;
    if isempty(EULOUTSEQ)
        EULOUTSEQ = [3;1;3];
    end
end

if mod(I(1),floor(I(1)))
    error('Specified input parametrization must be of integer type.');
end
if mod(I(2),floor(I(2)))
    error('Specified input parametrization must be of integer type.');
end

inp = I(1);
outp = I(2);

%%check if output and inp are the same - if so do nothing
if I(1) == I(2)
    %disp('Warning - input and output parametrizations are the same.');
    Y = X;
else
    %for each inp, convert to DCM
    switch inp
        case 1 %DCM
            %disp('Input value specified as direction cosine matrix.');
            if size(X)~=[3,3]
                error('Input dimensions invalid for DCM.');
            end
            DCM = X;
            %check orthogonality of DCM using Frobenius norm:
            Cinv = inv(DCM);
            Ctrans = DCM';
            err = norm(Cinv-Ctrans,'fro');
            if err>=1e-4
                %disp('Matrix input is not orthonormal to 4 decimal places, measured by the Frobenius norm.');
                %disp(['Error is ' num2str(err) '.']);
                disp('Terminating after nonorthogonal matrix specification.');
            elseif err>1e-15
                %disp('Warning: cosine matrix input is not orthogonal to machine precision.');
                %disp(['Frobenius norm satisfies orthogonality to ' num2str(-floor(log10(err))) ' decimal places.']);
                %disp('Calclation proceeding:');
            end
        case 2 %principal axis/angle
            %disp('Input value specified as Euler principal axis/angle.');
            if size(X)~=[3,2]
                error('Input dimensions invalid for principal axis/angle.');
            end
            PHI_in = X(1,2);
            e_in = X(:,1);
            DCM = eye(3)*cos(PHI_in)+(1-cos(PHI_in))*(e_in*e_in')-squiggle(e_in)*sin(PHI_in);
        case 3 %2-angle parametrization
            %X: [3 x 4]
            %extract e_a, PHI_a, e_b, PHI_b from X:
            %disp('Input value specified as two-angle parametrization.');
            if size(X)~=[3,4]
                error('Input dimensions invalid for two-angle parametrization.');
            end
            e_a = X(:,1);
            e_b = X(:,3);
            PHI_a = X(1,2);
            PHI_b = X(1,4);
            %compute cosine matrices C_a and C_b
            C_a = eye(3)*cos(PHI_a)+(1-cos(PHI_a))*(e_a*e_a')-squiggle(e_a)*sin(PHI_a);
            C_b = eye(3)*cos(PHI_b)+(1-cos(PHI_b))*(e_b*e_b')-squiggle(e_b)*sin(PHI_b);
            DCM = C_b*C_a;
        case 4 %Euler angles
            %disp(['Input value specified as Euler angle sequence ' num2str(X(1,2)) '-' num2str(X(2,2)) '-' num2str(X(3,2)) '.']);
            if (size(X)~=[3,2])
                if size(X)==[3,1]
                    error('Rotation sequence not specified.');
                else
                    error('Input dimensions invalid for Euler angle sequence.');
                end
            end
            %extract rotation sequence
            r1 = X(1,2);
            r2 = X(2,2);
            r3 = X(3,2);
            if (r2==r1)||(r2==r3)
                error('Specified second rotation axis must be different from 1st and 3rd rotation axis.')
            end
            %extract rotation angles
            phi1 = X(1,1);
            phi2 = X(2,1);
            phi3 = X(3,1);
            %for symmetric, second angle should be POSITIVE. If not, may cause
            %problems. Autoconvert but display warning.
            if phi2<0
                phi2 = mod(phi2,pi*2);
                %disp('Warning - second Euler angle specified is less than 0 radians, may cause problems!');
                %disp('Attempting to resolve by converting to positive angle via modulus operation.');
            end
            %determine rotation matrices
            R1 = DCMConverter(r1,phi1);
            R2 = DCMConverter(r2,phi2);
            R3 = DCMConverter(r3,phi3);
            DCM = R3*R2*R1;
        case 5 %Rodrigues parameters
            %disp('Input value specified as classic Rodrigues parameters.');
            if size(X)~=[3,1]
                error('Input dimensions invalid for Rodrigues parameters.');
            end
            rho = X;
           %DCM = 1/(1+rho'*rho)*((1-rho'*rho)*eye(3)+2*(rho*rho')-2*squiggle(rho));
           DCM = eye(3)+2./(1+rho'*rho)*(-squiggle(rho)+squiggle(rho)*squiggle(rho));
        case 6 %quaternion
            %disp('Input value specified as quaternion.');
            if length(X)~=4
                error('Input dimensions invalid for quaternion.');
            end
            q1 = X(2);
            q2 = X(3);
            q3 = X(4);
            q4 = X(1);
            DCM = [q1^2-q2^2-q3^2+q4^2 2*(q1*q2+q3*q4) 2*(q1*q3-q2*q4);
                2*(q1*q2-q3*q4) q2^2-q1^2-q3^2+q4^2 2*(q2*q3+q1*q4);
                2*(q1*q3+q2*q4) 2*(q2*q3-q1*q4) q3^2-q1^2-q2^2+q4^2];
        case 7 %modified Rodrigues parameters
            %disp('Input value specified as modified Rodrigues parameters.');
            if size(X)~=[3,1]
                error('Input dimensions invalid for modified Rodrigues parameters.');
            end
            sigma = X;
            %DCM = eye(3)+(8*squiggle(sigma)*squiggle(sigma)-4*(1-(sigma'*sigma))*squiggle(sigma))./((1+(sigma'*sigma))^2);
            DCM = eye(3)-4*(1-sigma'*sigma)/(1+sigma'*sigma)^2*squiggle(sigma)+8/(1+sigma'*sigma)^2*squiggle(sigma)*squiggle(sigma);
        otherwise
            error('Invalid parametrization specified.');
    end
    %convert DCM to output form
    switch outp
        case 1%DCM
            %disp('Output value specified as direction cosine matrix.');
            Y = DCM;
        case 2%principal axis/angle
            %disp('Output value specified as Euler principal axis/angle.');
            ksi = trace(DCM);
            PHI = acos((ksi-1)/2);
            e = zeros(3,1);
            if ((round(ksi*1e4)/1e4)==-1)
                e(1) = sqrt((1+DCM(1,1))*.5);
                e(2) = sqrt((1+DCM(2,2))*.5);
                e(3) = sqrt((1+DCM(3,3))*.5);
                %create a vertical array of the sign of the products [c3c1;c2c3;c1c2]; 
                signs = [sign(DCM(3,1)); sign(DCM(2,3)); sign(DCM(1,2))];
                %set the negative values to zero for a binary representation
                signs(find(signs==-1))=0;
                % compute binary from signs
                signs = signs(3)*4 + signs(2)*2 + signs(1)*1;
                %depending on the result, change signs.
                switch signs
                    case 1
                        e(3) = -e(3);
                    case 2
                        e(2) = -e(2);
                        e(3) = -e(3);
                    case 4
                        e(2) = -e(2);
                    otherwise
                        %do nothing
                end
            else
                e(1) = (DCM(2,3)-DCM(3,2));
                e(2) = (DCM(3,1)-DCM(1,3));
                e(3) = (DCM(1,2)-DCM(2,1));
                e=e./sqrt((1+ksi)*(3-ksi));
            end
            %e(1) = (DCM(2,3)-DCM(3,2))/(2*sin(PHI));
            %e(2) = (DCM(3,1)-DCM(1,3))/(2*sin(PHI));
            %e(3) = (DCM(1,2)-DCM(2,1))/(2*sin(PHI));
            
            Y = zeros(3,2);
            Y(:,1) = e;
            Y(1,2) = PHI;
        case 3%2-angle parametrization
            %disp('Output value specified as two-angle parametrization.');
            C_a = [cos(pi/4) sin(pi/4) 0;
                -sin(pi/4) cos(pi/4) 0;
                0 0 1];
            C_b = DCM*C_a';
            %decompose C_a into e_a, PHI_a
            PHI_a = acos((trace(C_a)-1)/2);
            e_a = zeros(3,1);
            e_a(1) = (C_a(2,3)-C_a(3,2))/(2*sin(PHI_a));
            e_a(2) = (C_a(3,1)-C_a(1,3))/(2*sin(PHI_a));
            e_a(3) = (C_a(1,2)-C_a(2,1))/(2*sin(PHI_a));
            %decompose C_b into e_b, PHI_b
            PHI_b = acos((trace(C_b)-1)/2);
            e_b = zeros(3,1);
            e_b(1) = (C_b(2,3)-C_b(3,2))/(2*sin(PHI_b));
            e_b(2) = (C_b(3,1)-C_b(1,3))/(2*sin(PHI_b));
            e_b(3) = (C_b(1,2)-C_b(2,1))/(2*sin(PHI_b));
            %assign output
            Y = zeros(3,4);
            Y(:,1) = e_a;
            Y(1,2) = PHI_a;
            Y(:,3) = e_b;
            Y(1,4) = PHI_b;
        case 4%Euler angles
            %use a 3-1-3 rotation sequence as a default;
            %if ~exist('EULOUTSEQ','var')
            %    EULOUTSEQ = [3;1;3];
            %end
            %disp(['Output value specified as Euler angle sequence ' num2str(EULOUTSEQ(1)) '-' num2str(EULOUTSEQ(2)) '-' num2str(EULOUTSEQ(3)) '.']);
            [eul, seq] = DCM2eul(DCM,EULOUTSEQ);
            %verify sequence by computing error norm of reconstruction
            froErr = norm(DCMConverter(seq(3),eul(3))*DCMConverter(seq(2),eul(2))*DCMConverter(seq(1),eul(1))-DCM,'fro');
            if froErr>1e-6
                %disp(['Warning: Frobenius norm of error in DCM reconstruction from Euler angles is ' num2str(froErr) '.']);
            end
            Y = [eul seq];
        case 5%Rogrigues parameters
            %disp('Output value specified as classic Rodrigues parameters.');
            ksi = trace(DCM);
            rho = zeros(3,1);
            rho(1)=DCM(2,3)-DCM(3,2);
            rho(2)=DCM(3,1)-DCM(1,3);
            rho(3)=DCM(1,2)-DCM(2,1);
            rho = rho./(1+ksi);
            Y = rho;
        case 6%quaternion
            %disp('Output value specified as quaternion.');
            q1 = 1/2*sqrt(1+DCM(1,1)-DCM(2,2)-DCM(3,3));
            q2 = 1/2*sqrt(1-DCM(1,1)+DCM(2,2)-DCM(3,3));
            q3 = 1/2*sqrt(1-DCM(1,1)-DCM(2,2)+DCM(3,3));
            q4 = 1/2*sqrt(1+DCM(1,1)+DCM(2,2)+DCM(3,3));%scalar part
            %determine the maximum of the four and use this value to determine the
            %other parameters
            [~,iMax] = max([q1;q2;q3;q4]);
            switch iMax
                case 1
                    qV = 1/(4*q1)*[DCM(1,2)+DCM(2,1);DCM(1,3)+DCM(3,1);DCM(2,3)-DCM(3,2)];
                    q = [q1;qV];
                case 2
                    qV = .25/q2*[DCM(2,1)+DCM(1,2);DCM(2,3)+DCM(3,2);DCM(3,1)-DCM(1,3)];
                    q = [qV(1);q2;qV(2:3)];
                case 3
                    qV = .25/q3*[DCM(3,1)+DCM(1,3);DCM(3,2)+DCM(2,3);DCM(1,2)-DCM(2,1)];
                    q = [qV(1:2);q3;qV(3)];
                case 4
                    qV = .25/q4*[DCM(2,3)-DCM(3,2);DCM(3,1)-DCM(1,3);DCM(1,2)-DCM(2,1)];
                    q = [qV;q4];
            end
            %output in the format [qScalar;qVector]
            Y = [q(4);q(1);q(2);q(3)];
        case 7 %modified Rodrigues parameters
            %disp('Output value specified as modified Rodrigues parameters.');
            ksi = trace(DCM);
            s = zeros(3,1);
            %if trace(C) is within 1e-4 of -1, then assume ksi = -1:
            if (round(ksi*1e4)/1e4)==-1
                s(1) = sqrt((1+DCM(1,1))*.5);
                s(2) = sqrt((1+DCM(2,2))*.5);
                s(3) = sqrt((1+DCM(3,3))*.5);
                %create a vertical array of the sign of the products [c3c1;c2c3;c1c2]; 
                signs = [sign(DCM(3,1)); sign(DCM(2,3)); sign(DCM(1,2))];
                %set the negative values to zero for a binary representation
                signs(find(signs==-1))=0;
                % compute binary from signs
                signs = signs(3)*4 + signs(2)*2 + signs(1)*1;
                %depending on the result, change signs.
                switch signs
                    case 1
                        s(3) = -s(3);
                    case 2
                        s(2) = -s(2);
                        s(3) = -s(3);
                    case 4
                        s(2) = -s(2);
                    otherwise
                        %do nothing
                end
            %else, perform the usual computation:
            else
                k = 1/((sqrt(ksi+1)+2)*(sqrt(ksi+1)));
                s(2) = k*(DCM(3,1)-DCM(1,3));
                s(3) = k*(DCM(1,2)-DCM(2,1));
                s(1) = k*(DCM(2,3)-DCM(3,2));
            end
            %determine principal axis
%             PHI = acos((trace(DCM)-1)/2);
%             e = zeros(3,1);
%             e(1) = (DCM(2,3)-DCM(3,2))/(2*sin(PHI));
%             e(2) = (DCM(3,1)-DCM(1,3))/(2*sin(PHI));
%             e(3) = (DCM(1,2)-DCM(2,1))/(2*sin(PHI));
%             sigma = e*tan(PHI/4);
            Y = s;
        otherwise
            error('Specified output parametrization not available.');
    end
end
end