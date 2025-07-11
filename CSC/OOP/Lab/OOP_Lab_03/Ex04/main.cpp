#include <iostream>

using namespace std;

class Ngay {
private:
	int _ng, _th, _n;
	static int arrNgayCuaThang[][13];
	static bool LaNamNhuan(const int&);

public:
	Ngay();
	Ngay(const int&, const int&, const int&);
	Ngay(const int&);
	~Ngay();

	Ngay operator+(const Ngay&);
	Ngay operator+(const int&);
	friend Ngay operator+(const int&, const Ngay&);
	Ngay operator-(const Ngay&);
	Ngay operator-(const int&);
	friend Ngay operator-(const int&, const Ngay&);
	bool operator>(const Ngay&);
	friend ostream& operator<<(ostream&, const Ngay&);

	int changeFromDateToNumber();
};

int Ngay::changeFromDateToNumber() {
	int res = 0;
	for (int i = 1; i < _n; i++) {
		int idxN = LaNamNhuan(i);
		res += (idxN == 0) ? 365 : 366;
	}

	int idxN = LaNamNhuan(_n);
	for (int i = 1; i < _th; i++) {
		res += arrNgayCuaThang[idxN][i];
	}

	res += _ng;
	return res;
}


bool Ngay::LaNamNhuan(const int& n) {
	return (n % 400 == 0) || (n % 4 == 0 && n % 100 != 0);
}

Ngay::Ngay() {
	_ng = _th = _n = 1;
}

Ngay::Ngay(const int& ng, const int& th, const int& n) {
	_ng = (ng >= 0) ? ng : -ng;
	_th = (th >= 0) ? th : -th;
	_n = (n >= 0) ? n : -n;

	if (_th > 12) {
		_th -= 12;
		_n++;
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

Ngay::Ngay(const int& n) : Ngay() {
	_ng = (n >= 0) ? n : -n;

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

Ngay Ngay::operator+(const Ngay& ngay) {
	Ngay res;
	res._ng = this->_ng + ngay._ng;
	res._th = this->_th + ngay._th;
	res._n = this->_n + ngay._n;

	res._th = (res._th > 12) ? res._th - 12 : res._th;
	res._ng = (res._ng > 31) ? res._ng - 31 : res._ng;

	return res;
}

Ngay Ngay::operator+(const int& n) {
	return *this + Ngay(n);
}

Ngay operator+(const int& n, const Ngay& ngay) {
	return Ngay(n) + ngay;
}

Ngay Ngay::operator-(const Ngay& ngay) {
	Ngay res;
	res._ng = this->_ng - ngay._ng;
	res._th = this->_th - ngay._th;
	res._n = this->_n - ngay._n;

	if (res._th < 1) {
		res._th += 12;
		res._n--;
	}

	if (res._ng < 1) {
		res._ng = 1;
	}

	return res;
}

Ngay Ngay::operator-(const int& n) {
	return *this - Ngay(n);
}

Ngay operator-(const int& n, const Ngay& ngay) {
	return Ngay(n) - ngay;
}

bool Ngay::operator>(const Ngay& ngay) {
	if (_n > ngay._n) {
		return true;
	}
	else if (_n == ngay._n) {
		if (_th > ngay._th) {
			return true;
		}
		else if (_th == ngay._th) {
			if (_ng > ngay._ng) {
				return true;
			}
		}
	}

	return false;
}

ostream& operator<<(ostream& os, const Ngay& ngay) {
	os << ngay._ng << "/" << ngay._th << "/" << ngay._n;
	return os;
}

int Ngay::arrNgayCuaThang[][13] = { {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
									{-1, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} };


/*
Nhan xet:
- Chuan hoa ngay theo quy luat: 
	+ Phep cong: cong theo ngay, thang, nam roi lam tron xuong
	+ Phep tru: tru theo ngay, thang, nam roi lam tron xuong

- Theo ket qua ham main: cac phep cong o n6, n7, n8, khi thang > 12, ta
tru di 12, khong can phai tang nam len 1 don vi.
Nhung nhu vay ngay n5 lai bi lech 1 nam.

- Nguoc lai, neu ta cong phan du qua nam, thi cac phep cong o n5, n6, n7, n8
lai cho ra ket qua khong chinh xac.

- Neu chuan hoa theo quy luat co quy tac ngay tuan theo thang, co xet nam nhuan
thi ket qua cung se khac.
*/


int main() {
	Ngay n1;
	Ngay n2(2, 10, 2014);
	Ngay n3(-10, 16, 2000);
	Ngay n4(1000);
	Ngay n5 = n2 + n3;
	Ngay n6 = n1 + 5000;
	Ngay n7 = 1234 + n4;
	Ngay n8 = 190 + n6 + n7;
	Ngay n9 = n8 - n6;
	Ngay n10 = 12000 - n9;

	if (n10 > n6) {
		n10 = n2 - 1000 + n6;
	}

	cout << n1 << endl << n2 << endl << n3 << endl << n4 << endl;
	cout << n5 << endl << n6 << endl << n7 << endl << n8 << endl;
	cout << n9 << endl << n10 << endl;

	system("pause");
	return 0;
}

// Phep cong co quy tac theo so ngay trong thang, xet nam nhuan
/*
Ngay Ngay::operator+(const Ngay& ngay) {
	Ngay res;

	res._ng = this->_ng + ngay._ng;
	res._th = this->_th + ngay._th;
	res._n = this->_n + ngay._n;

	if (res._th > 12) {
		res._th -= 12;
		res._n++;
	}

	int idxN = LaNamNhuan(res._n);
	int soNgayChuan = arrNgayCuaThang[idxN][res._th];

	while (res._ng > soNgayChuan) {
		res._ng -= soNgayChuan;
		res._th++;
		if (res._th > 12) {
			res._th = 1;
			res._n++;
			idxN = LaNamNhuan(res._n);
		}
		soNgayChuan = arrNgayCuaThang[idxN][res._th];
	}

	return res;
}
*/

// Phep tru co quy tac theo so ngay trong thang, xet nam nhuan
/*
Ngay Ngay::operator-(const Ngay& ngay) {
	Ngay res;
	res._ng = this->_ng - ngay._ng;
	res._th = this->_th - ngay._th;
	res._n = this->_n - ngay._n;
	if (res._th < 1) {
		res._th += 12;
		res._n--;
	}
	int idxN = LaNamNhuan(res._n);
	int soNgayChuan = (_th == 1) ? arrNgayCuaThang[idxN][12] : arrNgayCuaThang[idxN][res._th - 1];
	while (res._ng < 1) {
		res._ng += soNgayChuan;
		res._th--;
		if (res._th < 1) {
			res._th = 12;
			res._n--;
			idxN = LaNamNhuan(res._n);
		}
		soNgayChuan = (_th == 1) ? arrNgayCuaThang[idxN][12] : arrNgayCuaThang[idxN][res._th - 1];
	}
	return res;
}
*/
