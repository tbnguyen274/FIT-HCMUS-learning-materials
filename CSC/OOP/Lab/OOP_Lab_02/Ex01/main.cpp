#include <iostream>

using namespace std;

class SoPhuc {
private:
	int thuc, ao;
	int sl;
	static int ssl;

public:
	SoPhuc();
	SoPhuc(const int& th, const int& a);
	SoPhuc(const SoPhuc& sp);
	~SoPhuc();

	SoPhuc Cong(const SoPhuc& sp);
	int SoLuongSP();
	static int SSoLuongSP();
};

SoPhuc::SoPhuc() {
	thuc = ao = 0;
	sl++;
	ssl++;
}

SoPhuc::SoPhuc(const int& th, const int& a) {
	thuc = th;
	ao = a;
	sl++;
	ssl++;
}

SoPhuc::SoPhuc(const SoPhuc& sp) {
	thuc = sp.thuc;
	ao = sp.ao;
	sl++;
	ssl++;
}

SoPhuc::~SoPhuc() {
	sl--;
	ssl--;
}

SoPhuc SoPhuc::Cong(const SoPhuc& sp) {
	SoPhuc kq(*this);
	kq.thuc += sp.thuc;
	kq.ao += sp.ao;
	return kq;
}

int SoPhuc::SoLuongSP() {
	return sl;
}

int SoPhuc::SSoLuongSP() {
	return ssl;
}

int SoPhuc::ssl = 0;

int main() {
	SoPhuc sp1;
	SoPhuc sp2(5, 10);
	SoPhuc sp3(sp1);
	SoPhuc sp4 = sp2.Cong(sp1);
	cout << SoPhuc::SSoLuongSP() << endl;	// 4
	{
		SoPhuc sp5;
		SoPhuc sp6 = sp2.Cong(sp4);
	}
	cout << sp4.SoLuongSP() << endl;		// ???
	cout << SoPhuc::SSoLuongSP() << endl;	// 4

	system("pause");
}