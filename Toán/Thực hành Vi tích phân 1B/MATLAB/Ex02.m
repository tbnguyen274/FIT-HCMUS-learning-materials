clc
clear all

% Khởi tạo biến
syms x i

% Số lượng khoảng con
n = 100;

% Định nghĩa deltaX
deltaX = (3-1)/n;

% a. Định nghĩa xi là điểm biên trái
xi = 1 + (i-1)*deltaX;

% b. Định nghĩa xi là điểm biên phải
% xi = 1 + i*deltaX;

% c. Định nghĩa xi là trung điểm
% xi = 1 + (i-1/2)*deltaX;

% Định nghĩa hàm số f(x)
f = 3 * x^2 * log(x);

% Thay điểm biên xi vào f(x)
fi = subs(f, x, xi);

% Tính tổng Sn
symsum(fi * deltaX, i, 1, n)
