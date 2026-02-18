#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <iostream>
#include <string>

// To inherit from many classes at the same time, separates class with commas
// ex:  class Student: public Person, std::string, Stack { ... }
class Student : public Person {
  public:
    Student();
    Student(std::string major);
    Student(std::string major, std::string name, int age);

    void printMajor();

    void print(std::ostream &out);

  private:
    std::string major;
};

std::ostream &operator<<(std::ostream &out, Student student);


#endif