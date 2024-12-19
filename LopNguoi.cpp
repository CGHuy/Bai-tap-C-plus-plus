#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

class Nguoi {
	private:
		string ht;
		int ns;
	public:
		void input() {
			cout << "\nNhap ho ten: "; fflush(stdin); getline(cin, ht);
			cout << "Nhap nam sinh: "; cin >> ns;	
		}
		void output() {
			cout << "\n" << left << setw(20) << ht << setw(15) << ns;
		}
};

class SinhVien : public Nguoi {
	private:
		string msv;
		float dtb;
		int a[100];
	public:
		void inputsv() {
			input();
			cout << "Nhap ma sinh vien: "; fflush(stdin); getline(cin, msv);
			cout << "Nhap diem trung binh: "; cin >> dtb;
		}
		void outputsv() {
			output();
			cout << setw(10) << msv << setw(15) << dtb;
		}
		void tangdan(SinhVien a[100], int n) {
			for (int i = 0; i < n-1; i++) {
				for (int j = i+1; j < n; j++) {
					if (a[i].dtb > a[j].dtb) {
						SinhVien temp = a[i];
						a[i] = a[j];
						a[j] = temp;
					}
				}
			}		
		}
		friend void tangdan(SinhVien a[100], int n);
		friend void giamdan(SinhVien a[100], int n);
		friend void timkiem(SinhVien a[100], int n);
};

void tangdan(SinhVien a[100], int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (a[i].dtb > a[j].dtb) {
				SinhVien temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}		
}

void giamdan(SinhVien a[100], int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (a[i].dtb < a[j].dtb) {
				SinhVien temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

void timkiem(SinhVien a[100], int n) {
	string find;
	int x = 0, index = 0;
	cout << "Nhap ma sinh vien can tim kiem: "; fflush(stdin); getline(cin, find);
	for (int i = 0; i < n; i++) {
		if (a[i].msv.compare(find) == 0) {
			x = 1;
			index = i;
			break;
		}
	}
	if (x == 1) {
		cout << "Tim thay sinh vien trong danh sach!";
		a[index].inputsv();
	} else {
		cout << "Khong tim thay sinh vien trong danh sach!";
	}
}

void titlesv() {
	cout << "\n" << left << setw(20) << "Ho va Ten" << setw(15) << "Nam sinh" << setw(10) << "MaSV" << setw(15) << "Diem tb";
}

class GiangVien : public Nguoi {
	private:
		string monct, mongd;
		int sbb;
	public:
		inputgv() {
			input();
			cout << "Nhap bo mon cong tac: "; fflush(stdin); getline(cin, monct);
			cout << "Nhap mon dang giang day: "; fflush(stdin); getline(cin, mongd);
			cout << "Nhap so bai bao: "; cin >> sbb;
		}
		outputgv() {
			output();
			cout << left << setw(15) << monct << setw(15) << mongd;
			cout << right << setw(10) << sbb;
		}
		
};

main() {
	SinhVien a[100];
	int n;
	cout << "NHAP SO LUONG SINH VIEN: "; cin >> n;
	cout << "-----------------------------------";
	cout << "\nNHAP THONG TIN DANH SACH SINH VIEN";
	for (int i = 0; i < n; i++) {
		a[i].inputsv();
	}
	cout << "---------------------------------";
	cout << "\nIN THONG TIN DANH SACH SINH VIEN";
	titlesv();
	for (int i = 0; i < n; i++) {
		a[i].outputsv();
	}
	cout << "\n----------------------------";
	cout << "\nSAP XEP THEO THU TU TANG DAN";
	titlesv();
	tangdan(a,n);
	for (int i = 0; i < n; i++) {
		a[i].outputsv();
	}
	cout << "\n----------------------------";
	cout << "\nSAP XEP THEO THU TU GIAM DAN";
	titlesv();
	giamdan(a,n);
	for (int i = 0; i < n; i++) {
		a[i].outputsv();
	}
	getch();
}
