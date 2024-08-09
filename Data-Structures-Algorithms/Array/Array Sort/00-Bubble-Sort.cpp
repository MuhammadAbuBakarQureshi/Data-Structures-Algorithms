#include <iostream>

using namespace std;

int bubble_sort()
{

    int arr[5] = { 7, 12, 9, 11, 3 };

    int n = size(arr);

    // Printing Input

    cout << "Before : ";

    for (int i = 0; i < n; i++)
    {

        cout << arr[i] << " ";
    }

    // Algorithm

    for (int i = 0; i < n; i++)
    {

        // If the algorithm goes through the array one time without swapping any values, the array must be finished sorted, and we can 
        //stop the algorithm

        bool swaped = false;

        for (int j = 0; j < (n - 1 - i); j++)
        {

            if (arr[j] > arr[j + 1])
            {

                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaped = true;
            }
        }

        if (!swaped)
        {

            break;
        }
    }

    // Printing output

    cout << "\nAfter  : ";

    for (int i = 0; i < 5; i++)
    {

        cout << arr[i] << " ";
    }

    return 0;
}