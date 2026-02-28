#include <iostream>

using namespace std;

typedef int ElementType;

/*
All sorting algorithms

Sort in increasing order
*/

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

// Performs one pass through the part of the array between low and high
int partition_pivot_last(int arr[], int low, int high) // pivot = last element
{
    ElementType pivot = arr[high];
    int x = low - 1;

    for (int y = low; y < high; y++)
    {
        if (arr[y] < pivot)
        {
            x++;
            // swap x and y
            swap(arr[x], arr[y]);
        }
    }

    swap(arr[++x], arr[high]);
    return x; // return the new index of the pivot
}

int partition_pivot_first(int arr[], int low, int high)
{
    ElementType pivot = arr[low];

    // int x = high + 1;
    // for (int y = high; y > low; y--)
    // {
    //     if (arr[y] > pivot)
    //     {
    //         x--;
    //         swap(arr[x], arr[y]);
    //     }
    // }
    // swap(arr[--x], arr[low]);

    int x = low;
    for (int y = low + 1; y <= high; y++)
    {
        if (arr[y] < pivot)
        {
            x++;
            swap(arr[x], arr[y]);
        }
    }

    // DO NOT INCREMENT x,  it points to the last element smallest than the
    // pivot
    swap(arr[x], arr[low]);
    return x;
}

// Remains the same with any pivot (simply calls different partition function)
void quick_sort(ElementType arr[], int low, int high = SIZE - 1)
{
    if (low < high)
    {
        // partition array and return pivot index
        // int pivotIndex = partition_pivot_last(arr, low, high);
        int pivotIndex = partition_pivot_first(arr, low, high);

        quick_sort(arr, low, pivotIndex - 1);  // recursively sort left
        quick_sort(arr, pivotIndex + 1, high); // recursively sort right
    }
}

void run()
{
    int a[SIZE] = {6, 2, 5, 1, 4, 9, 0, 3, 4, 4, 8, 7, -10};

    cout << "Original:\t" << a;

    quick_sort(a, 0, SIZE - 1);
    cout << "Quick Sort:\t" << a;
}

int main()
{
    cout << "\n";
    run();
    cout << "\n\n";
}