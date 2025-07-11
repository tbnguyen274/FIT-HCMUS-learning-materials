#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>

using namespace std;

class NgayThang {
private:
	int _ng, _th, _n;
	void chuanHoa();

public:
	NgayThang();
	NgayThang(const int&);
	NgayThang(const int&, const int&, const int&);
	NgayThang(const char* mssv);
	~NgayThang();
	void Xuat();
};

void NgayThang::chuanHoa() {
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

NgayThang::NgayThang() {
	_ng = _th = _n = 1;
}

NgayThang::NgayThang(const int& x) {
	_ng = abs(x);
	_th = _n = 1;
	chuanHoa();
}

NgayThang::NgayThang(const int& ng, const int& th, const int& n) {
	_ng = abs(ng);
	_th = abs(th);
	_n = abs(n);
	chuanHoa();
}

NgayThang::NgayThang(const char* mssv) {
	int len = strlen(mssv);
	char* sTemp = new char[len + 1];
	strcpy_s(sTemp, len + 1, mssv);

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

NgayThang::~NgayThang() {

}

void NgayThang::Xuat() {
	cout << _ng << "/" << _th << "/" << _n;
}

class SinhVien {
private:
	char* _mssv;
	char* _hoTen;
	NgayThang _ngaySinh;
	float _DLT;
	float _DTH;

public:
	SinhVien();
	SinhVien(const char*);
	SinhVien(const char*, const char*, const float&, const float&);
	SinhVien(const char*, const char*, const float&, const float&, const int&, const int&, const int&);
	SinhVien(const char*, const char*, const float&, const float&, const NgayThang&);
	SinhVien(const SinhVien&);
	~SinhVien();
	void Xuat();
};

SinhVien::SinhVien() {
	_mssv = new char[8];
	strcpy_s(_mssv, 8, "0000000");

	_hoTen = new char[51];
	strcpy_s(_hoTen, 51, "An Danh");

	_DLT = _DTH = 0;
}

SinhVien::SinhVien(const char* mssv) {
	int len = strlen(mssv);
	_mssv = new char[len + 1];
	strcpy_s(_mssv, len + 1, mssv);

	_hoTen = new char[51];
	strcpy_s(_hoTen, 51, "An Danh");

	_DLT = _DTH = 0;
}

SinhVien::SinhVien(const char* mssv, const char* hoTen, const float& DLT, const float& DTH) {
	int len = strlen(mssv);
	_mssv = new char[len + 1];
	strcpy_s(_mssv, len + 1, mssv);

	int lenName = strlen(hoTen);
	_hoTen = new char[lenName + 1];
	strcpy_s(_hoTen, strlen(hoTen) + 1, hoTen);

	_DLT = DLT;
	_DTH = DTH;
}

SinhVien::SinhVien(const char* mssv, const char* hoTen, const float& DLT, const float& DTH, 
					const int& ng, const int& th, const int& n) {
	int len = strlen(mssv);
	_mssv = new char[len + 1];
	strcpy_s(_mssv, len + 1, mssv);

	int lenName = strlen(hoTen);
	_hoTen = new char[lenName + 1];
	strcpy_s(_hoTen, strlen(hoTen) + 1, hoTen);

	_DLT = DLT;
	_DTH = DTH;
	_ngaySinh = NgayThang(ng, th, n);
}

SinhVien::SinhVien(const char* mssv, const char* hoTen, const float& DLT, const float& DTH, const NgayThang& ngaySinh) {
	int len = strlen(mssv);
	_mssv = new char[len + 1];
	strcpy_s(_mssv, len + 1, mssv);

	int lenName = strlen(hoTen);
	_hoTen = new char[lenName + 1];
	strcpy_s(_hoTen, strlen(hoTen) + 1, hoTen);

	_DLT = DLT;
	_DTH = DTH;
	_ngaySinh = ngaySinh;
}

SinhVien::SinhVien(const SinhVien& sv) {
	int len = strlen(sv._mssv);
	_mssv = new char[len + 1];
	strcpy_s(_mssv, len + 1, sv._mssv);

	int lenName = strlen(sv._hoTen);
	_hoTen = new char[lenName + 1];
	strcpy_s(_hoTen, strlen(sv._hoTen) + 1, sv._hoTen);

	_DLT = sv._DLT;
	_DTH = sv._DTH;
	_ngaySinh = sv._ngaySinh;
}

SinhVien::~SinhVien() {
	delete[] _mssv;
	delete[] _hoTen;
}

void SinhVien::Xuat() {
	cout << "MSSV: \"" << _mssv << "\", HoTen: \"" << _hoTen << "\", NgaySinh: ";
	_ngaySinh.Xuat();
	cout << ", DLT: " << _DLT << ", DTH: " << _DTH << "." << endl;
}

void main() {
	// mssv: "xxxxxxx", hoTen: "xxxx", NgaySinh: xx/xx/xxxx, DLT: 10, DTH: 10.
	SinhVien sv1;
	sv1.Xuat();

	SinhVien sv2("1363001");
	sv2.Xuat();

	SinhVien sv3("1363002", "Nguyen Van A", 7, 8.5);
	sv3.Xuat();

	SinhVien sv4("1363003", "Tran Thi B", 8, 9.5, 12, 3, 1996);
	sv4.Xuat();

	NgayThang n(30, 2, 1996);

	SinhVien sv5("1363004", "Ngo Van C", 5, 6, n);
	sv5.Xuat();

	SinhVien sv6(sv5);
	sv6.Xuat();
}