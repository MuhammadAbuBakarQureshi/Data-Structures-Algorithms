#include <iostream>

using namespace std;

class Node {

public:

	int data;
	Node* left, * right;

	// constructor

	Node(int data) {

		this->data = data;
		left = right = nullptr;
	}
};

void insert_in_tree_in_order(Node* &root, int data) {
	
	Node* newNode = new Node(data);

	if (root == nullptr) {

		root = newNode;
		return;
	}

	Node* iterNode = root;

	while (true) {

		if (data < iterNode->data) {

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

			cout << "Can't store same data twice" << endl;
			return;
		}
	}
}

void in_order(Node* iterNode) {
	
 	if (iterNode->left)	in_order(iterNode->left);
	
	cout << iterNode->data << " ";
	
	if (iterNode->right) in_order(iterNode->right);
}

int in_order_DFS() {

	Node* root = nullptr;

	insert_in_tree_in_order(root, 100);
	insert_in_tree_in_order(root, 50);
	insert_in_tree_in_order(root, 150);
	insert_in_tree_in_order(root, 25);
	insert_in_tree_in_order(root, 75);
	insert_in_tree_in_order(root, 125);
	insert_in_tree_in_order(root, 175);

	in_order(root);

	return 0;
}