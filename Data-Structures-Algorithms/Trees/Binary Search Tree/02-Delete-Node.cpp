#include <iostream>
#include <queue>

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

// ND == node deletion

void insert_in_tree_ND(Node* &root, int data){

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

			cout << "Can't store same number twice" << endl;
			return;
		}
	}
}

void level_order_traversal_ND(Node* root) {

	if (root == nullptr)return;

	queue <Node*> q;
	q.push(root);
	q.push(nullptr);

	while (!q.empty()) {

		Node* temp = q.front();
		q.pop();

		if (temp == nullptr) {

			cout << endl;
			if (!q.empty()) {

				q.push(nullptr);
			}
		}
		else {

			cout << temp->data << " ";
			if (temp->left) {
				q.push(temp->left);
			}

			if (temp->right) {
				q.push(temp->right);
			}
		}
	}
}

Node* in_order_succ(Node* iterNode){

	while (true) {

		if (iterNode->right) iterNode = iterNode->right;

		if (!iterNode->right) return iterNode;
	}

}

Node* delete_node_recursive(Node*& iterNode, int key) {

	if (key < iterNode->data) {

		iterNode->left = delete_node_recursive(iterNode->left, key);
	}
	else if (key > iterNode->data) {

		iterNode->right = delete_node_recursive(iterNode->right, key);
	}
	else {

		if (iterNode->left == nullptr) {

			Node* temp = iterNode->right;
			cout << iterNode->data << " deleted." << endl;
			delete iterNode;
			return temp;
		}
		else if (iterNode->right == nullptr) {

			Node* temp = iterNode->left;
			cout << iterNode->data << " delted." << endl;
			delete iterNode;
			return temp;
		}

		Node* temp = in_order_succ(iterNode->right);
		iterNode->data = temp->data;
		iterNode->right = delete_node_recursive(iterNode->right, temp->data);
		
	}

	return iterNode;
}

int node_deletion_BST() {

	Node* root = nullptr;

	insert_in_tree_ND(root, 47);
	insert_in_tree_ND(root, 21);
	insert_in_tree_ND(root, 74);
	insert_in_tree_ND(root, 15);
	insert_in_tree_ND(root, 35);
	insert_in_tree_ND(root, 51);
	insert_in_tree_ND(root, 98);

	delete_node_recursive(root, 74);

	level_order_traversal_ND(root);

	return 0;
}