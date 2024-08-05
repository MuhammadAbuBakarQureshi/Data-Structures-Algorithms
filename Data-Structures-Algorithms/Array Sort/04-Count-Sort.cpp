#include <iostream>

using namespace std;

int max(int arr[], int arr_size) {

	int max = INT_MIN;

	for (int i = 0; i < arr_size; i++) {

		if (arr[i] > max) {

			max = arr[i];
		}
	}

	return max;
}

void sort(int arr[], int arr_size) {

	int count_arr_size = max(arr, arr_size) + 1;

	int* count_arr = new int[count_arr_size];

	for (int i = 0; i < count_arr_size; i++) {

		count_arr[i] = 0;
	}

	// algorithm

	for (int i = 0; i < arr_size; i++) {

		count_arr[arr[i]]++;
	}

	int j = 0;

	for (int i = 0; i < count_arr_size; i++) {

			for (int k = 0; k < count_arr[i]; k++) {

				arr[j] = i;

				j++;
			}
	}

	delete[] count_arr;

}

int count_sort() {

	cout << "Enter the size of the array : ";

	int arr_size;

	cin >> arr_size;

	int* arr = new int[arr_size];

	for (int i = 0; i < arr_size; i++) {

		cout << "Enter the value of " << i << " Index : ";

		cin >> arr[i];
	}
	
	sort(arr, arr_size);

	for (int i = 0; i < arr_size; i++) {

		cout << arr[i] << " ";
	}cout << endl;

	delete[] arr;

	return 0;
}