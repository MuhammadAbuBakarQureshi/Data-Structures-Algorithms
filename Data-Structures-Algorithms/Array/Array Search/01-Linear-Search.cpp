#include <iostream>
#include "../Header Files/Array-Functions.h"

using namespace std;

int linear_search(int arr[], int arr_size) {

	int search_number;

	cout << "Enter the number you want to search : ";

	cin >> search_number;

	for (int i = 0; i < arr_size; i++) {

		if (search_number == arr[i]) {

			return i;
		}
	}

	return -1;
}

int linear_search() {

	int arr_size;

	cout << "Enter the array size : ";

	cin >> arr_size;

	int* arr = new int[arr_size];

	arr_input(arr, arr_size);

	print_arr(arr, arr_size);

	int result = linear_search(arr, arr_size);

	(result == -1) ? cout << "Element not found" : cout << "Element Found at index : " << result << endl;

	delete[] arr;

	return 0;
}