// driver means tester
#include <iostream>

#include "Time.h"

using namespace std;

int main()
{
    Time h(1, 2, 'A');
    cout << h;

    Time q; // call the no-arg constructor
    cout << q;
}
