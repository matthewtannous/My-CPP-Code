#include <iostream>

using namespace std;

int main()
{
    const int size = 10;
    int a[size] = {1, 2, 3};

    // 1
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << ", ";
    }
    cout << "\n\n";

    // 2
    for (int i = 0; i < size; i++)
    {
        cout << *(a + i) << ", ";
    }
    cout << "\n\n";
}
