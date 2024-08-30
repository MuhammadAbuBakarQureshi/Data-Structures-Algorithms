#include <iostream>

using namespace std;

void print_stack(int stack[], int stack_size) {

	cout << "\n\n\t\t\t\t PRINTING STACK \t\t\t\t\n\n" << endl;

	if (stack_size == 0) {

		cout << "Stack is empty." << endl;
	}
	else {

		for (int i = stack_size - 1; i >= 0; i--) {

			cout << stack[i] << endl;
		}cout << endl;
	}
}

void push_in_stack(int stack[], int& stack_size) {

	cout << "\n\n\t\t\t\t PUSHING IN STACK \t\t\t\t\n\n" << endl;

	if (stack_size == 10) {

		cout << "Stack overflow" << endl;
	}
	else
	{
		cout << "Enter the data you want to push : ";

		int data;

		cin >> data;

		stack[stack_size] = data;

		stack_size++;
	}
}

void pop_in_stack(int stack[], int& stack_size) {

	cout << "\n\n\t\t\t\t POP IN STACK \t\t\t\t\n\n" << endl;

	if (stack_size == 0) {

		cout << "Stack underflow" << endl;
	}
	else {

		cout << stack[stack_size - 1] << " pop out." << endl;
		stack_size--;
	}
}

void peek_in_stack(int stack[], int stack_size) {

	cout << "\n\n\t\t\t\t STACK PEEK \t\t\t\t\n\n" << endl;

	if (stack_size == 0) {

		cout << "Stack is empty" << endl;
	}
	else {

		cout << "Peek in stack " << stack[stack_size - 1] << endl;
	}
}

int is_empty_stack(int stack_size) {

	cout << "\n\n\t\t\t\t IS STACK EMPTY \t\t\t\t\n\n" << endl;

	bool is_empty = false;

	if (stack_size == 0) {

		is_empty = true;
	}
	else if (stack_size > 0) {

		is_empty = false;
	}

	return is_empty;
}

int stacks_basics() {

	int stack[10];

	int stack_size = 0, option;

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

			push_in_stack(stack, stack_size);
			break;

		case 2:

			pop_in_stack(stack, stack_size);
			break;

		case 3:

			peek_in_stack(stack, stack_size);
			break;

		case 4:

			bool is_empty;
			is_empty = is_empty_stack(stack_size);
			(is_empty == 0) ? cout << "FALSE" : cout << "TRUE" << endl;
			break;

		case 5:
			
			cout << "\n\n\t\t\t\t FUNCTIONS FOR STACK \t\t\t\t\n\n" << endl;

			cout << "Stack size = " << stack_size << endl;

			break;

		case 6:

			print_stack(stack, stack_size);
			break;

		case 7:

			condition = false;
			break;

		default:

			cout << "Enter the correct option." << endl;
			break;
		}

	}
	return 0;
}