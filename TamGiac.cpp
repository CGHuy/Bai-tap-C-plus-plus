#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;

class DIEM {
	protected:
		float x, y;
	public:
		DIEM() {
			x = y = 0;
		}
		DIEM(float x, float y) {
			this->x = x;
			this->y = y;
		}
		void input();
		void output();
		float kc2d(DIEM a);
};

void DIEM::input() {
	cout << "\nToa do x = "; cin >> x;
	cout << "Toa do y = "; cin >> y;
}

void DIEM::output() {
	cout << "(" << x << "," << y << ")";
}
		
float DIEM::kc2d(DIEM a) {
	float kc;
	kc = sqrt(pow(a.x-x,2)+pow(a.y-y,2));
	return kc;
}

class TAM_GIAC : public DIEM {
	private:
		DIEM a,b,c;	
	public:
		void nhapdiem() {
			cout << "\nNhap diem A"; a.input();
			cout << "Nhap diem B"; b.input();
			cout << "Nhap diem C"; c.input();
		}
		void xuatdiem() {
			cout << "\nDiem A co toa do la: "; a.output();
			cout << "\nDiem B co toa do la: "; b.output();
			cout << "\nDiem C co toa do la: "; c.output();
		}
		void kt_tamgiac() {
			float c1, c2, c3;
			c1 = a.kc2d(b);
			c2 = b.kc2d(c);
			c3 = c.kc2d(a);
			if (c1>0&&c2>0&&c3>0&&(c1+c2>c3)&&(c2+c3>c1)&&(c3+c1>c2)) {
				cout << "\nLa tam giac ";
				if (c1==c2==c3) {
					cout << "deu";
				} else if (c1==c2 || c2 == c3 || c3 == c1) {
					cout << "can";
				} else if ((c1=c2*c2+c3*c3)||(c2=c1*c1+c3*c3)||(c3=c1*c1+c2*c2)) {
					cout << "vuong";
				}
			} else {
				cout << "\nKhong phai la tam giac";
			}
		}
		float cv_tamgiac() {
			float c1, c2, c3;
			c1 = a.kc2d(b);
			c2 = b.kc2d(c);
			c3 = c.kc2d(a);
			return c1+c2+c3;
		}
		float dt_tamgiac() {
			float c1, c2, c3, p;
			c1 = a.kc2d(b);
			c2 = b.kc2d(c);
			c3 = c.kc2d(a);
			p = (c1+c2+c3)/2;
			return sqrt(p*(p-c1)*(p-c2)*(p-c3));
		}
};


main() {
	TAM_GIAC a[10];
	int n;
	cout << "Nhap so luong tam giac: "; cin >> n;
	cout << ("\n----------Nhap danh sach tam giac----------\n");
	for (int i=0; i<n; i++) {
		cout << "\nTam giac thu " << i+1; a[i].nhapdiem();
	}
	cout << ("\n----------Danh sach tam giac----------\n");
	for (int i=0; i<n; i++) {
		cout << "\nTam giac thu " << i+1;
		a[i].xuatdiem();
		a[i].kt_tamgiac();
		cout << "\nChu vi tam giac la: " << a[i].cv_tamgiac();
		cout << "\nDien tich tam giac la: " << a[i].dt_tamgiac();
		cout << "\n";	
	}
	cout << ("\n----------Tam giac co chu vi lon nhat----------\n");
	float cv_max = a[0].cv_tamgiac();
	int index = 0;
	for (int i=0; i<n; i++) {
		if (cv_max < a[i].cv_tamgiac()) {
			cv_max = a[i].cv_tamgiac();
			index = i;
		}
	cout << "Tam giac thu " << index+1;
	cout << "Co chu vi la: " << a[index].cv_tamgiac();
	}
	getch();
}
