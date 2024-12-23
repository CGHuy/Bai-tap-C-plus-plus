#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;

class SP1 {
	protected:
		float pt, pa;
	public:
		SP1() {
			pt = 0;
			pa = 0;
		}
		SP1(float a, float b) {
			pt = a;
			pa = b;
		}
		~SP1() {
			pt = 0;
			pa = 0;
		}
		friend istream& operator >> (istream &is, SP1 &a) {
			cout << "\nNhap phan thuc: "; is >> a.pt;
			cout << "Nhap phan ao: "; is >> a.pa;
		}
		friend ostream& operator << (ostream &os, SP1 a) {
			os << a.pt << ((a.pa >= 0) ? "+" : "") << a.pa << "i";
		}
		float module() {
			return sqrt(pt * pt + pa * pa);
		}
		SP1 operator + (SP1 a) {
			SP1 tong;
			tong.pt = pt + a.pt;
			tong.pa = pa + a.pa;
			return tong;
		}
		SP1 operator - (SP1 a) {
			SP1 hieu;
			hieu.pt = pt - a.pt;
			hieu.pa = pa - a.pa;
			return hieu;
		}
		SP1 operator * (SP1 a) {
			SP1 tich;
			tich.pt = pt * a.pt - pa * a.pa;
			tich.pa = pt * a.pa + pa * a.pt;
			return tich;
		}
		SP1 operator / (SP1 a) {
			float sbc = a.pt * a.pt + a.pa * a.pa;
			SP1 thuong;
			thuong.pt = (pt * a.pt + pa * a.pa) / sbc;
			thuong.pa = (pa * a.pt - pt * a.pa) / sbc;
			return thuong;
		}
};

class SP2 : public SP1 {
	public:
		SP2 &operator = (SP2 a) {
			this->pt = a.pt;
			this->pa = a.pa;
			return *this;
		}
		int operator > (SP2 a) {
			if (this->module() > a.module())
			return 1;
			else return 0;
		}
		int operator < (SP2 a) {
			if (this->module() < a.module())
			return 1;
			else return 0;
		}
		int operator == (SP2 a) {
			if (this->module() == a.module())
			return 1;
			else return 0;
		}
};

main() {
	SP2 a[10];
	int n;
	cout << "NHAP SO LUONG SO PHUC: "; cin >> n;
	// Nhap so phuc
	cout << "----------------------------\n";
	cout << "NHAP SO PHUC\n";
	for (int i = 0; i < n; i++) {
		cout << "----------------";
		cout << "\nSo phuc thu " << i+1 << " la ";
		cin >> a[i];
	}
	// In so phuc
	cout << "----------------------------\n";
	cout << "IN SO PHUC";
	for (int i = 0; i < n; i++) {
		cout << "\nSo phuc thu " << i+1 << " la ";
		cout << a[i];
	}
	// Sap xep theo module
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if ( a[i] > a[j]) {
				SP2 temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	cout << "\n----------------------------";
	cout << "\nSAP XEP THEO THU TU TANG DAN ";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if ( a[i] < a[j]) {
				SP2 temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	cout << "\nSAP XEP THEO THU TU GIAM DAN ";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	// Max, min
	SP2 max = a[0];
	SP2 min = a[0];
	for (int i = 0; i < n; i++) {
		if (max < a[i]) {
			max = a[i];
		}
		if (min > a[i]) {
			min = a[i];
		}
	}
	cout << "\nSO PHUC LON NHAT LA " << max;
	cout << "\nSO PHUC NHO NHAT LA " << min;
	
	getch();
}
