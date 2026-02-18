#include <cstdio>
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

void bubble_sort(ElementType *arr, int size = SIZE)
{
    ElementType temp;
    bool sorted;
    // SIZE - 1  is the number of swaps needed to "traverse" the array
    for (int i = 0; i < SIZE - 1; i++)
    {
        sorted = true;
        for (int j = 0; j < SIZE - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // swap
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                sorted = false;
            }
        }
        if (sorted)
            break;
    }
}

void selection_sort(ElementType *arr, int size = SIZE)
{
    // ElementType maxElement; // not needed, we can get it from arr[maxIndex]
    ElementType temp;
    int maxIndex;

    for (int i = SIZE - 1; i > 0; i--)
    {
        // maxElement = arr[0];
        maxIndex = 0;
        // get largest and put it at the end
        for (int j = 1; j <= i; j++)
        {
            if (arr[j] > arr[maxIndex])
            {
                // maxElement = arr[j];
                maxIndex = j;
            }
        }
        // swap
        temp = arr[maxIndex];
        arr[maxIndex] = arr[i];
        arr[i] = temp;
    }
}

/*
Same as selection, but selects largest and smallest in each pass through the
loop
*/
void double_ended_selection_sort(ElementType *arr, int size = SIZE)
{
    int minIndex, maxIndex;
    ElementType temp;

    for (int i = 0; i < SIZE / 2; i++)
    {
        minIndex = maxIndex = i;

        // Find max and min
        for (int j = i + 1; j < SIZE - i; j++)
        {
            if (arr[j] > arr[maxIndex])
                maxIndex = j;

            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        // Special case
        if (i == maxIndex)
            maxIndex = minIndex;

        // swap min
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;

        // swap max
        temp = arr[maxIndex];
        arr[maxIndex] = arr[SIZE - i - 1];
        arr[SIZE - i - 1] = temp;
    }
}

void insertion_sort(ElementType *arr, int size = SIZE)
{
    ElementType temp;
    int j;
    // Assume element 0 is already sorted
    for (int i = 1; i < SIZE; i++)
    {
        temp = arr[i];
        // place element arr[i] in the correct position <= i
        // shift all elements until correct position is reached   2 5 8 4
        for (j = i; j > 0 && arr[j - 1] > temp; j--)
        {
            // cout << "D";
            arr[j] = arr[j - 1];
        }
        arr[j] = temp;
    }
}

void run()
{
    cout << "\n";

    // Code here

    int a[SIZE] = {6, 2, 5, 1, 4, 9, 0, 3, 4, 4, 8, 7, -10};

    cout << "Original:\t\t" << a;

    // bubble_sort(a);
    // cout << "Bubble sort:\t" << a;

    // selection_sort(a);
    // cout << "Selection sort:\t" << a;

    double_ended_selection_sort(a);
    cout << "Double selection sort:\t" << a;

    // insertion_sort(a);
    // cout << "Insertion sort:\t" << a;

    cout << "\n\n";
}

int main() { run(); }