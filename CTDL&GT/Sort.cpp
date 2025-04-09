#include <iostream>
using namespace std;

void SelectionSort(int a[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        swap(a[i], a[min]);
    }
}

void BubbleSort(int a[], int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = n-1; j > i; j--) {
			if (a[j] < a[j-1]) {
				swap(a[j], a[j-1]);
			}
		}
	}
}

void InsertionSort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int key = a[i];
		int pos = i-1;
		while (pos >= 0 && a[pos] > key) {
			a[pos+1] = a[pos];
			pos--;
		}
		a[pos+1] = key;
	}
}

void InterchangeSort(int a[], int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (a[i] > a[j]) {
				swap(a[i], a[j]);
			}
		}
	}
}

void QuickSort(int a[], int left, int right) {
	if (left >= right) return;
	
	int pivot = a[(left+right)/2];
	int i = left, j = right;
	
	while (i <= j) {
		while (a[i] < pivot) i++;
		while (a[j] > pivot) j--;
		if (i <= j) {
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	
	if(left < j) QuickSort(a,left,j);
	if(i < right) QuickSort(a,i,right);
}

void Heapify(int a[], int n, int i) { // i la root
	int largest = i;
	int left = 2*i+1;
	int right = 2*i+2;
	if (left < n && a[left] > a[largest]) largest = left;
	if (right < n && a[right] > a[largest]) largest = right;
	if (largest != i) {
		swap(a[i], a[largest]);
		Heapify(a, n, largest);
	}
}

void HeapSort(int a[], int n) {
	for (int i = n/2-1; i >= 0; i--) { // Xay dung max heap, goi ham Heapify tu duoi len
		Heapify(a, n, i);
	}
	for (int i = n-1; i >= 0; i--) {
		swap(a[0], a[i]);
		Heapify(a, i, 0); // Heapify mang co so luong pt la i va Heapify tu  pt 0 de day gia tri nho nhat xuong duoi
	}
}

int main() {
    int a[100], n;
    
    cout << "Nhap so luong phan tu cua mang: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
    	cout << "a[" << i+1 << "] = ";
    	cin >> a[i];
	}
    
    HeapSort(a, n);

    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
