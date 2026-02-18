/*
std::multiset contains sorted elements that are not unique.

contains and find do the same thing, but find returns iterator and contains returns bool
*/

#include <iostream>
#include <set>

using std::cout;

template <typename T>
std::ostream& operator<<(std::ostream& out, std::multiset<T> s)
{
    out << "elements: ";
    for (auto it = s.begin(); it != s.end(); it++)
    {
        out << *it << " ";
    }
    out << "\nreverse:  "; // unordered_set does not have reverse iterator
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

    std::multiset<double> set{2,3,3,3,3,2, 0,1,12};

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
    std::multiset<char> characters(name.begin(), name.end());
    cout << characters;


    {
        std::set<double>::iterator it = set.lower_bound(10); // first >= 10
        cout << "Lower bound 10: ";
        for (auto iter = it; iter != set.end(); iter++)
        {
            cout << *iter << " ";
        }
    }

    cout << "\n";
    {
        std::set<double>::iterator it = set.upper_bound(10); // first > 10
        cout << "Upper bound 10: ";
        for (auto iter = it; iter != set.end(); iter++)
        {
            cout << *iter << " ";
        }
    }

    cout << "\n\n";

}