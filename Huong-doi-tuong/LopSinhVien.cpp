#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

class SINHVIEN {
	private:
		string ht;
		int ns;
		float diem[5];
	public:
		void input() {
			cout << "\nNhap ho ten: "; cin.ignore(); getline(cin,ht);
			cout << "Nhap nam sinh: "; cin >> ns;
			cout << "Nhap diem 5 mon\n";
			for (int i = 0; i < 5; i++) {
				cout << "Diem thu " << i+1 << ": "; cin >> diem[i];
			}
		}
		void output() {
			cout << "\n" << left << setw(20) << ht;
			cout << setw(10) << ns;
			cout << setw(10) << diem[0];
			cout << setw(10) << diem[1];
			cout << setw(10) << diem[2];
			cout << setw(10) << diem[3];
			cout << setw(10) << diem[4];
			cout << setw(10) << dtb();
		}
		void output1() {
			cout << "\n" << left << setw(20) << ht;
			cout << setw(10) << ns;
			cout << setw(10) << doiDiem(diem[0]);
			cout << setw(10) << doiDiem(diem[1]);
			cout << setw(10) << doiDiem(diem[2]);
			cout << setw(10) << doiDiem(diem[3]);
			cout << setw(10) << doiDiem(diem[4]);
		}
		float dtb() {
			float tong = 0;
			for (int i = 0; i < 5; i++) {
				tong += diem[i];
			}
			return tong/5;
		}
		void checkThilai() {
			for (int i = 0; i < 5; i ++) {
				if (diem[i] < 5) {
					cout << "\n" << left << setw(20) << ht;
					cout << setw(10) << ns; 
					cout << "Thi lai mon thu " << i+1 << " voi diem: " << diem[i];
				}
			}
		}
		bool checkDiem() {
			for (int i = 0; i < 5; i++) {
				if (diem[i] < 5) {
					return false;
				}
			}
			return true;
		}
		string doiDiem(float diem) {
			if (diem >= 8.5) return "A";
			else if (diem >= 8) return "B+";
			else if (diem >= 7) return "B";
			else if (diem >= 6) return "C+";
			else if (diem >= 5.5) return "C";
			else if (diem >= 5) return "D+";
			else if (diem >= 4) return "D";
			else return "F";
		}
};

void title() {
	cout << "\n" << left << setw(20) << "Ho Ten";
	cout << setw(10) << "Nam Sinh";
	cout << setw(10) << "Mon 1";
	cout << setw(10) << "Mon 2";
	cout << setw(10) << "Mon 3";
	cout << setw(10) << "Mon 4";
	cout << setw(10) << "Mon 5";
	cout << setw(10) << "Diem TB";
}

void title1() {
	cout << "\n" << left << setw(20) << "Ho Ten";
	cout << setw(10) << "Nam Sinh";
	cout << setw(10) << "Mon 1";
	cout << setw(10) << "Mon 2";
	cout << setw(10) << "Mon 3";
	cout << setw(10) << "Mon 4";
	cout << setw(10) << "Mon 5";
}

main() {
	SINHVIEN a[50];
	int n;
	cout << "NHAP SO LUONG SINH VIEN: "; cin >> n;
	
	cout << "---------------------------------------------------";
	cout << "\nNHAP THONG TIN SINH VIEN\n";
	for (int i=0; i<n; i++) {
		cout << "---------------";
		cout << "\nSinh vien thu " << i+1;
		a[i].input();
	}
	
	cout << "---------------------------------------------------";
	cout << "\nDANH SACH SINH VIEN THI LAI VA MON TUONG UNG";
	for (int i=0; i<n; i++) {
		a[i].checkThilai();
	}
	
	cout << "\n---------------------------------------------------";
	cout << "\nDANH SACH SINH VIEN PHAI THI TOT NGHIEP";
	title();
	for (int i = 0; i < n; i++) {
		if (a[i].dtb() < 7 && a[i].checkDiem()) {
			a[i].output();
		}
	}
	
	cout << "\n---------------------------------------------------";
	cout << "\nDANH SACH SINH VIEN PHAI LAM DO AN TOT NGHIEP";
	title();
	for (int i = 0; i < n; i++) {
		if (a[i].dtb() >= 7 && a[i].checkDiem()) {
			a[i].output();
		}
	}
	
	cout << "\n---------------------------------------------------";
	cout << "\nDANH SACH DIEM CHU HE 4 CUA SINH VIEN";
	title1();
	for (int i = 0; i < n; i++) {
		a[i].output1();
	}
	
	getch();
}
