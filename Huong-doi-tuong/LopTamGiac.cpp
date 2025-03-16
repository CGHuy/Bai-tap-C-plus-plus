#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;

class TAMGIAC {
	private:
		float a,b,c;
	public:
		TAMGIAC() {
			a = 0;
			b = 0;
			c = 0;
		}
		TAMGIAC(float a, float b, float c) {
			a = a;
			b = b;
			c = c;
		}
		~TAMGIAC() {
			a = 0;
			b = 0;
			c = 0;
		}
		void input() {
			do {
				cout << "\nNhap canh thu nhat: "; cin >> a;
				cout << "Nhap canh thu hai: "; cin >> b;
				cout << "Nhap canh thu ba: "; cin >> c;
				if (a+b<=c || b+c<=a || c+a<=b) {
					cout << "Ba canh tren khong tao thanh mot tam giac, vui long nhap lai";
				}
			} while (a+b<=c || b+c<=a || c+a<=b);
		}
		void output() {
			cout << "\nTam giac co canh " << a << "-" << b << "-" << c << ", Chu vi: " << cv() << ", Dien tich: " << dt();
		}
		float cv() {
			return a+b+c;
		}
		float dt() {
			float p = (a+b+c)/2;
			return sqrt(p*(p-a)*(p-b)*(p-c));
		}
};

main() {
	int n;
	TAMGIAC a[50];
	cout << "NHAP SO LUONG TAM GIAC: "; cin >> n;
	
	cout << "-----------------";
	cout << "\nNHAP CAC TAM GIAC\n";
	for (int i = 0; i < n; i++) {
		cout << "Tam giac thu " << i+1;
		a[i].input();
	}
	
	cout << "------------------";
	cout << "\nDANH SACH TAM GIAC";
	for (int i = 0; i < n; i++) {
		a[i].output();
	}
	
	cout << "\n-----------------------------------------------------";
	cout << "\nDANH SACH TAM GIAC THEO THU TU TANG DAN CUA DIEN TICH";
	for (int i = 0; i < n-1; i++) {
		for (int j = 1; j < n; j++) {
			if (a[i].dt() > a[j].dt()) {
				TAMGIAC temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		a[i].output();
	}
	
	getch();
}
