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

void insert_in_tree_post_order(Node* &root, int data){

	Node* newNode = new Node(data);

	if (!root) {

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

			cout << "You cannot enter same number twice" << endl;
			return;
		}
	}
}

int post_order_DFS(){

	Node* root = nullptr;

	insert_in_tree_post_order(root, 47);
	insert_in_tree_post_order(root, 21);
	insert_in_tree_post_order(root, 76);
	insert_in_tree_post_order(root, 18);
	insert_in_tree_post_order(root, 27);
	insert_in_tree_post_order(root, 52);
	insert_in_tree_post_order(root, 82);

	return 0;
}