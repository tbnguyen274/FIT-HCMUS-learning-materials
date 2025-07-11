clc
clear all

syms x y

% Số lượng điểm mẫu
m = 200;
n = 200;

delta_x = (20 - 0) / m;
delta_y = (10 - 0) / n;
delta_A = delta_x * delta_y;

f = x * exp(-x*y);

% Tính tổng Riemann bội 2 với điểm mẫu là trung điểm
s = 0;
for i = 1:m
    for j = 1:n
        x_i = 0 + (i - 0.5) * delta_x;
        y_j = 0 + (j - 0.5) * delta_y;
        s = s + subs(f, [x, y], [x_i, y_j]);
    end
end
disp('s = %f', s * delta_A);