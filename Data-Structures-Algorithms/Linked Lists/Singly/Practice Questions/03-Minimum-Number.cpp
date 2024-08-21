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

void insert_minimum_number(Node*& head, int data) {

	Node* newNode = new Node(data);

	for (Node* iterNode = head; iterNode; iterNode = iterNode->next) {

		if (iterNode->next == NULL) {

			iterNode->next = newNode;

			break;
		}
	}

}

int MN(Node* head) {

	Node* min = new Node(INT_MAX);

	for (Node* iterNode = head; iterNode; iterNode = iterNode->next) {

		if (iterNode->data < min->data) {

			min->data = iterNode->data;
		}
	}

	return min->data;
}

int minimum_number_ll() {

	Node* head = new Node(20);

	insert_minimum_number(head, 10);
	insert_minimum_number(head, 23);
	insert_minimum_number(head, 14);
	insert_minimum_number(head, 12);
	insert_minimum_number(head, 18);
	insert_minimum_number(head, 21);

	// Minimum number

	int result = MN(head);

	// print the result

	cout << "Minimum number in the linked list is : " << result << endl;

	return 0;
}