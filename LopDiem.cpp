#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;

class DIEM {
	private:
		int x,y;
	public:
		void input() {
			cout << "\nNhap toa do x: "; cin >> x;
			cout << "Nhap toa do y: "; cin >> y;
		}
		void output() {
			cout << "(" << x << "," << y << ")";
		}
		friend float kc2d(DIEM &a, DIEM &b);
};

float kc2d(DIEM &a, DIEM &b) {
		return sqrt(pow(b.x-a.x,2) + pow(b.y-a.y,2));
	}

class TAMGIAC : public DIEM {
	private:
		DIEM a,b,c;
		float c1,c2,c3;
	public:
		void canh() {
			c1 = kc2d(a,b);
			c2 = kc2d(b,c);
			c3 = kc2d(c,a);
		}
		void input() {
			cout << "Nhap diem A"; a.input();
			cout << "Nhap diem B"; b.input();
			cout << "Nhap diem C"; c.input();
			canh();
		}
		void output() {
			cout << "\nToa do diem A la "; a.output();
			cout << "\nToa do diem B la "; b.output();
			cout << "\nToa do diem C la "; c.output();
			cout << "\nDo dai canh AB la " << c1;
			cout << "\nDo dai canh BC la " << c2;
			cout << "\nDo dai canh CA la " << c3;
		}
		void check() {
			if (c1+c2>c3 && c2+c3>c1 && c3+c1>c2) {
				cout << "Day la tam giac ";
				if (c1==c2 && c2==c3 && c3==c1) {
					cout << "deu";
				} else if (c1==c2 || c2==c3 || c3==c1) {
					cout << "can";
				} else if (c1*c1+c2*c2==c3*c3 || c2*c2+c3*c3==c1*c1 || c3*c3+c1*c1==c2*c2) {
					cout << "vuong";
				} else {
					cout << "thuong";
				}
			} else {
				cout << "Day khong la tam giac";
			}
		}
};

main() {
	TAMGIAC a;
	
	cout << "NHAP TAM GIAC\n";
	a.input();
	
	cout << "------------------";
	cout << "\nTHONG TIN TAM GIAC";
	a.output();
	
	cout << "\n------------------";
	cout << "\nTINH CHAT TAM GIAC\n";
	a.check();
	
	getch();
}
