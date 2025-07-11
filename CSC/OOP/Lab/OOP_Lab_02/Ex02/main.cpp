#include <iostream>

using namespace std;

class Ngay {
private:
	int _ng, _th, _n;
	static int arrNgayCuaThang[][13];
	static bool LaNamNhuan(const int& n);

public:
	Ngay();
	Ngay(const int& n);
	~Ngay();
	void Xuat(ostream& os);
};

Ngay::Ngay() {
	_ng = _th = _n = 1;
}

Ngay::Ngay(const int& n) {
	_ng = (n >= 0) ? n : -n;
	_th = _n = 1;
	
	if (_ng == 0) {
		_ng = 1;
		return;
	}

	int idxN = LaNamNhuan(_n);
	while (_ng > arrNgayCuaThang[idxN][_th]) {
		_ng -= arrNgayCuaThang[idxN][_th];
		_th++;

		if (_th > 12) {
			_th = 1;
			_n++;
			idxN = LaNamNhuan(_n);
		}
	}
}

Ngay::~Ngay() {

}

bool Ngay::LaNamNhuan(const int& n) {
	return (n % 400 == 0) || (n % 4 == 0 && n % 100 != 0);
}

void Ngay::Xuat(ostream& os) {
	os << _ng << "-" << _th << "-" << _n;
}

int Ngay::arrNgayCuaThang[][13] = { {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
									{-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} };

int main() {
	Ngay n1;
	Ngay n2(1000);
	Ngay n3(2000);
	Ngay n4(3000);
	Ngay n5(4000);

	n1.Xuat(cout);
	cout << endl;
	n2.Xuat(cout);
	cout << endl;
	n3.Xuat(cout);
	cout << endl;
	n4.Xuat(cout);
	cout << endl;
	n5.Xuat(cout);
	cout << endl;

	system("pause");
}