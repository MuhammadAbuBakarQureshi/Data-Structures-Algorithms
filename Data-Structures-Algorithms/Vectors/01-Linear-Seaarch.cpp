#include <iostream>
#include <vector>

using namespace std;

int vector_linear_search() {

	vector<int> nums = { 23, 523, 12 , 512 , 125, 64, 78, 42, 85 , 91 };

	cout << "Enter the number you want to search : ";

	int number;

	cin >> number;

	bool found = false;

	for (int value : nums) {

		if (number == value) {

			found = true;
			break;
		}
	}

	(found == false) ? cout << "Number Not Found\n" : cout << "Number Found" << endl;

	return 0;
}