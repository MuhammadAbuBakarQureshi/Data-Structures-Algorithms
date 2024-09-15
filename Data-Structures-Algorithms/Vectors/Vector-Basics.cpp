#include <vector>
#include <iostream>

using namespace std;

int vector_basics() {

	// Intitalizing

	// 1. vector<int> vec;

	// 2. vector<int> vec = { 1, 2, 3 };

	// 3. vector<int> vec(3, 0);  ------> This means size of vector is 3 and every index have value is equal to 0.

	vector<char> vec = { 'a', 'b', 'c', 'd', 'e' };
	
	// Loop for vector

	cout << "\nPrinting vector" << endl;

	for (char value: vec) {

		cout << value << endl;
	}

	// Size of the vector

	cout << "\nSize of the vector = " << vec.size() << endl;

	// Push back in vector

	cout << "\n\nSize of the vector before push back = " << vec.size() << endl;

	vec.push_back('f');

	cout << "\nSize of the vector after push back = " << vec.size() << endl;


	// Pop back in vector

	cout << "\n\n\nSize of the vector before pop back = " << vec.size() << endl;

	vec.pop_back();

	cout << "\nSize of the vector after pop back = " << vec.size() << endl;

	
	// front in vector

	cout << "\n\nFront value in vector = " << vec.front() << endl;

	

	// Back in vector

	cout << "\n\nBack value in vector = " << vec.back() << endl;


	// at in vector

	cout << "\n\nValue on 3rd index in vector = " << vec.at(3) << endl;

	return 0;
}