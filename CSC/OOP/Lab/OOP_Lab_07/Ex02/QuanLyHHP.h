#ifndef QuanLyHHP_H
#define QuanLyHHP_H

#include "HHP.h"

class QuanLyHinhHocPhang {
private:
	HinhHocPhang** dsHinh;
	int slHinh;

public:
	QuanLyHinhHocPhang();
	QuanLyHinhHocPhang(HinhHocPhang** dsHinh, int slHinh);
	QuanLyHinhHocPhang(const QuanLyHinhHocPhang& ql);
	~QuanLyHinhHocPhang();

	QuanLyHinhHocPhang& operator=(const QuanLyHinhHocPhang& ql);

	void themHinh(HinhHocPhang* hhp);
	void xuatTatCa();
	double getTongDienTich();
	double getTongChuVi();
	int getSoLuongHinh();
};

#endif // !QuanLyHHP_H
