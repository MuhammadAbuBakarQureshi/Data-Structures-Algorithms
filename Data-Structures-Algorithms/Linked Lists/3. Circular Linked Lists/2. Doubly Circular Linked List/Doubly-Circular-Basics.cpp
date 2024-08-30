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
	else if (head->next == NULL) {

		cout << head->data << endl;
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
	else if (head->next == NULL) {

		cout << head->data << endl;
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

	Node* n = new Node(data);

	if (head->next == NULL){

		
		head->prev = n;
		head->next = n;
		n->prev = head;
		n->next = head;

		head = n;
	}
	else {

		n->next = head;
		n->prev = head->prev;
		head->prev->next = n;
		head->prev = n;

		head = n;

		return;
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

		if (head->next == NULL) {

			cout << "This is last element in the Linked List.\n" <<
				"Do you want to delete this NODE  (y/n) : ";

			char option;

			cin >> option;

			if (option == 'y' || option == 'Y') {

				cout << "NODE having " << head->data << " value DELETED." << endl;
				delete head;
				head = NULL;
				return;
			}
			else if (option == 'n' || option == 'Y') {

				cout << "Returning without deleting NODE." << endl;

				return;
			}
		}
		else {

			cout << "NODE having " << head->data << " value DELETED." << endl;

			iterNode->next->prev = iterNode->prev;
			iterNode->prev->next = iterNode->next;
			head = head->next;
			return;
		}
	}


	do {

		if (iterNode->data == element) {

			cout << "NODE having " << iterNode->data << " value DELETED." << endl;

			iterNode->next->prev = iterNode->prev;
			iterNode->prev->next = iterNode->next;

			delete iterNode;
			return;
		}

		iterNode = iterNode->next;
	} while (iterNode != head);
}

int doubly_circular_ll_basic() {


	cout << "Enter First Node value : ";

	int first_value;

	cin >> first_value;

	Node* head = new Node(first_value);
	
	int option, data, element;
	bool condition = true;

	while (condition) {


		cout << "1. Insert at head.\n" <<
				"2. Insert after number.\n" <<
				"3. Node Deletion.\n" <<
				"4. Forward Traverse.\n" <<
				"5. Backward Traverse.\n" <<
				"6. Exit.\n" << endl;


		cout << "Enter the function you want to perform : ";

		cin >> option;

		switch (option)
		{
		case 1:

			cout << "Enter the number you want to store: ";
			cin >> data;
			insert_at_head_DC_ll(head, data);
			break;

		case 2:

			cout << "Enter the number you want to store: ";
			cin >> data;

			cout << "\nAfter which number you want to add given number (above): ";
			cin >> element;

			insert_after_DC_ll(head, data, element);
			break;

		case 3:

			cout << "Enter the element you want to delete: ";
			cin >> element;
			deletion_DC_ll(head, element);
			break;

		case 4:

			forward_traverse_DC_ll(head);
			break;

		case 5:

			reverse_traverse_DC_ll(head);
			break;

		case 6:

			condition = false;
			break;

		default:
			
			cout << "Enter correct function" << endl;
			break;
		}
	}


	return 0;
}