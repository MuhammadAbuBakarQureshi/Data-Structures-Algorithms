#include <iostream>
#include "../Header Files/Array-Functions.h"

using namespace std;


void radix_count(int arr[], int arr_size, int pos) {

	int count_arr[10] = { {}, {} ,{}, {} ,{}, {} ,{}, {} ,{}, {} };

	for (int i = 0; i < arr_size; i++) {

		count_arr[(arr[i] / pos) % 10]++;
	}

	for (int i = 1; i < 10; i++) {

		count_arr[i] += count_arr[i - 1];
	}

	int* sorted_arr = new int[arr_size];

	for (int i = arr_size - 1; i >= 0; i--) {

		sorted_arr[--count_arr[(arr[i] / pos) % 10]] = arr[i];
	}

	for (int i = 0; i < arr_size; i++) {

		arr[i] = sorted_arr[i];
	}
	
}

void radix_algorithm(int arr[], int arr_size) {

	int arr_max_ele = max(arr, arr_size);

	for (int pos = 1; arr_max_ele / pos > 0; pos *= 10) {

		radix_count(arr, arr_size, pos);
	}
}


int radix_sort() {

	int arr_size = 5;

	int* arr = new int[arr_size];

	arr_input(arr, arr_size);

	radix_algorithm(arr, arr_size);

	print_arr(arr, arr_size);

	delete[] arr;

	return 0;
}