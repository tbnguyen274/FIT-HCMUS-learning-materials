#include "CString.h"

int main() {
	srand((unsigned int)time(NULL));
	const int maxV = 1000, iTest = 2;
	int n = 5 + rand() % 10;
	LinkedList<int> ll;
	for (int i = 0; i < n; i++) {
		if (rand() % 2 == 0) {
			ll.AddHead(rand() % maxV);
		}
		else {
			ll.AddTail(rand() % maxV + maxV);
		}
	}
	cout << ll << endl;
	ll[iTest] = -123;
	ll[iTest + 2] = 9876;
	ll.RemoveHead();
	ll.RemoveTail();
	cout << "Sau thay doi: " << endl;
	cout << ll << endl;

	LinkedList<CString> llCS;
	llCS.AddTail(CString("cstring-1"));
	llCS.AddTail(CString("cstring-2"));
	llCS.AddTail(CString("cstring-3"));
	cout << "List Cstring: " << llCS << endl;
	llCS[iTest] = CString("new CString");
	cout << "List CString changed: " << endl << llCS << endl;
	system("pause");
	return 0;
}