#include <iostream>

using namespace std;

int main()
{
    struct Day
    {
        int day, month, year;
        string name;
    };

    // typedef original_name new_name
    // According to the C++ standards, "struct Day" is the name of the created ADT with struct
    typedef struct Day stupid;

    stupid d = {1, 2, 3, "d"}; // Initialize each data field in order.

    cout << d.day << endl
         << d.month << endl
         << d.year << endl
         << d.name << endl;

    return 0;
}
