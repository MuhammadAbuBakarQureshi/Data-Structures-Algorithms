#include <iostream>

using namespace std;

void print_queue(int queue[], int queue_size) {

	cout << "\n\n\t\t\t\ PRINTING QUEUE \t\t\t\t\n\n" << endl;

	if (queue_size == 0) {

		cout << "Queue is empty. Nothing to print." << endl;
		return;
	}

	for (int i = 0; i < queue_size; i++) {

		cout << queue[i] << " ";
	}cout << endl;
}

void enqueue(int queue[], int& queue_size) {

	cout << "\n\n\t\t\t\t ENQUEUE \t\t\t\t\n\n" << endl;

	if (queue_size == 10) {

		cout << "Queue is full." << endl;
		return;
	}

	int data;
	cout << "Enter the data you want to ENQUEUE : ";
	cin >> data;

	queue[queue_size] = data;
	queue_size++;
}

void dequeue(int queue[], int& queue_size) {

	cout << "\n\n\t\t\t\t DEQUEUE \t\t\t\t\n\n" << endl;

	if (queue_size == 0) {

		cout << "Queue is empty. Nothing to delete" << endl;
		return;
	}
	
	cout << "Dequeue " << queue[0] << endl;

	int i = 0, j = 1;

	while (j <= queue_size) {

		queue[i] = queue[j];
		i++, j++;
	}

	queue_size--;

}

void peek(int queue[], int queue_size) {

	cout << "\n\n\t\t\t\t FUNCTIONS FOR QUEUES \t\t\t\t\n\n" << endl;

	if (queue_size == 0) {

		cout << "Queue is empty" << endl;
		return;
	}
	else {

		cout << "Peek queue is " << queue[0] << endl;
		return;
	}
}

int queues_basics_using_array() {

	int queue[10], queue_size = 0, option;
	
	bool condition = true;

	while(condition){

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

			enqueue(queue, queue_size);
			break;

		case 2:

			dequeue(queue, queue_size);
			break;

		case 3:

			peek(queue, queue_size);
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

			print_queue(queue, queue_size);
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