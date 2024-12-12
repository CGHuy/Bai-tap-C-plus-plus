#include <iostream>
#include <conio.h>
using namespace std;

class matrix {
	public:
		int m, n;
		int **arr; // ** Khai bao con tro mang 2 chieu
	public:
		matrix() : m(0), n(0), arr {}

        matrix(int a, int b) : m(a), n(b) {
            arr = new int*[m];
            for (int i = 0; i < m; i++) {
                arr[i] = new int[n]{0};
            }
        }
        
        ~matrix() {
            for (int i = 0; i < m; i++) {
                delete[] arr[i];
            }
            delete[] arr;
        }
		
		void input() {
			cout << "\nNhap kich thuoc ma tran\n";
			cout << "Nhap so hang: "; cin >> m;
			cout << "Nhap so cot: "; cin >> n;
			
			arr = new int*[m];
            for (int i = 0; i < m; i++) {
                arr[i] = new int[n];
            }
			
			cout << "Nhap phan tu cua ma tran\n";
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					cout << "a[" << i << "][" << j << "] = ";
					cin >> arr[i][j];
				}
			}
		}
		void output() {
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					cout << arr[i][j];
					cout << "\t";
				}
				cout << "\n";
			}
		}
		friend matrix cong(matrix &a, matrix &b);
		friend int tong_hangcotk(matrix &a);
		friend int tong_4duong(matrix &a);
};

matrix cong(matrix &a, matrix &b) {
	
}

main() {
	matrix A,B,C;
	cout << "NHAP MA TRAN A";
	A.input();
	cout << "MA TRAN A LA";
	A.output();
	cout << "NHAP MA TRAN B";
	B.input();
	cout << "MA TRAN B LA";
	B.output();
	getch();
}
