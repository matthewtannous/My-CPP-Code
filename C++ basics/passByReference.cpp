#include <iostream>

using namespace std;

void power(long &, long);

int main()
{
    long b, p;

    cout << "Enter base: ";
    cin >> b;

    cout << "\nEnter power: ";
    cin >> p;

    cout << b << " , " << p;
    power(b, p);
    cout << "\n\nResult: " << b;

    return 0;
}

// Changes the given base to be raised by the power
void power(long &base, long power)
{
    long n = 1;
    if (power >= 0)
    {
        for (int i = 0; i < power; i++)
        {
            n *= base;
        }
    }

    base = n;
}
