/*
std::list is implemented as a singly-linked list
*/

#include <algorithm>
#include <iostream>
#include <forward_list>

using std::cout;

template <typename T>
std::ostream& operator<<(std::ostream& out, std::forward_list<T> v)
{
    cout << "\nElements: ";
    for (T i : v) {
        cout << i << " ";
    }
    cout << "\nsize: " << ", max size: " << v.max_size()
         << "\nEmpty? " << v.empty() <<"\n";
    return out;
}

int main()
{
    cout << std::boolalpha << "\n";

    std::forward_list<int> l{1,2,3,4,5,6};
    cout << l;
    

    l.push_front(1000);

    cout << l << "\n";

    std::forward_list<int>::iterator it = std::find(l.begin(), l.end(), -1000);
    
    if (it != l.end())
    {
        cout << "Found";

    }
    else
    {
        cout << "Not found";

    }

    l.erase_after(l.begin()); // delete the second element

    cout << "\n" << l;

    l.erase_after(++l.begin(), l.end()); // delete everything in this range
    cout << l;

    cout << "\n\n";
    
}