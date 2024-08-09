#include <iostream>

using namespace std;

void print_array(int arr[], int size) {

    for (int i = 0; i < size; i++) {

        cout << arr[i] << " ";
    }
}

void selection_sort(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {

        int min_index = i;

        for (int j = i + 1; j < size; j++)
        {

            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }

        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}

int selection_sort()
{

    cout << "Enter the size of the array : ";

    int size;

    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter the value of " << i << " Index = ";

        cin >> arr[i];
    }

    selection_sort(arr, size);

    cout << "Sorted array : ";

    print_array(arr, size);

    delete[] arr;

    return 0;
}