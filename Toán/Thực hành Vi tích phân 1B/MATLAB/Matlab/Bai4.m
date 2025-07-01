clc
clear all

% a. y′ + y = 1, y(0) = 1.
syms y(x);
res = dsolve(diff(y,x) + y == 1, y(0) == 1)
% sử dụng lệnh plot để vẽ đồ thị của nghiệm:
X = linspace(-1, 1, 100);
Y = subs(res, x, X);
plot(X, Y)

% b.
syms y(x);
res = dsolve((x^2 + 1) * diff(y,x) + 3*x*(y-1) == 0, y(0) == 2)
% sử dụng lệnh plot để vẽ đồ thị của nghiệm:

% c.
syms y(x);
res = dsolve(diff(y,x,2) - 4*y == exp(x)*cos(x) + x^3, y(0) == 1, subs(diff(y,x),x,0) == 2)
% sử dụng lệnh plot để vẽ đồ thị của nghiệm: