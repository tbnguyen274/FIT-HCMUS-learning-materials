#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>

using namespace std;

class Ngay {
private:
	int _ng, _th, _n;
	void chuanHoa();

public:
	Ngay();
	Ngay(const int&);
	Ngay(const int&, const int&, const int&);
	Ngay(const char* s);
	~Ngay();
	void Xuat();
};

void Ngay::chuanHoa() {
	_ng = abs(_ng);
	_th = abs(_th);
	_n = abs(_n);

	int thangDu = (_ng - 1) / 30;
	_ng = (_ng - 1) % 30 + 1;
	_th += thangDu;

	int namDu = (_th - 1) / 12;
	_th = (_th - 1) % 12 + 1;
	_n += namDu;
}

Ngay::Ngay() {
	_ng = _th = _n = 1;
}

Ngay::Ngay(const int& x) {
	_ng = abs(x);
	_th = _n = 1;
	chuanHoa();
}

Ngay::Ngay(const int& ng, const int& th, const int& n) {
	_ng = abs(ng);
	_th = abs(th);
	_n = abs(n);
	chuanHoa();
}

Ngay::Ngay(const char* s) {
	int len = strlen(s);
	char* sTemp = new char[len + 1];
	strcpy_s(sTemp, len + 1, s);

	const char* delimiters = "-/";
	char* temp;
	char* sCur = strtok_s(sTemp, delimiters, &temp);
	_ng = atoi(sCur);

	if (sCur) {
		sCur = strtok_s(nullptr, delimiters, &temp);
		_th = atoi(sCur);
	}

	if (sCur) {
		sCur = strtok_s(nullptr, delimiters, &temp);
		_n = atoi(sCur);
	}

	delete[] sTemp;
	chuanHoa();
}

Ngay::~Ngay() {

}

void Ngay::Xuat() {
	cout << _ng << "/" << _th << "/" << _n;
}

int main() {
	Ngay n1;
	n1.Xuat();
	cout << endl;
	Ngay n2(2, 10, 2024);
	n2.Xuat();
	cout << endl;
	Ngay n3(-100, 16, 1990);
	n3.Xuat();
	cout << endl;
	Ngay n4(1403);
	n4.Xuat();
	cout << endl;
	Ngay n5("12-02-2012");
	n5.Xuat();
	cout << endl << endl;

	system("pause");
}