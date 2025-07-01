clc
clear all

% Khởi tạo biến
syms x

% Xác định bậc đạo hàm
n = 10;
% n = 100;

% Định nghĩa hàm số f(x)
f = cos(n*x);

% Xuất kết quả từ 1 đến n
for i=1:n
    diff(subs(f, n, i), i)
end

