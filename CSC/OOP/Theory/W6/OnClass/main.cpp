#include <iostream>

using namespace std;

class A {
public:
	A() {};
	A(int x) {};
};

class B : public A{
public:
	B() {};
	B(int x, int y) : A(x) {};
};

class C : public B {
public:
	C() {};
	C(int x) {};
	C(int x, int y, int z) : B(x, y) {};
};

class D {
public:
	//D(int i) {};
};

class E : public D {
public:
	E() : D() {};
};

int main() {
	E e;

	return 0;
}