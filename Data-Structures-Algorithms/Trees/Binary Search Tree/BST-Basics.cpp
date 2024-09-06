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

// bst = Binary Search Tree

void building_bst(Node* &root) {

	cout << "\n\nEnter the data : ";
	int data;
	cin >> data;

	Node* newNode = new Node(data);

	if (root == nullptr) {

		root = newNode;
		return;
	}

	bool condition = true;

	Node* temp = root;

	while (condition) {

		if (newNode->data == temp->data){
		
			cout << newNode->data << " already present in the tree." << endl;
			condition = false;
		}

		if (newNode->data < temp->data) {

			if (temp->left == nullptr) {

				temp->left = newNode;
				condition = false;
			}
			else {

				temp = temp->left;
			}

		}
		else if (newNode->data > temp->data) {

			if (temp->right == nullptr) {

				temp->right = newNode;
				condition = false;
			}
			else {

				temp = temp->right;
			}
		}
	}
}

void level_order_traversal_bst(Node* root) {

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

bool search_in_bst(Node* root) {

	cout << "\n\n\nEnter the number : ";
	int data;
	cin >> data;

	if (root == nullptr)return false;
	
	Node* temp = root;

	while (temp) {

		if (data < temp->data) {

			temp = temp->left;
		}
		else if (data > temp->data){

			temp = temp->right;
		}
		else {
			return true;
		}
	}

	return false;
}

int bst_basics() {

	Node* root = nullptr;
	
	building_bst(root);
	building_bst(root);
	building_bst(root);

	bool result = search_in_bst(root);
	(result == false) ? cout << "Number not found.\n" : cout << "Number found." << endl;
	result = search_in_bst(root);
	(result == false) ? cout << "Number not found.\n" : cout << "Number found." << endl;
	result = search_in_bst(root);
	(result == false) ? cout << "Number not found.\n" : cout << "Number found." << endl;
	result = search_in_bst(root);
	(result == false) ? cout << "Number not found.\n" : cout << "Number found." << endl;
	
	level_order_traversal_bst(root);

	return 0;
}