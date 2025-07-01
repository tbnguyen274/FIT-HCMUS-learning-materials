clear all
clc

% 2
syms x y
f = atan(x^2*y^3-3*x/y);
subs(f,[x,y],[pi,1])

% 3
syms x y
z = log(x^2+y^3)
zx = diff(z,x)
zy = diff(z,y)
zxx = diff(z,x,2)
zyy = diff(z,y,2)
zxy = diff(z,x,y)
zyx = diff(z,y,x)


% 5
syms x y m n
z = exp(x*y)*sin(m*x+n*y)^2;
diff(z,y,x,x)

% 6
syms s t
x = s/t;
y= t/s;
z = exp(x+2*y);
diff(z,s)
diff(z,t)

% 7
syms x
f = sin(x)
int(f,x,0,3)

% 8
syms x y
f = sin(x*y);
int(int(f,y,[3 7]),x,[1 5])

% 9
% syms x y
% ymax = @(x)x.^2
% f = @(x,y)y./(x.^5+1)
% q = integral2(f,0,exp(1),0,ymax)

% 9
syms x y
a = int(int(y/(x^5+1),y,0,x^2),x,0,exp(1))
eval(a)

% 11
s = 0;
for n = 1:100
    for m = 1:50
        s = s + log(2*n-m);
    end
end
s

% 12
B = -10:0.5:10;
for i = 1 : length(B)
    if B(i) >= 0
        B(i) = 0;
    end
end

% 13
syms x y
f = log(x-3*y);
kq1 = subs(subs(diff(f,x),x,7),y,2); %fx(7,2)
kq2 = subs(subs(diff(f,y),x,7),y,2); %fy(7,2)

if ((kq1 == inf) | (kq1 == -inf)) | ((kq2 == inf) | (kq2 == -inf))
    disp('khong ton tai phep xap xi tuyen tinh')
else
    % L = f(7,2) + fx(7,2)(x-7) + fy(7,2)(y-2)
    L = subs(f,[x,y],[7,2]) + kq1*(x-7) + kq2*(y-2);
    subs(L,[x,y],[6.9,2.06])
end



% 14