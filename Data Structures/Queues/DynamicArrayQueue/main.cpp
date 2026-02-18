#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
    cout << boolalpha; // print boolean as true and false instead of 1 and 0
    Queue q;

    cout << q;

    q.enqueue(1);
    q.enqueue(123);

    cout << q;

    q.enqueue(3);
    q.enqueue(5);

    cout << q;

    q.enqueue(12343);
    cout << q;
    q.enqueue(-134);
    cout << q << "\n\n";

    for (int i = 1; i <= 6; i++)
    {
        cout << q.dequeue() << endl
             << "Removed " << i << ":\t" << q;
    }

    cout << "\n\n";
    for (int i = 0; i < 6; i++)
    {
        q.enqueue(i);
    }

    cout << q;

    q.dequeue();

    q.dequeue();

    q.enqueue(999);

    cout << q;

    q.dequeue();

    cout << q;

    q.enqueue(-23);
    q.enqueue(-231);

    cout << q;

    q.enqueue(23456);
}
