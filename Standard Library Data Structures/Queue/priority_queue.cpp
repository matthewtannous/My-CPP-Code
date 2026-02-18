/*
std::priority_queue is a container adaptor that provides constant time lookup
of the largest (by default) element.
A priority_queue sorts elements in a specific order, depending on the result of
Compare (largest to smallest by default)

A user-provided Compare can be supplied to change the ordering, e.g. using
std::greater<T> would cause the smallest element to appear as the top().

std::priority_queue is usually built on top of a vector (or deque)

To use a custom class in a priority queue, you must override operator<
Example:
bool operator<(const MyClass &c1, const MyClass c2)
{
    return c1.data < c2.data;
}
*/

#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using std::cout, std::string;

void test1();
void test2();

// Pass the queue by value so we have to copy to iterate over
template <typename T>
std::ostream& operator<<(std::ostream& out, std::priority_queue<T> queue)
{
    out << "\nSize: " << queue.size() << " | Empty? " << queue.empty();

    if (!queue.empty())
    {
        out << " | Top: " << queue.top()
            << "\nAll elements: ";

        while (!queue.empty())
        {
            out << queue.top() << " | ";
            queue.pop();
        }
    }

    out << "\n";
    return out;
}

// Pass the queue by value so we have to copy to iterate over
template <typename Element, typename Container, typename Order>
std::ostream& operator<<(std::ostream& out, 
        std::priority_queue<Element, Container, Order> queue)
{
    out << "\nSize: " << queue.size() << " | Empty? " << queue.empty();

    if (!queue.empty())
    {
        out << " | Top: " << queue.top()
            << "\nAll elements: ";

        while (!queue.empty())
        {
            out << queue.top() << " | ";
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
    std::priority_queue<string> people;

    cout << people;

    // Add elements
    people.push("Al");
    people.push("Bo");
    people.push("CR7");
    people.push("Donald");

    cout << people;

    // Modify front and back (Cannot modify top)
    // people.front() = "HELLLO";
    // people.back() = "BYEE";

    cout << people;

    // Remove elements from front
    people.pop();
    people.pop();

    cout << people;

    // Test with integers
    std::priority_queue<int> numbers;
    cout << "\n\nQueue of integers:\n" << numbers;

    numbers.push(10);
    numbers.push(-132);
    numbers.push(1);
    numbers.push(55);

    cout << numbers;

    numbers.pop();
    cout << numbers;

    // Test with integers with reversed order
    // NOTE: must create queue with three values inside <> : ElementType, ContainerType (ex:vector), Order (ex greater<>)
    std::priority_queue<int, std::vector<int>, std::greater<>> numbers_reversed;
    cout << "\n\nQueue of integers (reversed):\n" << numbers_reversed;

    numbers_reversed.push(10);
    numbers_reversed.push(-132);
    numbers_reversed.push(1);
    numbers_reversed.push(55);

    cout << numbers_reversed;

    numbers_reversed.pop();
    cout << numbers_reversed;
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

// Provide comparison for priority queue
bool operator<(const Person& p1, const Person& p2)
{
    return p1.age < p2.age;
}

void test2()
{
    std::priority_queue<Person> queue;
    cout << queue;

    // emplace constructs the object in-place, using the passed arguments as arguments to the constructor
    // returns void with priority_queue
    queue.emplace("Matthew Tannous", 20);
    queue.emplace("Other", 100);

    queue.push(Person()); // returns null
    queue.push(Person("New", 23));

    cout << queue;
}