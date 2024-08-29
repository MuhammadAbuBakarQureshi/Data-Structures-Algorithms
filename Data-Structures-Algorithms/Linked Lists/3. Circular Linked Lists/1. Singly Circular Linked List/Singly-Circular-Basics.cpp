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

// SC = singly circular

void traverse_SC_ll(Node*& tail, int total_elements) {

	for (int i = 0; i < total_elements; i++) {

		tail = tail->next;
		cout << tail->data << " ";
	}cout << "\n\n" << endl;
}

void insert_at_head_SC_ll(Node*& tail, int& total_elements, int data) {

	Node* n = new Node(data);

	n->next = tail->next;
	tail->next = n;

	total_elements++;
}

void insert_at_tail_SC_ll(Node*& tail, int& total_elements, int data) {

	Node* n = new Node(data);

	if (tail->next == NULL) {

		n->next = tail;
		tail->next = n;
		tail = n;
	}
	else {

		n->next = tail->next;
		tail->next = n;
		tail = n;
	}
	
	total_elements++;
}

void insert_after_number_SC_ll(Node*& tail, int& total_elements, int data, int element) {

	if (tail == NULL) {

		cout << "Linked List is empty" << endl;
		return;
	}
	else if (total_elements == 1 || tail->data == element) {

		insert_at_tail_SC_ll(tail, total_elements, data);
		return;
	}
	else {
		Node* n = new Node(data);

		Node* iterNode = tail;

		for (int i = 0; i < total_elements; i++) {

			iterNode = iterNode->next;
			
			if (iterNode->data == element) {
			
				n->next = iterNode->next;
				iterNode->next = n;


				total_elements++;
				return;
			}
		}

	}

}

void deletion_SC_ll(Node*& tail, int& total_elements, int element) {

	if (tail == NULL) {

		cout << "Linked List is empty" << endl;
		return;
	}

	Node* temp = tail;
	Node* current = tail;

	for (int i = 0; i < total_elements; i++) {
		
		current = current->next;

		if (current->data == element) {

			temp->next = current->next;

			if (current->next == tail->next) {

				tail = temp;
			}

			delete current;
			
			total_elements--;
			return;
		}

		temp = temp->next;
	}
}

int singly_circular_ll_basic() {

	Node* tail = new Node(10);

	int total_elements= 1;

	//insert_at_tail_SC_ll(tail, total_elements, 20);
	//insert_at_head_SC_ll(tail, total_elements, 0);
	//insert_after_number_SC_ll(tail, total_elements, 15, 10);
	deletion_SC_ll(tail, total_elements, 10);

	traverse_SC_ll(tail, total_elements);

	return 0;
}