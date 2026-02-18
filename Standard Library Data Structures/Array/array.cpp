#include <iostream>
#include <array>

using std::cout;

template<typename ArrType, std::size_t N>
std::ostream& operator<<(std::ostream& out, const std::array<ArrType, N> &arr)
{
    out << "\nElements: ";
    for (ArrType i : arr)
    {
        out << i << " ";
    }
    out << "\n";
    return out;
}

int main()
{
    cout <<  "\n";
    std::array<int, 10> a;
    cout << a; // Not allowed normally

    a.fill(2);

    cout << a;

    a[3] = 30;
    cout << a;

    std::array<int, 5> a1 {1,2,3};

    cout << "\n\n";
}
