clc
clear all

syms x y
f = x^3 - 12*x*y + 8*y^3;
fx = diff(f, x);
fy = diff(f, y);
[xc, yc] = solve(fx, fy, x, y);
[xc, yc];
fxx = diff(fx, x); fxy = diff(fx, y); fyy = diff(fy, y);
D = fxx * fyy - fxy^2;
subs(D, {x, y}, {xc(1), yc(1)})
subs(fxx, {x, y}, {xc(1), yc(1)})

% tìm cực đại địa phương, cực tiểu địa phương, điểm yên ngựa
% D > 0, fxx > 0 => cực tiểu địa phương
% D > 0, fxx < 0 => cực đại địa phương
% D < 0 => điểm yên ngựa
% D = 0 => không xác định