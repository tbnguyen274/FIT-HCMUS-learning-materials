#include "QuanLyHHP.h"

QuanLyHinhHocPhang::QuanLyHinhHocPhang() {
	dsHinh = nullptr;
	slHinh = 0;
}

QuanLyHinhHocPhang::QuanLyHinhHocPhang(HinhHocPhang** dsHinh, int slHinh) {
	this->dsHinh = dsHinh;
	this->slHinh = slHinh;
}

QuanLyHinhHocPhang::QuanLyHinhHocPhang(const QuanLyHinhHocPhang& ql) {
	slHinh = ql.slHinh;
	dsHinh = new HinhHocPhang* [slHinh];
	for (int i = 0; i < slHinh; i++) {
		dsHinh[i] = ql.dsHinh[i];
	}
}

QuanLyHinhHocPhang::~QuanLyHinhHocPhang() {
	for (int i = 0; i < slHinh; i++) {
		delete dsHinh[i];
	}
	delete[] dsHinh;
}

QuanLyHinhHocPhang& QuanLyHinhHocPhang::operator=(const QuanLyHinhHocPhang& ql) {
	if (this != &ql) {
		for (int i = 0; i < slHinh; i++) {
			delete dsHinh[i];
		}
		delete[] dsHinh;

		slHinh = ql.slHinh;
		dsHinh = new HinhHocPhang * [slHinh];

		// deep copy
		for (int i = 0; i < slHinh; i++) {
			dsHinh[i] = ql.dsHinh[i];
		}
	}

	return *this;
}

void QuanLyHinhHocPhang::themHinh(HinhHocPhang* hhp) {
	HinhHocPhang** temp = new HinhHocPhang* [slHinh + 1];

	for (int i = 0; i < slHinh; i++) {
		temp[i] = dsHinh[i];
	}

	temp[slHinh] = hhp;
	delete[] dsHinh;
	dsHinh = temp;
	slHinh++;
}

void QuanLyHinhHocPhang::xuatTatCa() {
	for (int i = 0; i < slHinh; i++) {
		cout << *dsHinh[i];
		cout << "Dien tich: " << dsHinh[i]->tinhDienTich() << endl;
		cout << "Chu vi: " << dsHinh[i]->tinhChuVi() << endl;
		cout << endl;
	}
}

double QuanLyHinhHocPhang::getTongDienTich() {
	double s = 0;
	for (int i = 0; i < slHinh; i++) {
		s += dsHinh[i]->getDienTich();
	}
	return s;
}

double QuanLyHinhHocPhang::getTongChuVi() {
	double p = 0;
	for (int i = 0; i < slHinh; i++) {
		p += dsHinh[i]->getChuVi();
	}
	return p;
}

int QuanLyHinhHocPhang::getSoLuongHinh() {
	return slHinh;
}