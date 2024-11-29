#include <iostream>
#include <conio.h>

using namespace std;

class mang1c {
	private:
		int a[50], n;
	public:
		void input();
		void output();
		int tongchan(mang1c m);
		int max(mang1c m);
		void acs();
};

void mang1c::input() {
	cout << "Nhap so phan tu trong mang: "; cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "] = "; cin >> a[i];  
	}
}

void mang1c::output() {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

int mang1c::tongchan(mang1c m) {
	int tong = 0;
	for (int i = 0; i < n; i++) {
		if (a[i]%2==0) {
			tong += a[i];
		}
	}
	return tong;
}

int mang1c::max(mang1c m) {
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (max < a[i]) {
			max = a[i];
		}
	}
	return max;
}

void mang1c::acs() {
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

main() {
	mang1c a[10];
	a[10].input();
	cout << "-------------------------------------------\n";
	cout << "Mang vua nhap la: "; a[10].output();
	cout << "\n-------------------------------------------\n";
	cout << "Tong cac phan tu chan trong mang la: " << a[10].tongchan(a[10]);
	cout << "\n-------------------------------------------\n";
	cout << "Phan tu lon nhat trong mang la: " << a[10].max(a[10]);
	cout << "\n-------------------------------------------\n";
	cout << "Mang sau khi sap xep theo thu tu tang dan la: "; a[10].acs();
	getch();
}
