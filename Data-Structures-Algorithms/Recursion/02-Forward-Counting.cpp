#include <iostream>

using namespace std;

int counting_print(int n) {

	if (n == 0)
		return 0;

	// This is tail recursion

	counting_print(n - 1);

	cout << n << endl;
}

int forward_counting() {

	counting_print(10);

	return 0;
}