#include <iostream>
#include <vector>

using namespace std;

vector<int> brute_force(vector<int>nums, int target) {

	vector<int> pairs;

	for (int first = 0; first < nums.size(); first++) {

		for (int second = first + 1; second < nums.size(); second++) {

			if (target == nums.at(first) + nums.at(second)) {

				pairs.push_back(first);
				pairs.push_back(second);
				return pairs;
			}
		}
	}

	return pairs;
}

vector<int> optimized(vector<int> nums, int target) {

	vector<int> pairs;

	int start = 0, end = nums.size() - 1;

	while (start < end) {
		
		if ((nums.at(start) + nums.at(end)) > target) {
			
			end--;
		}
		else if ((nums.at(start) + nums.at(end)) < target) {

			start++;
		}
		else {

			pairs.push_back(start);
			pairs.push_back(end);
			return pairs;
		}
	}

	return pairs;
}

int pair_sum() {

	vector<int> nums = { 2, 7, 11, 15};

	int target = 6;

	vector<int> pairs = optimized(nums, target);

	(pairs.capacity() == 0) ? cout << "Pair Not found\n" : cout << pairs.at(0) << " " << pairs.at(1) << endl;

	return 0;
}