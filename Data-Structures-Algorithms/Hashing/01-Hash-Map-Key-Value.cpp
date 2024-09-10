#include <iostream>

using namespace std;

class Node {

public:

	string key;
	int value;
	Node* next;

	// Constructor

	Node(string key, int value) {

		this->key = key;
		this->value = value;
		next = nullptr;
	}
	
};

class HashTable {

private:

	static const int SIZE = 7;

	Node* hash_table[SIZE];

public:

	int hash(string key) {

		int hash = 0;
		
		for (int i = 0; i < key.length(); i++) {

			int ascii_value = int(key[i]);

			hash = (hash + ascii_value * 23) % SIZE;
		}

		return hash;
	}

	void add(string key, int value) {

		int index = hash(key);

		Node* newNode = new Node(key, value);

		if (hash_table[index] == nullptr) {

			hash_table[index] = newNode;
			return;
		}
		else {

			Node* iterNode = hash_table[index];
			while (true) {

				if (key == iterNode->key) {

					cout << "Already in the hash table : " << key << endl;
					return;
				}

				if (!iterNode->next) {

					iterNode->next = newNode;
					return;
				}

				iterNode = iterNode->next;
			}
		}
	}

	int get(string key) {

		int index = hash(key);

		Node* iterNode = hash_table[index];

		while (iterNode) {

			if (key == iterNode->key) return iterNode->value;

			iterNode = iterNode->next;
		}

	}

	void print_hash_table() {

		for (int i = 0; i < SIZE; i++) {

			cout << i << ": " << endl;

			Node* iterNode = hash_table[i];

			while (iterNode) {

				cout << iterNode->key << " : " << iterNode->value << endl;
				iterNode = iterNode->next;
			}
		}
	}

	int size() {


		int count = 0;

		for (int i = 0; i < SIZE; i++) {

			Node* iterNode = hash_table[i];

			while (iterNode) {
				iterNode = iterNode->next;
				count++;
			}
		}
		return count;
	}

	void keys() {

		int count = 0;

		for (int i = 0; i < SIZE; i++) {

			Node* iterNode = hash_table[i];

			while (iterNode) {

				cout << iterNode->key << "  ";
				iterNode = iterNode->next;
				count++;
			}
		}

		cout << endl;
	}

	void remove(string key) {

		for (int i = 0; i < SIZE; i++) {

			if (hash_table[i]) {

				if (key == hash_table[i]->key && hash_table[i]->next == nullptr) {

					cout << "Removed : " << hash_table[i]->key << endl;
					hash_table[i] = nullptr;
					return;
				}
				else {

					Node* prev = hash_table[i];
					Node* iterNode = hash_table[i];
					
					while (iterNode) {

						if (key == iterNode->key) {

							if (prev == iterNode) {

								cout << "Removed : " << iterNode->key << endl;
								iterNode = iterNode->next;
								hash_table[i] = iterNode;
								free(iterNode);
								return;
							}
							else if (iterNode->next == nullptr) {

								cout << "Removed : " << iterNode->key << endl;
								prev->next = nullptr;
								free(iterNode);
								return;
							}
							else {

								cout << "Removed : " << iterNode->key << endl;
								prev->next = iterNode->next;
								free(iterNode);
								return;
							}
						}

						prev = iterNode;
						iterNode = iterNode->next;
						
					}

				}
			}
		}
	}
};

int hash_table_key_value() {

	HashTable* my_hash_table = new HashTable();

	my_hash_table->add("Nails", 1000);
	my_hash_table->add("Tile", 80);
	my_hash_table->add("Lumber", 50);
	my_hash_table->add("paint", 20);
	my_hash_table->add("bolts", 100);

	/*my_hash_table->keys();

	cout << "Size of the hash table : " << my_hash_table->size() << endl;*/

	my_hash_table->remove("Tile");

	my_hash_table->print_hash_table();

	return 0;
}