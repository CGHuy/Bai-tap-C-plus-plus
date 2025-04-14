#include <iostream>
using namespace std;

typedef struct NODE {
	int data;
	NODE *next;
} NODE;

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

void pushFront(NODE &*head, int x) {
	NODE *newNode = makeNode(x);
	newNode->next = *head;
	head = newNode;
}

void insert_After(NODE &*head, NODE *M, int x) {
	NODE *newNode = makeNode(x);
	if (M == NULL) {
		cout << "\nKhong the them duoc";
		return;
	}
	if (head == NULL) { // list chua co phan tu
		pushFront(head,x);
		return;
	} else { // them newNode
		newNode->next = M->next;
		M->next = newNode;
	}
}

void insert_Before(NODE &*head, NODE *M, int x) {
	NODE *newNode = makeNode(x);
	if (M == NULL) {
		cout << "\nKhong the them duoc";
		return;
	}
	if (head == NULL) { // neu list rong thi pushFront luon
		pushFront(head,x);
		return;
	} else { // them newNode nhu insert_After va doi du lieu cua newNode va M
		newNode->next = M->next;
		M->next = newNode;
		newNode->data = M->data;
		M->data = x;
	}
}

void addTrcViTriK(NODE **head, int k, int x) {
	if (k < 1) {
		cout << "\nKhong ton tai vi tri K";
		return;
	}
	NODE *temp = *head;
	for (int i = 1; i < k; i++) {
		if (temp->next == NULL) {
			cout << "\nVi tri vuot qua do dai danh sach";
			return;
		}
		temp = temp->next;
	}
	insert_Before(head,temp,x);
}

void addSauViTriK(NODE **head, int k, int x) {
	if (k < 1) {
		cout << "\nKhong ton tai vi tri K";
		return;
	}
	NODE *temp = *head;
	for (int i = 1; i < k; i++) {
		if (temp->next == NULL) {
			cout << "\nVi tri vuot qua do dai danh sach";
			return;
		}
		temp = temp->next;
	}
	insert_After(head,temp,x);
}

bool search(NODE *head, int x) {
	if (head == NULL) {
		cout << "\nDanh sach lien ket rong";
		return false;
	}
	if (head != NULL) {
		int index = 1;
		while (head->next != NULL && head->data != x) { // head != NULL phai kiem tra truoc
			head = head->next;
			index++;
		}
		if (head->next == NULL) {
			cout << "\nKhong ton tai phan tu " << x;
			return false;
		}
		cout << "\nTon tai phan tu " << x << " o vi tri thu " << index;
		return true;
	}
}

void xoa(NODE &*head, NODE *p) {
	if (head == NULL || p == NULL) {
		cout << "\nDanh sach rong hoac con tro rong";
		return;
	}
	if (head == p) {
		head = p->next;
		delete p;
		return;
	}
	NODE *temp = *head;
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

void xoaViTriK(NODE **head, int k) {
	if (k < 1) {
		cout << "\nKhong ton tai vi tri K";
		return;
	}
	NODE *temp = *head;
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
        pushFront(&a, x);
    }
    
    cout << "\nDanh sach truoc khi xoa: ";
    scan(a);

    cout << "\nXoa vi tri 4...";
    xoaViTriK(&a, 4);
    
    cout << "\nDanh sach sau khi xoa: ";
    scan(a);

    search(a, 5);

    return 0;
}
