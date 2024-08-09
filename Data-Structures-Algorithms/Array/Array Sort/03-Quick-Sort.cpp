#include <iostream>

using namespace std;

void swap(int& a, int& b) {

	int temp = a;
	a = b;
	b = temp;
}

int partition(int arr[], int start, int end) {

	int pivot = arr[start];

	int count = 0;

	for (int i = start + 1; i <= end; i++) {

		if (arr[i] <= pivot) {

			count++;
		}

	}

	// Place pivot at right position

	int pivotIndex = start + count;

	swap(arr[start], arr[pivotIndex]);

	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {

		while (arr[i] <= arr[pivotIndex]) {

			i++;
		}

		while (arr[j] > arr[pivotIndex]) {

			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
		
			swap(arr[i++], arr[j--]);
		}
	}

	return pivotIndex;
}

int sort(int arr[], int start, int end) {


	// Base case 

	if (start >= end)
		return start;

	int p = partition(arr, start, end);

	// Before pivot

	sort(arr, start, p - 1);

	// After pivot

	sort(arr, p + 1, end);

}

int quick_sort() {

	int arr[5] = { 10, 2, 9, 0, 5 };

	int arr_size = size(arr);

	sort(arr, 0, arr_size - 1);

	for (int i = 0; i < arr_size; i++) {

		cout << arr[i] << " ";
	}cout << endl;

	return 0;
}