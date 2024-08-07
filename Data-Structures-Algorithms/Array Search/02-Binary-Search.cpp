#include <iostream>
#include "../Header Files/Array-Functions.h"

using namespace std;

int binary_search_algorithm(int arr[], int start, int end, int search_number) {

	if (search_number > max(arr, end + 1))
		return 0;

	int half = (start + end) / 2;

	if (search_number < arr[half]) {

		binary_search_algorithm(arr, start, half, search_number);
	}
	else if (search_number > arr[half]) {
		
		binary_search_algorithm(arr, half + 1, end, search_number);
	}
	else if (search_number == arr[half]) {

		return 1;
	}

	//int s = start, e = end;

	//while (s <= e) {

	//	int half = (s + e) / 2;

	//	if (search_number < arr[half]) {

	//		e = half - 1;
	//	}

	//	if (search_number > arr[half]) {

	//		s = half + 1;
	//	}

	//	if (search_number == arr[half]) {

	//		return 1;
	//	}

	//}

	//return 0;
}

int binary_search() {

	int arr_size = 5;

	int arr[5] = {45, 87, 91, 105, 204};

	int search_number;

	cout << "Enter a number : ";

	cin >> search_number;

	cout << binary_search_algorithm(arr, 0, arr_size - 1, search_number) << endl;

	return 0;
}