/*  NOTE ABOUT inline functions/methods:
        When a function is declared as inline, it means the compiler will replace
        every function with it's definition during compile-time (BEFORE LINKING).
        Therefore, the definition of an inline function MUST BE PRESENT in every
        code file that wants to use it, so it is a good idea to define in the
        header file.

        The compiler expects to find a definition of an inline function in every
        file that #include it's header (file)

    NOTE ABOUT assert(bool) and exit(int):
        assert() takes a boolean. If it is true, nothing happens.
        If it is false, it raises an exception ??

        exit() takes an integer and stops execution completely.

*/

#include <iostream>
#include "List.h"

using std::cout;
using std::endl;

int main()
{
    List a;
    cout << a;

    cout << std::boolalpha;
    a.insertAtEnd(12.3);
    cout << a;

    for (int i = 0; i < 30; i++)
    {
        a.insertAtEnd(i);
    }
    cout << a;

    cout << a.insertAtPos(1234, 200) << endl;
    // cout << a.insertAtPos(-123, 12);
    // a.insertAtPos(-123, 12);

    a.deleteAtPos(0);
    cout << endl
         << a.isSorted() << endl;
    List b(a);
    cout << a << b << "&a: " << &a << "\n&b: " << &b << endl;

    cout << "DONE";

    cout << "\n\n"
         << a.isSorted() << b.isSorted();
}
