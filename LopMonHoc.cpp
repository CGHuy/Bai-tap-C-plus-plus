#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

class MONHOC {
	protected:
		string tenmon;
		float cc,kt,dt;
	public:
		float getCc() {
			return cc;
		}
		float getKt() {
			return kt;
		}
		float diemHP() {
			return cc*0.1 + kt*0.3 + dt*0.6;
		}
};

class SINHVIEN : public MONHOC {
	private:
		string ht, lop, msv;
	public:
		void input() {
			cin.ignore();
			cout << "\nNhap ho ten: "; getline(cin,ht);
			cout << "Nhap lop hoc: "; getline(cin,lop);
			cout << "Nhap ma sinh vien: "; getline(cin,msv);
			cout << "Nhap ten mon hoc: "; getline(cin,tenmon);
			cout << "Nhap diem chuyen can: "; cin >> cc;
			cout << "Nhap diem kiem tra: "; cin >> kt;
			cout << "Nhap diem thi: "; cin >> dt;
		}
		void output() {
			cout << "\n" << left << setw(20) << ht;
			cout << setw(15) << lop;
			cout << setw(10) << msv;
			cout << setw(10) << tenmon;
			cout << setw(10) << cc;
			cout << setw(10) << kt;
			cout << setw(10) << dt;
			cout << setw(10) << diemHP();
		}
};

void title() {
	cout << "\n" << left << setw(20) << "Ho Ten";
	cout << setw(15) << "Lop";
	cout << setw(10) << "MSV";
	cout << setw(10) << "Mon";
	cout << setw(10) << "Diem CC";
	cout << setw(10) << "Diem KT";
	cout << setw(10) << "Diem Thi";
	cout << setw(10) << "Diem HP";
}

main() {
	int n;
	SINHVIEN a[50];
	cout << "NHAP SO LUONG SINH VIEN: "; cin >> n;
	
	cout << "----------------------------------";
	cout << "\nNHAP THONG TIN SINH VIEN\n";
	for (int i = 0; i < n; i++) {
		cout << "---------------------";
		cout << "\nSinh vien thu " << i+1;
		a[i].input();
	}
	
	cout << "----------------------------------";
	cout << "\nDANH SACH SINH VIEN";
	title();
	for (int i = 0; i < n; i++) {
		a[i].output();
	}
	
	cout << "\n----------------------------------";
	cout << "\nDANH SACH SINH VIEN BI CAM THI";
	title();
	for (int i = 0; i < n; i++) {
		if (a[i].getCc() < 5 || a[i].getKt() == 0) {
			a[i].output();
		}
	}
	
	cout << "\n----------------------------------";
	cout << "\nDANH SACH SINH VIEN THI LAI";
	title();
	for (int i = 0; i < n; i++) {
		if (a[i].diemHP() < 4) {
			a[i].output();
		}
	}
	
	getch();
}
