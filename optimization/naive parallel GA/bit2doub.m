function U = bit2doub(Ubit,mN)

U = zeros(mN,size(Ubit,2));

for i = 1:mN
    for j = 1:size(Ubit,2)
        ix = (1:8) + (i-1)*8;
        U(i,j) = (bin2dec(num2str(Ubit(ix,j))'))*4/255-2;
    end
end

end