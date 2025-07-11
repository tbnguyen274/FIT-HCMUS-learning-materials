#include "SoNguyenLon.h"

void SoNguyenLon::Pow10(const int& n) {
	for (int i = 0; i < n; i++) {
		lCS.insert(lCS.begin(), 0);
	}
}

SoNguyenLon::SoNguyenLon(void) {
	lCS.push_back(0);
}

SoNguyenLon::SoNguyenLon(const int& cs, const int& scs) {
	int csR = cs;
	if (csR < 1) {
		csR = 1;
	}
	if (csR > 9) {
		csR = 9;
	}
	int soCS = abs(scs);
	if (soCS < 1) {
		soCS = 1;
	}
	for (int i = 0; i < soCS; i++) {
		lCS.push_back(csR);
	}
}

SoNguyenLon::SoNguyenLon(const unsigned long& n) {
	unsigned long temp = n;
	while (temp > 0) {
		lCS.push_back(temp % 10);
		temp /= 10;
	}
}

SoNguyenLon::SoNguyenLon(const SoNguyenLon& snl) {
	lCS = snl.lCS;
}

SoNguyenLon::SoNguyenLon(const char* s) {
	int n = strlen(s);
	for (int i = n - 1; i >= 0; i--) {
		lCS.push_back(s[i] - '0');
	}
}

SoNguyenLon::~SoNguyenLon(void) {
}

int SoNguyenLon::SoCS() {
	return lCS.size();
}

bool SoNguyenLon::operator>(SoNguyenLon& snl) {
	if (lCS.size() > snl.lCS.size()) {
		return true;
	}
	if (lCS.size() < snl.lCS.size()) {
		return false;
	}
	for (int i = lCS.size() - 1; i >= 0; i--) {
		if (lCS[i] == snl.lCS[i]) {
			continue;
		}
		if (lCS[i] > snl.lCS[i]) {
			return true;
		}
		return false;
	}
	return false;
}

const SoNguyenLon& SoNguyenLon::operator=(const SoNguyenLon& snl) {
	lCS = snl.lCS;
	return *this;
}

SoNguyenLon& SoNguyenLon::operator+=(SoNguyenLon snl) {
	*this = *this + snl;
	return *this;
}

SoNguyenLon SoNguyenLon::operator+(SoNguyenLon snl) {
	SoNguyenLon snlKQ;
	snlKQ.lCS.clear();
	SoNguyenLon* snlSCSMax = (SoCS() > snl.SoCS()) ? this : &snl;
	SoNguyenLon* snlSCSMin = (SoCS() < snl.SoCS()) ? this : &snl;
	int nho = 0, temp;

	for (int i = 0; i < snlSCSMin->SoCS(); ++i) {
		temp = lCS[i] + snl.lCS[i] + nho;
		snlKQ.lCS.push_back(temp % 10);
		nho = temp / 10;
	}

	for (int i = snlSCSMin->SoCS(); i < snlSCSMax->SoCS(); ++i) {
		temp = snlSCSMax->lCS[i] + nho;
		snlKQ.lCS.push_back(temp % 10);
		nho = temp / 10;
	}

	if (nho > 0) {
		snlKQ.lCS.push_back(nho);
	}

	return snlKQ;
}

SoNguyenLon SoNguyenLon::operator-(SoNguyenLon snl) {
	if (snl > *this) {
		return SoNguyenLon();
	}

	SoNguyenLon snlKQ;
	snlKQ.lCS.clear();
	int nho = 0, temp;

	for (int i = 0; i < snl.SoCS(); ++i) {
		temp = lCS[i] - snl.lCS[i] - nho;
		if (temp < 0) {
			temp += 10;
			nho = 1;
		}
		else {
			nho = 0;
		}
		snlKQ.lCS.push_back(temp);
	}

	for (int i = snl.SoCS(); i < SoCS(); ++i) {
		temp = lCS[i] - nho;
		if (temp < 0) {
			temp += 10;
			nho = 1;
		}
		else {
			nho = 0;
		}
		snlKQ.lCS.push_back(temp);
	}

	while (snlKQ.lCS.size() > 1 && snlKQ.lCS.back() == 0) {
		snlKQ.lCS.pop_back();
	}

	return snlKQ;
}

SoNguyenLon SoNguyenLon::operator*(SoNguyenLon snl) {
	SoNguyenLon snlKQ, * psnlTemp;
	SoNguyenLon* snlSCSMax = (SoCS() > snl.SoCS()) ? this : &snl;
	SoNguyenLon* snlSCSMin = (SoCS() < snl.SoCS()) ? this : &snl;
	int nho = 0, temp;

	for (int i = 0; i < snlSCSMin->SoCS(); i++) {
		psnlTemp = new SoNguyenLon;
		psnlTemp->lCS.clear();
		nho = 0;

		for (int j = 0; j < snlSCSMax->SoCS(); j++) {
			temp = snlSCSMin->lCS[i] * snlSCSMax->lCS[j] + nho;
			psnlTemp->lCS.push_back(temp % 10);
			nho = temp / 10;
		}

		if (nho > 0) {
			psnlTemp->lCS.push_back(nho);
		}

		psnlTemp->Pow10(i);
		snlKQ += *psnlTemp;
		delete psnlTemp;
	}

	return snlKQ;
}

SoNguyenLon operator+(const unsigned int& n, const SoNguyenLon& snl) {
	SoNguyenLon snlTemp(n);
	return snlTemp + snl;
}

SoNguyenLon operator-(const unsigned int& n, const SoNguyenLon& snl) {
	SoNguyenLon snlTemp(n);
	return snlTemp - snl;
}

ostream& operator<<(ostream& os, const SoNguyenLon& snl) {
	for (int i = snl.lCS.size() - 1; i >= 0; i--) {
		os << (int)snl.lCS[i];
	}
	return os;
}