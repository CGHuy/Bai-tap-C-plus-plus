#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

class CANBO {
	private:
		string mcb, mdv, ht, ns;
	public:
		void input() {
			cout << "\nNhap ma can bo: "; cin.ignore(); getline(cin,mcb);
			cout << "Nhap ma don vi: "; getline(cin,mdv);
			cout << "Nhap ho ten: "; getline(cin,ht);
			cout << "Nhap nam sinh: "; cin >> ns;
		}
		void output() {
			cout << "\n" << left << setw(10) << mcb;
			cout << setw(10) << mdv;
			cout << setw(20) << ht;
			cout << setw(10) << ns;
		}
};

class LUONG : public CANBO {
	private:
		int pc, bh;
		float hsl;
	public:
		void input() {
			CANBO::input();
			cout << "Nhap phu cap: "; cin >> pc;
			cout << "Nhap he so luong: "; cin >> hsl;
			cout << "Nhap bao hiem: "; cin >> bh;
		}
		float tinhLuong() {
			return hsl*290000+pc-bh;
		}
		void output() {
			CANBO::output();
			cout << setw(10) << pc;
			cout << setw(10) << hsl;
			cout << setw(10) << bh;
			cout << fixed << setprecision(2) << setw(15) << tinhLuong();
		}
};

void title() {
	cout << "\n" << left << setw(10) << "MCB";
	cout << setw(10) << "MDV";
	cout << setw(20) << "Ho ten";
	cout << setw(10) << "Nam sinh";
	cout << setw(10) << "Phu cap";
	cout << setw(10) << "HSL";
	cout << setw(10) << "Bao hiem";
	cout << setw(15) << "Luong";
}

main() {
	int n;
	LUONG a[50];
	cout << "NHAP SO LUONG CAN BO: "; cin >> n;
	
	cout << "----------------------------";
	cout << "\nNHAP THONG TIN CAN BO\n";
	for (int i = 0; i < n; i++) {
		cout << "---------------------";
		cout << "\nCan bo thu " << i+1;
		a[i].input();
	}
	
	cout << "----------------------------";
	cout << "\nHIEN THI THONG TIN CAN BO";
	title();
	for (int i = 0; i < n; i++) {
		a[i].output();
	}
	
	getch();
}
