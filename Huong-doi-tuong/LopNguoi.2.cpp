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
			cout << "\nHo ten: " << left << setw(20) << ht << ", Nam sinh: " << ns;
		}
};

class GIANGVIEN : public NGUOI {
	private:
		string monct, mongd;
		int sobb;
	public:
		void input() {
			NGUOI::input();
			cout << "Nhap bo mon cong tac: "; cin.ignore(); getline(cin, monct);
			cout << "Nhap bo mon dang giang day: "; getline(cin, mongd);
			cout << "Nhap so bai bao: "; cin >> sobb;
		}
		void output() {
			NGUOI::output();
			cout << ", Bo mon cong tac: " << monct;
			cout << ", Bo mon giang day: " << mongd;
			cout << ", So bai bao: " << sobb;
		}
		string getMonct() {
			return monct;
		}
		int getSobb() {
			return sobb;
		}
};

main() {
	int n;
	GIANGVIEN a[50];
	cout << "NHAP SO LUONG GIANG VIEN: "; cin >> n;
	
	cout << "-------------------------";
	cout << "\nNHAP THONG TIN GIANG VIEN\n";
	for (int i=0; i < n; i++) {
		cout << "Giang vien thu " << i+1;
		a[i].input();
	}
	
	cout << "----------------------------------------------";
	cout << "\nDANH SACH GIANG VIEN THEO TUNG BO MON CONG TAC";
	for (int i=0; i<n-1; i++) {
		for (int j=1; j<n; j++) {
			if (a[i].getMonct() > a[j].getMonct()) {
				GIANGVIEN temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	for (int i=0; i<n; i++) {
		a[i].output();
	}
	
	cout << "\n----------------------------------------------------";
	cout << "\nDANH SACH GIANG VIEN THEO THU TU SO BAI BAO TANG DAN";
	for (int i=0; i<n-1; i++) {
		for (int j=1; j<n; j++) {
			if (a[i].getSobb() > a[j].getSobb()) {
				GIANGVIEN temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	for (int i=0; i<n; i++) {
		a[i].output();
	}
	
	cout << "\n----------------------------------------------------";
	cout << "\nDANH SACH GIANG VIEN THEO THU TU SO BAI BAO GIAM DAN";
	for (int i=0; i<n-1; i++) {
		for (int j=1; j<n; j++) {
			if (a[i].getSobb() < a[j].getSobb()) {
				GIANGVIEN temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	for (int i=0; i<n; i++) {
		a[i].output();
	}
	
	getch();
}
