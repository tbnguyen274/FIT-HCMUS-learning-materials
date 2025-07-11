#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

class HocSinh {
private:
	char* _hoTen;
	int _id;
	double _diem1, _diem2, _diem3;
	static int _capNhatID;
	static HocSinh* _hsMax;
	
public:
	HocSinh();
	HocSinh(const char*, const double&, const double&, const double&);
	~HocSinh();

	void DatHoTen(const char*);
	void GanDiem(const double&, const double&, const double&);
	void In(ostream&);

	double DiemTB();
	static HocSinh& HSDiemTBCaoNhat();
	void capNhatHSMax();
};

HocSinh::HocSinh(){
	_id = ++_capNhatID;

	_hoTen = new char[1];
	_hoTen[0] = '\0';
	_diem1 = _diem2 = _diem3 = 0;

	capNhatHSMax();
}

HocSinh::HocSinh(const char* hoTen, const double& diem1, const double& diem2, 
														const double& diem3) {
	_id = ++_capNhatID;

	_hoTen = new char[strlen(hoTen) + 1];
	strcpy_s(_hoTen, strlen(hoTen) + 1, hoTen);

	_diem1 = (diem1 >= 0) ? diem1 : -diem1;
	_diem2 = (diem2 >= 0) ? diem2 : -diem2;
	_diem3 = (diem3 >= 0) ? diem3 : -diem3;

	capNhatHSMax();
}

HocSinh::~HocSinh() {
	if (_hsMax == this) {
		_hsMax = nullptr;
	}

	delete[] _hoTen;
}

void HocSinh::DatHoTen(const char* hoTen) {
	if (_hoTen != nullptr) {
		delete[] _hoTen;
	}

	_hoTen = new char[strlen(hoTen) + 1];
	strcpy_s(_hoTen, strlen(hoTen) + 1, hoTen);
}

void HocSinh::GanDiem(const double& diem1, const double& diem2, const double& diem3) {
	_diem1 = (diem1 >= 0) ? diem1 : -diem1;
	_diem2 = (diem2 >= 0) ? diem2 : -diem2;
	_diem3 = (diem3 >= 0) ? diem3 : -diem3;

	capNhatHSMax();
}

void HocSinh::In(ostream& os) {
	os << "HS: " << _hoTen << ", MS: " << _id << ", DTB: ";
	os << fixed << setprecision(2) << DiemTB();
}

double HocSinh::DiemTB() {
	return (_diem1 + _diem2 + _diem3) / 3;
}

void HocSinh::capNhatHSMax() {
	if (_hsMax == nullptr || DiemTB() > _hsMax->DiemTB()) {
		_hsMax = this;
	}
}

HocSinh& HocSinh::HSDiemTBCaoNhat() {
	return *_hsMax;
}

int HocSinh::_capNhatID = 23120000;
HocSinh* HocSinh::_hsMax = nullptr;

int main() {
	HocSinh hs1;
	hs1.DatHoTen("Nguyen Van A");
	hs1.GanDiem(7, 8, 10);

	HocSinh hs2("Tran Thi B", 5, 8, 4.5);
	HocSinh hs3("Hoang Thi C", -9.5, 8.5, 4.5);
	HocSinh hs4("Le Van D", 7.5, 9, -10);

	hs1.In(cout);
	cout << endl;
	hs2.In(cout);
	cout << endl;
	hs3.In(cout);
	cout << endl;
	hs4.In(cout);
	cout << endl;

	cout << "Hoc sinh co diem TB cao nhat:" << endl;
	HocSinh::HSDiemTBCaoNhat().In(cout);
	cout << endl;

	system("pause");
	return 0;
}