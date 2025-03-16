#include <iostream>
#include <conio.h>
#include <iomanip> // dung lenh setfill
using namespace std;

class date {
	private:
		int d, m, y;
	public:
		date() {
			d = 1;
			m = 1;
			y = 1;
		}
		date(int d, int m, int y) {
			d = d;
			m = m;
			y = y;
		}
		~date() {
			d = 1;
			m = 1;
			y = 1;
		}
		bool namnhuan(int y) {
			return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
		}
		int chuanhoangay(int m, int y) {
			switch (m) {
				case 1: case 3: case 5: case 7: case 8: case 10: case 12:
					return 31;
				case 4: case 6: case 9: case 11:
					return 30;
				case 2:
					return namnhuan(y) ? 29 : 28;
				default:
					return 0;
			}
		}
		void chuanhoa() {
			while (d > chuanhoangay(m,y)) { // dung while trong truong hop d rat lon phai chay nhieu lan
				d = d - chuanhoangay(m,y);
				m++;
				if (m > 12) {
					m = 1;
					y++;
				}
			}
			while (d < 1) { // dung while trong truong hop d rat lon phai chay nhieu lan
				m--;
				if (m < 1) {
					m = 12;
					y--;
				}
				d = d + chuanhoangay(m,y);
			}
		}
		void input() {
			cout << "\nNhap ngay: "; cin >> d;
			cout << "Nhap thang: "; cin >> m;
			cout << "Nhap nam: "; cin >> y;
			chuanhoa();
		}
		void output() {
			cout << setfill('0') << setw(2) << d << "/";
			cout << setfill('0') << setw(2) << m << "/";
			cout << setfill('0') << setw(4) << y;
		}
		date operator ++ (int) {
			date kq = *this;
			kq.d++;
			kq.chuanhoa();
			return kq;
		}
		date operator -- (int) {
			date kq = *this;
			kq.d--;
			kq.chuanhoa();
			return kq;
		}
};

main() {
	date a, tang, giam;
	cout << "NHAP NGAY"; a.input();
	cout << "NGAY DA NHAP LA: "; a.output();
	tang = a++;
	giam = a--;
	cout << "\nNGAY TIEP THEO LA: "; tang.output();
	cout << "\nNGAY TRUOC DO LA: "; giam.output();
	getch();
}
