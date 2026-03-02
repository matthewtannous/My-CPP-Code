#include <iostream>

using namespace std;

typedef int ElementType;

/*
Sort in increasing order

Sorting algorithms in this file:
    Bubble Sort
    Selection Sort
    Double-Ended Selection Sort
    Insertion Sort

PSEUDOCODES:

Bubble Sort:
1. Assume that N data in an array (List, Table, ...)
2. Assume that N elements are not sorted
3. Assume the last element is not sorted (?)
4. Repeat N - 1 times or until all elements are sorted:
5.    Assume all elements are sorted
6.    For index from 0 to before the index of the last unsorted element:
7.        If element at index is greater than its successor
                                        (element at index + 1):
8.            Swap them
9.            Assume the elements are not sorted
      // By the end of this repetition the last element will be sorted


Selection Sort:
1. Assume N data in an array
(2. Assume N elements are not sorted) --- Not Needed?
3. For i starting from index of last element to 1:
4.    Assume index of max element is 0 (the first element)
5.    For j starting from 1 (second element) to i:
6.            If element at j is greater than element at max index:
7.                Assume max index is j
8.    swap element at max index with element at i
      // By the end of this repetition the last element will be sorted


Insertion Sort:
1. Assume N data in an array
2. For index from 1 to the index of last element
3.    Copy element at index into 'temp'
4.    For j starting from i until 1 OR until element at j-1 is bigger than temp:
5.        Move element at position j - 1 into element at position j
6.    Copy temp into element at position j

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
    bool sorted = false;
    // SIZE - 1  is the number of swaps needed to "traverse" the array
    for (int i = 0; i < SIZE - 1 && !sorted; i++)
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
        // if (sorted)
        //     break;
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
    int a[SIZE] = {6, 2, 5, 1, 4, 9, 0, 3, 4, 4, 8, 7, -10};

    cout << "Original:\t\t" << a;

    // bubble_sort(a);
    // cout << "Bubble sort:\t" << a;

    // selection_sort(a);
    // cout << "Selection sort:\t" << a;

    // double_ended_selection_sort(a);
    // cout << "Double selection sort:\t" << a;

    // insertion_sort(a);
    // cout << "Insertion sort:\t" << a;
}

int main()
{
    cout << "\n";
    run();
    cout << "\n\n";
}