#include <iostream>
#include <vector>

using namespace std;

void reverse_V(vector<int>& nums, int start, int end) {

    while (start < end) {

        int temp = nums.at(start);
        nums.at(start) = nums.at(end);
        nums.at(end) = temp;
        start++, end--;
    }
}

int vector_reverse() {

    vector<int> vec = { 1, 2, 3 ,4 ,5 };

	return 0;
}