#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

class matrix {
	private:
		int hang;
		int cot;
		int **arr;
	public:
		matrix() {
			hang = 0;
			cot = 0;
		}
		matrix(int hang1, int cot1) {
			hang = hang1;
			cot = cot1;
			arr = new int*[hang];
			for (int i = 0; i < hang; i++) {
				arr[i] = new int[cot]();
			}
		}
		void input() {
			for (int i = 0; i < hang; i++) {
				for (int j = 0; j < cot; j++) {
					cout << "a[" << i << "][" << j << "]: ";
					cin >> arr[i][j];
				}
			}
		}
		void output() {
			for (int i = 0; i < hang; i++) {
				for (int j = 0; j < cot; j++) {
					cout << arr[i][j] << "\t";
				}
				cout << "\n";
			}
		}
		friend matrix cong(matrix &a, matrix &b) {
			if (a.hang != b.hang || a.cot != b.cot) {
				cout << "Hai ma tran khong cung cap";
				return matrix();
			}
			matrix kq(a.hang,a.cot);
			for (int i = 0; i < a.hang; i++) {
				for (int j = 0; j < a.cot; j++) {
					kq.arr[i][j] = a.arr[i][j] + b.arr[i][j];
				}
			}
			return kq;
		}
		friend matrix tru(matrix &a, matrix &b) {
			if (a.hang != b.hang || a.cot != b.cot) {
				cout << "Hai ma tran khong cung cap";
				return matrix();
			}
			matrix kq(a.hang,a.cot);
			for (int i = 0; i < a.hang; i++) {
				for (int j = 0; j < a.cot; j++) {
					kq.arr[i][j] = a.arr[i][j] - b.arr[i][j];
				}
			}
			return kq;
		}
		int tonghangk(int &k) {
			int sum = 0;
			if (k >= 0 && k < hang)
				for (int i = 0; i < cot; i++) {
					sum += arr[k][i];
				}
			return sum;
		}
		int tongcotk(int &k) {
			int sum = 0;
			if (k >= 0 && k < cot)
				for (int i = 0; i < hang; i++) {
					sum += arr[k][i];
				}
			return sum;
		}
		int tong4duong() {
			int sum = 0;
			for (int i = 0; i < cot; i++) { // tinh tong hang dau va hang cuoi
				sum += arr[0][i] + arr[hang-1][i];
			}
			for (int i = 1; i < hang-1; i++) { // tinh tong cot dau va cot cuoi
				sum += arr[i][0] + arr[i][cot-1];
			}
			return sum;
		}
};

main() {
	int hang, cot, hang1, cot1, hangk, cotk;
	// nhap va in hai ma tran A va B	
	cout << "Nhap kich thuoc cua 2 ma tran A va B";
	cout << "\nNhap hang: "; cin >> hang;
	cout << "Nhap cot: "; cin >> cot;
	matrix a(hang,cot), b(hang,cot);
	cout << "Nhap ma tran A\n"; a.input();
	cout << "Nhap ma tran B\n"; b.input(); 
	cout << "Ma tran A\n"; a.output();
	cout << "Ma tran B\n"; b.output();
	// tinh tong va hieu 2 ma tran A va B
	matrix tong = cong(a,b);
	matrix hieu = tru(a,b);
	cout << "Cong hai ma tran\n";
	tong.output();
	cout << "Tru hai ma tran\n";
	hieu.output();
	// nhap ma tran C
	cout << "Nhap kich thuoc ma tran C";
	cout << "\nNhap hang: "; cin >> hang1;
	cout << "Nhap cot: "; cin >> cot1;
	matrix c(hang1,cot1);
	cout << "Nhap ma tran C\n"; c.input();
	cout << "Ma tran C\n"; c.output();
	do {
		
		cout << "Nhap hang muon tinh tong: "; cin >> hangk;
		if (hangk < 0 || hangk >= hang1)
		cout << "Hang muon tinh phai lon hon hoac bang 0 va nho hon so hang cua ma tran C\n";
	} while (hangk < 0 || hangk >= hang1);
	do {
		
		cout << "Nhap cot muon tinh tong:"; cin >> cotk;
		if (cotk < 0 || cotk >= cot1)
		cout << "Cot muon tinh phai lon hon hoac bang 0 va nho hon so cot cua ma tran C\n";
	} while (cotk < 0 || cotk >= cot1);
	cout << "\nTong hang " << hangk << " la: " << c.tonghangk(hangk);
	cout << "\nTong cot " << cotk << " la: " << c.tongcotk(cotk);
	cout << "\nTong 4 duong vien la: " << c.tong4duong();
	getch();
}
