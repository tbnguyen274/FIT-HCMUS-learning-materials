#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

#define PI 3.14159

class Hinh {
public:
	virtual double tinhChuVi() = 0;
	virtual double tinhDienTich() = 0;
	virtual double tinhDienTichXungQuanh() = 0;
	virtual double tinhTheTich() = 0;
	virtual string tenHinh() = 0;

	friend ostream& operator<<(ostream& os, Hinh& h) {
		os << h.tenHinh();
		if (h.tinhChuVi() > 0) {
			os << " [P = " << h.tinhChuVi();
			if (h.tinhDienTich() > 0) {
				os << ", S = " << h.tinhDienTich() << "]";
			}
			else {
				os << "]";
			}
		}
		else if (h.tinhDienTichXungQuanh() > 0) {
			os << " [Sxq = " << h.tinhDienTichXungQuanh();
			if (h.tinhTheTich() > 0) {
				os << ", V = " << h.tinhTheTich() << "]";
			}
			else {
				os << "]";
			}
		}
		return os;
	}

};


class HinhTron : public Hinh {
protected:
	double banKinh;

public:
	HinhTron() {
		banKinh = 0;
	}

	HinhTron(double bk) {
		banKinh = (bk == 0) ? 1 : abs(bk);
	}

	double tinhDienTich() override {
		return PI * banKinh * banKinh;
	}

	double tinhChuVi() override {
		return 2 * PI * banKinh;
	}

	double tinhDienTichXungQuanh() override {
		return 0;
	}

	double tinhTheTich() override {
		return 0;
	}

	string tenHinh() override {
		return "Hinh Tron";
	}
};


class HinhTamGiacDeu : public Hinh {
private:
	double canh;

public:
	HinhTamGiacDeu() {
		canh = 0;
	}

	HinhTamGiacDeu(double c) {
		canh = (c == 0) ? 1 : abs(c);
	}

	double tinhDienTich() override {
		return (sqrt(3) / 4) * canh * canh;
	}

	double tinhChuVi() override {
		return canh * 3;
	}

	double tinhDienTichXungQuanh() override {
		return 0;
	}

	double tinhTheTich() override {
		return 0;
	}

	string tenHinh() override {
		return "Hinh Tam Giac Deu";
	}
};


class HinhChuNhat : public Hinh {
protected:
	double chieuDai, chieuRong;

public:
	HinhChuNhat() {
		chieuDai = chieuRong = 0;
	}

	HinhChuNhat(const double& cd, const double& cr) {
		chieuDai = (cd == 0) ? 1 : abs(cd);
		chieuRong = (cr == 0) ? 1 : abs(cr);
	}

	double tinhDienTich() override {
		return chieuDai * chieuRong;
	}

	double tinhChuVi() override {
		return (chieuDai + chieuRong) * 2;
	}

	double tinhDienTichXungQuanh() override {
		return 0;
	}

	double tinhTheTich() override {
		return 0;
	}

	string tenHinh() override {
		return "Hinh Chu Nhat";
	}
};


class HinhVuong : public HinhChuNhat {
public:
	HinhVuong() : HinhChuNhat() {}

	HinhVuong(double canh) : HinhChuNhat(canh, canh) {}

	string tenHinh() override {
		return "Hinh Vuong";
	}
};

class HinhCau : public HinhTron {
public:
	HinhCau() : HinhTron() {}

	HinhCau(double bk) : HinhTron(bk) {}

	double tinhChuVi() override {
		return 0;
	}

	double tinhDienTich() override {
		return 0;
	}

	double tinhTheTich() override {
		return (4.0 / 3) * PI * pow(banKinh, 3);
	}

	double tinhDienTichXungQuanh() override {
		return 4 * PI * banKinh * banKinh;
	}

	string tenHinh() override {
		return "Hinh Cau";
	}
};


