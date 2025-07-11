#include "lib.h"

int main() {
	Array arr1(10);
	cin >> arr1;
	cout << arr1 << endl;

	// histogram of arr1
	HistogramArray histArr1(arr1);
	histArr1.displayHistogram();

}