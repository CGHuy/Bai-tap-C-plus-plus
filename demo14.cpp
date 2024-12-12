#include <iostream>
#include <conio.h>
using namespace std;

class PRODUCT {
	protected:
		string tensp;
		int gia;
		string DVT;
	public:
		virtual void output() const = 0;
};

class ELECTRONIC : public PRODUCT {
	protected:
		int nambh;
	public:
		void input() {
			cout << "Nhap ten san pham: "; fflush(stdin); getline(cin, tensp);
			cout << "Nhap gia san pham: "; cin >> gia;
			cout << "Nhap don vi tinh: "; fflush(stdin); getline(cin, DVT);
			cout << "Nhap nam bao hanh: "; cin >> nambh;
		}
		void output() const override {
			cout << "\nTen\t\tGia\t\tDVT\t\tNamBH";
			cout << "\n" << tensp << "\t\t" << gia << "\t\t" << DVT << "\t\t" << nambh;
		}
};

class CLOTHING : public PRODUCT {
	private:
		string sz, ms, chat;
	public:
		void output() const override {
			cout << "\nTen\t\tGia\t\tDVT\t\tSize\t\tColor\t\tMaterial";
			cout << "\n" << tensp << "\t\t" << gia << "\t\t" << DVT << "\t\t" << sz << "\t\t" << ms << "\t\t" << chat;
		}
};

main() {
	ELECTRONIC a[5];
	for (int i = 0; i < 2; i++) {
		a[i].input();
	}
	for (int i = 0; i < 2; i++) {
		a[i].output();
	}
	getch();
}
