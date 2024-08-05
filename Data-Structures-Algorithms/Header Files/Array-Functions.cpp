#include <iostream>

using namespace std;

void arr_input(int arr[], int arr_size) {

	cout << "Enter the size of the array : ";

	cin >> arr_size;

	for (int i = 0; i < arr_size; i++) {

		cout << "Enter the value of " << i << " Index : ";

		cin >> arr[i];
	}

}

void print_arr(int arr[], int arr_size) {

	for (int i = 0; i < arr_size; i++) {

		cout << arr[i] << " ";
	}cout << endl;
}