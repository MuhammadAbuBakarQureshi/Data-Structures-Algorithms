#include <iostream>
#include <vector>

using namespace std;

inline void print_array(vector<int> nums, int start, int end) {

	for (int i = start; i <= end; i++) cout << nums.at(i);

	cout << " ";
}

int all_sub_arrays() {

	vector<int> nums = { 1, 2, 3, 4, 5 };

	for (int start = 0; start < nums.size(); start++) {

		for (int end = start; end < nums.size(); end++) {

			
			print_array(nums, start, end);
		}

		cout << endl;
	}

	return 0;
}