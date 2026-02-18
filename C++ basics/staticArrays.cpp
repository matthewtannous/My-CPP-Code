/*
In C++, we can read values from outside the array (arr[12313])
On both left (negative) and right (> arraySize)
*/

#include <iostream>

using namespace std;

void display(int arr[], int s);

int main()
{
    // static array size MUST be const or a literal
    // (put a number directly as the size)
    const int size = 12;

    int arr1[size]; // Creates an array with garbage values
    display(arr1, size);

    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // Initializer list
    display(arr2, size);

    int arr3[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    display(arr3, size);

    // Array is deleted when we exit the block
    {
        int arr4[size] = {0}; // Create an array with initial values of 0
        display(arr4, size);
    }
    // display(arr4, size); does not work

    // cout << arr2[-12];
    // arr2[142] = 6;
}

void display(int arr[], int s)
{
    for (int i = 0; i < s; i++)
    {
        cout << arr[i];
        if (i != s - 1)
        {
            cout << " , ";
        }
    }
    cout << "\n\n";
}
