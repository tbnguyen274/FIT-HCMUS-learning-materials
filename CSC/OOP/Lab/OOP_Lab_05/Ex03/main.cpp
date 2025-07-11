#include "SoNguyenLon.h"
using namespace std;

int main() {
	const int iTest = 78912;
	SoNguyenLon snl1(123);
	SoNguyenLon snl2(40000);
	cout << snl1 << " + " << snl2 << " = ";
	cout << (snl1 + snl2) << endl;
	cout << snl1 << " * " << snl2 << " = ";
	cout << (snl1 * snl2) << endl;
	cout << snl1 << " - " << snl2 << " = ";
	cout << (snl1 - snl2) << endl;
	cout << snl2 << " - " << snl1 << " = ";
	cout << (snl2 - snl1) << endl;
	cout << iTest << " - " << snl2 << " = ";
	cout << (iTest - snl2) << endl;
	return 0;
}