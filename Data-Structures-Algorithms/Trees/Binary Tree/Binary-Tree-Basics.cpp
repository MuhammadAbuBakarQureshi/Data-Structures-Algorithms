#include <iostream>
#include <queue>

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

Node* build_tree(Node* root) {

	cout << "Enter the data : ";
	int data;
	cin >> data;

	if (data == -1) {

		return NULL;
	}

	root = new Node(data);
	
	cout << "Enter data for inserting in the left " << data << endl;
	root->left = build_tree(root->left);
	cout << "Enter data for inserting in the right " << data << endl;
	root->right = build_tree(root->right);

	return root;
}

void level_order_traversal(Node* root) {

	queue <Node*> q;
	q.push(root);
	q.push(nullptr);

	while (!q.empty()) {

		Node* temp = q.front();
		q.pop();

		if (temp == nullptr) {

			cout << "\t" << endl;
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

int binary_tree_basics() {

	Node* root = build_tree(nullptr);

	cout << "Traversing the tree." << endl;
	
	level_order_traversal(root);

	return 0;
}