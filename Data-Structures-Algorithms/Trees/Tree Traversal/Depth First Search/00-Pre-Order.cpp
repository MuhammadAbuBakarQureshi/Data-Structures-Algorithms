#include <iostream>

using namespace std;

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

void insert_at_tree_DFS(Node* &root, int data) {

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

void pre_order_DFS_recursive(Node* currentNode){

	cout << currentNode->data << " ";

	if (currentNode->left)	pre_order_DFS_recursive(currentNode->left);
	
	if (currentNode->right)	pre_order_DFS_recursive(currentNode->right);
	
}

int pre_order_DFS() {

	Node* root = nullptr;

	insert_at_tree_DFS(root, 200);
	insert_at_tree_DFS(root, 100);
	insert_at_tree_DFS(root, 300);
	insert_at_tree_DFS(root, 50);
	insert_at_tree_DFS(root, 150);
	insert_at_tree_DFS(root, 250);
	insert_at_tree_DFS(root, 350);

	pre_order_DFS_recursive(root);
	
	return 0;
}