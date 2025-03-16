#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

class NHANSU {
	private:
		string mnv, ht, ns;
	public:
		void input() {
			cin.ignore();
			cout << "\nNhap ma nhan su: "; getline(cin,mnv);
			cout << "Nhap ho ten: "; getline(cin,ht);
			cout << "Nhap nam sinh: "; cin >> ns;
		}
		void output() {
			cout << "\n" << left << setw(10) << mnv;
			cout << setw(20) << ht;
			cout << setw(15) << ns;
		}
};

class CANBO : public NHANSU {
	private:
		float hsl;
		int lcb;
	public:
		float tinhLuong() {
			return lcb* hsl;
		}
		void input() {
			NHANSU::input();
			cout << "Nhap luong co ban: "; cin >> lcb;
			cout << "Nhap he so luong: "; cin >> hsl;
			tinhLuong();
		}
		void output() {
			NHANSU::output();
			cout << setw(15) << lcb;
			cout << setw(15) << hsl;
			cout << fixed << setprecision(2) << setw(15) << tinhLuong();
		}
		friend void giamdan(int n, CANBO a[50]) {
			for (int i = 0; i < n-1; i++) {
				for (int j = 1; j < n; j++) {
					if(a[i].tinhLuong() < a[j].tinhLuong()) {
						CANBO temp = a[i];
						a[i] = a[j];
						a[j] = temp;
					}
				}
			}
			for (int i = 0; i < n; i++) {
				a[i].output();
			}
		}
};

void title() {
	cout << "\n" << left << setw(10) << "Ma NS";
	cout << setw(20) << "Ho ten";
	cout << setw(15) << "Nam sinh";
	cout << setw(15) << "Luong CB";
	cout << setw(15) << "HS luong";
	cout << setw(15) << "Luong";
}

main() {
	int n;
	CANBO a[50];
	cout << "NHAP SO LUONG CAN BO: "; cin >> n;
	
	cout << "---------------------";
	cout << "\nNHAP THONG TIN CAN BO\n";
	for (int i = 0; i < n; i++) {
		cout << "--------------";
		cout << "\nCan bo thu " << i+1;
		a[i].input();
	}
	
	cout << "-------------------------";
	cout << "\nHIEN THI THONG TIN CAN BO";
	title();
	for (int i = 0; i < n; i++) {
		a[i].output();
	}
	
	cout << "\n----------------------------------------------------";
	cout << "\nDANH SACH CAN BO THEO THU TU GIAM DAN CUA TIEN LUONG";
	title();
	giamdan(n,a);
	
	getch();
}
