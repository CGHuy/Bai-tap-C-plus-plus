#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

class Sinhvien {
	private:
		string ht;
		int ns;
		float d1, d2, d3, dtb;
	public:
		void input();
		void output();
		void khoaluan(Sinhvien sv);
		void totnghiep(Sinhvien sv);
		void thilai(Sinhvien sv);
};

void Sinhvien::input() {
	cout << "\nHo ten: "; cin >> ht;
	cout << "Nam sinh: "; cin >> ns;
	cout << "Diem mon 1: "; cin >> d1;
	cout << "Diem mon 2: "; cin >> d2;
	cout << "Diem mon 3: "; cin >> d3;
}

void Sinhvien::output() {
	cout << setw(10) << ht << setw(10) << ns << setw(10) << d1 << setw(10) << d2 << setw(10) << d3 << "\n";
}

void Sinhvien::khoaluan(Sinhvien sv) {
	sv.dtb = (sv.d1+sv.d2+sv.d3)/3;
	if (sv.dtb >= 7 && sv.d1 > 5 && sv.d2 > 5 && sv.d3 > 5) {
		sv.output();
	}
}

void Sinhvien::totnghiep(Sinhvien sv) {
	sv.dtb = (sv.d1+sv.d2+sv.d3)/3;
	if (sv.dtb < 7 && sv.d1 > 5 && sv.d2 > 5 && sv.d3 > 5) {
		sv.output();
	}
}

void Sinhvien::thilai(Sinhvien sv) {
	if (sv.d1 < 5 || sv.d2 < 5 || sv.d3 < 5) {
		sv.output();
	}
}

void title() {
	cout << setw(10) << "Ho Ten" << setw(10) << "Nam sinh" << setw(10) << "Diem 1" << setw(10) << "Diem 2" << setw(10) << "Diem 3\n";
} 

main() {
	Sinhvien sv[10];
	int n;
	cout << "Nhap so luong sinh vien: "; cin >> n;
	cout << "---------------------------------------\n";
	for (int i = 0; i < n; i++) {
		cout << "Sinh vien thu " << i+1;
		sv[i].input();
	}
	cout << "--------------------------------------------------\n";
	cout << "Danh sach sinh vien\n";
	title();
	for (int i = 0; i < n; i++) {
		sv[i].output();
	}
	cout << "--------------------------------------------------";
	cout << "\nDanh sach sinh vien lam khoa luan\n";
	title();
	for (int i = 0; i < n; i++) {
		sv[i].khoaluan(sv[i]);
	}
	cout << "--------------------------------------------------";
	cout << "\nDanh sach sinh vien tot nghiep\n";
	title();
	for (int i = 0; i < n; i++) {
		sv[i].totnghiep(sv[i]);
	}
	cout << "--------------------------------------------------";
	cout << "\nDanh sach sinh vien thi lai\n";
	title();
	for (int i = 0; i < n; i++) {
		sv[i].thilai(sv[i]);
	}
	getch();
}
