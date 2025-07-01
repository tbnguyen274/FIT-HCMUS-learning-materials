clc
clear all

syms x y z
a = 2;
b = 7;
c = 4;

f = (a*x + b*y + c*z) * asin(x*y*z);
% Tìm tất cả đạo hàm riêng cấp 1 và 2 của f 

fx = diff(f, x)
fy = diff(f, y)
fxx = diff(f, x, 2)
fyy = diff(f, y, 2)
fxy = diff(f, x, y)
fyx = diff(f, y, x)