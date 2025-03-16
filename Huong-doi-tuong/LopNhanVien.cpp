#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

class NHANVIEN {
	private:
		string ht, cv, gt, dc;
		int ns, nl;
	public:
		int tinhTuoi(int namhientai) {
			return namhientai - ns;
		}
		int tinhNamLam(int namhientai) {
			return namhientai - nl;
		}
		friend istream& operator >> (istream& is, NHANVIEN& a) {
			cout << "\nNhap ho ten: "; getline(is,a.ht);
			cout << "Nhap cong viec: "; getline(is,a.cv);
			cout << "Nhap gioi tinh: "; getline(is,a.gt);
			cout << "Nhap nam sinh: "; is >> a.ns;
			cout << "Nhap nam lam viec: "; is >> a.nl;
			is.ignore();
			cout << "Nhap dia chi: "; getline(is,a.dc);
			return is;
		}
		friend ostream& operator << (ostream& os, NHANVIEN& a) {
			os << "\n" << left << setw(20) << a.ht;
			os << setw(20) << a.cv;
			os << setw(15) << a.gt;
			os << setw(10) << a.ns;
			os << setw(10) << a.nl;
			os << setw(20) << a.dc;
			return os;
		}
		bool tuoiVeHuu(int namhientai) {
			int tuoi = tinhTuoi(namhientai);
			if (gt == "Nam" || gt == "nam" && tuoi >= 60) {
				return true;
			}
			if (gt == "Nu" || gt == "nu" && tuoi >=55) {
				return true;
			}
			return false;
		}
		bool lamVien20Nam(int namhientai) {
			int namlam = tinhNamLam(namhientai);
			if (namlam > 20) {
				return true;
			}
			return false;
		}
};

void title() {
	cout << "\n" << left << setw(20) << "Ho ten";
	cout << setw(20) << "Cong viec";
	cout << setw(15) << "Gioi tinh";
	cout << setw(10) << "Nam sinh";
	cout << setw(10) << "Nam lam";
	cout << setw(20) << "Dia chi";
}

main() {
	int n, namhientai;
	NHANVIEN a[50];
	cout << "NHAP SO LUONG NHAN VIEN: "; cin >> n;
	cout << "NHAP NAM HIEN TAI: "; cin >> namhientai;
	cin.ignore();
	
	cout << "NHAP THONG TIN NHAN VIEN\n";
	for (int i = 0; i < n; i++) {
		cout << "------------------";
		cout << "\nNhan vien thu " << i+1;
		cin >> a[i];
	}
	
	cout << "HIEN THI THONG TIN NHAN VIEN";
	title();
	for (int i = 0; i < n; i++) {
		cout << a[i];
	}
	
	cout << "\nDANH SACH NHAN VIEN DU TUOI VE HUU";
	title();
	for (int i = 0; i < n; i++) {
		if (a[i].tuoiVeHuu(namhientai)) {
			cout << a[i];
		}
	}
	
	cout << "\nDANH SACH NHAN VIEN LAM VIEC TREN 20 NAM";
	title();
	for (int i = 0; i < n; i++) {
		if (a[i].lamVien20Nam(namhientai)) {
			cout << a[i];
		}
	}
	
	getch();
}
