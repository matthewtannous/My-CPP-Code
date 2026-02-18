#include "Person.h"
#include <iostream>

Person::Person() : name("???"), age(-1) {}

Person::Person(std::string name) : name(name), age(-1) {}

Person::Person(std::string name, int age) : name(name), age(age) {}

void Person::print(std::ostream& out) {
    out << "Name: " << name << "\tAge: " << age << std::endl;
}

// Definition of non-member non-friend function
// std::ostream & operator<<(std::ostream& out, Person person)
// {
//     person.print(out);
//     return out;
// }

// Definition of friend function
std::ostream & operator<<(std::ostream& out, Person person)
{
    out << "Name: " << person.name << "\tAge: " << person.age << std::endl;
    return out;
}