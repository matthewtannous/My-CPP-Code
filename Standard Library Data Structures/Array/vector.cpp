/*
vector is implemented as a dynamic array \list


NOTE ABOUT ITERATORS
iterators are pointers to elements in the data structure.
They are created from member functions of the class you want to iterate through
*/

#include <iostream>
#include <vector>

using std::cout;

template <typename T>
void print(const std::vector<T> v)
{
    cout << "\nElements: ";
    for (T i : v) {
        cout << i << " ";
    }
    cout << "\nsize: " << v.size() << ", capacity: " << v.capacity() << ", max size: " << v.max_size()
         << "\nEmpty? " << v.empty() <<"\n";
}

template <typename T>
std::ostream& operator<<(std::ostream& out, std::vector<T> v)
{
    print(v);
    return out;
}


int main()
{
    cout << std::boolalpha;
    cout << "\n";

    std::vector<double> v0;
    cout << v0;


    v0.assign(7, 123.32);

    cout << v0;

    v0.push_back(-100);
    cout << v0;

    v0.pop_back();
    cout << v0;

    v0.insert(v0.begin(), 8);
    cout << v0;

    std::vector<double> v1 {1,2,3,4};
    cout << v1;

    v1.swap(v0);

    cout << v0 << v1;

    v1.clear();
    cout << v1;


    // print contents of v0 using iterators
    cout << "\n\n";
    for (std::vector<double>::iterator i = v0.begin(); i != v0.end(); i++)
    {
        cout << *i << " ";
    }
    cout << "\n";
    for (std::vector<double>::reverse_iterator i = v0.rbegin(); i != v0.rend(); i++)
    {
        cout << *i << " ";
    }

    std::vector<double>::iterator it = v0.begin() + 2;
    *it = 99999;

    print(v0);
    cout << "\n\n";
}

