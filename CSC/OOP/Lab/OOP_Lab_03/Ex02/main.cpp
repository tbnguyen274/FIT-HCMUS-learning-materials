#include <iostream>

using namespace std;

class SoPhuc {
private:
	int _thuc, _ao;

public:
	SoPhuc();
	SoPhuc(const int&);
	SoPhuc(const int&, const int&);
	SoPhuc operator+(const SoPhuc&);

	void operator<<(ostream&);
};

SoPhuc::SoPhuc() {
	_thuc = _ao = 0;
}

SoPhuc::SoPhuc(const int& t) : SoPhuc() {
	cout << "using... ";
	_thuc = t;
}

SoPhuc::SoPhuc(const int& t, const int& a) {
	_thuc = t;
	_ao = a;
}

SoPhuc SoPhuc::operator+(const SoPhuc& sp) {
	SoPhuc rt = *this;
	rt._thuc += sp._thuc;
	rt._ao += sp._ao;
	return rt;
}

void SoPhuc::operator<<(ostream& os) {
	os << _thuc;
	if (_ao != 0) {
		os << ((_ao > 0) ? " + " : " - ") << _ao << "*i";
	}
}

int main() {
	SoPhuc sp1(3, 5);
	SoPhuc sp3 = sp1 + 10;

	sp1.operator<<(cout);
	cout << endl;
	sp3.operator<<(cout);
	cout << endl;

	system("pause");
	return 0;
}