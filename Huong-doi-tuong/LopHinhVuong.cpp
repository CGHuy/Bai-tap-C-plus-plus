#include <iostream>
#include <conio.h>
using namespace std;

class HV {
	protected:
		int c1;
	public:
		HV() {
			c1 = 0;
		}
		HV(int c1) {
			this->c1 = c1;
		}
		void input() {
			cout << "- do dai canh: "; cin >> c1;
		}
		void output() {
			cout << "Hinh vuong canh " << c1 << ", Chu vi: " << cvHV() << ", Dien tich: " << dtHV();
		}
		int cvHV() {
			return c1*4;
		}
		int dtHV() {
			return c1*c1;
		}
};
 
class HCN : public HV {
	private:
		int c2;
	public:
		HCN() {
			c2 = 0;
		}
		HCN(int c2) {
			this->c2 = c2;
		}
		void input() {
			cout << "Nhap do dai canh thu nhat: "; cin >> c1;
			cout << "Nhap do dai canh thu hai: "; cin >> c2;
		}
		void output() {
			cout << "Hinh chu nhat canh " << c1 << "-" << c2 << ", Chu vi: " << cvHCN() << ", Dien tich: " << dtHCN();
		}
		int cvHCN() {
			return (c1+c2)*2;
		}
		int dtHCN() {
			return c1*c2;
		}
};

main() {
	int n, m;
	HV a[50];
	HCN b[50];
	cout << "NHAP SO LUONG HINH VUONG: "; cin >> m;
	
	cout << "-------------------------------";
	cout << "\nNHAP DO DAI CANH CUA HINH VUONG\n";
	for (int i = 0; i < m; i++) {
		cout << "Hinh vuong thu " << i+1 << " ";
		a[i].input();
	}
	
	int maxDTHV = a[0].dtHV();
	int index = 0;
	for (int i = 0; i < m; i++) {
		if (maxDTHV < a[i].dtHV()) {
			maxDTHV = a[i].dtHV();
			index = i;
		}
	}
	cout << "--------------------------------";
	cout << "\nHINH VUONG CO DIEN TICH LON NHAT\n";
	a[index].output();
	cout << " vi tri thu " << index + 1;
	
	cout << "\n------------------------------";
	cout << "\nNHAP SO LUONG HINH CHU NHAT: "; cin >> n;
	
	cout << "----------------------------------";
	cout << "\nNHAP DO DAI CANH CUA HINH CHU NHAT\n";
	for (int i = 0; i < n; i++) {
		cout << "Hinh chu nhat thu " << i + 1 << "\n";
		b[i].input();
	}
	
	cout << "------------------------------------------------------------";
	cout << "\nDANH SACH HINH CHU NHAT SAU KHI SAP XEP THEO CHU VI GIAM DAN";
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (b[i].cvHCN() < b[j].cvHCN()) {
				HCN temp = b[i];
				b[i] = b[j];
				b[j] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << "\n";
		b[i].output();
	}
	
	getch();
}

