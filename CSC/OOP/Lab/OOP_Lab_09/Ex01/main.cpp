#include <iostream>
#include <vector>

using namespace std;

class Base {
public:
	virtual void Print(ostream& os) = 0;
	friend ostream& operator<<(ostream& os, Base& base) {
		base.Print(os);
		return os;
	}
};

class Derived1 : public Base {
private: 
	int _ofD1;

public:
	Derived1(const int& v) {
		_ofD1 = v;
	}

	void Print(ostream& os) {
		os << "D1 - " << _ofD1;
	}
};

class Derived2 : public Base {
private: 
	int _ofD2;

public:
	Derived2(const int& v) {
		_ofD2 = v;
	}

	void Print(ostream& os) {
		os << "D 2- " << _ofD2;
	}
};

int main() {
	vector<Base*> ds;
	ds.push_back(new Derived1(13));
	ds.push_back(new Derived1(17));
	ds.push_back(new Derived2(24));
	ds.push_back(new Derived2(28));

	for (int i = 0; i < ds.size(); i++) {
		cout << *ds[i] << endl;
	}

	cout << endl << endl;
	system("pause");
	return 0;
}