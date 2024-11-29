#include <iostream>
#include <cmath>

using namespace std;

class DaThuc {
	private:
		int n, a[10];
	public:
		DaThuc() {
			n = 0;
			a[n] = 0;
		}
		DaThuc(int n, int b[10]) {
			
			for (int i = 0; i < n; i++) {
				a[i] = b[i];
			}	
		}
		void input();
		void output();
		DaThuc tong(DaThuc dt2);
		DaThuc hieu(DaThuc dt2);
};
void DaThuc::input() {
	cout << "\nNhap bac cua da thuc: "; cin >> n;
	cout << "Nhap he so cua da thuc:\n";
	for (int i = 0; i <= n; i++) {
		cout << "a[" << i << "] = "; cin >> a[i];
	}
}
void DaThuc::output() {
	cout << a[n] << "x^" << n;
	for (int i = n-1; i > 0; i--) {
		if (a[i] > 0)
			cout << "+" << a[i] << "x^" << i;
		else if (a[i] < 0)
			cout << a[i] << "x^" << i;
	}
	if (a[0] >= 0)
		cout << "+" << a[0];
	else
		cout << a[0];
}
DaThuc DaThuc::tong(DaThuc dt2) {
	DaThuc t;
	if (dt1.n > dt2.n) {
		t.n = dt1.n;
		for (int i = 0; i <= dt2.n; i++)
			t.a[i] = dt1.a[i] + dt2.a[i];
		for (int i = dt2.n + 1; i <= dt1.n; i++)
			t.a[i] = dt1.a[i];
	} else if (dt1.n < dt2.n) {
		t.n = dt2.n;
		for (int i = 0; i <= dt1.n; i++)
			t.a[i] = dt1.a[i] + dt2.a[i];
		for (int i = dt1.n + 1; i <= dt2.n; i++)
			t.a[i] = dt2.a[i];
	}
	return t;
}



main() {
	DaThuc dt1, dt2;
	cout << "Nhap da thuc 1"; dt1.input();
	cout << "\nNhap da thuc 2"; dt2.input();
	cout << "\nDa thuc 1 la: "; dt1.output();
	cout << "\nDa thuc 2 la: "; dt2.output();
	tong(DaThuc dt1, DaThuc dt2).output();
}







