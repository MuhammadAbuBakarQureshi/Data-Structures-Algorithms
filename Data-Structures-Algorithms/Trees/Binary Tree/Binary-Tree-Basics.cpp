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

Node* build_tree_recursive(Node* root) {

	cout << "Enter the data : ";
	int data;
	cin >> data;

	if (data == -1) {

		return nullptr;
	}

	root = new Node(data);

	cout << "Enter the data for the left of " << data << endl;
	root->left = build_tree_recursive(root->left);
	cout << "Enter the data for the right of " << data << endl;
	root->right = build_tree_recursive(root->right);

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

void build_tree(Node* &root) {

	cout << "\n\n\nEnter the data : ";
	int data;
	cin >> data;

	bool condition = true;

	Node* temp = root;

	while (condition) {

		cout << "\nCurrent Node value is " << temp->data << endl;
		cout << "\nChoose side\n" <<
			"1. Left.\n" <<
			"2. Right.\n" << endl;

		Node* newNode = new Node(data);

		int option, choice;
		cin >> option;

		switch (option)
		{
		case 1:

			cout << "\n\nDo you want to add on the left of " << temp->data << " (1/0)" << endl;
			cin >> choice;

			if (choice == 1) {

				temp->left = newNode;
				return;
			}
			else if (choice == 0) {

				if (temp->left == NULL) {

					cout << "\nTree ends here" << endl;
				}
				else {

					temp = temp->left;
					cout << "\nMoving to next node having data " << temp->data << endl;
				}
			}

			break;

		case 2:

			cout << "\n\nDo you want to add on the rigth of " << temp->data << "(1/0)" << endl;
			cin >> choice;

			if (choice == 1) {

				temp->right = newNode;
				return;
			}
			else if (choice == 0) {

				if (temp->right == NULL) {

					cout << "\nTree ends here" << endl;
				}
				else {

					temp = temp->right;
					cout << "\nMoving to next node having data " << temp->data << endl;
				}
			}
			break;

		case 3:

			condition = false;
			break;

		default:
			cout << "\n\t Enter Correct option" << endl;
			break;
		}
	}
}

int binary_tree_basics() {

	/*Node* root = build_tree_recursive(nullptr);*/

	Node* root = new Node(7);

	build_tree(root);
	build_tree(root);
	build_tree(root);
	build_tree(root);
	build_tree(root);
	build_tree(root);
	build_tree(root);

	cout << "Traversing the tree." << endl;
	
	level_order_traversal(root);

	return 0;
}