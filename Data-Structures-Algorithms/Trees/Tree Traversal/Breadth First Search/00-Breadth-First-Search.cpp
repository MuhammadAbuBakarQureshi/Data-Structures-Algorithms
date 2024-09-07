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

// BFS == breath first search

void insert_at_tree_BFS(Node* &root, int data) {

	Node* newNode = new Node(data);

	if (root == nullptr) {

		root = newNode;
		return;
	}

	Node* temp = root;

	while (true) {

		if (data < temp->data) {

			if (temp->left == nullptr) {

				temp->left = newNode;
				return;
			}

			temp = temp->left;
		}
		else if (data > temp->data) {

			if (temp->right == nullptr) {

				temp->right = newNode;
				return;
			}

			temp = temp->right;
		}
		else {

			cout << "Same values cannot added in same tree" << endl;
			return;
		}
	}
}

int breadth_first_search() {

	// Creating Tree

	Node* root = nullptr;

	insert_at_tree_BFS(root, 100);
	insert_at_tree_BFS(root, 50);
	insert_at_tree_BFS(root, 150);
	insert_at_tree_BFS(root, 25);
	insert_at_tree_BFS(root, 75);
	insert_at_tree_BFS(root, 125);
	insert_at_tree_BFS(root, 175);

	queue<Node*> queue;
	queue.push(root);
	queue.push(nullptr);
	
	while (!queue.empty()) {

		if (queue.front()->left != nullptr)	queue.push(queue.front()->left);
		
		if (queue.front()->right != nullptr) queue.push(queue.front()->right);
		

 		if (!queue.empty()) {

			cout << queue.front()->data << " ";
			queue.pop();

			if (queue.front() == nullptr) {

				cout << endl;
				queue.pop();

				if (!queue.empty()) queue.push(nullptr);
			}
		}

	}
	
	return 0;
}