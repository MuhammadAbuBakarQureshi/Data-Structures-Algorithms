#include <iostream>
#include <vector>

using namespace std;

inline int maximum(int a, int b) {
	
	return (a > b) ? a : b;
}

int maximum_subarray_sum() {

	vector<int> nums = { 1, 2, 3 ,4 , 5 };

	int maximum_sum = INT_MIN;

	for (int start = 0; start < nums.size(); start++) {

		int current_sum = 0;

		for (int end = start; end < nums.size(); end++) {

			current_sum += nums.at(end);

			maximum_sum = max(current_sum, maximum_sum);
		}
	}

	cout << maximum_sum << endl;

	return 0;
}