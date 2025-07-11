#ifndef CONGTY_H
#define CONGTY_H

#include "NhanVien.h"
#include "LinkedList.h"

class CongTy {
private:
	LinkedList<NhanVien*> dsNV;
	int soLuongNV;

public:
	CongTy();
	CongTy(LinkedList<NhanVien*> dsNV, int sl);
	CongTy(const CongTy& ct);
	~CongTy();

	friend istream& operator>>(istream& is, CongTy& ct);
	friend ostream& operator<<(ostream& os, const CongTy& ct);

	void themNV(NhanVien* nv);
	void xuatDSNVXuatSac();
};

#endif // !CONGTY_H
