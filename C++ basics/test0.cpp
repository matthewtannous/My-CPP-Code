#include <iostream>

using namespace std;

void s(int &, int &);

int main()
{
    int *intPtr = new int;

    // IMPORTANT: Check that the variable was succesfully created
    if (intPtr == NULL)
    {
        return 1;
    }
    *intPtr = 3;
    cout << intPtr // Prints the adress
         << endl
         << *intPtr << endl
         << endl;

    int a = 19;
    int *aPtr = &a;
    cout << a << endl;

    *aPtr = 123;
    cout << a << endl
         << (a == *aPtr) << endl
         << endl
         << endl;

    // Arrays
    const int size = 20;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << arr[size];
    }
}

void s(int &a, int &b) // pass by reference (pass the adress of a and b)
{
    int temp = a;
    a = b;
    b = temp;
}
