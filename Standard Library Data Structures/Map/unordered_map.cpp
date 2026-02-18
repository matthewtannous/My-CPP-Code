/*
std::unordered_map is an unstorted associative container that contains
unique key-value pairs grouped into buckets

Syntax:  std::unordered_map<KeyType, ValueType>

Using operator[] with non-existent key always performs an insert

NOTE: std::unordered_map is also called a hash map
*/

#include <iostream>
#include <unordered_map>

using std::cout, std::string;

void test1();
void test2();

template<typename KeyType, typename ValueType>
std::ostream& operator<<(std::ostream& out,const std::unordered_map<KeyType, ValueType>& map)
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
    std::unordered_map<string, int> people = {{"Mat", 20}, {"Tan", -10},
                {"George G",3}};

    // Access elements
    cout << people["Mat"] << ", " << people.at("Tan") << ", "
        // << people.at("jfiw") // throws exception
        << people["defaulttt"] << "\n"; // creates new key-value pair with default value (0 for int)


    // Modify elements
    people["Mat"] = 100000;
    cout << people["Mat"] << "\n";

    people.at("Mat") = -1;
    cout << people["Mat"] << "\n";

    cout << people;

    // Add elements
    people["new"] = 1111;
    people["also new"] = 2222;

    people.insert({"oh", 23});
    people.insert({"oh", 250}); // does nothing

    cout << people;

    // Remove elements
    people.erase("oh");
    people.erase("oh");

    cout << people;

    // Check if key is in map
    cout << people.count("new") << "\n"; // 1 --> found key


    // Reverse order
    std::unordered_map<string, int> people_normal_order = {{"Mat", 20}, {"Tan", -10},
                {"George G",3}};
    // std::unordered_map<string, int, std::greater<string>> people_reverse_order = {{"Mat", 20}, {"Tan", -10},
    //             {"George G",3}};

    cout << "\nNormal order:\n";
    for (auto i : people_normal_order)
    {
        cout << i.first << "\t" << i.second << "\n";
    }

    // cout << "\nReverse order:\n"; // unordered
    // for (auto i : people_reverse_order)
    // {
    //     cout << i.first << "\t" << i.second << "\n";
    // }
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
    std::unordered_map<string, Person> map{{"joe", Person()}, {"mat", Person("Matthew Tannous", 19)}};
    cout << map;

    cout << "Age of mat: " << map["mat"].age << "\n";

    map.emplace(std::make_pair("other", Person("Otherrr", 10)));

    map.emplace("Again", Person());
    map.emplace("Again", Person());

    map.insert({{"HELLOO", Person()}, {"FEWWW", Person()}});

    cout << map;

    // auto iter = map.lower_bound("ZZZ"); // no lower or uppper bound if unordered
    // cout << "\nLower bound of ZZZ:\n";
    // for (auto it = iter; it != map.end(); it++)
    // {
    //     cout << it->first << " ";
    // }

    cout << "\n\n";
    // Find specific element
    std::unordered_map<string, Person>::iterator it2 = map.find("mat");
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

    cout << "\n" << map
         << "\nBucket info:\ncount: " << map.bucket_count() << ", max count: "
         << map.max_bucket_count() << ", bucket of mat: " << map.bucket("mat");
 
}