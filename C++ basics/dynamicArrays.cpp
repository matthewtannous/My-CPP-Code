#include <iostream>

using namespace std;

int main()
{
    [[maybe_unused]] int *bPtr = new int[4]; // to create a dynamic array (contains garbage values at creation)

    for (int i = 0; i < 4; i++)
    {
        cout << bPtr[i];
    }
    cout << endl
         << endl;
    int size;
    [[maybe_unused]] int *arrPtr;

    cout << "Enter size: ";
    cin >> size;

    if (size > 0)
    {
        arrPtr = new int[size];
    }
    else
    {
        cout << "ERROR";
        return 2;
    }

    cout << "Enter elements: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arrPtr[i];
    }

    for (int i = 0; i < size; i++)
    {
        cout << arrPtr[i] << " , ";
    }

    cout << endl;

    delete[] arrPtr; // frees the memory occupied by the array
    for (int i = 0; i < size; i++)
    {
        cout << arrPtr[i] << " , ";
    }

    cout << endl
         << endl;

    // To make an array bigger
    size = 3;
    arrPtr = new int[size];
    arrPtr[0] = 1;
    arrPtr[1] = 2;
    arrPtr[2] = 3;
    int *biggerPtr = new int[size * 10];
    int i = 0;
    for (; i < size; i++)
    {
        biggerPtr[i] = arrPtr[i];
    }
    for (; i < size * 10; i++)
    {
        biggerPtr[i] = 0;
    }

    cout << "Original: ";
    for (int i = 0; i < size; i++)
    {
        cout << arrPtr[i] << " , ";
    }
    cout << endl;
    for (int i = 0; i < size * 10; i++)
    {
        cout << biggerPtr[i] << " , ";
    }

    delete[] arrPtr;
    arrPtr = biggerPtr;

    // This produces an exception because r is already deleted on the second delete[] r statement
    int *r = new int[12];
    delete[] r;
    delete[] r;
}
