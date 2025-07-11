#ifndef SONGUYENLON_H 
#define SONGUYENLON_H

#include "LinkedList.h"

using namespace std;

class SoNguyenLon {
private:
	LinkedList<int> _list;
	int _size;
	static int countDigit(const int&);

public:
	SoNguyenLon();
	SoNguyenLon(const int&);
	SoNguyenLon(const int&, const int&);
	SoNguyenLon(const SoNguyenLon&);
	~SoNguyenLon();

	SoNguyenLon operator-(const SoNguyenLon&);
	friend SoNguyenLon operator-(const int&, const SoNguyenLon&);
	SoNguyenLon operator+(const SoNguyenLon&);
	friend SoNguyenLon operator+(const int&, const SoNguyenLon&);
	SoNguyenLon operator*(const SoNguyenLon&);

	friend ostream& operator<<(ostream&, const SoNguyenLon&);
};

#endif SONGUYENLON_H
