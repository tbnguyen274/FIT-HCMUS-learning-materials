clc
clear all

a = -10 : 0.1 : 10;
b = -10 : 0.1 : 20;

[X,Y] = meshgrid(a,b);
f = 6 * exp(-3.*X.^2 - Y.^2) + X./2 + Y;
plot3(X, Y, f)