#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;

class sophuc {
	private:
		int PT, PA;
	public:
		void input();
		void output();
		sophuc tong(sophuc sp2);
		sophuc hieu(sophuc sp2);
		float modun();
};

void sophuc::input() {
	cout << "Nhap phan thuc: "; cin >> PT;
	cout << "Nhap phan ao: "; cin >> PA;
}

void sophuc::output() {
	if (PA >= 0)
		cout << PT << "+" << PA <<"i";
	else if (PA < 0)
		cout << PT << PA <<"i";
}

sophuc sophuc::tong(sophuc sp2) {
	sophuc t;
	t.PT = PT + sp2.PT;
	t.PA = PA + sp2.PA;
	return t;
}

sophuc sophuc::hieu(sophuc sp2) {
	sophuc t;
	t.PT = PT - sp2.PT;
	t.PA = PA - sp2.PA;
	return t;
}

float sophuc::modun() {
	return abs(sqrt(PT*PT+PA*PA));
}

main() {
	sophuc a[10];
	int n;
	cout << "Nhap so luong so phuc: "; cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "\nSo phuc thu " << i+1 << "\n"; a[i].input();
	}
	for (int i = 0; i < n; i++) {
		cout << "\nSo phuc thu " << i+1 << " la: "; a[i].output();
	}
	float max = a[0].modun();
	int idx = 0;
	for (int i = 0; i < n; i++) {
		if (max < a[i].modun()) {
			max = a[i].modun();
			idx = i;
		}
	}
	cout << "\n\nSo phuc co modun lon nhat la: "; a[idx].output();
	getch();
}
