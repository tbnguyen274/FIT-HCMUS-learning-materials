#include "QuanLyHHP.h"

bool readFile(const char* filename, QuanLyHinhHocPhang& ql) {
	FILE* file = fopen(filename, "r");
	if (file == nullptr) {
		cout << "Khong the mo file!" << endl;
		return false;
	}

	char line[256];
	char* loaiHinh, *token;

	while (fgets(line, sizeof(line), file)) {
		line[strcspn(line, "\n")] = '\0';
		loaiHinh = strtok(line, ":");

		if (strcmp(loaiHinh, "hcn") == 0) {
			token = strtok(nullptr, ",");
			double chieuDai = atof(token);
			token = strtok(nullptr, ",");
			double chieuRong = atof(token);
			HinhChuNhat* hcn = new HinhChuNhat(chieuDai, chieuRong);
			ql.themHinh(hcn);
		}

		else if (strcmp(loaiHinh, "htr") == 0) {
			token = strtok(nullptr, ",");
			double banKinh = atof(token);
			HinhTron* htr = new HinhTron(banKinh);
			ql.themHinh(htr);
		}

		else if (strcmp(loaiHinh, "htg") == 0) {
			token = strtok(nullptr, ",");
			double canh1 = atof(token);
			token = strtok(nullptr, ",");
			double canh2 = atof(token);
			token = strtok(nullptr, ",");
			double canh3 = atof(token);
			HinhTamGiac* htg = new HinhTamGiac(canh1, canh2, canh3);
			ql.themHinh(htg);
		}

		else if (strcmp(loaiHinh, "hthv") == 0) {
			token = strtok(nullptr, ",");
			double dayLon = atof(token);
			token = strtok(nullptr, ",");
			double dayBe = atof(token);
			token = strtok(nullptr, ",");
			double chieuCao = atof(token);
			HinhThangVuong* hthv = new HinhThangVuong(dayLon, dayBe, chieuCao);
			ql.themHinh(hthv);
		}
	}

	ql.xuatTatCa();
	fclose(file);
	return true;
}


int main() {
	QuanLyHinhHocPhang ql;

	if (!readFile("hhp.txt", ql)) {
		return 1;
	}

	cout << endl;
	cout << "Thong ke so luong:\n";
	cout << "- Hinh chu nhat: " << HinhChuNhat::getSoLuongHinhChuNhat() << endl;
	cout << "- Hinh tron: " << HinhTron::getSoLuongHinhTron() << endl;
	cout << "- Hinh tam giac: " << HinhTamGiac::getSoLuongHinhTamGiac() << endl;
	cout << "- Hinh thang vuong: " << HinhThangVuong::getSoLuongHinhThangVuong() << endl;
	cout << "Tong so luong hinh: " << ql.getSoLuongHinh() << endl;

	cout << "Tong dien tich: " << ql.getTongDienTich() << endl;
	cout << "Tong chu vi: " << ql.getTongChuVi() << endl;

	return 0;
}
