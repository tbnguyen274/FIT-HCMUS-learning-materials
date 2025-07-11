#include "SoNguyenLon.h"

int main() {
	SoNguyenLon snl1;
	SoNguyenLon snl2(44667733);
	SoNguyenLon snl3(5, 9);
	SoNguyenLon snl4(7, 30);
	SoNguyenLon snl5 = snl3 - snl2;
	SoNguyenLon snl6 = 1098765432 - snl2;
	SoNguyenLon snl7 = snl4 - snl3 + 123456789;
	SoNguyenLon snl8 = snl2 * snl3;

	cout << snl1 << endl << snl2 << endl << snl3 << endl;
	cout << snl4 << endl << snl5 << endl << snl6 << endl;
	cout << snl7 << endl << snl8 << endl << endl;
	system("pause");
	return 0;
}