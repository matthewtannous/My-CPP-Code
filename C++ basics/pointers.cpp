#include <iostream>

using namespace std;

int main()
{
    int *intPtr = new int;

    // Check if it was successfully created
    if (intPtr == NULL)
    {
        // Quit
        return 1;
    }

    *intPtr = 1000;
    cout << intPtr << endl   // Prints the address
         << *intPtr << endl << endl; // Prints the value

    // double *dPtr = NULL; // Best practice: always initialize pointers to NULL

    // Use pointer and memory

    delete intPtr; // delete only frees the allocated memory that intPtr points to
                   // The pointer still exists, but it points to a garbage value

    cout << intPtr << endl
         << *intPtr << endl << endl;

    int a = 100;

    int *aPtr = &a;

    *aPtr = -12;
    cout << a << endl;

    return 0;
}
