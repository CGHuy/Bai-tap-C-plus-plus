#include <iostream>
#include <conio.h>

using namespace std;

class sophuc {
	private:
		int thuc, ao;
	public:
		sophuc() {
			thuc = 0;
			ao = 0;
		}
		sophuc(int thuc, int ao) {
			thuc = thuc;
			ao = ao;
		}
		friend istream &operator >> (istream &is, sophuc &a);
		friend ostream &operator << (ostream &os, sophuc a);
		sophuc operator + (sophuc a);
		sophuc operator * (sophuc a);
};

istream &operator >> (istream &is, sophuc &a) {
	cout << "\nPhan thuc = "; is >> a.thuc;
	cout << "Phan ao = "; is >> a.ao;
}

ostream &operator << (ostream &os, sophuc a) {
	if (a.ao > 0) {
		os << a.thuc << "+" << a.ao << "i" << endl;
	} else {
		os << a.thuc << a.ao << "i" << endl;
	}
	return os;
}

sophuc sophuc::operator + (sophuc a) {
	sophuc tong;
	tong.thuc = thuc + a.thuc;
	tong.ao = ao + a.ao;
	return tong;
}

sophuc sophuc::operator * (sophuc a) {
	sophuc tich;
	tich.thuc = thuc*a.thuc - ao*a.ao;
	tich.ao = thuc*a.ao + ao*a.thuc;
	return tich;
}

main() {
	sophuc a[10], tong, tich(1,1);
	int n;
	cout << "Nhap so luong so phuc n = "; cin >> n;
	cout << "-------------------------------------------\n";
	for (int i = 0; i < n; i++) {
		cout << "So phuc thu " << i+1; cin >> a[i];		
	}
	cout << "-------------------------------------------\n";
	cout << "Danh sach so phuc gom\n";
	for (int i = 0; i < n; i++) {
		cout << "So phuc thu " << i+1 << " la: " << a[i];
	}
	cout << "-------------------------------------------\n";
	cout << "Tong cac so phuc = ";
	for (int i = 0; i < n; i++) {
		tong = tong + a[i];
	}
	cout << tong;
	cout << "-------------------------------------------\n";
	cout << "Tich cac so phuc = ";
	for (int i = 0; i < n; i++) {
		tich = tich * a[i];
	}
	cout << tich;
	getch();
}
