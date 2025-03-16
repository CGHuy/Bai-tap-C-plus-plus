#include <iostream>
#include <conio.h>
using namespace std;

class DT {
	private:
		int a[10], n;
	public:
		DT() {
			n = 0;	
		}
		DT(int b[10], int n) {
			for (int i = 0; i < n; i++) {
				a[i] = b[i];
			}
		}
		void input() {
			cout << "\nNhap bac cua da thuc: "; cin >> n;
			cout << "Nhap he so cua da thuc:\n";
			for (int i = 0; i <= n; i++) {
				cout << "He so cua x^" << i << " = "; cin >> a[i];
			} 
		}
		void output() {
			cout << a[n] << "x^" << n;
			for (int i = n-1; i >= 1; i--) {
				if (a[i] >= 0) {
					cout << "+" << a[i] << "x^" << i;
				} else {
					cout << a[i] << "x^" << i;
				}
			}
			if (a[0] >= 0) {
				cout << "+" << a[0];
			} else {
				cout << a[0];
			}
		}
		DT operator + (DT dt) {
			DT tong;
			if (n > dt.n) {
				tong.n = n;
				for (int i = 0; i <= dt.n; i++) {
					tong.a[i] = a[i] + dt.a[i];
				}
				for (int i = dt.n + 1; i <= n; i++) {
					tong.a[i] = a[i];
				}
			} else if (n < dt.n) {
				tong.n = dt.n;
				for (int i = 0; i <= n; i++) {
					tong.a[i] = a[i] + dt.a[i];
				}
				for (int i = n + 1; i <= dt.n; i++) {
					tong.a[i] = dt.a[i];
				}
			} else {
				tong.n = n;
				for (int i = 0; i <= n; i++) {
					tong.a[i] = a[i] + dt.a[i];
				}
			}
			return tong;
		}
		DT operator - (DT dt) {
			DT hieu;
			if (n > dt.n) {
				hieu.n = n;
				for (int i = 0; i <= dt.n; i++) {
					hieu.a[i] = a[i] - dt.a[i];
				}
				for (int i = dt.n + 1; i <= n; i++) {
					hieu.a[i] = a[i];
				}
			} else if (n < dt.n) {
				hieu.n = dt.n;
				for (int i = 0; i <= n; i++) {
					hieu.a[i] = a[i] - dt.a[i];
				}
				for (int i = n + 1; i <= dt.n; i++) {
					hieu.a[i] = dt.a[i];
				}
			} else {
				hieu.n = n;
				for (int i = 0; i <= n; i++) {
					hieu.a[i] = a[i] - dt.a[i];
				}
			}
			return hieu;
		}	
};

main() {
	DT dt1, dt2;
	cout << "NHAP DA THUC 1"; dt1.input();
	cout << "-------------------------";
	cout << "\nNHAP DA THUC 2"; dt2.input();
	cout << "-------------------------";
	cout << "\nDA THUC 1 LA: "; dt1.output();
	cout << "\nDA THUC 2 LA: "; dt2.output();
	DT tong = dt1 + dt2;
	DT hieu = dt1 - dt2;
	cout << "\n-------------------------";
	cout << "\nTONG HAI DA THUC LA: "; tong.output();
	cout << "\nHIEU HAI DA THUC LA: "; hieu.output();
	
	getch();
}
