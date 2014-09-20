% driver_test

%L0 = zeros(4,1);
%L0 = [-1.8362    -0.013242      -1.0542     -0.91184]';
count = 0;
while( costf(L0) > h^2 )
    count = count + 1;
    L0 = graddescent(L0,@costf);
    disp([count L0' costf(L0)]);
end

% generate time histories
x0 = [1;0;0;1];

X = zeros(4,N+1);
L = zeros(4,N+1);

X(:,1) = x0;
L(:,1) = L0;
t = 0:h:T;

for i = 1:N
    f = local_eqom([],[X(:,i);L(:,i)]);
    new = [X(:,i);L(:,i)] + h*f;
    X(:,i+1) = new(1:4);
    L(:,i+1) = new(5:8);
end

U = -0.5*L(3:4,:);

figure;
subplot(311);
plot(t,X);

subplot(312);
plot(t,L);

subplot(313);
plot(t,U);