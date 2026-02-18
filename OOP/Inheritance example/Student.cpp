#include "Student.h"
#include "Person.h"

Student::Student() : Person(), major("?????") {}

Student::Student(std::string major) : Person(), major(major) {}

Student::Student(std::string major, std::string name, int age)
    : Person(name, age), major(major) {}

void Student::printMajor() {
    std::cout << "Student's major is " << major << std::endl;
}

void Student::print(std::ostream &out) {
    Person::print(out);
    out << "Major: " << major << std::endl;
}

std::ostream &operator<<(std::ostream &out, Student student) {
    student.print(out);
    return out;
}
