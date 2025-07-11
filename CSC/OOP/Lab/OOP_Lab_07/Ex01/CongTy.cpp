#include "CongTy.h"

CongTy::CongTy() {
	soLuongNV = 0;
}

CongTy::CongTy(LinkedList<NhanVien*> dsNV, int sl) {
	this->dsNV = dsNV;
	soLuongNV = sl;
}

CongTy::CongTy(const CongTy& ct) {
	dsNV = ct.dsNV;
	soLuongNV = ct.soLuongNV;
}

CongTy::~CongTy() {
	for (int i = 0; i < soLuongNV; i++) {
		delete dsNV[i];
	}
}

istream& operator>>(istream& is, CongTy& ct) {
	cout << "Nhap so luong nhan vien: ";
	is >> ct.soLuongNV;

	for (int i = 0; i < ct.soLuongNV; i++) {
		cout << "Nhap nhan vien thu " << i + 1 << ":" << endl;
		cout << "Chon loai nhan vien (1: Thu ky, 2: Ky thuat): ";
		int loai;
		is >> loai;

		if (loai == 1) {
			NhanVienThuKy* nv = new NhanVienThuKy;
			is >> *nv;
			ct.dsNV.addTail(nv);
		}
		else {
			NhanVienKyThuat* nv = new NhanVienKyThuat;
			is >> *nv;
			ct.dsNV.addTail(nv);
		}
	}
	return is;
}

ostream& operator<<(ostream& os, const CongTy& ct) {
	os << "So luong nhan vien: " << ct.soLuongNV << endl << endl;
	for (int i = 0; i < ct.soLuongNV; i++) {
		os << *ct.dsNV[i] << endl;
	}
	return os;
}

void CongTy::themNV(NhanVien* nv) {
	dsNV.addTail(nv);
	soLuongNV++;
}

void CongTy::xuatDSNVXuatSac() {
	cout << "Danh sach nhan vien xuat sac:" << endl << endl;
	for (int i = 0; i < soLuongNV; i++) {
		if (dsNV[i]->laNVXuatSac()) {
			cout << *dsNV[i] << endl;
		}
	}
}