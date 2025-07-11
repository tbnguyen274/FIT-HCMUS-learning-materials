#include "NhanVien.h"

// NHANVIEN

NhanVien::NhanVien() {
	hoTen = new char[1];
	hoTen[0] = '\0';
	diaChi = new char[1];
	diaChi[0] = '\0';
}

NhanVien::NhanVien(const char* ht, const char* dc) {
	hoTen = new char[strlen(ht) + 1];
	strcpy(hoTen, ht);
	diaChi = new char[strlen(dc) + 1];
	strcpy(diaChi, dc);
}

NhanVien::NhanVien(const NhanVien& nv) {
	hoTen = new char[strlen(nv.hoTen) + 1];
	strcpy(hoTen, nv.hoTen);
	diaChi = new char[strlen(nv.diaChi) + 1];
	strcpy(diaChi, nv.diaChi);
}

NhanVien::~NhanVien() {
	if (hoTen != nullptr) {
		delete[] hoTen;
		hoTen = nullptr;
	}

	if (diaChi != nullptr) {
		delete[] diaChi;
		diaChi = nullptr;
	}
}

istream& operator>>(istream& is, NhanVien& nv) {
	nv.nhap(is);
	return is;
}

ostream& operator<<(ostream& os, const NhanVien& nv) {
	nv.xuat(os);
	return os;
}

// NHANVIENTHUKY

NhanVienThuKy::NhanVienThuKy() : NhanVien() {
	ccNgoaiNgu = new char[1];
	ccNgoaiNgu[0] = '\0';
	soLuongBaoCao = 0;
}

NhanVienThuKy::NhanVienThuKy(const char* ht, const char* dc, const char* cc, int sl) : NhanVien(ht, dc) {
	ccNgoaiNgu = new char[strlen(cc) + 1];
	strcpy(ccNgoaiNgu, cc);
	soLuongBaoCao = sl;
}

NhanVienThuKy::NhanVienThuKy(const NhanVienThuKy& nv) : NhanVien(nv) {
	ccNgoaiNgu = new char[strlen(nv.ccNgoaiNgu) + 1];
	strcpy(ccNgoaiNgu, nv.ccNgoaiNgu);
	soLuongBaoCao = nv.soLuongBaoCao;
}

NhanVienThuKy::~NhanVienThuKy() {
	if (ccNgoaiNgu != nullptr) {
		delete[] ccNgoaiNgu;
		ccNgoaiNgu = nullptr;
	}
}

void NhanVienThuKy::nhap(istream& is) {
	char ht[MAX], dc[MAX], cc[MAX];
	cout << "Nhap ho ten: ";
	is.ignore();
	is.getline(ht, MAX);
	cout << "Nhap dia chi: ";
	is.getline(dc, MAX);
	cout << "Nhap chung chi ngoai ngu: ";
	is.getline(cc, MAX);
	cout << "Nhap so luong bao cao: ";
	is >> soLuongBaoCao;

	hoTen = new char[strlen(ht) + 1];
	strcpy(hoTen, ht);
	diaChi = new char[strlen(dc) + 1];
	strcpy(diaChi, dc);
	ccNgoaiNgu = new char[strlen(cc) + 1];
	strcpy(ccNgoaiNgu, cc);
}

void NhanVienThuKy::xuat(ostream& os) const {
	os << "Ho ten: " << hoTen << endl;
	os << "Dia chi: " << diaChi << endl;
	os << "Chung chi ngoai ngu: " << ccNgoaiNgu << endl;
	os << "So luong bao cao: " << soLuongBaoCao << endl;
}

bool NhanVienThuKy::laNVXuatSac() {
	return soLuongBaoCao >= 12;
}

// NHANVIENKYTHUAT

NhanVienKyThuat::NhanVienKyThuat() : NhanVien() {
	ccNganh = new char[1];
	ccNganh[0] = '\0';
	soLuongSangKien = 0;
}

NhanVienKyThuat::NhanVienKyThuat(const char* ht, const char* dc, const char* cc, int sl) : NhanVien(ht, dc) {
	ccNganh = new char[strlen(cc) + 1];
	strcpy(ccNganh, cc);
	soLuongSangKien = sl;
}

NhanVienKyThuat::NhanVienKyThuat(const NhanVienKyThuat& nv) : NhanVien(nv) {
	ccNganh = new char[strlen(nv.ccNganh) + 1];
	strcpy(ccNganh, nv.ccNganh);
	soLuongSangKien = nv.soLuongSangKien;
}

NhanVienKyThuat::~NhanVienKyThuat() {
	if (ccNganh != nullptr) {
		delete[] ccNganh;
		ccNganh = nullptr;
	}
}

void NhanVienKyThuat::nhap(istream& is) {
	char ht[MAX], dc[MAX], cc[MAX];
	cout << "Nhap ho ten: ";
	is.ignore();
	is.getline(ht, MAX);
	cout << "Nhap dia chi: ";
	is.getline(dc, MAX);
	cout << "Nhap chung chi nganh: ";
	is.getline(cc, MAX);
	cout << "Nhap so luong sang kien: ";
	is >> soLuongSangKien;

	hoTen = new char[strlen(ht) + 1];
	strcpy(hoTen, ht);
	diaChi = new char[strlen(dc) + 1];
	strcpy(diaChi, dc);
	ccNganh = new char[strlen(cc) + 1];
	strcpy(ccNganh, cc);
}

void NhanVienKyThuat::xuat(ostream& os) const {
	os << "Ho ten: " << hoTen << endl;
	os << "Dia chi: " << diaChi << endl;
	os << "Chung chi nganh: " << ccNganh << endl;
	os << "So luong sang kien: " << soLuongSangKien << endl;
}

bool NhanVienKyThuat::laNVXuatSac() {
	return soLuongSangKien >= 6;
}