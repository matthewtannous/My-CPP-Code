/*
std::set contains unique elements, sorted in increasing order

contains and find do the same thing, but find returns iterator and contains returns bool

Sets are usually implemented as Red-black trees
*/

#include <iostream>
#include <set>

using std::cout;

template <typename T>
std::ostream& operator<<(std::ostream& out, std::set<T> s)
{
    out << "elements: ";
    for (auto it = s.begin(); it != s.end(); it++)
    {
        out << *it << " ";
    }
    out << "\nreverse:  ";
    for (auto it = s.rbegin(); it != s.rend(); it++)
    {
        out << *it << " ";
    }
    out << "\nsize: " << s.size() << ", Empty? " << s.empty()
         << "\n" << "\n";

    return out;
}


int main()
{
    cout << std::boolalpha << "\n";
    
    std::set<double> set{2,3,3,3,3,2, 0,1,12};
    
    cout << set;

    set.insert(10);
    set.insert(10);

    cout << set;

    cout << "Erase 2: " << set.erase(2) << "\n";

    cout << set;

    cout << "Erase 2 again: " << set.erase(2) << "\n";
    cout << set;


    std::set<double> other{2, 10};

    for (double key : other)
    {
        if (set.find(key) != set.end())
        {
            cout << "Found " << key;
        }
    }
    cout << "\n";

    std::string name = "Matthew Tannous";
    std::set<char> characters(name.begin(), name.end());
    cout << characters;

}