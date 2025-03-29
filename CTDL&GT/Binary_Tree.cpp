#include <iostream>
using namespace std;

struct BTNode {
	int data;
	BTNode *left;
	BTNode *right;
};

BTNode *makeNode(int x) {
	BTNode *newNode = new BTNode();
	newNode->data = x	;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

int insert(BTNode *&root, int x) {
	if (root == NULL) { // TH1: root rong
		root = new BTNode(); // tao node moi hoac dung ham makeNode
		if (root == NULL) {
			cout << "Loi cap phat bo nho!";
			return -1;
		} else {
			root->data = x;
			root->left = NULL;
			root->right = NULL;
			return 1;
		}
	} else { // TH2: root khong rong
		if (x == root->data) { // ton tai gia tri cua x trong cay
			cout << "Da ton tai gia tri nay trong cay!";
			return 0;
		} else { // khong ton tai gia tri cua x trong cay
			if (x < root->data) {
				return insert(root->left,x); // goi de quy de chen sang ben trai
			} else {
				return insert(root->right,x); // goi de quy de chen sang ben phai
			}
		}
	}
}

BTNode *find(BTNode *root, int x) {
	if (root == NULL) {
		cout << "\nCay rong";
		return NULL;
	}
	if (x < root->data) {
		return find(root->left,x);
	} else if (x > root->data) {
		return find(root->right,x);
	} else {
		return root;
	}
}

BTNode *findMin(BTNode *root) {
	if (root == NULL) {
		cout << "\nCay rong";
		return NULL;
	}
	while (root->left != NULL) {
		root = root->left;
	}
	return root;
}

BTNode *findMax(BTNode *root) {
	if (root == NULL) {
		return NULL;
	}
	while (root->right != NULL) {
		root = root->right;
	}
	return root;
}

void preOrder(BTNode *root) {
	if (root != NULL) {
		cout << root->data << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

int *xoa(BTNode *&root, int x) {
    if (root == NULL) {
        cout << "\nCay rong";
        return 0;
    }
    if (x < root->data) {
        root->left = xoa(root->left, x); // De quy sang ben trai
    } else if (x > root->data) {
        root->right = xoa(root->right, x); // De quy sang ben phai
    } else { // Tim ra phan tu can xoa
        // Node can xoa co 1 con
        if (root->left == NULL) {
            root->data = root->right;
        } else if (root->right == NULL) {
            root->data = root->left;
        }
        // Node can xoa co 2 con
        BTNode *temp = findMax(root->left); // Tim node max ben trai
        root->data = temp->data; // Sao chep gia tri max vao root
        root->left = xoa(root->left, temp->data); // Xoa node duoc sao chep
    }
    return 1;
}


int main() {
	BTNode *a = NULL;
	insert(a,9);
	insert(a,5);
	insert(a,4);
	insert(a,7);
	insert(a,10);
	cout << "\nKet qua duyet cay: ";
	preOrder(a);
	return 0;
}