class HinhLapPhuong : public HinhVuong {
public:
	HinhLapPhuong() : HinhVuong() {}

	HinhLapPhuong(double canh) : HinhVuong(canh) {}

	double tinhChuVi() override {
		return 0;
	}

	double tinhDienTich() override {
		return 0;
	}

	double tinhTheTich() override {
		return pow(chieuDai, 3);
	}

	double tinhDienTichXungQuanh() override {
		return pow(chieuDai, 2) * 4;
	}
	string tenHinh() override {
		return "Hinh Lap Phuong";
	}
};


class HinhHop : public HinhChuNhat {
private:
	double chieuCao;

public:
	HinhHop() : HinhChuNhat() {
		chieuCao = 0;
	}

	HinhHop(double cd, double cr, double cc) : HinhChuNhat(cd, cr) {
		chieuCao = (cc == 0) ? 1 : abs(cc);
	}

	double tinhChuVi() override {
		return 0;
	}

	double tinhDienTich() override {
		return 0;
	}
	
	double tinhTheTich() override {
		return chieuDai * chieuRong * chieuCao;
	}

	double tinhDienTichXungQuanh() override {
		return (chieuDai + chieuRong) * 2 * chieuCao;
	}

	string tenHinh() override {
		return "Hinh Hop";
	}
};


class HinhTru : public HinhTron {
private:
	double chieuCao;

public:
	HinhTru() : HinhTron() {
		chieuCao = 0;
	}

	HinhTru(double bk, double cc) : HinhTron(bk) {
		chieuCao = (cc == 0) ? 1 : abs(cc);
	}

	double tinhChuVi() override {
		return 0;
	}

	double tinhDienTich() override {
		return 0;
	}

	double tinhTheTich() override {
		return PI * banKinh * banKinh * chieuCao;
	}

	double tinhDienTichXungQuanh() override {
		return 2 * PI * banKinh * chieuCao;
	}

	string tenHinh() override {
		return "Hinh Tru";
	}
};


class HinhNon : public HinhTron {
private:
	double chieuCao;

public:
	HinhNon() : HinhTron() {
		chieuCao = 0;
	}

	HinhNon(double bk, double cc) : HinhTron(bk) {
		chieuCao = (cc == 0) ? 1 : abs(cc);
	}

	double tinhChuVi() override {
		return 0;
	}

	double tinhDienTich() override {
		return 0;
	}

	double tinhTheTich() override {
		return (1.0 / 3) * PI * banKinh * banKinh * chieuCao;
	}

	double tinhDienTichXungQuanh() override {
		double duongSinh = sqrt(chieuCao * chieuCao + banKinh * banKinh);
		return PI * banKinh * duongSinh;

	}

	string tenHinh() override {
		return "Hinh Non";
	}
};


int main() {
	vector<Hinh*> dsHinh;
	dsHinh.push_back(new HinhTron(3.5));
	dsHinh.push_back(new HinhTamGiacDeu(8.5));
	dsHinh.push_back(new HinhChuNhat(3.7, 1.9));
	dsHinh.push_back(new HinhVuong(4.1));
	dsHinh.push_back(new HinhCau(13.5));
	dsHinh.push_back(new HinhLapPhuong(2.9));
	dsHinh.push_back(new HinhHop(1.2, 3.7, 6.3));
	dsHinh.push_back(new HinhTru(6.1, 4.9));
	dsHinh.push_back(new HinhNon(8.7, 3.2));
	
	// Xuat thong tin cac hinh
	// dinh dang: <Ten Hinh> [P hoac Sxq = xx, S hoac V = xx]
	// vd: "Hinh Vuong [P = 12.5, S = 45.7]"
	// hoac: "Hinh Cau [Sxq = 45.7, V = 67.4]"

	for (int i = 0; i < dsHinh.size(); i++) {
		cout << *dsHinh[i] << endl;
	}

	cout << endl << endl;
	system("pause");
	return 0;
}