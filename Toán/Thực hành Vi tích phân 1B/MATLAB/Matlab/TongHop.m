% Bai 1
clc
clear all

syms x y z a b c
% a = 2;
% b = 7;
% c = 4;

f = (a*x + b*y + c*z) * asin(x*y*z);

% Tìm tất cả đạo hàm riêng cấp 1 và 2 của f 
fx = diff(f, x)
fy = diff(f, y)
fz = diff(f, z)

fxx = diff(f, x, 2)
fxy = diff(f, x, y)
fxz = diff(f, x, z)

fyy = diff(f, y, 2)
fyx = diff(f, y, x)
fyz = diff(f, y, z)

fzz = diff(f, z, 2)
fzx = diff(f, z, x)
fzy = diff(f, z, y)

% Bai 2
clc
clear all

syms x y

% a
f = x * sin(x + y);
% R = [0,pi/6] x [0,pi/3
disp('a)');
int(int(f, y, 0, pi/3), x, 0, pi/6)

% b
f = x^2 + 2*y;
% D là miền được bao bởi các đường y = x, y = x^3 và x >=0
disp('b)');
int(int(f, y, x^3, x), x, 0, 1)

% c
syms t x(t) y(t)

x(t) = t^2;
y(t) = t;
k = exp(x);

disp('c)');
int(k * diff(x, t), t, 1, 2)

% d
syms t x(t) y(t)

x(t) = t;
y(t) = t^2 + 1;
% t thuộc [-1,1]

u = x / sqrt(x^2 + y^2);
v = y / sqrt(x^2 + y^2);

disp('d)');
int((u * diff(x, t) + v * diff(y, t)), t, -1, 1)

% Bai 3
clc
clear all

syms x y

% Số lượng điểm mẫu
m = 250;
n = 250;

delta_x = (20 - 0) / m;
delta_y = (10 - 0) / n;
delta_A = delta_x * delta_y;

% Tính tổng Riemann bội 2 với điểm mẫu là trung điểm
s = 0;
for i = 1:m
    x_i = 0 + (i - 0.5) * delta_x;
    for j = 1:n
        y_j = 0 + (j - 0.5) * delta_y;
        s = s + (x_i * exp(-x_i * y_j));
    end
end
s = s * delta_A;
fprintf('Giá trị tổng Riemann bội 2: %f\n', s);

% f = x * exp(-x*y);
% double(int(int(f, x, 0, 20), y, 0, 10))

% Bai 4
clc
clear all

% a. y′ + y = 1, y(0) = 1.
syms y(x);
res = dsolve(diff(y,x) + y == 1, y(0) == 1)
% sử dụng lệnh plot để vẽ đồ thị của nghiệm:
X = linspace(-10, 10, 100);
Y = double(subs(res, x, X));
plot(X, Y)

% b.
syms y(x);
res = dsolve((x^2 + 1) * diff(y,x) + 3*x*(y-1) == 0, y(0) == 2)
% sử dụng lệnh plot để vẽ đồ thị của nghiệm:
X = linspace(-10, 10, 100);
Y = double(subs(res, x, X));
plot(X, Y)

% c.
syms y(x);
res = dsolve(diff(y,x,2) - 4*y == exp(x)*cos(x) + x^3, y(0) == 1, subs(diff(y,x),x,0) == 2)
% sử dụng lệnh plot để vẽ đồ thị của nghiệm:
X = linspace(-10, 10, 100);
Y = double(subs(res, x, X));
plot(X, Y)

% Bai 5
clc
clear all

a = -10 : 0.1 : 10;
b = -10 : 0.1 : 20;

[X,Y] = meshgrid(a,b);
f = 6 * exp(-3.*X.^2 - Y.^2) + X./2 + Y;
plot3(X, Y, f)

% Bai 6
clc
clear all

syms x y;
f = x*y - x^3/3;

% Tìm vector gradient của f
fx = diff(f, x)
fy = diff(f, y)

[X,Y] = meshgrid(-5:.5:5, -5:.5:5);
P = subs(fx, {x, y}, {X, Y});
Q = subs(fy, {x, y}, {X, Y});

quiver(X,Y,P,Q)

% Bai 7
clc
clear all

syms x y
f = x^3 - 12*x*y + 8*y^3;

fx = diff(f, x);
fy = diff(f, y);

[xc, yc] = solve(fx, fy, x, y);
[xc, yc]

fxx = diff(fx, x); fxy = diff(fx, y); fyy = diff(fy, y);
D = fxx * fyy - fxy^2;

% tìm cực đại địa phương, cực tiểu địa phương, điểm yên ngựa
% D > 0, fxx > 0 => cực tiểu địa phương
% D > 0, fxx < 0 => cực đại địa phương
% D < 0 => điểm yên ngựa
% D = 0 => không xác định

for i = 1:length(xc)
    if isreal(xc(i)) && isreal(yc(i))
        D_val = subs(D, {x, y}, {xc(i), yc(i)});
        fxx_val = subs(fxx, {x, y}, {xc(i), yc(i)});

        fprintf('Điểm dừng (x = %f, y = %f):\n', xc(i), yc(i));
        fprintf('D = %f, fxx = %f\n', D_val, fxx_val);

        if D_val > 0
            if fxx_val > 0
                disp('Cực tiểu địa phương');
            elseif fxx_val < 0
                disp('Cực đại địa phương');
            end
        elseif D_val < 0
            disp('Điểm yên ngựa');
        else
            disp('Không có kết luận tổng quát');
        end
    end
end