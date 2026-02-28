#include <iostream>
using namespace std;

const int SIZE = 10; // So we don't pass size as argument every time

// Print an array
ostream &operator<<(ostream &out, int *arr)
{
    for (int i = 0; i < SIZE; i++)
    {
        // cout << arr[i] << " ";
        printf("%4i", arr[i]);
    }
    cout << endl;
    return out;
}

// A utility function to get maximum
// value in arr[]
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// count sort of arr[] according to the digit represented by exp.
void countSort(int arr[], int size, int exp)
{
    int output[size]; // place sorted elements
    int i, count[10] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < size; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] now contains actual
    // position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // count[i] now stores the number of elements with digits <= i

    // Build the output array
    for (i = size - 1; i >= 0; i--)
    {
        int elementDigit = (arr[i] / exp) % 10;

        output[count[elementDigit] - 1] = arr[i];
        count[elementDigit]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < size; i++)
        arr[i] = output[i];
}

// Function that sorts arr[] of size n using Radix Sort
void radixsort(int arr[], int size)
{
    // Find the maximum number to know number of digits
    int m = getMax(arr, size);

    // Do counting sort for every digit.
    // Note that instead of passing digit number, exp is passed.
    // exp is 10^I, where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, size, exp);
}

void run()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66, 542, 8};

    cout << "Original:\t" << arr;

    radixsort(arr, SIZE);
    cout << "Radix Sort:\t" << arr;
}

int main()
{
    cout << "\n\n";
    run();
    cout << "\n\n";
}