#include <iostream>
using namespace std;

struct Stack {
	int data[50];
	int top;
};

void Init(Stack &s) {
	s.top = -1;
}

bool IsFull(Stack &s) {
	return s.top == 50 - 1;
}

bool IsEmpty(Stack &s) {
	return s.top == -1;
}

void Push(Stack &s, int x) {
	if (IsFull(s)) {
		cout << "Stack is full!";
		return;
	}
	s.data[++s.top] = x;
}

int Pop(Stack &s) {
	if (IsEmpty(s)) {
		cout << "Stack is empty";
		return -1;
	}
	return s.data[s.top--];
}

void DecimalToBinary(int &n) {
	if (n < 100) {
		cout << "Vui long nhap so co 3 chu so!";
		return;
	}
	Stack s;
	Init(s); // Khoi tao stack s
	while (n > 0) {
		Push(s,n%2);
		n = n/2;
	}
	cout << "Day so nhi phan la: ";
	while (!IsEmpty(s)) {
		cout << Pop(s);
	}
}

int main() {
	int n;
	cout << "Nhap so co 3 chu so: "; cin >> n;
	DecimalToBinary(n);
	return 0;
}
