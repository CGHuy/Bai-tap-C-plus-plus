#include <iostream>
using namespace std;

struct BTNode {
	int data;
	BTNode *left;
	BTNode *right;
};

BTNode *makeNode(int x) {
	BTNode *newNode = new BTNode();
	newNode->data = x;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

BTNode *insert(BTNode *root, int x) {
	if (root == NULL) {
		return makeNode(x);
	}
	if (x < root->data) {
		root->left = insert(root->left, x);
	} else if (x > root->data) {
		root->right = insert(root->right, x);
	} else {
		cout << "Da ton tai gia tri nay trong cay!" << endl;
	}
	return root;
}

BTNode *find(BTNode *root, int x) {
	if (root == NULL) {
		return NULL;
	}
	if (x < root->data) {
		return find(root->left, x);
	} else if (x > root->data) {
		return find(root->right, x);
	} else {
		return root;
	}
}

BTNode *findMin(BTNode *root) {
	if (root == NULL) {
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

void inOder(BTNode *root) {
	if (root != NULL) {
		inOder(root->left);
		cout << root->data << " ";
		inOder(root->right);
	}
}

void postOder(BTNode *root) {
	if (root != NULL) {
		postOder(root->left);
		postOder(root->right);
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

