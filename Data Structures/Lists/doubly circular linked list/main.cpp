#include <iostream>
#include "DoublyCircularLinkedList.h"

using namespace std;

int main()
{
    cout << boolalpha;
    DoublyCLL l;

    cout << l;
    cout << l.size() << endl;

    for (int i = 0; i < 5; i++)
    {
        l.insertAtBegin(i);
        l.insertAtEnd(i * 10);
    }

    cout << l;
    cout << l.size() << endl;

    DoublyCLL l2(l);
    for (int i = 0; i < 3; i++)
    {
        l.deleteFromBegin();
        l.deleteFromEnd();
    }

    cout << "Original: " << l;
    cout << "Copy: " << l2;

    l = l2;

    cout << "Original: " << l;
    cout << "Copy: " << l2;

    for (int i = 0; i < 10; i++)
    {
        l.insertAtBegin(i);
        l.insertAtEnd(i * 10);

        l2.insertAtBegin(-10 * i);
        l2.insertAtBegin(-100 * i);
    }

    for (int i = 0; i < 6; i++)
    {
        l.deleteFromEnd();
        l2.deleteFromEnd();
    }

    cout << "Original: " << l;
    // cout << "Copy: " << l2;

    l.insertAfterElement(9999, 6);

    l.insertAfterElement(99, 30);
    l.insertAfterElement(9999, 9);

    cout << "Original: " << l;

    l.insertAtEnd(-99);
    l.insertAfterElement(12, -99);

    cout << "\n\nOriginal: " << l;

    l.insertBeforeElement(-1, 8);
    l.insertBeforeElement(-1, 9);

    l.insertBeforeElement(-91, 9);

    cout << "Original: " << l << "Reverse:  ";

    l.displayReverse(cout);

    cout << "\n\n\n"
         << l;

    l.deleteElement(-99);

    l.deleteElement(12);

    l.deleteElement(-91);
    l.deleteElement(-1);
    cout << l;
    l.displayReverse(cout);
}
