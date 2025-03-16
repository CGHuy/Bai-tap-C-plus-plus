#include <iostream>
#include <conio.h>
using namespace std;

class MT {
	private:
		int hang, cot;
		int **a;
	public:
		MT() {
			hang = 0;
			cot = 0;
			a = NULL;
		}
		MT(int hang, int cot) {
			this->hang = hang;
			this->cot = cot;
			a = new int*[hang];
			for (int i = 0; i < hang; i++) {
				a[i] = new int[cot];
			}
		}
		void input() {
			cout << "\nNhap so hang: "; cin >> hang;
			cout << "Nhap so cot: "; cin >> cot;
			
			a = new int*[hang];
			for (int i = 0; i < hang; i++) {
				a[i] = new int[cot];
			}
			
			for (int i = 0; i < hang; i++) {
				for (int j = 0; j < cot; j++) {
					cout << "a[" << i << "][" << j << "] = ";
					cin >> a[i][j];
				}
			}
		}
		void output() {
			for (int i = 0; i < hang; i++) {
				cout << "\n";
				for (int j = 0; j < cot; j++) {
					cout << a[i][j] << "\t";
				}
			}
		}
		friend MT cong(MT &mt1, MT &mt2) {
			if (mt1.hang != mt2.hang || mt1.cot != mt2.cot) {
				cout << "Hai ma tran khong dong cap!";
				return MT();
			} else {
				MT kq(mt1.hang,mt2.cot);
				for (int i = 0; i < mt1.hang; i++) {
					for (int j = 0; j < mt1.cot; j++) {
						kq.a[i][j] = mt1.a[i][j] + mt2.a[i][j];
					}
				}
				return kq;
			}
		}
		friend MT tru(MT &mt1, MT &mt2) {
			if (mt1.hang != mt2.hang || mt1.cot != mt2.cot) {
				cout << "Hai ma tran khong dong cap!";
				return MT();
			} else {
				MT kq(mt1.hang,mt2.cot);
				for (int i = 0; i < mt1.hang; i++) {
					for (int j = 0; j < mt1.cot; j++) {
						kq.a[i][j] = mt1.a[i][j] - mt2.a[i][j];
					}
				}
				return kq;
			}
		}
		int tongHangK(int k) {
			int tong = 0;
			if (k < 0 || k >= hang) {
				cout << "Gia tri K khong hop le!";
			} else {
				for (int i = 0; i < cot; i++) {
					tong += a[k][i];
				}
			}
			return tong;
		}
		int tongCotK(int k) {
			int tong = 0;
			if (k < 0 || k >= cot) {
				cout << "Gia tri K khong hop le!";
			} else {
				for (int i = 0; i < hang; i++) {
					tong += a[i][k];
				}
			}
			return tong;
		}
		int tong4DuongVien() {
			int tong = 0;
			for (int i = 0; i < cot; i++) {
				tong += a[0][i] + a[hang-1][i];
			}
			for (int i = 1; i < hang-1; i++) {
				tong += a[i][0] + a[i][cot-1];
			}
			return tong;
		}
};

main() {
	MT a, b, c, tong, hieu;
	cout << "NHAP MA TRAN A"; a.input();
	cout << "NHAP MA TRAN B"; b.input();
	cout << "MA TRAN A LA"; a.output();
	cout << "\nMA TRAN B LA"; b.output();
	tong = cong(a,b);
	hieu = tru(a,b);
	cout << "\nTONG HAI MA TRAN LA"; tong.output();
	cout << "\nHIEU HAI MA TRAN LA"; hieu.output(); 
	cout << "\nNHAP MA TRAN C"; c.input();
	cout << "MA TRAN C LA"; c.output();
	int k;
	cout << "\nNHAP HANG K, COT K MUON TINH: "; cin >> k;
	cout << "TONG HANG K LA: " << c.tongHangK(k);
	cout << "\nTONG COT K LA: " << c.tongCotK(k);
	cout << "\nTONG 4 DUONG VIEN LA: " << c.tong4DuongVien();
	
	getch();
}
