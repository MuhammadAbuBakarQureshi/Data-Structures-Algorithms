#include <iostream>

using namespace std;

class Node {

public:

	int data;
	Node* left, * right;

	// Constructor

	Node(int data) {

		this->data = data;
		left = right = nullptr;
	}
};

// MM == maximum minimum

void insert_in_tree_MM(Node* &root, int data){

	Node* newNode = new Node(data);

	if (root == nullptr) {

		root = newNode;
		return;
	}

	Node* iterNode = root;

	while (true) {
		
		
		if (data < iterNode->data){

			if (!iterNode->left) {

				iterNode->left = newNode;
				return;
			}

			iterNode = iterNode->left;
		}
		else if (data > iterNode->data) {

			if (!iterNode->right) {

				iterNode->right = newNode;
				return;
			}

			iterNode = iterNode->right;
		}
		else {

			cout << "Can't store same number twice" << endl;
			return;
		}
	}
}

int max_in_BST(Node* root) {

	if (root == nullptr) {
		
		cout << "Tree is empty" << endl;
		return -1;
	}

	Node* iterNode = root;

	while (true) {
		
		if (iterNode->right) iterNode = iterNode->right;
		
		if (!iterNode->right) return iterNode->data;
		
	}
}

int min_in_BST(Node* root) {

	if (root == nullptr) {

		cout << "Tree is empty" << endl;
		return -1;
	}

	Node* iterNode = root;

	while (true) {

		if (iterNode->left) iterNode = iterNode->left;
		
		if (!iterNode->left) return iterNode->data;
		
	}

}

int maximum_minimum_BST() {

	Node* root = nullptr;

	insert_in_tree_MM(root, 47);
	insert_in_tree_MM(root, 21);
	insert_in_tree_MM(root, 74);
	insert_in_tree_MM(root, 15);
	insert_in_tree_MM(root, 35);
	insert_in_tree_MM(root, 51);
	insert_in_tree_MM(root, 98);

	int maximum = max_in_BST(root);

	cout << "Maximum number in BST is : " << maximum << endl;
	
	int minimum = min_in_BST(root);

	cout << "Minimum number in BST is : " << minimum << endl;

	return 0;
}