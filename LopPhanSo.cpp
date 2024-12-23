#include <iostream>
#include <conio.h>
using namespace std;

class PS1 {
	protected:
		int t, m;
	public:
		PS1() {
			t = 0;
			m = 1;
		}
		PS1(int a, int b) {
			t = a;
			m = b;
		}
		~PS1() {
			t = 0;
			m = 1;
		}
		friend istream& operator >> (istream& is, PS1 &a) {
			cout << "\nNhap tu so: "; is >> a.t;
			cout << "Nhap mau so: "; is >> a.m;
			return is;
		}
		friend ostream& operator << (ostream& os, PS1 a) {
			os << a.t << "/" << a.m;
			return os;
		}
		PS1 rutgon() {
			PS1 rutgon;
			rutgon.t = t / ucln(t,m);
			rutgon.m = m / ucln(t,m);
			return rutgon;
		}
		PS1 operator + (PS1 a) {
			PS1 tong;
			tong.t	= t*a.m + a.t*m;
			tong.m = m*a.m;
			return tong;
		}
		PS1 operator - (PS1 a) {
			PS1 hieu;
			hieu.t = t*a.m - a.t*m;
			hieu.m = m*a.m;
			return hieu;
		}
		PS1 operator * (PS1 a) {
			PS1 tich;
			tich.t = t*a.t;
			tich.m = m*a.m;
			return tich;
		}
		PS1 operator / (PS1 a) {
			PS1 thuong;
			thuong.t = t*a.m;
			thuong.m = m*a.t;
			return thuong;
		}
};

int ucln(int t, int m) {
	while (m != 0) {
		int temp = m;
		m = t % m;
		t = temp;
	}
	return t;
}

class PS2 : public PS1 {
	public:
		PS2 operator = (PS2 a) {
			this->t = a.t;
			this->m = a.m;
			return *this;
		}
		int operator > (PS2 a) {
			if (t*a.m > a.t*m) return 1;
			else return 0;
		}
		int operator < (PS2 a) {
			if (t*a.m < a.t*m) return 1;
			else return 0;
		}
};

main() {
	PS2 a[10];
	int n;
	cout << "NHAP SO LUONG PHAN SO: "; cin >> n;
	// Nhap phan so
	cout << "----------------------------";
	cout << "\nNHAP PHAN SO\n";
	for (int i = 0; i < n; i++) {
		cout << "-----------------";
		cout << "\nPhan so thu " << i+1;
		cin >> a[i];
	}
	// In phan so
	cout << "----------------------------";
	cout << "\nIN PHAN SO";
	for (int i = 0; i < n; i++) {
		cout << "\nPhan so thu " << i+1 << " la ";
		cout << a[i].rutgon();
	}
	// Phan so lon nhat, nho nhat
	PS2 max = a[0];
	PS2 min = a[0];
	for (int i = 0; i < n; i++) {
		if (max < a[i]) {
			max = a[i];
		}
		if (min > a[i]) {
			min = a[i];
		}
	}
	cout << "\n----------------------------";
	cout << "\nPHAN SO LON NHAT LA: " << max.rutgon();
	cout << "\nPHAN SO NHO NHAT LA: " << min.rutgon();
	// Sap xep phan so theo thu tu tang dan, giam dan
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (a[i] > a[j]) {
				PS2 temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	cout << "\nSAP XEP THEO THU TU TANG DAN: ";
	for (int i = 0; i < n; i++) {
		cout << a[i].rutgon() << " ";
	}
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (a[i] < a[j]) {
				PS2 temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	cout << "\nSAP XEP THEO THU TU GIAM DAN: ";
	for (int i = 0; i < n; i++) {
		cout << a[i].rutgon() << " ";
	}
	// Tinh tong
	PS1 tong;
	for (int i = 0; i < n; i++) {
		tong = tong + a[i];
	}
	cout << "\nTONG DAY PHAN SO LA: " << tong.rutgon();
	getch();
}
