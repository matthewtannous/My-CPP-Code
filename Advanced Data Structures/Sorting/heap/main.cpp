#include "heap.h"
#include <ios>
#include <iostream>

using namespace std;

void test()
{
    cout << boolalpha;
    Heap<int> heap;

    cout << heap;

    for (int i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
            heap.insert(i * 10);
        else
            heap.insert(i);
    }

    cout << heap;

    Heap<int> h2 = heap;
    cout << "H2" << h2;

    for (int i = 0; i < 3; i++)
        h2.remove();

    cout << "\n\n\n\n" << heap << h2;
}

int main()
{
    cout << endl;
    test();

    cout << "\n\n";
}
