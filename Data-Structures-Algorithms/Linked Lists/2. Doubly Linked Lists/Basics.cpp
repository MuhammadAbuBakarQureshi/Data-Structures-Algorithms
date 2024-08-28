#include <iostream>

using namespace std;

class Node {

public:

	int data;
	Node *prev, *next;

	// Constructor

	Node(int data) {

		this->data = data;
		prev = next = NULL;
	}
};

void forward_traverse_doubly_ll(Node* head) {

	for (Node* iterNode = head; iterNode; iterNode = iterNode->next) {

		cout << iterNode->data << endl;
	}
}

void backward_traverse_doubly_ll(Node* tail) {

	for (Node* iterNode = tail; iterNode; iterNode = iterNode->prev) {

		cout << iterNode->data << endl;
	}
}

void insert_at_head_doubly_ll(Node*& head, int data) {

	if (head == NULL) {

		cout << "Linked List is empty" << endl;
		return;
	}
	else {

		Node* n = new Node(data);
		head->prev = n;
		n->next = head;
		head = n;
	}
}

void insert_at_tail_doubly_ll(Node*& tail, int data) {

	if (tail == NULL) {

		cout << "Linked List is empty" << endl;
		return;
	}
	else {

		Node* n = new Node(data);
		tail->next = n;
		n->prev = tail;
		tail = n;
	}
}

void insert_at_position_doubly_ll(Node* &head,Node* & tail, int data, int position) {

	if (position == 1) {

		insert_at_head_doubly_ll(head, data);
		return;
	}

	Node* n = new Node(data);

	int count = 1;

	for (Node* iterNode = head; iterNode; iterNode = iterNode->next) {

		count++;

		if (position == count) {

			if (iterNode->next == NULL) {

				insert_at_tail_doubly_ll(tail, data);
				return;
			}
			else {

				n->next = iterNode->next;
				n->prev = iterNode;
				iterNode->next->prev = n;
				iterNode->next = n;
				return;
			}
		}
	}
}

void head_deletion_doubly_ll(Node* &head) {

	Node* temp = head;

	cout << "head : " << head->data << endl;

	head->next->prev = NULL;
	head = head->next;
	
	cout << "head : " << head->data << endl;

	delete temp;
}

void tail_deletion_doubly_ll(Node*& tail) {

	Node* temp = tail;

	tail->prev->next = NULL;
	tail = tail->prev;

	delete temp;
}

void deletion_doubly_ll (Node* &head, Node*& tail, int position) {

	if (position == 1) {

		head_deletion_doubly_ll(head);
		return;
	}

	int count = 0;

	for (Node* iterNode = head; iterNode; iterNode = iterNode->next) {

		count++;

		if (position == count) {

			if (iterNode->next == NULL) {

				tail_deletion_doubly_ll(tail);
				return;
			}
			else {

				iterNode->prev->next = iterNode->next;
				iterNode->next->prev = iterNode->prev;
				delete iterNode;
				return;
			}
		}
	}
}

int get_length_doubly_ll(Node* head) {

	int count = 0;

	for (Node* iterNode = head; iterNode; iterNode = iterNode->next) {

		count++;
	}

	return count;
}

int doubly_basic() {

	Node* head = new Node(10);
	Node* tail = head;

	insert_at_tail_doubly_ll(tail, 20);
	insert_at_tail_doubly_ll(tail, 30);
	insert_at_position_doubly_ll(head, tail, 40, 4);

	deletion_doubly_ll(head, tail, 4);
	
	//backward_traverse_doubly_ll(tail);

	forward_traverse_doubly_ll(head);

	cout << "Linked List length : " << get_length_doubly_ll(head) << endl;

	return 0;
}