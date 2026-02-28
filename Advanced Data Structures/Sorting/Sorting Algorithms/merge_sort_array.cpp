#include <iostream>

using namespace std;

typedef int ElementType;

const int SIZE = 13; // So we don't pass size as argument every time

ostream &operator<<(ostream &out, ElementType *arr)
{
    for (int i = 0; i < SIZE; i++)
    {
        // cout << arr[i] << " ";
        printf("%4i", arr[i]);
    }
    cout << endl;
    return out;
}

void swap(ElementType &e1, ElementType &e2)
{
    ElementType temp = e1;
    e1 = e2;
    e2 = temp;
}

// Merge two subarrays of arr[]
void merge(int arr[], int left, int middle, int right)
{
    // cout << "left = " << left << "\tmiddle = " << middle << "\tright = " << right << "\n";
    int sizeLeft = middle - left + 1; // Size of the left subarray
    int sizeRight = right - middle;   // Size of the right subarray

    // Create temporary arrays
    int L[sizeLeft], R[sizeRight];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < sizeLeft; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < sizeRight; j++)
        R[j] = arr[middle + 1 + j];

    // Merge the two subarrays back into the original array arr[]
    int l = 0, r = 0;
    int i;
    for (i = left; i <= right && l < sizeLeft && r < sizeRight; i++)
    {
        if (L[l] < R[r])
            arr[i] = L[l++];
        else
            arr[i] = R[r++];
    }

    while (i <= right && l < sizeLeft)
        arr[i++] = L[l++];

    while (i <= right && r < sizeRight)
        arr[i++] = R[r++];
}

// takes an array arr, and two indices left and right representing the left and
// right boundaries of the array to be sorted.
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int middle = (left + right) / 2; // Calculate the middle index

        // Recursively call mergeSort on the left half of the array.
        mergeSort(arr, left, middle);

        // Recursively call mergeSort on the right half of the array.
        mergeSort(arr, middle + 1, right);

        // Call the merge function to merge the two sorted halves of the array.
        merge(arr, left, middle, right);
    }
}

void run()
{
    int a[SIZE] = {6, 2, 5, 1, 4, 9, 0, 3, 4, 4, 8, 7, -10};

    cout << "Original:\t" << a;

    mergeSort(a, 0, SIZE - 1);
    cout << "Merge Sort:\t" << a;
}

int main()
{
    cout << "\n";
    run();
    cout << "\n\n";
}
