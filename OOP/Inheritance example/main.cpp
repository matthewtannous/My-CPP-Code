#include <iostream>
#include "Person.h"
#include "Student.h"

using namespace std;

int main() {
    cout << "Testing base class (Person):\n";
    Person p("MATTHEW", 10);
    p.print(cout);
    cout << p;

    cout << "\n\nTesting derived class (Student):\n";
    Student s;
    s.print(cout);
    cout << s << "\n\n";

    Student s2("Comp Sci", "Tannous", 20);
    s2.print(cout);
    cout << s2;
}