#include <iostream>
#include "CircularLL.h"

using namespace std;

int main()
{
    CircularLL l1;

    cout << l1;

    l1.insertAtEnd(123);
    for (int i = 0; i < 10; i++)
    {
        l1.insertAtBeginnning(i);
        l1.insertAtEnd(100 * i);
    }
    l1.insertAtPos(0, -1);
    l1.insertAtPos(3, 987);

    cout << l1;
    
    
    l1.insertAtPos(23, -1000);
    cout << l1;

    CircularLL l2(l1);

    l2.deleteAtBeginning();

    cout << l2;

    CircularLL *l3 = new CircularLL(l1);

    l3->insertAtEnd(43434);

    
    cout << endl << l1 << endl << l2 << endl << *l3 << endl;

    delete l3;

    cout << "DONE";
}
