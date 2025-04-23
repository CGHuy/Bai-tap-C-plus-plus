#include <iostream>
using namespace std;

struct BTN{
	int data;
	BTN *left;
	BTN *right;
};

BTN *makeNode(int x) {
	BTN *newNode = new BTN();
	newNode->data = x;
	newNode->right = NULL;
	newNode->left = NULL;
	return newNode;
}

BTN *insert(BTN *root, int x) {
	if (root == NULL) {
		return makeNode(x);
	} else {
		if (x > root->data) {
			root->right = insert(root->right,x);
		} else if (x < root->data) {
			root->left = insert(root->left,x);
		} else {
			cout << "Gia tri da ton tai";
			return root;
		}
	}
}

BTN *find(BTN *root, int x) {
	if (root == NULL) {
		return NULL;
	} else {
		if (x > root->data) {
			return find(root->right,x);
		} else if (x < root->data) {
			return find(root->left,x);
		} else {
			return root;
		}
	}
}

int findMax(BTN *root) {
	if (root == NULL) {
		return -1;
	}
	while (root->right != NULL) {
		root = root->right;
	}
	return root->data;
}

int findMin(BTN *root) {
	if (root == NULL) {
		return -1;
	}
	while (root->left != NULL) {
		root = root->left;
	}
	return root->data;
}

void preOrder(BTN *root) {
	if (root != NULL) {
		cout << root->data << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(BTN *root) {
	if (root != NULL) {
		inOrder(root->left);
		cout << root->data << " ";
		inOrder(root->right);
	}
}

void postOrder(BTN *root) {
	if (root != NULL) {
		postOrder(root->left);
		postOrder(root->right);
		cout << root->data << " ";
	}
}

int main() {
	BTNode *a = NULL;
	a = insert(a, 9);
	a = insert(a, 5);
	a = insert(a, 4);
	a = insert(a, 7);
	a = insert(a, 10);
	a = insert(a, 20);
	a = insert(a, 1);
	a = insert(a, 18);
	a = insert(a, 11);
	a = insert(a, 17);
	
	cout << "\nKet qua duyet cay theo thu tu truoc la: ";
	preOrder(a);
	cout << "\nKet qua duyet cay theo thu tu giua la: ";
	inOder(a);
	cout << "\nKet qua duyet cay theo thu tu sau la: ";
	postOder(a);
	
	int x = 11;
	BTNode *kq = find(a,x);
	if (kq != NULL) {
		cout << "\nTim thay gia tri " << x << " trong cay";
	} else {
		cout << "\nKhong tim thay gia tri " << x << " trong cay";
	}
	
	return 0;
}
