#include <iostream>
#include <conio.h>
using namespace std;

class A {
	private:
		int n;
	public:
		A() {
			n = 0;
		}
		A(int a) {
			n = a;
		}
		virtual void output() {
			cout << "Lop A: " << n;
		}
		int getn() {
			return n;
		}
};

class B : public A {
	public:
		B():A() {}
		B(int a):A(a) {}
		void output() {
			cout << "\nLop B: " << getn();
		}
};

class C : public A {
	public:
		C():A() {}
		C(int a):A(a) {}
		void output() {
			cout << "\nLop C: " << getn();
		}
};

class D : public C {
	public:
		D():C() {}
		D(int a):C(a) {}
		void output() {
			cout << "\nLop D: " << getn();
		}
};

void hien(A *p) {
	p->output();
}

main() {
	A a(2);
	B b(4);
	C c(6);
	D d(8);
	hien(&a);
	hien(&b);
	hien(&c);
	hien(&d);
	getch();
}
