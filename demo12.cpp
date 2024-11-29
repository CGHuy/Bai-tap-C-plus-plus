#include <iostream>
#include <conio.h>
using namespace std;

class MANG {
	private:
		string name;
		int n, a[50];
	public:
		void input() {
			fflush(stdin);
			cout << "Nhap ten mang: "; getline(cin, name);
			cout << "Nhap so phan tu cua mang: "; cin >> n;
			for (int i = 0; i < n; i++) {
				cout << "a[" << i+1 << "] = "; cin >> a[i];
			}
		}
		void output() {
			for (int i = 0; i < n; i++) {
				cout << "\na[" << i+1 << "]: " << a[i];
			}
		}
		void tongchan() {
			int tong = 0;
			for (int i = 0; i < n; i++) {
				if (a[i] % 2 == 0) {
					tong += a[i];
				}
			}
			cout << "TONG CHAN LA: " << tong;
		}
		void max() {
			int max = a[0];
			for (int i = 0; i < n; i++) {
				if (max < a[i]) {
					max = a[i];
				}
			}
			cout << "MAX LA: " << max;
		}
		void sx() {
			for (int i = 0; i < n-1; i++) {
				for (int j = i+1; j < n; j++) {
					if (a[i] > a[j]) {
						int temp = a[i];
						a[i] = a[j];
						a[j] = temp;
					}
				}
			}
			output();
		}
};

main() {
	MANG a;
	cout << "NHAP MANG\n";
	a.input();
	cout << "-----------------------------------\n";
	cout << "IN MANG";
	a.output();
	cout << "\n-----------------------------------\n";
	a.tongchan();
	cout << "\n-----------------------------------\n";
	a.max();
	cout << "\n-----------------------------------\n";
	cout << "MANG SAU KHI SAP XEP LA: ";
	a.sx();
	getch();
}


