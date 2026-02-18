/*
std::queue is a container adapter that gives the functionality of a queue (FIFO structure)

Container Adapters are special containers that change/limit how we use existing
containers.
std::queue is usually built on top of a deque

The queue pushes elements to the back and pops them from the front
*/

#include <iostream>
#include <queue>

using std::cout, std::string;

void test1();
void test2();

// Pass the queue by value so we have to copy to iterate over
template <typename T>
std::ostream& operator<<(std::ostream& out, std::queue<T> queue)
{
    out << "\nSize: " << queue.size() << " | Empty? " << queue.empty();

    if (!queue.empty())
    {
        out << " | Front: " << queue.front() << " | Back: " << queue.back()
            << "\nAll elements: ";

        while (!queue.empty())
        {
            out << queue.front() << " | ";
            queue.pop();
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
    // std::queue<string> people = {"feij"}; // NOT ALLOWED
    std::queue<string> people;

    cout << people;

    // Add elements
    people.push("Al");
    people.push("Bo");
    people.push("CR7");
    people.push("Donald");

    cout << people;

    // Modify front and back
    people.front() = "HELLLO";
    people.back() = "BYEE";

    cout << people;

    // Remove elements from front
    people.pop();
    people.pop();

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
    std::queue<Person> queue;
    cout << queue;

    // emplace constructs the object in-place, using the passed arguments as arguments to the constructor
    // returns the value or reference of the created object
    Person& s = queue.emplace("Matthew Tannous", 20);

    queue.push(Person());

    cout << queue;

    s.age = 4378923;
    cout << queue;
}