#include <iostream>
#include <cstring>

using namespace std;

class SoNguyenLon {
private:
	int* _mangGiaTri;
	int _soLuong;
	static SoNguyenLon* _snlMax;
	static int demSoChuSo(const long long& n);

public:
	SoNguyenLon();
	SoNguyenLon(const char* snl);
	SoNguyenLon(const int& chuSo, const int& soLuong);
	SoNguyenLon(const SoNguyenLon& snl);
	~SoNguyenLon();

	SoNguyenLon Tru(const SoNguyenLon& snl);
	SoNguyenLon Cong(const long long& hangSo);
	static SoNguyenLon HieuVoiHangSo(const long long& hangSo, const SoNguyenLon& snl);
	void In(ostream& os);
	void capNhatMax();
	static SoNguyenLon SNLMax();
};

int SoNguyenLon::demSoChuSo(const long long& n) {
	int dem = 0;
	long long tam = n;
	while (tam != 0) {
		dem++;
		tam /= 10;
	}
	return dem;
}

SoNguyenLon::SoNguyenLon() {
	_mangGiaTri = new int[1];
	_mangGiaTri[0] = 0;
	_soLuong = 1;

	capNhatMax();
}

SoNguyenLon::SoNguyenLon(const char* snl) {
	_soLuong = strlen(snl);
	_mangGiaTri = new int[_soLuong];

	for (int i = 0; i < _soLuong; i++) {
		_mangGiaTri[i] = snl[i] - '0';
	}

	capNhatMax();
}

SoNguyenLon::SoNguyenLon(const int& chuSo, const int& soLuong) {
	if (soLuong > 100 || chuSo < 0 || chuSo > 9) {
		if (soLuong > 100) {
			cout << "So chu so toi da la 100" << endl;
		}
		else {
			cout << "Chu so khong hop le" << endl;
		}

		_soLuong = 1;
		_mangGiaTri = new int[1];
		_mangGiaTri[0] = 0;
		return;
	}

	_soLuong = soLuong;
	_mangGiaTri = new int[_soLuong];

	for (int i = 0; i < _soLuong; i++) {
		_mangGiaTri[i] = chuSo;
	}

	capNhatMax();
}

SoNguyenLon::SoNguyenLon(const SoNguyenLon& snl) {
	_soLuong = snl._soLuong;
	_mangGiaTri = new int[_soLuong];

	for (int i = 0; i < _soLuong; i++) {
		_mangGiaTri[i] = snl._mangGiaTri[i];
	}

	capNhatMax();
}

SoNguyenLon::~SoNguyenLon() {
	if (_snlMax == this) {
		_snlMax = nullptr;
	}

	delete[] _mangGiaTri;
}

SoNguyenLon SoNguyenLon::Tru(const SoNguyenLon& snl) {
	if (_soLuong < snl._soLuong) {
		return SoNguyenLon();	// So be tru so lon = 0
	}

	SoNguyenLon hieu;
	hieu._soLuong = _soLuong;
	hieu._mangGiaTri = new int[hieu._soLuong];

	// Tru tu hang don vi
	int nho = 0;
	int i = _soLuong - 1;
	int j = snl._soLuong - 1;

	while (i >= 0) {
		hieu._mangGiaTri[i] = (j >= 0) ? _mangGiaTri[i] - snl._mangGiaTri[j] - nho : _mangGiaTri[i] - nho;

		if (hieu._mangGiaTri[i] < 0) {
			hieu._mangGiaTri[i] += 10;
			nho = 1;
		}
		else {
			nho = 0;
		}

		i--;
		j--;
	}

	// Xoa so 0 o dau
	while (hieu._soLuong > 1 && hieu._mangGiaTri[0] == 0) {
		hieu._soLuong--;

		for (int k = 0; k < hieu._soLuong; k++) {
			hieu._mangGiaTri[k] = hieu._mangGiaTri[k + 1];
		}
	}

	return hieu;
}

