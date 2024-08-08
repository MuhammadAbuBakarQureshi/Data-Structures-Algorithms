#include <iostream>
#include "../Header Files/Array-Functions.h"

using namespace std;

int binary_search_algorithm_recursion(int arr[], int start, int end, int search_number) {

	// RECURSIVE METHOD

	if (start > end)
		return -1;

	int half = (start + end) / 2;

	if (search_number == arr[half]) {

		return half;
	}
	else if (search_number < arr[half]) {

		binary_search_algorithm_recursion(arr, start, half - 1, search_number);
	}
	else if (search_number > arr[half]) {

		binary_search_algorithm_recursion(arr, half + 1, end, search_number);
	}
}

int binary_search_algorithm_iteration(int arr[], int start, int end, int search_number){

	// ITERATION METHOD

	int s = start, e = end;

	while (s <= e) {

		int half = (s + e) / 2;

		if (search_number == arr[half]) {

			return half;
		
		}else if (search_number < arr[half]) {
		
			e = half - 1;

		}else if (search_number > arr[half]) {

			s = half + 1;
		}

	}

	return -1;
}

int binary_search() {

	int arr_size = 10;

	int arr[10] = {30, 35, 40, 45, 50, 55, 87, 91, 105, 204};

	int search_number;

	cout << "Enter a number : ";

	cin >> search_number;

	// int result = binary_search_algorithm_recursion(arr, 0, arr_size - 1, search_number);

	int result = binary_search_algorithm_iteration(arr, 0, arr_size - 1, search_number);

	(result == -1) ? cout << "Number not found" : cout << "Number found at index : " << result << endl;

	return 0;
}