#include "HHP.h"

HinhHocPhang::HinhHocPhang() {
	dienTich = chuVi = 0;
}

HinhHocPhang::HinhHocPhang(const HinhHocPhang& hhp) {
	dienTich = hhp.dienTich;
	chuVi = hhp.chuVi;
}

HinhHocPhang::~HinhHocPhang() {}

double HinhHocPhang::getDienTich() const {
	return dienTich;
}

double HinhHocPhang::getChuVi() const {
	return chuVi;
}

void HinhHocPhang::capNhatDienTichVaChuVi() {
	dienTich = tinhDienTich();
	chuVi = tinhChuVi();
}

istream& operator>>(istream& is, HinhHocPhang& hhp) {
	hhp.nhap(is);
	return is;
}

ostream& operator<<(ostream& os, const HinhHocPhang& hhp) {
	hhp.xuat(os);
	return os;
}

// HINHCHUNHAT
HinhChuNhat::HinhChuNhat() {
	chieuDai = 0;
	chieuRong = 0;
	capNhatDienTichVaChuVi();
	slHinhChuNhat++;
}

HinhChuNhat::HinhChuNhat(double cd, double cr) {
	chieuDai = cd;
	chieuRong = cr;
	capNhatDienTichVaChuVi();
	slHinhChuNhat++;
}

HinhChuNhat::HinhChuNhat(const HinhChuNhat& hcn) {
	chieuDai = hcn.chieuDai;
	chieuRong = hcn.chieuRong;
	capNhatDienTichVaChuVi();
	slHinhChuNhat++;
}

double HinhChuNhat::tinhDienTich() const {
	return chieuDai * chieuRong;
}

double HinhChuNhat::tinhChuVi() const {
	return (chieuDai + chieuRong) * 2;
}

void HinhChuNhat::nhap(istream& is) {
	cout << "Nhap chieu dai: ";
	is >> chieuDai;
	cout << "Nhap chieu rong: ";
	is >> chieuRong;
	capNhatDienTichVaChuVi();
}

void HinhChuNhat::xuat(ostream& os) const {
	os << "Hinh Chu Nhat: Chieu Dai = " << chieuDai << ", Chieu Rong = " << chieuRong << endl;
	os << "Dien Tich = " << dienTich << ", Chu Vi = " << chuVi << endl;
}

int HinhChuNhat::getSoLuongHinhChuNhat() {
	return slHinhChuNhat;
}

// HINHTRON
HinhTron::HinhTron() {
	banKinh = 0;
	capNhatDienTichVaChuVi();
	slHinhTron++;
}

HinhTron::HinhTron(double r) {
	banKinh = r;
	capNhatDienTichVaChuVi();
	slHinhTron++;
}

HinhTron::HinhTron(const HinhTron& ht) {
	banKinh = ht.banKinh;
	capNhatDienTichVaChuVi();
	slHinhTron++;
}

double HinhTron::tinhDienTich() const {
	return PI * banKinh * banKinh;
}

double HinhTron::tinhChuVi() const {
	return 2 * PI * banKinh;
}

void HinhTron::nhap(istream& is) {
	cout << "Nhap ban kinh: ";
	is >> banKinh;
	capNhatDienTichVaChuVi();
}

void HinhTron::xuat(ostream& os) const {
	os << "Hinh Tron: Ban Kinh = " << banKinh << endl;
	os << "Dien Tich = " << dienTich << ", Chu Vi = " << chuVi << endl;
}

int HinhTron::getSoLuongHinhTron() {
	return slHinhTron;
}

// HINHTAMGIAC
HinhTamGiac::HinhTamGiac() {
	a = b = c = 0;
	capNhatDienTichVaChuVi();
	slHinhTamGiac++;
}

HinhTamGiac::HinhTamGiac(double c1, double c2, double c3) {
	a = c1;
	b = c2;
	c = c3;
	capNhatDienTichVaChuVi();
	slHinhTamGiac++;
}

HinhTamGiac::HinhTamGiac(const HinhTamGiac& htg) {
	a = htg.a;
	b = htg.b;
	c = htg.c;
	capNhatDienTichVaChuVi();
	slHinhTamGiac++;
}

// Dung cong thuc Heron
double HinhTamGiac::tinhDienTich() const {
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

double HinhTamGiac::tinhChuVi() const {
	return a + b + c;
}

void HinhTamGiac::nhap(istream& is) {
	cout << "Nhap 3 canh: ";
	is >> a >> b >> c;
	capNhatDienTichVaChuVi();
}

void HinhTamGiac::xuat(ostream& os) const {
	os << "Hinh Tam Giac: Canh 1 = " << a << ", Canh 2 = " << b << ", Canh 3 = " << c << endl;
	os << "Dien Tich = " << dienTich << ", Chu Vi = " << chuVi << endl;
}

int HinhTamGiac::getSoLuongHinhTamGiac() {
	return slHinhTamGiac;
}

// HINHTHANGVUONG
HinhThangVuong::HinhThangVuong() {
	dayLon = dayBe = chieuCao = 0;
	capNhatDienTichVaChuVi();
	slHinhThangVuong++;
}

HinhThangVuong::HinhThangVuong(const double& dl, const double& db, const double& cc) {
	dayLon = dl;
	dayBe = db;
	chieuCao = cc;
	capNhatDienTichVaChuVi();
	slHinhThangVuong++;
}

HinhThangVuong::HinhThangVuong(const HinhThangVuong& htv) {
	dayLon = htv.dayLon;
	dayBe = htv.dayBe;
	chieuCao = htv.chieuCao;
	capNhatDienTichVaChuVi();
	slHinhThangVuong++;
}

double HinhThangVuong::tinhDienTich() const {
	return ((dayLon + dayBe) * chieuCao) / 2;
}

double HinhThangVuong::tinhChuVi() const {
	return (dayLon + dayBe) * 2;
}

void HinhThangVuong::nhap(istream& is) {
	cout << "Nhap day lon, day be, chieu cao theo thu tu: ";
	is >> dayLon >> dayBe >> chieuCao;
	capNhatDienTichVaChuVi();
}

void HinhThangVuong::xuat(ostream& os) const {
	os << "Hinh Thang Vuong: Day Lon = " << dayLon << ", Day Be = " << dayBe << ", Chieu Cao = " << chieuCao << endl;
	os << "Dien Tich = " << dienTich << ", Chu Vi = " << chuVi << endl;
}

int HinhThangVuong::getSoLuongHinhThangVuong() {
	return slHinhThangVuong;
}

// Khoi tao bien static
int HinhChuNhat::slHinhChuNhat = 0;
int HinhTron::slHinhTron = 0;
int HinhTamGiac::slHinhTamGiac = 0;
int HinhThangVuong::slHinhThangVuong = 0;