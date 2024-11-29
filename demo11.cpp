#include <iostream>
#include <conio.h>
using namespace std;

class NGUOI {
	public:
		string ht;
		int ns;
	public:
		void input() {
			fflush(stdin);
			cout << "Nhap ho ten: "; getline(cin,ht);
			cout << "Nhap nam sinh: "; cin >> ns;
		}
		void output() {
			cout << ht << "\t" << ns;
		}	
};

class SINHVIEN:public NGUOI {
	public:
		string masv;
		float dtb;
	public:
		void input1() {
			fflush(stdin);
			cout << "\nNhap ma sinh vien: "; getline(cin,masv);
			input();
			cout << "Nhap diem TB: "; cin >> dtb;
		}
		void output1() {
			cout << "\n" << masv << "\t";
			output(); 
			cout << "\t" << dtb;
		}
};

void sx(SINHVIEN a[10], int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (a[i].dtb < a[j].dtb) {
				SINHVIEN temp;
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		a[i].output1();
	}
}

void timkiem(SINHVIEN a[10], int n) {
	string find;
	int x=0;
	fflush(stdin);
	cout << "\nNhap ma sinh vien can tim: "; getline(cin,find);
	for (int i = 0; i < n; i++) {
		if (a[i].masv.compare(find)==0) {
			x = 1;
			break;
		}
	}
	if (x==1) {
		cout << "Tim thay sinh vien trong danh sach";
	} else {
		cout << "Khong tim thay sinh vien trong danh sach";
	}
}

main() {
	SINHVIEN a[10];
	int n;
	
	cout << "NHAP SO LUONG SINH VIEN: "; cin >> n;
	
	cout << "--------------------------------------------------------\n";
	cout << "NHAP DANH SACH SINH VIEN";
	for (int i = 0; i < n; i++) {
		a[i].input1();
	}
	
	cout << "\n--------------------------------------------------------\n";
	cout << "IN DANH SACH SINH VIEN";
	for (int i = 0; i < n; i++) {
		a[i].output1();
	}

	cout << "\n--------------------------------------------------------\n";	
	cout << "DANH SACH SINH VIEN DUOC SAP XEP CO DIEM TB GIAM DAN";
	sx(a,n);

	cout << "\n--------------------------------------------------------\n";	
	cout << "TIM KIEM SINH VIEN";
	timkiem(a,n);
	
	getch();
}
