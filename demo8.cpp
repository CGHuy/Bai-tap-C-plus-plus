#include <iostream>
#include <conio.h>
using namespace std;

class ps {
	private:
		int tu, mau;
	public:
		ps() {
			tu = 0;
			mau = 1;
		}
		ps(int tu, int mau) {
			this->tu = tu;
			this->mau = mau;
		}
		friend istream& operator >> (istream& is, ps& a);
		friend ostream& operator << (ostream& os, ps a);
		ps operator + (ps a);
		ps operator - (ps a);
		ps operator * (ps a);
		ps operator / (ps a);		 
};

istream& operator >> (istream& is, ps& a) {
	cout << "\nNhap tu so: "; is >> a.tu;
	do {
		cout << "Nhap mau so: "; is >> a.mau;
		if (a.mau == 0) {
			cout << "Mau so phai khac 0. Vui long nhap lai!\n";
		}
	} while (a.mau == 0);
	return is;
}

ostream &operator << (ostream &os, ps a) {
	os << a.tu << "/" << a.mau;
	return os;
}

ps ps::operator + (ps a) {
	ps tong;
	tong.tu = tu*a.mau + mau*a.tu;
	tong.mau = mau*a.mau;
	return tong;
}

ps ps::operator - (ps a) {
	ps hieu;
	hieu.tu = tu*a.mau - a.tu*mau;
	hieu.mau = mau*a.mau;
	return hieu;
}

ps ps::operator * (ps a) {
	ps tich;
	tich.tu = tu*a.tu;
	tich.mau = mau*a.mau;
	return tich;
}

ps ps::operator / (ps a) {
	ps thuong;
	thuong.tu = tu*a.mau;
	thuong.mau = mau*a.tu;
	return thuong;
}

main () {
	ps a[10], tong, tich(1,1);
	int n;
	cout << "Nhap so luong phan so: "; cin >> n;
	cout << "-------------------------\n";
	for (int i = 0; i < n; i++) {
		cout << "Phan so thu " << i+1; cin >> a[i];
	}
	cout << "-------------------\n";
	cout << "DANH SACH PHAN SO";
	for (int i = 0; i < n; i++) {
		cout << "\nPhan so thu " << i+1 << " la: " << a[i];
	}
//Tong
	cout << "\n-----------------\n";
	for (int i = 0; i < n; i++) {
		tong = tong + a[i];
	}
	cout << "Tong la: " << tong;
//Hieu
	cout << "\n-----------------\n";
	ps hieu = a[0];
	for (int i = 1; i < n; i++) {
		hieu = hieu - a[i];
	}
	cout << "Hieu la: " << hieu;
//Tich
	cout << "\n-----------------\n";
	for (int i = 0; i < n; i++) {
		tich = tich * a[i];
	}
	cout << "Tich la: " << tich;
//Thuong
	cout << "\n-----------------\n";
	ps thuong = a[0];
	for (int i = 1; i < n; i++) {
		thuong = thuong / a[i];
	}
	cout << "Thuong la: " << thuong;
	getch();
}
