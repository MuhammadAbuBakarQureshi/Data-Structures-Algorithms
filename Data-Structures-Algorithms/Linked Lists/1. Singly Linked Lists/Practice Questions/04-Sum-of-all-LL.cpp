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

void insert_sum_all(Node* &head, int data) {

	Node* n = new Node(data);

	for (Node* iterNode = head; iterNode; iterNode = iterNode->next) {

		if (iterNode->next == NULL) {

			iterNode->next = n;
			return;
		}
	}
}

// SA --> sum all
int SA(Node* head) {

	int result = 0;

	for(Node* iterNode = head; iterNode; iterNode = iterNode->next){

		result += iterNode->data;
	}

	return result;
}

int sum_all_ll() {

	Node* head = new Node(10);

	insert_sum_all(head, 20);
	insert_sum_all(head, 30);
	insert_sum_all(head, 40);
	insert_sum_all(head, 50);

	int sum = SA(head);

	cout << "Sum of all numbers in Linked List is : " << sum << endl;

	return 0;
}