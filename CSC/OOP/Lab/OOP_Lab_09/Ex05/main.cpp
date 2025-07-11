#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

class Component {
protected:
	string _name;

public:
	Component(const string& s) {
		_name = s;
	}

	virtual ~Component() {}

	virtual double GetSize() = 0;
	virtual void Print(ostream& os, int indent = 0) = 0;
	virtual bool isDirectory() = 0;
};

class Directory : public Component {
private:
	vector<Component*> _children;

public:
	Directory(const string& s) : Component(s) {}

	~Directory() {
		for (int i = 0; i < _children.size(); i++) {
			delete _children[i];
		}
	}

	void AddChild(Component* c) {
		_children.push_back(c);
	}

	double GetSize() {
		double total = 0;
		for (int i = 0; i < _children.size(); i++) {
			total += _children[i]->GetSize();
		}
		return total;
	}

	void Print(ostream& os, int indent = 0) {
		for (int i = 0; i < indent; i++) {
			os << "\t";
		}

		os << "[" << _name << "]" << endl;
		for (int i = 0; i < _children.size(); i++) {
			_children[i]->Print(os, indent + 1);
		}
	}

	bool isDirectory() {
		return true;
	}

	void CountComponents(int& dCount, int& fCount) {
		for (int i = 0; i < _children.size(); i++) {
			if (_children[i]->isDirectory()) {
				Directory* cur = (Directory*)_children[i];
				int subDCount = 1, subFCount = 0;
				cur->CountComponents(subDCount, subFCount);
				dCount += subDCount;
				fCount += subFCount;
			}
			else {
				fCount++;
			}
		}
	}

	double GetSizeByName(const string& name) {
		if (_name == name) {
			return GetSize();
		}

		for (int i = 0; i < _children.size(); i++) {
			if (_children[i]->isDirectory()) {
				Directory* cur = (Directory*)_children[i];
				double size = cur->GetSizeByName(name);
				if (size > 0) {
					return size;
				}
			}
		}
		
		return 0;	// not found
	}

};

class File : public Component {
private:
	double _size;

public:
	File(const string& s, const double& size) : Component(s) {
		_size = abs(size);
	}

	double GetSize() {
		return _size;
	}

	void Print(ostream& os, int indent = 0) {
		for (int i = 0; i < indent; i++) {
			os << "\t";
		}
		os << _name << " (" << fixed << setprecision(3) << _size << " B)" << endl;
	}

	bool isDirectory() {
		return false;
	}
};

int main() {
	// Tao cay thu muc tap tin
	Directory* dRoot = new Directory("C:");

	Directory* dChild1 = new Directory("Bai tap");
	Directory* dChild2 = new Directory("Ly thuyet");

	// child1's children
	dChild1->AddChild(new File("BT1.doc", 123.456));

	Directory* dSubChild1 = new Directory("Bai tap C");
	dSubChild1->AddChild(new File("BT2.cpp", 1.280));
	dChild1->AddChild(dSubChild1);

	dChild1->AddChild(new File("BT2.xls", 23.456));

	// child2's children
	dChild2->AddChild(new File("Ch1.ppt", 34.567));

	// root's children
	dRoot->AddChild(dChild1);
	dRoot->AddChild(dChild2);

	// Xuat cay thu muc tu thu muc goc
	dRoot->Print(cout);

	// Dem so tap tin va thu muc trong mot thu muc
	cout << "\nDem so luong tap tin va thu muc [C:]:" << endl;
	int dCount = 0, fCount = 0;
	dRoot->CountComponents(dCount, fCount);
	cout << "So luong thu muc: " << dCount << endl;
	cout << "So luong tap tin: " << fCount << endl;

	// Tinh kich thuoc thu muc co ten cho truoc
	string name = "Bai tap";
	double size = dRoot->GetSizeByName(name);
	if (size > 0) {
		cout << "\nTong kich thuoc thu muc [" << name << "] la: " << size << " B" << endl;
	}
	else {
		cout << "\nKhong tim thay thu muc [" << name << "]" << endl;
	}

	system("pause");
	return 0;
}