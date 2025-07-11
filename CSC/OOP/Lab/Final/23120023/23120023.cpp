/*
Ho va ten : Nguyen Thai Bao
MSSV : 23120023
*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <sstream>

using namespace std;

class MachDien {
protected:
	string _maSo;

public:
	MachDien() {
		_maSo = "";
	}

	MachDien(const string& id) {
		_maSo = id;
	}

	virtual ~MachDien() {}

	string getMaSo() {
		return _maSo;
	}

	virtual double getDienTro() = 0;
	virtual double getTriGia() = 0;

	virtual void print(ostream& os) = 0;
	friend ostream& operator<<(ostream& os, MachDien* m) {
		m->print(os);
		return os;
	}


};

// Mach don
class MachDon : public MachDien {
private:
	double _dienTro;
	double _triGia;

public:
	MachDon() : MachDien() {
		_dienTro = _triGia = 0;
	}

	MachDon(const string& s, const double& dienTro, const double& triGia) : MachDien(s) {
		_dienTro = dienTro;
		_triGia = triGia;
	}

	MachDon(const MachDon& m) {
		_maSo = m._maSo;
		_dienTro = m._dienTro;
		_triGia = m._triGia;
	}

	~MachDon() {}

	double getDienTro() {
		return _dienTro;
	}

	double getTriGia() {
		return _triGia;
	}

	void setDienTro(double d) {
		_dienTro = d;
	}

	void setTriGia(double d) {
		_triGia = d;
	}

	void print(ostream& os) {
		os << _maSo << " " << getDienTro() << " " << getTriGia() << endl;
	}
};

// Mach Phuc
class MachPhuc : public MachDien {
protected:
	vector<MachDien*> _children;
	int count;

public:
	MachPhuc() : MachDien() {}

	MachPhuc(const string& s) : MachDien(s) {}

	virtual ~MachPhuc() {
		for (int i = 0; i < _children.size(); i++) {
			delete _children[i];
		}
	}

	void addChild(MachDien* m) {
		_children.push_back(m);

		count++;
	}

	void print(ostream& os) {
		os << _maSo << " " << getDienTro() << " " << getTriGia() << endl;

		os << "Children: \n";
		for (int i = 0; i < _children.size(); i++) {
			_children[i]->print(os);
		}
	}
};

class MachNoiTiep : public MachPhuc {
public:
	MachNoiTiep() : MachPhuc() {}

	MachNoiTiep(const string& s) : MachPhuc(s) {}

	double getDienTro() {
		double total = 0;
		for (int i = 0; i < _children.size(); i++) {
			total += _children[i]->getDienTro();
		}
		return total;
	}

	double getTriGia() {
		double total = 0;
		for (int i = 0; i < _children.size(); i++) {
			total += _children[i]->getTriGia();
		}
		return total;
	}
};


class MachSongSong : public MachPhuc {
private:
	// Tim mach song song nhieu mach don nhat
	static MachDien* maxMach;

public:
	MachSongSong() : MachPhuc() {}

	MachSongSong(const string& s) : MachPhuc(s) {}

	double getDienTro() {
		double reverse_total = 0;

		for (int i = 0; i < _children.size(); i++) {
			reverse_total += (1.0 / _children[i]->getDienTro());
		}

		double total = 1.0 / reverse_total;
		return total;
	}

	double getTriGia() {
		double total = 0;
		for (int i = 0; i < _children.size(); i++) {
			total += _children[i]->getTriGia();
		}
		return total * 1.1;
	}
};

class BoMach {
private:
	vector<MachDien*> _children;

public:
	BoMach() {}

	~BoMach() {
		for (int i = 0; i < _children.size(); i++) {
			delete _children[i];
		}
	}

	void addChild(MachDien* m) {
		_children.push_back(m);
	}

	friend ostream& operator<<(ostream& os, const BoMach& b) {
		os << "Bo mach:\n";
		for (int i = 0; i < b._children.size(); i++) {
			b._children[i]->print(os);
		}
		return os;
	}

	MachDien* timMachSSNhieuDonNhat() {
		// Khi add cac mach song song thi so sanh cac "count" de tim ra Mach nhieu don nhat
		MachDien* m;
		return m;
	}
};


int main() {
	BoMach b;

	fstream fs("data.txt");
	if (!fs.is_open()) {
		cout << "Error opening file.";
		return -1;
	}
	else {
		cout << "Opened file successfully\n\n";
	}

	string temp;
	while (getline(fs, temp)) {
		int hyphen = temp.find("-", 0);
		string type = temp.substr(0, hyphen - 1);
		string maSo = temp.substr(hyphen + 2);

		getline(fs, temp);
		double triGia = 0, tongTro = 0;
		int space = temp.find(" ", 0);
		triGia = stod(temp.substr(0, space));
		tongTro = stod(temp.substr(space + 1));

		MachDien* m;
		if (type == "MachNoiTiep") {
			m = new MachNoiTiep(maSo);
		}
		else if (type == "MachSongSong") {
			m = new MachSongSong(maSo);
		}
		else {
			m = new MachDon(maSo, tongTro, triGia);
		}

		string temp2;

		while (getline(fs, temp2) && temp2 != maSo) {
			// Tiep tuc doc cac mach con den khi gap co <maSo>
		}

		// them vao bo mach chu
		b.addChild(m);
	}

	fs.close();

	// Xuat thong tin Bo Mach
	cout << b << endl;

	return 0;
}