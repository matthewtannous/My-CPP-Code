#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <ostream>

class Person {
  public:
    Person();
    Person(std::string name);
    Person(std::string name, int age);

    void print(std::ostream &out);

    friend std::ostream &operator<<(std::ostream &out, Person person);

  private:
    std::string name;
    int age;
};

// std::ostream &operator<<(std::ostream &out, Person person);

#endif