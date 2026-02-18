#include <iostream>

using namespace std;

typedef int ElementType;

/*
All sorting algorithms

Sort in increasing order
*/

const int SIZE = 11; // So we don't pass size as argument every time

ostream &operator<<(ostream &out, ElementType *arr)
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i] << " ";
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

void insertion_sort(ElementType *arr, int size = SIZE) {}

void run()
{
    cout << "\n";

    // Code here

    int a[SIZE] = {6, 2, 5, 1, 3, 9, 0, 4, 8, 7, -100};

    cout << "Original:\t" << a;

    // bubble_sort(a);
    // cout << "Bubble sort:\t" << a;

    selection_sort(a);
    cout << "Selection sort:\t" << a;

    cout << "\n\n";
}

int main() { run(); }