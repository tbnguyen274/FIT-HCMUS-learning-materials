clc
clear all

syms x y;
f = x*y - x^3/3;

% Tìm vector gradient của f
fx = diff(f, x);
fy = diff(f, y);

[X,Y] = meshgrid(-5:.5:5,-5:.5:5);
P = fx;
Q = fy;
quiver(X,Y,P,Q)