#include <iostream>

using namespace std;

class Node {

public:

	string data;
	Node* next;

	// Constructor

	Node(string data) {

		this->data = data;
		next = nullptr;
	}
};

void print_hash_table(Node* hash_table[], int size) {

	for (int i = 0; i < size; i++) {

		cout << i << ": " << endl;

		if (hash_table[i]) {

			Node* iterNode = hash_table[i];

			while (iterNode) {

				cout << iterNode->data << endl;
				iterNode = iterNode->next;
			}
		}

	}
}

int hashing(string data, int size){

	int hash = 0;

	for (int i = 0; i < data.length(); i++) {

		int asciivalue = int(data[i]);

		hash = (hash + asciivalue * 23) % size;
	}

	return hash;
}

void set_value(Node* hash_table[], int size, string data) {

	Node* newNode = new Node(data);

	int index = hashing(data, size);

	if (hash_table[index] == nullptr) {

		hash_table[index] = newNode;
	}
	else {

		Node* iterNode = hash_table[index];
		while (true) {

			if (!iterNode->next){
			
				iterNode->next = newNode;
				return;
			}

			iterNode = iterNode->next;
		}
	}

}

bool get_value(Node* hash_table[], int size, string data) {

	int index = hashing(data, size);

	Node* iterNode = hash_table[index];

	while (iterNode) {
			
		if (iterNode->data == data)	return 1;

		iterNode = iterNode->next;
	}

	return 0;
}

int hash_tables_basics() {

	const int size = 7;

	Node* hash_table[size];

	for (int i = 0; i < size; i++) {

		hash_table[i] = nullptr;
	}

	set_value(hash_table, size, "Bakar");

	/*set_value(hash_table, size, "g");*/

	print_hash_table(hash_table, size);

	cout << get_value(hash_table, size, "Br");
	
	return 0;
}