#include <iostream>
using namespace std;

class stack {
	private:
		int max;
		int top;
		int *arr;
	public:
		stack(int size) {
			arr = new int[size];
			max = size;
			top = -1;
		}
		bool isEmpty() {
			if (top == -1) {
				return true;
			} else {
				return false;
			}
		}
		bool isFull() {
			if (top == max-1) {
				return true;
			} else {
				return false;
			}
		}
		bool push(int x) {
			if (!isFull()) {
				top++;
				arr[top] = x;
				return true;
			} else {
				return false;
			}
		}
		bool pop() {
			if (!isEmpty()) {
				top--;
				return true;
			} else {
				return false;
			}
		}
		int arr_top() {
			if(isEmpty()) {
				cout << "Stack rong";
				return -1;
			} else {
				return arr[top];
			}
		}
};

void DecimalToBinary(int &n) {
	if (n < 100) {
		cout << "Vui long nhap so co 3 chu so!";
		return;
	}
	stack ds(20);
	while (n > 0) {
		ds.push(n%2);
		n = n/2;
	}
	cout << "Day so nhi phan la: ";
	while (!ds.isEmpty()) {
		cout << ds.arr_top();
		ds.pop();
	}
}

int main() {
	int n;
	cout << "Nhap so co 3 chu so: "; cin >> n;
	DecimalToBinary(n);
	return 0;
}
