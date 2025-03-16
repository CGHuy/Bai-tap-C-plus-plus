#include <iostream>
#include <conio.h>
#include <math.h>
#include <iomanip> // dung lenh setfill va setw
using namespace std;

class time {
	private:
		int h, m, s;
	public:
		time() {
			h = 0;
			m = 0;
			s = 0;
		}
		time(int h, int m, int s) {
			h = h;
			m = m;
			s = s;
		}
		~time() {
			h = 0;
			m = 0;
			s = 0;
		}
		void chuanhoa() {
			if (s >= 60) {
				m = m + s / 60;
				s = s % 60;
			} else if (s < 0) {
				m = m - (abs(s) + 59) / 60;
				s = 60 - (abs(s) % 60);
				if (s == 60) s = 0;
			}
			if (m >= 60) {
				h = h + m / 60;
				m = m % 60;
			} else if (m < 0) {
				h = h - (abs(m) + 59) / 60;
				m = 60 - (abs(m) % 60);
				if (m == 60) m = 0;
			}
			if (h >= 24) {
				h = h % 24;
			} else if (h < 0) {
				h = h - (abs(h) + 23) / 24;
				if (h == 24) h = 0;
			}
		}
		void input() {
			cout << "\nNhap gio: "; cin >> h;
			cout << "Nhap phut: "; cin >> m;
			cout << "Nhap giay: "; cin >> s;
			chuanhoa();
		}
		void output() {
			cout << setfill('0') << setw(2) << h << ":";
			cout << setfill('0') << setw(2) << m << ":";
			cout << setfill('0') << setw(2) << s;
		}
		time operator ++ (int) {
			time kq = *this; // sao chep gia tri hien tai vao kq
			kq.s++;
			chuanhoa();
			return kq;
		}
		time operator -- (int) {
			time kq = *this; // sao chep gia tri hien tai vao kq
			kq.s--;
			chuanhoa();
			return kq;
		}
};

main() {
	time a, tang, giam;
	cout << "NHAP THOI GIAN"; a.input();
	cout << "THOI GIAN DA NHAP LA: "; a.output();
	tang = a++;
	giam = a--;
	cout << "\nTHOI GIAN SAU KHI TANG 1 GIAY LA: "; tang.output();
	cout << "\nTHOI GIAN SAU KHI GIAM 1 GIAY LA: "; giam.output();
	getch();
}
