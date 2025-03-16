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

class CONGNHAN : public NHANSU {
	private:
		int ngaycong;
	public:
		void input() {
			NHANSU::input();
			cout << "Nhap ngay cong: "; cin >> ngaycong;
		}
		void output() {
			NHANSU::output();
			cout << setw(15) << ngaycong;
			cout << setw(15) << tinhThuong();
		}
		int tinhThuong() {
			if (ngaycong > 26) {
				return (ngaycong-26) * 100000;
			} else {
				return 0;
			}
		}
		int getNgaycong() {
			return ngaycong;
		}
};

void title() {
	cout << "\n" << left << setw(10) << "Ma NS";
	cout << setw(20) << "Ho ten";
	cout << setw(15) << "Ngay sinh";
	cout << setw(15) << "Ngay cong";
	cout << setw(15) << "Tien thuong";
}

main() {
	int n;
	CONGNHAN a[50];
	cout << "NHAP SO CONG NHAN: "; cin >> n;
	
	cout << "------------------------";
	cout << "\nNHAP THONG TIN CONG NHAN\n";
	for (int i = 0; i < n; i++) {
		cout << "------------------";
		cout << "\nCong nhan thu " << i+1;
		a[i].input();
	}
	
	cout << "----------------------------";
	cout << "\nHIEN THI THONG TIN CONG NHAN";
	title();
	for (int i = 0; i < n; i++) {
		a[i].output();
	}
	
	cout << "\n-----------------------------------";
	cout << "\nDANH SACH CAC CONG NHAN DUOC THUONG";
	title();
	for (int i = 0; i < n; i++) {
		if (a[i].getNgaycong() > 26) {
			a[i].output();
		}
	}
	
	getch();
}
