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

// insert is the name of function and linear is used to avoid conflicts with other functions in this project
void insert_linear(Node* &head, int data){

	Node* newNode = new Node(data);

	for (Node* iterNode = head; iterNode; iterNode = iterNode->next) {

		if (iterNode->next == NULL) {

			iterNode->next = newNode;
			
			break;
		}
	}

}

// LS stands for linear search
int LS(Node* head) {

	cout << "Enter the number you want to search : ";

	int search_number;

	cin >> search_number;

	for (Node* iterNode = head; iterNode; iterNode = iterNode->next) {

		if (search_number == iterNode->data) {

			return 1;
		}
	}

	return -1;
}

int linear_search_ll() {

	Node* head = new Node(5);
	
	insert_linear(head, 4);
	insert_linear(head, 8);
	insert_linear(head, 18);
	insert_linear(head, 10);

	// searching linked list

	int result = LS(head);

	// Printing results 

	(result == -1) ? cout << "Number not found": cout << "Number found" << endl;

	return 0;
}