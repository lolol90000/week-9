#include <iostream>
using namespace std;

// Function prototypes
int findMin(int arr[], int size);
int findMin(int arr[][3], int rows);

// Find minimum in 1D array
int findMin(int arr[], int size)
{
    int min = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    return min;
}

// Find minimum in 2D array
int findMin(int arr[][3], int rows)
{
    int min = arr[0][0];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] < min)
            {
                min = arr[i][j];
            }
        }
    }

    return min;
}

int main()
{
    int arr1D[5] = {8, 3, 11, 1, 6};

    int arr2D[2][3] = {
        {4, 9, 2},
        {15, 7, 6}
    };

    cout << "Minimum in 1D array: "
         << findMin(arr1D, 5) << endl;

    cout << "Minimum in 2D array: "
         << findMin(arr2D, 2) << endl;

    return 0;
}