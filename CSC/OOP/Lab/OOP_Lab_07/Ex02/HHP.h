#ifndef HHP_H
#define HHP_H

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>

const double PI = 3.14;

using namespace std;

// abstract class
class HinhHocPhang {
protected:
	double dienTich;
	double chuVi;

	void capNhatDienTichVaChuVi();

public:
	HinhHocPhang();
	HinhHocPhang(const HinhHocPhang& hhp);
	virtual ~HinhHocPhang();

	virtual double tinhDienTich() const = 0;
	virtual double tinhChuVi() const = 0;

	double getDienTich() const;
	double getChuVi() const;

	virtual void nhap(istream& is) = 0;
	virtual void xuat(ostream& os) const = 0;

	friend istream& operator>>(istream& is, HinhHocPhang& hhp);
	friend ostream& operator<<(ostream& os, const HinhHocPhang& hhp);

	
};


class HinhChuNhat : public HinhHocPhang {
private:
	double chieuDai;
	double chieuRong;
	static int slHinhChuNhat;

public:
	HinhChuNhat();
	HinhChuNhat(double cd, double cr);
	HinhChuNhat(const HinhChuNhat& hcn);
	~HinhChuNhat() {};

	double tinhDienTich() const override;
	double tinhChuVi() const override;

	void nhap(istream& is) override;
	void xuat(ostream& os) const override;

	static int getSoLuongHinhChuNhat();
};


class HinhTron : public HinhHocPhang {
private:
	double banKinh;
	static int slHinhTron;

public:
	HinhTron();
	HinhTron(double r);
	HinhTron(const HinhTron& ht);
	~HinhTron() {};

	double tinhDienTich() const override;
	double tinhChuVi() const override;

	void nhap(istream& is) override;
	void xuat(ostream& os) const override;

	static int getSoLuongHinhTron();
};


class HinhTamGiac : public HinhHocPhang {
private:
	double a, b, c;
	static int slHinhTamGiac;

public:
	HinhTamGiac();
	HinhTamGiac(double c1, double c2, double c3);
	HinhTamGiac(const HinhTamGiac& htg);
	~HinhTamGiac() {};

	double tinhDienTich() const override;
	double tinhChuVi() const override;

	void nhap(istream& is) override;
	void xuat(ostream& os) const override;

	static int getSoLuongHinhTamGiac();
};


class HinhThangVuong : public HinhHocPhang {
private:
	double dayLon;
	double dayBe;
	double chieuCao;
	static int slHinhThangVuong;

public:
	HinhThangVuong();
	HinhThangVuong(const double& dl, const double& db, const double& cc);
	HinhThangVuong(const HinhThangVuong& htv);
	~HinhThangVuong() {};

	double tinhDienTich() const override;
	double tinhChuVi() const override;

	void nhap(istream& is) override;
	void xuat(ostream& os) const override;

	static int getSoLuongHinhThangVuong();
};


#endif // !HHP_H
