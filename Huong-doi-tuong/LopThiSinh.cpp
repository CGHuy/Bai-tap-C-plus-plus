#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

class ThiSinh {
	private:
		string id, hoten;
		float toan, ly, hoa;
	public:
		void input() {
			cout << "\nNhap ma cua thi sinh: "; fflush(stdin); getline(cin, id);
			cout << "Nhap ho ten: "; fflush(stdin); getline(cin, hoten);
			cout << "Nhap diem toan: "; cin >> toan;
			cout << "Nhap diem ly: "; cin >> ly;
			cout << "Nhap diem hoa: "; cin >> hoa;
		}
		void output() {
			cout << "\n" << left << setw(20) << id;
			cout << left << setw(20) << hoten;
			cout << left << setw(10) << toan;
			cout << left << setw(10) << ly;
			cout << left << setw(10) << hoa;
		}
		float tongdiem() {
			return toan + ly + hoa;
		}
		bool check() {
			return (tongdiem() > 21 && toan >= 2 && ly >= 2 && hoa >= 2);
		}
};

title() {
	cout << "\n" << left << setw(20) << "Ma thi sinh";
	cout << left << setw(20) << "Ho ten";
	cout << left << setw(10) << "Toan";
	cout << left << setw(10) << "Ly";
	cout << left << setw(10) << "Hoa";
}

main() {
	int n;
	cout << "NHAP SO LUONG THI SINH: "; cin >> n;
	ThiSinh *ds = new ThiSinh[n];
	
	cout << "-----------------------";
	cout << "\nNHAP THONG TIN THI SINH\n";
	for (int i = 0; i < n; i++) {
		cout << "--------------";
		cout << "\nThi sinh thu " << i+1;
		ds[i].input();
	}
	
	cout << "-----------------------";
	cout << "\nIN THONG TIN THI SINH";
	title();
	for (int i = 0; i < n; i++) {
		ds[i].output();
	}
	
	cout << "\n---------------------------------";
	cout << "\nTHI SINH CO TONG DIEM CAO NHAT LA";
	title();
	int index = 0;
	for (int i = 0; i < n; i++) {
		if (ds[i].tongdiem() > ds[index].tongdiem()) {
			index = i;
		}
	}
	
	ds[index].output();
	cout << "\n-------------------------------------------------------------------";
	cout << "\nDANH SACH THI SINH CO TONG DIEM TREN 21 VA KHONG CO DIEM NAO DUOI 2";
	title();
	for (int i = 0; i < n; i++) {
		if (ds[i].check()) {
			ds[i].output();
		}
	}
	getch();
}
