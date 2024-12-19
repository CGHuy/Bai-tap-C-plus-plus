#include <iostream>
#include <conio.h>
using namespace std;

class matrix {
	public:
		int m, n;
		int **x; // ** Khai bao con tro mang 2 chieu
	public:
		matrix() {
			m = 0;
			n = 0;
		}

        matrix(int a, int b) : m(a), n(b) {
            x = new int*[m];
            for (int i = 0; i < m; i++) {
                x[i] = new int[n]{0};
            }
        }
        
        ~matrix() {
            for (int i = 0; i < m; i++) {
                delete[] x[i];
            }
            delete[] x;
        }
		
		void input() {
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					cout << "a[" << i << "][" << j << "] = ";
					cin >> x[i][j];
				}
			}
		}
		
		void output() {
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					cout << x[i][j] << "\t";
				}
				cout << "\n";
			}
		}
		friend matrix cong(matrix &a, matrix &b);
		friend int tong_hangcotk(matrix &a, int &k);
		friend int tong_4duong(matrix &a);
};

matrix cong(matrix &a, matrix &b) {
	if ((a.n != b.n) || (a.m != b.m)) {
		cout << "Hai ma tran khong cung cap";
		return matrix(); // tra ve matrix 0x0
	}
	matrix kq;
	for (int i = 0; i < a.m; i++) {
		for (int j = 0; j < a.n; j++) {
			kq.x[i][j] = a.x[i][j] + b.x[i][j];
		}
	}
	return kq;
}

int tong_hangcotk(matrix &a, int &k) {
	if (k < a.m || k < a.n) {
		cout << "K phai lon hon m va n";
	}
	int tong = 0;
	for (int i = 0; i < a.m; i++) {
		for (int j = 0; j < a.n; j++) {
			if (i == k || j == k) {
				tong += a.x[i][j];
			}
		}
	}
	return tong;
}

int tong_4duong(matrix &a) {
	int tong;
	for (int i = 0; i < a.m; i++) {
		tong += a.x[i][0];
		if (a.n > 1) {
			tong += a.x[i][a.n-1];
		}
	}
	for (int i = 1; i < a.n-1; i++) {
		tong += a.x[0][i];
		if (a.m > 1) {
			tong += a.x[a.m-1][i];
		}
	}
	return tong;
}

main() {
	matrix A,B,C;
	int m,n,k;
	cout << "Nhap so hang m = "; cin >> m;
	cout << "Nhap so cot n = "; cin >> n;
	cout << "\nNhap ma tran A";
	A.input();
	cout << "\nMa tran A la";
	A.output();
	cout << "\nNhap ma tran B";
	B.input();
	cout << "\nMa tran B la";
	B.output();
	cout << "\nMa tran A + B la";
	C = cong(A,B);
	C.output();
	cout << "Nhap k: "; cin >> k;
	tong_hangcotk(C,k);
	tong_4duong(C);
	
	getch();
}
