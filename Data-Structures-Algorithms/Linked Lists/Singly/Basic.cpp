#include <iostream>

using namespace std;

class Node{

public:

	int data;
	Node* next;

	 // Constructor

	Node(int data) {

		this->data = data;
		next = NULL;
	}

};

void printlist(Node* n) {

	// Printing using While loop

	/*
	while (n) {

		cout << n->data << endl;
		
		n = n->next;
	}*/

	// Printing using for loop

	for (Node* iternode = n; iternode; iternode = iternode->next) {

		cout << iternode->data << endl;
	}
}

void insert_at_head(Node** head, int newData){

	Node* newNode = new Node(newData);

	newNode->next = *head;

	*head = newNode;
}

void insert_at_tail(Node** head, int newData){

	Node* newNode = new Node(newData);

	if (*head == NULL) {

		*head = newNode;
		return;
	}

	Node* last = *head;

	while (last->next) {

		last = last->next;
	}

	last->next = newNode;
}

void insert_at_position(Node** head, int position, int newData) {

	if (position == 1) {

		insert_at_head(head, newData);
		return;
	}

	Node* n = new Node(newData);

	int count = 1;

	for (Node* iterNode = *head; iterNode; iterNode = iterNode->next) {
		
		count++;

		if (count == position) {

			n->next = iterNode->next;
			
			iterNode->next = n;

			break;
		}
	}


}

void delete_position(Node* &head, int position) {

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

		if (count == position) {

			iterNode->next = temp->next;
			break;
		}
	}
}

int singly_basic() {

	// Node* head = new Node(10);

	/*Node* n2 = new Node();

	Node* n3 = new Node();

	head->data = 10;

	head->next = n2;

	n2->data = 20;

	n2->next = n3;

	n3->data = 40;

	n3->next = NULL;
	*/
	
	//cout << "Enter the size of LL : ";

	//int ll_size;

	//cin >> ll_size;

	Node* head = new Node(10);

	//for (int i = 0; i < ll_size; i++) {

	//	cout << "Enter " << i + 1 << " element : ";

	//	int data;

	//	cin >> data;

	//	if (i == 0) {

	//		head->data = data;

	//		continue;
	//	}

	//	insert_at_tail(&head, data);
	//}

	insert_at_tail(&head, 30);

	insert_at_position(&head, 2, 20);

	printlist(head);

	delete_position(head, 1);

	cout << "After deletion" << endl;

	printlist(head);

	return 0;
}