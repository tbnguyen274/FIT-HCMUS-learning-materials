#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class ThoiGian {
private:
	int gio, phut, giay;
	void chuanHoa();

public:
	ThoiGian();
	ThoiGian(const int&);
	ThoiGian(const int&, const int&);
	ThoiGian(const int&, const int&, const int&);
	~ThoiGian();
	void Xuat();
};

ThoiGian::ThoiGian() {
	gio = phut = giay = 0;
}

void ThoiGian::chuanHoa() {
	gio = (gio > 0) ? gio : 0;
	phut = (phut > 0) ? phut : 0;
	giay = (giay > 0) ? giay : 0;

	int phutDu = giay / 60;
	giay = giay % 60;
	phut += phutDu;

	int gioDu = phut / 60;
	phut = phut % 60;
	gio += gioDu;
}

ThoiGian::ThoiGian(const int& x) {
	giay = x;
	gio = phut = 0;
	chuanHoa();
}

ThoiGian::ThoiGian(const int& x, const int& y) {
	gio = 0;
	phut = x;
	giay = y;
	chuanHoa();
}

ThoiGian::ThoiGian(const int& x, const int& y, const int& z) {
	gio = x;
	phut = y;
	giay = z;
	chuanHoa();
}

ThoiGian::~ThoiGian() {

}

void ThoiGian::Xuat() {
	cout << setw(2) << setfill('0') << gio << ":";
	cout << setw(2) << setfill('0') << phut << ":";
	cout << setw(2) << setfill('0') << giay << endl;
}

void main() {
	ThoiGian tg1;
	tg1.Xuat();
	ThoiGian tg2(1212);
	tg2.Xuat();
	ThoiGian tg3(125, 45);
	tg3.Xuat();
	ThoiGian tg4(12, 239, -78);
	tg4.Xuat();
}