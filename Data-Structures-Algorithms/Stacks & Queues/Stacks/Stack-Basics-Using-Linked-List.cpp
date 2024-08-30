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

void print_stack_ll(Node* head) {

	if (head == NULL) {

		return;
	}

	print_stack_ll(head->next);

	cout << head->data << endl;
}

void push_in_stack_ll(Node* &head, int data, int& stack_size) {

		Node* newNode = new Node(data);

		for (Node* iterNode = head; iterNode; iterNode = iterNode->next) {

			if (iterNode->next == NULL) {

				iterNode->next = newNode;
				stack_size++;
				return;
			}
		}

}

void pop_in_stack_ll(Node*& head, int& stack_size) {

	cout << "\n\n\t\t\t\t POP IN STACK \t\t\t\t\n\n" << endl;

	if (head == NULL) {

		cout << "Stack is empty. Nothing to delete" << endl;
		return;
	}
	else if (head->next == NULL) {

		cout << "Node having value " << head->data << " is deleted." << endl;
		delete head;
		head = NULL;
		stack_size--;
		return;
	}

	Node* iterNode = head;
	
	iterNode = iterNode->next;

	Node* temp = head;

	for (; iterNode; iterNode = iterNode->next) {

		if (iterNode->next == NULL) {
			
			cout << "Node having value " << iterNode->data << " is deleted." << endl;
			delete iterNode;
			temp->next = NULL;
			stack_size--;
			return;
		}

		temp = temp->next;
	}
}

void peek_in_stack_ll(Node*& head) {

	if (head == NULL) {

		cout << "Stack is empty." << endl;
		return;
	}

	cout << "\n\n\t\t\t\t PEEK IN STACK \t\t\t\t\n\n" << endl;

	for (Node* iterNode = head; iterNode; iterNode = iterNode->next) {

		if (iterNode->next == NULL) {

			cout << "Peek in stack " << iterNode->data << endl;
			return;
		}
	}
}

void stack_basics_using_linked_list() {

create_Node:

	cout << "\n\n\t\t\t\t PUSHING IN STACK \t\t\t\t\n\n" << endl;
	
	int stack_size = 1, option, data;

	cout << "Enter the value for first Node : ";

	cin >> data;

	Node* head = new Node(data);

	bool condition = true;

	while (condition) {

		cout << "\n\n\t\t\t\t FUNCTIONS FOR STACK \t\t\t\t\n\n" << endl;

		cout << "1). push.\n" <<
			"2). pop.\n" <<
			"3). peek.\n" <<
			"4). isEmpty.\n" <<
			"5). size.\n" <<
			"6). Print stack.\n" <<
			"7). EXIT.\n" << endl;

		cout << "Enter the function you want to perform: ";
		cin >> option;

		switch (option)
		{
		case 1:

			if (stack_size == 0) {

				goto create_Node;
			}
			else {

				cout << "\n\n\t\t\t\t PUSHING IN STACK \t\t\t\t\n\n" << endl;

				cout << "Enter the value you want to push: ";
				cin >> data;
				push_in_stack_ll(head, data, stack_size);
			}
			break;

		case 2:

			pop_in_stack_ll(head, stack_size);
			break;

		case 3:

			peek_in_stack_ll(head);
			break;

		case 4:

			cout << "\n\n\t\t\t\t IS STACK EMPTY \t\t\t\t\n\n" << endl;

			if (head == NULL) {

				cout << "TRUE" << endl;
			}
			else {

				cout << "FALSE" << endl;
			}
			break;

		case 5:

			cout << "\n\n\t\t\t\t STACK SIZE \t\t\t\t\n\n" << endl;

			cout << "Stack size = " << stack_size << endl;
			break;

		case 6:

			cout << "\n\n\t\t\t\t PRINTING STACK \t\t\t\t\n\n" << endl;

			if (stack_size == 0) {

				cout << "Stack is empty. Nothing to print" << endl;
			}
			else {

				print_stack_ll(head);
			}
			break;

		case 7:

			condition = false;
			break;

		default:

			cout << "Enter the correct option." << endl;
			break;
		}

	}
}
	
