#include <iostream>
#include <conio.h>
using namespace std;

class date {
	private:
		int d,m,y;
	public:
		date() {
			d = 1;
			m = 1;
			y = 1;
		}
		date(int a, int b, int c) {
			d = a;
			m = b;
			y = c;
		}
		~date() {
			d = 0;
			m = 0;
			y = 0;
		}
		void input() {
			do {
				cout << "Nhap ngay: "; cin >> d;
			}
			while (d<1||d>31);
			do {
				cout << "Nhap thang: "; cin >> m;
			}
			while (m<1||m>12);
			do {
				cout << "Nhap nam: "; cin >> y;
			}
			while (y<1||y>9999);
		}
		void output() {
			cout << d << "/" << m << "/" << y;
		}
		int getd() {
			return d;
		}
		int getm() {
			return m;
		}
		int gety() {
			return y;
		}
		date chuanhoa();
		date operator ++ (int);
		date operator -- (int);
};

date date::operator ++ (int) {
	date kq;
	kq.d = getd() + 1;
	if (getm() == 1 || getm() == 3 || getm() == 5 || getm() == 7 || getm() == 8 || getm() == 10 || getm() == 12) {
		if (kq.d > 31 && getm() != 12) {
			kq.d = 1;
			kq.m = getm() + 1;
			kq.y = gety();
		} else if (kq.d > 31 && getm() == 12) {
			kq.d = 1;
			kq.m = 1;
			kq.y = gety() + 1;
		} else {
			kq.m = getm();
			kq.y = gety();
		}
	} else if (getm() == 4 || getm() == 6 || getm() == 9 || getm() == 11) {
		if (kq.d > 30) {
			kq.d = 1;
			kq.m = getm() + 1;
			kq.y = gety();
		} else {
			kq.m = getm();
			kq.y = gety();
		}
	} else if (getm() == 2) {
		if (gety() % 400 == 0 || (gety() % 4 == 0 && gety() % 100 != 0)) {
			if (kq.d > 29) {
				kq.d = 1;
				kq.m = getm() + 1;
				kq.y = gety();
			} else {
				kq.m = getm();
				kq.y = gety();
			}
		} else {
			if (kq.d > 28) {
				kq.d = 1;
				kq.m = getm() + 1;
				kq.y = gety();
			} else {
				kq.m = getm();
				kq.y = gety();
			}
		}
	}
	return kq;
}

date date::operator -- (int) {
	date kq;
	kq.d = getd() - 1;
	if (getm() == 1 || getm() == 5 || getm() == 7 || getm() == 10 || getm() == 12) {
		if (kq.d < 1 && getm() == 1) {
			kq.d = 31;
			kq.m = 12;
			kq.y = gety() - 1;
		} else if (kq.d < 1 && getm() != 1) {
			kq.d = 30;
			kq.m = getm() - 1;
			kq.y = gety();
		} else {
			kq.m = getm();
			kq.y = gety();
		}
	} else if (getm() == 2 || getm() == 4 || getm() == 6 || getm() == 8 || getm() == 9 || getm() == 11) {
		if (kq.d < 1) {
			kq.d = 31;
			kq.m = getm() - 1;
			kq.y = gety();
		} else {
			kq.m = getm();
			kq.y = gety();
		}
	} else if (getm() == 3) {
		if (gety() % 400 == 0 || (gety() % 4 == 0 && gety() % 100 == 0)) {
			if (kq.d < 1) {
				kq.d = 29;
				kq.m = getm() - 1;
				kq.y = gety();
			} else {
				kq.m = getm();
				kq.y = gety();
			}
		} else {
			if (kq.d < 1) {
				kq.d = 28;
				kq.m = getm() - 1;
				kq.y = gety();
			} else {
				kq.m = getm();
				kq.y = gety();
			}
		}
	}
	return kq;
}

main() {
	date a;
	cout << "NHAP NGAY\n"; a.input();
	cout << "NGAY DA NHAP: "; a.output();
	cout << "\nNGAY TIEP THEO: "; a++.output();
	cout << "\nNGAY TRUOC DO: "; a--.output();
	getch();
}
