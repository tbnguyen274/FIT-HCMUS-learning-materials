#include "CongTy.h"

bool readFile(const char* filename, CongTy& ct) {
	FILE* fp = fopen(filename, "r");
	if (fp == nullptr) {
		cout << "Khong the mo file " << filename << endl;
		return false;
	}

	char type[10], ht[MAX], dc[MAX], cc[MAX];
	int sl;

	while (fscanf(fp, "%[^:]: %[^()] (%[^)]) [%[^]]] <%d>\n", type, ht, dc, cc, &sl) != EOF) {
		int len = strlen(ht);

		if (ht[len - 1] == ' ') {
			ht[len - 1] = '\0';
		}

		if (strcmp(type, "nvkt") == 0) {
			NhanVien* nv = new NhanVienKyThuat(ht, dc, cc, sl);
			ct.themNV(nv);
		}
		else if (strcmp(type, "nvtk") == 0) {
			NhanVien* nv = new NhanVienThuKy(ht, dc, cc, sl);
			ct.themNV(nv);
		}
	}

	fclose(fp);
	return true;
}

int main() {
	CongTy ct;

	if (!readFile("input.txt", ct)) {
		return 1;
	}

	cout << ct << endl;
	cout << "--------------------------" << endl;
	ct.xuatDSNVXuatSac();

	return 0;
}