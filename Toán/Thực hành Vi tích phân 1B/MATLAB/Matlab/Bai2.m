clc
clear all

syms x y

% a
f = x * sin(x + y);
% R = [0,pi/6] x [0,pi/3]
int(int(f,y,0,pi/3),x,0,pi/6)

% b
f = x^2 + 2*y;
% D là miền được bao bởi các đường y = x, y = x^3 và x >=0
int(int(f,y,x^3,x),x,0,1)

% c
syms t
f = exp(x);
y = t;
x = t^2;
% t thuộc [1,2]
% C là đường cong y = sqrt(x) từ điểm (1,1) đến (4,2)
int(f * diff(x, t), t, 1, 2)

% d

x = t;
y = t^2 + 1;
u = x / sqrt(x^2 + y^2);
v = y / sqrt(x^2 + y^2);
int((u*diff(x, t) + v*diff(y, t)),t,-1,1)