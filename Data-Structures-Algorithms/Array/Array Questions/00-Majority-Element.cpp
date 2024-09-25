#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// O(n^2)

int brute_force_majority_element(vector<int> nums) {

	for (int value : nums) {

		int freq = 0;

		for (int element : nums) {

			if (element == value) freq++;
		}

		if (freq > nums.size() / 2) return value;		
	}

	return -1;
}

// O(nlogn)

int optimized_majority_element(vector<int> nums) {

	sort(nums.begin(), nums.end());

	int freq = 0, value = nums.at(0);

	for (int element : nums) {

		if (value == element) {

			freq++;
		}
		else {

			freq = 1;

			value = element;
		}

		if (freq > nums.size() / 2)	return value;
		
	}

	return -1;
}

int moores_algorithm(vector<int> nums) {

	int freq = 0, ans = 0;

	for (int value : nums) {

		if (freq == 0) {

			ans = value;
		}

		if (ans == value) {
			
			freq++;
		}
		else {

			freq--;
		}
	}

	return ans;
}

int majority_element() {

	vector<int> nums = { 1, 2, 2, 1, 1 };

	int ans = moores_algorithm(nums);

	cout << "Majority Element : " << ans << endl;

	return 0;
}