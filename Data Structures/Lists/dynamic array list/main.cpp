#include <iostream>
#include "List.h"

using namespace std;

int main()
{
    List a;
    cout << a;
    a.deleteAtEnd();
    a.insertAtEnd(123);
    cout << a;

    cout << a.deleteAtPos(1);
    cout << a.deleteAtPos(0);

    for (int i = 0; i < 12; i++)
        a.insertAtEnd(i * 2);

    cout << a << endl;

    for (int i = 0; i < 21; i++)
    {
        a.insertAtPos(i * 10, i + 10);
    }
    cout << a;
    a.modify(1, -3);
    cout << a;

    cout << "\n\n\n";

    // List *o;
    // for (int i = 0; i < 12345; i++)
    // {
    //     o = new List(9999999);
    // }
    
    List b = a;
    cout << "Comparing original (a) with new array made with = (b):\nCapacity: "
         << (b.capacity == a.capacity) << "\nSize: " << (a.size == b.size)
         << "\narray address: " << (a.array == b.array);
}
