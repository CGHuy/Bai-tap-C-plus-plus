#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

class Sinhvien {
	private:
		string msv, ht, ml;
	public:
		void input() {
			cout << "\nNhap ma sinh vien: "; fflush(stdin); getline(cin,msv);
			cout << "Nhap ho ten: "; fflush(stdin); getline(cin,ht);
			cout << "Nhap ma lop: "; fflush(stdin); getline(cin,ml);
		}
		void output() {
			cout << "\n" << left << setw(10) << msv;
			cout << left << setw(20) << ht;
			cout << left << setw(10) << ml;
		}
};

class SinhvienK74 : public Sinhvien {
	private:
		string mmh;
		float diemCC, diemKT, diemthi, HP;
	public:
		void input1() {
			input();
			cout << "Nhap ma mon hoc: "; fflush(stdin); getline(cin,mmh);
			cout << "Nhap diem chuyen can: "; cin >> diemCC;
			cout << "Nhap diem kiem tra: "; cin >> diemKT;
			cout << "Nhap diem thi: "; cin >> diemthi;
		}
		void output1() {
			output();
			cout << left << setw(10) << mmh;
			cout << setw(10) << diemCC;
			cout << setw(10) << diemKT;
			cout << setw(10) << diemthi;
			cout << setw(10) << diemHP();
		}
		float diemHP() {
			HP = (diemCC*0.1 + diemKT*0.3 + diemthi*0.6);
			return HP;
		}
};

void title() {
	cout << "\n" << left << setw(10) << "Ma SV";
	cout << left << setw(20) << "Ho ten";
	cout << left << setw(10) << "Ma lop";
	cout << left << setw(10) << "Ma MH";
	cout << setw(10) << "Diem CC";
	cout << setw(10) << "Diem KT";
	cout << setw(10) << "Diem thi";
	cout << setw(10) << "Diem HP";
}

main() {
	// khai bao
	SinhvienK74 a[10];
	int n;
	// nhap so luong
	cout << "NHAP SO LUONG SINH VIEN: "; cin >> n;
	// nhap thong tin
	cout << "-----------------------------------------";
	cout << "\nNHAP THONG TIN SINH VIEN";
	for (int i = 0; i < n; i++) {
		cout << "\nSinh vien thu " << i+1;
		a[i].input1();
	}
	// in thong tin
	cout << "-----------------------------------------";
	cout << "\nIN THONG TIN SINH VIEN";
	title();
	for (int i = 0; i < n; i++) {
		a[i].output1();
	}
	// tim max
	cout << "\n-----------------------------------------";
	cout << "\nSINH VIEN CO DIEM HOC PHAN CAO NHAT";
	title();
	SinhvienK74 max = a[0];
	for (int i = 0; i < n; i++) {
		if (a[i].diemHP() > max.diemHP()) {
			max = a[i];
		}
	}
	max.output1();
	// sap xep giam dan
	cout << "\n-----------------------------------------";
	cout << "\nSAP XEP THEO DIEM HOC PHAN GIAM DAN";
	title();
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (a[i].diemHP() < a[j].diemHP()) {
				SinhvienK74 temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		a[i].output1();
	}
	getch();
}

// Cao Giang Huy 
