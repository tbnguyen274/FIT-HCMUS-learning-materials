% 2
% a = -3:0.1:3;
% b = -2:0.1:2;
% [X,Y] = meshgrid(a,b);
% Z = exp(Y.^2 - X.^2)
% plot3(X,Y,Z)

% 3
% ezplot3('3*t*sin(t)', '1.5*t*cos(t)','t',[0,8*pi])

% 4
% a = -3:0.2:3;
% b = -2:0.2:2;
% [X,Y] = meshgrid(a,b);
% Z = exp(Y.^2 - X.^2);
% mesh(X,Y,Z)
% ezmesh('exp(Y.^2-X.^2)',[-3,3,-2,2])

% 5

% 6
% vd4
% [x,y] = meshgrid(-5:.5:5,-5:.5:5)
% P = -y;
% Q = x;
% quiver(x,y,P,Q)

%vd 5
% [x,y] = meshgrid(-5:.5:5,-5:.5:5)
% P = 2*x-3*y;
% Q = -3*x+4*y-8;
% quiver(x,y,P,Q)

%vd6
% [x,y,z] = meshgrid(-5:.5:5,-5:.5:5,-5:.5:5)
% P = sin(x);
% Q = cos(x);
% R = x.*z;
% quiver3(x,y,z,P,Q,R)

% 7
dsolve('Dy = 1 + y^2','y(0)=1')
dsolve('D2y+y = exp(x)+x^3','y(0)=2','Dy(0)=0','x') %chu y bien x cuoi
% or
syms y(x)
dsolve(diff(y,x,2) + y == exp(x)+x^3,y(0)==2,subs(diff(y,x),x,0)==0)

%VD*
syms x y
f = x^3-3*x+3*x*y^2;
fx = diff(f,x)
fy = diff(f,y)
[xc,yc]=solve(fx,fy,x,y);
[xc,yc];
fxx = diff(fx,x); fxy = diff(fx,y); fyy = diff(fy,y);
D = fxx * fyy - fxy^2;
subs(D,{x,y},{xc(1),yc(1)})
subs(fxx,{x,y},{xc(1),yc(1)})
