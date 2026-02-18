#include <iostream>
#include <stack>

using std::cout;

template <typename T>
void print(const std::stack<T> s)
{
    cout << "\nsize: " << s.size() << ", Empty? " << s.empty()
         << "\ntop: " << s.top() << "\n";
}

int main()
{
    cout << std::boolalpha << "\n";
    std::stack<int> s;

    // cout << "top: " << s.top(); // error (stack is empty)

    s.push(10);
    s.push(20);
    print(s);

    s.pop();
    print(s);
}