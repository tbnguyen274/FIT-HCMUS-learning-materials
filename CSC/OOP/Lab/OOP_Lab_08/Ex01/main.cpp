#include <iostream>
#include <string>

using namespace std;

class NhanVien {
private:
	string hoTen, diaChi;

public:
	NhanVien();
	NhanVien(const string& ht, const string& dc);
	~NhanVien();

	friend ostream& operator<<(ostream& os, const NhanVien& nv);
};

NhanVien::NhanVien() {
	hoTen = "";
	diaChi = "";
}

NhanVien::NhanVien(const string& ht, const string& dc) {
	hoTen = ht;
	diaChi = dc;
}

NhanVien::~NhanVien() {}

ostream& operator<<(ostream& os, const NhanVien& nv) {
	os << nv.hoTen << " (" << nv.diaChi << ")";
	return os;
}

class NhanVienKyThuat : public NhanVien {
private:
	string chungChiNganh;

public:
	NhanVienKyThuat();
	NhanVienKyThuat(const string& ht, const string& dc, const string& cc);
	~NhanVienKyThuat();

	friend ostream& operator<<(ostream& os, const NhanVienKyThuat& nvkt);
};

NhanVienKyThuat::NhanVienKyThuat() : NhanVien() {
	chungChiNganh = "";
}

NhanVienKyThuat::NhanVienKyThuat(const string& ht, const string& dc, const string& cc) : NhanVien(ht, dc) {
	chungChiNganh = cc;
}

NhanVienKyThuat::~NhanVienKyThuat() {}

ostream& operator<<(ostream& os, const NhanVienKyThuat& nvkt) {
	os << (NhanVien)nvkt;
	os << " [" << nvkt.chungChiNganh << "]";
	return os;
}

int main() {
	NhanVienKyThuat nvkt("Nguyen Van A", "Nguyen Van Cu, Q.5", "CNTT");
	cout << nvkt << endl << endl;
	system("pause");
	return 0;
}