#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;

class ChiTietMay {
protected:
	string _maCT;

public:
	ChiTietMay(const string& maCT) {
		_maCT = maCT;
	}
	virtual ~ChiTietMay() {}
	virtual double TrongLuong() = 0;
	virtual double GiaThanh() = 0;
	virtual void Xuat(ostream& os, int indent = 0) = 0;
};

class ChiTietDon : public ChiTietMay {
private:
	double _trongLuong;
	double _giaThanh;

public:
	ChiTietDon(const string& maCT, const double& trongLuong, const double& giaThanh) : ChiTietMay(maCT) {
		_trongLuong = abs(trongLuong);
		_giaThanh = abs(giaThanh);
	}

	double TrongLuong() {
		return _trongLuong;
	}

	double GiaThanh() {
		return _giaThanh;
	}

	void Xuat(ostream& os, int indent = 0) {
		for (int i = 0; i < indent; i++) {
			os << "\t";
		}
		os << "Chi tiet don: " << _maCT << " [Trong luong: " << _trongLuong << ", Gia thanh: " << _giaThanh << "]" << endl;
	}
};

class ChiTietPhuc : public ChiTietMay {
private:
	vector<ChiTietMay*> _dsCT;

public:
	ChiTietPhuc(const string& maCT) : ChiTietMay(maCT) {}

	~ChiTietPhuc() {
		for (int i = 0; i < _dsCT.size(); i++) {
			delete _dsCT[i];
		}
	}

	void ThemChiTiet(ChiTietMay* ct) {
		_dsCT.push_back(ct);
	}

	double TrongLuong() {
		double total = 0;
		for (int i = 0; i < _dsCT.size(); i++) {
			total += _dsCT[i]->TrongLuong();
		}
		return total * 1.1;
	}

	double GiaThanh() {
		double total = 0;
		for (int i = 0; i < _dsCT.size(); i++) {
			total += _dsCT[i]->GiaThanh();
		}
		return total * 1.2;
	}

	void Xuat(ostream& os, int indent = 0) {
		for (int i = 0; i < indent; i++) {
			os << "\t";
		}
		os << "Chi tiet phuc: " << _maCT << endl;
		for (int i = 0; i < _dsCT.size(); i++) {
			_dsCT[i]->Xuat(os, indent + 1);
		}
	}
};

class CoMay {
private:
	vector<ChiTietMay*> _dsCT;

public:
	CoMay() {}

	~CoMay() {
		for (int i = 0; i < _dsCT.size(); i++) {
			delete _dsCT[i];
		}
	}

	void ThemChiTietMay(ChiTietMay* ct) {
		_dsCT.push_back(ct);
	}

	double TrongLuong() {
		double total = 0;
		for (int i = 0; i < _dsCT.size(); i++) {
			total += _dsCT[i]->TrongLuong();
		}
		return total * 1.1;
	}

	double GiaThanh() {
		double total = 0;
		for (int i = 0; i < _dsCT.size(); i++) {
			total += _dsCT[i]->GiaThanh();
		}
		return total * 1.2;
	}

	friend ostream& operator<<(ostream& os, CoMay& cm) {
		for (int i = 0; i < cm._dsCT.size(); i++) {
			cm._dsCT[i]->Xuat(os);
		}
		return os;
	}
};

int main() {
	// tao moi Co may
	CoMay* pcm = new CoMay();
	// them chi tiet
	pcm->ThemChiTietMay(new ChiTietDon("CTD001", 120, 350000));

	// tao Chi tiet phuc
	ChiTietMay* pctm = new ChiTietPhuc("CTP001");
	((ChiTietPhuc*)pctm)->ThemChiTiet(new ChiTietDon("CTD002", 50, 1280000));
	((ChiTietPhuc*)pctm)->ThemChiTiet(new ChiTietDon("CTD003", 20, 10000));
	ChiTietMay* pctm1 = new ChiTietPhuc("CTP002");
	((ChiTietPhuc*)pctm1)->ThemChiTiet(new ChiTietDon("CTD004", 80, 170000));

	((ChiTietPhuc*)pctm)->ThemChiTiet(pctm1);

	pcm->ThemChiTietMay(pctm);
	pcm->ThemChiTietMay(new ChiTietDon("CTD005", 210, 2350000));
	pcm->ThemChiTietMay(new ChiTietDon("CTD006", 40, 50000));

	// xuat thong tin co may
	// xuat danh sach cac chi tiet con
	cout << "Thong tin co may: " << endl << *pcm << endl;

	// Xuat trong luong co may
	cout << "Trong luong : " << pcm->TrongLuong() << endl;

	// Xuat gia thanh co may
	cout << "Gia thanh : " << pcm->GiaThanh() << endl;

	cout << endl << endl;
	system("pause");
	return 0;
}