#include <iostream>
#include "Polynomial.h"

using namespace std;

int main()
{
    Polynomial p1;
    cin >> p1;

    Polynomial p2;
    cin >> p2;

    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;

    Polynomial sum = p1 * p2;

    cout << "mult: " << sum << endl;
}
