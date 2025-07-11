#ifndef NHANVIEN_H
#define NHANVIEN_H
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 100;

// abstract class
class NhanVien {
protected:
	char* hoTen;
	char* diaChi;

public:
	NhanVien();
	NhanVien(const char* ht, const char* dc);
	NhanVien(const NhanVien& nv);
	virtual ~NhanVien();

	// Ham thuan ao
	virtual void nhap(istream& is) = 0;
	virtual void xuat(ostream& os) const = 0;
	virtual bool laNVXuatSac() = 0;

	friend istream& operator>>(istream& is, NhanVien& nv);	
	friend ostream& operator<<(ostream& os, const NhanVien& nv);

	
};


class NhanVienThuKy : public NhanVien {
private:
	char* ccNgoaiNgu;
	int soLuongBaoCao;

public:
	NhanVienThuKy();
	NhanVienThuKy(const char* ht, const char* dc, const char* cc, int sl);
	NhanVienThuKy(const NhanVienThuKy& nv);
	~NhanVienThuKy();

	void nhap(istream& is) override;
	void xuat(ostream& os) const override;
	bool laNVXuatSac() override;

};


class NhanVienKyThuat : public NhanVien {
private:
	char* ccNganh;
	int soLuongSangKien;

public:
	NhanVienKyThuat();
	NhanVienKyThuat(const char* ht, const char* dc, const char* cc, int sl);
	NhanVienKyThuat(const NhanVienKyThuat& nv);
	~NhanVienKyThuat();

	void nhap(istream& is) override;
	void xuat(ostream& os) const override;
	bool laNVXuatSac() override;
};



#endif // !NHANVIEN_H
