#include <iostream>
#include <vector>

using namespace std;

int kadanes_algorithm() {

	vector<int> nums = { 2, 4, -7, 1 };

	int maximum_sum = INT_MIN, current_sum = 0;

	for (int value : nums) {

		current_sum += value;

		maximum_sum = max(maximum_sum, current_sum);

		if (current_sum < 0) {

			current_sum = 0;
		}
	}
	
	cout << maximum_sum << endl;

	return 0;
}