#include <iostream>
#include "../Header Files/Array-Functions.h"

using namespace std;

void merge_arr(int arr[], int start, int end) {

	int half = (start + end) / 2;

	int len1 = half - start + 1;
	int len2 = end - half;

	int* arr_1 = new int[len1];
	int* arr_2 = new int[len2];

	int mainArrayIndex = start;

	for (int i = 0; i < len1; i++) {
		arr_1[i] = arr[mainArrayIndex++];
	}

	mainArrayIndex = half + 1;
	for (int i = 0; i < len2; i++) {
		arr_2[i] = arr[mainArrayIndex++];
	}

	int index1 = 0, index2 = 0;

	mainArrayIndex = start;

	while (index1 < len1 && index2 < len2) {

		if (arr_1[index1] < arr_2[index2]) {

			arr[mainArrayIndex++] = arr_1[index1++];
		}
		else {

			arr[mainArrayIndex++] = arr_2[index2++];
		}
	}

	while (index1 < len1) {

		arr[mainArrayIndex++] = arr_1[index1++];
	}

	while (index2 < len2) {

		arr[mainArrayIndex++] = arr_2[index2++];
	}

	delete[] arr_1;
	delete[] arr_2;
}

int merge_algorithm(int arr[], int start, int end) {

	if (start >= end)
		return start;

	int half = (start + end) / 2;

	// Left part
	merge_algorithm(arr, start, half);

	// Right part
	merge_algorithm(arr, half + 1, end);

	merge_arr(arr, start, end);

	return start;
}

int merge_sort() {

	int arr_size;

	cout << "Enter the size of the array : ";

	cin >> arr_size;

	int* arr = new int[arr_size];

	arr_input(arr, arr_size);

	merge_algorithm(arr, 0, arr_size - 1);

	cout << "Sorted array : ";

	print_arr(arr, arr_size);

	delete[] arr;

	return 0;
}