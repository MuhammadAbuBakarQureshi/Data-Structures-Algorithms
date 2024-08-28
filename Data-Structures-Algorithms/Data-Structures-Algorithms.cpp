#include <iostream>
#include "Header Files/Array/Array-Search.h"
#include "Header Files/Array/Array-Sort.h"
#include "Header Files/Array/Array-Functions.h"
#include "Header Files/Linked Lists/LL.h"
#include "Header Files/Recursion.h"

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

void printing_ll(Node* head){

	for (Node* iterNode = head; iterNode; iterNode = iterNode->next) {

		cout << iterNode->data << endl;
	}
}

void head_insertion(Node* &head, int data) {

	Node* n = new Node(data);

	n->next = head;

	head = n;
}

void position_insertion(Node* &head, int data, int position){

	if (position <= 1) {

		head_insertion(head, data);
		return;
	}

	Node* n = new Node(data);

	int count = 1;

	for (Node* iterNode = head; iterNode; iterNode = iterNode->next) {

		count++;

		if (position == count) {

			n->next = iterNode->next;

			iterNode->next = n;

			return;
		}

	}
}

void tail_insertion(Node* &head, int data) {

	Node* n = new Node(data);

	for (Node* iterNode = head; iterNode; iterNode = iterNode->next) {

		if (iterNode->next == NULL) {

			iterNode->next = n;
			return;
		}
	}
}

void deletion(Node*& head, int position) {

	// Check if the Linked List is empty

	if (head == NULL || position < 1) {

		cout << "Linked List is empty or Invalid position" << endl;
		return;
	}

	Node* temp = head;

	if (position == 1) {

		temp = head;
		head = head->next;
		delete temp;
		return;
	}

	int count = 1;

	for (Node* iterNode = head; iterNode; iterNode = iterNode->next) {

		count++;

		temp = temp->next;

		if (position == count) {

			iterNode->next = temp->next;

			delete temp;

			return;
		}
		
	}
}

int main() {

	Node* head = new Node(10);

	head_insertion(head, 0);

	position_insertion(head, 5, 2);


	tail_insertion(head, 15);

	printing_ll(head);

	cout << endl;

	deletion(head, 1);

	printing_ll(head);

	return 0;
}