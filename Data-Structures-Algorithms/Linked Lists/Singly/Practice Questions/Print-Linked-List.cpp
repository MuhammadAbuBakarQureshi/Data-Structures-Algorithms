#include <iostream>

using namespace std;

class Node {

public:

	int data;
	Node* next;

	// Constructor

	Node(int data) {

		this->data = data;
		next = NULL;
	}
};

void insert(Node*& head, int newData) {

	Node* n = new Node(newData);

	/*for (Node* iterNode = head; iterNode != NULL; iterNode = iterNode->next) {

		if (iterNode->next == NULL) {

			iterNode->next = n;
		}
	}
}*/
	if (head == NULL) {

		head = n;
		return;
	}

	Node* last = head;

	while (last->next) {

		last = last->next;
	}

	last->next = n;
}

int print_linked_list() {

	Node* head = new Node(0);

	cout << "Enter the size of the Likend List: ";

	int ll_size;

	cin >> ll_size;

	// Storing value in the Linked List

	for (int i = 0; i < ll_size; i++) {

		cout << "Enter the value of the " << i + 1 << " LL: ";

		int data;

		cin >> data;

		if (i == 0) {

			head->data = data;
			continue;
		}

		insert(head, data);
	}

	// Printing the Linked List

	for (Node* iterNode = head; iterNode; iterNode = iterNode->next) {

		cout << iterNode->data << endl;
	}
	
	return 0;
}