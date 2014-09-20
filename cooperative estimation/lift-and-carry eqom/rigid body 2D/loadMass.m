function [m0, mi, mj, I0, Ii, Ij, li, lj, raix, raiy, rajx, rajy] = loadMass()
    X = dlmread('properties.txt','\t',1,0);
    m0 = X(1);
    mi = X(2);
    mj = X(3);
    I0 = X(4);
    Ii = X(5);
    Ij = X(6);
    li = X(7);
    lj = X(8);
    raix = X(9);
    raiy = X(10);
    rajx = X(11);
    rajy = X(12);
end