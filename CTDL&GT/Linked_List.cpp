#include <iostream>
using namespace std;

struct NODE {
	int data;
	NODE *next;
};

NODE *makeNode(int x) {
	NODE *newNode = new NODE();
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

// Duyet danh sach
void scan(NODE *a) {
	while (a != NULL) {
		cout << a->data << " ";
		a = a->next;
	}
}

void pushFront(NODE *&head, int x) {
	NODE *newNode = makeNode(x);
	newNode->next = head;
	head = newNode;
}

void insertAfter(NODE *&head, NODE *p, int x) {
	NODE *newNode = makeNode(x);
	if (p == NULL) {
		cout << "\nKhong the them duoc";
		return;
	}
	newNode->next = p->next;
	p->next = newNode;	
}

void insertAfterK(NODE *&head, int k, int x) {
	if (k < 1) {
		cout << "\nKhong ton tai vi tri K";
		return;
	}
	NODE *temp = head;
	for (int i = 1; i < k; i++) {
		if (temp->next == NULL) {
			cout << "\nVi tri vuot qua do dai danh sach";
			return;
		}
		temp = temp->next;
	}
	insertAfter(head,temp,x);
}

void xoa(NODE *&head, NODE *p) {
	if (head == NULL || p == NULL) {
		cout << "\nDanh sach rong hoac con tro rong";
		return;
	}
	if (p == head) {
		head = p->next;
		delete p;
		return;
	}
	NODE *temp = head;
	while (temp->next != NULL && temp->next != p) {
		temp = temp->next;
	}
	if (temp->next == NULL) {
		cout << "\nKhong tim thay nut can xoa";
		return;
	}
	temp->next = p->next;
	delete p; 
}

void xoaK(NODE *&head, int k) {
	if (k < 1) {
		return;
	}
	NODE *temp = head;
	for (int i = 1; i < k; i++) {
		if (temp->next == NULL) {
			cout << "\nVi tri vuot qua do dai danh sach";
			return;
		}
		temp = temp->next;
	}
	xoa(head,temp);
}

int main() {
	NODE *a = NULL;
    int n;
    cout << "Nhap so luong phan tu cua danh sach: "; cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cout << "Nhap phan tu thu " << i << ": "; cin >> x;
        pushFront(a, x);
    }
    
    cout << "\nDanh sach truoc khi chinh sua: ";
    scan(a);

    cout << "\nAdd gia tri 5 sau vi tri thu 4: ";
    insertAfterK(a, 4, 5);
    scan(a);
    
    cout << "\nXoa vi tru thu 3: ";
    xoaK(a,3);
    scan(a);
    
    return 0;
}
