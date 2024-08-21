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

void insert_largest_number(Node*& head, int data) {

	Node* newNode = new Node(data);

	for (Node* iterNode = head; iterNode; iterNode = iterNode->next) {

		if (iterNode->next == NULL) {

			iterNode->next = newNode;

			break;
		}
	}

}

int LN(Node* head){

	Node* max = new Node(INT_MIN);

	for (Node* iterNode = head; iterNode; iterNode = iterNode->next) {

		if (iterNode->data > max->data) {

			max->data = iterNode->data;
		}
	}

	return max->data;
}

int largest_number_ll() {

	Node* head = new Node(3);

	insert_largest_number(head, 5);
	insert_largest_number(head, 1);
	insert_largest_number(head, 10);
	insert_largest_number(head, 14);

	// Largest number

	int result = LN(head);

	cout << "Largest number in the linked list is : " << result << endl;

	return 0;
}