#include <iostream>

using namespace std;

int main()
{

    // C-style casts
    int x = 23;
    cout << x / 5 << endl          // without casting
         << (double)x / 5 << endl  // C-style cast (used in C)
         << double(x) / 5 << endl; // function-style cast (looks like a function call)

    cout << "\n\n";

    /* function-style casts are easier to read.

    AVOID USING C-STYLE CASTS. It can actually perform many casts, which the code harder to understand
    */

    // static_cast (most commonly used)
    // Syntax:  static_cast<type>(value_to_cast);
    // static_cast returns the converted value

    char c{'a'};
    cout << c << endl
         << (float)c << " - " << double(c) << endl // C-style casts (avoid)
         << static_cast<int>(c) << endl;           // better

    cout << static_cast<double>(x) / 5 << "\n\n";

    // other
    int i = 4329;
    // char ch {static_cast<int>(i)};
    char ch = static_cast<char>(i); // might raise an error without expicit conversion. static_cast returns a char, which is the expected type of ch
    cout << ch;
}

void testSwitch()
{
    cout << "Enter number: ";
    int c;
    cin >> c;

    switch (c)
    {
    case 1:
        cout << "wow 1" << endl;
    case 2:
        cout << "d2" << endl;
    default:
        cout << "DEF";
    }
}
