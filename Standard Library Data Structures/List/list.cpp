/*
std::list is implemented as a doubly-linked list
*/

#include <algorithm>
#include <iostream>
#include <list>

using std::cout;

template <typename T>
std::ostream& operator<<(std::ostream& out, std::list<T> v)
{
    cout << "\nElements: ";
    for (T i : v) {
        cout << i << " ";
    }
    cout << "\nsize: " << v.size() << ", max size: " << v.max_size()
         << "\nEmpty? " << v.empty() <<"\n";
    return out;
}

int main()
{
    cout << std::boolalpha << "\n";

    std::list<int> l{1,2,3,4,5,6};
    cout << l;

    l.push_front(1000);
    l.push_back(-1000);

    cout << l << "\n";

    std::list<int>::iterator it = std::find(l.begin(), l.end(), -1000);
    
    if (it != l.end())
    {
        cout << "Found";
        l.insert(it, 999);
    }
    else
    {
        l.insert(it, 999);
        cout << "Not found";
    }

    cout << "\n" << l;

    cout << "\n\n";
    
    
    
}