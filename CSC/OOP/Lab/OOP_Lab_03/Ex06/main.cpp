#include <iostream>
#include <iomanip>

using namespace std;

class ThoiGian {
private:
	int _gio, _phut, _giay;
	void chuanHoa();

public:
	ThoiGian();
	ThoiGian(const int&);
	ThoiGian(const int&, const int&);
	ThoiGian(const int&, const int&, const int&);
	~ThoiGian();

	ThoiGian operator+(const ThoiGian&);
	friend ThoiGian operator+(const int&, const ThoiGian&);
	ThoiGian operator-(const ThoiGian&);
	friend ThoiGian operator-(const int&, const ThoiGian&);
	bool operator<=(const ThoiGian&);
	friend bool operator<=(const int&, const ThoiGian&);
	friend ostream& operator<<(ostream&, const ThoiGian&);
};

ThoiGian::ThoiGian() {
	_gio = _phut = _giay = 0;
}

void ThoiGian::chuanHoa() {
	_gio = (_gio >= 0) ? _gio : -_gio;
	_phut = (_phut >= 0) ? _phut : -_phut;
	_giay = (_giay >= 0) ? _giay : -_giay;

	if (_giay >= 60) {
		_phut += _giay / 60;
		_giay %= 60;
	}

	if (_phut >= 60) {
		_gio += _phut / 60;
		_phut %= 60;
	}
}

ThoiGian::ThoiGian(const int& x) : ThoiGian() {
	_giay = x;
	chuanHoa();
}

ThoiGian::ThoiGian(const int& x, const int& y) : ThoiGian() {
	_phut = x;
	_giay = y;
	chuanHoa();
}

ThoiGian::ThoiGian(const int& x, const int& y, const int& z) : ThoiGian() {
	_gio = x;
	_phut = y;
	_giay = z;
	chuanHoa();
}

ThoiGian::~ThoiGian() {

}

ThoiGian ThoiGian::operator+(const ThoiGian& tg) {
	ThoiGian res;
	res._gio = _gio + tg._gio;
	res._phut = _phut + tg._phut;
	res._giay = _giay + tg._giay;
	res.chuanHoa();
	return res;
}

ThoiGian operator+(const int& x, const ThoiGian& tg) {
	ThoiGian res(x);
	return res + tg;
}

ThoiGian ThoiGian::operator-(const ThoiGian& tg) {
	ThoiGian res;
	res._gio = _gio - tg._gio;
	res._phut = _phut - tg._phut;
	res._giay = _giay - tg._giay;

	if (res._giay < 0) {
		res._giay += 60;
		res._phut--;
	}

	if (res._phut < 0) {
		res._phut += 60;
		res._gio--;
	}

	if (res._gio < 0) {
		res._gio = res._phut = res._giay = 0;
	}

	return res;
}

ThoiGian operator-(const int& x, const ThoiGian& tg) {
	ThoiGian res(x);
	return res - tg;
}

bool ThoiGian::operator<=(const ThoiGian& tg) {
	if (_gio < tg._gio) {
		return true;
	}
	else if (_gio == tg._gio) {
		if (_phut < tg._phut) {
			return true;
		}
		else if (_phut == tg._phut) {
			if (_giay <= tg._giay) {
				return true;
			}
		}
	}

	return false;
}

bool operator<=(const int& x, const ThoiGian& tg) {
	return ThoiGian(x) <= tg;
}

ostream& operator<<(ostream& os, const ThoiGian& tg) {
	os << setw(2) << setfill('0') << tg._gio << ":"
		<< setw(2) << setfill('0') << tg._phut << ":"
		<< setw(2) << setfill('0') << tg._giay;
	return os;
}

/*
Nhan xet: 12345 > tg5 nen gia tri tg10 khong thay doi va bang 00:00:00
*/

int main() {
	ThoiGian tg1;
	ThoiGian tg2(1212);
	ThoiGian tg3(125, 45);
	ThoiGian tg4(12, 239, -78);
	ThoiGian tg5 = tg2 + tg3;
	ThoiGian tg6 = 5000 + tg2;
	ThoiGian tg7 = tg4 - tg6;
	ThoiGian tg8 = 12300 - tg4;
	ThoiGian tg9, tg10;
	if (tg8 <= tg3) {
		tg9 = tg1 + tg2 + 36000;
	}
	if (12345 <= tg5) {
		tg10 = tg5 + 12345;
	}

	cout << tg1 << endl << tg2 << endl << tg3 << endl << tg4 << endl;
	cout << tg5 << endl << tg6 << endl << tg7 << endl << tg8 << endl;
	cout << tg9 << endl << tg10 << endl;
	return 0;
}