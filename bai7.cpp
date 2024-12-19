#include <iostream>
#include <conio.h>
using namespace std;

class NGUOI {
	private:
		string hoten;
		int maso, luong;
	public:
		void input() {
			cout << "\nNhap ma so: "; cin >> maso;
			fflush(stdin);
			cout << "Nhap ho ten: "; getline(cin,hoten);
			cout << "Nhap luong: "; cin >> luong;
		}
		void output() {
			cout << "\nMa so: " << maso;
			cout << "\nHo ten: " << hoten;
			cout << "\nLuong: " << luong;
		}
};

class BIENCHE:public NGUOI {
	private:
		int pc;
		float hsl;
	public:
		void input1() {
			input();
			cout << "Nhap he so luong: "; cin >> hsl;
			cout << "Nhap tien phu cap chuc vu: "; cin >> pc;
		}
		void output1() {
			output();
			cout << "\nHe so luong: " << hsl;
			cout << "\nTien phu cap chuc vu: " << pc;
		}
};

class HOPDONG:public NGUOI {
	private:
		int tcld, snlv;
		float hsvg;
	public:
		void input2() {
			input();
			cout << "Nhap tien cong lao dong: "; cin >> tcld;
			cout << "Nhap so ngay lam viec: "; cin >> snlv;
			cout << "Nhap he so vuot gio: "; cin >> hsvg;
		}
		void output2() {
			output();
			cout << "\nTien cong lao dong: " << tcld;
			cout << "\nSo ngay lam viec: " << snlv;
			cout << "\nHe so vuot gio: " << hsvg;
		}
};

main() {
	BIENCHE a[10];
	HOPDONG b[10];
	int n, m;
	cout << "Nhap so luong nguoi bien che: "; cin >> n;
	cout << "---------------------------------------\n";
	cout << "NHAP DANH SACH BIEN CHE\n";
	for (int i = 0; i < n; i++) {
		cout << "-----------";
		cout << "\nNguoi thu " << i+1;
		a[i].input1();
	}
	cout << "---------------------------------------\n";
	cout << "Nhap so luong nguoi hop dong: "; cin >> m;
	cout << "---------------------------------------\n";
	cout << "NHAP DANH SACH HOP DONG\n";
	for (int i = 0; i < m; i++) {
		cout << "-----------";
		cout << "\nNguoi thu " << i+1;
		b[i].input2();
	}
	cout << "---------------------------------------\n";
	cout << "DANH SACH NGUOI BIEN CHE";
	for (int i = 0; i < n; i++) {
		cout << "\n-----------";
		cout << "\nNguoi thu " << i+1;
		a[i].output1();
	}
	cout << "\n---------------------------------------\n";
	cout << "DANH SACH NGUOI HOP DONG";
	for (int i = 0; i < m; i++) {
		cout << "\n-----------";
		cout << "\nNguoi thu " << i+1;
		b[i].output2();
	}
	getch();
}
