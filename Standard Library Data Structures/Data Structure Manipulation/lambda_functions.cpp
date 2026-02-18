/*
A lambda function is a small, anonymous function

Syntax:
auto name = [capture] (parameters) { code };

capture are variables that you want to give lambda access to
*/

#include <iostream>
#include <vector>

#include <functional> // needed for std::function

using std::cout, std::string;

template <typename T>
std::ostream& operator<<(std::ostream& out, std::vector<T> v)
{
    cout << "\n";
    for (T i : v)
        out << i << " ";
    cout << "\n";
    return out;
}


void test1();
void test2();

int main()
{
    cout << std::boolalpha << "\n";

    test1();

    cout << "\n\n";
}

void myFunction(std::function<void()> func)
{
    func();
    func();
}

void test1()
{
    auto message = []()
    {
        cout << "Helloo\n";
    };
    message();


    auto add = [](int a, int b)
    {
        return a + b;
    };
    cout << add(1,2) << "\n";

    myFunction(message);

    cout << "\n";
    // In loops
    for (int i = 0; i < 3; i++)
    {
        auto show = [i]()
        {
            cout << "Number: " << i << ", ";
        };
        show();
    }

    cout << "\n\n";
    ///////
    int x = 10;
    auto show = [&x]()// can capture by value or by reference
    {
        cout << x << "\n";
        // x = 1;
    };

    x = 32;
    show();
    cout << x << "\n";
}


void test2()
{

}