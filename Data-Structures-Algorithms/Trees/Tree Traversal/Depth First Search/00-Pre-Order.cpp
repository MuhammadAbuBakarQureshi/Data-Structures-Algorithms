#include <iostream>

using namespace std;

// postO == Post Order
// DFS == Depth First Search

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

void insert_at_tree_pre_order(Node* &root, int data) {

	Node* newNode = new Node(data);

	if (root == nullptr) {

		root = newNode;
		return;
	}

	Node* temp = root;

	while (true) {

		if (data < temp->data) {

			if (!temp->left) {

				temp->left = newNode;
				return;
			}
			temp = temp->left;
		}
		else if (data > temp->data) {

			if (!temp->right) {

				temp->right = newNode;
				return;
			}
			temp = temp->right;
		}
		else {

			cout << "Enter same number" << endl;
			return;
		}
	}
}

void pre_order(Node* currentNode){

	cout << currentNode->data << " ";

	if (currentNode->left)	pre_order(currentNode->left);
	
	if (currentNode->right)	pre_order(currentNode->right);
	
}

int pre_order_DFS() {

	Node* root = nullptr;

	insert_at_tree_pre_order(root, 200);
	insert_at_tree_pre_order(root, 100);
	insert_at_tree_pre_order(root, 300);
	insert_at_tree_pre_order(root, 50);
	insert_at_tree_pre_order(root, 150);
	insert_at_tree_pre_order(root, 250);
	insert_at_tree_pre_order(root, 350);

	pre_order(root);
	
	return 0;
}