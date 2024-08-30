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

// ll = Linked List

void print_queue_ll(Node* head) {

	cout << "\n\n\t\t\t\t FUNCTIONS FOR QUEUES \t\t\t\t\n\n" << endl;

	if (head == NULL) {

		cout << "Queue is empty. Nothing to print." << endl;
		return;
	}
	else {

		for (Node* iterNode = head; iterNode; iterNode = iterNode->next) {

			cout << iterNode->data << " ";
		}
	}
}

void enqueue_ll(Node* &head, int& queue_size){

	int data;
	cout << "Enter the number you want to ENQUEUE : ";
	cin >> data;

	Node* newNode = new Node(data);

	for (Node* iterNode = head; iterNode; iterNode = iterNode->next) {

		if (iterNode->next == NULL) {

			iterNode->next = newNode;
			queue_size++;
			return;
		}
	}

}

void dequeue_ll(Node* &head, int& queue_size) {

	cout << "\n\n\t\t\t\t DEQUEUE \t\t\t\t\n\n" << endl;

	if (head == NULL) {

		cout << "Queue is empty. Nothing to dequeue." << endl;
		return;
	}
	else if (head->next == NULL){

		cout << head->data << " dequeue." << endl;
		delete head;
		head = NULL;
		queue_size--;
		return;
	}

	Node* temp = head;

	cout << head->data << " dequeue" << endl;

	head = head->next;
	delete temp;
	queue_size--;
	return;
}

void peek_ll(Node* head) {
	
	cout << "\n\n\t\t\t\t PEEK QUEUE \t\t\t\t\n\n" << endl;

	if (head == NULL) {

		cout << "Queue is empty." << endl;
		return;
	}
	else {

		cout << "Peek queue is " << head->data << endl;
	}
}

int queues_basics_using_linked_list() {

first_node:

	cout << "Enter number to ENQUEUE : ";
	int data;
	cin >> data;

	Node* head = new Node(data);

	int option, queue_size = 1;

	bool condition = true;

	while (condition) {

		cout << "\n\n\t\t\t\t FUNCTIONS FOR QUEUES \t\t\t\t\n\n" << endl;

		cout << "1). Enqueue.\n" <<
			"2). Dequeue.\n" <<
			"3). Peek.\n" <<
			"4). Is Empty.\n" <<
			"5). Size.\n" <<
			"6). Print.\n" <<
			"7). Exit.\n" << endl;

		cout << "Enter the fuction you want to perform : ";

		cin >> option;

		switch (option)
		{
		case 1:

			cout << "\n\n\t\t\t\t ENQUEUE \t\t\t\t\n\n" << endl;

			if (queue_size == 0) {
				
				goto first_node;
			}
			else {

				enqueue_ll(head, queue_size);
			}
			break;

		case 2:

			dequeue_ll(head, queue_size);
			break;

		case 3:

			peek_ll(head);
			break;

		case 4:

			cout << "\n\n\t\t\t\t IS QUEUE EMPTY \t\t\t\t\n\n" << endl;

			if (queue_size == 0) {

				cout << "Yes, queue is empty." << endl;
			}
			else {

				cout << "No, queue is not empty." << endl;
			}

			break;

		case 5:

			cout << "\n\n\t\t\t\t QUEUE SIZE \t\t\t\t\n\n" << endl;

			cout << "Queue size is " << queue_size << endl;
			break;

		case 6:

			print_queue_ll(head);
			break;

		case 7:

			condition = false;
			break;
		default:

			cout << "\n\nEnter correct option" << endl;
			break;
		}

	}

	return 0;
}