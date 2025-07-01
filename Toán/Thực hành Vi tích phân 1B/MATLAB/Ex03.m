clc
clear all

% Khoang gia tri cua x
x = -2*pi:0.01:2*pi;

% Định nghĩa hàm số f(x) và g(x)
f = cos(x.^2);
g = sin(x.^2);

% Vẽ trên cùng một khung hình
hold on
plot(x, f)
plot(x, g)