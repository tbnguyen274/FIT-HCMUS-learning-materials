#include "lib.h"

int main() {
	int data[] = { 1, 2, 3, 4, 5 };

	Array a1;
	Array a2(5);
	Array a3(data, 5);
	Array a4(a3);

	a1.print();
	a2.print();
	a3.print();
	a4.print();

	return 0;
}