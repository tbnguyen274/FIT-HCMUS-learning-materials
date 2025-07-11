#include <iostream>

using namespace std;

class SoPhuc {
private:
	int _thuc, _ao;

public:
	SoPhuc();
	SoPhuc(const int&);
	SoPhuc(const int&, const int&);
	
	friend SoPhuc operator+(const int&, const SoPhuc&);
	friend ostream& operator<<(ostream&, const SoPhuc&);
};

SoPhuc operator+(const int& n, const SoPhuc& sp) {
	SoPhuc spR(n);
	spR._thuc += sp._thuc;
	spR._ao += sp._ao;
	return spR;
}

SoPhuc::SoPhuc() {
	_thuc = _ao = 0;
}

SoPhuc::SoPhuc(const int& t) : SoPhuc() {
	_thuc = t;
}

SoPhuc::SoPhuc(const int& t, const int& a) {
	_thuc = t;
	_ao = a;
}

ostream& operator<<(ostream& os, const SoPhuc& sp) {
	os << sp._thuc;
	if (sp._ao != 0) {
		os << ((sp._ao > 0) ? " + " : " - ") << sp._ao << "*i";
	}
	return os;
}

int main() {
	SoPhuc sp1(3, 5);
	SoPhuc sp2 = 10 + sp1;
	cout << sp1 << endl;
	cout << sp2 << endl;

	system("pause");
	return 0;
}