/*
std::deque (double-ended queue) is an indexed sequence container that allows
fast insertion and deletion at both its beginning and its end.

The deque allows pushing and popping elements from both the front and the back
*/

#include <iostream>
#include <deque>

using std::cout, std::string;

void test1();
void test2();

// Pass the queue by value so we have to copy to iterate over
template <typename T>
std::ostream& operator<<(std::ostream& out, std::deque<T> queue)
{
    out << "\nSize: " << queue.size() << " | Empty? " << queue.empty();

    if (!queue.empty())
    {
        out << " | Front: " << queue.front() << " | Back: " << queue.back()
            << "\nAll elements: ";

        for (T element : queue) // for-each loop
        {
            cout << element << " | ";
        }
    }

    out << "\n";
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
    std::deque<string> people{"Al", "Bro", "CR7", "Donald"};
    cout << people;

    // Access elements
    cout << people[0] << " , " << people[5] << " | "
         << people.at(0) << " , " 
        //  << people.at(5) // ERROR
         << "\n";

    cout << people.front() << " , " << people.back() << "\n";

    // Modify elements
    people.front() = "FRONTT";
    people.back() = "BACKKKK";
    people[1] = "ONEE";
    people.at(2) = "TWOOOO";

    cout << people;

    // Add elements
    people.push_front("New front");
    people.push_back("New back");

    cout << people;

    // Remove elements
    people.pop_back();
    people.pop_front();
    cout << people;

    // Add elements to the middle using iterators
    std::deque<string>::iterator iter1 = people.insert(people.begin() + 2, "MIDDDLE");
    std::deque<string>::iterator iter2 = people.emplace(people.begin() + 3, "ALSO MIDDLE");

    cout << people;

    *iter1 = "Modified";
    *iter2 = "Also modified";

    cout << people;
}

class Person
{
    public:
        string full_name;
        int age;
        Person() : full_name("Unknown"), age(-1) {}
        Person(int age) : full_name("Unknown"), age(age) {}
        Person(string full_name) : full_name(full_name), age(-1) {}
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
    std::deque<Person> queue {{}, {100}, {"Mat"}, {"Tannous", 17}};
    cout << queue;

    // emplace constructs the object in-place, using the passed arguments as arguments to the constructor
    // returns iterator pointing to the created object
    auto iter = queue.emplace(queue.cbegin() + 2, "Gofofof", 123);

    queue.push_back(Person(99999999));

    cout << queue;

    iter->age = 4378923;
    cout << queue;
}