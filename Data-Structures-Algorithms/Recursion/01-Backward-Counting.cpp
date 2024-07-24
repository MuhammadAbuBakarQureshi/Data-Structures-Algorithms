#include <iostream>

using namespace std;

int counting(int n) {

	if (n == 0)
		return 0;
	
	// This is head recursion

	cout << n << endl;
	
	counting(n - 1);

}

int backward_counting() {

	counting(5);

	return 0;
}