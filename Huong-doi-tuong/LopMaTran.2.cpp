#include <iostream>
#include <conio.h>
using namespace std;

class MTV {
	private:
		int cap;
		int **a;
	public:
		MTV() {
			cap = 0;
			a = NULL;
		}
		MTV(int cap) {
			this->cap = cap;
			a = new int*[cap];
			for (int i = 0; i < cap; i++) {
				a[i] = new int[cap];
			}
		}
		void input() {
			cout << "\nNhap cap cua ma tran: "; cin >> cap;
			a = new int*[cap];
			for (int i = 0; i < cap; i++) {
				a[i] = new int[cap];
			}
			for (int i = 0; i < cap; i++) {
				for (int j = 0; j < cap; j++) {
					cout << "a[" << i << "][" << j << "] = ";
					cin >> a[i][j];
				}
			}
		}
		void output() {
			for (int i = 0; i < cap; i++) {
				cout << "\n";
				for (int j = 0; j < cap; j++) {
					cout << a[i][j] << "\t";
				}
			}
		}
		int tongDuongCheoChinh() {
			int tong = 0;
			for (int i = 0; i < cap; i++) {
				tong += a[i][i];
			}
			return tong;
		}
		int tongDuongCheoPhu() {
			int tong = 0;
			for (int i = 0; i < cap; i++) {
				tong += a[i][cap - i - 1];
			}
			return tong;
		}
};

main() {
	MTV a;
	cout << "NHAP MA TRAN VUONG";
	a.input();
	
	cout << "HIEN THI MA TRAN VUA NHAP";
	a.output();
	
	cout << "\nTONG DUONG CHEO CHINH: " << a.tongDuongCheoChinh();
	cout << "\nTONG DUONG CHEO PHU: " << a.tongDuongCheoPhu();
	
	getch();
}
