#include <iostream>

using namespace std;

class Node {

public:

	int data;
	Node* prev, * next;

	// Constructor

	Node(int data) {

		this->data = data;
		prev = next = NULL;
	}
};

// DC -> Doubly Circular

void forward_traverse_DC_ll(Node* head) {

	if (head == NULL) {

		cout << "Linked List is empty" << endl;
		return;
	}

	Node* iterNode = head;

	do {
		cout << iterNode->data << " ";
		iterNode = iterNode->next;

	} while (iterNode != head);

	cout << endl;
}

void reverse_traverse_DC_ll(Node* head) {

	if (head == NULL) {

		cout << "Linked List is empty" << endl;
		return;
	}

	Node* iterNode = head;

	do {
		
		iterNode = iterNode->prev;
		cout << iterNode->data << " ";
	} while (iterNode != head);
	
	cout << endl;
}

void insert_at_head_DC_ll(Node*& head, int data) {

	if (head == NULL) {

		cout << "Linked List is empty" << endl;
		return;
	}
	else {

		Node* n = new Node(data);

		n->next = head;
		n->prev = head->prev;
		head->prev->next = n;
		head->prev = n;

		head = n;
	}
}

void insert_after_DC_ll(Node*& head, int data, int element) {

	Node* n = new Node(data);

	if (head == NULL) {

		cout << "Linked List is empty" << endl;
		return;
	}
	else if (head->next == NULL) {
	// if there is one element in the linked list 

		head->prev = n;
		head->next = n;
		n->prev = head;
		n->next = head;

		return;
	}

	Node* iterNode = head;

	do {

		if (iterNode->data == element) {

			n->prev = iterNode;
			iterNode->next->prev = n;
			n->next = iterNode->next;
			iterNode->next = n;

			return;
		}

		iterNode = iterNode->next;
	} while (iterNode != head);
}

void deletion_DC_ll(Node*& head, int element) {

	if (head == NULL) {

		cout << "Linked List is empty" << endl;
		return;
	}
	Node* iterNode = head;
	
	if (head->data == element) {

		iterNode->next->prev = iterNode->prev;
		iterNode->prev->next = iterNode->next;

		head = head->next;
		return;
	}


	do {

		if (iterNode->data == element) {

			iterNode->next->prev = iterNode->prev;
			iterNode->prev->next = iterNode->next;

			delete iterNode;
			return;
		}

		iterNode = iterNode->next;
	} while (iterNode != head);
}

int doubly_circular_ll_basic() {

	Node* head = new Node(10);
	insert_after_DC_ll(head, 20, 10);
	insert_after_DC_ll(head, 30, 20);
	insert_at_head_DC_ll(head, 0);

	forward_traverse_DC_ll(head);

	deletion_DC_ll(head, 0);

	forward_traverse_DC_ll(head);

	return 0;
}