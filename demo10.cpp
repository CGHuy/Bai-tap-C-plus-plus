#include <iostream>
#include <conio.h>
using namespace std;

class CANBO {
	protected:
		string id, ht;
	public:
		void input() {
				cin.ignore();
				cout << "\nNhap ma can bo: "; getline(cin,id);
				cout << "Nhap ho ten can bo: "; getline(cin,ht);
		}
		void output() {
				cout << "\n" << id << "\t" << ht << "\t";
		}
		

};

class LUONG : CANBO {
	public:
		double pc, hsl, bh;
	public:
		void input1() {
			input();
			cout << "Nhap phu cap: "; cin >> pc;
			cout << "Nhap he so luong: "; cin >> hsl;
			cout << "Nhap bao hiem: "; cin >> bh;
		}
		double luong() {
			return hsl*390000+pc-bh;
		}
		void output1() {
			output();
			cout << pc << "\t\t" << hsl << "\t\t" << bh << "\t\t" << luong();
		}
		string getid() {
			return id;
		}
};

void title() {
	cout << "\nID\tHo Ten\tPhu Cap\t\tHe So Luong\tBao Hiem\tLuong"; 
}

main() {
	LUONG a[10];
	int n;
	
	cout << "NHAP SO LUONG CAN BO: "; cin >> n;
	
	cout << "-------------------------------------------\n";
	cout << "NHAP DANH SACH LUONG CAN BO";
	for (int i = 0; i < n; i++) {
		cout << "\nCan bo thu " << i+1;
		a[i].input1();
	}
	
	cout << "-------------------------------------------\n";
	cout << "IN DANH SACH LUONG CAN BO";
	title();
	for (int i = 0; i < n; i++) {
		a[i].output1();
	}
	
	cout << "\n-------------------------------------------\n";
	cout << "IN DANH SACH CAN BO CO LUONG > 2.000.000";
	title();
	for (int i = 0; i < n; i++) {
		if (a[i].luong() > 2000000) {
			a[i].output1();
		}
	}
	
	cout << "\n-------------------------------------------\n";
	string find;
	cout << "Nhap ma can bo can tim: "; cin >> find;
	cout << "CAN BO CAN TIM LA";
	title();
	for (int i = 0; i < n; i++) {
		if(a[i].getid().compare(find)==0) {
			a[i].output1();
		}
	}
	
	getch();
}
