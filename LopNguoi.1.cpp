#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

class NGUOI {
	private:
		string ht;
		int ns;
	public:
		void input() {
			cout << "\nNhap ho ten: "; cin.ignore(); getline(cin,ht);
			cout << "Nhap nam sinh: "; cin >> ns;
		}
		void output() {
			cout << "\n" << left << setw(20) << ht;
			cout << setw(10) << ns;
		}
		string getHt() {
			return ht;
		}
};

class SINHVIEN : public NGUOI {
	private:
		string msv;
		float dtb;
	public:
		void input() {
			NGUOI::input();
			cout << "Nhap ma sinh vien: "; cin.ignore(); getline(cin,msv);
			cout << "Nhap diem trung binh: "; cin >> dtb;
		}
		void output() {
			NGUOI::output();
			cout << setw(10) << msv;
			cout << setw(10) << dtb;
		}
		float getDtb() {
			return dtb;
		}
		string getMsv() {
			return msv;
		}
};

void title() {
	cout << "\n" << left << setw(20) << "Ho ten";
	cout << setw(10) << "Nam sinh";
	cout << setw(10) << "Ma SV";
	cout << setw(10) << "Diem TB";
}

main() {
	int n;
	SINHVIEN a[50];
	cout << "NHAP SO LUONG SINH VIEN: "; cin >> n;
	
	cout << "------------------------";
	cout << "\nNHAP THONG TIN SINH VIEN\n";
	for (int i = 0; i < n; i++) {
		cout << "Sinh vien thu " << i+1;
		a[i].input();
	}
	
	cout << "-----------------------------------------------------";
	cout << "\nDANH SACH SV THEO THU TU TANG DAN CUA DIEM TRUNG BINH";
	for (int i = 0; i < n-1; i++) {
		for (int j = 1; j < n; j++) {
			if (a[i].getDtb() > a[j].getDtb()) {
				SINHVIEN temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	title();
	for (int i = 0; i < n; i++) {
		a[i].output();
	}
	
	cout << "\n-----------------------------------------------------";
	cout << "\nDANH SACH SV THEO THU TU GIAM DAN CUA DIEM TRUNG BINH";
	for (int i = 0; i < n-1; i++) {
		for (int j = 1; j < n; j++) {
			if (a[i].getDtb() < a[j].getDtb()) {
				SINHVIEN temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	title();
	for (int i = 0; i < n; i++) {
		a[i].output();
	}
	
	cout << "\n---------------------------------------------------------";
	bool find = false;
	string tk;
	cout << "\nNHAP MA SINH VIEN HOAC TEN SINH VIEN CAN TIM KIEM: "; cin.ignore(); getline(cin,tk);
	for (int i = 0; i < n; i++) {
		if (tk == a[i].getHt() || tk == a[i].getMsv()) {
			a[i].output();
			find = true;
			break;
		}
	}
	if (!find) {
		cout << "Khong tim thay sinh vien!";
	}
	
	getch();
}