SoNguyenLon SoNguyenLon::Cong(const long long& hangSo) {
	int soLuong = demSoChuSo(hangSo);

	SoNguyenLon tong;
	tong._soLuong = (soLuong > _soLuong) ? soLuong : _soLuong;
	tong._mangGiaTri = new int[tong._soLuong + 1];

	int i = _soLuong - 1;
	int j = soLuong - 1;
	int nho = 0;
	long long hangSoTam = hangSo;

	// Cong tu hang don vi
	while (i >= 0) {
		int chuSo = hangSoTam % 10;
		hangSoTam /= 10;
		tong._mangGiaTri[i] = (j >= 0) ? _mangGiaTri[i] + chuSo + nho : _mangGiaTri[i] + nho;
		
		if (tong._mangGiaTri[i] >= 10) {
			tong._mangGiaTri[i] -= 10;
			nho = 1;
		}
		else {
			nho = 0;
		}

		i--;
		j--;
	}

	// Neu con nho thi them 1 vao dau mang
	if (nho == 1) {
		for (int k = tong._soLuong; k > 0; k--) {
			tong._mangGiaTri[k] = tong._mangGiaTri[k - 1];
		}
		tong._mangGiaTri[0] = 1;
		tong._soLuong++;
	}

	return tong;
}

SoNguyenLon SoNguyenLon::HieuVoiHangSo(const long long& hangSo, const SoNguyenLon& snl) {
	int soLuong = demSoChuSo(hangSo);
	if (soLuong < snl._soLuong) {
		return SoNguyenLon();
	}

	SoNguyenLon hieu;
	hieu._soLuong = soLuong;
	hieu._mangGiaTri = new int[hieu._soLuong];

	long long hangSoTam = hangSo;
	int nho = 0;
	int i = soLuong - 1;
	int j = snl._soLuong - 1;

	while (i >= 0) {
		int chuSo = hangSoTam % 10;
		hangSoTam /= 10;
		hieu._mangGiaTri[i] = (j >= 0) ? chuSo - snl._mangGiaTri[j] - nho : chuSo - nho;

		if (hieu._mangGiaTri[i] < 0) {
			hieu._mangGiaTri[i] += 10;
			nho = 1;
		}
		else {
			nho = 0;
		}
		i--;
		j--;
	}

	// Xoa so 0 o dau
	while (hieu._soLuong > 1 && hieu._mangGiaTri[0] == 0) {
		hieu._soLuong--;

		for (int k = 0; k < hieu._soLuong; k++) {
			hieu._mangGiaTri[k] = hieu._mangGiaTri[k + 1];
		}
	}

	return hieu;
}

void SoNguyenLon::In(ostream& os) {
	for (int i = 0; i < _soLuong; i++) {
		os << _mangGiaTri[i];
	}
}

SoNguyenLon SoNguyenLon::SNLMax() {
	return *_snlMax;
}

void SoNguyenLon::capNhatMax() {
	if (_snlMax == nullptr || this->_soLuong > _snlMax->_soLuong) {
		_snlMax = this;
		return;
	}

	if (this->_soLuong < _snlMax->_soLuong) {
		return;
	}

	int i = _soLuong - 1;
	int j = _snlMax->_soLuong - 1;

	while (i >= 0 && j >= 0 && _mangGiaTri[i] == _snlMax->_mangGiaTri[j]) {
		i--;
		j--;
	}

	if (i >= 0 && j >= 0 && _mangGiaTri[i] > _snlMax->_mangGiaTri[j]) {
		_snlMax = this;
	}
}

SoNguyenLon* SoNguyenLon::_snlMax = nullptr;

int main() {
	SoNguyenLon snl1;
	SoNguyenLon snl2("1234567");
	SoNguyenLon snl3(3, 14);
	SoNguyenLon snl4(9, 20);

	SoNguyenLon snl5 = snl3.Tru(snl2);
	SoNguyenLon snl6 = SoNguyenLon::HieuVoiHangSo(45678910, snl2);
	SoNguyenLon snl7 = snl4.Tru(snl3).Cong(123456789);

	snl1.In(cout);
	cout << endl;
	snl2.In(cout);
	cout << endl;
	snl3.In(cout);
	cout << endl;
	snl4.In(cout);
	cout << endl;
	snl5.In(cout);
	cout << endl;
	snl6.In(cout);
	cout << endl;
	snl7.In(cout);
	cout << endl;

	cout << "SoNguyenLon Max:" << endl;
	SoNguyenLon::SNLMax().In(cout);
	cout << endl;
	system("pause");
	return 0;
}