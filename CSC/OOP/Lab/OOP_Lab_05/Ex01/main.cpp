#include <iostream>

using namespace std;

#define NOE 10

class A {
private:
	int info[NOE];
public:
	A();

	typedef int* indexOf;
	indexOf GetInfo(const int&);

	void Xuat(ostream&);
};

A::A() {
	for (int i = 0; i < NOE; ++i) {
		info[i] = i + NOE;
	}
}

A::indexOf A::GetInfo(const int& i) {
	indexOf rt = new int;
	rt = info + i;
	return rt;
}

void A::Xuat(ostream& os) {
	for (int i = 0; i < NOE; i++) {
		os << info[i] << ", ";
	}
	os << endl;
}

int main() {
	const int i = 7;
	A a;
	A::indexOf io = a.GetInfo(i);
	cout << *io << endl;
	*io = 10;
	a.Xuat(cout);

	system("pause");
	return 0;
}