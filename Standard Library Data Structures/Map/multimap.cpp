/*
std::multimap is a sorted associative container that contains
key-value pairs while permitting multiple entries with the same key.
Keys are sorted using the comparison function Compare

It is like a python dictionary

Syntax:  std::multimap<KeyType, ValueType>

In a multimap, operator[] and .at() method are not available,
as there could be many elements with the same key
*/

#include <iostream>
#include <map>

using std::cout, std::string;

void test1();
void test2();

template<typename KeyType, typename ValueType>
std::ostream& operator<<(std::ostream& out,const std::multimap<KeyType, ValueType>& map)
{
    cout << "\n\nSize: " << map.size() << "\n";
    for (auto element : map) // element if of type pair (?)
    {
        // cout << typeid(element).name();
        cout << "KEY:  " << element.first << "\tVALUE:  " << element.second << "\n";
    }

    cout << "\n";
    return out;
}


int main()
{
    cout << std::boolalpha << "\n";

    // test1();
    test2();

    cout << "\n\n";
}

void test1()
{
    // std::map<string, int> map; // empty map
    std::multimap<string, int> people = {{"Mat", 20}, {"Tan", -10},
                {"George G",3}};
    
    // Access one element with key
    std::multimap<string, int>::iterator iter = people.find("Tan");
    if (iter == people.end())
    {
        cout << "Not found";
    }
    else
    {
        cout << "Found | " << iter->first << ", " << iter->second;
    }

    cout << "\n";

    std::multimap<string, int>::iterator iter2 = people.find("Tan");
    if (iter2 == people.end())
    {
        cout << "Not found";
    }
    else
    {
        iter2->second = 10000000;
        // iter2->first = "JIE"; // cannot change key
        cout << "Found | " << iter2->first << ", " << iter2->second;
    }   

    cout << "\n" << people;

    // Add elements

    people.insert({"oh", 23});
    people.insert({"oh", 250}); // adds second value with same key

    cout << people;

    // Remove elements
    cout << "Num of \"oh\" erased: " << people.erase("oh")
         << "\nNum of \"oh\" erased (again): " << people.erase("oh");


    cout << people;

    // Check if key is in map
    cout << people.count("new") << "\n"; // 1 --> found key

    // Access all elements with specific key

    people.insert({{"hello", 1000}, {"hello", -1927}});
    string test = "hello";
    cout << "All elements with key " << test << "\n";

    // range is of type   std::pair<std::map<string, int>::iterator, std::map<string, int>::iterator> 
    auto range = people.equal_range(test);
    for (auto i = range.first; i != range.second; i++)
    {
        cout << "\t" << i->first << ", " << i->second << "\n"; 
    }

    // Reverse order of keys
    std::multimap<string, int> people_normal_order = {{"Mat", 20}, {"Tan", -10},
                {"George G",3}};
    std::multimap<string, int, std::greater<string>> people_reverse_order = {{"Mat", 20}, {"Tan", -10},
                {"George G",3}};


    people_normal_order.insert({"A", 1});
    people_normal_order.insert({"A", 2});
    
    people_reverse_order.insert({"A", 1});
    people_reverse_order.insert({"A", 2});
    
    cout << "\nNormal order:\n";
    for (auto i : people_normal_order)
    {
        cout << i.first << "\t" << i.second << "\n";
    }

    cout << "\nReverse order:\n";
    for (auto i : people_reverse_order)
    {
        cout << i.first << "\t" << i.second << "\n";
    }


    cout << "\nReverse order with reverse_iterator:\n";
    for (auto i = people_normal_order.rbegin(); i != people_normal_order.rend(); i++)
    {
        cout << i->first << "\t" << i->second << "\n";
    }
}

class Person
{
    public:
        string full_name;
        int age;
        Person() : full_name("Unknown"), age(-1) {}
        Person(string full_name, int age) : full_name(full_name), age(age) {}

        void print(std::ostream& out) const
        {
            out << "Name: " << full_name << ". Age: " << age;
        }
};

std::ostream& operator<<(std::ostream& out, const Person& person)
{
    person.print(out);
    return out;
}

void test2()
{
    std::multimap<string, Person> map{{"joe", Person()}, {"mat", Person("Matthew Tannous", 19)}};
    cout << map;

    cout << "New Age of mat: ";
    auto iterator = map.find("mat");
    if (iterator == map.end())
    {
        cout << "Unknown.......";
    }
    else
    {
        iterator->second.age = -9;
        cout << iterator->second.age;
    }
    cout << "\n";

    map.emplace(std::make_pair("other", Person("Otherrr", 10)));

    map.emplace("Again", Person());
    map.emplace("Again", Person());

    map.insert({{"HELLOO", Person()}, {"FEWWW", Person()}});

    cout << map;

    auto iter = map.lower_bound("ZZZ");
    cout << "\nLower bound of ZZZ:\n";
    for (auto it = iter; it != map.end(); it++)
    {
        cout << it->first << " ";
    }


    cout << "\n\n";
    // Find specific element
    std::multimap<string, Person>::iterator it2 = map.find("mat");
    if (it2 == map.end())
    {
        cout << "Not found"
            // << it2->first << " | " << it2->second // Segmentation fault
            ;
    }
    else
    {
        cout << "Found: " << it2->first << " | " << it2->second;
    }

    // cout << "\n" << map
    //      << "\nBucket info:\ncount: " << map.bucket_count() << ", max count: "
    //      << map.max_bucket_count() << ", bucket of mat: " << map.bucket("mat");
}