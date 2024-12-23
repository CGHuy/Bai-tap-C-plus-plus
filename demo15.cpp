#include <iostream>
#include <conio.h>
using namespace std;

template <class val> void swap1(val &a, val&b) {
	val tg;
	tg = a;
	a = b;
	b = tg;
}

main() {
	int x = 4, y = -5;
	float a = 0.5, b = 1.2;
	swap1(x,y);
	cout << "x = " << x << "\ty = " << y << endl;
	swap1(a,b);
	cout << "a = " << a << "\tb = " << b << endl;
	getch();
}
