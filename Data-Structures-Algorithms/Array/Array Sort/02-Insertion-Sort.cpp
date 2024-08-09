#include <iostream>

using namespace std;

void insertion_sort(int arr[], int arr_size)
{

    // Using For Loop

    // for (int i = 1; i < arr_size; i++)
    // {

    //     int current = arr[i];

    //     int j = i - 1;

    //     for (; j >= 0; j--)
    //     {

    //         if (arr[j] > current)
    //         {

    //             arr[j + 1] = arr[j];
    //         }
    //         else
    //         {

    //             break;
    //         }
    //     }

    //     arr[j + 1] = current;
    // }

    //
    //
    // Using while loop

    for (int i = 1; i < arr_size; i++) {

        int current = arr[i];

        int j = i - 1;

        while (arr[j] > current && j >= 0) {

            arr[j + 1] = arr[j];

            j--;
        }

        arr[j + 1] = current;
    }
}

int insertion_sort()
{

    cout << "Enter size of the array : ";

    int arr_size;

    cin >> arr_size;

    int* arr = new int[arr_size];

    // Input

    for (int i = 0; i < arr_size; i++)
    {

        cout << "Enter value of " << i << " Index : ";

        cin >> arr[i];
    }

    insertion_sort(arr, arr_size);

    // Output

    cout << "Sorted array : ";

    for (int i = 0; i < arr_size; i++)
    {

        cout << arr[i] << " ";
    }

    return 0;
}
