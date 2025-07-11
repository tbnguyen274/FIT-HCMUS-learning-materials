#include "MyString.h"


int main() {
	MyString ms1("abcdsf");
	MyString ms2 = "____" + ms1;
	MyString ms3 = ms1 + ms2;

	cout << "ms1 = " << ms1 << endl;
	cout << "ms2 = " << ms2 << endl;
	cout << "ms3 = " << ms3 << endl << endl;

	MyString ms = "a,b,c;d.r;.,h;e,w__u,t.f;j_..";
	vector<char> arrChar;
	arrChar.push_back(',');
	arrChar.push_back('.');
	arrChar.push_back(';');

	vector<MyString> vMs = ms.Split(arrChar, false);
	cout << "Split: " << endl;
	for (vector<MyString>::iterator itMS = vMs.begin(); itMS != vMs.end(); ++itMS) {
		cout << *itMS << " ";
	}
	cout << endl << "size= " << vMs.size() << endl << endl;

	vMs = ms.Split(arrChar, true);
	cout << "Split co loai bo empty: " << endl;
	for (vector<MyString>::iterator itMS = vMs.begin(); itMS != vMs.end(); ++itMS) {
		cout << *itMS << " ";
	}
	cout << endl << "size= " << vMs.size() << endl << endl;

	system("pause");
	return 0;
}